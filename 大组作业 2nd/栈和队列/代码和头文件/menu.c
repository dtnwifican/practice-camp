#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "head.h"
#include <conio.h>


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
