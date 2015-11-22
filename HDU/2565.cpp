#include<cstdio>
int main(){
    int n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n/2+1;++i){
            for(int j=0;j<i;++j) putchar(' ');
            putchar('X');
            if(i==n/2) break;
            for(int j=n-2-2*i;j>0;--j) putchar(' ');
            putchar('X');
            puts("");
        }
        puts("");
        for(int i=n/2-1;i>=0;--i){
            for(int j=0;j<i;++j) putchar(' ');
            putchar('X');
            for(int j=n-2-2*i;j>0;--j) putchar(' ');
            putchar('X');
            puts("");
        }
        puts("");
    }
}
