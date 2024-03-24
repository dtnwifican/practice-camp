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

Status InitSqStack(SqStack *s){
	s->base = (SElemType*)malloc(MAXSIZE*sizeof(SElemType));
	//复习！！！这个malloc函数是创建一个连续的等大的空间，让后返回首地址 
	if(s->base == NULL){ //开辟空间失败 
		exit(OVERFLOW); 
	} 
	else{
		s->top = s->base;
		s->stacksize = MAXSIZE;	
		return OK;
	}
} 
//判断顺序栈是否为空：
Status IsEmptySqStack(SqStack *s){
	if(s==NULL){
		return ERROR;
	}
	if (s->top == s->base){
		printf("empty!!!");
		return TRUE;
	}	
	else{
		printf("not empty"); 
		return FALSE;	
	}
}
//判断是否为满 :
Status IsFullSqStack(SqStack *s){
	if(s==NULL){
		return ERROR;
	}
	if(s->top - s->base == MAXSIZE){
		printf("full");
		return TRUE;
	}
	else return FALSE;
}
//清空栈：
Status ClearSqStack(SqStack *s){
	if(s==NULL){
		return ERROR;
	}
	else{
		 s->top = s->base;
		 return OK;
	}
} 
//销毁栈：
Status DestroySqStack(SqStack *s){
	if(s == NULL){
		return ERROR;
	} 
	else{
		free(s->base);
		//复习！！！这个free函数是接收一个连续地址的头指针！！！
		//然后把整个连续空间都搞没
		s->top = NULL;
		s->base = NULL;
		s->stacksize = 0;
	}
} 
//入栈：
Status Push(SqStack *s, SElemType* num){
	if(s == NULL){
		return ERROR;
	}
	else if(s->top-s->base == MAXSIZE){
		return OVERFLOW;
	}
	else{
		*(s->top) = *num;
		s->top++;
		return OK;
	}
} 
//出栈：
Status Pop(SqStack *s,SElemType* num){
	if(s == NULL || s->top == s->base){
		return ERROR;
	}
	else{
		*num = *(--s->top);
		//刚刚搞错了，不用再退了 
		return OK; 
	}
} 
//输出栈：
Status ShowSqStack(SqStack *s){
	//SqStack *p = s->base;
	//这里搞错了，还是理解有偏差啊
	//这个应该是数据的指针
	SElemType* p = s->base; 
	if(s == NULL || s->top == s->base){
		return ERROR;
	}
	else{
		while(p!= s->top){
			printf("%d ",*p);
			p++;
			//就只输出有的数据 
		}
		return OK;
	}
} 
Status InitLinkQueue(LinkQueue* q){
	//我的front和rear都是一个指针
	//创建节点 差点创建错了 
	q->front =	q->rear = (QNode*)malloc(sizeof(QNode));
	if(q->front==NULL||q->rear==NULL)	return ERROR;
	else{
		q->rear->next = NULL;
		//等等看看这个尾部指针是否还往后指一个节点 
		return OK;
	}
}
//这个是完全销毁，最后一个节点还数据 
//但是还有front=rear即为空 
Status DestoryLinkQueue(LinkQueue* q){
	if(q->front == NULL||q->rear == NULL) return ERROR;
//	else{
//		q->front->next = NULL;
//		q->rear = q->front;
//		
//	}【全搞错了】
//  【注意！！！！概念又没搞清楚！！！！】 
// 【是从头开始删！！！】
	//【攀山算法！！！】
	QNode* p;
	//q->front到最后面最后也为NULL 
	while(q->front!=NULL){ 
		p = q->front->next;
		free(q->front);
		q->front = p;
	} 
} 
//链队的入队：尾插法！！！！ 
Status EnLinkQueue(LinkQueue *q,QElemType* num){
	QNode* new1;
	if(q->front==NULL||q->rear==NULL) return ERROR;
	else{
		new1 = (QNode*)malloc(sizeof(QNode));
		new1->data = *num;
		//这时候尾部指针老实了，就指向最后一个有数据的节点（悬念解除） 
		//【注意！！！！应该两步来实现！！！！，不要想着一步实现】 
		new1->next = q->rear->next;
		q->rear->next = new1;		
		//别忘了把尾指针也移过来！！！！
		q->rear = new1;
		q->rear->next = NULL;
		return OK;
//	QNode* new1;
//	new1 = (QNode*)malloc(sizeof(QNode));
//	new1->data = *num;
//	new1->next = q->rear->next;
//	q->rear->next = new1;
//	q->rear = new1;		//更新队列尾指针
//	return OK;
	}
}
//链队的出队：取头节点后面的！！！！
//要判空！！！！
Status DeLinkQueue(LinkQueue *q,QElemType* num){
	Qnode *p; 
	if(q->front==NULL||q->rear==NULL) return ERROR;
	if(q->front == q->rear) return ERROR;
	else{
		p = q->front->next;
		*num = p->data;
		//上面这样也是可以的！！！ 
		q->front->next = p->next;
//【注意！！！！嗨哟啊考虑只有一个元素的情况1！！！！】
		if(q->rear == p) q->front = q->rear; 
		free(p);
		return OK;
	}
} 
//获取链队的头元素：【找最前面的元素】
QElemType GetHead(LinkQueue *q){
	//【别忘了判空】 
	if(q->front!=q->rear)
		return q->front->next->data;
} 
//显示链队
// 不知道原来哪里错了 /捂脸 
void ShowLinkQueue(LinkQueue q){
//	【判空】
	if (q.front == q.rear)
	{
		printf("The LinkQueue is Empty\n");

	}
	q.front = q.front->next;			//跳过头结点
	while (q.front!=NULL)
	{
		printf("%d ", q.front->data);
		q.front = q.front->next;
	}
	putchar('\n');
}
