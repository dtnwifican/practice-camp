#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h>
#include"head.h"
// ʵ��˫����

 
//���û�취��ͷ�ڵ� 

//��ʼ��˫����
line* initline(){
	line* head;
	head = (line*)malloc(sizeof(line));
	head->prior = NULL;
	head->next = NULL;
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
	line* new1;
	int n,n1;
	int j = 1;
	scanf("%d",&n);
	new1 = (line*)malloc(sizeof(line));
	scanf("%d",&n);
	printf("�������½���ֵ��"); 
	scanf("%d",&new1->data);
	// n��ָ����ڵ����� 
	if(n==1){
		line* list = head;
		new1->next = head;
		head->prior = new1;
		head = new1;
		// ���ù�new1��prior 
	}
	if(n>lenline(head))	printf("error!");
	else{
		//��ǰ��Ķ���һ����
		//�����ҵ�ǰһ���ڵ� 
		line *p;
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
	line *p,*s;
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
    printf("δ�ҵ�������ݣ�����");
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

