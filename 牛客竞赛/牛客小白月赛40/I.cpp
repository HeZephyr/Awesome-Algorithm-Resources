#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 10;

int t, n;
int a[33], b[33];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        b[i] = i;
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    do{
        bool flag = false;
        for(int i = 1; i <= n; ++ i){
            //i要排在ai前面。
            if(i == a[i])continue;
            int idx1 = 0, idx2 = 0;
            for(int j = 1; j <= n; ++ j){
                if(b[j] == i){
                    idx1 = j;
                    break;
                }
                if(b[j] == a[i]){
                    idx2 = j;
                    if(!idx1){
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)break;
        }
        if(!flag)++ cnt;
    }while(next_permutation(b + 1, b + n + 1));
    printf("%d\n", cnt);
    return 0;
}