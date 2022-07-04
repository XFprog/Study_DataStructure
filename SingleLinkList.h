#pragma once
#define _CRT_SECURE_NO_WARNINGS														//VS����Ҫ��������������ɾ������
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

typedef enum { Error, Ok } Status;														//״̬����(����/�ɹ�)
typedef enum { False, True } Boolean;													//��������(����/��)

typedef int SData;																	//����������
typedef int Pos;																	//�������±�λ��
typedef long Length;																//��������
//#define STATIC 0	
#define SLL



#pragma region ������

#pragma region �ṹ����
//��������ṹ����
typedef struct Node
{
	SData data;
	struct Node* next;
}Node;
//������ṹ�嶨��
typedef struct
{
	Node* head;
	Length len;
}SList;
#pragma endregion

#pragma region �ṹ��������
/*Ԥ�ò���*/
Status SListInit(SList* list);													//��ʼ��
Node* SListGetNewNode();														//��ȡ�½��
Boolean isSListEmpty(SList list);												//����Ƿ�Ϊ��
Boolean isSListExsistPos(SList list, Pos pos);									//���λ���Ƿ����
Length SListLength(SList list);													//��������
/*��������*/
Status SListInsert(SList* list, Pos pos, SData data);							//����
Status SListDelete(SList* list, Pos pos);										//ɾ��
Pos SListFind(SList list, SData data);											//����(��ȡλ��)
Status SListModify(SList* list, Pos pos, SData data);							//�޸�
/*��չ����*/
SData SListFindByPos(SList list, Pos pos);										//ͨ��λ�ò���ֵ
Status SListAdd(SList* list, SData data);										//����(β��)
Status SListDelInEnd(SList* list);												//βɾ
Status SListAddToHead(SList* list, SData data);									//ͷ��
Status SListDelInHead(SList* list);												//ͷɾ
Status SListClearAll(SList* list);												//��յ�����
Status SListTraverse(SList list);												//����������(���ֵ)
#pragma endregion

#pragma endregion