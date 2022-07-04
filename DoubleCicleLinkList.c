#include "DoubleCicleLinkList.h"



#pragma region �ṹ��������
/*Ԥ�ò���*/
Status DCListInit(DCList* list)													//��ʼ��
{
	assert(list);
	list->head = (Node*)malloc(sizeof(Node));
	list->head->next = list->head->prev = list->head;
	list->len = 0;
	return Ok;
}
Node* DCListGetNewNode()															//��ȡ�½��
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode);
	newNode->data = 0;
	newNode->next = newNode->prev = NULL;
	return newNode;
}
Boolean isDCListEmpty(DCList list)												//����Ƿ�Ϊ��
{
	return list.head->next==list.head;
}
Boolean isDCListExsistPos(DCList list, Pos pos)									//���λ���Ƿ����
{
	assert(&list);
	return pos >= 1 && pos <= list.len;
}
Length DCListLength(DCList list)													//��������
{
	return list.len;
}
/*��������*/
Status DCListInsert(DCList* list, Pos pos, DCData data)							//����
{
	assert(list);
	//���λ���Ƿ����
	assert(!(isDCListExsistPos(*list, pos) == False && pos != list->len + 1));

	//��ȡ�½��
	Node* newNode = DCListGetNewNode();
	newNode->data = data;

	//����posλ��
	int i;
	Node* cur = list->head->next;
	for (i = 1; i < pos; i++, cur = cur->next);

	//����
	newNode->next = cur;
	newNode->prev = cur->prev;
	cur->prev->next = newNode;
	cur->prev = newNode;
	list->len++;

	return Ok;
}
Status DCListDelete(DCList* list, Pos pos)										//ɾ��
{
	assert(list);
	//�ж������Ƿ�Ϊ��
	if (isDCListEmpty(*list) == True) return Error;
	//�ж�λ���Ƿ����
	if (isDCListExsistPos(*list, pos) == False) return Error;

	//����posλ��
	int i;
	Node* cur = list->head->next;
	for (i = 1; i < pos; i++,cur = cur->next);

	//ɾ��
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	free(cur);
	list->len--;
	return Ok;
}
Pos DCListFind(DCList list, DCData data)											//����(��ȡλ��)
{
	assert(&list);
	//�ж��Ƿ�Ϊ��
	if (isDCListEmpty(list) == True) return Error;

	Pos pos = 0;
	Node* cur = list.head;
	while ((pos++, cur = cur->next)&&cur!=list.head)
	{
		if (data == cur->data) return pos;
	}
	return 0;
}
Status DCListModify(DCList* list, Pos pos, DCData data)							//�޸�
{
	assert(list);
	//�ж��Ƿ�Ϊ��
	if (isDCListEmpty(*list) == True) return Error;
	//�ж�λ���Ƿ����
	if (isDCListExsistPos(*list, pos) == False) return Error;

	//�޸�
	Pos curPos = 0;
	Node* cur = list->head;
	while ((++curPos, cur = cur->next)&&cur!=list->head)
	{
		if (curPos == pos) cur->data = data;
	}

	return Ok;
}
/*��չ����*/
DCData DCListFindByPos(DCList list, Pos pos)										//ͨ��λ�ò���ֵ
{
	assert(&list);
	//�ж��Ƿ�Ϊ��
	if (isDCListEmpty(list) == True) return Error;
	//�ж�λ���Ƿ����
	if (isDCListExsistPos(list, pos) == False) return Error;

	//���Ҳ�����ֵ
	Pos curPos = 0;
	Node* cur = list.head;
	while ((++curPos, cur = cur->next) && cur!=list.head)
	{
		if (curPos == pos) return cur->data;
	}
}
Status DCListAdd(DCList* list, DCData data)										//����(β��)
{
	assert(list);

	//��ȡβ�����½��
	Node* endNode = list->head->prev;
	Node* newNode = DCListGetNewNode();
	newNode->data = data;

	//β��
	endNode->next = newNode;
	newNode->prev = endNode;
	list->head->prev = newNode;
	newNode->next = list->head;
	list->len++;

	return Ok;
}
Status DCListDelInEnd(DCList* list)												//βɾ
{
	assert(list);
	//�ж������Ƿ�Ϊ��
	if (isDCListEmpty(*list) == True) return Error;
	
	//����β���
	Node* endNode = list->head->prev;
	Node* newEndNode = endNode->prev;

	//βɾ
	newEndNode->next = list->head;
	list->head->prev = newEndNode;
	free(endNode);
	list->len--;
	return Ok;
}
Status DCListAddToHead(DCList* list, DCData data)								//ͷ��
{
	return DCListInsert(list,1,data);
}
Status DCListDelInHead(DCList* list)												//ͷɾ
{
	return DCListDelete(list, 1);
}
Status DCListClearAll(DCList* list)												//��յ�����
{
	assert(list);
	//�ж��Ƿ�Ϊ��
	if (isDCListEmpty(*list) == True) return Error;

	//ɾ��
	while (isDCListEmpty(*list) != True) DCListDelInEnd(list);

	return Ok;
}
Status DCListTraverse(DCList list)												//����˫��ѭ������(���ֵ)
{
	assert(&list);

	Node* cur = list.head;
	while ((cur = cur->next) && cur!=list.head) printf("%d->", cur->data);
	printf("NULL\n");
	return Ok;
}
#pragma endregion