//首先是我们的找中间值的优化
//要是我的是数据是0，1，2，3，4，5，6，7，9，8 
//解释：首先我们的要是我按照默认的取法 要是我取第一个作为low
//那么我们每次循环我这个low循环都动不了，而且low和high对应的下标的元素都在乱换 
//而且只有右边的high在往左边走，这样的话循环就要遍历整个数组的长度
//要是我们的第一个元素（默认比较值）是中间大小的元素的话：那我的循环（high和low的更新）就井然有序的 
//左右两边同时往中间走 
//这时候我们的循环就可以减少一半次数
//只要能取到相比最大值或者最小值更加靠近中间值的元素
//对于我们的循环都是有很大好处的（哪怕取到第二的都有好处） 
//（取到中间值）是可以减少一半的大循环次数！！！！（左右两边分析是这样的）
// 要是我们的中间值就在中间附近的位置：（要是数组顺序很对）那能减少的就是非常多的
// 上面这一行：要是数组顺序很乱中间值在中间或者左右两边（循环次数）倒是都是一样的


//所以我们的第一个改进方法：取【相对】中值法
int getmidindex(int a[], int low, int high){
	int mid = (low + high)/2;
	if(a[low] > a[mid]){
		if(a[high]>a[mid]){
			return high;
		}
		if(a[low] < a[high]){
			return low;
		}
		else return high;
		//其他无法确定的情况一律返回high
		//基本可以找到相对中间大小的元素了！！！ 
		//可以减少很多次循环了 
	}
	else if(a[mid] > a[low]){
		if(a[high] > a[mid]){
			return mid;
		}
		if(a[low] > a[high]){
			return low;
		}
		else return high;
		//其他无法确定的情况一律返回high
		//基本可以找到相对中间大小的元素了！！！ 
		//可以减少很多次循环了 
	} 
} 
int pivotposition1(int a[], int high, int low){
	int num = getmidindex(a, low, high);
	if(low<high){
		while(low < high && a[high] > num){ 
			high--;
			//一定是high先走！！！！！
			//因为只有一开始的low那里有一个空位，被num存走了 
		}
		a[low] = a[high];
		while(low<high && a[low] < num){
			low++;
		}
		a[high] = a[low];
	} 
	//high = low了，跳出循环
	a[high] = num;
	return high; 
}
void qsort(int a[], int low, int high){
	int pivotposi;
	if(low<high){
		pivotposi = pivotposition1(a, low,high);
		qsort(a, low, pivotposi);
		qsort(a, pivotposi-1, high);
	}
}

//第二种就是我们的要是我们的low和high中间的相隔的元素要是很少：
//我们就不用我们的快速排序：快排在20个数据一下还不如别的排序
//我们换我们的插入排序
void qsort1(int a[], int low, int high){
	int pivotposi;
	if(high - low >20){
		pivotposi = pivotposition1(a, low,high);
		qsort1(a, low, pivotposi);
		qsort1(a, pivotposi-1, high);
	}
	else insert_sort(a, high - low+1);
} 




//第三种就是我们的采用随机数来进行找我们的对比对象
int pivotposition(int a[], int high, int low){
	int num = a[beg + rand() % (end-beg+1)];
	if(low<high){
		while(low < high && a[high] > num){ 
			high--;
			//一定是high先走！！！！！
			//因为只有一开始的low那里有一个空位，被num存走了 
		}
		a[low] = a[high];
		while(low<high && a[low] < num){
			low++;
		}
		a[high] = a[low];
	} 
	//high = low了，跳出循环
	a[high] = num;
	return high; 
}
void qsort(int a[], int low, int high){
	int pivotposi;
	if(low<high){
		pivotposi = pivotposition1(a, low,high);
		qsort(a, low, pivotposi);
		qsort(a, pivotposi-1, high);
	}
}


 

