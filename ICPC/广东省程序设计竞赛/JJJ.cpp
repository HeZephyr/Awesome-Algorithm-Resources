#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int cnt[N];
vector<int> v;
struct node{
    int x, step;
};
void init(){
    queue<node> q;
    for(int i = 1; i * i < N; ++ i){
        q.push({i * i, 1});
        cnt[i * i] = 1;
        v.push_back(i * i);
    }
    while(!q.empty()){
        node head = q.front();
        int x = head.x, step = head.step;
        q.pop();
        if(step > 3)break;
        for(auto y : v){
            for(int i = 0; i < 2; ++ i){
                int xx = x;
                if(i == 0)xx += y;
                else xx -= y;
                if(xx > 0 && xx < N && !cnt[xx]){
                    q.push({xx, cnt[step] + 1});
                    cnt[xx] = cnt[step] + 1;
                }
            }
        }
    }
    /* for(int i = 0; i < 1e5; ++ i){
        cout << cnt[i] << " ";
    } */
}
int main(){
    ll q, n, x;
   /*  freopen("test.txt", "w", stdout); */
    init();
    scanf("%lld", &q);
    while(q--){
        cin >> x;
        cout << cnt[x] << endl;
    }
    return 0;
}