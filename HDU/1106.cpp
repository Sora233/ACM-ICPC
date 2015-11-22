#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
		char s[1050];
		while(cin>>s){
			int a[1050]={0},count=0,num=-1,len=strlen(s);
			for(int i=0;i<len;++i){
				if(s[i]!='5'){
				if(num==-1) num=s[i]-'0';
				else num=num*10+s[i]-'0';
			    }
				else if(num!=-1){
					a[count++]=num;
					num=-1;
				}
			}
			if(num!=-1) a[count++]=num;
			sort(a,a+count);
			for(int i=0;i<count;++i)
			if(!i) cout<<a[i];
			else cout<<' '<<a[i];
			cout<<endl;
		}
} 
