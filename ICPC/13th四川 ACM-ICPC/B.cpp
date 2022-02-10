#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, k, x, p[N], t[N];
int s[N];
int res[N];
int main(){
    scanf("%d%d%d", &n, &k, &x, &p[0]);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &s[i]);
    }
    int maxt = p[0] - 0;
    for(int i = 1; i <= k; ++ i){
        scanf("%d", &t[i]);
    }
    for(int i = 1; i <= k; ++ i){
        scanf("%d", &p[i]);
        maxt = max(maxt, p[i] - t[i]);
    }
    int sum = 0;
    for(int i = 1; i <= n; ++i){
        if(x / s[i] <= maxt)sum++;
    }
    cout<<sum<<endl;
    return 0;
}