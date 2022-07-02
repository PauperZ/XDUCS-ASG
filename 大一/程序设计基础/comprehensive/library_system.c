#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book{
    int number;
    char name[30];
    int amount;
}Book;
struct reader{
    int id;
    char name[20];
    char borrowedBook[30];
    //flag=1��˵���ڽ���״̬��
    int flag;
}Reader;
int adminOperate();
int adminOperateB();
int adminOperateR();
int readerOperate();
int bookBorrow();
int bookReturn();
void whoBorrowBook();
int searchBook();
int readerMatch();
int bookAdd();
int bookRevise();
int bookDelete();
int readerAdd();
int readerRevise();
int readerDelete();
int main(){
    int choice;
    printf("��ѡ���������:\n1.����Ա\n2.����\n");
    scanf("%d",&choice);
    if (choice==1)
    {
        char passward[20];
        printf("���������Ա����:");
        scanf("%s",passward);
        if (strcmp(passward,"114514")==0)
        {
            printf("��ӭ��,����Ա��\n");
            if(adminOperate()==0){
                return 0;
            }
        }else{
            printf("�������");
            return 0;
        }
    }
    else if(choice==2){
        if(readerMatch()==1){
            readerOperate();
        }else{
            return 0;
        }
    }
}
//����ƥ��
int readerMatch(){
    FILE *reader = fopen("file//readers.txt","r");
    int id,sign=0;
    char name[20];
    printf("���������ı�ź�����,�м��ÿո����!\n");
    scanf("%d %s",&id,name);
    while (feof(reader)==0)
    {
        fscanf(reader,"%d%20s%10d%30s\n",&Reader.id,Reader.name,&Reader.flag,Reader.borrowedBook);
        if (id==Reader.id&&(strcmp(name,Reader.name)==0))
        {
            printf("������ϢΪ:\n���:%d\n����%s\n",id,name);
            sign=1;
            fclose(reader);
            return 1;
        }
    }
    if (sign==0)
    {
        printf("ϵͳ��δ��ѯ��������Ϣ,����ϵͼ��ݹ���Ա¼����Ϣ!\n");
        fclose(reader);
        return 0;
    }
    return 0;
}
//��ѯ�鼮
int searchBook(){
    FILE *book = fopen("file//books.txt","r");
    FILE *reader = fopen("file//books.txt","r");
    if (book==NULL||reader==NULL)
    {
        printf("�����쳣��");
    }
    int choice,flag=0;
    printf("��ѡ���ѯ��ʽ��\n1.���\n2.����\n");
    scanf("%d",&choice);
    if (choice==1)
    {
        int num;
        printf("��������ı�ţ�\n");
        scanf("%d",&num);
        while (feof(book)==0)
        {
            fscanf(book,"%d%20s%10d\n",&Book.number,Book.name,&Book.amount);
            if (num==Book.number)
            {
                flag=1;
                printf("���:%d\n����:%s\n����:%d\n",Book.number,Book.name,Book.amount);
            }
            if (flag==1){
                break;
            }
        }
        
    }else if(choice==2){
        char name[30];
        printf("������������ƣ�\n");
        scanf("%s",name);
        while (feof(book)==0)
        {
            fscanf(book,"%d%20s%10d\n",&Book.number,Book.name,&Book.amount);
            if (strcmp(name,Book.name)==0)
            {
                flag=1;
                printf("���:%d\n����:%s\n����:%d\n",Book.number,Book.name,Book.amount);
                break;
            }
        }
    }
    fclose(book);
    fclose(reader);
    if (flag==0){
        printf("�Բ���,���޸��鼮��Ϣ!��������ϵͼ��ݹ���Ա����!\n");
        return 0;
    }
    return 1;
}
//���߲���
int readerOperate(){
    int choice;
    printf("��ѡ����Ҫ���еĲ���:\n1.����ͼ��\n2.�黹ͼ��\n");
    scanf("%d",&choice);
    if(choice==1){
        bookBorrow();
    }else if(choice==2){
        bookReturn();
    }else{
        printf("�������ָ������,����������!");
        readerOperate();
    }
    return 0;
}
//���߽������
int bookBorrow(){
    if (Reader.flag==1){
    printf("�Բ���,ÿ�˽��޽���һ����!\n����ǰ�����鼮��Ϣ:\n");
    printf("�鼮����:%s\n",Reader.borrowedBook);
    printf("��黹���ٽ���!");
    }else{
        printf("�����Ҫ���ĵ��鼮��\n");
        if (searchBook()==1)
        {
            if (Book.amount<1)
            {
                printf("�Ȿ����ȫ�������\n");
            }else{
                int tempreader = Reader.id;
                char booked[30];
                int tempbook = Book.number;
                strcpy(booked,Book.name);
                FILE *reader1 = fopen("file//readers.txt","r");
                FILE *reader2 = fopen("file//readers2.txt","w");
                FILE *book1 = fopen("file//books.txt","r");
                FILE *book2 = fopen("file//books2.txt","w");
                while (feof(book1)==0)
                {
                    fscanf(book1,"%d%s%d\n",&Book.number,Book.name,&Book.amount);
                    if (Book.number!=tempbook){
                        fprintf(book2,"%d%30s%10d\n",Book.number,Book.name,Book.amount);
                    }else{
                        fprintf(book2,"%d%30s%10d\n",Book.number,Book.name,Book.amount-1);
                    }
                }
                while (feof(reader1)==0)
                {
                    fscanf(reader1,"%d%s%d%s\n",&Reader.id,Reader.name,&Reader.flag,Reader.borrowedBook);
                    if (Reader.id!=tempreader){
                        fprintf(reader2,"%d%20s%10d%30s\n",Reader.id,Reader.name,Reader.flag,Reader.borrowedBook);
                    }else{
                        fprintf(reader2,"%d%20s%10d%30s\n",Reader.id,Reader.name,1,booked);
                    }                    
                }
                printf("���ĳɹ���");
                fclose(reader2);
                fclose(reader1);
                fclose(book2);
                fclose(book1);
                remove("file//books.txt");
                remove("file//readers.txt");
                rename("file//readers2.txt","file//readers.txt");
                rename("file//books2.txt","file//books.txt");
            }
            
        }else{
            bookBorrow();
        }
        
    }
    return 0;
}
//���߻������
int bookReturn(){
    if (Reader.flag==0){
        printf("����ǰδ����ͼ��,����黹��\n");
        return 0;
        }else{
                int tempreader = Reader.id;
                char tempbook[30];
                strcpy(tempbook,Reader.borrowedBook);
                FILE *reader1 = fopen("file//readers.txt","r");
                FILE *reader2 = fopen("file//readers2.txt","w");
                FILE *book1 = fopen("file//books.txt","r");
                FILE *book2 = fopen("file//books2.txt","w");
                while (feof(book1)==0)
                {
                    fscanf(book1,"%d%30s%10d\n",&Book.number,Book.name,&Book.amount);
                    if (strcmp(tempbook,Book.name)==0){
                        fprintf(book2,"%d%30s%10d\n",Book.number,Book.name,Book.amount+1);
                    }else{
                        fprintf(book2,"%d%30s%10d\n",Book.number,Book.name,Book.amount);
                    }
                }
                while (feof(reader1)==0)
                {
                    fscanf(reader1,"%d%20s%10d%30s\n",&Reader.id,Reader.name,&Reader.flag,Reader.borrowedBook);
                    if (tempreader!=Reader.id){
                        fprintf(reader2,"%d%20s%10d%30s\n",Reader.id,Reader.name,Reader.flag,Reader.borrowedBook);
                    }else{
                        fprintf(reader2,"%d%20s%10d%30s\n",Reader.id,Reader.name,0,"0");
                    }                    
                }
                printf("����ɹ���");
                fclose(reader2);
                fclose(reader1);
                fclose(book2);
                fclose(book1);
                remove("file//books.txt");
                remove("file//readers.txt");
                rename("file//readers2.txt","file//readers.txt");
                rename("file//books2.txt","file//books.txt");
                return 1;
    }
}
//����Ա����ѡ��
int adminOperate(){
    int choice;
    printf("��ѡ����Ҫ���в����Ķ���:\n1.ͼ��\n2.����\n3.�˳�\n");
    scanf("%d",&choice);
    if(choice==1){
        adminOperateB();
    }else if(choice==2){
        adminOperateR();
    }else if(choice==3){
        printf("�ѳɹ��˳���");
        return 0;
    }else{
        printf("�������ָ������,����������!\n");
        adminOperate();
    }
    return 0;
}
//����Ա���鼮�Ĳ���
int adminOperateB(){
    int choice;
    printf("��ѡ����������Ҫ���еĲ���:\n1.¼��ͼ����Ϣ;\n2.�޸�ͼ����Ϣ;\n3.ɾ��ͼ����Ϣ;\n4.��ѯ������;\n5.������һ��\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        bookAdd();
        break;
    case 2:
        bookRevise();
        break;
    case 3:
        bookDelete();
        break;
    case 4:
        whoBorrowBook();
        break;
    case 5:
        adminOperate();
        break;
    default:
        printf("�������ָ������,����������!\n");
        break;
    }
    return 0;
}
//����Ա�Զ�����Ϣ�Ĳ���
int adminOperateR(){
    int choice1;
    printf("��ѡ����������Ҫ���еĲ���:\n1.¼�������Ϣ;\n2.�޸Ķ�����Ϣ;\n3.ɾ��������Ϣ;\n4.����\n");
    scanf("%d",&choice1);
    switch (choice1)
    {
    case 1:
        readerAdd();
        break;
    case 2:
        readerRevise();
        break;
    case 3:
        readerDelete();
        break;
    case 4:
        adminOperate();
        break;
    default:
        printf("�������ָ������,����������!");
        adminOperateR();
        break;
    }
    return 0;
}
int bookAdd(){
    int tempnum,tempamount;
    char tempname[30];
    FILE *book = fopen("file//books.txt","r+");
    printf("��������Ҫ¼���鼮����Ϣ��\n(��ʽ:��� ���� ����)\n");
    scanf("%d %s %d",&tempnum,tempname,&tempamount);
    while (feof(book)==0)
        fscanf(book,"%d %s %d\n",&Book.number,Book.name,&Book.amount);
    fprintf(book,"%d%30s%10d\n",tempnum,tempname,tempamount);
    printf("¼��ɹ���\n");
    fclose(book);
    return 0;
}
int bookRevise(){
    int id;
    int tempid,tempamount;
    char tempname[30];
    printf("��������Ҫ�޸��鼮�ı�ţ�\n");
    scanf("%d",&id);
    printf("�������޸ĺ��鼮����Ϣ��\n(��ʽ:��� ���� ����)\n");
    scanf("%d %s %d",&tempid,tempname,&tempamount);
    FILE *book1 = fopen("file//books.txt","r");
    FILE *book2 = fopen("file//books2.txt","w");
    while (!feof(book1))
    {
        fscanf(book1,"%d%30s%10d\n",&Book.number,Book.name,&Book.amount);
        if (Book.number==id){
            fprintf(book2,"%d%30s%10d\n",tempid,tempname,tempamount);
        }else{
            fprintf(book2,"%d%30s%10d\n",Book.number,Book.name,Book.amount);
        }
    }
    printf("�޸ĳɹ���\n");               
    fclose(book2);
    fclose(book1);
    remove("file//books.txt");
    rename("file//books2.txt","file//books.txt");          
    return 0;
}
int bookDelete(){
    int id;
    printf("��������Ҫɾ���鼮�ı�ţ�\n");
    scanf("%d",&id);
    FILE *book1 = fopen("file//books.txt","r");
    FILE *book2 = fopen("file//books2.txt","w");
    while (feof(book1)==0)
    {
        fscanf(book1,"%d%30s%10d\n",&Book.number,Book.name,&Book.amount);
        if (Book.number!=id){
            fprintf(book2,"%d%30s%10d\n",Book.number,Book.name,Book.amount);
        }else{
            continue;
        }
    }
    printf("ɾ���ɹ���\n");               
    fclose(book2);
    fclose(book1);
    remove("file//books.txt");
    rename("file//books2.txt","file//books.txt");  
    return 0;
}
int readerAdd(){
    int tempid;
    char tempname[20];
    FILE *reader = fopen("file//readers.txt","r+");
    printf("��������Ҫ¼����ߵ���Ϣ��\n(��ʽ:��� ����)\n");
    scanf("%d %s",&tempid,tempname);
    while (feof(reader)==0)
        fscanf(reader,"%d %s %d %s\n",&Reader.id,Reader.name,&Reader.flag,Reader.borrowedBook);
    fprintf(reader,"%d%20s%10d%30s\n",tempid,tempname,0,"0");
    printf("¼��ɹ���\n");
    fclose(reader);
    return 0;
}
int readerRevise(){
    int id;
    int tempid;
    char readername[20];
    char tempname[30];
    printf("��������Ҫ�޸Ķ��ߵı��\n");
    scanf("%d",&id);
    printf("�������޸ĺ���ߵ���Ϣ��\n(��ʽ:��� ����)\n");
    scanf("%d %s",&tempid,readername);
    strcpy(tempname,"0");
    FILE *reader1 = fopen("file//readers.txt","r");
    FILE *reader2 = fopen("file//readers2.txt","w");
    while (feof(reader1)==0)
    {
        fscanf(reader1,"%d%s%d%s\n",&Reader.id,Reader.name,&Reader.flag,Reader.borrowedBook);
        if (id!=Reader.id){
            fprintf(reader2,"%d%20s%10d%30s\n",Reader.id,Reader.name,Reader.flag,Reader.borrowedBook);
        }else{
            fprintf(reader2,"%d%20s%10d%30s\n",tempid,readername,Reader.flag,Reader.borrowedBook);
        }                    
    }
    printf("�޸ĳɹ���\n");
    fclose(reader2);
    fclose(reader1);                
    remove("file//readers.txt");
    rename("file//readers2.txt","file//readers.txt");
    return 0;
}
int readerDelete(){
    int id;
    printf("��������Ҫɾ�����ߵı�ţ�\n");
    scanf("%d",&id);
    FILE *reader1 = fopen("file//readers.txt","r");
    FILE *reader2 = fopen("file//readers2.txt","w");
    while (feof(reader1)==0)
    {
        fscanf(reader1,"%d%s%d%s\n",&Reader.id,Reader.name,&Reader.flag,Reader.borrowedBook);
        if (id!=Reader.id){
            fprintf(reader2,"%d%20s%10d%30s\n",Reader.id,Reader.name,Reader.flag,Reader.borrowedBook);
        }else{
            continue;
        }                    
    }
    printf("ɾ���ɹ���\n");
    fclose(reader2);
    fclose(reader1);                
    remove("file//readers.txt");
    rename("file//readers2.txt","file//readers.txt");
    return 0;
}
void whoBorrowBook(){
    char book[30];
    printf("�������鼮���ƣ�");
    scanf("%s",book);
    printf("��Щ�˽������Ȿ�飺\n");
    FILE *reader = fopen("file//readers.txt","r");
    while(!feof(reader))
    {
        fscanf(reader,"%d%20s%d%30s\n",&Reader.id,Reader.name,&Reader.flag,Reader.borrowedBook);
        if(strcmp(Reader.borrowedBook,book)==0)
        {
            printf("%d%20s\n",Reader.id,Reader.name);
        }
    }
    fclose(reader);
}
