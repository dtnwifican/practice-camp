//�����Ǽ�flag�ķ���
/*ÿ��ð������ǰ��С�Ķ�Ҫ�ͺ����Ļ�λ�ã�Ҫ�Ƕ����ź���ľͲ��ö����ˣ�
�������ǵ�һ���ð������û����ֹ��������һֱѭ����
����Ҫ�Ǽ������һ�η���λ�øı�ĵط�
�����λ�ÿ��ܺ�ԭ��ѭ��Ӧ�ñ�����λ�ò��Զ�������м���������øı䣨˳���ǶԵģ���
�´�ѭ��ֱ�ӱ��������һ�ν���λ�õĵط�������
*/
/*
�����ѭ�������ÿ��ѭ�������Խ�ʡ�ܶ��
*/
void bubblesort(int num[], int size){
	int temp;
	int flag;
	flag = size-1;
	while(flag >0){
		stop_posi = flag;
		//ע�⣡�������stop_posi���ֹͣѭ��λ�õı���ÿ�� ��������ѭ������ 
		flag = 0;
		//����Ǻ������ѭ��������Ӧ��
		//Ҫ��û�б仯��ô���ǵ�flag����0�����ǾͲ�ѭ���ˣ��������ֱ���ź������ 
		for(int i = 0; i<stop_posi; i++){
			if(num[i]>num[i+1]){
				temp = num[i];
				num[i] = num[i+1];
				num[i+1] = temp;
				flag = i;
				//���µ�����ĶԻ�ǰ�����
				//���õ��Ļ��������Ժ������������Ӧ������Ĳ���˳������Ϊ��ǰ��
				//������Ԫ�ض����� 
			}
		}
	}
} 


//���������ǵ�˫��ð�ݣ�
//ð��������ð�ݣ�
//�����ǿ��Լ���һ���

//��Ĵ�ѭ������Сѭ��������Сѭ�� 
//����Сֵ�����ֵ���϶Գ��Ÿ�����
//�������Լ��ٺܶ�ѭ���ɱ� 
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

//�����ۺϣ�
//Ҫ�Ǵ�ǰ���������ŵ��м��ĳһ����֮���ͣ������
//˵��������ź��� �Ӻ���ǰ�ŵ�ֻҪ��ֹͣ����ĵط���ǰ���������
//�Ӻ���ǰ�ŵ�ͬ�� 
void bubblesort3(int num[], int size){
	int flag = 0;
	int temp;
	//���ó�ʼֵ 
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
	flag = -1;//�����ѭ�����滹��Ҫ���õģ����� 
	} 
} 




