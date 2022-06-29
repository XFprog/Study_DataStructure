#include "SeqList.h"



#ifdef STATIC
#pragma region ��̬˳���

#pragma region �ṹ��������
/*Ԥ�ò���*/
Status SeqListInit(SeqList* list)													//��ʼ��
{
	//˳����ȳ�ʼ��
	list->length = 0;
	return Ok;
}
Boolean isSeqListEmpty(SeqList list)												//����Ƿ�Ϊ��
{
	return list.length == 0;
}
Boolean isSeqListFull(SeqList list)													//����Ƿ�����
{
	return list.length == MAXSIZE;
}
Boolean isSeqListExsistPos(SeqList list, Pos pos)									//���λ���Ƿ����
{
	return pos>=1 && pos <= list.length;
}
Length SeqListLength(SeqList list)													//˳�����
{
	return list.length;
}
/*��������*/
Status SeqListInsert(SeqList* list, Pos pos, SeqData data)							//����
{
	//˳���������
	assert(list);
	//����Ƿ���
	if (isSeqListFull(*list) == True) return Error;
	//���λ���Ƿ����
	if (pos<=0||pos>list->length+1) return Error;

	//λ�ò���β������һ��
	if (pos <= list->length)
	{
		int curPos = pos;
		Length length = list->length;
		//��ָ��λ�ú��������Ԫ�غ���һλ
		for (curPos = length; curPos >= pos; curPos--)
		{
			list->a[curPos + 1] = list->a[curPos];
		}
		//������Ԫ�ز���ָ��λ��
		list->a[pos] = data;
	}
	//λ����β������һ��
	else if (pos == list->length + 1)
	{
		//������Ԫ�ز���ָ��λ��
		list->a[pos] = data;
	}
	//��������
	list->length++;
	return Ok;
}
Status SeqListDelete(SeqList* list, Pos pos)										//ɾ��
{
	//˳���������
	assert(list);
	//˳�����Ϊ��
	if (isSeqListEmpty(*list) == True) return Error;
	//ָ��λ�ô���
	if (isSeqListExsistPos(*list, pos) == False) return Error;

	//ָ��λ��֮�������Ԫ��ǰ��һλ
	Pos curPos;
	Length length = list->length;
	for (curPos = pos; curPos <= length-1; curPos++)
	{
		list->a[curPos] = list->a[curPos + 1];
	}

	//˳����ȼ�һ
	list->length--;
	return Ok;
}
Pos SeqListFind(SeqList list, SeqData data)											//����(��ȡλ��)
{
	//˳���һ������
	assert(&list);
	//����Ƿ�Ϊ��
	if (isSeqListEmpty(list) == True) return Error;
	
	Pos curPos;
	Length length = list.length;
	for (curPos = 1; curPos <= length; curPos++)
	{
		if (list.a[curPos] == data) return curPos;
	}
	if (curPos > length) return 0;
}
Status SeqListModify(SeqList* list, Pos pos, SeqData data)							//�޸�
{
	//˳���һ������
	assert(&list);
	//����Ƿ�Ϊ��
	if (isSeqListEmpty(*list) == True) return Error;
	//���λ���Ƿ����
	if (isSeqListExsistPos(*list,pos) == False) return Error;

	//�޸�
	list->a[pos] = data;
	return Ok;
}
/*��չ����*/
SeqData SeqListFindByPos(SeqList list, Pos pos)										//ͨ��λ�ò���ֵ
{
	//˳���һ������
	assert(&list);
	//����Ƿ�Ϊ��
	if (isSeqListEmpty(list) == True) return Error;
	//���λ���Ƿ����
	if (isSeqListExsistPos(list, pos) == False) return Error;

	//����ֵ
	return list.a[pos];
}
Status SeqListAdd(SeqList* list, SeqData data)										//����(β��)
{
	return SeqListInsert(list,list->length+1,data);
}
Status SeqListDelInEnd(SeqList* list)												//βɾ
{
	return SeqListDelete(list,SeqListLength(*list));
}
Status SeqListAddToHead(SeqList* list, SeqData data)								//ͷ��
{
	return SeqListInsert(list,1,data);
}
Status SeqListDelInHead(SeqList* list)												//ͷɾ
{
	return SeqListDelete(list,1);
}
Status SeqListClearAll(SeqList* list)												//���˳���
{
	assert(list);
	//����Ƿ�Ϊ��
	if (isSeqListEmpty == True) return Error;
	
	//������0��ɾ��
	list->length = 0;
	return Ok;
}
Status SeqListTraverse(SeqList list)												//����˳���(���ֵ)
{
	//˳���������
	assert(&list);

	//����
	Pos curPos;
	Length length = list.length;
	putchar('{');
	for (curPos = 1; curPos <= length; curPos++)
	{
		if (curPos != length) 
			printf("%d, ", list.a[curPos]);
		else
			printf("%d", list.a[curPos]);
	}
	putchar('}');
	putchar('\n');
	return Ok;
}
#pragma endregion

#pragma endregion
#else
#pragma region ��̬˳���

#pragma region �ṹ��������
/*Ԥ�ò���*/
Status SeqListInit(SeqList* list)													//��ʼ��
{
	//�����ַ��ʼ��
	list->a = NULL;
	//˳����Ⱥ�������ʼ��
	list->length = list->capacity = 0;
	return Ok;
}
Status SeqListCheckCapacity(SeqList* list)											//��������ͽ�������
{
	if (list->length == list->capacity)
	{
		int newCapacity = list->capacity == 0 ? 4 : list->capacity * 2;
		SeqData* a = (SeqData*)realloc(list->a, sizeof(SeqData) * newCapacity);
		assert(a);//����ʧ��ʱ
		list->a = a;
		list->capacity = newCapacity;
	}
	return Ok;
}
Boolean isSeqListEmpty(SeqList list)												//����Ƿ�Ϊ��
{
	return list.length == 0;
}
Boolean isSeqListExsistPos(SeqList list, Pos pos)									//���λ���Ƿ����
{
	return pos >= 1 && pos <= list.length;
}
Length SeqListLength(SeqList list)													//˳�����
{
	return list.length;
}
/*��������*/
Status SeqListInsert(SeqList* list, Pos pos, SeqData data)							//����
{
	//˳���������
	assert(list);
	//�������
	SeqListCheckCapacity(list);
	//���λ���Ƿ����
	if (pos <= 0 || pos > list->length + 1) return Error;

	//λ�ò���β������һ��
	if (pos <= list->length)
	{
		int curPos = pos;
		Length length = list->length;
		//��ָ��λ�ú��������Ԫ�غ���һλ
		for (curPos = length; curPos >= pos; curPos--)
		{
			list->a[curPos + 1] = list->a[curPos];
		}
		//������Ԫ�ز���ָ��λ��
		list->a[pos] = data;
	}
	//λ����β������һ��
	else if (pos == list->length + 1)
	{
		//������Ԫ�ز���ָ��λ��
		list->a[pos] = data;
	}
	//��������
	list->length++;
	return Ok;
}
Status SeqListDelete(SeqList* list, Pos pos)										//ɾ��
{
	//˳���������
	assert(list);
	//˳�����Ϊ��
	if (isSeqListEmpty(*list) == True) return Error;
	//ָ��λ�ô���
	if (isSeqListExsistPos(*list, pos) == False) return Error;

	//ָ��λ��֮�������Ԫ��ǰ��һλ
	Pos curPos;
	Length length = list->length;
	for (curPos = pos; curPos <= length - 1; curPos++)
	{
		list->a[curPos] = list->a[curPos + 1];
	}

	//˳����ȼ�һ
	list->length--;
	return Ok;
}
Pos SeqListFind(SeqList list, SeqData data)											//����(��ȡλ��)
{
	//˳���һ������
	assert(&list);
	//����Ƿ�Ϊ��
	if (isSeqListEmpty(list) == True) return Error;

	Pos curPos;
	Length length = list.length;
	for (curPos = 1; curPos <= length; curPos++)
	{
		if (list.a[curPos] == data) return curPos;
	}
	if (curPos > length) return 0;
}
Status SeqListModify(SeqList* list, Pos pos, SeqData data)							//�޸�
{
	//˳���һ������
	assert(&list);
	//����Ƿ�Ϊ��
	if (isSeqListEmpty(*list) == True) return Error;
	//���λ���Ƿ����
	if (isSeqListExsistPos(*list, pos) == False) return Error;

	//�޸�
	list->a[pos] = data;
	return Ok;
}
/*��չ����*/
SeqData SeqListFindByPos(SeqList list, Pos pos)										//ͨ��λ�ò���ֵ
{
	//˳���һ������
	assert(&list);
	//����Ƿ�Ϊ��
	if (isSeqListEmpty(list) == True) return Error;
	//���λ���Ƿ����
	if (isSeqListExsistPos(list, pos) == False) return Error;

	//����ֵ
	return list.a[pos];
}
Status SeqListAdd(SeqList* list, SeqData data)										//����(β��)
{
	return SeqListInsert(list, list->length + 1, data);
}
Status SeqListDelInEnd(SeqList* list)												//βɾ
{
	return SeqListDelete(list, SeqListLength(*list));
}
Status SeqListAddToHead(SeqList* list, SeqData data)								//ͷ��
{
	return SeqListInsert(list, 1, data);
}
Status SeqListDelInHead(SeqList* list)												//ͷɾ
{
	return SeqListDelete(list, 1);
}
Status SeqListClearAll(SeqList* list)												//���˳���
{
	assert(list);
	//����Ƿ�Ϊ��
	if (isSeqListEmpty == True) return Error;

	//������0��ɾ��
	list->length = 0;
	return Ok;
}
Status SeqListTraverse(SeqList list)												//����˳���(���ֵ)
{
	//˳���������
	assert(&list);

	//����
	Pos curPos;
	Length length = list.length;
	putchar('{');
	for (curPos = 1; curPos <= length; curPos++)
	{
		if (curPos != length)
			printf("%d, ", list.a[curPos]);
		else
			printf("%d", list.a[curPos]);
	}
	putchar('}');
	putchar('\n');
	return Ok;
}
#pragma endregion

#pragma endregion
#endif