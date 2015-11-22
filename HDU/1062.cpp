#include<iostream>
#include<cstring>
using namespace std;
void Strrev(char *a,char *b){
	int len=b-a;
	char temp;
	for(int i=0,j=len-1;i<len/2;i++,j--)
	temp=*(a+i),*(a+i)=*(a+j),*(a+j)=temp;
}
int main(){
	char st[1005];
	int T;
	cin>>T;
	cin.ignore();
	while(T--){
		cin.getline(st,1005);
		int i=0,j=0;
		while(st[j]!='\0'){
			while(st[j]!=' '&&st[++j]!='\0');
			Strrev(&st[i],&st[j]);
			i=j+1;
			j++;
		}
		cout<<st<<endl;
	}
}
