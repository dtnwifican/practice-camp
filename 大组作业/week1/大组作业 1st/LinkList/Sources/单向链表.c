#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h>
#include"head.h"

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
  }if (slowNode == fastNode) {
      printf("�ɻ�\n");
    }
 	printf("���ɻ�\n");
}
