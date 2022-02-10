/**
  *@filename:027名人堂与代金券
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-21 20:54
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,g,k;//n学生总数，g为等级分界线，k为进入名人堂的最低名次。
int ans;//统计总值。
struct Student{
    string id;
    int score;
    bool operator<(const Student &A){
        if(score==A.score)return id<A.id;
        return score>A.score;
    }
};
Student stu[maxn];
int cal(int score){
    if(score<=100&score>=g)return 50;
    else if(score<g&&score>=60)return 20;
    else return 0;
}
void solve(){
    cout<<ans<<endl;
    sort(stu+1,stu+1+n);
    int pre_score=stu[1].score,pre_index=1;
    for(int i=1;;i++){
        if(i>k){
            if(pre_score!=stu[i].score)break;
        }
        if(pre_score==stu[i].score)cout<<pre_index<<" ";
        else{
            cout<<i<<" ";
            pre_index=i;
            pre_score=stu[i].score;
        }
        cout<<stu[i].id<<" "<<stu[i].score<<endl;
    }
}
int main(){
    cin>>n>>g>>k;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>stu[i].id>>stu[i].score;
        ans+=cal(stu[i].score);
        //cout<<ans<<endl;
    }
    solve();
    return 0;
}