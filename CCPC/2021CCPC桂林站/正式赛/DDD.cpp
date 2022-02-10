#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 1e6 + 7;
const int N = 2033;
int a[N], b[N];
int ida[N], idb[N];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        vector<pair<int , int >>ans;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            ida[a[i]] = i;
        }
        for(int i = 1; i <= n; ++i){
            scanf("%d", &b[i]);
            idb[b[i]] = i;
        }
        for(int i = 1; i < n; ++i){
            if(idb[i] < ida[i + 1]){
                swap(ida[i], ida[i + 1]);
                swap(a[ida[i]], a[ida[i + 1]]);
            }
            swap(ida[i], ida[b[idb[i]]]);
            swap(a[ida[i]], a[ida[b[idb[i]]]]);
            ans.push_back(make_pair(ida[i], ida[b[idb[i]]]));
        }
        int flag = 1;
        for(int i = 1; i <= n; ++i){
            if(a[i] != b[i])flag = 0;
        }
        if(!flag)printf("-1\n");
        else {
            for(int i = 0; i < ans.size(); ++i){
                printf("%d %d\n", ans[i].first, ans[i].second);
            }
        }
    }
}