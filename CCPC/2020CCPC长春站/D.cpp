#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, c;
int a[N];
int main(){
    int n;
    scanf("%d%d", &n, &c);
    a[0] = 1;
    for(int i =  1; i <= n; ++ i){
        int maxx = 0;
        for(int j = 0; j < i; ++ j){
            maxx = max(maxx, a[(i & j)]);
        }
        a[i] = maxx * c;
    }
    for(int i = 0; i <= n; ++ i){
        string s = "";
        int j = i;
        while(true){
            s = char((j % 2) + '0') + s;
            j /= 2;
            if(j == 0)break;
        }
        cout << s << " " << a[i] << endl;
    }
    cout << endl;
 }