//�˵�:
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h>
#include"head.h"
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
			linknode* p = create(); 
			singlelinklistmenu(p);
			break;
		case 2:	
			printf("\n��������һ���µ�����ɣ�\n");
			line* p1 = initline();
			doublelinkemenu(p1);
			break; 
		case 3:
			printf("\n��������һ���µ�����ɣ�\n");
			Linklist p2 = create1();
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
			printf("\n����������Ҫ���ֵ,������������޸�ֵ\n");
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

