#include<stdio.h>
#include<math.h>
int queen[305]={0},flag=0;
int mark[305][305]={0};
void Mark(int n){
	for(int i=1;i<=n;i++)
	printf("%d ",queen[i]);
	printf("\n");
}
void Queen(int i,int n){  //第i个皇后 n*n棋盘 
        if(i>n){
        Mark(n);
        flag=1;
    }
    if(flag) return;
		for(int j=1;j<=n;j++){ 
			queen[i]=j;  //放置第i个皇后   
			int k=1; //从1开始遍历
			while(mark[n][k]){
				k++;
			}
			while(k<i){  //遍历扫在这个位置第i个皇后是否满足 即对之前的i-1个皇后分别检查 
				if(abs(queen[i]-queen[k])!=0&&(abs(queen[i]-queen[k])-abs(i-k))!=0){  //满足的条件  不在同一行  同一列 同一斜线 数学的多项式为0 
					k++; //满足一次 
					if(k==i)
						Queen(i+1,n);
					else;
				}
				else{
					mark[n][k]=1;
				break;
			}
		}
}
}
int main(){  //queen[i]=m  第i行第m个位置 从左到右 
	int n;
	while(scanf("%d",&n)!=EOF){
		flag=0;
		if(!n) break; 
	for(int i=1;i<=n;i++){  //第1个皇后从1到j个位置遍历 
		queen[1]=i;
		Queen(2,n);
	} 
	}
}
