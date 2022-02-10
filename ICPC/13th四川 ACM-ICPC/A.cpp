#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n, k;
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; ++ i){
        for(int j = i; j <= n; j += k){
            cout << j << " ";
        }
    }
    cout << endl;
    return 0;
}