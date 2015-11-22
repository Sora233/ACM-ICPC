#include<iostream>
#include<cstring>
using namespace std;
void Strrev(char *a){
	int len=strlen(a);
	char temp;
	for(int i=0,j=len-1;i<len/2;i++,j--)
	temp=a[i],a[i]=a[j],a[j]=temp;
}
int main(){
	int T;
	cin>>T;
	cin.ignore();
	while(T--){
		char s[100];
		cin.getline(s,100);
		Strrev(s);
		cout<<s<<endl;
	}
}
