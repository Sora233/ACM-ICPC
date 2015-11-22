#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
#include<ctime>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
const int MAXN=1<<15;
struct obj{
    string name;
    int deadline,cost;
}o[20];
int path[MAXN][20];
int dp[MAXN][2];//dp[i] ������Ϊi�� 0Ϊ��ʱ�� 1Ϊ�ͷ�
int main(){
    int T;
    cin>>T;
    while(T--){
        int num;
        memset(dp,(1<<6)-1,sizeof(dp));
        memset(path,0,sizeof(path));
        dp[0][0]=dp[0][1]=0;
        cin>>num;
        cin.ignore();
        for(int i=0;i<num;++i) {
                cin>>o[i].name>>o[i].deadline>>o[i].cost;
                cin.ignore();
        }

        for(int i=0;i<(1<<num);++i){ //��ǰ��ҵ���Ϊi ״ѹ��������� ������֪�����i�ľ���˳��
            for(int j=0;j<num;++j){ //���ǵ�j����ҵ
                if(i&(1<<j)) continue; //��j�����
                int fa=o[j].cost+dp[i][0]; //���jʱ������
                if(fa>o[j].deadline) fa-=o[j].deadline; //�������� ����۷�
                else fa=0;//û�������۷�

                if(dp[i][1]+fa<dp[i|(1<<j)][1]){
                    for(int k=1;k<=path[i][0];++k) path[i|(1<<j)][k]=path[i][k]; //״̬ת�Ƶ�ʱ��˳��ת��·��
                    path[i|(1<<j)][0]=path[i][0]+1; //�Ѿ���¼��·����+1
                    path[i|(1<<j)][path[i][0]+1]=j; //����һ���µ�·��
                    dp[i|(1<<j)][1]=dp[i][1]+fa;
                    dp[i|(1<<j)][0]=dp[i][0]+o[j].cost;
                }
            }
        }
        cout<<dp[(1<<num)-1][1]<<endl;
        for(int i=1;i<=num;++i){
            cout<<o[path[(1<<num)-1][i]].name<<endl;
        }
    }
}
