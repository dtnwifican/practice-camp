#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h>
#include"head.h"
// 实现双链表：

 
//这个没办法搞头节点 

//初始化双链表：
line* initline(){
	line* head;
	head = (line*)malloc(sizeof(line));
	head->prior = NULL;
	head->next = NULL;
	line *p = head;
	line *new1;
	int n=1;
	while(1){
		printf("请输入数据(输入0后不再创建)：");
		scanf("%d",&n);
		if(n==0) break; 
		new1 = (line*)malloc(sizeof(line));
		new1->data = n;
		// 尾插法： 
		p->next = new1;
		new1->prior = p;
		p = p->next;
	}
	return head; 
}

//计算链表的长：
int lenline(line* head){
	line* p = head;
	int n = 0;
	while(p->next!=NULL){
		p = p->next;
		n++;
	}
	return n;
} 

//插入节点：
void insertline(line* head){
	printf("请输入插入的节点的序号（插在这个节点前面）：");
	line* new1;
	int n,n1;
	int j = 1;
	scanf("%d",&n);
	new1 = (line*)malloc(sizeof(line));
	scanf("%d",&n);
	printf("请输入新结点的值："); 
	scanf("%d",&new1->data);
	// n是指插入节点的序号 
	if(n==1){
		line* list = head;
		new1->next = head;
		head->prior = new1;
		head = new1;
		// 不用管new1的prior 
	}
	if(n>lenline(head))	printf("error!");
	else{
		//和前面的都是一样的
		//都是找到前一个节点 
		line *p;
		while(j<n-1){
			p = p->next;
			j++;
		}
		if(p->next == NULL){
			//那就在尾部加
			 p->next = new1;
			 new1->prior = p;
		}
		else{
			//在中间
			p->next->prior = new1;
			new1->next = p->next;
			p->next = new1;
			new1->prior = p;	 
		}
	}
}

//删除节点：按值来删 
void delLine(line *head)
{	int data;
	printf("请输入要查的节点的数据值：");
	scanf("%d",&data); 
    line *p=head;
    //遍历链表
    while(p!=NULL)
    {
        //判断当前结点中数据域和data是否相等，若相等，摘除该结点
        if (p->data==data)
        {
            p->prior->next=p->next;
            p->next->prior=p->prior;
            free(p);
        }
        p=p->next;
    }
    printf("链表中无该数据元素");
}
//更新函数
void changenode(line* head)
{	int i;
	line *p,*s;
	p = head; 
	printf("请输入要修改的节点位置：");
	scanf("%d",&i);
	if(i<0||i==0 || i>lenline(head))
	{
		printf("error\n");
	}
	else
	{	
		int j=0;//跑到第i个前面一个车厢 
		while(j<i-1)
		{
			p = p->next;
			j++; 
		}
		s = p->next;
		printf("请输入该节点的新值：");
		scanf("%d",&s->data); 
	}
 } 

//查找节点,返回节点的位置：
void searchnode(line * head,int elem){
//新建一个指针t，初始化为头指针 head
    line * t=head;
    int i=1;
    while(t)
    {
        if(t->data==elem)
        {
            printf("找到了！！！是第%d个\n",i);
        }
        i++;
        t=t->next;
    }
    //程序执行至此处，表示查找失败
    printf("未找到相关数据！！！");
}

//输出函数：
void display(line *head)
{
    line *temp=head->next;
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
            printf("%d\n",temp->data);
        }
        else
        {
            printf("%d->",temp->data);
        }
        temp=temp->next;
    }
}

