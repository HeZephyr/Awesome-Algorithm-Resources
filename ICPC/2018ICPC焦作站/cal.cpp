#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 10;

bool notprimer[N];
void init(){
    for(int i = 2; i < N; ++ i){
        if(!notprimer[i]){
            printf("%d, ", i);
            for(int j = i * 2; j < N; j += i){
                notprimer[j] = true;
            }
        }
    }
}
int main(){
    freopen("data.txt", "w", stdout);
    init();
    return 0;
}