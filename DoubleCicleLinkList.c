#include "DoubleCicleLinkList.h"



#pragma region 结构操作定义
/*预置操作*/
Status DCListInit(DCList* list)													//初始化
{
	assert(list);
	list->head = (Node*)malloc(sizeof(Node));
	list->head->next = list->head->prev = list->head;
	list->len = 0;
	return Ok;
}
Node* DCListGetNewNode()															//获取新结点
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode);
	newNode->data = 0;
	newNode->next = newNode->prev = NULL;
	return newNode;
}
Boolean isDCListEmpty(DCList list)												//检测是否为空
{
	return list.head->next==list.head;
}
Boolean isDCListExsistPos(DCList list, Pos pos)									//检测位置是否存在
{
	assert(&list);
	return pos >= 1 && pos <= list.len;
}
Length DCListLength(DCList list)													//单链表长度
{
	return list.len;
}
/*基本操作*/
Status DCListInsert(DCList* list, Pos pos, DCData data)							//插入
{
	assert(list);
	//检测位置是否存在
	assert(!(isDCListExsistPos(*list, pos) == False && pos != list->len + 1));

	//获取新结点
	Node* newNode = DCListGetNewNode();
	newNode->data = data;

	//到达pos位置
	int i;
	Node* cur = list->head->next;
	for (i = 1; i < pos; i++, cur = cur->next);

	//插入
	newNode->next = cur;
	newNode->prev = cur->prev;
	cur->prev->next = newNode;
	cur->prev = newNode;
	list->len++;

	return Ok;
}
Status DCListDelete(DCList* list, Pos pos)										//删除
{
	assert(list);
	//判断链表是否为空
	if (isDCListEmpty(*list) == True) return Error;
	//判断位置是否存在
	if (isDCListExsistPos(*list, pos) == False) return Error;

	//到达pos位置
	int i;
	Node* cur = list->head->next;
	for (i = 1; i < pos; i++,cur = cur->next);

	//删除
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	free(cur);
	list->len--;
	return Ok;
}
Pos DCListFind(DCList list, DCData data)											//查找(获取位置)
{
	assert(&list);
	//判断是否为空
	if (isDCListEmpty(list) == True) return Error;

	Pos pos = 0;
	Node* cur = list.head;
	while ((pos++, cur = cur->next)&&cur!=list.head)
	{
		if (data == cur->data) return pos;
	}
	return 0;
}
Status DCListModify(DCList* list, Pos pos, DCData data)							//修改
{
	assert(list);
	//判断是否为空
	if (isDCListEmpty(*list) == True) return Error;
	//判断位置是否存在
	if (isDCListExsistPos(*list, pos) == False) return Error;

	//修改
	Pos curPos = 0;
	Node* cur = list->head;
	while ((++curPos, cur = cur->next)&&cur!=list->head)
	{
		if (curPos == pos) cur->data = data;
	}

	return Ok;
}
/*扩展操作*/
DCData DCListFindByPos(DCList list, Pos pos)										//通过位置查找值
{
	assert(&list);
	//判断是否为空
	if (isDCListEmpty(list) == True) return Error;
	//判断位置是否存在
	if (isDCListExsistPos(list, pos) == False) return Error;

	//查找并返回值
	Pos curPos = 0;
	Node* cur = list.head;
	while ((++curPos, cur = cur->next) && cur!=list.head)
	{
		if (curPos == pos) return cur->data;
	}
}
Status DCListAdd(DCList* list, DCData data)										//增添(尾插)
{
	assert(list);

	//获取尾结点和新结点
	Node* endNode = list->head->prev;
	Node* newNode = DCListGetNewNode();
	newNode->data = data;

	//尾插
	endNode->next = newNode;
	newNode->prev = endNode;
	list->head->prev = newNode;
	newNode->next = list->head;
	list->len++;

	return Ok;
}
Status DCListDelInEnd(DCList* list)												//尾删
{
	assert(list);
	//判断链表是否为空
	if (isDCListEmpty(*list) == True) return Error;
	
	//找新尾结点
	Node* endNode = list->head->prev;
	Node* newEndNode = endNode->prev;

	//尾删
	newEndNode->next = list->head;
	list->head->prev = newEndNode;
	free(endNode);
	list->len--;
	return Ok;
}
Status DCListAddToHead(DCList* list, DCData data)								//头插
{
	return DCListInsert(list,1,data);
}
Status DCListDelInHead(DCList* list)												//头删
{
	return DCListDelete(list, 1);
}
Status DCListClearAll(DCList* list)												//清空单链表
{
	assert(list);
	//判断是否为空
	if (isDCListEmpty(*list) == True) return Error;

	//删除
	while (isDCListEmpty(*list) != True) DCListDelInEnd(list);

	return Ok;
}
Status DCListTraverse(DCList list)												//遍历双向循环链表(输出值)
{
	assert(&list);

	Node* cur = list.head;
	while ((cur = cur->next) && cur!=list.head) printf("%d->", cur->data);
	printf("NULL\n");
	return Ok;
}
#pragma endregion