#include<bits/stdc++.h>

using namespace std;

int b, g, n;
int main(){
    cin >> b >> g >> n;
    int res = 0;
    for(int i = 0, j; i <= b; ++ i){
        j = n - i;
        if(j >= 0 && j <= g){
            ++ res;
        }
    }
    cout << res << endl;
    return 0;
}