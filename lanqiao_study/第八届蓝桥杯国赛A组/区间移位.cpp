/**
  *@filename:区间移位
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-02 18:53
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;//区间的数量。
struct Interval{
    int l,r;//左区间端点和右区间端点。
    bool operator<(const Interval A){
        if(A.r==r)return l<A.l;
        return r<A.r;
    }  
};
Interval intervals[maxn];
bool check(int len){
    vector<Interval> temp(intervals,intervals+n);//利用临时数组来进行处理。
    int last=0;//这个代表我们已经更新区间的最右边的点
    while(true){
        //我们枚举我们需要用的。
        bool flag=false;
        for(int i=0;i<temp.size();i++){
            //判断该区间是否符合。
            //判断是否可以移动，如果往左移都区间都在last右边，或者往右移区间都在last左边，这种情况必然不行。
            if(temp[i].l-len<=last&&temp[i].r+len>=last){
                flag=true;
                if(temp[i].l+len>=last){
                    //说明可以往左或往右移动到last，这个时候就可以获取整个区间的长度
                    last=last+(temp[i].r-temp[i].l);//更新最右边的点。
                }
                else{
                    //如果移动距离不够，那么我们最大化移动，即往右移动len.
                    last+=(temp[i].r+len-last);
                }
                //移动成功，我们就删除这个区间。即使用了这个区间。下一次重新选择最优区间。避免选择了的区间干扰。
                temp.erase(temp.begin()+i);
                break;
            }
        }
        //如果我们找不到合格的区间或者已经使用完区间了，那么我们直接退出。
        if(temp.size()==0||flag==0){
            break;
        }
    }
    return last>=20000;//判断区间最右边的点是否满足条件。
}
void solve(){
    //首先对这些进行排序。
    sort(intervals,intervals+n);
    int l=0,r=2e4,mid;//利用二分法枚举我们移动的区间位移量
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            //可行就让这个变得更小。
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<(float(l))/2.0<<endl;
}
int main(){
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>intervals[i].l>>intervals[i].r;//由于区间可能是小数，所以我们可以先扩大二倍，避免精度缺失。
            intervals[i].l*=2,intervals[i].r*=2;
        }
        solve();
    }
    return 0;
}