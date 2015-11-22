#include<stdio.h>
#include<stack>
using namespace std;
int main(){
	int n;
	char in[205],out[205];
	while(scanf("%d%s%s",&n,in,out)!=EOF){
		stack<char>q;
		int k=0,times[205]={0},j=0;
		for(int i=0;i<n;i++){
			q.push(in[i]);
			times[k++]=1;
			while(out[j]!='\0'&&q.size()&&q.top()==out[j]){
				q.pop();
				times[k++]=2;
				j++;
			}
		}
		if(q.empty()){
			printf("Yes.\n");
			for(int i=0;;i++)
			if(times[i]==1) printf("in\n");
			else if(times[i]==2) printf("out\n");
			else if(times[i]==0){
				printf("FINISH\n");
				break;
			}
		}
		else printf("No.\nFINISH\n");
	}
}
