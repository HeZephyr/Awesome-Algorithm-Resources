#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

//自然是想着将同意义的单词分组，然后排序取最低费用即可。
int n,k,m;
map<string,int> p;
int cost[N],idx[N];//idx[i]表示第i个单词所在的组序号。
string s;
vector<int> group[N];
//重写比较方法，根据花费来排序。
bool cmp(int i,int j){
    return cost[i] < cost[j];
}
void solve(){
    for(int i = 1; i <= k; ++ i){
        sort(group[i].begin(),group[i].end(),cmp);
    }
    for(int i = 1; i <= k; ++ i){
        /*
        cout << i << " group" << endl;
        for(auto &x:group[i]){
            cout << x << " " << cost[x] << endl;
        }
        */
    }
    long long ans = 0;
    while(m -- ){
        cin >> s;
        //获取序号。
        int pos = p[s];
        //根据组号选择最小值。
        //cout << s << " " << idx[pos] << endl;
        ans += cost[group[idx[pos]][0]];
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin >> n >> k >> m;
    for(int i = 1; i <= n; ++ i){
        cin >> s;
        p[s] = i;//记录其所在下标。
    }
    for(int i = 1; i <= n; ++ i){
        cin >> cost[i];
    }
    int cnt,x;
    for(int i = 1; i <= k; ++ i){
        cin >> cnt;
        while(cnt --){
            cin >> x;
            group[i].push_back(x);
            //记录x所在的组。
            idx[x] = i;
        }
    }
    solve();
    return 0;
}