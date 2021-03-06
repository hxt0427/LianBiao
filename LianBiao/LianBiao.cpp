// LianBiao.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include"pch.h"
#include <iostream>
#include<stdlib.h>

struct Node {
	int Date;
	struct Node * next;
};

struct Node* Create() {   //创建空链表
	struct Node *L;
	L = (struct Node *)malloc(sizeof(struct Node));
	L->next = NULL;
	return L;
}

void Insert(struct Node *L, int x) { //L为链表的头结点    在链表末尾插入
	struct Node *p, *q;
	p = L;
    while (p->next != NULL && x >= p->Date)
		p = p->next;
	q = (struct Node *)malloc(sizeof(struct Node));
	q->Date = x;
	q->next = p->next;
	p->next = q;
}

int Delete(struct Node *p) { //删除带头结点的链表 节点p的下一个节点
	struct Node *q;
	int tmp;
	q = p->next;
	if (q != NULL) {
		p->next = q->next;
		tmp = q->Date;
		free(q);
	}
	return tmp;
}

void Print(struct Node *L) {    //打印链表
	struct Node *p;
	p = L;
	while (p->next != NULL) {
		p = p->next;
		printf("%d ", p->Date);
	}
	printf("\n");
}

int Number(struct Node * L) {
	int sum = 0;
	struct Node *p;
	p = L;
	while (p->next != NULL) {
		p = p->next;
		sum++;
	}
	return sum;
}

void Insert2(struct Node* p , int num) {
	struct Node *q;
	q = (struct Node *)malloc(sizeof(struct Node));
	q->Date = num;
	q->next = p->next;
	p->next = q;
}

void slim(struct Node *L) {
	struct Node *p,*q;
	p = L;
	while (p->next!= NULL) {
		p = p->next;
		q = p->next;
		while (p->Date == q->Date) {
			p->next =q->next;
		    free(q);
			q = p->next;
	    }
	}	
}
int main()
{
	struct Node *L;
	L = Create();
//	int tmp;
//	for (int i = 0; i < 10; i++) {
//		Insert(L,i);
//	}
//	Print(L);
//	struct Node*p;
//	p = L;
//	while (p->Date != 5) {
//		p = p->next;
//	}
//	printf("%d\n", Number(L));
//	tmp = Delete(p);
//	Insert2(L->next, 22);
//	Print(L);
//	printf("%d\n", L->next->Date);
	int num;
	for (int i = 0; i < 10; i++){
		scanf_s("%d",&num);
		Insert(L,num);
	}
	Print(L);
//	slim(L);
	//Print(L);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
