/**
  *@filename:License_Plate_Recognition
  *@author: pursuit
  *@created: 2021-08-05 10:20
**/
#include <bits/stdc++.h>
#define debug(a) cout << (#a)<< ":" << a << endl;
#define l first
#define r second
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 33 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t;
char s[35][110];
bool vis[110];//判断该列有没有出现字符。
pii pos[N];
void solve(){
    for(int j = 1; j <= 100; ++ j){
        for(int i = 1; i <= 30; ++ i){
            if(s[i][j] == '#'){
                vis[j] = true;
                break;
            }
        }
    }
    int l, r = -1;
    int cnt = 7;
    for(int j = 99; j >= 0; -- j){
        if(vis[j]){
            if(r == -1){
                r = j;
            }
            if(cnt == 1){
                //此时记录了r的位置。
                break;
            }
            l = j;
        }
        else{
            if(r != -1){
                pos[cnt].l = l,pos[cnt].r = r;
                cnt --;
                r = -1;
            }
        }
    }
    for(int j = 0; j < 100; ++ j){
        if(vis[j]){
            l = j;
            pos[cnt].l = l,pos[cnt].r = r;
            break;
        }
    }
    for(int i = 1; i <= 7; ++ i){
        printf("%d %d\n", pos[i].l + 1, pos[i].r + 1);
    }
    memset(vis,false,sizeof(vis));
}
int main(){	
    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++ Case){
        for(int i = 0; i < 30; ++ i){
            scanf("%s", &s[i]);
        }
        printf("Case #%d:\n",Case);
        solve();
    }
    return 0;
}