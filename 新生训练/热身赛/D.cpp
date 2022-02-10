#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+5;
struct Interval{
    ll l,r;
    bool operator<(const Interval A){
        if(l!=A.l)return l<A.l;
        else return r<A.r;
    }
};
Interval intervals[maxn];
ll n,m;//n个区间m张补签卡。
void solve(){
    sort(intervals,intervals+n);
    //先将区间处理成不相交的子区间
    int i=0,temp,index=0;
    ll last;//当前所更新区间的最右端点位置。
    while(i<n){
        temp=i+1,last=intervals[i].r;
        //利用当前区间去更新后面区间。判断条件为左端点是否在该区间内。
        while(temp<n&&intervals[temp].l<=last){
            //将区间合并，更新该区间的右端点。
            last=max(last,intervals[temp].r);
            temp++;//继续寻找
        }
        intervals[index].l=intervals[i].l,intervals[index].r=last;
        index++;//新区间数++。
        i=temp;//此时temp是不满足条件的，所以我们以此为准去更新区间。
    }
    //现在我们得到的区间都是有序的，且不相交，所以我们可以利用尺取法来解决。
    n=index;//更新区间数量。
    /* for(int i=0;i<n;i++){
        printf("[%d,%d]\n",intervals[i].l,intervals[i].r);
    } */
    ll ans=m;//ans代表签到数，由于有m张补签卡，至少会签到m次。
    temp=m;//temp代表的是补签数量
    int l=0,r=0;
    while(r<n){
        //尺取法
        while(r+1<n&&intervals[r+1].l-intervals[r].r-1<=temp){
            //固定左端点，右端点不断移动。
            temp-=intervals[r+1].l-intervals[r].r-1;//补签，使得变为连续区间。
            r++;
        }
        ans=max(ans,intervals[r].r-intervals[l].l+temp+1);
        //移动l，处理清楚补签次数。
        if(l+1<n&&intervals[l+1].l-intervals[l].r-1>0&&intervals[l+1].l-intervals[l].r-1+temp<=m){
            //如果该区间空隙被补过，就清除影响，因为我们要做下次移动了。
            temp+=intervals[l+1].l-intervals[l].r-1;
        }
        l++;
        while(l>r)r++;//确保r大于等于l。
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            cin>>intervals[i].l>>intervals[i].r;
        }
        solve();
    }
    return 0;
}