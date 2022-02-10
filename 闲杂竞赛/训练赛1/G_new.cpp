/**
  *@filename:G
  *@author: pursuit
  *@created: 2021-08-08 20:14
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int a[N];
map<int, int> p;
int main(){
    int n;
    cin >> n;
    int maxx = 0, last;
    for(int i = 1;i <= n; i++){
        int temp;
        cin >> temp;
        a[i] = temp;
        p[temp] = p[temp - 1] + 1;
        if(p[temp] > maxx){
            maxx = p[temp];
            last = temp;
        }
    }
    vector<int> ans;
    for(int i = n; i >= 1; -- i){
        if(a[i] == last){
            ans.push_back(i);
            last--;
        }
    }
    cout << maxx << endl;
    for(int i = ans.size() - 1; i >= 0; -- i){
        cout << ans[i] << ' ';
    }
}