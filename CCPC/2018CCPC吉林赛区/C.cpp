#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5+7;

int ans[N], a[N], b[N];
vector<int> v[N];
int main(){
    int t, n, x;
    scanf("%d", &t);
    for(int c = 1;c <= t;c++){
        map<int, int> mp;
        scanf("%d", &n);
        for(int i = 1;i <= n;i++){
            ans[i] = 0;
            scanf("%d", &x);
            if(x<=1e5){
                mp[x]++;
                v[x].push_back(i);
            }
        }
        auto it = mp.end();
        it--;
        int pos = 0, Max = -1, tem = 0, p = 0;
        while(1){
            int x = it->first, y = it->second;
            //printf("x = %d %d\n", x, y);
            Max = max(Max, x);
            a[x] += y/2;
            b[x] += y/2;
            int fla = 0;
            if((y/2)&1){
                a[x]--;
                b[x]++;
                pos = x;
                fla = 1;
            }
            else if(y&1){
                b[x]++;
                pos = x;
            }
            for(int i = 0;i < v[x].size()/2-fla;i++){
                ans[v[x][i]] = 1; 
            }
            if(it==mp.begin()) break;
            it--;
        }
        //printf("pos = %d, Max = %d\n", pos, Max);
        a[pos]++;
        if(v[pos].size()) ans[v[pos][v[pos].size()-1]] = 1;
        b[pos]--;
        for(int i = Max;i >= 2;i--){
            a[i-1] += a[i]/2;
            b[i-1] += b[i]/2;
        }
        printf("Case %d: ", c);
        if(a[1] && b[1]){
            printf("YES\n");
            for(int i = 1;i <= n;i++){
                printf("%d",ans[i]);
            }
            printf("\n");
        } else {
            printf("NO\n");
        }
        for(int i = 0;i <= Max;i++){
            v[i].clear();
            a[i] = b[i] = 0;
        }
    }
    return 0;
}