#include<stdio.h>

void getnext(char a[],int next[],int n) {
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

void A(char a[]) {     //����ֵ 
	
}

void E(char a[],char b[]) {     //�ж���� 
	int m,n,i;
	m = sizeof(a);
	n = sizeof(b);
	if(m != n) {
		printf("UNEQUAL");
		return;
	}
	else {
		for(i = 0;i < m;i++) {
			if(a[i] != b[i]) {
				printf("UNEQUAL");
				return;
			}
		} 
		printf("EQUAL");    
	}
}

void C(char a[],char b[],char c[]) {            //������ 
	int m = sizeof(a) - 1,n = sizeof(b),i;
	for(i = 0;i < m+n;i++) {
		if(i < m) c[i] = a[i];
		else c[i] = b[i];
	}
}

int L(char a[]) {      //�󴮵ĳ��� 
	return sizeof(a) - 1; 
}

void S(char a[],int m,int n);     //���Ӵ�

int I(char a[],char b[]) {                              //�Ӵ���λ 
	int next[255],m = L(b),n = L(a),i = 0,j = 0;
	getnext(b,next,m);
	while(i < n) {
		if(j == -1 || a[i] == b[j]) {
			i++;
			j++;
		}
		else
		    j = next[j];
		if(j == m) return i - j;
	}
} 

int main() {
	
	return 0;
}
