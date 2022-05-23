/**
 * 
 * 该文件用于实现记录，redo，undo的操作实现
 * 
 */ 

#include "record.h"
#include "display.h"

static linkedList *nodeHead = NULL, *nodeTail = NULL;
static linkedList *curNode = NULL;


/**
 * 初始化操作记录
 * 若之前有记录过操作数据，则要全部清除！！
 */ 
void initRecord()
{
    linkedList *temp;
    while(nodeHead != NULL)
    {
        temp = nodeHead->next;
        free(nodeHead->str);
        free(nodeHead);
        nodeHead = temp;
    }
    nodeHead = nodeTail = curNode = NULL;
}

/**
 * 记录操作
 * op 操作类型: OP_ADD 添加字符串 OP_DELETE 删除字符串
 * pos 操作位置
 * str 添加/删除的字符串
 */ 
void record(int op, RCNode pos, string str) {
    if (nodeHead == NULL)   //判断头节点是否为空
    {
        nodeHead = (linkedList*)malloc(sizeof(linkedList));
        nodeHead->op = op;
        nodeHead->pos = pos;
        nodeHead->str = (string)malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(nodeHead->str, str);
        nodeTail = nodeHead;
        curNode = nodeHead;
        nodeHead->last = NULL;
        nodeHead->next = NULL;
    }else
    {
        if(curNode != nodeTail)  //如果目前操作不是尾节点，释放后面所有节点
        {
            linkedList *temp;
            while(nodeTail != curNode)
            {
                nodeTail = nodeTail->last;
                if (nodeTail == NULL) {     //到行头了
                    free(nodeHead->str);
                    free(nodeHead);
                    nodeHead = NULL;
                } else {
                    free(nodeTail->next->str);
                    free(nodeTail->next);
                    nodeTail->next = NULL;
                }
            }
        }
        if (nodeHead == NULL)   //判断头节点是否为空
        {
            nodeHead = (linkedList*)malloc(sizeof(linkedList));
            nodeHead->op = op;
            nodeHead->pos = pos;
            nodeHead->str = (string)malloc(sizeof(char) * (strlen(str) + 1));
            strcpy(nodeHead->str, str);
            nodeTail = nodeHead;
            curNode = nodeHead;
            nodeHead->last = NULL;
            nodeHead->next = NULL;
        }else
        {
            linkedList *temNode;
            temNode = (linkedList*)malloc(sizeof(linkedList));  
            temNode->op = op;
            temNode->pos = pos;
            temNode->str = (string)malloc(sizeof(char) * (strlen(str) + 1));
            temNode->next = NULL;
            strcpy(temNode->str, str);
            nodeTail->next = temNode;    //链接双向链表
            temNode->last = nodeTail;
            nodeTail = nodeTail->next;
            curNode = nodeTail;    //将指向当前节点的指针移到链表末端
        }
    }
}

/**
 * 实现撤销功能
 */ 
void undo() {
    if(curNode == NULL)  //判断当前节点是否为空，为空则不进行撤销操作
    {
        return;
    }else
    {
        if(curNode->op == OP_ADD)   //如果操作为增加字符串，则将增加的部分删去
        {
            //定位字符串结束位置
            RCNode nextPos = endPos(curNode->pos, curNode->str);
            deleteContent(curNode->pos, nextPos, 0);

            //定位光标位置在删除字符的开始位置
            setCursorRC(curNode->pos);
            setSelectStartRC(curNode->pos);
            setSelectEndRC(curNode->pos);
            setCursorInWindow();

        }else if(curNode->op == OP_DELETE)   //如果操作为删除字符，则将删除的字符加回去
        {
            addContentByString(curNode->pos, curNode->str, 0);
            
            //定位光标位置在增加的字符串后
            RCNode nextPos = endPos(curNode->pos, curNode->str);
            setCursorRC(nextPos);
            setSelectEndRC(nextPos);
            if (strlen(curNode->str) == 1 || (strlen(curNode->str) == 2 && curNode->str[0] & 0x80)) {   //如果重做的是单字符或单个汉字则不用重选
                setSelectStartRC(nextPos);
            }
            else {  //如果重做的是字符串，则将选择区域划为重做的字符串
                setSelectStartRC(curNode->pos);
            }
            setCursorInWindow();
        }
        curNode = curNode->last;   //将指向当前操作的指针前移一位
    }
}

/**
 * 实现重做功能
 */ 
void redo() {
    if (curNode == NULL)    //如果现在的节点为空，则要指向头节点
    {
        if (nodeHead != NULL)
        {
            curNode = nodeHead;
        }else
        {
            return;
        }
    }else
    {
        if(curNode->next == NULL)   //如果下一个操作节点为空则不操作
        {
            return;
        }else
        {
            curNode = curNode->next;  //指针指向下一个节点
        }
    }
    if(curNode->op == OP_ADD)    //如果为增加操作则重新将字符串加回去
    {
        addContentByString(curNode->pos, curNode->str, 0);

        //定位光标位置在增加字符串结束处
        RCNode nextPos = endPos(curNode->pos, curNode->str);
        setCursorRC(nextPos);
        setSelectEndRC(nextPos);
        setSelectStartRC(nextPos);
        setCursorInWindow();

    }else if(curNode->op == OP_DELETE)   //如果为删除操作则删除字符串
    {
        //找到删除的字符串的结束位置
        RCNode nextPos = endPos(curNode->pos, curNode->str);
        deleteContent(curNode->pos, nextPos, 0);
        
        //定位光标位置在删除字符串的开始位置
        setCursorRC(curNode->pos);
        setSelectStartRC(curNode->pos);
        setSelectEndRC(curNode->pos);
        setCursorInWindow();
    }
}

/**
 * 计算传入字符的结束坐标
 * 传入开始的坐标与中间的字符串
 * */
RCNode endPos(RCNode startPos, string str)
{
    RCNode nextPos = startPos;
    char *p = str;
    char *pp = p;
    char *enter = p;
    int isEnter = 0;
    while(*pp)
    {
        if(*pp=='\n')
        {
        	isEnter = 1;
            enter = pp;   //定位换行符位置
            nextPos.row ++;
        }
        pp ++;
    }
    if(isEnter)
    {
    	nextPos.column = strlen(enter);   //最后一行的列数为换行符后字符串的字数
	}else
	{
		nextPos.column += strlen(enter);  //列数为原列数加字符串长度 
	}
    
    return nextPos;
}