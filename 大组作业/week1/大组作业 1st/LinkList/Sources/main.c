#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h>
#include"head.h"
int main(){
	menu();
	return 0;
}

////�ݹ鷨(��ͷָ��)��
//linknode* reverse2(linknode* head){
//	linknode* new_head; 
//	if(head->next == NULL)
//		return head;
//		//���head����ԭ���ĵ�һ��ͷ�ڵ���
//	
//	new_head = reverse2(head->next);
//	//�������ڵ��Ϊ���� 
//	//һֱ�Ƶ����һ���ڵ�
//	//��һ���εݹ飨���һ���ڵ㣩��ֻ������ͷ�ڵ㣡������ 
//	//�ڶ��εݹ�Ż���ƶ�head�Ĳ���������
//	//���head����ָĿǰ�ķ���������Ľڵ㣬����ǰ���head 
//	//��һ�εݹ��newheadҲ���� 
//	//head->next=�������ڵ�
//	//head->next->next��ָ������ 
//	//��ת��newhead���������ڵ㣩�͵ڶ����ڵ� ֮���next���� 
//	head->next->next = head;
//	//��ǰ�ƣ���� 
//	head->next = NULL;
//	return new_head;
//	//��ת��� 
//}
