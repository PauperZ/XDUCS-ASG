#include<stdio.h>

int quicksort(int a[], int l, int r) {             //һ�λ��� 
	if (l < r) {
		int i,j,x;
		i = l;
		j = r;
		x = a[i];
		while (i < j) {
			while(i < j && a[j] >= x)
				j--;   // ���������ҵ�һ��С��x����
			if(i < j)
				a[i++] = a[j];
			while(i < j && a[i] <= x)
				i++;   // ���������ҵ�һ������x����
			if(i < j)               //����Ԫ�� 
				a[j--] = a[i];
		}
		a[i] = x;       //�ڱ���λ 
		return i+1;
	}
}

void quick_sort(int a[], int l, int r) {          //�����㷨 
	int j;
	if (l >= r) return;
	int i = quicksort(a,l,r);  
	quick_sort(a,l,i-1);        //���ڱ�ǰ��������п��� 
	quick_sort(a,i,r);         //���ڱ����������п��� 
}

int main() {
	int a[1000],n,i;
	printf("������������������� ��");
	scanf("%d",&n);
	printf("��������������� ��");
	for(i = 0;i < n;i++) scanf("%d",&a[i]);
	quick_sort(a,0,n-1);
	printf("������Ϊ ��");
	for(i = 0;i < n;i++) printf("%d ",a[i]);
	
	return 0;
}

