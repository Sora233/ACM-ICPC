#include<stdio.h>
#include<math.h>
int queen[305]={0},flag=0;
int mark[305][305]={0};
void Mark(int n){
	for(int i=1;i<=n;i++)
	printf("%d ",queen[i]);
	printf("\n");
}
void Queen(int i,int n){  //��i���ʺ� n*n���� 
        if(i>n){
        Mark(n);
        flag=1;
    }
    if(flag) return;
		for(int j=1;j<=n;j++){ 
			queen[i]=j;  //���õ�i���ʺ�   
			int k=1; //��1��ʼ����
			while(mark[n][k]){
				k++;
			}
			while(k<i){  //����ɨ�����λ�õ�i���ʺ��Ƿ����� ����֮ǰ��i-1���ʺ�ֱ��� 
				if(abs(queen[i]-queen[k])!=0&&(abs(queen[i]-queen[k])-abs(i-k))!=0){  //���������  ����ͬһ��  ͬһ�� ͬһб�� ��ѧ�Ķ���ʽΪ0 
					k++; //����һ�� 
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
int main(){  //queen[i]=m  ��i�е�m��λ�� ������ 
	int n;
	while(scanf("%d",&n)!=EOF){
		flag=0;
		if(!n) break; 
	for(int i=1;i<=n;i++){  //��1���ʺ��1��j��λ�ñ��� 
		queen[1]=i;
		Queen(2,n);
	} 
	}
}
