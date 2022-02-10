#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

const int N = 2e5 + 10;
int n;
pair<int,int> a[N];
void solve(){
    //注意，这个相当于一个圈，所以我们可以任取队头。
    //确定队头之后，怎么确定之后的两个元素的顺序呢。
    vector<int> q;//队列q。
    q.push_back(1);
    int x = a[1].x, y = a[1].y;
    bool flag = true;
    //判断x的后两个元素是不是y。
    if(a[x].x == y || a[x].y == y){
        flag = false;
    }
    if(flag){
        swap(x,y);//那么说明x的后一个元素不是y，则y在x前面，我们交换这两个值即可。保证x在前y在后。
    }
    q.push_back(x),q.push_back(y);
    int len = q.size();
    while(len < n){
        int cur = a[x].x;
        if(y == cur){
            //说明cur是第一个元素，而我们要将第二个元素入队。
            cur = a[x].y;
        }
        q.push_back(cur);
        //这样一直迭代后两个元素。
        len ++;
        x = y;
        y = cur;
    }
    for(int i = 0; i < len; ++ i){
        cout << q[i] << " ";
    }
    cout << endl;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    solve();
    return 0;
}