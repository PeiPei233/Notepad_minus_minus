/*
    主要实现文件交互的相关功能
*/
#ifndef __FILE_H__
#define __FILE_H__

#include "global.h"

/**
 * 获取程序处理文件的状态
 */ 
int getProcessFileState();

/*
	初始化文件配置 , 一显示图形界面就要调用 
*/
void initFileConfig();
/*
    打开一个文件
    这个应该要和Windows交互
    打开后更新窗口左上角坐标
    更新currentString字符串
*/
void openFile();

/*
    新建一个文件
    对于新建的文件，在保存时要选择存放位置
*/
void createFile();


/*
    保存当前打开的文件
    如果是新建的文件 要和Windows交互选择打开位置
    否则就存在之前的位置
*/
void saveFile();

/*
    获取当前的保存状态
    是否保存
*/
int getSaveState();

/*
	另存为 
	如果此时文件不是临时写的，则同时保存当时文件 
*/
void saveAsFile();
 
/*
    设置保存状态
*/
void setSaveState(int newSaveState);

/*
	返回当前文件名
*/ 
char *getCurrentFileName();

/*
    退出时若未保存则提供选项 选择是否保存更改 
*/
void exitApplication();

#endif
