#pragma once
#define _CRT_SECURE_NO_WARNINGS														//VS����Ҫ��������������ɾ������
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

typedef enum { Error, Ok } Status;														//״̬����(����/�ɹ�)
typedef enum { False, True } Boolean;													//��������(����/��)

typedef int DCData;																	//˫��ѭ����������
typedef int Pos;																	//˫��ѭ�������±�λ��
typedef long Length;																//˫��ѭ��������
//#define STATIC 0	
#define SLL



#pragma region ˫��ѭ������

#pragma region �ṹ����
//˫��ѭ��������ṹ����
typedef struct Node
{
	DCData data;
	struct Node* prev,*next;
}Node;
//˫��ѭ������ṹ�嶨��
typedef struct
{
	Node* head;
	Length len;
}DCList;
#pragma endregion

#pragma region �ṹ��������
/*Ԥ�ò���*/
Status DCListInit(DCList* list);												//��ʼ��
Node* DCListGetNewNode();														//��ȡ�½��
Boolean isDCListEmpty(DCList list);												//����Ƿ�Ϊ��
Boolean isDCListExsistPos(DCList list, Pos pos);								//���λ���Ƿ����
Length DCListLength(DCList list);												//˫��ѭ��������
/*��������*/
Status DCListInsert(DCList* list, Pos pos, DCData data);							//����
Status DCListDelete(DCList* list, Pos pos);										//ɾ��
Pos DCListFind(DCList list, DCData data);										//����(��ȡλ��)
Status DCListModify(DCList* list, Pos pos, DCData data);							//�޸�
/*��չ����*/
DCData DCListFindByPos(DCList list, Pos pos);									//ͨ��λ�ò���ֵ
Status DCListAdd(DCList* list, DCData data);										//����(β��)
Status DCListDelInEnd(DCList* list);											//βɾ
Status DCListAddToHead(DCList* list, DCData data);								//ͷ��
Status DCListDelInHead(DCList* list);											//ͷɾ
Status DCListClearAll(DCList* list);											//���˫��ѭ������
Status DCListTraverse(DCList list);												//����˫��ѭ������(���ֵ)
#pragma endregion

#pragma endregion