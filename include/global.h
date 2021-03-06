#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <stddef.h>

//行列坐标表示
typedef struct {
    int row;  //行位置
    int column;  //列位置
}RCNode;

extern double winHeight, winWidth;	//窗口高度和宽度

/*
    获取目前窗口左上角的行列位置
*/
RCNode getWindowCurrentRC();

/*
    更改目前窗口左上角的行列位置
*/
void setWindowCurrentRC(RCNode newWindowCurrent);

/*
    根据传入的参数设置光标位置
*/
void setCursorRC(RCNode newCursor);

/*
    获取光标位置
*/
RCNode getCursorRC();

/*
    获取选择范围起始位置
*/
RCNode getSelectStartRC();

/*
    获取选择范围终止位置
*/
RCNode getSelectEndRC();

/*
    设置选择范围起始位置
*/
void setSelectStartRC(RCNode newStartSelect);

/*
    设置其实范围终止位置
*/
void setSelectEndRC(RCNode newEndSelect);

/*
	比较两个节点在字符串流中的位置前后
	start在end前返回1，相等返回0，否则返回-1 
*/
int RCcompare(RCNode start,RCNode end);

/**
 * 计算传入字符的结束坐标
 * 传入开始的坐标与中间的字符串
 * */
RCNode endPos(RCNode startPos, char *str);

/**
 * 带警告的malloc
 */ 
void *mallocDIY(size_t size);

#endif
