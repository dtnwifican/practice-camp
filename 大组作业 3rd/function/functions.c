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


//����ʵ�� 
void quicksort(int arr[], int high, int low){
	int pivotposi;
	if(low<high){
		pivotposi = pivotposition(arr, high, low);
		//�ȴ�����ߵ�
		quicksort(arr, pivotposi-1, low);
		//�������pivotpositionλ���Ѿ��̶��� ��������
		quicksort(arr, high, pivotposi+1);
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
	arr[low] = num; 
	return high; 
}


////�鲢����ʵ��
//void mergesort(int a[],int l, int r,int count){
//	int b[count];
//	if(l == r){
//		//��ʱ����ǷֵĿ�ֻ��һ��Ԫ�ص������
//		//��ʱ���Ҫͣ�����ˣ����ع� 
//		return ; 
//	}
//	//�������������������� 
//	else{
//		int mid;
//		//�ֳɺܶ�飬ÿһ��ͬʱ����
//		mergesort(a,l,mid,count);
//		mergesort(a,mid+1,r,count);
//		int i = l, j = mid+1, k = 1;
//		//������Ƕ������ǵģ���ָ�룩
//		//k�ĳ�ʼ��1
//		
//		//������ǵ�����û���ƶ�����ߵı߽磺�м���ұߵı߽磺���ұߵ�ʱ�� 
//		while(i<mid && j<r){
//			if(a[i]<a[j]){
//				b[k] = a[i];
//				i++; 
//			}else{
//				b[k] = a[j];
//				j++;
//			}
//			k++;//��������� 
//		}	
//			//��һ�ߵ����ˣ����˳�ѭ����
//			//ֱ�Ӱ�û�����ĸ��Ƶ��ݴ���������� 
//		 	while(i<mid) b[k++] = a[i++];
//			while(j<r) b[k++] = a[j++];
//			
//			//���һ�����Ǽ��ɼ���Ľ����
//			//���и��£�
//			//������һ�����½��ͣ�����һ�飺���ĸ������ĸ�����һ���������ͬ�����в���������
//			//��ͬ����������ǵ�a��������ġ�
//			for(int i = 0; i<=r; i++) a[i] = b[i]; 
//	}
//} 
//�鲢����
void merge(int arr[], int tempArr[], int left, int mid, int right)
{
    // ����������һ��δ�����Ԫ��
    int l_pos = left;
    // ����Ұ�����һ��δ�����Ԫ��
    int r_pos = mid + 1;
    // ��ʱ����Ԫ�ص��±�
    int pos = left;

    // �ϲ�
    while (l_pos <= mid && r_pos <= right)
    {
        if (arr[l_pos] < arr[r_pos])  // �������һ��ʣ��Ԫ�ظ�С
            tempArr[pos++] = arr[l_pos++];
        else  // �Ұ�����һ��ʣ��Ԫ�ظ�С
            tempArr[pos++] = arr[r_pos++];
    }

    // �ϲ������ʣ���Ԫ��
    while (l_pos <= mid)
        tempArr[pos++] = arr[l_pos++];

    // �ϲ��Ұ���ʣ���Ԫ��
    while (r_pos <= right)
        tempArr[pos++] = arr[r_pos++];

    // ����ʱ�����кϲ����Ԫ�ظ��ƻ�ԭ��������
    while (left <= right)
    {
        arr[left] = tempArr[left];
        left++;
    }
}

// �鲢����
void msort(int arr[], int tempArr[], int left, int right)
{
    // ���ֻ��һ��Ԫ�أ���ô����Ҫ��������
    // ֻ��һ��Ԫ�ص����򣬱�����������ģ�ֻ��Ҫ���鲢����
    if (left < right)
    {
        // ���м��
        int mid = (left + right) / 2;
        // �ݹ黮�������
        msort(arr, tempArr, left, mid);
        // �ݹ黮���Ұ���
        msort(arr, tempArr, mid + 1, right);
        // �ϲ��Ѿ�����Ĳ���
        merge(arr, tempArr, left, mid, right);
    }
}

// �鲢�������
void mergesort(int arr[], int n)
{
    // ����һ����������
    int tempArr[n];
    // ����ʵ�ʵĹ鲢����
    msort(arr, tempArr, 0, n - 1);
}

//��������ʵ�֣�
//int * counting_sort(int arr[], int count, int max){
//	int i = 0;
//	int *countarr;
//	int *temarr;
//	//���ǵ��ۼ�����Ĵ�С�����ǵ�ԭ������������Ĵ�С 
//	countarr = (int*)malloc(max* sizeof(int));
//	temarr = (int*)malloc(max* sizeof(int));
//	
//	for(int t = 0; t<max; t++){
//		temarr[t] = 0;
//	}
//	//��ÿ�����ĳ��ֵ��ۼƴ�������� 
//	for(int j = 0; j<max; j++){
//		countarr[arr[j]]++;
//	}
//	//������ǰ����ǵ��ۻ�����Ͷ�Ӧ�±��ֵ�ۺ�һ��֮��ų���
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
   //�ҵ����ֵ
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	int range = max + 1;//���ٿռ������
	int* countArr = (int*)malloc(sizeof(int)*range);//���ٿռ�
	//��ʼ������ȫ��Ϊ0
	memset(countArr, 0, sizeof(int)*range);

	//��ʼ����
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i]]++;
	}

	//��ʼ����
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




//���������ʵ�� 
//void radixsort(int a[],int length){
//	//ʵ�����ǽ��������ǵļ������������
//	//���Ƿ�����10���õ���λ��ʮλ����λ��ǧλ�� 
//	//Ȼ�������Ƽ�������Ĳ�����ÿ�εõ���λ����������
//	//�����������ź�����
//	int max = a[0]; 
//	for(int i = 0; i<length; i++){
//		if(a[i]>max){
//			max = a[i];
//		}
//	} 
//	//���濪ʼ���λ��ʮλ����λ��...
//	//�����ǵ���������������λ��������ǧλ�����߰�λ����ֹ��
//	//�ðٷֺţ�ȡ��������м��㣩 
//	int div = 1;
//	
//	//��Ҫ����һ��0-9�� ���飺�������ǵ�ÿ�������λ�����м�������
//	int countarr[10] = {0}; 
//	int* t = (int*)malloc(max*sizeof(int)); 
//	while(max/div!=0){
//		for(int i =0; i<length; i++){
//			//���������ĩλ�� 
//			countarr[a[i]/div%10]++;
//		}
//		//����һ���ڴ��ݴ��м�Ľ��
//		for(int i = length-1; i>=0; i--){
//			while(countarr[a[i]/div %10 -1]!=0){
//				t[countarr[a[i]/div %10 -1]] = a[i];
//				countarr[a[i]/div %10 -1] --;
//			}
//		}
//		//���һ���ٴ�ţ�
//		for(int i =0; i<length; i++){
//			a[i] = t[i];
//			//�ٸ��£���ʵ��һ��Ҳ���Էŵ���һ��ѭ��
//			//���µ�������û������� 
//		} 
//		div = div*10;
//		//��һ��arr 
//	}
//}
void radixsort( int data[], int length )
{
	int i, k, maxVal, count, base;
	int bucket[10] = { 0 };
	int *buff = new int[ length ];
	//�������е����Ԫ�� 
	maxVal = data[0];
	for( i = 1; i < length; i++ )
	{
		if( data[i] > maxVal )
		{
			maxVal = data[i];
		}
	}
	//printf( "maxVal = %d\n", maxVal );
	//�������Ԫ�ص�λ�� 
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
		//��ÿһ��Ԫ�ص� baseλ�ϵ����֣���Ӧ��ͰԪ�����ۼ� 
		for( i = 0; i < length; i++  ) 
		{
			bucket[ ( data[i] / base ) % 10 ]++;
		}
		//���¼���ͰԪ�ص�ֵ��ÿһ��Ԫ�ض�����ǰ��Ԫ��֮��
		//��˲��������Եõ�ÿһ��Ͱ�е�Ԫ��������֮���λ���±� 
		for( i = 1; i < 10; i++ ) 
		{
			bucket[i] += bucket[i-1];
		}
		//����ͰԪ�ص�ֵ����data�е�Ԫ��������λ����buff��
		for( i = length-1; i >= 0; i-- ) 
		{
			buff[ bucket[ ( data[i] / base ) % 10 ] - 1 ] = data[i];
			bucket[ ( data[i] / base ) % 10 ]--;
		}
		//��buff��Ԫ�ض�λ��ŵ�data��
		for( i = 0; i < length; i++ ) 
		{
			data[i] = buff[i];
		}
		//���Ͱ������Ͱ��Ԫ�ع�0 
		for( i = 0; i < 10; i++ ) 
		{
			bucket[i] = 0;
		}
		//base��ֵ����10,֮�������һ������ 
		base *= 10;
	}
	delete[] buff;
}



//��������ʵ�� 
void insert_sort(int a[], int n){
	for(int i = 1; i<n; i++){
		//��������� 
		//�����ǵ�δ֪���еĵ�һ������������ 
		int key = a[i];
		//a[j]�����ǵ�Ҫ���бȽϵ��� 
		int j = i -1;
		while(j>=0 && a[j]>key){
			//�������һֱ�Ƚ�
			//���ǵ��Ǹ�������������ǰ�ߣ�ֱ��ǰ����������ǵ��������������С 
			
			//���Ʋ��� 
			a[j+1] = a[j];
			//���������ǰ�ƶ������Ĳ��� 
			j--;
		}
		a[j+1] = key;
		//�������ǵ�key�����ŵ�ʱ��Ϊ����Ҫ��ǰ��һ���ٷ����ǵ�key 
	}
}

//��ɫ����
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
			//������֮��p2��ǰ�� 
			p2--;
			continue;
		}
		if(a[p1] == 0&&a[p0] == 1){
			tem = a[p1];
			a[p1] = a[p0];
			a[p0] = tem;
			//Ȼ��p1��p0������ǰ��
			//������������������ֵ������ʲô��̺ʽ����
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
