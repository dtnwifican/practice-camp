#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h> 
typedef struct linknode{
	int data;
	struct linknode* next;
}linknode; 
typedef struct line{
	struct line* prior;
	int data;
	struct line* next;
}line;
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode,*Linklist; 


linknode* create();
int len(struct linknode* head);
void print(struct linknode *head);
void inputnode(linknode * head);
void deletenode(linknode* head);
void searchmiddle(linknode* head);
void reverse(linknode* head);
void reverse1(linknode* head);
void existLoop1(linknode* head); 

line* initline();
int lenline(line* head);
void insertline(line* head);
void delLine(line *head);
void changenode(line* head);

Linklist create1();
void existLoop(Linklist head);

void menu();
void singlelinklistmenu(linknode *p);
void doublelinkemenu(line* p);

int main(){
	menu();
	return 0;
} 
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
    if (slowNode == fastNode) {
      printf("成环");
    }
  }
 	printf("不成环");
}

Linklist create1(){
	Linklist head;
	head = (Linklist)malloc(sizeof(LNode));
	head->next = NULL;
	head->data = -1;
	Linklist new1,p;
	int n;
	while(1){
		printf("请输入节点的数据(头插法)（输入0时停止）：");
		scanf("%d",&n);
		if(n==0) break;
		new1 = (LNode*)malloc(sizeof(LNode));
		new1->data = n;
		new1->next = head->next;
		head->next = new1;
	}
	
	p = head->next;
	while (p->next!=NULL){
		p = p->next; 
	}
	p->next = head;
	return head;
}

// 判断是否成环：
void existLoop(Linklist head) {
  Linklist slowNode = head, fastNode = head;
  while (fastNode != NULL && fastNode->next != NULL) {
    slowNode = slowNode->next;
    fastNode = fastNode->next->next;
	}
    if (slowNode == fastNode) {
      printf("成环");
    }
  else{
  	printf("不成环");
  }
 	
}
line* initline(){
	line* head;
	head = (line*)malloc(sizeof(line));
	head->prior = NULL;
	head->next = NULL;
	head->data=1;
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
	int n,n1;
	int j = 1;
	scanf("%d",&n);
	printf("请输入新结点的值："); 
	line* new1;
	new1 = (line*)malloc(sizeof(line));
	scanf("%d",&new1->data);
	// n是指插入节点的序号 
	if(n==1){
		new1->next = head;
		head->prior = new1;
		head = new1;
		// 不用管new1的prior 
	}
	else{
		//和前面的都是一样的
		//都是找到前一个节点 
		line *p = head;
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
	line* p,*s;
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
void menu(){
	printf("请选择功能：\n");
	printf("***************************************************\n");
	printf("***1.设置单链表*********************2.设置双链表***\n");
	printf("*****************3.关于单循环链表******************\n");
	printf("***************************************************\n");
	printf("\n");
	
	printf("请输入您要进行的操作：");
	int n;
begin:	
	scanf("%d",&n);
	switch(n){
		case 1:
			printf("\n先来创建一个新的链表吧！\n");
			linknode* p;
			p = create(); 
			singlelinklistmenu(p);
			break;
		case 2:	
			printf("\n先来创建一个新的链表吧！\n");
			line* p1;
			p1 = initline();
			doublelinkemenu(p1);
			break; 
		case 3:
			printf("\n先来创建一个新的链表吧！\n");
			Linklist p2;
			p2  = create1();
			// 直接判断是否成环：
			printf("\n");
			existLoop(p2); 
		default:
			printf("请重新输入\n");
				goto begin;
				break;	
	}
} 

//单链表菜单：
void singlelinklistmenu(linknode *p){
	printf("请选择功能：\n");
	printf("********************************************************\n");
	printf("***1.长度******2.插入*******3.删除*******4.找中间元素***\n");
	printf("********5.反转（递归法（无头结点）代码我也有）**********\n");
	printf("*****************6.反转奇数位偶数位*********************\n"); 
	printf("*********************7.判断成环*************************\n");
	printf("***********************8.退出***************************\n");
	printf("********************************************************\n");
begin:
	printf("请输入您要进行的操作：");
	int n;	
	scanf("%d",&n);
	switch(n){
		case 1:
			printf("\n有这么多个节点：%d\n",len(p));
			printf("\n数据为：\n");
			print(p);
			printf("\n");
			singlelinklistmenu(p);
			break;
		case 2:
			printf("\n数据为：\n");
			print(p);
			printf("\n");
			inputnode(p);
			printf("\n现在数据为：\n");
			print(p);
			singlelinklistmenu(p);
			break;
		case 3:
			printf("\n数据为：\n");
			print(p);
			printf("\n");
			deletenode(p);
			printf("\n现在数据为：\n");
			print(p);
			singlelinklistmenu(p);
			break;
		case 4:
			printf("\n数据为：\n");
			print(p);
			printf("\n");
			searchmiddle(p);
			printf("\n");
			singlelinklistmenu(p);
			break;
		case 5:
			printf("\n数据为：\n");
			print(p);
			printf("\n");
			reverse1(p);
			printf("\n现在数据为：\n");
			print(p);
			singlelinklistmenu(p);
			break;
		case 6:
			printf("\n数据为：\n");
			print(p);
			printf("\n");
			reverse(p);
			printf("\n现在数据为：\n");
			print(p);
			singlelinklistmenu(p);
			break;
		case 7:
			printf("\n数据为：\n");
			print(p);
			printf("\n");
			existLoop1(p);
			printf("\n");
			singlelinklistmenu(p);
		case 8:
			printf("程序将要退出！");	
			printf("输入任意键退出！");
			getch();
			system("pause");
			exit(-1);
		default:
			printf("请重新输入\n");
				goto begin;
				break;		
	}
}  
//双链表菜单：
void doublelinkemenu(line* p){
	printf("请选择功能：\n");
	printf("*****************************************\n");
	printf("***1.长度***2.插入***3.删除***4.更改值***\n");	
	printf("******************5.查找*****************\n");
	printf("******************6.退出*****************\n");
	printf("*****************************************\n");	
begin:	
	printf("请输入您要进行的操作：");
	int n;
	scanf("%d",&n);
	switch(n){
		case 1:
			printf("\n有这么多个节点：%d\n",lenline(p));
			printf("\n数据为：\n");
			display(p);
			printf("\n");
			doublelinkemenu(p);
		case 2:
			printf("\n数据为：\n");
			display(p);
			printf("\n");
			insertline(p);
			printf("\n");
			printf("现在是这样的了：");
			display(p);
			doublelinkemenu(p);
		case 3:
			printf("\n数据为：\n");
			display(p);
			printf("\n");
			delLine(p);
			printf("\n");
			printf("现在是这样的了：");
			display(p);	
			doublelinkemenu(p);	
		case 4:
			printf("\n数据为：\n");
			display(p);
			printf("\n");
			changenode(p);
			printf("\n");
			printf("现在是这样的了：");
			display(p);
			doublelinkemenu(p);
		case 5:
			printf("\n数据为：\n");
			display(p);
			printf("\n");
			int num;
			printf("\n请输入你要查的值,若无输出，则无该值\n");
			scanf("%d",&num);
			searchnode(p,num);
			printf("\n");
			printf("现在是这样的了：");
			display(p);
			doublelinkemenu(p);
		case 6:
			printf("程序将要退出！");	
			printf("输入任意键退出！");
			getch();
			system("pause");
			exit(-1);
		default:
			printf("请重新输入\n");
				goto begin;
				break;
	} 
}
