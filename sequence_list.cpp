// 顺序表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "seqlist.h"
int main()
{
	/*//基本操作
	int i, n;
	SeqList L;
	IniList(&L, 10);
	InsertRear(&L, 5);
	InsertRear(&L, 15);
	InsertRear(&L, 20);
	Insert(&L, 1, 10);
	Erase(&L, 0);
	n = Size(&L);
	for (i = 0; i < n; ++i)
		printf("%d\t", Getdata(&L, i));
	Clear(&L);
	FreeList(&L);*/
	//删除重复数据
	int i, n;
	SeqList L;
	IniList(&L, 10);
	printf("Input 10 integers:\n");
	for (i = 0; i < 10; ++i)
	{
		scanf_s("%d", &n);
		InsertRear(&L, n);
	}
	purge_seqlist(&L);
	//display_seqlist(&L);//基于索引
	display_seqlist(Begin(&L), End(&L));
	FreeList(&L);
    return 0;
	
}

