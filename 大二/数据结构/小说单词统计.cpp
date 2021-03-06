#include<stdio.h>
#include<string.h>

typedef struct position {                //结构体用于存放文中出现单词的位置信息 
	int row;
	int num;
}pos;

void getnext(char a[],int next[],int n) {           //KMP算法获取Next函数 
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

int getnum(char a[],char b[],pos *p,int *t) {               //KMP算法实现 ，t用来指向单词出现次数的下标 
	int i = 0,j = 0,next[100] = {0},na,nb,sum = 0;          //sum统计单词本行出现的次数 
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
		if(j == nb) {                                      //匹配一个单词后开始下一个单词的统计 
			p[*t].num = i - j + 1;                         //记录单词列数 
			j = 0;                                         //重置单词字符串，进行本行下一个单词的匹配 
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
	char a[1000][300],b[100][100] = {0};                   //a数组存储文章信息，b数组存储单词信息 
	int sum[1000] = {0},i = 0,j = 0,k,m,ps = 0,pq,*t = &ps;         //sum存储每个单词出现次数，i,j,k,m为循环变量 
	while(!feof(fp)) {
		fgets(a[i],sizeof(a[i]) - 1,fp);                   //按行输入文章 
		i++;
	}
	fclose(fp);
	printf("请输入要查询的单词，每行一个，以#结束：\n");   
	gets(b[j]);
	while(b[j][0] != '#') {                                 //按行读入需要统计的单词 
		for(k = 0;k < i;k++) {
			pq = sum[j];
			sum[j] += getnum(a[k],b[j],p[j],t);            //统计每行单词个数和位置   
			for(m = pq;m < sum[j];m++) 
				p[j][m].row = k + 1;
		}
		*t = 0;
		j++;
		gets(b[j]);
	}
	for(i = 0;i < j;i++) {                                //按输入顺序输出各单词出现次数和位置 
		printf("\"");
		printf("%s",b[i]);
		printf("\" 单词在文中出现了 %d 次\n",sum[i]);
		for(k = 0;k < sum[i];k++) {
			printf("第 %d 个 \"",k+1);
			printf("%s",b[i]);
			printf("\" 的位置在第 %d 行 第 %d 列\n",p[i][k].row,p[i][k].num);
		}
	} 
	
	return 0;
}
