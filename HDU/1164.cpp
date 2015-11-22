#include<iostream>
using namespace std;
int prime[10000]={2,3,5},count=3;
bool isprime(int x){
	for(int i=0;prime[i]*prime[i]<=x;++i)
	if(x%prime[i]==0) return 0;
	return 1;
}
int main(){
	for(int i=7;i<=65535;i+=6){
	if(isprime(i)) prime[count++]=i;
	if(isprime(i+4)) prime[count++]=i+4;
    }
    int num;
    while(cin>>num){
    	int a[1000]={0},c=0;
    	for(int i=0;prime[i]<=num;++i){
    		while(num%prime[i]==0){
    			a[c++]=prime[i];
    			num/=prime[i];
    		}
    	}
    	for(int i=0;i<c;++i)
    	if(!i) cout<<a[i];
    	else cout<<'*'<<a[i];
    	cout<<endl;
    }
}
