#include<stdio.h>
#include<string.h>

typedef struct position {                //�ṹ�����ڴ�����г��ֵ��ʵ�λ����Ϣ 
	int row;
	int num;
}pos;

void getnext(char a[],int next[],int n) {           //KMP�㷨��ȡNext���� 
	int i = 0,j = -1;
	next[0] = -1;
	while(i < n) {
		if(j == -1 || a[i] == a[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else 
			j = next[j];
	}
}

int getnum(char a[],char b[],pos *p,int *t) {               //KMP�㷨ʵ�� ��t����ָ�򵥴ʳ��ִ������±� 
	int i = 0,j = 0,next[100] = {0},na,nb,sum = 0;          //sumͳ�Ƶ��ʱ��г��ֵĴ��� 
	nb = strlen(b);
	getnext(b,next,nb);
	na = strlen(a);
	while(i < na) {
		if(j == -1 || a[i] == b[j]) {
			i++;
			j++;
		}
		else 
			j = next[j];
		if(j == nb) {                                      //ƥ��һ�����ʺ�ʼ��һ�����ʵ�ͳ�� 
			p[*t].num = i - j + 1;                         //��¼�������� 
			j = 0;                                         //���õ����ַ��������б�����һ�����ʵ�ƥ�� 
            *t = *t + 1;                                    
			sum++;
		}
	}
	return sum;
}

int main() {
	FILE *fp;
	fp = fopen("text.txt","r");
	pos p[100][1000];
	char a[1000][300],b[100][100] = {0};                   //a����洢������Ϣ��b����洢������Ϣ 
	int sum[1000] = {0},i = 0,j = 0,k,m,ps = 0,pq,*t = &ps;         //sum�洢ÿ�����ʳ��ִ�����i,j,k,mΪѭ������ 
	while(!feof(fp)) {
		fgets(a[i],sizeof(a[i]) - 1,fp);                   //������������ 
		i++;
	}
	fclose(fp);
	printf("������Ҫ��ѯ�ĵ��ʣ�ÿ��һ������#������\n");   
	gets(b[j]);
	while(b[j][0] != '#') {                                 //���ж�����Ҫͳ�Ƶĵ��� 
		for(k = 0;k < i;k++) {
			pq = sum[j];
			sum[j] += getnum(a[k],b[j],p[j],t);            //ͳ��ÿ�е��ʸ�����λ��   
			for(m = pq;m < sum[j];m++) 
				p[j][m].row = k + 1;
		}
		*t = 0;
		j++;
		gets(b[j]);
	}
	for(i = 0;i < j;i++) {                                //������˳����������ʳ��ִ�����λ�� 
		printf("\"");
		printf("%s",b[i]);
		printf("\" ���������г����� %d ��\n",sum[i]);
		for(k = 0;k < sum[i];k++) {
			printf("�� %d �� \"",k+1);
			printf("%s",b[i]);
			printf("\" ��λ���ڵ� %d �� �� %d ��\n",p[i][k].row,p[i][k].num);
		}
	} 
	
	return 0;
}
