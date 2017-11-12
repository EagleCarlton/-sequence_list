#pragma once
typedef int Type;//只能写在此头文件，否则有一大堆错误
typedef struct SeqList//顺序表结构
{
	Type *data;//typedef int Type;
	int size;//元素个数
	int max;//最大允许元素个数
}SeqList;
//准构造函数和准析构函数
void IniList(SeqList *l, int n);//生成空表
void FreeList(SeqList *l);//释放动态数组空间
//用于修改的基本操作函数
void InsertRear(SeqList *l, Type item);//在最后一个数据后插入一个数据
void Insert(SeqList *l, int id, Type item);//在id处插入一个数据
void Erase(SeqList *l, int id);//删除id处数据
void purge_seqlist(SeqList *l);//删除重复数据
void Clear(SeqList *l);//清表，令size=0
//用于读取的基本操作函数
Type Getdata(const SeqList *l, int id);//取id处数据
int Size(const SeqList *l);//取数据个数值
int Empty(const SeqList *l);//判空
int Full(const SeqList *l);//判满
Type *Begin(const SeqList *l);//返回数据首元素指针
Type *End(const SeqList *l);//返回数据尾元素的下一个元素指针
//void display_seqlist(const SeqList *l);//输出顺序表//基于索引
void display_seqlist(const Type *first, const Type *last);//输出顺序表//基于指针
