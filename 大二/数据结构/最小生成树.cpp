#include<stdio.h>

typedef struct {                               //�ߵ����ݽṹ 
	int begin;
	int end;
	int weight;
}Edge;

void sort(Edge *a,int n) {                    //ͼ�бߵ������㷨��ѡ������ 
	int i,j;
	for(i = 0;i < n;i++) {
		for(j = i + 1;j < n;j++) {
			if(a[i].weight > a[j].weight) {
				int t1 = a[i].begin,t2 = a[i].end,t3= a[i].weight;
				a[i].begin = a[j].begin;
				a[i].weight = a[j].weight;
				a[i].end = a[j].end;
				a[j].begin = t1;
				a[j].end = t2;
				a[j].weight = t3;
			 }
		}
	}
}

//MFSet 
int Find(int *parent,int f) {             //���Һ����� ���ڶ�λ��С�������ĸ��ڵ� 
	while(parent[f]) {
		f = parent[f];
	}
	return f;
}

int max(int a,int b,int type) {           //���������еĽϴ�/��Сֵ 
	if(a > b) {
		if(type) return a;
		else return b; 
	}
	if(type) return b;
	else return a; 
}

void kruskal(Edge *a,int parent[],int m) {         //��³˹�����㷨 
	int i,begin,end;
	for(i = 0;i < m;i++) {
		begin = Find(parent,a[i].begin);
		end = Find(parent,a[i].end);
		if(begin != end) {
			parent[begin] = end;              //merge������ʵ�ֹ鲢����             
			printf("%d %d %d\n",max(a[i].begin,a[i].end,0),max(a[i].begin,a[i].end,1),a[i].weight);
		}
	}
}

int main() {
	int i,m,n;
	scanf("%d %d",&n,&m);                   //���������ͱ��� 
	Edge a[m];
	int parent[n+1];
	for(i = 0;i < m;i++)                    //��������ͼ 
		scanf("%d %d %d",&a[i].begin,&a[i].end,&a[i].weight);
    for(i = 0;i < n+1;i++)                  //���ڵ��ʼ�� 
		parent[i] = 0; 
	sort(a,m);                              //���ձߵ�Ȩֵ���� 
	kruskal(a,parent,m);
	return 0;
}
