#include "stdafx.h"
#include "stdlib.h"
#include "seqlist.h"

void IniList(SeqList *l, int n)
{//构造函数
	l->data = (Type*)malloc(n * sizeof(Type));
	if (l->data == NULL)
	{
		printf("Memory allocation error\n");
		exit(1);
	}
	l->size = 0;
	l->max = n;
}
void FreeList(SeqList *l)
{//析构函数
	free(l->data);
}
void InsertRear(SeqList *l, Type item)
{//于最后写入数据
	if (l->size == l->max)
	{
		printf("InsertRear:list is full!\n");
		exit(1);
	}
	l->data[l->size] = item;
	l->size++;
}
void Insert(SeqList *l, int id, Type item)
{//定点插入
	int i;
	if (id<0 || id>l->size || l->size == l->max)
	{
		printf("Insert:id is illegal or list is full!\n");
		exit(1);
	}
	for (i = l->size - 1; i >= id; --i)
		l->data[i + 1] = l->data[i];
	l->data[id] = item;
	l->size++;
}
void Erase(SeqList *l, int id)
{//定点删除
	int i;
	if (id<0 || id>l->size - 1)
	{
		printf("Erase:id is illegal or list is empty!\n");
		exit(1);
	}
	for (i = id + 1; i < l->size; ++i)
		l->data[i - 1] = l->data[i];
	l->size--;
}
void purge_seqlist(SeqList *l)
{//删除重复数据
	int i, j;
	for (i = 0; i < Size(l) - 1; ++i)
	{
		j = i + 1;
		while (j < Size(l))
			if (Getdata(l, i) == Getdata(l, j))
				Erase(l, j);
			else
				++j;
	}
}
void Clear(SeqList *l)
{//清表
	l->size = 0;
}
Type Getdata(const SeqList *l, int id)
{//取id处值
	if (id<0 || id>l->size - 1)
	{
		printf("Getdata:id is illegal or list is empty!\n");
		exit(1);
	}
	return l->data[id];
}
int Size(const SeqList *l)
{//取大小值
	return l->size;
}
int Empty(const SeqList *l)
{//判空
	return l->size == 0;
}
int Full(const SeqList *l)
{
	return l->size == l->max;
}
Type *Begin(const SeqList *l)
{
	return l->data;
}
Type *End(const SeqList *l)
{
	return l->data + l->size;
}
/*
void display_seqlist(const SeqList *l)
{//输出顺序表//基于索引
	int i;
	for (i = 0; i < Size(l); ++i)
		printf("%d\t", Getdata(l, i));
	printf("\n");
}
*/
void display_seqlist(const Type *first, const Type *last)
{//输出顺序表//基于指针
	for (; first != last; first++)
		printf("%d\t", *first);
	printf("\n");
}
