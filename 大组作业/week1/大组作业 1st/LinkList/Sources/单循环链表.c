#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h>
#include"head.h"

//�������Ҫ��Ϊ�˲����Ƿ�Ϊѭ�������á� 

//��ʼ����
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
      printf("�ɻ�\n"); 
    }
    else{
    	printf("���ɻ�\n"); 	
	}

}


