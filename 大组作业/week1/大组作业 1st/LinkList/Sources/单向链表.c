#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h>
#include"head.h"

// 头插法： 
linknode* create()
{
	struct linknode* head ;
	head =(linknode*)malloc(sizeof(linknode));
	head->next=NULL;
	linknode* s;
	int num;
	while(1)//你输入数据如果是>0就继续 
	{
		printf("请输入节点的数据(头插法)（输入0时停止）：");
		scanf("%d",&num); 
		if(num<=0)
		{
			break;
		}
		s=(linknode*)malloc(sizeof(linknode));
		if(s==NULL)
		{
			printf("申请内存失败");
			exit(-1);	
		}		
		s->data = num; 
		s->next = head->next;
		head->next = s; 
	}
	return head;
}

//看有多少个节点：
//单链表的数目的确定
int len(struct linknode* head)
{	int icount =0;
	while(head->next!=NULL)//注意，while循环的条件这里就是head->next！！！ 
	{
		head = head->next;
		icount++;
	}
	return icount;
 } 

//打印函数：
void print(struct linknode *head)   //输出链表 
{
	linknode *Temp = head -> next ;    //临时指针指向首元结点 
	while(Temp!=NULL)
	{
		printf("数据: %d\n",Temp->data );		
		Temp = Temp->next ; //移动临时指针到下一个结点 
	} 
	printf("\n");
} 

//在任意位置插入一个链表，插入一个车厢；
void inputnode(linknode * head)
{	int i; 
	struct linknode* p;//p就是类似摆渡人的角色 
	struct linknode* s;
	p = head;
	int j=0;
	printf("请输入要插的位置");
	scanf("%d",&i);
	while(j<i-1&&p!=NULL)//注意，j的初值为0；小于j-1就循环j-1次，p刚好从头指针运动到i的位置前一个，自己演算一下，没问题的 
	//第二个条件是为了确保i的合理性 
	{
		p = p->next; 
		j++;
	}
	if(p !=NULL)
	{
	 	s = (linknode*)malloc(sizeof(linknode));
		printf("please input the data:");
		scanf("%d",&s->data);
		
	s->next = p->next;
	p->next = s;
	}
 } 
//删除某个位置的车厢 
void deletenode(linknode* head)
{	int i;
	linknode* p,*s;
	p = head; 
	printf("请输入要删除的节点位置：");
	scanf("%d",&i);
	if(i<0||i==0 || i>len(head))
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
		p->next = s->next;
		free(s);
	}
 } 
//设置快慢指针，找中间元素
void searchmiddle(linknode* head){
	linknode* fast;
	linknode* slow;
	if(len(head)%2==0){
		fast = head;
		slow = head;
		while(fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}	
	printf("中间元素有两个：分别是：%d和%d\n\n",slow->data,slow->next->data); 	
	}
	else{
		fast = head->next;
		slow = head->next;
		while(fast->next!=NULL){
			fast = fast->next->next;
			slow = slow->next;
		}	 printf("中间元素只有一个：%d\n",slow->data);
	} 
} 
////单链表的奇数偶数项互换位置：
void reverse(linknode* head){
	//先创建两个头节点 
	linknode* head1;
	head1 = (linknode*)malloc(sizeof(linknode));
	linknode *p,*q,*r;
	//首先分拆两个链表：
	p = head->next;
	//p指向原来的奇数项 
	q = head;
	r = head1;
	head1->next = NULL;
	// 下面就是分拆。 
	// head1放偶数 
	if(len(head)%2==1) printf("奇数元素个不支持反转！！！！");
	else{
	
	while(p!=NULL&&q!=NULL){
		q = p->next;
		//q指向原来的链表的偶数项
		p->next = q->next;
		r->next = q;	
		r = r->next;
		r->next =NULL;
		p = p->next;
	}
	// 分拆完成：
	// 下面开始重组：
	//  定义三个指针：还有一个指针在head1链表上面移动 
	linknode *p1,*q1,*r1,*r2;
	p1 = head->next;
	q1 = head;
	r1 = head1->next;//在偶数链表中的前驱指针 
	r2 = head1;
	
	//开始插入：
	while(p1!=NULL&&r1!=NULL){
		r2 = r1;
		r1 = r1->next;
		r2->next = p1;
		q1->next = r2;
		q1 = q1->next->next;
		p1 = p1->next;
		}	
	} 
}
//单链表的原地反转：
void reverse1(linknode* head){
	linknode *p;
	linknode *q;
	q = head->next;//开始的beg指针 
	p = head->next->next; //结束的end指针 
	
	while(p!=NULL){
		q->next = p->next;
		p->next = head->next;//不要想当然！！！！，就是head->next 
		head->next = p;
		p = q->next;
	}
	printf("反转之后数据是这样的：\n");
	print(head);
} 
//递归法(无头指针)：
linknode* reverse2(linknode* head){
	linknode* new_head; 
	if(head->next == NULL)
		return head;
		//这个head不是原来的第一个头节点了
	
	new_head = reverse2(head->next);
	//以三个节点的为例子 
	//一直移到最后一个节点
	//第一个次递归（最后一个节点）【只返回新头节点！！！】 
	//第二次递归才会设计对head的操作！！！
	//这个head就是指目前的放在括号里的节点，不是前面的head 
	//第一次递归的newhead也还在 
	//head->next=第三个节点
	//head->next->next又指回来了 
	//反转了newhead（第三个节点）和第二个节点 之间的next方向 
	head->next->next = head;
	//往前移，这个 
	head->next = NULL;
	return new_head;
	//反转完毕 
}
void existLoop1(linknode* head) {
  linknode* slowNode = head, *fastNode = head;
  while (fastNode != NULL && fastNode->next != NULL) {
    slowNode = slowNode->next;
    fastNode = fastNode->next->next;  
  }if (slowNode == fastNode) {
      printf("成环\n");
    }
 	printf("不成环\n");
}
