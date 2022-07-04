#pragma once
#define _CRT_SECURE_NO_WARNINGS														//VS里需要，其他编译器可删除这条
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

typedef enum { Error, Ok } Status;														//状态类型(错误/成功)
typedef enum { False, True } Boolean;													//布尔类型(不是/是)

typedef int SData;																	//单链表数据
typedef int Pos;																	//单链表下标位置
typedef long Length;																//单链表长度
//#define STATIC 0	
#define SLL



#pragma region 单链表

#pragma region 结构定义
//单链表结点结构定义
typedef struct Node
{
	SData data;
	struct Node* next;
}Node;
//单链表结构体定义
typedef struct
{
	Node* head;
	Length len;
}SList;
#pragma endregion

#pragma region 结构操作声明
/*预置操作*/
Status SListInit(SList* list);													//初始化
Node* SListGetNewNode();														//获取新结点
Boolean isSListEmpty(SList list);												//检测是否为空
Boolean isSListExsistPos(SList list, Pos pos);									//检测位置是否存在
Length SListLength(SList list);													//单链表长度
/*基本操作*/
Status SListInsert(SList* list, Pos pos, SData data);							//插入
Status SListDelete(SList* list, Pos pos);										//删除
Pos SListFind(SList list, SData data);											//查找(获取位置)
Status SListModify(SList* list, Pos pos, SData data);							//修改
/*扩展操作*/
SData SListFindByPos(SList list, Pos pos);										//通过位置查找值
Status SListAdd(SList* list, SData data);										//增添(尾插)
Status SListDelInEnd(SList* list);												//尾删
Status SListAddToHead(SList* list, SData data);									//头插
Status SListDelInHead(SList* list);												//头删
Status SListClearAll(SList* list);												//清空单链表
Status SListTraverse(SList list);												//遍历单链表(输出值)
#pragma endregion

#pragma endregion