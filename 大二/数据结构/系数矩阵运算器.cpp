#include<stdio.h>

typedef struct datagroup {
    int m = 0;
	int n = 0;
	int num;	
}Dg;

int main() {
	char c;
	int m1,n1,m2,n2,i = 0,j,k = 0,t = 0,temp = 0,a[21][21] = {0};
	Dg t1[100],t2[100];
	printf("�������������㷽ʽ(+��-��*)��"); 
	scanf("%c",&c);
	printf("���������������������������"); 
	scanf("%d %d %d %d",&m1,&n1,&m2,&n2);
	switch(c) {
		case '+':
			if(m1 != m2 || n1 != n2) {
				printf("������������������������Ƿ���ȷ"); 
				break;
			}
			printf("��������������ϡ��������Ԫ�����ڵ��к����Լ�Ԫ��ֵ����0����:\n"); 
			a:scanf("%d",&t1[0].m);
			if(t1[0].m == 0 && temp == 1) break;
			else {
				if(t1[0].m == 0 && temp == 0) {
					temp++;
					goto a;
				}
				scanf("%d %d",&t1[0].n,&t1[0].num);
				a[t1[0].m][t1[0].n] += t1[0].num;
				goto a; 
			}
		case '-':
			if(m1 != m2 || n1 != n2) {
				printf("������������������������Ƿ���ȷ"); 
				goto e;
			}
			printf("��������������ϡ��������Ԫ�����ڵ��к����Լ�Ԫ��ֵ����0����:\n"); 
			b:scanf("%d",&t1[0].m);
			if(t1[0].m == 0 && temp == 1) break;
			else {
				if(t1[0].m == 0 && temp == 0) {
					temp++;
					goto b;
				}
				scanf("%d %d",&t1[0].n,&t1[0].num);
				if(temp == 0) a[t1[0].m][t1[0].n] += t1[0].num;
				else a[t1[0].m][t1[0].n] -= t1[0].num;
				goto b; 
			}
		case '*':
			if(n1 != m2) {
				printf("������������������������Ƿ���ȷ"); 
				goto e;
			}
			printf("��������������ϡ��������Ԫ�����ڵ��к����Լ�Ԫ��ֵ����0����:\n"); 
			c:if(temp == 0) scanf("%d",&t1[i].m);
			else scanf("%d",&t2[i].m);
			if(temp == 1 && t2[i].m == 0) {
				for(i = 0;i < t;i++) {
					for(j = 0;j < k;j++) {
						if(t1[i].n == t2[j].m) {
							a[t1[i].m][t2[j].n] += t1[i].num * t2[j].num;
						} 
					}
				}
				break;
			}
			else {
				if(t1[i].m == 0 && temp == 0) {
					temp++;
					i = 0;
					goto c;
				}
				if(temp == 0) {
					scanf("%d %d",&t1[i].n,&t1[i].num);
					i++;
					t++;
				}
				else {
					scanf("%d %d",&t2[i].n,&t2[i].num);
					i++;
					k++;
				}
				goto c; 
			}
	}
	for(i = 1;i <= m1;i++) {
		for(j = 1;j <= n2;j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	e:return 0;
}
