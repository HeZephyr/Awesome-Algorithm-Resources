#include<bits/stdc++.h>

using namespace std;

string s;
string op = "edgnb";
int main(){
    cin >> s;
    int len = s.size();
    int res = 0;
    for(int i = 0; i < len; ++ i){
        bool flag = false;
        for(int j = 0; j < 5; ++ j){
            if(s[i + j] != op[j]){
                flag = true;
                break;
            }
        }
        if(!flag){
            ++ res;
            i += 4;
        }
    }
    printf("%d\n", res);
    return 0;
}