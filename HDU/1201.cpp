#include<iostream>
using namespace std;
struct date{
	int year,month,day;
};
istream& operator >>(istream &in,date &p){
	in>>p.year;
	cin.ignore();
	in>>p.month;
	cin.ignore();
	in>>p.day;
	return in;
}
bool run(int year){
	if((year%4==0&&year%100!=0)||year%400==0) return 1;
	return 0;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		date a;
		cin>>a;
		if(a.day==29&&a.month==2){
			cout<<"-1"<<endl;
			continue;
		}
		int count=0,sum=0;
		while(count!=18){
			if(run(a.year)) sum+=366;
			else sum+=365;
			++a.year;
			++count;
		}
		cout<<sum<<endl;
	}
}
