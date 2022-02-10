#include<bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

char s[N];
int n;
int vis[26];
bool check[26];
vector<int> v[37]
int main(){
    scanf("%d", &n);
    scanf("%s", s + 1);
    for(int i = 1;i <= n;i++){
        if(!v[s[i]-'a'].empty()){
            for(int j = 0;i < v[s[i]-'a'].size();j++){
                
            }
        }
        v[s[i]-'a'].push_back(i);
    }
    cout << res << endl;
    return 0;
}