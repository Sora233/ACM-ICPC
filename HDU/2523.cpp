#include<iostream>
using namespace std;
int abs(int x){
	return x>0?x:-x;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		int a[1005],b[2005]={0};
		for(int i=0;i<n;i++)
		cin>>a[i];
		for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
		b[abs(a[i]-a[j])]=1;
		for(int i=0,count=0;;++i){
			if(b[i]) ++count;
		    if(count==k&&b[i]) {
			cout<<i<<endl;
			break;
		}
		}
	}
}
