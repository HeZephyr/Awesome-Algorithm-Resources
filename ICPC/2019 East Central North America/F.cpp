/**
  *@filename:F
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-23 10:03
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10000 + 5;
const int P = 1e9+7;

int n;
pair<int,int> a[N];
void solve(){
    int pos = 0;//当前所在的下下标。
    while(n > 1){
        int temp = a[pos].first;
        temp %= n;
        if(temp == 0)temp = n;
        pos = (pos + temp - 1) % n;
        //cout << pos << " " << a[pos].second << endl;
        for(int i = pos; i < n - 1; ++ i){
            a[i] = a[i + 1];
        }
        n --;
        pos %= n;
    }
    printf("%d\n", a[0].second);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i){
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
    }
    solve();
    return 0;
}
