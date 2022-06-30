#include<stdio.h>

typedef struct Dot {
    int num = 0;
	int visit = 0;	
	int target;
}D;

typedef struct Queue {
	D a[1000];
	int front = 0;
	int rear = 0;
	int length = 0;
}Q;
typedef struct Queue *Lq;

void in(Lq p,D a) {
	p->a[p->rear].num = a.num;
	p->a[p->rear].visit = a.visit;
	p->a[p->rear].target = a.target;
	p->rear++;
	p->length++;
}

void out(Lq p,D *a) {
	a->num = p->a[p->front].num;
	a->visit = p->a[p->front].visit;
	a->target = p->a[p->front].target;
	p->front++;
	p->length--;
}

int main() {
	int i,j,n,a[100][100];
	D b[100],t; 
	Q q;
	Lq p = &q;
	scanf("%d",&n);
	for(i = 0;i < n;i++) 
		for(j = 0;j < n;j++) 
		    scanf("%d",&a[i][j]);   
		    
	for(i = 0;i < n;i++) b[i].target = i;		 //��ʼ���ڵ��� 
	in(p,b[0]);                                  //���׽ڵ������ 
	while(p->length != 0) {
		out(p,&t);                               //����ǰ���ӵĽڵ������Ϊ�׽ڵ� 
		for(i = 0;i < n;i++) {
			if(a[t.target][i]) {                 //������ڽڵ���ͨ������ 
				if(b[i].visit < n) {             //�ж��޻����������Ȩֵ 
					b[i].visit++;
					if(t.num + a[t.target][i] > b[i].num) {        //������������Ȩֵ�������Ȩֵ�����½ڵ���Ϊ�׽ڵ� 
						b[i].num = t.num + a[t.target][i];         
						if(i != n-1) in(p,b[i]);
					}
				}
				else {
					printf("NO");               //�л����NO 
					goto end;
				}
			}
		}
	}
	printf("%d",b[n-1].num); 
	
	end:
	return 0;
} 
