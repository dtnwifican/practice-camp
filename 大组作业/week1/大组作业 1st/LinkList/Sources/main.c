#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h>
#include"head.h"
int main(){
	menu();
	return 0;
}

////递归法(无头指针)：
//linknode* reverse2(linknode* head){
//	linknode* new_head; 
//	if(head->next == NULL)
//		return head;
//		//这个head不是原来的第一个头节点了
//	
//	new_head = reverse2(head->next);
//	//以三个节点的为例子 
//	//一直移到最后一个节点
//	//第一个次递归（最后一个节点）【只返回新头节点！！！】 
//	//第二次递归才会设计对head的操作！！！
//	//这个head就是指目前的放在括号里的节点，不是前面的head 
//	//第一次递归的newhead也还在 
//	//head->next=第三个节点
//	//head->next->next又指回来了 
//	//反转了newhead（第三个节点）和第二个节点 之间的next方向 
//	head->next->next = head;
//	//往前移，这个 
//	head->next = NULL;
//	return new_head;
//	//反转完毕 
//}
