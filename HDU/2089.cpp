#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
bool a[1000005]={0};
int main(){
	char num[20];
	for(int i=1;i<=1000000;i++){
		itoa(i,num,10);
		if(strstr(num,"62")==NULL&&strstr(num,"4")==NULL) a[i]=1;
	}
	int m,n;
	while(cin>>m>>n&&(m||n)){
		int ans=0;
		for(int i=m;i<=n;i++)
		ans+=a[i];
		cout<<ans<<endl;
	}
}
