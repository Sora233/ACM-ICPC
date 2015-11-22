#include<iostream>
#include<cctype>
#include<iomanip>
using namespace std;
int main(){
	char c,s;
	while(cin>>c){
		int count=0,num=0;
		while(cin.get(s)&&s!='\n') {
			if(s==' ') continue;
		if(tolower(s)==tolower(c)) count++;
		num++;
	    }
		cout<<setiosflags(ios::fixed)<<setprecision(5)<<count*1.0/num<<endl;
	}
}
