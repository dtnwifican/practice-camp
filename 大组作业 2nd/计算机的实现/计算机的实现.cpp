#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
//******************�ȶ���һ��ջ
//�ŷ��ŵ�ջ 
//typedef struct{
//	char data[100];
//	int top;
//}OptStack; 
//
//
////��ջ��
//int Push(OptStack s,char opt){
//	if(s.top == 100){
//		return -1;
//	}
//	s.data[s.top] = opt;
//	s.top++;
//	return 1;
//} 
////�����ĵ���ֵ�����ǲ��õ�
//int Pop(OptStack s){
//	if(s.top == 0){
//		return -1;
//	}
//	s.data[s.top-1] = '\0';
//	//��ԭ����ջ��Ԫ������Ϊ��
//	s.top--;
//	return 1;
//} 
////�پ���һ��popout���������ǽ����ǵ�ջ��Ԫ�صõ������ҳ�ջ
//char popout(OptStack s){
//	if(s.top == 0){
//		return '\0';
//	}
//	char e;
//	e = s.data[s.top-1];
//	s.data[s.top-1] = '\0';
//	s.top--;
//	return e;
//}
////�پ���ֻ�ǻ�ȡջ��Ԫ�أ����ǲ����г�վ������
//char gettopelem(OptStack s){
//	if (s.top == 0){
//		return '\0';
//	}
//	char e = s.data[s.top];
//	return e;
//} 
////�پ��ǿ����ǵķ���ջ�ǲ���Ϊ��
//int isempty(OptStack s){
//	if(s.top > 0){
//		return 0;
//	}
//	return 1;
//}
////���ڼӼ��˳�����Ҫ����Ԥ������ȼ�
////���ǵ������ǵķ�����ջ��Ҫ�����ǵ�ջ����Ԫ�ص����ȼ������ǵĴ���ջ
////�ķ��ŵ����ȼ����бȽϣ�Ҫ�����ȼ������ǵͣ�ȫ����ջ��ֱ�����ǵ�ջ��Ԫ�ص����ȼ��ȴ���ջ�ķ��ŵ����ȼ���
////Ҫ�����ȼ������Ǹߣ�����ջ
//int priority(char sig){
//	if(sig == '+'|| sig == '-'){
//		return 1;
//	}
//	if(sig == '*'|| sig == '/'){
//		return 2;
//	}
//}	 
//int main(){
//	OptStack s; 
//	s.top = 0;
//	char express[100];
//	printf("������Ҫ����ı��ʽ��");
//	scanf("%s",express);
//	for(int i = 0; i<strlen(express);i++){
//		if(express[i]=='+'||express[i]=='-'||express[i]=='*'||express[i]=='/'){ 
//			//��ӵ��ǼӼ��˳�
//			
//			//����Ҫ�����ǵķ���ջ�ǿյĻ������Ǿ�ֱ����ջ
//			if(isempty(s)){
//				Push(s,express[i]); 
//				continue;
//			} 		
//			
//			//Ҫ��ջ����Ԫ�������ǵ������ţ�
//			//����Ҳ���� �����ǵ� �Ӽ��˳����뵽���ǵķ���ջ
//			char topele = gettopelem(s);
//			if(topele=='('){
//				Push(s,express[i]);
//				continue;
//			}
//			
//			
//			//���ھ����ж����ǵ����ȼ���
//			while(priority(topele)>=priority(express[i])){
//				printf("%c ",popout(s));
//				topele = gettopelem(s);
//			} 
//			Push(s,express[i]); 
//		} 
//		
//	//***********************************************************	
//		if(express[i]=='('){
//			//Ҫ�����ǵ���׺���ʽ��������Ԫ��������������ֱ����ջ
//			Push(s,express[i]);
//		}
//		if(express[i]==')'){
//			//Ҫ�����ǵ���׺���ʽ��������Ԫ���������ţ�
//			//���ǰ������ź�������֮��ķ��Ŷ��ó��� 
//			char e = popout(s);
//			while(e!='('){
//				printf("%c ",e);
//				e = popout(s);
//			} 
//		} 
//	//**************************************************************
//		else{
//			//���������Ҫ�������ǵĶ�λ�� 
//			printf("%c ",express[i]);
//			for(int j =1; i+j<strlen(express); j++){
//				if(express[i+j]>='0'&&express[i+j]<='9'){
//					//Ҫ�����������Ǿͳ������
//					printf("%c",express[i+j]); 
//				}
//				else{
//					i = i+j-1;
//					//��ʱ��i�Ǳ�����i+j-1��λ�� 
//					//Ҫ����һ����Ϊforѭ�����滹�и���һ 
//
//					break;
//				}			
//			}
//		}
//	} 
//	//���һ������Ҫ�����ǵ��������û������
//	//Ҫ�����ǵ�ջ��Ϊ�յĻ���������Ķ����ó��� 
//	while(!isempty(s)){
//		printf("%c ",popout(s));
//	}
//	return 0;
//}

//
////**********************8���ھ�Ҫ����ջ�������ǵ�ǰ׺���ʽת�������ǵĺ�׺���ʽ��
//typedef struct{
//	char data[100];
//	int top;
//}OperatorStack;
//OperatorStack s;
////�ȶ���һ����ջ�ĺ�����
//int Push(char opt){
//	if(s.top == 100){
//		//ջ�� 
//		return -1; 
//	}
//	s.data[s.top] = opt;
//	s.top++;
//}
////��ջ��(������ջ��������ջ��Ԫ��)
//int Pop(){
//	if(s.top == 0){
//		return -1;
//	}
//	s.data[s.top -1] = '\0';
//	s.top--;
//	return 1;
//} 
//
////����������ǳ�ջ�����ҷ���ջ��Ԫ�أ�
//char popout(){
//	if(s.top == 0){
//		return '\0';
//	}
//	//���ǵ�ջ��Ҳ����ջ��ָ���Ϸ��� 
//	char e = s.data[s.top-1];
//	s.data[s.top -1] = '\0';
//	s.top -- ;
//	return 1;
//}
////����һ��Ԫ�ؾ���ֻ��ȡջ��Ԫ�أ����ǲ����г�ջ������
//char GetEleTop(){
//	if(s.top == 0){
//		return '\0';
//	}
//	//���ǵ�ջ��Ҳ����ջ��ָ���Ϸ��� 
//	char e = s.data[s.top-1];
//	return e;
//} 
////�پ��ǿ����ǵ�ջ�Ƿ�Ϊ��
//int isempty(){
//	if(s.top > 0){
//		return 0;
//	}
//	return 1;
//}
////��������������ȼ���
//int prior(char sig){
//	if(sig == '+'||sig == '-'){
//		return 1;
//	}
//	else if(sig == '*'||sig == '/'){
//		return 2;
//	}
//}
//
//int main(){
//	char express[100];
//	printf("������Ҫ����ı��ʽ��");
//	scanf("%s",express);
//	for(int i = 0; i<strlen(express); i++){
//		//Ϊ�˷�����д������в�֣� 
//		if(express[i]=='+'||express[i]=='-'||express[i]=='*'||express[i]=='/'){
//			//�ȿ����ǵķ���ջ�ǲ��ǿյģ�
//			if(isempty()){
//				Push(express[i]); //Ҫ���ǿյ�ֱ�ӷ� 
//				continue; //��ֹ���ŵ������while������ 
//			} 
//			char topele = GetEleTop();
//			if(topele == '('){
//				//Ҫ��ջ��Ԫ��Ϊ������Ҳֱ�ӽ�ջ
//				Push(express[i]);
//				continue;
//			} 
//			//Ҫ�ǲ�Ϊ�յĻ����Ǿ���Ҫ�ȽϺ�ջ����ķ��ŵ����ȼ�
//			//��ջ���������ο���Ҫ�����ȼ��ߵ�ֱ�ӵ�������ֱ��ջ�����ȼ������ǵķ��ŵ͵��ٽ����ǵķ��Ž�ջ
//			while(prior(topele) >= prior(express[i])){
//				printf("%c ",popout());
//				topele = GetEleTop();
//			}
//			//��ʱ���Ѿ����� 
//			Push(express[i]);	
//	}
//		
//		
//	//****************************************************
//		else if(express[i]=='('){
//			//�����Ǳ����������ţ�ֱ�ӡ���ջ��
//			Push(express[i]); 
//		}
//		else if(express[i]==')'){
//			//������ȡ�����ǵ�ջ��Ԫ��;
//			 char topele = popout();
//			 while(topele != '('){
//			 	//ֱ���ó���
//			 	printf("%c ",topele);
//				topele= popout();//�ٴ�ȡ��ջ��Ԫ�� 
//			 }
//		}
//		
//		
//		//************************************************
//		else{ //������������֣�
//			//�Ȳ����л��У�
//			//�ȱ�����Ҫ������������ֱ����� 
//			printf("%c",express[i]); 
//			for(int j = 1; i+j<=strlen(express); j++){
//				if(express[i+j]>='0' && express[i+j]<='9'){
//					//Ҫ�����������Ǽ������ 
//					printf("%c",express[i+j]); //������i+j!!!!! 
//					 
//				}
//				//Ҫ�ǲ��������ˣ����Ǿ�Ҫֹͣ���ѭ��������
//				else{
//					i = i+j-1;
//					//���������λ�� 
//					// -1����Ϊ����һ�����ѭ����i++ 
//					printf(" ");
//					break;
//					//���ǾͲ�Ҫ�ټ�j�ˣ����� 
//				} 
//			}
//		}
//	}
//	while(!isempty()){
//		printf("%c ",popout());
//	} 
//	return 0;
//}

typedef struct{
	int data[100];
	int top;
}SqStack;

SqStack* InitStack()//��ʼ��ջ 
{
	SqStack *s=(SqStack*)malloc(sizeof(SqStack));
	s->top=-1;//��ʼ��ջ��ָ�� 
	return s;
}
int StackEmpty(SqStack s){//�ж�ջ�Ƿ�Ϊ�� 
	if(s.top==-1) return 1;//Ϊ��
	else return 0;//��Ϊ�� 
}
int PushStack(SqStack *s,int x)//ѹջ���� 
{
	if(s->top==99) return 0;
		s->top++;
	s->data[s->top]=x;
	return 1;
 }
int PopStack(SqStack *s){//��ջ���� 
    if(s->top==-1) return 0;
    return s->data[s->top--];
}
int Priority(char u)//�ж�����������ȼ�
{
	switch(u){
		case '+':
		case '-': return 1;
		case '*':
		case '/':return 2;
		default: return -1;
	}
}
void PopPush(SqStack *OPTR,SqStack *OPND)
{  //������������������ջ���������������ջ 
    char u;
    int x1,x2,sum;
    u=PopStack(OPTR);//����������ջ 
    x1=PopStack(OPND);//��������������ջ 
    x2=PopStack(OPND);
    switch(u){//���ݳ�ջ������ѡ����㷽ʽ 
    	case '+':sum=x2+x1;break;
    	case '-':sum=x2-x1;break;
    	case '*':sum=x2*x1;break;
    	case '/':sum=x2/x1;break; 
	}
	PushStack(OPND,sum);//������õ����� �����������ջ 
}
int Count(char *s)//ɨ����ʽ������
{
	SqStack *OPTR,*OPND;//��������ջ
	 OPTR=InitStack();// �ֱ��ʼ�� 
	 OPND=InitStack();
	 while(*s!='\0'){//ɨ����ʽֱ��ɨ�����Ϊֹ 
	 	if(*s>='0'&&*s<='9'){//ɨ�赽���� 
	 	   int y= *s-'0';//���ַ�תΪ����
	 		s++;//ɨ���ָ�������� 
	 		while(*s>='0'&&*s<='9') {//�����λ�� 
	 		  y=y*10+*s-'0'; //�ʼ�õ���Ԫ����ǰ�� 
			    s++;//ɨ��ָ�������� 
				}
			 PushStack(OPND,y);//�������ջ 
		 }
		 else if(OPTR->top==-1||*s=='('||Priority(*s)>Priority(OPTR->data[OPTR->top])){//ɨ�赽����� 
		 //���ɨ���ջΪ�ա������š���������ȼ�>�����ջ�����ȼ� 
		 	PushStack(OPTR,*s);//�������ѹ�������ջ 
			 s++; //ɨ���ָ����������� 
			 if(*s=='-'){ //��Ӹ��ŵ���� 
			 	PushStack(OPND,0);//��0�������ջ
			 }
		 }
		 else if(*s==')'&&OPTR->data[OPTR->top]=='('){
		 	//���ɨ�赽��������ջ��Ϊ������ 
		 	PopStack(OPTR);//�������ų�ջ 
		 	s++;//ɨ���ָ����������� 
		 }
		 else //ɨ�赽����������ȼ�<=�����ջ�����ȼ�
		 PopPush(OPTR,OPND);//�����м������ 
	 }
	 while(OPTR->top>=0)//���ʽɨ����ɣ��������������ջ 
	  PopPush(OPTR,OPND);//��������������ջ 
	  int n=OPND->data[OPND->top];//�������������г�ջ 
	  free(OPTR);//�ͷ���ջ 
	  free(OPND);
	 return n;//���ؽ�� 
}
//������ 
int Count1(char *s){//ɨ����ʽ������
	//�ȳ�ʼ��
	SqStack *OPTR;
	SqStack *OPND;
	OPTR = InitStack();
	OPND = InitStack();
	while(*s!= '\0'){
		if(*s>='0'&&*s<='9'){
			int num = *s - '0';
			s++;
			while(*s>='0'&&*s<='9'){
				num = num*10+(*s)-'0';
				s++;
			}
			PushStack(OPND,num);
		}
		//������ǻ���;����ʲôʱ������ֱ�ӽ�ջ 
		//��Ҫ�Ƿ���ջΪ�գ����������ȼ����ֻ����������������
		//�Ѿ�����������䲻�������� 
		else if(OPTR->top <0||*s == '('||Priority(OPTR->data[OPTR->top] < Priority(*s))){
			PushStack(OPTR,*s);
			s++;
			//�������ﻹ�ɶ����ǵ��ʼ�ĸ��������ǵ�
			//�������еĸ������д���
			//����Ҫ��s++֮��õ�һ�����ţ�Ҫ���Ǹ�������˼
			//���ǲ��Ǹ����ĵ���˼�����ԣ�����Ҳ���ԣ�
			//���ǿ��Խ�һ��0ȥ���ǵ�����ջ��Ȼ�����ǵ�*s�����ţ�
			//ѭ���ֻ����±�����ȥ�����ǿ��Եļ���Ҳ���������ջ
			if(*s == '-'){
				PushStack(OPND,0);
			} 
		}
		//����һ�֣���Ҫ�ǵ��Ե�ʱ��
		//Ҫ�����ǵ�������֮��ֱ���������š�
		else if(*s == ')'&&OPTR->data[OPTR->top] == '('){
			//ֱ�ӽ����ǵ������ŵ�����
			PopStack(OPTR);
			s++; 
		}
		
		
		
		//�������ţ���ˣ�����������
		//�ҿ���û�뵽����6+2*3+2Ϊ����
		//����ֱ�Ӱ� ����� �˷������ˣ����������ֵ��������
		//�����ʽ������������Ȼ�����ֵ�����ǰ��ļӺŲ�������������Ӧ�������� 
		//��� 
		//Ȼ�󻯳�ȫΪ�Ӽ��� 
		else PopPush(OPTR,OPND);
		//ע�⣡��������û��s++��
		//����֮�����ǵ�ɨ�赽�ķ��ŵ����ȼ��Ǳ�ǰ��ߵ�
		//�ٿ��Ծ��������ѭ���������ɨ�赽�����ȼ�С�ķ���Ҳ���Ա��ŵ�����ջ��ջ�� 
	}
	while(OPTR->top>=0)
		PopPush(OPTR,OPND); 
		//��ǰ��ķ���û�ˣ����������ջҲֻʣһ������ 
		int n = OPND->data[OPND->top];
		free(OPTR);//�ͷ���ջ 
	  	free(OPND);
	 	return n;//���ؽ��
}
//���Ա��ʽ�Ƿ�Ϸ���
int test(char *s){//�ж�������ʽ�Ƿ�Ϸ� 
	while(*s!='\0'){
	   if(*s>='0'&&*s<='9'||*s=='('||*s==')'){
	   		   	s++;
				  }
	   	else if(*s=='*'||*s=='/'){//������*/ʱ 
	   		s++;
	   		if(*s=='*'||*s=='/')
	   		return 0;
		   }
		else if(*s=='-'||*s=='+'){//������+-ʱ 
			s++;
			if(*s=='-'||*s=='+')
			 return 0;
		}
	   else //�������֡�������� 
	   	return 0;
	}
	return 1;
}

int main()
{
	char c[50];
	int x,flgh=1;
	while(flgh){
		printf("��������Ҫ����ı��ʽ(ֻ֧���������㣡):");
			gets(c);//���������ֵ
			if(test(c)==0){//�жϱ��ʽ�Ƿ�Ϸ� 
				printf("��������ȷ�ı��ʽ��\n");
			}
			else
	        printf("���㶼�õ���:%s=%d\n",c,Count(c));
	        }
return 0;  
}  

	 







