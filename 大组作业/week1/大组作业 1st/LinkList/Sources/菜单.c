//菜单:
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h>
#include"head.h"
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
			linknode* p = create(); 
			singlelinklistmenu(p);
			break;
		case 2:	
			printf("\n先来创建一个新的链表吧！\n");
			line* p1 = initline();
			doublelinkemenu(p1);
			break; 
		case 3:
			printf("\n先来创建一个新的链表吧！\n");
			Linklist p2 = create1();
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
			printf("\n请请输入你要查的值,若无输出，则无该值\n");
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

