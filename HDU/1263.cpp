#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
struct fr{
	char name[90];
	char place[90];
	int num;
};
fr fruit[105];
int count,N,T;
bool cmp(fr a,fr b){
	int lena,lenb,len,flag;
	lena=strlen(a.place);
	lenb=strlen(b.place);
	len=lena>lenb?lena:lenb;
	for(flag=0;flag<len;flag++)
	if(a.place[flag]!=b.place[flag]) return b.place[flag]>a.place[flag];
	lena=strlen(a.name);
	lenb=strlen(b.name);
	len=lena>lenb?lena:lenb;
	for(flag=0;flag<len;flag++)
	if(a.name[flag]!=b.name[flag]) return b.name[flag]>a.name[flag];
}
void quicksort(int l,int r){
	if(l<r){
		int i=l,j=r;
		fr x=fruit[l];
		while(i<j){
			while(i<j&&cmp(x,fruit[j])) j--;
			if(i<j) fruit[i++]=fruit[j];
			while(i<j&&!cmp(x,fruit[i])) i++;
			if(i<j) fruit[j--]=fruit[i];
		}
		fruit[j]=x;
		quicksort(l,j-1);
		quicksort(i+1,r);
	}
}
int main(){
	//freopen("1263.in","r",stdin);
	scanf("%d%*c",&T);
	while(T--){
		count=0;
		memset(fruit,0,sizeof(fruit));
		scanf("%d%*c",&N);
		for(int deal=0;deal<N;deal++){
		char name[90]={0},place[90]={0};
		int num,flag,len_n;
		scanf("%s%s%d%*c",name,place,&num);
		len_n=strlen(name);
		if(!count){
			strcpy(fruit[count].name,name);
			strcpy(fruit[count].place,place);
			fruit[count++].num+=num;
		}
		else{
		for(int i=0;i<count;i++){
			int lenfru=strlen(fruit[i].name);
			if(lenfru==len_n&&strncmp(fruit[i].name,name,lenfru>len_n?lenfru:len_n)==0&&!strcmp(fruit[i].place,place)){
				fruit[i].num+=num;
				break;
			}
			else if(i==count-1){
				strcpy(fruit[count].name,name);
			    strcpy(fruit[count].place,place);
			    fruit[count++].num=num;
			    break;
			}
		}
	    }
	    }
	    quicksort(0,count-1);
	    char temp[90];
	    strcpy(temp,fruit[0].place);
	    puts(temp);
	    int i=0;
	    while(i<count){
	    	if(strcmp(temp,fruit[i].place)==0){
	        printf("   |----%s(%d)\n",fruit[i].name,fruit[i].num);
	        i++;
	        }
	        else{
	        	strcpy(temp,fruit[i].place);
	        	puts(temp);
	        	printf("   |----%s(%d)\n",fruit[i].name,fruit[i].num);
	        	i++;
	        }
	    }
	    if(T) printf("\n");
	}
}
