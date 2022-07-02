
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	unsigned int number;
	struct node * next;
}* pt,node;

void creat(pt * c, int a);

int yue(int m, int n);

int main ()
{
	int m, n;
	while(scanf("%d %d", &m, &n) != EOF)
	{
		printf("%d\n", yue(m, n));
	}
 } 
void creat (pt * c, int a)
{
	pt current, prev;
	* c = (pt) malloc (sizeof(node));
	prev = * c;
	for(int i = 1; a--; i++)
	{
		current = (pt) malloc (sizeof(node));
		current->number = i;
		prev->next = current;
		prev = current ;
	}
	current->next = (*c)->next;
}

int yue(int m,int n)
{
	pt head, current, prev; 
	creat(&head,m);
	current = head->next;//��ǰcurrent����Ԫ�ڵ��ˣ�Ҳ���� 1 ��
	for (int i = 1; i < m; i++) //m���ˣ�ʣ��һ���ˣ�����ѭ��m-1�Σ�ÿ��ѭ��ɾ��һ����
	{
		for (int j = 0; j < n - 1; j++)//��ʼ������һ��ִ��n-1�Σ����current����Ҫ��Ӧ�ñ�ɾ���ģ�����8 4������current��4��ʵ���������Ը��Ǵ�ɾ��ɾ������һ����Ҳ����5��
		{
			current = current->next;//������
		}
		prev = current->next; //��prev��¼Ҫ�������Ľڵ㣬���������ͷ�
		current->number = current->next->number;//����һ���ڵ㣨��ɾ����5������ת�Ƶ���һ���ڵ㣨4��
		current->next = current->next->next;//������һ���ڵ㣬ָ�����¸��ڵ�
		free(prev);//�ͷŵ��������Ľڵ�
	}
	return current->number;
}
