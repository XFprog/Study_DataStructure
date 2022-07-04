#include "SingleLinkList.h"



#pragma region 结构操作定义
/*预置操作*/
Status SListInit(SList* list)													//初始化
{
	assert(list);
	list->head = (Node*)malloc(sizeof(Node));
	list->head->next = NULL;
	list->len = 0;
	return Ok;
}
Node* SListGetNewNode()															//获取新结点
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode);
	newNode->data = 0;
	newNode->next = NULL;
	return newNode;
}
Boolean isSListEmpty(SList list)												//检测是否为空
{
	return list.len == 0;
}
Boolean isSListExsistPos(SList list, Pos pos)									//检测位置是否存在
{
	assert(&list);
	return pos >= 1 && pos <= list.len;
}
Length SListLength(SList list)													//单链表长度
{
	return list.len;
}
/*基本操作*/
Status SListInsert(SList* list, Pos pos, SData data)							//插入
{
	assert(list);
	//检测位置是否存在
	assert(!(isSListExsistPos(*list, pos) == False && pos != list->len + 1));

	//获取新结点
	Node* newNode = SListGetNewNode();
	newNode->data = data;

	//到达pos位置
	int i;
	Node* prev = list->head;
	Node* cur = prev->next;
	for (i = 1; i < pos; i++, prev = prev->next, cur = cur->next);

	//插入
	newNode->next = cur;
	prev->next = newNode;
	list->len++;

	return Ok;

}
Status SListDelete(SList* list, Pos pos)										//删除
{
	assert(list);
	//判断链表是否为空
	if(isSListEmpty(*list) == True) return Error;
	//判断位置是否存在
	if (isSListExsistPos(*list,pos) == False) return Error;

	//到达pos位置
	int i;
	Node* prev = list->head;
	Node* cur = prev->next;
	for (i = 1; i < pos; i++, prev = prev->next, cur = cur->next);

	//删除
	prev->next = cur->next;
	free(cur);
	list->len--;

	return Ok;
}
Pos SListFind(SList list, SData data)											//查找(获取位置)
{
	assert(&list);
	//判断是否为空
	if (isSListEmpty(list)==True) return Error;

	Pos pos = 0;
	Node* cur = list.head;
	while (pos++,cur = cur->next)
	{
		if (data == cur->data) return pos;
	}
	return 0;
}
Status SListModify(SList* list, Pos pos, SData data)							//修改
{
	assert(list);
	//判断是否为空
	if (isSListEmpty(*list) == True) return Error;
	//判断位置是否存在
	if (isSListExsistPos(*list, pos) == False) return Error;

	//修改
	Pos curPos = 0;
	Node* cur = list->head;
	while (++curPos, cur = cur->next)
	{
		if (curPos == pos) cur->data = data;
	}

	return Ok;
}
/*扩展操作*/
SData SListFindByPos(SList list, Pos pos)										//通过位置查找值
{
	assert(&list);
	//判断是否为空
	if (isSListEmpty(list) == True) return Error;
	//判断位置是否存在
	if (isSListExsistPos(list,pos) == False) return Error;

	//查找并返回值
	Pos curPos = 0;
	Node* cur = list.head;
	while (++curPos,cur = cur->next)
	{
		if (curPos == pos) return cur->data;
	}
}
Status SListAdd(SList* list, SData data)										//增添(尾插)
{
	return SListInsert(list,SListLength(*list)+1,data);
}
Status SListDelInEnd(SList* list)												//尾删
{
	return SListDelete(list,SListLength(*list));
}
Status SListAddToHead(SList* list, SData data)								//头插
{
	return SListInsert(list,1,data);
}
Status SListDelInHead(SList* list)												//头删
{
	return SListDelete(list, 1);
}
Status SListClearAll(SList* list)												//清空单链表
{
	assert(list);
	//判断是否为空
	if (isSListEmpty(*list) == True) return Error;

	//删除
	while(isSListEmpty(*list)!= True) SListDelInEnd(list);

	return Ok;
}
Status SListTraverse(SList list)												//遍历单链表(输出值)
{
	assert(&list);

	Node* cur = list.head;
	while (cur=cur->next) printf("%d->", cur->data);
	printf("NULL\n");
	return Ok;
}
#pragma endregion