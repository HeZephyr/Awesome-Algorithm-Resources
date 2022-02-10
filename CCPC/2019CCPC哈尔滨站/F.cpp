#include<bits/stdc++.h>

using namespace std;

int t, n;
string s[6];
int cnt[6][6];
unordered_map<int, int> p;
int main(){
    cin >> t;
    p['h'] = 0, p['a'] = 1, p['r'] = 2, p['b'] = 3, p['i'] = 4, p['n'] = 5;
    while(t -- ){
        int a[] = {0, 1, 2, 3, 4, 5};
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < 6; ++ i){
            cin >> s[i];
            for(int j = 0; j < s[i].size(); ++ j){
                if(p.count(s[i][j])){
                    cnt[i][p[s[i][j]]] = 1;
                }
            }
        }
        //puts("1");
        bool flag = false;
        do{
            bool flag1 = false;
            for(int i = 0; i < 6; ++ i){
                if(!cnt[i][a[i]]){
                    flag1 = true;
                    break;
                }
            }
            if(!flag1){
                flag = true;
                break;
            }
        }while(next_permutation(a, a + 6));
        if(flag)puts("Yes");
        else puts("No");
    }
    return 0;
}