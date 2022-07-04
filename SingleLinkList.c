#include "SingleLinkList.h"



#pragma region �ṹ��������
/*Ԥ�ò���*/
Status SListInit(SList* list)													//��ʼ��
{
	assert(list);
	list->head = (Node*)malloc(sizeof(Node));
	list->head->next = NULL;
	list->len = 0;
	return Ok;
}
Node* SListGetNewNode()															//��ȡ�½��
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode);
	newNode->data = 0;
	newNode->next = NULL;
	return newNode;
}
Boolean isSListEmpty(SList list)												//����Ƿ�Ϊ��
{
	return list.len == 0;
}
Boolean isSListExsistPos(SList list, Pos pos)									//���λ���Ƿ����
{
	assert(&list);
	return pos >= 1 && pos <= list.len;
}
Length SListLength(SList list)													//��������
{
	return list.len;
}
/*��������*/
Status SListInsert(SList* list, Pos pos, SData data)							//����
{
	assert(list);
	//���λ���Ƿ����
	assert(!(isSListExsistPos(*list, pos) == False && pos != list->len + 1));

	//��ȡ�½��
	Node* newNode = SListGetNewNode();
	newNode->data = data;

	//����posλ��
	int i;
	Node* prev = list->head;
	Node* cur = prev->next;
	for (i = 1; i < pos; i++, prev = prev->next, cur = cur->next);

	//����
	newNode->next = cur;
	prev->next = newNode;
	list->len++;

	return Ok;

}
Status SListDelete(SList* list, Pos pos)										//ɾ��
{
	assert(list);
	//�ж������Ƿ�Ϊ��
	if(isSListEmpty(*list) == True) return Error;
	//�ж�λ���Ƿ����
	if (isSListExsistPos(*list,pos) == False) return Error;

	//����posλ��
	int i;
	Node* prev = list->head;
	Node* cur = prev->next;
	for (i = 1; i < pos; i++, prev = prev->next, cur = cur->next);

	//ɾ��
	prev->next = cur->next;
	free(cur);
	list->len--;

	return Ok;
}
Pos SListFind(SList list, SData data)											//����(��ȡλ��)
{
	assert(&list);
	//�ж��Ƿ�Ϊ��
	if (isSListEmpty(list)==True) return Error;

	Pos pos = 0;
	Node* cur = list.head;
	while (pos++,cur = cur->next)
	{
		if (data == cur->data) return pos;
	}
	return 0;
}
Status SListModify(SList* list, Pos pos, SData data)							//�޸�
{
	assert(list);
	//�ж��Ƿ�Ϊ��
	if (isSListEmpty(*list) == True) return Error;
	//�ж�λ���Ƿ����
	if (isSListExsistPos(*list, pos) == False) return Error;

	//�޸�
	Pos curPos = 0;
	Node* cur = list->head;
	while (++curPos, cur = cur->next)
	{
		if (curPos == pos) cur->data = data;
	}

	return Ok;
}
/*��չ����*/
SData SListFindByPos(SList list, Pos pos)										//ͨ��λ�ò���ֵ
{
	assert(&list);
	//�ж��Ƿ�Ϊ��
	if (isSListEmpty(list) == True) return Error;
	//�ж�λ���Ƿ����
	if (isSListExsistPos(list,pos) == False) return Error;

	//���Ҳ�����ֵ
	Pos curPos = 0;
	Node* cur = list.head;
	while (++curPos,cur = cur->next)
	{
		if (curPos == pos) return cur->data;
	}
}
Status SListAdd(SList* list, SData data)										//����(β��)
{
	return SListInsert(list,SListLength(*list)+1,data);
}
Status SListDelInEnd(SList* list)												//βɾ
{
	return SListDelete(list,SListLength(*list));
}
Status SListAddToHead(SList* list, SData data)								//ͷ��
{
	return SListInsert(list,1,data);
}
Status SListDelInHead(SList* list)												//ͷɾ
{
	return SListDelete(list, 1);
}
Status SListClearAll(SList* list)												//��յ�����
{
	assert(list);
	//�ж��Ƿ�Ϊ��
	if (isSListEmpty(*list) == True) return Error;

	//ɾ��
	while(isSListEmpty(*list)!= True) SListDelInEnd(list);

	return Ok;
}
Status SListTraverse(SList list)												//����������(���ֵ)
{
	assert(&list);

	Node* cur = list.head;
	while (cur=cur->next) printf("%d->", cur->data);
	printf("NULL\n");
	return Ok;
}
#pragma endregion