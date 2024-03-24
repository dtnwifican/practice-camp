#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
//******************先定义一个栈
//放符号的栈 
//typedef struct{
//	char data[100];
//	int top;
//}OptStack; 
//
//
////入栈：
//int Push(OptStack s,char opt){
//	if(s.top == 100){
//		return -1;
//	}
//	s.data[s.top] = opt;
//	s.top++;
//	return 1;
//} 
////单纯的弹出值，但是不拿到
//int Pop(OptStack s){
//	if(s.top == 0){
//		return -1;
//	}
//	s.data[s.top-1] = '\0';
//	//将原来的栈顶元素设置为空
//	s.top--;
//	return 1;
//} 
////再就是一个popout函数：就是将我们的栈顶元素得到，并且出栈
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
////再就是只是获取栈顶元素，但是不进行出站操作：
//char gettopelem(OptStack s){
//	if (s.top == 0){
//		return '\0';
//	}
//	char e = s.data[s.top];
//	return e;
//} 
////再就是看我们的符号栈是不是为空
//int isempty(OptStack s){
//	if(s.top > 0){
//		return 0;
//	}
//	return 1;
//}
////对于加减乘除我们要计算预算的优先级
////还记得吗？我们的符号入栈是要看我们的栈里面元素的优先级和我们的待入栈
////的符号的优先级进行比较，要是优先级比他们低，全部出栈，直到我们的栈顶元素的优先级比待入栈的符号的优先级低
////要是优先级比他们高，就入栈
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
//	printf("请输入要计算的表达式：");
//	scanf("%s",express);
//	for(int i = 0; i<strlen(express);i++){
//		if(express[i]=='+'||express[i]=='-'||express[i]=='*'||express[i]=='/'){ 
//			//最复杂的是加减乘除
//			
//			//首先要是我们的符号栈是空的话，我们就直接入栈
//			if(isempty(s)){
//				Push(s,express[i]); 
//				continue;
//			} 		
//			
//			//要是栈顶的元素是我们的左括号：
//			//我们也无脑 将我们的 加减乘除加入到我们的符号栈
//			char topele = gettopelem(s);
//			if(topele=='('){
//				Push(s,express[i]);
//				continue;
//			}
//			
//			
//			//现在就来判断我们的优先级：
//			while(priority(topele)>=priority(express[i])){
//				printf("%c ",popout(s));
//				topele = gettopelem(s);
//			} 
//			Push(s,express[i]); 
//		} 
//		
//	//***********************************************************	
//		if(express[i]=='('){
//			//要是我们的中缀表达式遍历到的元素是左括号我们直接入栈
//			Push(s,express[i]);
//		}
//		if(express[i]==')'){
//			//要是我们的中缀表达式遍历到的元素是右括号，
//			//我们把左括号和右括号之间的符号都拿出来 
//			char e = popout(s);
//			while(e!='('){
//				printf("%c ",e);
//				e = popout(s);
//			} 
//		} 
//	//**************************************************************
//		else{
//			//下面就是我要保留我们的多位数 
//			printf("%c ",express[i]);
//			for(int j =1; i+j<strlen(express); j++){
//				if(express[i+j]>='0'&&express[i+j]<='9'){
//					//要是是数字我们就持续输出
//					printf("%c",express[i+j]); 
//				}
//				else{
//					i = i+j-1;
//					//这时候i是遍历到i+j-1的位置 
//					//要会退一格：因为for循环里面还有个加一 
//
//					break;
//				}			
//			}
//		}
//	} 
//	//最后一步就是要是我们的数组后面没东西了
//	//要是我们的栈不为空的话，把里面的东西拿出来 
//	while(!isempty(s)){
//		printf("%c ",popout(s));
//	}
//	return 0;
//}

//
////**********************8现在就要借助栈来将我们的前缀表达式转化成我们的后缀表达式：
//typedef struct{
//	char data[100];
//	int top;
//}OperatorStack;
//OperatorStack s;
////先定义一个入栈的函数：
//int Push(char opt){
//	if(s.top == 100){
//		//栈满 
//		return -1; 
//	}
//	s.data[s.top] = opt;
//	s.top++;
//}
////出栈：(单纯出栈，不返回栈顶元素)
//int Pop(){
//	if(s.top == 0){
//		return -1;
//	}
//	s.data[s.top -1] = '\0';
//	s.top--;
//	return 1;
//} 
//
////下面这个就是出栈：并且返回栈顶元素：
//char popout(){
//	if(s.top == 0){
//		return '\0';
//	}
//	//我们的栈订也是在栈顶指针上方的 
//	char e = s.data[s.top-1];
//	s.data[s.top -1] = '\0';
//	s.top -- ;
//	return 1;
//}
////下面一个元素就是只获取栈顶元素，但是不进行出栈操作：
//char GetEleTop(){
//	if(s.top == 0){
//		return '\0';
//	}
//	//我们的栈订也是在栈顶指针上方的 
//	char e = s.data[s.top-1];
//	return e;
//} 
////再就是看我们的栈是否为空
//int isempty(){
//	if(s.top > 0){
//		return 0;
//	}
//	return 1;
//}
////计算操作符的优先级：
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
//	printf("请输入要计算的表达式：");
//	scanf("%s",express);
//	for(int i = 0; i<strlen(express); i++){
//		//为了方便进行处理：进行拆分： 
//		if(express[i]=='+'||express[i]=='-'||express[i]=='*'||express[i]=='/'){
//			//先看我们的符号栈是不是空的：
//			if(isempty()){
//				Push(express[i]); //要是是空的直接放 
//				continue; //防止干扰到下面地while！！！ 
//			} 
//			char topele = GetEleTop();
//			if(topele == '('){
//				//要是栈顶元素为左括号也直接进栈
//				Push(express[i]);
//				continue;
//			} 
//			//要是不为空的话，那就是要比较和栈里面的符号的优先级
//			//从栈顶往下依次看，要是优先级高的直接弹出来，直到栈顶优先级比我们的符号低低再将我们的符号进栈
//			while(prior(topele) >= prior(express[i])){
//				printf("%c ",popout());
//				topele = GetEleTop();
//			}
//			//这时候已经好了 
//			Push(express[i]);	
//	}
//		
//		
//	//****************************************************
//		else if(express[i]=='('){
//			//当我们遍历到左括号：直接【入栈】
//			Push(express[i]); 
//		}
//		else if(express[i]==')'){
//			//我们先取出我们的栈顶元素;
//			 char topele = popout();
//			 while(topele != '('){
//			 	//直接拿出来
//			 	printf("%c ",topele);
//				topele= popout();//再次取出栈顶元素 
//			 }
//		}
//		
//		
//		//************************************************
//		else{ //下面是输出数字：
//			//先不进行换行：
//			//先遍历：要是是数字我们直接输出 
//			printf("%c",express[i]); 
//			for(int j = 1; i+j<=strlen(express); j++){
//				if(express[i+j]>='0' && express[i+j]<='9'){
//					//要是是数字我们继续输出 
//					printf("%c",express[i+j]); //这里是i+j!!!!! 
//					 
//				}
//				//要是不是数字了，我们就要停止这个循环！！！
//				else{
//					i = i+j-1;
//					//遍历到这个位置 
//					// -1是因为还有一个外层循环，i++ 
//					printf(" ");
//					break;
//					//我们就不要再加j了！！！ 
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

SqStack* InitStack()//初始化栈 
{
	SqStack *s=(SqStack*)malloc(sizeof(SqStack));
	s->top=-1;//初始化栈顶指针 
	return s;
}
int StackEmpty(SqStack s){//判断栈是否为空 
	if(s.top==-1) return 1;//为空
	else return 0;//不为空 
}
int PushStack(SqStack *s,int x)//压栈操作 
{
	if(s->top==99) return 0;
		s->top++;
	s->data[s->top]=x;
	return 1;
 }
int PopStack(SqStack *s){//出栈操作 
    if(s->top==-1) return 0;
    return s->data[s->top--];
}
int Priority(char u)//判断运算符的优先级
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
{  //两操作数、操作符出栈，计算结果，结果入栈 
    char u;
    int x1,x2,sum;
    u=PopStack(OPTR);//将操作符出栈 
    x1=PopStack(OPND);//将两个操作数出栈 
    x2=PopStack(OPND);
    switch(u){//根据出栈操作符选择计算方式 
    	case '+':sum=x2+x1;break;
    	case '-':sum=x2-x1;break;
    	case '*':sum=x2*x1;break;
    	case '/':sum=x2/x1;break; 
	}
	PushStack(OPND,sum);//将计算得到的数 重新入操作数栈 
}
int Count(char *s)//扫描表达式并计算
{
	SqStack *OPTR,*OPND;//建立两个栈
	 OPTR=InitStack();// 分别初始化 
	 OPND=InitStack();
	 while(*s!='\0'){//扫描表达式直到扫描结束为止 
	 	if(*s>='0'&&*s<='9'){//扫描到数字 
	 	   int y= *s-'0';//将字符转为数字
	 		s++;//扫描的指针往下移 
	 		while(*s>='0'&&*s<='9') {//处理多位数 
	 		  y=y*10+*s-'0'; //最开始得到的元素往前移 
			    s++;//扫描指针往后移 
				}
			 PushStack(OPND,y);//入操作数栈 
		 }
		 else if(OPTR->top==-1||*s=='('||Priority(*s)>Priority(OPTR->data[OPTR->top])){//扫描到运算符 
		 //如果扫描的栈为空、左括号、运算符优先级>运算符栈顶优先级 
		 	PushStack(OPTR,*s);//则运算符压入运算符栈 
			 s++; //扫描的指针继续往下移 
			 if(*s=='-'){ //添加负号的情况 
			 	PushStack(OPND,0);//将0入操作数栈
			 }
		 }
		 else if(*s==')'&&OPTR->data[OPTR->top]=='('){
		 	//如果扫描到右括号且栈顶为左括号 
		 	PopStack(OPTR);//将左括号出栈 
		 	s++;//扫描的指针继续往下移 
		 }
		 else //扫描到的运算符优先级<=运算符栈顶优先级
		 PopPush(OPTR,OPND);//将进行计算操作 
	 }
	 while(OPTR->top>=0)//表达式扫描完成，将所有运算符出栈 
	  PopPush(OPTR,OPND);//并计算放入操作数栈 
	  int n=OPND->data[OPND->top];//将最后操作数进行出栈 
	  free(OPTR);//释放两栈 
	  free(OPND);
	 return n;//返回结果 
}
//有问题 
int Count1(char *s){//扫描表达式并计算
	//先初始化
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
		//下面就是汇总;汇总什么时候我们直接进栈 
		//有要是符号栈为空，或者是优先级，又或者是左边是左括号
		//已经满足输入耳朵不是数字了 
		else if(OPTR->top <0||*s == '('||Priority(OPTR->data[OPTR->top] < Priority(*s))){
			PushStack(OPTR,*s);
			s++;
			//我们这里还可对我们的最开始的负数和我们的
			//在括号中的负数进行处理
			//我们要是s++之后得到一个符号，要是是负数的意思
			//（是不是负数的的意思都可以，减号也可以）
			//我们可以进一个0去我们的数据栈，然后我们的*s（减号）
			//循环又会重新遍历上去，我们可以的减号也可以入符号栈
			if(*s == '-'){
				PushStack(OPND,0);
			} 
		}
		//还有一种：主要是调试的时候：
		//要是我们的左括号之后直接是右括号”
		else if(*s == ')'&&OPTR->data[OPTR->top] == '('){
			//直接将我们的左括号弹出：
			PopStack(OPTR);
			s++; 
		}
		
		
		
		//下面这个牛逼了！！！！！！
		//我靠，没想到：以6+2*3+2为例：
		//他是直接把 里面的 乘法先算了，先算出来了值！！！！
		//在这个式子上面来看：然后这个值还会和前面的加号操作，【连锁反应！！！】 
		//最后 
		//然后化成全为加减的 
		else PopPush(OPTR,OPND);
		//注意！！！这里没有s++；
		//处理之后我们的扫描到的符号的优先级是比前面高的
		//再可以经过上面的循环后面的是扫描到的优先级小的符号也可以被放到符号栈的栈顶 
	}
	while(OPTR->top>=0)
		PopPush(OPTR,OPND); 
		//当前面的符号没了，我这个数字栈也只剩一个数了 
		int n = OPND->data[OPND->top];
		free(OPTR);//释放两栈 
	  	free(OPND);
	 	return n;//返回结果
}
//测试表达式是否合法：
int test(char *s){//判断输入表达式是否合法 
	while(*s!='\0'){
	   if(*s>='0'&&*s<='9'||*s=='('||*s==')'){
	   		   	s++;
				  }
	   	else if(*s=='*'||*s=='/'){//当连续*/时 
	   		s++;
	   		if(*s=='*'||*s=='/')
	   		return 0;
		   }
		else if(*s=='-'||*s=='+'){//当连续+-时 
			s++;
			if(*s=='-'||*s=='+')
			 return 0;
		}
	   else //当非数字、运算符等 
	   	return 0;
	}
	return 1;
}

int main()
{
	char c[50];
	int x,flgh=1;
	while(flgh){
		printf("请输入你要计算的表达式(只支持整数运算！):");
			gets(c);//输入计算表达值
			if(test(c)==0){//判断表达式是否合法 
				printf("请输入正确的表达式！\n");
			}
			else
	        printf("计算都得到的:%s=%d\n",c,Count(c));
	        }
return 0;  
}  

	 







