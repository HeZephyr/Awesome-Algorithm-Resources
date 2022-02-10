#include<bits/stdc++.h>

using namespace std;

int n;
string s;
int main(){
    cin >> n >> s;
    int idx = 0,cnt = 1;
    while(idx < n){
        cout << s[idx];
        idx += cnt;
        cnt ++;
    }
    cout << endl;
    return 0;
}