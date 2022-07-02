#include<stdio.h>
#include<string.h>
int main(){
    FILE *fin = fopen("file//words.txt","r");
    if (fin==NULL){
        printf("No such file!");
        return 0;
    }
    int choice;
    printf("��������Ҫ���еĲ���:\n1.ͳ��\n2.�滻�ַ���\n3.�˳�\n");
    scanf("%d",&choice);
    if (choice==1)
    {
        int numUpper[26]={0};
        int numLower[26]={0};
        char temp;
        int buff;
        while (feof(fin)==0)
        {
            temp = fgetc(fin);
            if(temp>='a'&&temp<='z'){
                buff = temp-'a';
                numLower[buff]++;
            }
            if(temp>='A'&&temp<='Z'){
                buff = temp-'a';
                numUpper[buff]++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            printf("%c:%d\n",97+i,numLower[i]);
        }
            for (int i = 0; i < 26; i++)
        {
            printf("%c:%d\n",65+i,numUpper[i]);
        }
        fclose(fin);
        return 0;
    }else if (choice== 2)
    {
        FILE *fout = fopen("file//words1.txt","w");
        char forward[50];
        char afterward[50];
        char temp[50];
        printf("�����뱻�滻���ַ���:");
        scanf("%s",forward);
        printf("�������滻���ַ���:");
        scanf("%s",afterward);
        while (feof(fin)==0)
        {
            fscanf(fin,"%s",temp);
            if (strcmp(forward,temp)==0)
            {
                fprintf(fout,"%s ",afterward);
            }else{
                fprintf(fout,"%s ",temp);
            }
        }
        fclose(fin);
        fclose(fout);
        remove("file//words.txt");
        rename("file//words1.txt","file//words.txt");
        printf("�滻���!");
        return 0;

    }else{
        fclose(fin);
        return 0;
    }
    
}