#include<stdio.h>
int calculate(int n){
    int m=0,d;
    while (n!=0)
    {
        d=n%10;
        m+=d*d;
        n/=10;
    }
    return m;
}
int main(){
    int n,count=0;
    scanf("%d",&n);
    if (n<10)
    {
        printf("%d\n",n);
        if (n==1)
        {
            printf("������ĩβ������1�����ݸ���Ϊ:1");
        }else{
            printf("������ĩβ������1�����ݸ���Ϊ:0");
        }
        return 0;
    }
    for (int i = n; i >=10 ; i--)
    {
        n = i;
        printf("%d->",n);
        while (n>=10)
        {
            n=calculate(n);
            if (n<10)
            {
                if (n==1)
                {
                    count ++;
                }
                printf("%d",n);
            }else{
                printf("%d->",n);
            }
        }
        printf("\n");
    }
    printf("������ĩβ������1�����ݸ���Ϊ:%d",count);
    return 0;
}