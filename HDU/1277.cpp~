#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
char ess[1000005];
int ecnt;
char ip[10005];
int n, m, kcnt;
vector< pair<int, int> >ans;
int main(){
    while( scanf("%d %d%*c", &n, &m) != EOF ){
        ecnt = 0, kcnt = 0;
        ans.clear();
        for(int i = 0; i < n; ++i){
            scanf("%s", ip);
            for(int j = 0; ip[j]; ++j) ess[ecnt++] = ip[j];
        }
        getchar();
        int flag = 0;
        for(int i = 0; i < m; ++i){
            scanf("%*s%*s%*s%s", ip);
            char *pos = strstr(ess, ip);
            if(pos != NULL) {
                ans.push_back( make_pair(pos - ess, i+1) );
                flag = 1;
            }
        }
        sort(ans.begin(), ans.end());
        if( !flag ) puts("No key can be found !");
        else {
            puts("Found key:");
            for(int i = 0; i < ans.size(); ++i) printf("  [Key No. %d]", ans[i].second);
            puts("");
        }
    }
}
