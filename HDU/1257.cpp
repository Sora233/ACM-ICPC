#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int ans=0,h,t=0xfffffff,c=1;
		while(n--){
			cin>>h;
			if(h>t) ++c;
			t=h; 
		}
		cout<<c<<endl;
	}
}
