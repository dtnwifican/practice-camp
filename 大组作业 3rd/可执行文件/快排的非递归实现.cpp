//ʵ�ַǵݹ���� 
#include <stdio.h>	
#include <stdlib.h>
//�������״̬����
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0
//�궨��
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
typedef int SElemType;
//˳��ջ�Ķ���
typedef struct {
	SElemType* top;
	SElemType* base;
	int stacksize;
} SqStack;
Status InitSqStack(SqStack *s){
	s->base = (SElemType*)malloc(1000*sizeof(SElemType));
	//��ϰ���������malloc�����Ǵ���һ�������ĵȴ�Ŀռ䣬�ú󷵻��׵�ַ 
	if(s->base == NULL){ //���ٿռ�ʧ�� 
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
		//�ոո���ˣ����������� 
		return OK; 
	}
}
int pivotposition(int arr[], int high, int low){
	//��ȡ�����ǵ�ֵ��
	int num = arr[low];
	//������ⲻ�����룡������
	//ע�⣡�������high��low����������ѭ����ʱ��һ��high = low�ˣ�����
	//������ʲô���⿴������Ƶ9.06
	//���ǻ�Ҫ����whileѭ��
	//ʹ�����ǵ�high��low���һ�ξ���ѭ�����Ե�ѭ������֮��������
	while(low<high){	
		while(low<high && arr[high]>= num)
		//������������и�һ����high>lowֻ��Ϊ�˷�����⣡���� 
			high--;
		// ��һ������low�ǿյ� 
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
		Pop(&s); //����ջ��Ԫ�� 
		int end = StackTop(&s);
		Pop(&s);

		
		int pivotposi = pivotposition(arr[], high, low);
		

		if (pivotposi + 1 < high)
		{
			Push(&s, high);
			Push(&s, div + 1);
		}
		//���Ǹ���ߣ������Ƚ��ұ߲��ֵ�������������˵����� 
		if (low < pivotposi - 1)
		{
			Push(&s, pivotposi - 1);
			Push(&s, low);
		} 
	}
}
