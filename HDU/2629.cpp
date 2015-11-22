#include<stdio.h>
int main(){
	int T;
	scanf("%d%*c",&T);
	while(T--){
		char s[50];
		scanf("%s",s);
		printf("He/She is from ");
		if(s[0]=='1') printf("Beijing,");
		else if(s[0]=='2') printf("Liaoning,");
		else if(s[0]=='3'){
			if(s[1]=='3') printf("Zhejiang,");
			else printf("Shanghai,");
		}
		else if(s[0]=='7') printf("Taiwan,");
		else if(s[0]=='8') 
		{
		if(s[1]=='1')
		printf("Hong Kong,");
		else printf("Macao,");
	    }
	    else if(s[0]=='5') printf("Tibet,");
	    printf("and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",s[10],s[11],s[12],s[13],s[6],s[7],s[8],s[9]);
	}
}
