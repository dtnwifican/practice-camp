//实现非递归快排 
#include <stdio.h>	
#include <stdlib.h>
//函数结果状态代码
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0
//宏定义
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef int SElemType;
//顺序栈的定义
typedef struct {
	SElemType* top;
	SElemType* base;
	int stacksize;
} SqStack;
Status InitSqStack(SqStack *s){
	s->base = (SElemType*)malloc(1000*sizeof(SElemType));
	//复习！！！这个malloc函数是创建一个连续的等大的空间，让后返回首地址 
	if(s->base == NULL){ //开辟空间失败 
		exit(OVERFLOW); 
	} 
	else{
		s->top = s->base;
		s->stacksize = MAXSIZE;	
		return OK;
	}
} 
Status IsEmptySqStack(SqStack *s){
	if(s==NULL){
		return ERROR;
	}
	if (s->top == s->base){
		printf("empty!!!");
		return TRUE;
	}	
	else{
		printf("not empty"); 
		return FALSE;	
	}
}
Status Push(SqStack *s, SElemType* num){
	if(s == NULL){
		return ERROR;
	}
	else if(s->top-s->base == MAXSIZE){
		return OVERFLOW;
	}
	else{
		*(s->top) = *num;
		s->top++;
		return OK;
	}
} 
Status Pop(SqStack *s,SElemType* num){
	if(s == NULL || s->top == s->base){
		return ERROR;
	}
	else{
		*num = *(--s->top);
		//刚刚搞错了，不用再退了 
		return OK; 
	}
}
int pivotposition(int arr[], int high, int low){
	//先取出我们的值：
	int num = arr[low];
	//还是理解不够深入！！！！
	//注意！！！这个high和low跳出这两个循环的时候不一定high = low了！！！
	//后续有什么问题看快排视频9.06
	//我们还要来个while循环
	//使得我们的high和low最后一次经过循环可以到循环外面之后可以相等
	while(low<high){	
		while(low<high && arr[high]>= num)
		//这个条件里面有个一样的high>low只是为了方便理解！！！ 
			high--;
		// 第一次这里low是空的 
		arr[low] = arr[high];
	
		while(low<high && arr[low]<= num)
			low++;
		arr[high] = arr[low];
	}
	a[low] = num; 
	return high; 
}
int StackTop(SqStack *s){
	return *(--s->top);
}
void quicksortnotr(int a[], int low, int high){
	Stack s;
	InitSqStack(&s);
	

	Push(&s, &low);
	Push(&s, &high);
	while(IsEmptySqStack(&s)!=0){
		int begin = StackTop(&s);
		Pop(&s); //弹出栈顶元素 
		int end = StackTop(&s);
		Pop(&s);

		
		int pivotposi = pivotposition(arr[], high, low);
		

		if (pivotposi + 1 < high)
		{
			Push(&s, high);
			Push(&s, div + 1);
		}
		//先是搞左边，所以先进右边部分的数组的左右两端的索引 
		if (low < pivotposi - 1)
		{
			Push(&s, pivotposi - 1);
			Push(&s, low);
		} 
	}
}
