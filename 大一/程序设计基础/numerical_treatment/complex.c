#include<stdio.h>
struct complex
{
    int real;
    int imaginary;
}num1,num2,answer;
void add(){
    answer.real=num1.real+num2.real;
    answer.imaginary=num1.imaginary+num2.imaginary;
}
void differ(){
    answer.real=num1.real-num2.real;
    answer.imaginary=num1.imaginary-num2.imaginary;
}
void product(){
    answer.real=num1.real*num2.real-num1.imaginary*num2.imaginary;
    answer.imaginary=num1.real*num2.imaginary+num2.real*num1.imaginary;
}
void print(struct complex temp)
{
    if (temp.imaginary==0)
    {
        printf("%d",temp.real);
    }else if (temp.imaginary<0)
    {
        if (temp.imaginary==-1)
        {
            printf("%d-i",temp.real);
        }else{
            printf("%d%di",temp.real,temp.imaginary);
        }

    }else if (temp.imaginary>0)
    {
        if (temp.imaginary==1)
        {
            printf("%d+i",temp.real);
        }else{
            printf("%d+%di",temp.real,temp.imaginary);
        }
    }
}
int main(){
    int choice,flag=0;;
    printf("�������һ������(ע:ʵ�����鲿�ÿո����,0Ҳ������):");
    scanf("%d %d",&num1.real,&num1.imaginary);
    printf("������ڶ�������(ע:ʵ�����鲿�ÿո����,0Ҳ������):");
    scanf("%d %d",&num2.real,&num2.imaginary);
    while(flag==0){
        printf("��ѡ����Ҫ���е����㣺\n1.+\n2.-\n3.*\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            add();
            flag = 1;
            break;
        case 2:
            differ();
            flag = 1;
            break;
        case 3:
            product();
            flag = 1;
            break;        
        
        default:
            printf("�����������������룡\n");
            break;
        }
    }
    printf("���Ϊ��");
    print(answer);
}
