#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

string a, b;
int main(){
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    bool flag = false;
    int idx1 = 0, idx2 = 0;
    while(idx1 < a.size() || idx2 < b.size()){
        int temp1 = (idx1 < a.size()) ? a[idx1 ++] - '0' : 0;
        int temp2 = (idx2 < b.size()) ? b[idx2 ++] - '0' : 0;
        if(temp1 + temp2 >= 10){
            flag = true;
            break;
        }
    }
    if(flag)puts("Hard");
    else puts("Easy");
    return 0;
}