#include<bits/stdc++.h>

using namespace std;

int n,m;
int main(){
    cin >> n >> m;
    if((n * m - 1) & 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}