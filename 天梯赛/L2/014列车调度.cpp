/**
  *@filename:014列车调度
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-20 20:50
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
//这个题我们首先要知道怎么插入怎么出来，必须要车号大的先出，小的后出。所以列车排队的每一队都必须从大到小排列，
//才能保障开出去的车也是从大到小的。由于我们只要比较每一队队尾，所以我们只要存储队尾值，又需要比较，所以采用set容器自动排序。
//那么如果可以插入，就插入一个最接近的队列中，并更新队尾的值。否则就新开一个队列。
void solve(){
    set<int> t;
    t.insert(0);//作为基准值比较。
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp<*t.rbegin()){
            t.erase(*t.upper_bound(temp));//删除第一个比它大的。
        }
        t.insert(temp);
    }
    cout<<t.size()-1<<endl;//因为一开始插入了一个基准值0.
}
int main(){
    cin>>n;    
    solve();
    return 0;
}