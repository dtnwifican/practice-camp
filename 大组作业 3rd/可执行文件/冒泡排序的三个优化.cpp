//首先是加flag的方法
/*每次冒泡排序前面小的都要和后面大的换位置：要是都是排好序的就不用动他了，
但是我们的一般的冒泡排序没有终止条件，会一直循环，
我们要是记下最后一次发生位置改变的地方
（这个位置可能和原本循环应该遍历的位置差很远，但是中间的数都不用改变（顺序是对的））
下次循环直接遍历到最近一次交换位置的地方就行了
*/
/*
后面大循环里面的每轮循环都可以节省很多次
*/
void bubblesort(int num[], int size){
	int temp;
	int flag;
	flag = size-1;
	while(flag >0){
		stop_posi = flag;
		//注意！！！这个stop_posi这个停止循环位置的变量每次 都会随着循环更新 
		flag = 0;
		//这个是和上面的循环条件呼应的
		//要是没有变化那么我们的flag就是0，我们就不循环了，这个就是直接排好序得了 
		for(int i = 0; i<stop_posi; i++){
			if(num[i]>num[i+1]){
				temp = num[i];
				num[i] = num[i+1];
				num[i+1] = temp;
				flag = i;
				//更新到最近的对换前后的数
				//不用担心换了这个会对后面产生连锁反应，后面的不变顺序是因为比前面
				//的所有元素都大了 
			}
		}
	}
} 


//下面是我们的双重冒泡：
//冒泡里面套冒泡：
//论上是可以减少一半的

//大的大循环换成小循环里面套小循环 
//把最小值和最大值不断对称着更新了
//这样可以减少很多循环成本 
void bubblesort1(int num[], int size){
	int temp;
	int max,min;
	for(int i = 0; i<size/2; i++){
		int flag =0;
		for(int j = 0; j< size - i -1; j++){
			if(num[j]<num[i+1]){
				temp = num[j];
				num[j] = num[j+1];
				num[j+1] = temp;
				flag = 1;
			}
		}	
		for(int k = size -i -1; k>0; k++){
			if(num[k]>num[k+1]){
				temp = num[k];
				num[k] = num[k-1];
				num[k-1] = temp;
				flag =1;
			}
		}
	if(flag == 0) break;
	}
}

//两个综合：
//要是从前往后排序排到中间的某一个数之后就停下来了
//说明后面的排好了 从后往前排的只要在停止排序的地方往前排序就行了
//从后往前排的同理 
void bubblesort3(int num[], int size){
	int flag = 0;
	int temp;
	//设置初始值 
	up = size-1;
	down = 0;
for(int l = size-1; l>0; l--){
		for(int i = down; i<up; i++){
		if(num[i]>num[i+1]){
			temp = num[i];
			num[i] = num[i+1];
			num[i+1] = temp;
			flag = i;
		}
	}
	if(flag == 0){
		break;
	}
	up = flag;
	flag = 0;
	for(int j = up; j>0; j--){
		if(num[j]<num[j-1]){
			temp = num[j];
			num[j] = num[j-1];
			num[j-1] = temp;
			flag = j;
		}
	}
	if(flag == 0){
		break;
	}
	down = flag;
	flag = -1;//最后还在循环里面还是要重置的！！！ 
	} 
} 




