#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAXSIZE 50

typedef struct  {       //Huffman���Ķ���
	char name;
	unsigned int w;    //Ȩֵ
	unsigned int pa;   //���ڵ�
	unsigned int lch;   //������
	unsigned int rch;   //������
} HTnode;

typedef struct {   //Huffman����
	int data;
	char name1;
	char *pre;
} HCnode;

int N,M;
HCnode *HC;
HTnode *HT;

void Reverse(char *str) {    //�ַ������ã���˱㲻��Ҫ�������
	int i,j;
	char ch;
	for(i=0,j=strlen(str)-1; i<j; i++,j--) {
		ch=str[i];
		str[i]=str[j];
		str[j]=ch;
	}
}

int min_node(HTnode *HT,int n) { //Ѱ��Node����С�Ľڵ�
	int i,min;
	for(i=1; HT[i].pa; i++); //Ѱ�Ҹ��ڵ�
	min=i;
	for(i=1; i<n; i++)
		if(!HT[i].pa)
			if(HT[i].w<HT[min].w)
				min=i;
	HT[min].pa=1;
	return min;
}

void Output_HT(HTnode *HT) { //���Huffman��
	int i;
	printf(" ���  ���� Ȩֵ ���ڵ� ������ ������\n");
	for(i=1; i<2*N; i++) {
		printf(" |%-5d %c    %-5d %-5d %-6d %-4d|\n",i,
		       HT[i].name,HT[i].w,  
		       HT[i].pa,HT[i].lch,
		       HT[i].rch);
	}
}

void PrintHC(HCnode *HC) {    //���Huffman����
	FILE *f1,*f2;
	int i=0,j=0,x=0,n=0,wpl=0;      //wpl��Ȩ·������
	char temp[50];
	if((f1=fopen("ToBeTran.txt","r"))==NULL) {     //��ToBeTran.txt
		printf("open failed!\n");
		exit(0);
	}
	if((f2=fopen("Code.txt","w"))==NULL) {      //��Code.txt
		printf("open failed!\n");
		exit(0);
	}
	printf("���Huffman����\n");
	for(i=1; i<=N; i++)  {
		printf("%c-->%s",HC[i].name1,HC[i].pre);
		x=strlen(HC[i].pre);
		wpl+=(HC[i].data*x);
		printf("\n");
	}
	i=0;
	while(!feof(f1)) { //��ToBeTran�ж�ȡ�ַ���д��Code
		temp[i]=fgetc(f1);
		for(j=1; j<=N; j++)
			if(temp[i]==HC[j].name1) {
				fprintf(f2,"%s",HC[j].pre);
			}
		i++;
	}
	fprintf(f2,"\b");
	fclose(f1);
	fclose(f2);
}

HTnode *Create() {               //����Huffman��
	FILE *fp;
	int i,Si,Sj;                //�ҳ�����������С����������Si��Sj����
	HTnode *HT;
	HT=(HTnode *)malloc((2*N)*sizeof(HTnode));             //��HT����2N-1�������2N��
	if((fp=fopen("DataFile.txt","rt"))==NULL) {           //��ȡDataFile���ļ�
		printf("can not find file DataFile failed!\n");
		exit(0);
	}
	for(i=1; i<=N; i++) {
		fscanf(fp,"%c,%d",&HT[i].name,&HT[i].w);            //��Data�����ƺ�Ȩֵ��ֵ��HT
		HT[i].lch=HT[i].rch=HT[i].pa=0;                     //��ʼ��
	}
	printf("\n");
	for(; i<=M; i++)
		HT[i].lch=HT[i].rch=HT[i].pa=HT[i].w=0;            //����������������г�ʼ��
	for(i=N+1; i<=M; i++) {
		Si=min_node(HT,i);            //Ѱ����С�Ľڵ�
		Sj=min_node(HT,i);
		HT[i].w=HT[Si].w+HT[Sj].w;           //����
		HT[Si].pa=HT[Sj].pa=i;
		HT[i].lch=Si;
		HT[i].rch=Sj;
	}
	
	return HT;
}

HCnode *Coding(HTnode *HT) {                     //Huffman����
	int i,j,c,f;
	HCnode *HC;
	char data[MAXSIZE];
	HC=(HCnode *)malloc(N*sizeof(HCnode));                  //Ҷ�ӽڵ�ĸ���
	for(i=1; i<=N; i++) {
		memset(data,'\0',MAXSIZE);
		HC[i].name1=HT[i].name;                      //���������Ƹ�HC
		HC[i].data=HT[i].w;                         //Ȩֵ����
		for(c=i,j=0,f=HT[c].pa; f; c=f,f=HT[f].pa,j++) {          //���ڵ�ѭ����ֹ��HC[f]�ĸ��ڵ��f������Huffman����
			if(HT[f].lch==c) data[j]='0';           //������Ϊ0��������Ϊ1
			else data[j]='1';
		}
		HC[i].pre=(char *)malloc((strlen(data)+1)*sizeof(char));
		Reverse(data);                     //����Huffman����
		for(j=0; j<strlen(data)+1; j++)
			HC[i].pre[j]=data[j];
		HC[i].pre[j]='\0';                //��Huffman�����HC.pre[]
	}
	return HC;
}

void Decoding(HTnode *HT) {         //����
	FILE *fp1,*fp2;
	char ch[50];
	char cod[200];
	int f,root,i=0,j=0;
	if((fp1=fopen("CodeFile.txt","r"))==NULL) {
		printf("open file failed");
		exit(0);
	}
	if((fp2=fopen("Textfile.txt","w"))==NULL) {
		printf("open file failed");
		exit(0);
	}
	while(!feof(fp1)) {             //��Codefile���ļ���cod[]
		fscanf(fp1,"%c",&cod[i]);
		i++;
	}
	i=1;
	while(HT[i].pa) {
		i++;                //Ѱ�Ҹ��ڵ�
	}
	root=i;
	i=0;
	while(cod[i]!='\b') {             //��β
		f=root;
		while(HT[f].lch!=NULL) {             //��Ϊ��
			if(cod[i]=='0') f=HT[f].lch;
			else f=HT[f].rch;
			i++;
		}
		ch[j++]=HT[f].name;
	}
	ch[j]='\0';
	printf("\nCodeFile.txt����Ϊ:%s\n",ch);
	i=0;
	fprintf(fp2,"%s\b",ch);
	fclose(fp1);
	fclose(fp2);
}

void Output() {          //���Textfile.txt��ToBeTran.txt��Code.txt��CodeFile.txt��Textfile.txt
	int c;
	char b;
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	if((fp1=fopen("Datafile.txt","r"))==NULL) {
		printf("open file0 failed!\n");
		exit(0);
	}
	if((fp1=fopen("Datafile.txt","r"))==NULL) {
		printf("open file0 failed!\n");
		exit(0);
	}
	if((fp2=fopen("ToBeTran.txt","r"))==NULL) {
		printf("open file ToBeTran failed!\n");
		exit(0);
	}
	if((fp3=fopen("Code.txt","r"))==NULL) {
		printf("open file Code failed!\n");
		exit(0);
	}
	if((fp4=fopen("CodeFile.txt","r"))==NULL) {
		printf("open file CodeFile failed!\n");
		exit(0);
	}
	if((fp5=fopen("Textfile.txt","r"))==NULL) {
		printf("open file Textfile failed!\n");
		exit(0);
	}
	printf("\n���DataFlie�е��ַ�����Ȩֵ:\n");
	while(!feof(fp1)) {
		fscanf(fp1,"%c,%d", &b,&c);
		printf("'%c'---%d\n",b,c);
	}
	printf("\n\n���ToBeTran:\n");
	while(!feof(fp2)) {
		fscanf(fp2,"%c",&b);
		printf("%c",b);
	}
	printf("\n\n���Code.txt:\n");
	while(!feof(fp3)) {
		fscanf(fp3,"%c",&b);
		printf("%c",b);
	}
	printf("\n\n���CodeFile.txt:\n");
	while(!feof(fp4)) {
		fscanf(fp4,"%c",&b);
		printf("%c",b);
	}
	printf("\n\n���Textfile.txt:\n");
	while(!feof(fp5)) {
		fscanf(fp5,"%c",&b);
		printf("%c",b);
	}
	printf("\n");
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
}

void Output2(int n) {            //���Textfile.txt��ToBeTran.txt��Code.txt��CodeFile.txt��Textfile.txt
	int c;
	char b;
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	switch(n) {
		case 2:
			printf("\n���ToBeTran:\n");
			if((fp2=fopen("ToBeTran.txt","r"))==NULL) {
				printf("open file ToBeTran failed!\n");
				exit(0);
			}
			while(!feof(fp2)) {
				fscanf(fp2,"%c",&b);
				printf("%c",b);
			}
			fclose(fp2);
			break;
		case 3:
			printf("\n\n���Code.txt:\n");
			if((fp3=fopen("Code.txt","r"))==NULL) {
				printf("open file Code failed!\n");
				exit(0);
			}
			while(!feof(fp3)) {
				fscanf(fp3,"%c",&b);
				printf("%c",b);
			}
			fclose(fp3);
			break;
		default:
			printf("ERROR!");
	}
	printf("\n");
}        

int main() {
	int i;
	char c;
	FILE *fp;
	char **code;   //����һ����ά���������
	char ope;
	printf("����Data�ļ�������Ҷ�ڵ���� : ");
	scanf("%d",&N);
	printf("��������Ҫ���еĲ�����"); 
	c = getchar();
	c = getchar();
	while(c != 'Q') {
		if(N>0&&N<=500) {
			M=2*N-1;
			code=(char**)malloc(100*sizeof(char));
			for(i=0; i<N; i++)
				code[i]=(char *)malloc(8*sizeof(char));
			HT=Create();
			if(c == 'T') Output_HT(HT);
			if(c == 'E') {
				printf("��Huffman�����б���:\n");
				HC=Coding(HT);
				PrintHC(HC);
				printf("-------------------------------------------------------------------\n");
				printf("��ToBeTran�����ݸ�д�ɱ���д��Code.txt\n");
				Output2(3);
			}
			if(c == 'D') {
				Output2(2);
				printf("-------------------------------------------------------------------\n");
				printf("���ļ�CodeFile.data�еĴ�����н����γ�ԭ�ģ���������ļ�Textfile.txt��\n");
		    }
			printf("\n��������Ҫ���еĲ�����"); 
	        c = getchar();
	        c = getchar();
		} 
		else printf("����������:\n");
	}
	
	return 0;
}
