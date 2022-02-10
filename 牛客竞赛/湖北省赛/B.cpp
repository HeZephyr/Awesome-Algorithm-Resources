/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-05 19:01
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m,t,k;
double a[maxn],b[maxn];//a代表的是户内景点，b代表的是户外景点。需要注意的是户外景点在下午会降到0.8
priority_queue<double> q1,q2;
void solve(){
    //题目意思也就是说选择的下午游玩的次数必须大于等于k。由于下午会有折扣，所以我们实际上只会选择下午去游玩k次即可。
    double ans=0;
    for(int i=1;i<=t;i++){
        double u=q1.top(),v=q2.top();
        //我们需要判断我们是否还能选择上午游玩。
        q1.pop(),q2.pop();
        if(i+k<=t){
            //说明还可以上午去游玩，我们需要判断去室内还是取室外。
            if(u>=v){
                //说明室内大于室外，那么我们实际上这时候就可以选择下午出发了，消耗k。
                ans+=u;
                q1.push(u*0.6),q2.push(v);
                k--;
            }
            else{
                //为了不折扣，我们选择上午出发。
                ans+=v;
                q1.push(u),q2.push(v*0.6);
            }
        }
        else{
            //说明必须下午出发。我们判断去室内还是室外。
            if(u>0.8*v){
                ans+=u;
                q1.push(u*0.6),q2.push(v);
            }
            else{
                ans+=v*0.8;
                q1.push(u),q2.push(v*0.6);
            }
        }
    }
    printf("%.2f\n",ans);
}
int main(){
    cin>>n>>m>>t>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q1.push(a[i]);
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        q2.push(b[i]);
    }
    solve();
    return 0;
}