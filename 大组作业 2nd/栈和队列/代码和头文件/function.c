#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "head.h"
#include <conio.h>

//�������״̬����
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0
//�궨��
#define MAXSIZE 100
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
typedef int SElemType;
//˳��ջ�Ķ���
typedef struct {
	SElemType* top;
	SElemType* base;
	int stacksize;
} SqStack;

Status InitSqStack(SqStack *s){
	s->base = (SElemType*)malloc(MAXSIZE*sizeof(SElemType));
	//��ϰ���������malloc�����Ǵ���һ�������ĵȴ�Ŀռ䣬�ú󷵻��׵�ַ 
	if(s->base == NULL){ //���ٿռ�ʧ�� 
		exit(OVERFLOW); 
	} 
	else{
		s->top = s->base;
		s->stacksize = MAXSIZE;	
		return OK;
	}
} 
//�ж�˳��ջ�Ƿ�Ϊ�գ�
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
//�ж��Ƿ�Ϊ�� :
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
//���ջ��
Status ClearSqStack(SqStack *s){
	if(s==NULL){
		return ERROR;
	}
	else{
		 s->top = s->base;
		 return OK;
	}
} 
//����ջ��
Status DestroySqStack(SqStack *s){
	if(s == NULL){
		return ERROR;
	} 
	else{
		free(s->base);
		//��ϰ���������free�����ǽ���һ��������ַ��ͷָ�룡����
		//Ȼ������������ռ䶼��û
		s->top = NULL;
		s->base = NULL;
		s->stacksize = 0;
	}
} 
//��ջ��
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
//��ջ��
Status Pop(SqStack *s,SElemType* num){
	if(s == NULL || s->top == s->base){
		return ERROR;
	}
	else{
		*num = *(--s->top);
		//�ոո���ˣ����������� 
		return OK; 
	}
} 
//���ջ��
Status ShowSqStack(SqStack *s){
	//SqStack *p = s->base;
	//�������ˣ����������ƫ�
	//���Ӧ�������ݵ�ָ��
	SElemType* p = s->base; 
	if(s == NULL || s->top == s->base){
		return ERROR;
	}
	else{
		while(p!= s->top){
			printf("%d ",*p);
			p++;
			//��ֻ����е����� 
		}
		return OK;
	}
} 
Status InitLinkQueue(LinkQueue* q){
	//�ҵ�front��rear����һ��ָ��
	//�����ڵ� ��㴴������ 
	q->front =	q->rear = (QNode*)malloc(sizeof(QNode));
	if(q->front==NULL||q->rear==NULL)	return ERROR;
	else{
		q->rear->next = NULL;
		//�ȵȿ������β��ָ���Ƿ�����ָһ���ڵ� 
		return OK;
	}
}
//�������ȫ���٣����һ���ڵ㻹���� 
//���ǻ���front=rear��Ϊ�� 
Status DestoryLinkQueue(LinkQueue* q){
	if(q->front == NULL||q->rear == NULL) return ERROR;
//	else{
//		q->front->next = NULL;
//		q->rear = q->front;
//		
//	}��ȫ����ˡ�
//  ��ע�⣡������������û��������������� 
// ���Ǵ�ͷ��ʼɾ��������
	//����ɽ�㷨��������
	QNode* p;
	//q->front����������ҲΪNULL 
	while(q->front!=NULL){ 
		p = q->front->next;
		free(q->front);
		q->front = p;
	} 
} 
//���ӵ���ӣ�β�巨�������� 
Status EnLinkQueue(LinkQueue *q,QElemType* num){
	QNode* new1;
	if(q->front==NULL||q->rear==NULL) return ERROR;
	else{
		new1 = (QNode*)malloc(sizeof(QNode));
		new1->data = *num;
		//��ʱ��β��ָ����ʵ�ˣ���ָ�����һ�������ݵĽڵ㣨�������� 
		//��ע�⣡������Ӧ��������ʵ�֣�����������Ҫ����һ��ʵ�֡� 
		new1->next = q->rear->next;
		q->rear->next = new1;		
		//�����˰�βָ��Ҳ�ƹ�����������
		q->rear = new1;
		q->rear->next = NULL;
		return OK;
//	QNode* new1;
//	new1 = (QNode*)malloc(sizeof(QNode));
//	new1->data = *num;
//	new1->next = q->rear->next;
//	q->rear->next = new1;
//	q->rear = new1;		//���¶���βָ��
//	return OK;
	}
}
//���ӵĳ��ӣ�ȡͷ�ڵ����ģ�������
//Ҫ�пգ�������
Status DeLinkQueue(LinkQueue *q,QElemType* num){
	Qnode *p; 
	if(q->front==NULL||q->rear==NULL) return ERROR;
	if(q->front == q->rear) return ERROR;
	else{
		p = q->front->next;
		*num = p->data;
		//��������Ҳ�ǿ��Եģ����� 
		q->front->next = p->next;
//��ע�⣡��������Ӵ������ֻ��һ��Ԫ�ص����1����������
		if(q->rear == p) q->front = q->rear; 
		free(p);
		return OK;
	}
} 
//��ȡ���ӵ�ͷԪ�أ�������ǰ���Ԫ�ء�
QElemType GetHead(LinkQueue *q){
	//���������пա� 
	if(q->front!=q->rear)
		return q->front->next->data;
} 
//��ʾ����
// ��֪��ԭ��������� /���� 
void ShowLinkQueue(LinkQueue q){
//	���пա�
	if (q.front == q.rear)
	{
		printf("The LinkQueue is Empty\n");

	}
	q.front = q.front->next;			//����ͷ���
	while (q.front!=NULL)
	{
		printf("%d ", q.front->data);
		q.front = q.front->next;
	}
	putchar('\n');
}
