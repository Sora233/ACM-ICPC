#include<stdio.h>
#include<math.h>
int main()
{
    int t,a,i,k;
    double sum=0;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&a);
        for(k=1;k<=a;k++)
            sum=sum+log(k)/log(10);
        printf("%d\n",(int)(sum+1));
        sum=0;
    }
    return 0;
}
