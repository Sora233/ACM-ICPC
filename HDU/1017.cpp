#include<iostream>
using namespace std;
int main(){
	int k;
	cin>>k;
	while(k--){
	int n,m,ca=1;
	while(cin>>n>>m){
		if(!n&&!m) break;
		int count=0;
	    for(int i=2;i<n;i++)
	    for(int j=1;j<i;j++)
	    if((i*i+j*j+m)%(i*j)==0) count++;
	    cout<<"Case "<<ca++<<": "<<count<<endl;
	}
	if(k) cout<<endl;
    }
}
