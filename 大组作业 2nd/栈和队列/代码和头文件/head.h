#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "head.h"
#include <conio.h>
//函数结果状态代码
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0
//宏定义
#define MAXSIZE 100
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef int SElemType;
//顺序栈的定义
typedef struct {
	SElemType* top;
	SElemType* base;
	int stacksize;
} SqStack;

typedef int QElemType;
//链队结点的定义
typedef struct Qnode {
	QElemType data;
	struct Qnode* next;
} QNode, *QueuePtr;
//链队的定义
typedef struct {
	QueuePtr front;		//队头指针
	QueuePtr rear;
} LinkQueue;

Status InitSqStack(SqStack *s);
Status IsEmptySqStack(SqStack *s);
Status IsFullSqStack(SqStack *s);
Status ClearSqStack(SqStack *s);
Status DestroySqStack(SqStack *s);
Status Push(SqStack *s, SElemType* num);
Status Pop(SqStack *s,SElemType* num);
Status ShowSqStack(SqStack *s);



Status InitLinkQueue(LinkQueue* q);
Status DestoryLinkQueue(LinkQueue* q);
Status EnLinkQueue(LinkQueue *q,QElemType* num);
Status DeLinkQueue(LinkQueue *q,QElemType* num); 
QElemType GetHead(LinkQueue *q);
void ShowLinkQueue(LinkQueue q);

void menu();
void sqmenu(SqStack s);
void lkmenu(LinkQueue q);
#endif
