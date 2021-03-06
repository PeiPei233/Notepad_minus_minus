/*
    主要包括复制 剪切 粘贴功能
    这一部分应该要和Windows剪贴板进行交互
*/

#ifndef __EDIT_H__
#define __EDIT_H__

/*
    根据传入的起始行列坐标与终止行列坐标进行复制
*/
void copyText();

/*
    根据传入的起始位置粘贴文本内容（即需要修改对应的文件）
*/
void pasteText();

/*
    根据传入的起始行列坐标与终止行列坐标进行剪切
    即需要先复制这段内容，再将其删除
*/
void shearText();

#endif