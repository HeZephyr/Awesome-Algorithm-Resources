/**
  *@filename:单调队列
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-02 15:25
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9+7;

int n,k,a[N];//我们用单调队列记录下标。
void get_min(){
    deque<int> q;
    //先将k - 1个数入队。由于这里求最小值，我们需要维护一个单调递增队列。指从队头到队尾递增。
    for(int i = 1; i <= k - 1; ++ i){
        while(!q.empty() && a[q.back()] >= a[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    //再将剩下的入队，注意提前剔除过期的值。
    for(int i = k; i <= n; ++ i){
        while(!q.empty() && a[q.back()] >= a[i]){
            q.pop_back();
        }
        q.push_back(i);
        while(!q.empty() && q.front() < i - k + 1){
            //队尾为i，那么k个元素则头部的元素下标为i - k + 1，超出的均为过期元素。
            q.pop_front();
        }
        printf("%d ",a[q.front()]);
    }
    printf("\n");
}
void get_max(){
    deque<int> q;
    //先将前k - 1个元素入队，维护一个单调递减序列。
    for(int i = 1; i <= k - 1; ++ i){
        while(!q.empty() && a[q.back()] <= a[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    for(int i = k; i <= n; ++ i){
        while(!q.empty() && a[q.back()] <= a[i]){
            q.pop_back();
        }
        q.push_back(i);
        //剔除过期元素。
        while(!q.empty() && q.front() < i - k + 1){
            q.pop_front();
        }
        printf("%d ",a[q.front()]);
    }
    printf("\n");
}
void solve(){
    get_min();
    get_max();
}
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}
/*
数组实现：
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n,k,st,ed,q[N],a[N];
void get_min(){
    st = 1,ed = 0;
    for(int i = 1; i <= k - 1; ++ i){
        while(st <= ed && a[q[ed]] >= a[i]){
            ed -- ;
        }
        q[++ ed] = i;
    }
    for(int i = k; i <= n; ++ i){
        while(st <= ed && a[q[ed]] >= a[i]){
            ed -- ;
        }
        q[++ ed] = i;
        //剔除过期元素。
        while(st <= ed && q[st] < i - k + 1){
            st ++;
        }
        printf("%d ",a[q[st]]);
    }
    printf("\n");
}
void get_max(){
    st = 1,ed = 0;
    for(int i = 1;i <= k - 1; ++ i){
        while(st <= ed && a[q[ed]] <= a[i]){
            ed -- ;
        }
        q[++ ed] = i;
    }
    for(int i = k; i <= n; ++ i){
        while(st <= ed && a[q[ed]] <= a[i]){
            ed -- ;
        }
        q[++ ed] = i;
        while(st <= ed && q[st] < i - k + 1){
            st ++ ;
        }
        printf("%d ",a[q[st]]);
    }
    printf("\n");
}
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    get_min();
    get_max();
    return 0;
}
*/