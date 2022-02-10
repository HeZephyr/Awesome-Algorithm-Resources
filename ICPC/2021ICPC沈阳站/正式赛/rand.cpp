#include<bits/stdc++.h>
using namespace std;
int p = 10000;
map<pair<int , int>, int> map1;
int main(){
    srand((unsigned)time(NULL));
    freopen("J.txt", "w", stdout);
    int T = 1000;
    cout << T << endl;
    while(T--){
        int x = rand() % p;
        int y = rand() % p;
        while(map1[{x, y}]){
            int x = rand() % p;
            int y = rand() % p;
        }
        map1[{x, y}] = 1;
        printf("%d %d\n", x, y);
    }
}