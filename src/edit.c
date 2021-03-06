/*
    主要包括复制 剪切 粘贴功能
    这一部分应该要和Windows剪贴板进行交互
*/
#include <stdio.h>
#include <Windows.h>
#include "global.h"
#include "edit.h"
#include "file.h"
#include "strlib.h"
#include <string.h>
#include "storage.h"
#include "display.h"
#include "record.h"
/*
    根据传入的起始行列坐标与终止行列坐标进行复制
*/
void copyText()
{   
    RCNode startSelect = getSelectStartRC();
    RCNode endSelect = getSelectEndRC();    
    if (startSelect.row > endSelect.row || (startSelect.row == endSelect.row && startSelect.column > endSelect.column)) {
        RCNode t = startSelect;
        startSelect = endSelect;
        endSelect = t;
    }else if(startSelect.row == endSelect.row && startSelect.column == endSelect.column)  //如果没有选中内容，不进行复制操作
    {
        return ;
    }
	char *copystr=getContent(startSelect, endSelect); 
    
    //与系统剪切板进行交互
    if (!OpenClipboard(NULL)|| !EmptyClipboard())
    {   
        MessageBoxA(NULL,"打开或清空剪切板出错！","Notepad--",MB_OK | MB_ICONWARNING | MB_TASKMODAL);
        return ;   
    }
    HGLOBAL hMen;
    hMen = GlobalAlloc(GMEM_MOVEABLE, ((strlen(copystr)+1)*sizeof(TCHAR)));    // 分配全局内存    
    // 把数据拷贝到全局内存中
    LPSTR lpStr = (LPSTR)GlobalLock(hMen);    // 先锁住内存区
    memcpy(lpStr, copystr, ((strlen(copystr))*sizeof(TCHAR)));    // 内存复制
    lpStr[strlen(copystr)] = (TCHAR)0;    // 设置字符结束符
    GlobalUnlock(hMen);   // 释放锁
    SetClipboardData(CF_TEXT, hMen);    // 把内存中的数据放到剪切板上
    CloseClipboard();  //关闭剪切板
    free(copystr);
    // printf("COPY3:%s\n", cur);
}

/*
    根据传入的起始位置粘贴文本内容（即需要修改对应的文件）
*/
void pasteText() {
    RCNode startSelect = getSelectStartRC();
    RCNode endSelect = getSelectEndRC();

    if (startSelect.row > endSelect.row || (startSelect.row == endSelect.row && startSelect.column > endSelect.column)) {
        RCNode t = startSelect;
        startSelect = endSelect;
        endSelect = t;
    }
    
    // length = end - start;  //计算要覆盖的字符的起始位置，终止位置，长度

    //与系统剪切板交互读取其中内容并储存在pasteText当中
    char *pasteText;
    if(!OpenClipboard(NULL))
    {
        MessageBoxA(NULL,"打开剪切板出错！","Notepad--",MB_OK | MB_ICONWARNING | MB_TASKMODAL);
        return ;   
    }
    HGLOBAL hMem = GetClipboardData(CF_TEXT);
    if(hMem == NULL)
    {
        // printf("不是文本");
        return ;
    }
    //获取字符串
    const char* lpStr = GlobalLock(hMem);
    if(lpStr == NULL)
    {
        MessageBoxA(NULL,"无法读取剪切板文本","Notepad--",MB_OK | MB_ICONWARNING | MB_TASKMODAL);
        return ;
    }
    pasteText = (char *) mallocDIY(sizeof(char) * (strlen(lpStr) + 1));
    strcpy(pasteText, lpStr);   //将剪切板的内容拷贝到字符串当中
    GlobalUnlock(hMem);   //释放内存锁
    //关闭剪切板
    CloseClipboard();
    
    int recordID = newRecordID();
    deleteContent(startSelect,endSelect,recordID);
    addContent(BY_STRING,startSelect,pasteText,recordID);  //粘贴目的字符串 
    setSaveState(0);

    //获得末端的行列位置
    int lens = strlen(pasteText);
	int i=0;
    while (i < lens) {
        if (pasteText[i] == '\n') {
            startSelect.row++;
            startSelect.column = 1;
        } else startSelect.column++;
        i++;
    }

    setSelectStartRC(startSelect);
    setSelectEndRC(startSelect);
    setCursorRC(startSelect);
    
    setCursorInWindow(); 

    free(pasteText);
}

/*
    根据传入的起始行列坐标与终止行列坐标进行剪切
    即需要先复制这段内容，再将其删除
*/
void shearText() {
    RCNode startSelect = getSelectStartRC();
    RCNode endSelect = getSelectEndRC();
    copyText();   //先对选中内容进行复制

    if (startSelect.row > endSelect.row || (startSelect.row == endSelect.row && startSelect.column > endSelect.column)) {
        RCNode t = startSelect;
        startSelect = endSelect;
        endSelect = t;
    }
    //将修改后的文本输入
	deleteContent(startSelect,endSelect,newRecordID());
    setSaveState(0);
     //设置选择范围 
    setSelectStartRC(startSelect);
    setSelectEndRC(startSelect);
    setCursorRC(startSelect);

    setCursorInWindow();    

}
