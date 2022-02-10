/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-06 20:12
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 500000 + 5;
const int mod = 1e9+7;

int n,k;
char s[maxn];
struct node{
    int l,r,w;
    bool operator<(const node temp)const {
        return w>temp.w;//由于我们需要放到优先队列中，而默认是大顶堆，所以我们需要这样设置。
    }
};
priority_queue<node> q;
void solve(){
    int pre=0;
    node temp;
    for(int i=1;i<=n;i++){
        if(s[i]=='a'){
            if(pre){
                //说明现在存在a。
                temp.l=pre+1,temp.r=i-1,temp.w=i-pre-1;
                q.push(temp);
            }
            pre=i;//记录先前的a下标。
        }
    }
    //我们需要将这间隔补全。
    while(!q.empty()){
        temp=q.top();
        q.pop();
        if(temp.w>k){
            //说明间隔补不全。
            break;
        }
        k-=temp.w;
        for(int i=temp.l;i<=temp.r;i++){
            s[i]='a';
        }
    }
    //接下来需要补全没有填的，如果字符串中不存在a，我们自己需要构造。
    if(pre==0&&k){
        s[1]='a';
        k--;
    }
    for(int i=1;i<=n;i++){
        //从前往后看。
        if(k&&s[i]!='a'&&s[i-1]=='a'){
            s[i]='a';
            k--;
        }
    }
    for(int i=n;i>=1;i--){
        if(k&&s[i]!='a'&&s[i+1]=='a'){
            s[i-1]='a';
            k--;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]==s[i+1]&&s[i]=='a')cnt++;
    }
    cout<<cnt<<endl<<s+1<<endl;
}
int main(){
    cin>>n>>k>>s+1;
    solve();
    return 0;
}