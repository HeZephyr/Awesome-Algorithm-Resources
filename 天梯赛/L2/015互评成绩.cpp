/**
  *@filename:015互评成绩
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-20 21:03
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,k,m;//学生总数、每份作业评审数、需要输出的学生数。
vector<double> score[maxn];
void solve(){
    vector<double> result;
    for(int i=0;i<n;i++){
        double ans=0,minn=101,maxx=-1;
        for(int j=0;j<k;j++){
            ans+=score[i][j];
            minn=min(minn,score[i][j]);
            maxx=max(maxx,score[i][j]);
        }
        result.push_back((ans-minn-maxx)*1.0/(k-2));
    }
    sort(result.begin(),result.end(),greater<double>() );//doubel的问题。
    for(int i=m-1;i>=0;i--){
        printf("%.3f%c",result[i],i==0?'\n':' ');
    }
}
int main(){
    cin>>n>>k>>m;
    for(int i=0;i<n;i++){
        score[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>score[i][j];
        }
    }
    solve();
    return 0;
}