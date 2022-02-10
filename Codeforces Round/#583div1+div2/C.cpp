#include<bits/stdc++.h>

using namespace std;

int n;
string s;
int main(){
    cin >> n >> s;
    if(n % 2)puts("No");
    else{
        //考虑内部有多少匹配。
        int cnt = 0;
        stack<char> st;
        for(int i = 0; i < n; ++ i){
            if(s[i] == ')'){
                if(!st.empty())st.pop();
                else ++ cnt;
            }
            else{
                st.push('(');
            }
        }
        if((cnt == 1 && st.size() == 1) || (!cnt && st.empty()))puts("Yes");
        else puts("No");
    }
    return 0;
}