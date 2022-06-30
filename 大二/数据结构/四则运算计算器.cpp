#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Sqstack {             //������ʽ��ջ�ṹ 
	char elem[100];                  //���ʽ�еķ��� 
	int num[100];                    //���ʽ�е����� 
	int top;
	int type[100] = {0};             //ջ�ж�Ӧ����Ԫ�ص����ͣ�1Ϊ���֣�0Ϊ�ַ� 
}sqstack;

int pushc(sqstack *p,char c) {       //��ջ�������ַ��� 
	p->top++;
	p->elem[p->top] = c;
}

char popc(sqstack *p) {             //��ջ�������ַ��� 
	char c;
	if(p->top == -1) return 0;
	c = p->elem[p->top];
	p->top--;
	return c;
}

int pushn(sqstack *p,int n) {       //��ջ���������֣�
	p->top++;
	p->num[p->top] = n;
	p->type[p->top]++;
}

int popn(sqstack *p) {             //��ջ���������֣�
	int n;
	if(p->top == -1) return 0;
	p->type[p->top]--;
	n = p->num[p->top];
	p->top--;
	return n;
}

int tonum(char a[],int n,int *num) {        //��������ʽ�ַ����е������ַ�ת��Ϊ���� 
	int t=0,i,sum=0;
	while('0'<=a[n]&&a[n]<='9') {
		t++;
		n++;
	}
	*num = t-1;
	for(i = n - t;i < n;i++) {
		sum+=(a[i] - '0') * pow(10,t-1);
		t--;
	}
	return sum;
}

void transfer(sqstack *m,sqstack *s) {                //���ջ�������������ɺ�׺���ʽ 
	while(m->elem[m->top]!='('&&m->top != -1) {
		pushc(s,popc(m));
	}
}

int main() {
	int i = 0,j,*num,t;
	sqstack pre,mid,end;
	sqstack *p = &pre,*s = &end,*m = &mid;
	char c,a[100] = {0};
	pre.top = -1;
	end.top = -1;
	mid.top = -1;
	num = (int*)malloc(sizeof(int*));
	while(( c = getchar() ) != '\n') {
		a[i] = c;
		i++;
	} 
	for(j = 0;j < i;j++) {
		if('0'<=a[j]&&a[j]<='9') {
			pushn(p,tonum(a,j,num));
			j += *num;
		}
		else pushc(p,a[j]);
	}
	for(j = 0;j <= p->top;j++) {
		if(p->type[j]) {
			pushn(s,p->num[j]);
		}
		else{
			if(p->elem[j] != ')') {
				if(m->top != -1) {
					if((p->elem[j] == '*' || p->elem[j] == '/')&&(m->elem[m->top] == '*' || m->elem[m->top] == '/')){
						pushc(s,popc(m));
					} 
					else{
						if(p->elem[j] == '+' || p->elem[j] == '-') transfer(m,s);
					}
				}
				pushc(m,p->elem[j]);
			} 
			else{
				transfer(m,s);
				popc(m);
			}
		}
	}
	transfer(m,s);
	for(j = 0;j <= s->top;j++) {
		if(s->type[j]) {
			pushn(m,s->num[j]);
		}
		else{
			if(s->elem[j] == '+') {
				int x=popn(m);
				int y=popn(m);
				pushn(m,x+y);
			} 
			if(s->elem[j] == '-') {
				int x=popn(m);
				int y=popn(m);
				pushn(m,y-x);
			} 
			if(s->elem[j] == '*') {
				int x=popn(m);
				int y=popn(m);
				pushn(m,x*y);
			} 
			if(s->elem[j] == '/') {
				int x=popn(m);
				int y=popn(m);
				pushn(m,y/x);
			} 
		}
	}
	printf("%d",popn(m));
	return 0;	
} 





















