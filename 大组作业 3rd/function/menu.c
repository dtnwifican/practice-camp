#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h>
#include <time.h>
#include"head.h"


void menu(){
	printf("**********************************************************************************\n");
	printf("***1.��10000�����ݸ���ʱ��***2.��50000�����ݸ���ʱ��***3.��100000�����ݸ���ʱ��***\n");
	printf("*************************4.��ɫ����***5.�ҵڼ����Ԫ��****************************\n");
	printf("***************��������Ĵ����뿴�ļ����������������Ѿ�ȫ��ʵ�֣�*****************\n");
	printf("***************************6.������С���ݵ��������ʱ��***************************\n");
	printf("**************************************7.�˳�**************************************\n");
	printf("**********************************************************************************\n");
	int input;
	int begintime,endtime,begintime1,endtime1,begintime2,endtime2,begintime3,endtime3,begintime4,endtime4,begintime5,endtime5,begintime6,endtime6,begintime7,endtime7,
	begintime8,endtime8,begintime9,endtime9,begintime10,endtime10,begintime11,endtime11,begintime12,endtime12,begintime13,endtime13,begintime14,endtime14,begintime15,endtime15,
	begintime16,endtime16,begintime17,endtime17,begintime18,endtime18,begintime19,endtime19;
	int a[] = {1,2,1,0,2,0,0};
	int n = 7;
	int a1[] = {5,2,8,4,3,7,6};
	int num;
	int *randomarray,*randomarray1,*randomarray2,*randomarray4,*randomarray5,*randomarray6,
			*randomarray7,*randomarray8;
begin:
	printf("\n������Ҫ���еĲ���\n");
	scanf("%d",&input);
	switch(input){
		case 1: randomarray = make_data10000();
			begintime = clock(); 
			quicksort(randomarray, 9999, 0);
			endtime = clock();
			printf("\n����ʱ�䣺%dms\n", endtime-begintime);
			
			begintime1 = clock(); 
			mergesort(randomarray, 10000);
			endtime1 = clock();
			printf("\n�鲢ʱ�䣺%dms\n", endtime1-begintime1);
			
			begintime2 = clock(); 
			counting_sort(randomarray, 10000);
			endtime2 = clock();
			printf("\n��������ʱ�䣺%dms\n", endtime2-begintime2);
			
			begintime3 = clock(); 
			radixsort(randomarray, 10000);
			endtime3 = clock();
			printf("\n��������ʱ�䣺%dms\n", endtime3-begintime3);
			
			begintime4 = clock(); 
			insert_sort(randomarray, 10000);
			endtime4 = clock();
			printf("\n��������ʱ�䣺%dms\n", endtime4-begintime4);
			
			menu();
			break;
		case 2: 
			randomarray1 = make_data50000();
			begintime5 = clock(); 
			quicksort(randomarray1, 49999, 0);
			endtime5 = clock();
			printf("\n����ʱ�䣺%dms\n", endtime5-begintime5);
			
			begintime6 = clock(); 
			mergesort(randomarray1, 50000);
			endtime6 = clock();
			printf("\n�鲢ʱ�䣺%dms\n", endtime6-begintime6);
			
			begintime7 = clock(); 
			counting_sort(randomarray1, 50000);
			endtime7 = clock();
			printf("\n��������ʱ�䣺%dms\n", endtime7-begintime7);
			
			begintime8 = clock(); 
			radixsort(randomarray1, 50000);
			endtime8 = clock();
			printf("\n��������ʱ�䣺%dms\n", endtime8-begintime8);
			
			begintime9 = clock(); 
			insert_sort(randomarray1, 50000);
			endtime9 = clock();
			printf("\n��������ʱ�䣺%dms\n", endtime9-begintime9);
			
			menu();
			break;
		case 3: 
			randomarray2 = make_data200000();
			begintime10 = clock(); 
			quicksort(randomarray2, 199999, 0);
			endtime10 = clock();
			printf("\n����ʱ�䣺%dms\n", endtime10-begintime10);
			
			begintime11 = clock(); 
			mergesort(randomarray2, 200000);
			endtime11 = clock();
			printf("\n�鲢ʱ�䣺%dms\n", endtime11-begintime11);
			
			begintime12 = clock(); 
			counting_sort(randomarray2, 200000);
			endtime12 = clock();
			printf("\n��������ʱ�䣺%dms\n", endtime12-begintime12);
			
			begintime13 = clock(); 
			radixsort(randomarray2, 200000);
			endtime13 = clock();
			printf("\n��������ʱ�䣺%dms\n", endtime13-begintime13);
			
			begintime14 = clock(); 
			insert_sort(randomarray2, 200000);
			endtime14 = clock();
			printf("\n��������ʱ�䣺%dms\n", endtime14-begintime14);
			
			menu();
			break;
		case 4:
			printf("\n��ppt�ϵ���ĿΪ��������ɲ�\n");
			coloursort(a, n);
			
			menu();
			break;
		case 5:
			printf("\n��ppt�ϵ���ĿΪ����\n");
			for(int i = 0; i<7; i++){
				printf("%d ", a1[i]);
			}
			quicksort(a1, 6, 0);
			printf("\n������Ҫ�鿴�ĵڼ�С�����֣�");
			scanf("%d", &num);
			printf("���������%d\n",a1[num]);
			
			menu();
			break;
		case 6:
			begintime15 = clock();
			for(int i =0; i<100000; i++){
				randomarray4 = make_data100();
				quicksort(randomarray4, 99, 0);
			}
			endtime15 = clock();
			printf("\n����ʱ�䣺%dms\n", endtime15-begintime15);
			
			begintime16 = clock();
			for(int i =0; i<100000; i++){
				randomarray5 = make_data100();
				mergesort(randomarray5, 100);
			}
			endtime16 = clock();
			printf("\n�鲢ʱ�䣺%dms\n", endtime16-begintime16);
			
			begintime17 = clock();
			for(int i =0; i<100000; i++){
				randomarray6 = make_data100();
				counting_sort(randomarray6, 100);
			}
			endtime17 = clock();
			printf("\n����ʱ�䣺%dms\n", endtime17-begintime17);
			
			begintime18 = clock();
			for(int i =0; i<100000; i++){
				randomarray7 = make_data100();
				radixsort(randomarray7, 100);
			}
			endtime18 = clock();
			printf("\n����ʱ�䣺%dms\n", endtime18-begintime18);
			
			begintime19 = clock();
			for(int i =0; i<100000; i++){
				randomarray8 = make_data100();
				insert_sort(randomarray8, 100);
			}
			endtime19 = clock();
			printf("\n����ʱ�䣺%dms\n", endtime19-begintime19);
			
			menu();
			break;
		case 7 :
			printf("����Ҫ�˳���");	
			printf("����������˳���");
			getch();
			system("pause");
			exit(-1);
		default : printf("����������\n");
				goto begin;
				break;
	}
	
} 






