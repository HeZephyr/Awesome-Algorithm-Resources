#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6 + 7;
char s[N];
int b[N];
int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d%s", &n, s+1);
        int cnt = 0, Max = -1;
        vector<int> v;
        for(int i = 1;i <= n;i++){
            if(s[i]=='0'){
                cnt++;
            } else {
                if(cnt){
                    v.push_back(cnt);
                    Max = max(Max, cnt);
                    cnt = 0;
                }
            }
        }
        if(cnt) v.push_back(cnt);
        if(v.empty()){
            printf("0\n");
            continue;
        }
        Max = max(Max, cnt);
        if(v.size()==2){
            //printf("%d %d\n", v[0], v[1]);
            printf("%d\n", max(max(v[0], v[1]), min(v[0], v[1])+1));
            continue;
        }
        bool fla = 0;
        for(int i = 0;i < v.size()-1;i++){
            if(v[i]==Max && v[i+1]==Max){
                fla = 1;
                break;
            }
        }
        int ans = -1;
        if(v.size()>2 && s[1]=='0' && v[1]==Max){
            ans = max(v[0], (v[1]-1+1)/2+1);
            ans = min(ans, max(v[0]+1, (v[1]-2+1)/2 + 1));
        }
        if(v.size()>2 && s[n]=='0' && v[v.size()-2]==Max){
            int m = v.size()-1;
            ans = max(ans, max(v[m], (v[m-1]-1+1)/2+1));
            ans = min(ans, max(v[m]+1, (v[m-1]-2+1)/2 + 1));
        }
        //printf("ans = %d\n", ans);
        if(fla) printf("%d\n", max(ans, (Max-1+1)/2 + 1));
        else printf("%d\n", max(ans, (Max-2+1)/2 + 1));
    }
    return 0;
}