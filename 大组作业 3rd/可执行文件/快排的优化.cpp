//���������ǵ����м�ֵ���Ż�
//Ҫ���ҵ���������0��1��2��3��4��5��6��7��9��8 
//���ͣ��������ǵ�Ҫ���Ұ���Ĭ�ϵ�ȡ�� Ҫ����ȡ��һ����Ϊlow
//��ô����ÿ��ѭ�������lowѭ���������ˣ�����low��high��Ӧ���±��Ԫ�ض����һ� 
//����ֻ���ұߵ�high��������ߣ������Ļ�ѭ����Ҫ������������ĳ���
//Ҫ�����ǵĵ�һ��Ԫ�أ�Ĭ�ϱȽ�ֵ�����м��С��Ԫ�صĻ������ҵ�ѭ����high��low�ĸ��£��;�Ȼ����� 
//��������ͬʱ���м��� 
//��ʱ�����ǵ�ѭ���Ϳ��Լ���һ�����
//ֻҪ��ȡ��������ֵ������Сֵ���ӿ����м�ֵ��Ԫ��
//�������ǵ�ѭ�������кܴ�ô��ģ�����ȡ���ڶ��Ķ��кô��� 
//��ȡ���м�ֵ���ǿ��Լ���һ��Ĵ�ѭ�����������������������߷����������ģ�
// Ҫ�����ǵ��м�ֵ�����м丽����λ�ã���Ҫ������˳��ܶԣ����ܼ��ٵľ��Ƿǳ����
// ������һ�У�Ҫ������˳������м�ֵ���м�����������ߣ�ѭ�����������Ƕ���һ����


//�������ǵĵ�һ���Ľ�������ȡ����ԡ���ֵ��
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
		//�����޷�ȷ�������һ�ɷ���high
		//���������ҵ�����м��С��Ԫ���ˣ����� 
		//���Լ��ٺܶ��ѭ���� 
	}
	else if(a[mid] > a[low]){
		if(a[high] > a[mid]){
			return mid;
		}
		if(a[low] > a[high]){
			return low;
		}
		else return high;
		//�����޷�ȷ�������һ�ɷ���high
		//���������ҵ�����м��С��Ԫ���ˣ����� 
		//���Լ��ٺܶ��ѭ���� 
	} 
} 
int pivotposition1(int a[], int high, int low){
	int num = getmidindex(a, low, high);
	if(low<high){
		while(low < high && a[high] > num){ 
			high--;
			//һ����high���ߣ���������
			//��Ϊֻ��һ��ʼ��low������һ����λ����num������ 
		}
		a[low] = a[high];
		while(low<high && a[low] < num){
			low++;
		}
		a[high] = a[low];
	} 
	//high = low�ˣ�����ѭ��
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

//�ڶ��־������ǵ�Ҫ�����ǵ�low��high�м�������Ԫ��Ҫ�Ǻ��٣�
//���ǾͲ������ǵĿ������򣺿�����20������һ�»�����������
//���ǻ����ǵĲ�������
void qsort1(int a[], int low, int high){
	int pivotposi;
	if(high - low >20){
		pivotposi = pivotposition1(a, low,high);
		qsort1(a, low, pivotposi);
		qsort1(a, pivotposi-1, high);
	}
	else insert_sort(a, high - low+1);
} 




//�����־������ǵĲ�������������������ǵĶԱȶ���
int pivotposition(int a[], int high, int low){
	int num = a[beg + rand() % (end-beg+1)];
	if(low<high){
		while(low < high && a[high] > num){ 
			high--;
			//һ����high���ߣ���������
			//��Ϊֻ��һ��ʼ��low������һ����λ����num������ 
		}
		a[low] = a[high];
		while(low<high && a[low] < num){
			low++;
		}
		a[high] = a[low];
	} 
	//high = low�ˣ�����ѭ��
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


 

