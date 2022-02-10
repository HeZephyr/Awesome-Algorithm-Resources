#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5;
char a[maxn],b[maxn];
void work(char *s,int &l,int &r){
    //去除首0.注意不要清除到小数点。
    while(s[l]=='0'&&l<r&&s[l+1]!='.')l++;
    //检查是否有小数点。
    bool flag=false;
    for(int i=l;i<=r;i++){
        if(s[i]=='.'){
            flag=true;
            break;
        }
    }
    //如果有小数点就去除尾0.
    if(flag){
        while(s[r]=='0')r--;
    }
    if(s[r]=='.')r--;
}
void solve(){
    //去除首0，和小数点之后的0.
    int la=0,ra=strlen(a)-1,lb=0,rb=strlen(b)-1;
    work(a,la,ra);
    work(b,lb,rb);
    if(ra-la!=rb-lb){
        cout<<"NO"<<endl;
        return;
    }
    else{
        //如果长度相同
        while(la<=ra){
            if(a[la]!=b[lb]){
                cout<<"NO"<<endl;
                return;
            }
            la++,lb++;
        }
        cout<<"YES"<<endl;
    }
}
int main(){
    while(cin>>a>>b){
        solve();
    }
    return 0;
}