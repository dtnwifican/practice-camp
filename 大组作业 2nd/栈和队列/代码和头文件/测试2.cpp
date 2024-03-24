#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
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
void menu(){
	printf("**************************************************************\n");
	printf("***********************请选择要操作的对象*********************\n");
	printf("*************************1.顺序栈的操作***********************\n");
	printf("*********2.链式队列的实现（不支持不同数据类型。。。）*********\n");
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
		default : printf("请重新输入\n");
				goto begin;
				break;
	}
	
}
void sqmenu(SqStack s){
	int n,n1;
	printf("*************************************\n");
	printf("********请输入要进行的操作：*********\n");
	printf("****1.判空*****2.判满*****3.清空*****\n");
	printf("****4.入栈*****5.出栈*****6.输出*****\n");
	printf("***************7.退出****************\n");
	printf("*************************************\n");
begin: 
	int input;
	scanf("%d",&input);
	switch(input){
		case 1: if(IsEmptySqStack(&s)==1) printf("\n为空\n");
				else printf("\n不为空\n");
				sqmenu(s);
				break;
		case 2: if(IsFullSqStack(&s)==1) printf("\n为满\n");
				else printf("\n不为满\n");
				sqmenu(s);
				break;
		case 3:	ClearSqStack(&s);
				ShowSqStack(&s);
				printf("\n若无输出则为空\n");
				sqmenu(s);
				break;
		case 4: 
				printf("请输入要入栈的数字：");
				scanf("%d",&n);
				Push(&s, &n);
				printf("\n");
				printf("数据是这个样子：\n");
				ShowSqStack(&s);
				printf("\n");
				printf("\n");
				sqmenu(s);
				break;
		case 5:
				printf("\n出栈的数字是这个：");
				Pop(&s,&n1);
				printf("%d",n1);
				printf("\n");
				sqmenu(s);
				break;
		case 6: ShowSqStack(&s);
				printf("\n若无输出则为空\n");
				printf("\n");
				sqmenu(s);
				break;
		case 7 :
			printf("程序将要退出！");	
			printf("输入任意键退出！");
			getch();
			system("pause");
			exit(-1);
		default : printf("请重新输入\n");
				goto begin;
				break;
				
} 
}
void lkmenu(LinkQueue q){
	int num,num1;
	printf("*************************************\n");
	printf("********请输入要进行的操作：*********\n");
	printf("****1.入队*****2.出队*****3.头元素***\n");
	printf("****4.销毁*****5.输出*****6.退出*****\n");
	printf("*************************************\n");
begin: 
	int input;
	scanf("%d",&input);
	switch(input){
		case 1: printf("\n请输入要输入的数字：");
			scanf("%d",&num);
			EnLinkQueue(&q,&num);
			lkmenu(q);
			break; 
		case 2: 
			DeLinkQueue(&q,&num1);
			printf("\n出队的元素为:%d\n",num1);
			lkmenu(q);
			break; 
		case 3: int num2;
			printf("\n队头的元素值为:%d\n",GetHead(&q));
			lkmenu(q);
			break; 	
		case 4: DestoryLinkQueue(&q);
			printf("\n若无输出则为空（清除成功）:\n");
			printf("程序将要退出");
			ShowLinkQueue(q);	
			lkmenu(q);
			break;
		case 5: printf("\n若无输出则为空:\n");
			ShowLinkQueue(q);
			printf("\n");	
			lkmenu(q);
			break;
		case 6 :
			printf("程序将要退出！");	
			printf("输入任意键退出！");
			getch();
			system("pause");
			exit(-1);
		default : printf("请重新输入\n");
				goto begin;
				break;
}
}
int main(){
	menu();
	return 0;
}
