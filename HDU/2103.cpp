#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m,flag=0,baby,count=0;
		long long int sum=0;
		cin>>m>>n;
		while(n--){
			cin>>baby;
			if(m--<1||flag) count++;
			if(m<1) flag=1;
			if(flag) sum+=10000*(long long int)pow(2.0,count*1.0-1);
			if(baby) flag=1;
		}
	    cout<<sum<<" RMB"<<endl;
	}
}
