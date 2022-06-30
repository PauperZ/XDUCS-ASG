#include<stdio.h>
#include<time.h>   //time �õ���ͷ�ļ�
#include<stdlib.h>  // ������õ���ͷ�ļ�
#include<ctype.h>  //toascii() �õ���ͷ�ļ�
#include<string.h>  // ��������ʱ�Ƚ��õ�ͷ�ļ�
#define HASH_LEN 50  // ��ϣ��ĳ���
#define P 47  // С�ڹ�ϣ���ȵ� P
#define NAME_LEN 30  // ������ĳ���
typedef struct {
	// ������
	char *py;  // ���ֵ�ƴ��
	int m;  // ƴ������Ӧ��
} NAME;
NAME NameTable[HASH_LEN];  // ȫ�ֶ���������
typedef struct {
	// ��ϣ��
	char *py;  // ���ֵ�ƴ��
	int m;  // ƴ������Ӧ�� ASCII �ܺ�
	int si;  // ���ҳ���
} HASH;
HASH HashTable[HASH_LEN];  // ȫ�ֶ����ϣ��
int d[30],i,j;  // ȫ�ֶ�������� , ѭ���õ� i �� j
void InitNameTable() {
	// ������ĳ�ʼ��
	NameTable[0].py="caowukui";
	NameTable[1].py="langzhijie";
	NameTable[2].py="dongshuliang";
	NameTable[3].py="qiuhouyang";
	NameTable[4].py="zhangxu";
	NameTable[5].py="duhuan";
	NameTable[6].py="fanqing";
	NameTable[7].py="songxiaofei";
	NameTable[8].py="dutongtong";
	NameTable[9].py="sunhaohao";
	NameTable[10].py="shanjianfeng";
	NameTable[11].py="wangbaoshan";
	NameTable[12].py="houfeng";
	NameTable[13].py="hujiaming";
	NameTable[14].py="jiangkaiqiang";
	NameTable[15].py="xuyang";
	NameTable[16].py="lvdelu";
	NameTable[17].py="shenjinfeng";
	NameTable[18].py="xuhui";
	NameTable[19].py="hanle";
	NameTable[20].py="xunwenwen";
	NameTable[21].py="chenhongcong";
	NameTable[22].py="zhangyanyan";
	NameTable[23].py="nieyanshun";
	NameTable[24].py="haopengcheng";
	NameTable[25].py="yuhaiyuan";
	NameTable[26].py="shuxiang";
	NameTable[27].py="sunyingjie";
	NameTable[28].py="wangbo";
	NameTable[29].py="zhaoqing";
	NameTable[30].py="zhangshengqian";
	for (i=0; i<NAME_LEN; i++) {   // ���ַ����ĸ����ַ�����Ӧ�� ASCII ����ӣ����õ�������Ϊ��ϣ��Ĺؼ���
		int s=0;
		char *p=NameTable[i].py;
		for (j=0; *(p+j)!='\0'; j++)
			s+=toascii(*(p+j));
		NameTable[i].m=s;
	}
}
void CreateHashTable() {
	// ������ϣ��
	for(i=0; i<HASH_LEN; i++) {
		HashTable[i].py="\0";
		HashTable[i].m =0;
		HashTable[i].si=0;
	}
	for(i=0; i<NAME_LEN; i++) {
		int sum=1,j=0;
		int adr=(NameTable[i].m)%P;   // ����������  H(key)=key MOD p,p<=m
		if(HashTable[adr].si==0) {   // �������ͻ����������ֵ����ϣ��
			HashTable[adr].m =NameTable[i].m;
			HashTable[adr].py=NameTable[i].py;
			HashTable[adr].si=1;
		} else {    // �����ͻ
			while(HashTable[adr].si!=0) {
				adr=(adr+d[j++])%HASH_LEN;   // α���̽����ɢ�з������ͻ
				sum=sum+1;   // ���Ҵ����� 1
			}
			HashTable[adr].m =NameTable[i].m;   // ���������Ƹ���ϣ���Ӧ��λ����
			HashTable[adr].py=NameTable[i].py;
			HashTable[adr].si=sum;
		}
	}
}
void DisplayNameTable() {
	// ��ʾ������
	printf("\n ��ַ  \t\t  ����  \t\t  �ؼ��� \n");
	for (i=0; i<NAME_LEN; i++)
		printf("%2d %18s \t\t %d \n",i,NameTable[i].py,NameTable[i].m);
}
void DisplayHashTable() {
	//  ��ʾ��ϣ��
	float asl=0.0;
	printf("\n\n  ��ַ  \t\t  ����  \t\t  �ؼ���  \t  �������� \n");   // ��ʾ�ĸ�ʽ
	for (i=0; i<HASH_LEN; i++) {
		printf("%2d %18s \t\t %d \t\t %d\n",i,HashTable[i].py,HashTable[i].m,HashTable[i].si);
		asl+=HashTable[i].si;
	}
	asl/=NAME_LEN;    // ��� ASL
	printf("\n\n ƽ�����ҳ��ȣ� ASL(%d)=%f \n",NAME_LEN,asl);
}
void FindName() {
	// ����
	char name[20]= {0};
	int s=0,sum=1,adr;
	printf("\n ��������Ҫ���ҵ�������ƴ�� :");
	scanf("%s",name);
	getchar();
	for (j=0; j<20; j++)    // ���������ƴ������Ӧ�� ASCII ��Ϊ�ؼ���
		s+=toascii(name[j]);
	adr=s%P;    // ����������
	j=0;
	if(HashTable[adr].m==s&&!strcmp(HashTable[adr].py,name))    // �� 3 ����������жϣ���������ҽ��
		printf("\n ���� :%s �ؼ��� :%d  ���ҳ���Ϊ : 1\n",HashTable[adr].py,s);
	else if (HashTable[adr].m==0)
		printf(" û����Ҫ���ҵ��� !\n");
	else {
		while(1) { 
			adr=(adr+d[j++])%HASH_LEN;    // α���̽����ɢ�з������ͻ
			sum=sum+1;    // ���Ҵ����� 1
			if(HashTable[adr].m==0) {
				printf(" û����Ҫ���ҵ��� !\n");
				break;
			}
			if(HashTable[adr].m==s&&!strcmp(HashTable[adr].py,name)) {
				printf("\n ���� :%s �ؼ��� :%d  ���ҳ���Ϊ :%d\n",HashTable[adr].py,s,sum);
				break;
			}
		}
	}
}
int main() {
	// ������
	char c;
	int a=1;
	srand((int)time(0));
	for(i=0; i<30; i++)    // ������������α������� d[i] ���� 1 �� 50 ֮�䣩
		d[i]=1+(int)(HASH_LEN*rand()/(RAND_MAX+1.0));
	InitNameTable();
	CreateHashTable();
	printf("*******************************************************\n");
	printf("* *\n");
	printf("*  ��ϣ�����  *\n");
	printf("* *\n");
	printf("* A:  ��ʾ������  B:  ��ʾ��ϣ��  *\n");
	printf("* *\n");
	printf("* C:  ����  D:  �˳�  *\n");
	printf("* *\n");
	printf("*******************************************************\n");
	while(a) {
		printf("\n ��ѡ�� :");
		scanf("%c",&c);
		getchar();
		switch(c) {    // ����ѡ������жϣ�ֱ��ѡ���˳�ʱ�ſ����˳�
			case 'A':
			case 'a':
				DisplayNameTable();
				break;
			case 'B':
			case 'b':
				DisplayHashTable();
				break;
			case 'C':
			case 'c':
				FindName();
				break;
			case 'D':
			case 'd':
				a=0;
				break;
			default:
				printf("\n ��������ȷ��ѡ�� !\n");
				break;
		}
	}
	return 0;
}
