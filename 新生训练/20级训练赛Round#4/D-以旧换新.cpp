#include<bits/stdc++.h>

using namespace std;

string a,b;//利用字符串存储更方便。
int cnt[10];
bool ok;//判断是否找到最优解。
void dfs(long long ans = 0,int len = 0,bool flag = false){
    //flag代表当前路径构造的ans是否已经知晓其小于0了。
    //经过我们的过滤，实际上我们已经得到了对应的结果。
    if(len == a.size()){
        ok = true;
        cout << ans << endl;
        return;
    }
    for(int i = 9; i >= 0; -- i){
        if(ok)return;
        if(cnt[i]){
            if(flag){
                //填充最大的。
                cnt[i] --;
                dfs(ans * 10 + i,len + 1,flag);
                cnt[i] ++;
                break;
            }
            else{
                if(i == b[len] - '0'){
                    cnt[i] --;
                    dfs(ans * 10 + i,len + 1,flag);
                    cnt[i] ++;
                }
                else if(i < b[len] - '0'){
                    cnt[i] --;
                    dfs(ans * 10 + i,len + 1,true);
                    cnt[i] ++;
                }
            }
        }
    }
}
void solve(){
    if(a.size() < b.size()){
        //说明a不依赖于b，我们输出所能构建的最大a。
        sort(a.begin(),a.end(),greater<char>() );
        cout << a << endl;
    }
    else if(a == b){
        cout << a << endl;
    }
    else{
        for(auto &x : a){
            cnt[x - '0'] ++;
        }
        dfs();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin >> a >> b;
    solve();
    return 0;
}