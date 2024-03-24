#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "head.h"
#include <conio.h>


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
