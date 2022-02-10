/**
  *@filename:C_Searching_Local_Minimum
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-02 08:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,l,r;
int get(int idx){
    cout << "? " << idx << endl;
    fflush(stdout);
    int res;
    cin >> res;
    return res;
}
void solve(){
    l = 1,r = n;
    while(l < r){
        int mid = l + r >> 1;
        int temp1 = get(mid + 1),temp2 = get(mid);
        if(temp2 < temp1){
            //说明左边小于右边。那么答案就在左边。
            r = mid;
        } 
        else{
            l = mid + 1;
        }
    }
    cout << "! " << l << endl;
    fflush(stdout);
}
int main(){
    cin >> n;
    solve();
    return 0;
}