/**
  *@filename:C_A_B_Palindrome
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-10 23:38
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,a,b;
string s;
void solve(){
    //如果是回文串，必有一个是偶数。
    if(a%2==1&&b%2==1){
        cout<<-1<<endl;
        return;
    }   
    int l=0,r=a+b-1;
    while(l<=r){
        if(l==r){
            if(a&1){
                if(s[l]=='0'){
                    cout<<-1<<endl;
                    return;
                }
                else{
                    a-=1;
                    s[l]='1';
                }
            }
            else if(b&1){
                if(s[l]=='1'){
                    cout<<-1<<endl;
                    return;
                }
                else{
                    b-=1;
                    s[l]='0';
                }
            }
        }
        else if((s[l]=='0'&&s[r]=='1')||(s[l]=='1'&&s[r]=='0')){
            cout<<-1<<endl;
            return;
        }
        else if((s[l]=='0'||s[r]=='0')&&b>1){
            b-=2;
            s[r]=s[l]='0';
        }
        else if((s[l]=='1'||s[r]=='1')&&a>1){
            a-=2;
            s[r]=s[l]='1';
        }
        else{
            if(a>1){
                s[l]=s[r]='1';
                a-=2;
            }
            else{
                s[l]=s[r]='0';
                b-=2;
            }
        }
        l++,r--;
    }
    if(a==0&&b==0){
        cout<<s<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
int main(){
    while(cin>>t){
        while(cin>>a>>b){
            cin>>s;
            solve();
        }
    }
    return 0;
}