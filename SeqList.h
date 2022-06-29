#pragma once
#define _CRT_SECURE_NO_WARNINGS														//VS����Ҫ��������������ɾ������
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

typedef enum{Error,Ok} Status;														//״̬����(����/�ɹ�)
typedef enum{False,True} Boolean;													//��������(����/��)

typedef int SeqData;																//˳�������
typedef int Pos;																	//˳����±�λ��
typedef long Length;																//˳�����
//˳�������(��̬/��̬��ͨ��ע�Ϳ�������)
//#define STATIC 0																	
#define DYNAMIC 1


#ifdef STATIC

#pragma region ��̬˳���

//˳�����󳤶�
#define MAXSIZE 20

#pragma region �ṹ����
//��̬˳���ṹ����
typedef struct
{
	SeqData a[MAXSIZE+1];	//˳�������(�±��1��ʼ)
	Length length;			//˳�����
}SeqList;
#pragma endregion

#pragma region �ṹ��������
/*Ԥ�ò���*/
Status SeqListInit(SeqList* list);													//��ʼ��
Boolean isSeqListEmpty(SeqList list);												//����Ƿ�Ϊ��
Boolean isSeqListFull(SeqList list);												//����Ƿ�����
Boolean isSeqListExsistPos(SeqList list, Pos pos);									//���λ���Ƿ����
Length SeqListLength(SeqList list);													//˳�����
/*��������*/
Status SeqListInsert(SeqList* list, Pos pos, SeqData data);							//����
Status SeqListDelete(SeqList* list, Pos pos);										//ɾ��
Pos SeqListFind(SeqList list, SeqData data);										//����(��ȡλ��)
Status SeqListModify(SeqList* list, Pos pos, SeqData data);							//�޸�
/*��չ����*/
SeqData SeqListFindByPos(SeqList list, Pos pos);									//ͨ��λ�ò���ֵ
Status SeqListAdd(SeqList* list, SeqData data);										//����(β��)
Status SeqListDelInEnd(SeqList* list);												//βɾ
Status SeqListAddToHead(SeqList* list, SeqData data);								//ͷ��
Status SeqListDelInHead(SeqList* list);												//ͷɾ
Status SeqListClearAll(SeqList* list);												//���˳���
Status SeqListTraverse(SeqList list);												//����˳���(���ֵ)
#pragma endregion

#pragma endregion
	
#else 

#pragma region ��̬˳���

//˳�����󳤶�
#define MAXSIZE 20

#pragma region �ṹ����
//��̬˳���ṹ����
typedef struct
{
	SeqData* a;				//˳�������(�±��1��ʼ)
	Length length;			//˳�����
	Length capacity;		//����
}SeqList;
#pragma endregion

#pragma region �ṹ��������
/*Ԥ�ò���*/
Status SeqListInit(SeqList* list);													//��ʼ��
Status SeqListCheckCapacity(SeqList* list);											//��������ͽ�������
Boolean isSeqListEmpty(SeqList list);												//����Ƿ�Ϊ��
Boolean isSeqListExsistPos(SeqList list, Pos pos);									//���λ���Ƿ����
Length SeqListLength(SeqList list);													//˳�����
/*��������*/
Status SeqListInsert(SeqList* list, Pos pos, SeqData data);							//����
Status SeqListDelete(SeqList* list, Pos pos);										//ɾ��
Pos SeqListFind(SeqList list, SeqData data);										//����(��ȡλ��)
Status SeqListModify(SeqList* list, Pos pos, SeqData data);							//�޸�
/*��չ����*/
SeqData SeqListFindByPos(SeqList list, Pos pos);									//ͨ��λ�ò���ֵ
Status SeqListAdd(SeqList* list, SeqData data);										//����(β��)
Status SeqListDelInEnd(SeqList* list);												//βɾ
Status SeqListAddToHead(SeqList* list, SeqData data);								//ͷ��
Status SeqListDelInHead(SeqList* list);												//ͷɾ
Status SeqListClearAll(SeqList* list);												//���˳���
Status SeqListTraverse(SeqList list);												//����˳���(���ֵ)
#pragma endregion

#pragma endregion

#endif