/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-29 14:05
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 200 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,pos[N];
string s[N];
char ans[N];
bool cmp(int i,int j){
    //按长度排序。
    return s[i].size() > s[j].size();
}
bool check(int x){
    string s1,s2;
    if(x)s1 = s[pos[1]], s2 = s[pos[2]], ans[pos[1]] = 'P', ans[pos[2]] = 'S';
    else s1 = s[pos[2]], s2 = s[pos[1]], ans[pos[1]] = 'S', ans[pos[2]] = 'P';
    int len = n - 2;
    for(int i = 3; i <= 2 * n - 2; i += 2){
        //根据s1和s2判断接下来的是前缀还是后缀。
        int idx1 = pos[i],idx2 = pos[i + 1];
        //debug(n - len);
        if(s1.substr(0,len) == s[idx1] && s2.substr(n - len - 1) == s[idx2]){
            ans[idx1] = 'P', ans[idx2] = 'S';
        }
        else if(s1.substr(0,len) == s[idx2] && s2.substr(n - len - 1) == s[idx1]){
            ans[idx1] = 'S', ans[idx2] = 'P';
        }
        else{
            return false;
        }
        -- len;
    }
    return true;
}
void solve(){
    sort(pos + 1, pos + 2 * n - 1,cmp);
    //间隔的一个是前缀一个是后缀。假定第一个是前缀然后去判断即可。
    if(check(1) || check(0)){
        ans[2 * n - 1] = '\0';
        cout << (ans + 1) << endl;
    }
}
int main(){	
    cin >> n;
    for(int i = 1; i <= 2 * n - 2; ++ i){
        cin >> s[i];
        pos[i] = i;
    }
    solve();
    return 0;
}