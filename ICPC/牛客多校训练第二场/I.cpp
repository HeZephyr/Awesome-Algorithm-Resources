/**
  *@filename:I
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-20 15:33
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 20 + 5;
const int P = 1e9+7;


char g1[N][N],g2[N][N];
string go[] = {"D","L","R","U"};
struct node{
    int x1,y1,x2,y2;
    string s;
};
bool vis[21][21][21][21];
void change(string s){
    //按照路径更改地图。
    char op = 'A';
    node head,temp;
    head.x1 = 20, head.y1 = 20, head.x2 = 20, head.y2 = 1;
    g1[20][20] = 'A',g2[20][1] = 'A';
    for(int i = 0; i < s.size(); ++ i){
        temp = head;
        if(s[i] == 'D'){
            temp.x1 += 1;
            temp.x2 += 1;
        }
        else if(s[i] == 'U'){
            temp.x1 -= 1;
            temp.x2 -= 1;
        }
        else if(s[i] == 'L'){
            temp.y1 -= 1;
            temp.y2 += 1;
        }
        else{
            temp.y1 += 1;
            temp.y2 -= 1;
        }
        if(temp.x1 < 1 || temp.y1 < 1 || temp.y1 > 20 || temp.x1 > 20 || g1[temp.x1][temp.y1] == '#'){
            temp.x1 = head.x1,temp.y1 = head.y1;
        } 
        if(temp.x2 < 1 || temp.y2 < 1 || temp.y2 > 20 || temp.x2 > 20 || g2[temp.x2][temp.y2] == '#'){
            temp.x2 = head.x2,temp.y2 = head.y2;
        }
        if(g1[temp.x1][temp.y1] != '#'){
            g1[temp.x1][temp.y1] = 'A';
        } 
        if(g2[temp.x2][temp.y2] != '#'){
            g2[temp.x2][temp.y2] = 'A';
        }
        head = temp;
    }
}
void solve(){
    node head,temp;
    queue<node> q;
    //起始点左企鹅在
    head.x1 = 20, head.y1 = 20, head.x2 = 20, head.y2 = 1;
    vis[20][20][20][1] = 1;
    head.s = "";
    q.push(head); 
    while(!q.empty()){
        head = q.front();
        q.pop();
        //判断是否到了该点。
        if(head.x1 == 1 && head.y1 == 20 && head.x2 == 1 && head.y2 == 1){
            cout << head.s.size() << endl;
            cout << head.s << endl;
            change(head.s);
            for(int i = 1; i <= 20; ++ i){
                cout << g1[i] + 1 << " " << g2[i] + 1 << endl;
            }
            break;
        }
        // cout << head.s << endl;
        for(int i = 0; i < 4; ++ i){
            temp = head;
            temp.s += go[i];
            if(go[i] == "D"){
                temp.x1 += 1;
                temp.x2 += 1;
            }
            else if(go[i] == "U"){
                temp.x1 -= 1;
                temp.x2 -= 1;
            }
            else if(go[i] == "L"){
                temp.y1 -= 1;
                temp.y2 += 1;
            }
            else{
                temp.y1 += 1;
                temp.y2 -= 1;
            }
            if((temp.x1 < 1 || temp.y1 < 1 || temp.x1 > 20 || temp.y1 > 20) && (temp.x2 < 1 || temp.y2 < 1 || temp.x2 > 20 || temp.y2 > 20))continue;
            if(temp.x1 >= 1 && temp.y1 >= 1 && temp.x1 <= 20 && temp.y1 <= 20 && temp.x2 >= 1 && temp.y2 >= 1 && temp.x2 <= 20 && temp.y2 <= 20
            &&g1[temp.x1][temp.y1] == '#' && g2[temp.x2][temp.y2] == '#')continue;
            if(temp.x1 < 1 || temp.y1 < 1 || temp.y1 > 20 || temp.x1 > 20 || g1[temp.x1][temp.y1] == '#'){
                temp.x1 = head.x1,temp.y1 = head.y1;
            } 
            if(temp.x2 < 1 || temp.y2 < 1 || temp.y2 > 20 || temp.x2 > 20 || g2[temp.x2][temp.y2] == '#'){
                temp.x2 = head.x2,temp.y2 = head.y2;
            } 
            if(vis[temp.x1][temp.y1][temp.x2][temp.y2])continue;
            vis[temp.x1][temp.y1][temp.x2][temp.y2] = true;
            q.push(temp);
        }
    }
}
int main(){
    for(int i = 1; i <= 20; ++ i){
        cin >> g1[i] + 1 >> g2[i] + 1;
    }
    solve();
    return 0;
}