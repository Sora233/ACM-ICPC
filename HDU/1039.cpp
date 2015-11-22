#include<iostream>
#include<string>
using namespace std;
bool isvio(char s){
	if(s=='a'||s=='e'||s=='u'||s=='i'||s=='o') return 1;
	return 0;
}
bool is_2(char a,char b){
	if(a==b&&a!='e'&&a!='o') return 1;
	return 0;
}
bool is_vio(char a,char b,char c){
	if(isvio(a)&&isvio(b)&&isvio(c)) return 1;
	if(!isvio(a)&&!isvio(b)&&!isvio(c)) return 1;
	return 0;
}
int main(){
	string mm;
	while(cin>>mm){
		if(mm=="end") break;
		int flag_vio=0,flag=0,flag_2=1,flag_3=1;
		for(int i=0;i<mm.length();i++)
		{
			if(isvio(mm.at(i))) flag_vio=1;
			if(i>=1){
				if(is_2(mm.at(i),mm.at(i-1))) flag_2=0;
			}
			if(i>=2) {
			if(is_vio(mm.at(i),mm.at(i-1),mm.at(i-2))) flag_3=0;
		    }
		}
		if(flag_vio&&flag_3&&flag_2) flag=1;
		if(flag) cout<<'<'<<mm<<'>'<<" is acceptable."<<endl;
		else cout<<'<'<<mm<<'>'<<" is not acceptable."<<endl;
	}
}
