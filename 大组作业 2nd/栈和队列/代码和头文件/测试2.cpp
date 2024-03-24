#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
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

typedef int QElemType;
//���ӽ��Ķ���
typedef struct Qnode {
	QElemType data;
	struct Qnode* next;
} QNode, *QueuePtr;
//���ӵĶ���
typedef struct {
	QueuePtr front;		//��ͷָ��
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
void menu(){
	printf("**************************************************************\n");
	printf("***********************��ѡ��Ҫ�����Ķ���*********************\n");
	printf("*************************1.˳��ջ�Ĳ���***********************\n");
	printf("*********2.��ʽ���е�ʵ�֣���֧�ֲ�ͬ�������͡�������*********\n");
	printf("**************************************************************\n");
	printf("**************************************************************\n");
	int input;
begin: 
	scanf("%d",&input);
	switch(input){
		case 1: 
			SqStack s;
			InitSqStack(&s);
			sqmenu(s);
			break;
		case 2:
			LinkQueue q; 
			InitLinkQueue(&q);
			lkmenu(q);
			break;
		default : printf("����������\n");
				goto begin;
				break;
	}
	
}
void sqmenu(SqStack s){
	int n,n1;
	printf("*************************************\n");
	printf("********������Ҫ���еĲ�����*********\n");
	printf("****1.�п�*****2.����*****3.���*****\n");
	printf("****4.��ջ*****5.��ջ*****6.���*****\n");
	printf("***************7.�˳�****************\n");
	printf("*************************************\n");
begin: 
	int input;
	scanf("%d",&input);
	switch(input){
		case 1: if(IsEmptySqStack(&s)==1) printf("\nΪ��\n");
				else printf("\n��Ϊ��\n");
				sqmenu(s);
				break;
		case 2: if(IsFullSqStack(&s)==1) printf("\nΪ��\n");
				else printf("\n��Ϊ��\n");
				sqmenu(s);
				break;
		case 3:	ClearSqStack(&s);
				ShowSqStack(&s);
				printf("\n���������Ϊ��\n");
				sqmenu(s);
				break;
		case 4: 
				printf("������Ҫ��ջ�����֣�");
				scanf("%d",&n);
				Push(&s, &n);
				printf("\n");
				printf("������������ӣ�\n");
				ShowSqStack(&s);
				printf("\n");
				printf("\n");
				sqmenu(s);
				break;
		case 5:
				printf("\n��ջ�������������");
				Pop(&s,&n1);
				printf("%d",n1);
				printf("\n");
				sqmenu(s);
				break;
		case 6: ShowSqStack(&s);
				printf("\n���������Ϊ��\n");
				printf("\n");
				sqmenu(s);
				break;
		case 7 :
			printf("����Ҫ�˳���");	
			printf("����������˳���");
			getch();
			system("pause");
			exit(-1);
		default : printf("����������\n");
				goto begin;
				break;
				
} 
}
void lkmenu(LinkQueue q){
	int num,num1;
	printf("*************************************\n");
	printf("********������Ҫ���еĲ�����*********\n");
	printf("****1.���*****2.����*****3.ͷԪ��***\n");
	printf("****4.����*****5.���*****6.�˳�*****\n");
	printf("*************************************\n");
begin: 
	int input;
	scanf("%d",&input);
	switch(input){
		case 1: printf("\n������Ҫ��������֣�");
			scanf("%d",&num);
			EnLinkQueue(&q,&num);
			lkmenu(q);
			break; 
		case 2: 
			DeLinkQueue(&q,&num1);
			printf("\n���ӵ�Ԫ��Ϊ:%d\n",num1);
			lkmenu(q);
			break; 
		case 3: int num2;
			printf("\n��ͷ��Ԫ��ֵΪ:%d\n",GetHead(&q));
			lkmenu(q);
			break; 	
		case 4: DestoryLinkQueue(&q);
			printf("\n���������Ϊ�գ�����ɹ���:\n");
			printf("����Ҫ�˳�");
			ShowLinkQueue(q);	
			lkmenu(q);
			break;
		case 5: printf("\n���������Ϊ��:\n");
			ShowLinkQueue(q);
			printf("\n");	
			lkmenu(q);
			break;
		case 6 :
			printf("����Ҫ�˳���");	
			printf("����������˳���");
			getch();
			system("pause");
			exit(-1);
		default : printf("����������\n");
				goto begin;
				break;
}
}
int main(){
	menu();
	return 0;
}
