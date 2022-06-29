#pragma once
#define _CRT_SECURE_NO_WARNINGS														//VS里需要，其他编译器可删除这条
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

typedef enum{Error,Ok} Status;														//状态类型(错误/成功)
typedef enum{False,True} Boolean;													//布尔类型(不是/是)

typedef int SeqData;																//顺序表数据
typedef int Pos;																	//顺序表下标位置
typedef long Length;																//顺序表长度
//顺序表类型(静态/动态，通过注释控制类型)
//#define STATIC 0																	
#define DYNAMIC 1


#ifdef STATIC

#pragma region 静态顺序表

//顺序表最大长度
#define MAXSIZE 20

#pragma region 结构定义
//静态顺序表结构定义
typedef struct
{
	SeqData a[MAXSIZE+1];	//顺序表数组(下标从1开始)
	Length length;			//顺序表长度
}SeqList;
#pragma endregion

#pragma region 结构操作声明
/*预置操作*/
Status SeqListInit(SeqList* list);													//初始化
Boolean isSeqListEmpty(SeqList list);												//检测是否为空
Boolean isSeqListFull(SeqList list);												//检测是否已满
Boolean isSeqListExsistPos(SeqList list, Pos pos);									//检测位置是否存在
Length SeqListLength(SeqList list);													//顺序表长度
/*基本操作*/
Status SeqListInsert(SeqList* list, Pos pos, SeqData data);							//插入
Status SeqListDelete(SeqList* list, Pos pos);										//删除
Pos SeqListFind(SeqList list, SeqData data);										//查找(获取位置)
Status SeqListModify(SeqList* list, Pos pos, SeqData data);							//修改
/*扩展操作*/
SeqData SeqListFindByPos(SeqList list, Pos pos);									//通过位置查找值
Status SeqListAdd(SeqList* list, SeqData data);										//增添(尾插)
Status SeqListDelInEnd(SeqList* list);												//尾删
Status SeqListAddToHead(SeqList* list, SeqData data);								//头插
Status SeqListDelInHead(SeqList* list);												//头删
Status SeqListClearAll(SeqList* list);												//清空顺序表
Status SeqListTraverse(SeqList list);												//遍历顺序表(输出值)
#pragma endregion

#pragma endregion
	
#else 

#pragma region 动态顺序表

//顺序表最大长度
#define MAXSIZE 20

#pragma region 结构定义
//静态顺序表结构定义
typedef struct
{
	SeqData* a;				//顺序表数组(下标从1开始)
	Length length;			//顺序表长度
	Length capacity;		//容量
}SeqList;
#pragma endregion

#pragma region 结构操作声明
/*预置操作*/
Status SeqListInit(SeqList* list);													//初始化
Status SeqListCheckCapacity(SeqList* list);											//检测容量和进行扩容
Boolean isSeqListEmpty(SeqList list);												//检测是否为空
Boolean isSeqListExsistPos(SeqList list, Pos pos);									//检测位置是否存在
Length SeqListLength(SeqList list);													//顺序表长度
/*基本操作*/
Status SeqListInsert(SeqList* list, Pos pos, SeqData data);							//插入
Status SeqListDelete(SeqList* list, Pos pos);										//删除
Pos SeqListFind(SeqList list, SeqData data);										//查找(获取位置)
Status SeqListModify(SeqList* list, Pos pos, SeqData data);							//修改
/*扩展操作*/
SeqData SeqListFindByPos(SeqList list, Pos pos);									//通过位置查找值
Status SeqListAdd(SeqList* list, SeqData data);										//增添(尾插)
Status SeqListDelInEnd(SeqList* list);												//尾删
Status SeqListAddToHead(SeqList* list, SeqData data);								//头插
Status SeqListDelInHead(SeqList* list);												//头删
Status SeqListClearAll(SeqList* list);												//清空顺序表
Status SeqListTraverse(SeqList list);												//遍历顺序表(输出值)
#pragma endregion

#pragma endregion

#endif