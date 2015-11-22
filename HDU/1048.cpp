#include<iostream>
#include<string>
#define IGN cin.ignore(1000,'\n')
using namespace std;
char ok(char s){
	if(s>='A'&&s<='Z') return (s-5)>='A'?(s-5):(s-5)+26;
	return s;
}
int main(){
	int T=0;
	string til;
	while(getline(cin,til)&&til=="START"&&++T<=100){
		string s;
		getline(cin,s);
		for(int i=0;i<s.length();i++)
		printf("%c",ok(s[i]));
		cout<<endl;
		IGN;
	}
}
