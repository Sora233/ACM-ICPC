#include<iostream>
using namespace std;
int a[100005];
int main(){
	int T;
	cin>>T;
	for(int ca=1;ca<=T;ca++){
		if(ca!=1) cout<<endl;
		int N,sum=0,max=-1005,start=0,end=0,temp=0;
		cin>>N;
		for(int i=0;i<N;i++){
		cin>>a[i];
		if(sum>=0) sum+=a[i];
		else sum=a[i],temp=i;
		if(sum>max) max=sum,start=temp,end=i;
	}
		cout<<"Case "<<ca<<':'<<'\n'<<max<<' '<<start+1<<' '<<end+1<<endl;
}
}
