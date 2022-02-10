#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, x1, Y1, x2, Y2;
struct node{
    int x1, x2;
    bool operator < (const node &A){
        return x1 < A.x1;
    }
}a[N];
int main(){
    cin >> n;
    for(int i = 0; i < n; ++ i){
        cin >> x1 >> Y1 >> x2 >> Y2;
        a[i].x1 = x1, a[i].x2 = x2;
    }
    sort(a, a + n);
    int res = 0;
    int last = 0;
    for(int i = 0; i < n; ++ i){
        if(a[i].x1 < last){
            if(a[i].x2 < last)continue;
            else res += a[i].x2 - last, last = a[i].x2;
        }
        else{
            res += a[i].x2 - a[i].x1;
            last = a[i].x2;
        }
    }
    cout << res << endl;
    return 0;
}