#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 4e5 + 100;
const int lim = 256;
int n, m, a[N];
int f[lim];
int local[lim];//表示值为i的元素最后一次出现的位置。
bool cmp(int i, int j){
    return local[i] > local[j];
}
void work(){
    memset(f, 1, sizeof(f));
    vector<int> v;
    for(int i = 0; i < lim; ++ i){
        if(local[i]){
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(auto x : v){
        bool flag = false;
        for(int i = 0; i < 8; ++ i){
            if(!f[x ^ (1 << i)]){
                flag = true;
            }
        }
        if(flag)f[x] = 1;
        else f[x] = 0;
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        local[a[i]] = i;
    }
    work();
    for(int i = 1, op, x; i <= m; ++ i){
        scanf("%d%d", &op, &x);
        if(op == 1){
            a[++ n] = x;
            local[x] = n;
            work();
        }
        else{
            if(local[a[x]] == x){
                if(f[a[x]]){
                    puts("Grammy");
                }
                else{
                    puts("Alice");
                }
            }
            else{
                puts("Grammy");
            }
        }
    }
    return 0;
}

