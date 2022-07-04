#pragma once
#define _CRT_SECURE_NO_WARNINGS														//VS里需要，其他编译器可删除这条
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

typedef enum { Error, Ok } Status;														//状态类型(错误/成功)
typedef enum { False, True } Boolean;													//布尔类型(不是/是)

typedef int DCData;																	//双向循环链表数据
typedef int Pos;																	//双向循环链表下标位置
typedef long Length;																//双向循环链表长度
//#define STATIC 0	
#define SLL



#pragma region 双向循环链表

#pragma region 结构定义
//双向循环链表结点结构定义
typedef struct Node
{
	DCData data;
	struct Node* prev,*next;
}Node;
//双向循环链表结构体定义
typedef struct
{
	Node* head;
	Length len;
}DCList;
#pragma endregion

#pragma region 结构操作声明
/*预置操作*/
Status DCListInit(DCList* list);												//初始化
Node* DCListGetNewNode();														//获取新结点
Boolean isDCListEmpty(DCList list);												//检测是否为空
Boolean isDCListExsistPos(DCList list, Pos pos);								//检测位置是否存在
Length DCListLength(DCList list);												//双向循环链表长度
/*基本操作*/
Status DCListInsert(DCList* list, Pos pos, DCData data);							//插入
Status DCListDelete(DCList* list, Pos pos);										//删除
Pos DCListFind(DCList list, DCData data);										//查找(获取位置)
Status DCListModify(DCList* list, Pos pos, DCData data);							//修改
/*扩展操作*/
DCData DCListFindByPos(DCList list, Pos pos);									//通过位置查找值
Status DCListAdd(DCList* list, DCData data);										//增添(尾插)
Status DCListDelInEnd(DCList* list);											//尾删
Status DCListAddToHead(DCList* list, DCData data);								//头插
Status DCListDelInHead(DCList* list);											//头删
Status DCListClearAll(DCList* list);											//清空双向循环链表
Status DCListTraverse(DCList list);												//遍历双向循环链表(输出值)
#pragma endregion

#pragma endregion