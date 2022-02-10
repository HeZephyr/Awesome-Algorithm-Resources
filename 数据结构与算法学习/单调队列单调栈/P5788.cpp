#include<bits/stdc++.h>

using namespace std;

const int N = 3e6 + 10;
int n,x,s[N],a[N],top;//s为单调栈。
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    vector<int> temp;
    for(int i = n; i >= 1; -- i){
        while(top && a[s[top]] <= a[i])top --;
        if(!top)temp.push_back(0);
        else temp.push_back(s[top]);
        s[++ top] = i;
    }
    for(int i = temp.size() - 1; i >= 0; -- i){
        printf("%d ",temp[i]);
    }
    printf("\n");
    return 0;
}
/*
int n,x;
stack<int> s;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &x);
        while(!s.empty() && s.top() >= x)s.pop();
        if(s.empty())printf("-1 ");
        else printf("%d ",s.top());
        s.push(x);
    }
    printf("\n");
    return 0;
}
*/