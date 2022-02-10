#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, a[N];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        if(a[i] > 18){
            puts("18");
        }
        else{
            printf("%d\n", a[i]);
        }
    }
    return 0;
}