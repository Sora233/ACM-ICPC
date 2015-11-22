#include<iostream>
#include<string>
using namespace std;
int main(){
	int z,o,j,flag;
	string s;
	while(cin>>s){
		z=o=j=flag=0;
		if(s[0]=='E') break;
		for(int i=0;i<s.length();++i)
		if(s[i]=='Z') ++z;
		else if(s[i]=='O') ++o;
		else ++j;
		while(!flag){
			if(z){
				cout<<'Z';
				--z;
			}
			if(o){
				cout<<'O';
				--o;
			}
			if(j){
				cout<<'J';
				--j;
			}
			if(!z&&!o&&!j) flag=1;
		}
		cout<<endl;
	}
}
