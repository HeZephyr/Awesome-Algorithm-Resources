#include<bits/stdc++.h>

using namespace std;

int n, k;
int main(){
    cin >> n >> k;
    if(k > n){
        cout << 2 << endl; 
    }
    else{
        cout << (2 * n + k - 1) / k << endl;
    }
    return 0;
}