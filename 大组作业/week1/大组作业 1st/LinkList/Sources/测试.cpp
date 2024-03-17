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
// ͷ�巨�� 
linknode* create()
{
	struct linknode* head ;
	head =(linknode*)malloc(sizeof(linknode));
	head->next=NULL;
	linknode* s;
	int num;
	while(1)//���������������>0�ͼ��� 
	{
		printf("������ڵ������(ͷ�巨)������0ʱֹͣ����");
		scanf("%d",&num); 
		if(num<=0)
		{
			break;
		}
		s=(linknode*)malloc(sizeof(linknode));
		if(s==NULL)
		{
			printf("�����ڴ�ʧ��");
			exit(-1);	
		}		
		s->data = num; 
		s->next = head->next;
		head->next = s; 
	}
	return head;
}

//���ж��ٸ��ڵ㣺
//���������Ŀ��ȷ��
int len(struct linknode* head)
{	int icount =0;
	while(head->next!=NULL)//ע�⣬whileѭ���������������head->next������ 
	{
		head = head->next;
		icount++;
	}
	return icount;
 } 

//��ӡ������
void print(struct linknode *head)   //������� 
{
	linknode *Temp = head -> next ;    //��ʱָ��ָ����Ԫ��� 
	while(Temp!=NULL)
	{
		printf("����: %d\n",Temp->data );		
		Temp = Temp->next ; //�ƶ���ʱָ�뵽��һ����� 
	} 
	printf("\n");
} 

//������λ�ò���һ����������һ�����᣻
void inputnode(linknode * head)
{	int i; 
	struct linknode* p;//p�������ưڶ��˵Ľ�ɫ 
	struct linknode* s;
	p = head;
	int j=0;
	printf("������Ҫ���λ��");
	scanf("%d",&i);
	while(j<i-1&&p!=NULL)//ע�⣬j�ĳ�ֵΪ0��С��j-1��ѭ��j-1�Σ�p�պô�ͷָ���˶���i��λ��ǰһ�����Լ�����һ�£�û����� 
	//�ڶ���������Ϊ��ȷ��i�ĺ����� 
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
//ɾ��ĳ��λ�õĳ��� 
void deletenode(linknode* head)
{	int i;
	linknode* p,*s;
	p = head; 
	printf("������Ҫɾ���Ľڵ�λ�ã�");
	scanf("%d",&i);
	if(i<0||i==0 || i>len(head))
	{
		printf("error\n");
	}
	else
	{	
		int j=0;//�ܵ���i��ǰ��һ������ 
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
//���ÿ���ָ�룬���м�Ԫ��
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
	printf("�м�Ԫ�����������ֱ��ǣ�%d��%d\n\n",slow->data,slow->next->data); 	
	}
	else{
		fast = head->next;
		slow = head->next;
		while(fast->next!=NULL){
			fast = fast->next->next;
			slow = slow->next;
		}	 printf("�м�Ԫ��ֻ��һ����%d\n",slow->data);
	} 
} 
////�����������ż�����λ�ã�
void reverse(linknode* head){
	//�ȴ�������ͷ�ڵ� 
	linknode* head1;
	head1 = (linknode*)malloc(sizeof(linknode));
	linknode *p,*q,*r;
	//���ȷֲ���������
	p = head->next;
	//pָ��ԭ���������� 
	q = head;
	r = head1;
	head1->next = NULL;
	// ������Ƿֲ� 
	// head1��ż�� 
	if(len(head)%2==1) printf("����Ԫ�ظ���֧�ַ�ת��������");
	else{	
	while(p!=NULL&&q!=NULL){
		q = p->next;
		//qָ��ԭ���������ż����
		p->next = q->next;
		r->next = q;	
		r = r->next;
		r->next =NULL;
		p = p->next;
	}
	// �ֲ���ɣ�
	// ���濪ʼ���飺
	//  ��������ָ�룺����һ��ָ����head1���������ƶ� 
	linknode *p1,*q1,*r1,*r2;
	p1 = head->next;
	q1 = head;
	r1 = head1->next;//��ż�������е�ǰ��ָ�� 
	r2 = head1;
	
	//��ʼ���룺
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
//�������ԭ�ط�ת��
void reverse1(linknode* head){
	linknode *p;
	linknode *q;
	q = head->next;//��ʼ��begָ�� 
	p = head->next->next; //������endָ�� 
	
	while(p!=NULL){
		q->next = p->next;
		p->next = head->next;//��Ҫ�뵱Ȼ��������������head->next 
		head->next = p;
		p = q->next;
	}
	printf("��ת֮�������������ģ�\n");
	print(head);
} 
//�ݹ鷨(��ͷָ��)��
linknode* reverse2(linknode* head){
	linknode* new_head; 
	if(head->next == NULL)
		return head;
		//���head����ԭ���ĵ�һ��ͷ�ڵ���
	
	new_head = reverse2(head->next);
	//�������ڵ��Ϊ���� 
	//һֱ�Ƶ����һ���ڵ�
	//��һ���εݹ飨���һ���ڵ㣩��ֻ������ͷ�ڵ㣡������ 
	//�ڶ��εݹ�Ż���ƶ�head�Ĳ���������
	//���head����ָĿǰ�ķ���������Ľڵ㣬����ǰ���head 
	//��һ�εݹ��newheadҲ���� 
	//head->next=�������ڵ�
	//head->next->next��ָ������ 
	//��ת��newhead���������ڵ㣩�͵ڶ����ڵ� ֮���next���� 
	head->next->next = head;
	//��ǰ�ƣ���� 
	head->next = NULL;
	return new_head;
	//��ת��� 
}
void existLoop1(linknode* head) {
  linknode* slowNode = head, *fastNode = head;
  while (fastNode != NULL && fastNode->next != NULL) {
    slowNode = slowNode->next;
    fastNode = fastNode->next->next;
    if (slowNode == fastNode) {
      printf("�ɻ�");
    }
  }
 	printf("���ɻ�");
}

Linklist create1(){
	Linklist head;
	head = (Linklist)malloc(sizeof(LNode));
	head->next = NULL;
	head->data = -1;
	Linklist new1,p;
	int n;
	while(1){
		printf("������ڵ������(ͷ�巨)������0ʱֹͣ����");
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

// �ж��Ƿ�ɻ���
void existLoop(Linklist head) {
  Linklist slowNode = head, fastNode = head;
  while (fastNode != NULL && fastNode->next != NULL) {
    slowNode = slowNode->next;
    fastNode = fastNode->next->next;
	}
    if (slowNode == fastNode) {
      printf("�ɻ�");
    }
  else{
  	printf("���ɻ�");
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
		printf("����������(����0���ٴ���)��");
		scanf("%d",&n);
		if(n==0) break; 
		new1 = (line*)malloc(sizeof(line));
		new1->data = n;
		// β�巨�� 
		p->next = new1;
		new1->prior = p;
		p = p->next;
	}
	return head; 
}

//��������ĳ���
int lenline(line* head){
	line* p = head;
	int n = 0;
	while(p->next!=NULL){
		p = p->next;
		n++;
	}
	return n;
} 

//����ڵ㣺
void insertline(line* head){
	printf("���������Ľڵ����ţ���������ڵ�ǰ�棩��");
	int n,n1;
	int j = 1;
	scanf("%d",&n);
	printf("�������½���ֵ��"); 
	line* new1;
	new1 = (line*)malloc(sizeof(line));
	scanf("%d",&new1->data);
	// n��ָ����ڵ����� 
	if(n==1){
		new1->next = head;
		head->prior = new1;
		head = new1;
		// ���ù�new1��prior 
	}
	else{
		//��ǰ��Ķ���һ����
		//�����ҵ�ǰһ���ڵ� 
		line *p = head;
		while(j<n-1){
			p = p->next;
			j++;
		}
		if(p->next == NULL){
			//�Ǿ���β����
			 p->next = new1;
			 new1->prior = p;
		}
		else{
			//���м�
			p->next->prior = new1;
			new1->next = p->next;
			p->next = new1;
			new1->prior = p;	 
		}
	}
}

//ɾ���ڵ㣺��ֵ��ɾ 
void delLine(line *head)
{	int data;
	printf("������Ҫ��Ľڵ������ֵ��");
	scanf("%d",&data); 
    line *p=head;
    //��������
    while(p!=NULL)
    {
        //�жϵ�ǰ������������data�Ƿ���ȣ�����ȣ�ժ���ý��
        if (p->data==data)
        {
            p->prior->next=p->next;
            p->next->prior=p->prior;
            free(p);
        }
        p=p->next;
    }
    printf("�������޸�����Ԫ��");
}
//���º���
void changenode(line* head)
{	int i;
	line* p,*s;
	p = head; 
	printf("������Ҫ�޸ĵĽڵ�λ�ã�");
	scanf("%d",&i);
	if(i<0||i==0 || i>lenline(head))
	{
		printf("error\n");
	}
	else
	{	
		int j=0;//�ܵ���i��ǰ��һ������ 
		while(j<i-1)
		{
			p = p->next;
			j++; 
		}
		s = p->next;
		printf("������ýڵ����ֵ��");
		scanf("%d",&s->data); 
	}
 } 

//���ҽڵ�,���ؽڵ��λ�ã�
void searchnode(line * head,int elem){
//�½�һ��ָ��t����ʼ��Ϊͷָ�� head
    line * t=head;
    int i=1;
    while(t)
    {
        if(t->data==elem)
        {
            printf("�ҵ��ˣ������ǵ�%d��\n",i);
        }
        i++;
        t=t->next;
    }
    //����ִ�����˴�����ʾ����ʧ��
}

//���������
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
	printf("��ѡ���ܣ�\n");
	printf("***************************************************\n");
	printf("***1.���õ�����*********************2.����˫����***\n");
	printf("*****************3.���ڵ�ѭ������******************\n");
	printf("***************************************************\n");
	printf("\n");
	
	printf("��������Ҫ���еĲ�����");
	int n;
begin:	
	scanf("%d",&n);
	switch(n){
		case 1:
			printf("\n��������һ���µ�����ɣ�\n");
			linknode* p;
			p = create(); 
			singlelinklistmenu(p);
			break;
		case 2:	
			printf("\n��������һ���µ�����ɣ�\n");
			line* p1;
			p1 = initline();
			doublelinkemenu(p1);
			break; 
		case 3:
			printf("\n��������һ���µ�����ɣ�\n");
			Linklist p2;
			p2  = create1();
			// ֱ���ж��Ƿ�ɻ���
			printf("\n");
			existLoop(p2); 
		default:
			printf("����������\n");
				goto begin;
				break;	
	}
} 

//������˵���
void singlelinklistmenu(linknode *p){
	printf("��ѡ���ܣ�\n");
	printf("********************************************************\n");
	printf("***1.����******2.����*******3.ɾ��*******4.���м�Ԫ��***\n");
	printf("********5.��ת���ݹ鷨����ͷ��㣩������Ҳ�У�**********\n");
	printf("*****************6.��ת����λż��λ*********************\n"); 
	printf("*********************7.�жϳɻ�*************************\n");
	printf("***********************8.�˳�***************************\n");
	printf("********************************************************\n");
begin:
	printf("��������Ҫ���еĲ�����");
	int n;	
	scanf("%d",&n);
	switch(n){
		case 1:
			printf("\n����ô����ڵ㣺%d\n",len(p));
			printf("\n����Ϊ��\n");
			print(p);
			printf("\n");
			singlelinklistmenu(p);
			break;
		case 2:
			printf("\n����Ϊ��\n");
			print(p);
			printf("\n");
			inputnode(p);
			printf("\n��������Ϊ��\n");
			print(p);
			singlelinklistmenu(p);
			break;
		case 3:
			printf("\n����Ϊ��\n");
			print(p);
			printf("\n");
			deletenode(p);
			printf("\n��������Ϊ��\n");
			print(p);
			singlelinklistmenu(p);
			break;
		case 4:
			printf("\n����Ϊ��\n");
			print(p);
			printf("\n");
			searchmiddle(p);
			printf("\n");
			singlelinklistmenu(p);
			break;
		case 5:
			printf("\n����Ϊ��\n");
			print(p);
			printf("\n");
			reverse1(p);
			printf("\n��������Ϊ��\n");
			print(p);
			singlelinklistmenu(p);
			break;
		case 6:
			printf("\n����Ϊ��\n");
			print(p);
			printf("\n");
			reverse(p);
			printf("\n��������Ϊ��\n");
			print(p);
			singlelinklistmenu(p);
			break;
		case 7:
			printf("\n����Ϊ��\n");
			print(p);
			printf("\n");
			existLoop1(p);
			printf("\n");
			singlelinklistmenu(p);
		case 8:
			printf("����Ҫ�˳���");	
			printf("����������˳���");
			getch();
			system("pause");
			exit(-1);
		default:
			printf("����������\n");
				goto begin;
				break;		
	}
}  
//˫����˵���
void doublelinkemenu(line* p){
	printf("��ѡ���ܣ�\n");
	printf("*****************************************\n");
	printf("***1.����***2.����***3.ɾ��***4.����ֵ***\n");	
	printf("******************5.����*****************\n");
	printf("******************6.�˳�*****************\n");
	printf("*****************************************\n");	
begin:	
	printf("��������Ҫ���еĲ�����");
	int n;
	scanf("%d",&n);
	switch(n){
		case 1:
			printf("\n����ô����ڵ㣺%d\n",lenline(p));
			printf("\n����Ϊ��\n");
			display(p);
			printf("\n");
			doublelinkemenu(p);
		case 2:
			printf("\n����Ϊ��\n");
			display(p);
			printf("\n");
			insertline(p);
			printf("\n");
			printf("�������������ˣ�");
			display(p);
			doublelinkemenu(p);
		case 3:
			printf("\n����Ϊ��\n");
			display(p);
			printf("\n");
			delLine(p);
			printf("\n");
			printf("�������������ˣ�");
			display(p);	
			doublelinkemenu(p);	
		case 4:
			printf("\n����Ϊ��\n");
			display(p);
			printf("\n");
			changenode(p);
			printf("\n");
			printf("�������������ˣ�");
			display(p);
			doublelinkemenu(p);
		case 5:
			printf("\n����Ϊ��\n");
			display(p);
			printf("\n");
			int num;
			printf("\n��������Ҫ���ֵ,������������޸�ֵ\n");
			scanf("%d",&num);
			searchnode(p,num);
			printf("\n");
			printf("�������������ˣ�");
			display(p);
			doublelinkemenu(p);
		case 6:
			printf("����Ҫ�˳���");	
			printf("����������˳���");
			getch();
			system("pause");
			exit(-1);
		default:
			printf("����������\n");
				goto begin;
				break;
	} 
}
