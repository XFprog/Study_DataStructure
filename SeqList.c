#include "SeqList.h"



#ifdef STATIC
#pragma region 静态顺序表

#pragma region 结构操作定义
/*预置操作*/
Status SeqListInit(SeqList* list)													//初始化
{
	//顺序表长度初始化
	list->length = 0;
	return Ok;
}
Boolean isSeqListEmpty(SeqList list)												//检测是否为空
{
	return list.length == 0;
}
Boolean isSeqListFull(SeqList list)													//检测是否已满
{
	return list.length == MAXSIZE;
}
Boolean isSeqListExsistPos(SeqList list, Pos pos)									//检测位置是否存在
{
	return pos>=1 && pos <= list.length;
}
Length SeqListLength(SeqList list)													//顺序表长度
{
	return list.length;
}
/*基本操作*/
Status SeqListInsert(SeqList* list, Pos pos, SeqData data)							//插入
{
	//顺序表必须存在
	assert(list);
	//检测是否满
	if (isSeqListFull(*list) == True) return Error;
	//检测位置是否存在
	if (pos<=0||pos>list->length+1) return Error;

	//位置不在尾部的下一个
	if (pos <= list->length)
	{
		int curPos = pos;
		Length length = list->length;
		//将指定位置后面的所有元素后移一位
		for (curPos = length; curPos >= pos; curPos--)
		{
			list->a[curPos + 1] = list->a[curPos];
		}
		//将给定元素插入指定位置
		list->a[pos] = data;
	}
	//位置在尾部的下一个
	else if (pos == list->length + 1)
	{
		//将给定元素插入指定位置
		list->a[pos] = data;
	}
	//长度增加
	list->length++;
	return Ok;
}
Status SeqListDelete(SeqList* list, Pos pos)										//删除
{
	//顺序表必须存在
	assert(list);
	//顺序表不能为空
	if (isSeqListEmpty(*list) == True) return Error;
	//指定位置存在
	if (isSeqListExsistPos(*list, pos) == False) return Error;

	//指定位置之后的所有元素前移一位
	Pos curPos;
	Length length = list->length;
	for (curPos = pos; curPos <= length-1; curPos++)
	{
		list->a[curPos] = list->a[curPos + 1];
	}

	//顺序表长度减一
	list->length--;
	return Ok;
}
Pos SeqListFind(SeqList list, SeqData data)											//查找(获取位置)
{
	//顺序表一定存在
	assert(&list);
	//检测是否为空
	if (isSeqListEmpty(list) == True) return Error;
	
	Pos curPos;
	Length length = list.length;
	for (curPos = 1; curPos <= length; curPos++)
	{
		if (list.a[curPos] == data) return curPos;
	}
	if (curPos > length) return 0;
}
Status SeqListModify(SeqList* list, Pos pos, SeqData data)							//修改
{
	//顺序表一定存在
	assert(&list);
	//检测是否为空
	if (isSeqListEmpty(*list) == True) return Error;
	//检测位置是否存在
	if (isSeqListExsistPos(*list,pos) == False) return Error;

	//修改
	list->a[pos] = data;
	return Ok;
}
/*扩展操作*/
SeqData SeqListFindByPos(SeqList list, Pos pos)										//通过位置查找值
{
	//顺序表一定存在
	assert(&list);
	//检测是否为空
	if (isSeqListEmpty(list) == True) return Error;
	//检测位置是否存在
	if (isSeqListExsistPos(list, pos) == False) return Error;

	//返回值
	return list.a[pos];
}
Status SeqListAdd(SeqList* list, SeqData data)										//增添(尾插)
{
	return SeqListInsert(list,list->length+1,data);
}
Status SeqListDelInEnd(SeqList* list)												//尾删
{
	return SeqListDelete(list,SeqListLength(*list));
}
Status SeqListAddToHead(SeqList* list, SeqData data)								//头插
{
	return SeqListInsert(list,1,data);
}
Status SeqListDelInHead(SeqList* list)												//头删
{
	return SeqListDelete(list,1);
}
Status SeqListClearAll(SeqList* list)												//清空顺序表
{
	assert(list);
	//检测是否为空
	if (isSeqListEmpty == True) return Error;
	
	//长度置0即删除
	list->length = 0;
	return Ok;
}
Status SeqListTraverse(SeqList list)												//遍历顺序表(输出值)
{
	//顺序表必须存在
	assert(&list);

	//遍历
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
#pragma region 动态顺序表

#pragma region 结构操作定义
/*预置操作*/
Status SeqListInit(SeqList* list)													//初始化
{
	//数组地址初始化
	list->a = NULL;
	//顺序表长度和容量初始化
	list->length = list->capacity = 0;
	return Ok;
}
Status SeqListCheckCapacity(SeqList* list)											//检测容量和进行扩容
{
	if (list->length == list->capacity)
	{
		int newCapacity = list->capacity == 0 ? 4 : list->capacity * 2;
		SeqData* a = (SeqData*)realloc(list->a, sizeof(SeqData) * newCapacity);
		assert(a);//分配失败时
		list->a = a;
		list->capacity = newCapacity;
	}
	return Ok;
}
Boolean isSeqListEmpty(SeqList list)												//检测是否为空
{
	return list.length == 0;
}
Boolean isSeqListExsistPos(SeqList list, Pos pos)									//检测位置是否存在
{
	return pos >= 1 && pos <= list.length;
}
Length SeqListLength(SeqList list)													//顺序表长度
{
	return list.length;
}
/*基本操作*/
Status SeqListInsert(SeqList* list, Pos pos, SeqData data)							//插入
{
	//顺序表必须存在
	assert(list);
	//检测容量
	SeqListCheckCapacity(list);
	//检测位置是否存在
	if (pos <= 0 || pos > list->length + 1) return Error;

	//位置不在尾部的下一个
	if (pos <= list->length)
	{
		int curPos = pos;
		Length length = list->length;
		//将指定位置后面的所有元素后移一位
		for (curPos = length; curPos >= pos; curPos--)
		{
			list->a[curPos + 1] = list->a[curPos];
		}
		//将给定元素插入指定位置
		list->a[pos] = data;
	}
	//位置在尾部的下一个
	else if (pos == list->length + 1)
	{
		//将给定元素插入指定位置
		list->a[pos] = data;
	}
	//长度增加
	list->length++;
	return Ok;
}
Status SeqListDelete(SeqList* list, Pos pos)										//删除
{
	//顺序表必须存在
	assert(list);
	//顺序表不能为空
	if (isSeqListEmpty(*list) == True) return Error;
	//指定位置存在
	if (isSeqListExsistPos(*list, pos) == False) return Error;

	//指定位置之后的所有元素前移一位
	Pos curPos;
	Length length = list->length;
	for (curPos = pos; curPos <= length - 1; curPos++)
	{
		list->a[curPos] = list->a[curPos + 1];
	}

	//顺序表长度减一
	list->length--;
	return Ok;
}
Pos SeqListFind(SeqList list, SeqData data)											//查找(获取位置)
{
	//顺序表一定存在
	assert(&list);
	//检测是否为空
	if (isSeqListEmpty(list) == True) return Error;

	Pos curPos;
	Length length = list.length;
	for (curPos = 1; curPos <= length; curPos++)
	{
		if (list.a[curPos] == data) return curPos;
	}
	if (curPos > length) return 0;
}
Status SeqListModify(SeqList* list, Pos pos, SeqData data)							//修改
{
	//顺序表一定存在
	assert(&list);
	//检测是否为空
	if (isSeqListEmpty(*list) == True) return Error;
	//检测位置是否存在
	if (isSeqListExsistPos(*list, pos) == False) return Error;

	//修改
	list->a[pos] = data;
	return Ok;
}
/*扩展操作*/
SeqData SeqListFindByPos(SeqList list, Pos pos)										//通过位置查找值
{
	//顺序表一定存在
	assert(&list);
	//检测是否为空
	if (isSeqListEmpty(list) == True) return Error;
	//检测位置是否存在
	if (isSeqListExsistPos(list, pos) == False) return Error;

	//返回值
	return list.a[pos];
}
Status SeqListAdd(SeqList* list, SeqData data)										//增添(尾插)
{
	return SeqListInsert(list, list->length + 1, data);
}
Status SeqListDelInEnd(SeqList* list)												//尾删
{
	return SeqListDelete(list, SeqListLength(*list));
}
Status SeqListAddToHead(SeqList* list, SeqData data)								//头插
{
	return SeqListInsert(list, 1, data);
}
Status SeqListDelInHead(SeqList* list)												//头删
{
	return SeqListDelete(list, 1);
}
Status SeqListClearAll(SeqList* list)												//清空顺序表
{
	assert(list);
	//检测是否为空
	if (isSeqListEmpty == True) return Error;

	//长度置0即删除
	list->length = 0;
	return Ok;
}
Status SeqListTraverse(SeqList list)												//遍历顺序表(输出值)
{
	//顺序表必须存在
	assert(&list);

	//遍历
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