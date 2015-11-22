#include<iostream>
using namespace std;
int quickpow(int n,int t,int mod){
	int ans=1,co=n;
	while(t){
		if(t&1) ans=(ans*co)%mod;
		co=(co*co)%mod;
		t>>=1;
	}
	return ans;
}
int main(){
	int mod;
	while(cin>>mod){
		if(!(mod%2)||mod==1){
			cout<<"2^? mod "<<mod<<" = 1"<<endl;
			continue;
		}
		for(int i=1;;i++)
		if(quickpow(2,i,mod)==1){
			cout<<"2^"<<i<<" mod "<<mod<<" = 1"<<endl;
			break;
		}
	}
}
