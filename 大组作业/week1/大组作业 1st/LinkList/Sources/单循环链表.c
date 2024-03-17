#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h>
#include"head.h"

//搞这个主要是为了测试是否为循环链表用。 

//初始化：
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
      printf("成环\n"); 
    }
    else{
    	printf("不成环\n"); 	
	}

}


