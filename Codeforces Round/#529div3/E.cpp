#include<bits/stdc++.h>

using namespace std;

int n;
string str;
void solve(){
    //由于我们只能修改一个位置的括号，所以必然是只存在一对不合法的括号，我们将这个不合法的给找出来。再讨论情况。
    stack<int> s;
    for(int i = 0; i < n; ++ i){
        if(str[i] == '('){
            s.push(i);
        }
        else{
            //碰到右括号就进行括号匹配。
            if(!s.empty() && str[s.top()] == '('){
                s.pop();
            }
            else{
                s.push(i);//如果不能匹配就入队。
            }
        }
    }
    //最后栈的大小一定是2个。其他的则不合法。
    int ans = 0;
    if(s.size() == 2){
        int idx2 = s.top();
        s.pop();
        int idx1 = s.top();
        //分析判断。注意按idx1 < idx2，因为我们是按下标顺序入栈的。
        if(str[idx1] == ')'){
            if(str[idx2] == '('){
                //)(当存在这种情况，我们无法修改使得其变为合法，因为进行操作只能对二者其中一个起作用。
                ans = 0;
            }
            else{
                //))当存在这种情况。我们将idx1左边的修改为(即可。
                for(int i = 0; i <= idx1; ++ i){
                    if(str[i] == ')'){
                        ans ++;
                    }
                }
            }
        }
        else{
            //说明是((类型，我们将)右边的修改为)即可。
            for(int i = idx2; i < n; ++ i){
                if(str[i] == '('){
                    ans ++;
                }
            }
        }
    }
    cout << ans << endl;
}
int main(){
    cin >> n >> str;
    solve();
    return 0;
}