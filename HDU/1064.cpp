#include<iostream>
#include<iomanip>
using namespace std;
int main(){
double a,b=0;
for(int i=1;i<=12;++i)
{
cin>>a;
b+=a;
}
cout<<'$'<<setiosflags(ios::fixed)<<setprecision(2)<<b/12<<endl;
}
