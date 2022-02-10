#include<bits/stdc++.h>

using namespace std;

int t, n, a, b;
bool vis[1010];
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> a >> b;
        if(a == b || n - a + 1 < n / 2 || b < n / 2){
            puts("-1");
        }
        else{
            vector<int> x, y;
            memset(vis, 0, sizeof(vis));
            x.push_back(a), y.push_back(b);
            vis[a] = true, vis[b] = true;
            int cnt = n / 2 - 1;
            for(int i = 1; i < b && cnt; ++ i){
                if(!vis[i])y.push_back(i), vis[i] = true, -- cnt;
            }
            cnt = n / 2 - 1;
            for(int i = n; i > a && cnt; -- i){
                if(!vis[i])x.push_back(i), vis[i] = true, -- cnt;
            }

            if(x.size() == n / 2 && y.size() == n / 2){
                for(auto a : x){
                    cout << a << " ";
                }
                for(auto b : y){
                    cout << b << " ";
                }
                cout << endl;
            }
            else{
                puts("-1");
            }
        }
    }
    return 0;
}