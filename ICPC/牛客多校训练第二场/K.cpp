#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n,k,a[N],b[N];
int main(){
    cin >> n >> k;
    int p,x;
    bool flag = false;
    for(int i = 1; i <= k; ++ i){
        cin >> p >> x;
        b[p] = x;
        if(p < x)flag = true;
    }
    if(flag){
        cout << - 1 << endl;
    }
    else{
        for(int i = 1; i <= n; ++ i){
            if(!b[i])b[i] = b[i - 1] + 1;
        }
        stack<int> s;
        int temp = 0;
        for(int i = n; i >= 1; -- i){
            while(s.size() < b[i]){
                //说明当前栈的大小小于当前状态的大小。
                s.push(++ temp);
            }
            a[i] = s.top();//栈顶为最后一个放入的元素，自然为a[i]。
            s.pop();//到前一个状态栈顶元素并没有放入，不存在了。
        }
        for(int i = 1; i <= n; ++ i){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}