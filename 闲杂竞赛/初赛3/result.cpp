/**
  *@filename:环上游走
  *@author: pursuit
  *@created: 2021-08-07 15:05
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
int a[] = {0,1,2,2,4,2,4,4,8,2,4,6,8,2,8,6,16,2,4,6,8,4,12,6,16,4,4,4,16,2,12,10,32,4,4,8,8,2,12,6,16,2,8,6,24,6,12,8,32,6,8,6,8,2,8,10,32,4,4,6,24,2,20,6,64,6,8,8,8,4,16,6,16,2,4,8,24,14,12,6,32};
int main(){ 
    int t;
    cin >> t;
    while(t -- ){
        cin >> n;
        cout << a[n] << endl;
    }	
    return 0;
}