#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h>
#include <time.h>
#include"head.h"
int* make_data10000(){
    int a;
    static int randomarray[10000];
    FILE *pf = fopen("test.txt","w");
    for(int i = 0; i< 10000; i++){
//    	srand((unsigned)time(NULL));
   		a = rand() % 30 + 1;
   		randomarray[i] = a;
	}
	for(int i = 0; i<10000; i++){
		fprintf(pf,"%d ", randomarray[i]);
	}
	fclose(pf);
    return randomarray;
}
int* make_data50000(){
    int a;
    static int randomarray1[50000];
    FILE *pf = fopen("test.txt","w");
    for(int i = 0; i< 50000; i++){
//    	srand((unsigned)time(NULL));
   		a = rand() % 30 + 1;
   		randomarray1[i] = a;
	}
	for(int i = 0; i<50000; i++){
		fprintf(pf,"%d ", randomarray1[i]);
	}
	fclose(pf);
    return randomarray1;
}
int* make_data200000(){
    int a;
    static int randomarray2[200000];
    FILE *pf = fopen("test.txt","w");
    for(int i = 0; i< 200000; i++){
//    	srand((unsigned)time(NULL));
   		a = rand() % 30 + 1;
   		randomarray2[i] = a;
	}
	for(int i = 0; i<200000; i++){
		fprintf(pf,"%d ", randomarray2[i]);
	}
	fclose(pf);
    return randomarray2;
}
int* make_data100(){
    int a;
    static int randomarray2[100];
    FILE *pf = fopen("test.txt","w");
    for(int i = 0; i< 100; i++){
//    	srand((unsigned)time(NULL));
   		a = rand() % 30 + 1;
   		randomarray2[i] = a;
	}
	for(int i = 0; i<100; i++){
		fprintf(pf,"%d ", randomarray2[i]);
	}
	fclose(pf);
    return randomarray2;
}


//快排实现 
void quicksort(int arr[], int high, int low){
	int pivotposi;
	if(low<high){
		pivotposi = pivotposition(arr, high, low);
		//先处理左边的
		quicksort(arr, pivotposi-1, low);
		//我们这个pivotposition位置已经固定了 不再排了
		quicksort(arr, high, pivotposi+1);
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
	arr[low] = num; 
	return high; 
}


////归并排序实现
//void mergesort(int a[],int l, int r,int count){
//	int b[count];
//	if(l == r){
//		//这时候就是分的块只有一个元素的情况：
//		//这时候就要停下来了，往回归 
//		return ; 
//	}
//	//下面就是排序操作的内容 
//	else{
//		int mid;
//		//分成很多块，每一块同时进行
//		mergesort(a,l,mid,count);
//		mergesort(a,mid+1,r,count);
//		int i = l, j = mid+1, k = 1;
//		//上面就是定义我们的（类指针）
//		//k的初始是1
//		
//		//下面就是当我们没有移动到左边的边界：中间和右边的边界：最右边的时候： 
//		while(i<mid && j<r){
//			if(a[i]<a[j]){
//				b[k] = a[i];
//				i++; 
//			}else{
//				b[k] = a[j];
//				j++;
//			}
//			k++;//别忘了这个 
//		}	
//			//有一边到顶了：就退出循环了
//			//直接把没到顶的复制到暂存数组就行了 
//		 	while(i<mid) b[k++] = a[i++];
//			while(j<r) b[k++] = a[j++];
//			
//			//最后一步就是集成计算的结果：
//			//进行更新：
//			//对两个一组做下解释：两个一组：有四个，这四个两个一组的数组是同步进行操作，更新
//			//【同步输入进我们的a数组里面的】
//			for(int i = 0; i<=r; i++) a[i] = b[i]; 
//	}
//} 
//归并排序
void merge(int arr[], int tempArr[], int left, int mid, int right)
{
    // 标记左半区第一个未排序的元素
    int l_pos = left;
    // 标记右半区第一个未排序的元素
    int r_pos = mid + 1;
    // 临时数组元素的下标
    int pos = left;

    // 合并
    while (l_pos <= mid && r_pos <= right)
    {
        if (arr[l_pos] < arr[r_pos])  // 左半区第一个剩余元素更小
            tempArr[pos++] = arr[l_pos++];
        else  // 右半区第一个剩余元素更小
            tempArr[pos++] = arr[r_pos++];
    }

    // 合并左半区剩余的元素
    while (l_pos <= mid)
        tempArr[pos++] = arr[l_pos++];

    // 合并右半区剩余的元素
    while (r_pos <= right)
        tempArr[pos++] = arr[r_pos++];

    // 把临时数组中合并后的元素复制回原来的数组
    while (left <= right)
    {
        arr[left] = tempArr[left];
        left++;
    }
}

// 归并排序
void msort(int arr[], int tempArr[], int left, int right)
{
    // 如果只有一个元素，那么不需要继续划分
    // 只有一个元素的区域，本生就是有序的，只需要被归并即可
    if (left < right)
    {
        // 找中间点
        int mid = (left + right) / 2;
        // 递归划分左半区
        msort(arr, tempArr, left, mid);
        // 递归划分右半区
        msort(arr, tempArr, mid + 1, right);
        // 合并已经排序的部分
        merge(arr, tempArr, left, mid, right);
    }
}

// 归并排序入口
void mergesort(int arr[], int n)
{
    // 分配一个辅助数组
    int tempArr[n];
    // 调用实际的归并排序
    msort(arr, tempArr, 0, n - 1);
}

//计数排序实现：
//int * counting_sort(int arr[], int count, int max){
//	int i = 0;
//	int *countarr;
//	int *temarr;
//	//我们的累计数组的大小是我们的原数组的最大的数的大小 
//	countarr = (int*)malloc(max* sizeof(int));
//	temarr = (int*)malloc(max* sizeof(int));
//	
//	for(int t = 0; t<max; t++){
//		temarr[t] = 0;
//	}
//	//把每个数的出现的累计次数算出来 
//	for(int j = 0; j<max; j++){
//		countarr[arr[j]]++;
//	}
//	//下面就是把我们的累积数组和对应下标的值综合一下之后放出来
//	int j = 0;
//	for(int x = 0; x<max; x++){
//		while(countarr[x]!=0){
//			temarr[j++] = x;
//			countarr[x]--;
//		}
//	} 
//	free(countarr);
//	countarr = NULL;
//	return temarr;
//}
void counting_sort(int* arr, int n)
{
   //找到最大值
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	int range = max + 1;//开辟空间的数量
	int* countArr = (int*)malloc(sizeof(int)*range);//开辟空间
	//初始化数组全部为0
	memset(countArr, 0, sizeof(int)*range);

	//开始计数
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i]]++;
	}

	//开始排序
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (countArr[i]--)
		{
			arr[j] = i ;
			j++;
		}
	}

	free(countArr);
}




//基数排序的实现 
//void radixsort(int a[],int length){
//	//实际上是建立在我们的计数排序上面的
//	//就是疯狂除以10，得到个位数十位数百位数千位数 
//	//然后用类似计数排序的操作对每次得到的位数进行排序
//	//最后会很神奇的排好序了
//	int max = a[0]; 
//	for(int i = 0; i<length; i++){
//		if(a[i]>max){
//			max = a[i];
//		}
//	} 
//	//下面开始算个位数十位数百位数...
//	//当我们的最大的数算出到最大位数（比如千位数或者百位数截止）
//	//用百分号（取余号来进行计算） 
//	int div = 1;
//	
//	//还要创建一个0-9的 数组：来对我们的每次算出来位数进行计数排序
//	int countarr[10] = {0}; 
//	int* t = (int*)malloc(max*sizeof(int)); 
//	while(max/div!=0){
//		for(int i =0; i<length; i++){
//			//是这样算的末位数 
//			countarr[a[i]/div%10]++;
//		}
//		//开辟一块内存暂存中间的结果
//		for(int i = length-1; i>=0; i--){
//			while(countarr[a[i]/div %10 -1]!=0){
//				t[countarr[a[i]/div %10 -1]] = a[i];
//				countarr[a[i]/div %10 -1] --;
//			}
//		}
//		//最后一步再存放：
//		for(int i =0; i<length; i++){
//			a[i] = t[i];
//			//再更新：其实这一步也可以放到上一个循环
//			//更新到最后就是没问题的了 
//		} 
//		div = div*10;
//		//第一次arr 
//	}
//}
void radixsort( int data[], int length )
{
	int i, k, maxVal, count, base;
	int bucket[10] = { 0 };
	int *buff = new int[ length ];
	//求数组中的最大元素 
	maxVal = data[0];
	for( i = 1; i < length; i++ )
	{
		if( data[i] > maxVal )
		{
			maxVal = data[i];
		}
	}
	//printf( "maxVal = %d\n", maxVal );
	//计算最大元素的位数 
	count = 0;
	while( maxVal > 0 )
	{
		count++;
		maxVal /= 10;
	}
	//printf( "count = %d\n", count );
	base = 1;
	for( k = 1; k <= count; k++ )
	{
		//求每一个元素的 base位上的数字，对应的桶元素做累加 
		for( i = 0; i < length; i++  ) 
		{
			bucket[ ( data[i] / base ) % 10 ]++;
		}
		//重新计算桶元素的值，每一个元素都是其前面元素之和
		//如此操作，可以得到每一个桶中的元素在排序之后的位置下标 
		for( i = 1; i < 10; i++ ) 
		{
			bucket[i] += bucket[i-1];
		}
		//根据桶元素的值，将data中的元素重新排位存入buff中
		for( i = length-1; i >= 0; i-- ) 
		{
			buff[ bucket[ ( data[i] / base ) % 10 ] - 1 ] = data[i];
			bucket[ ( data[i] / base ) % 10 ]--;
		}
		//将buff中元素对位存放到data中
		for( i = 0; i < length; i++ ) 
		{
			data[i] = buff[i];
		}
		//清空桶，即让桶里元素归0 
		for( i = 0; i < 10; i++ ) 
		{
			bucket[i] = 0;
		}
		//base的值乘以10,之后进入下一趟排序 
		base *= 10;
	}
	delete[] buff;
}



//插入排序实现 
void insert_sort(int a[], int n){
	for(int i = 1; i<n; i++){
		//往后面遍历 
		//把我们的未知序列的第一个数存起来了 
		int key = a[i];
		//a[j]是我们的要进行比较的数 
		int j = i -1;
		while(j>=0 && a[j]>key){
			//这个就是一直比较
			//我们的那个遍历到的数往前走，直到前面的数比我们的这个遍历到的数小 
			
			//复制操作 
			a[j+1] = a[j];
			//这个就是往前移动来看的操作 
			j--;
		}
		a[j+1] = key;
		//就拿我们的key不用排的时候为例：要往前走一个再放我们的key 
	}
}

//颜色排序：
void coloursort(int a[], int length){
	int p1 = 0;
	int p0 = 0;
	int p2 = length-1;
	int tem;
	while(p1<=p2){
		if(a[p1]== 2&&a[p2] == 0){
			tem = a[p2];
			a[p2] = a[p1];
			a[p1] = tem;
			//交换完之后p2往前走 
			p2--;
			continue;
		}
		if(a[p1] == 0&&a[p0] == 1){
			tem = a[p1];
			a[p1] = a[p0];
			a[p0] = tem;
			//然后p1和p0继续往前走
			//哈哈哈哈哈哈就三个值的排序：什么地毯式搜索
			p0++;
			p1++;
		}
		else p1++;
} 
	for(int i =0; i<length; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("\n");
} 
