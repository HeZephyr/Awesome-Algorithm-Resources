/**
  *@filename:G
  *@author: pursuit
  *@created: 2021-08-11 20:53
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m;
struct node{
    int id,s,d,c;//s为开始准备考试日期。d为考试日期，c为需要准备的考试天数。
    bool operator < (const node & A){
        return d < A.d;
    }
}item[N];
int ans[N];
bool vis[N];//考试不能占用。
void solve(){
    int cnt = 0;
    sort(item + 1,item + 1 + m);
    bool flag = true;
    for(int i = 1; i <= m; ++ i){
        int cnt = 0;
        for(int j = item[i].s; j < item[i].d && cnt < item[i].c; ++ j){
            if(!ans[j] && !vis[j]){
                ans[j] = item[i].id;
                cnt ++;
            }
        }
        if(cnt < item[i].c || ans[item[i].d]){
            flag = false;
            break;
        }
        else{
            ans[item[i].d] = m + 1;
        }
    }
    if(!flag){
        puts("-1");
    }
    else{
        for(int i = 1; i <= n; ++ i){
            printf("%d ", ans[i]);
        }
        puts("");
    }
}
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++ i){
        scanf("%d%d%d", &item[i].s, &item[i].d, &item[i].c);
        vis[item[i].d] = true;
        item[i].id = i;
    }
    solve();
    return 0;
}