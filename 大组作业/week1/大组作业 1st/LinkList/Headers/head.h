
#pragma once
#ifndef _FUN_H
#define _FUN_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
typedef struct linknode{
	int data;
	struct linknode* next;
}linknode; 
typedef struct line{
	struct line* prior;
	int data;
	struct line* next;
}line;
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode,*Linklist; 


linknode* create();
int len(struct linknode* head);
void print(struct linknode *head);
void inputnode(linknode * head);
void deletenode(linknode* head);
void searchmiddle(linknode* head);
void reverse(linknode* head);
void reverse1(linknode* head);
void existLoop1(linknode* head); 

line* initline();
int lenline(line* head);
void insertline(line* head);
void delLine(line *head);
void changenode(line* head);

Linklist create1();
void existLoop(Linklist head);

void menu();
void singlelinklistmenu(linknode *p);
void doublelinkemenu(line* p);

#endif
