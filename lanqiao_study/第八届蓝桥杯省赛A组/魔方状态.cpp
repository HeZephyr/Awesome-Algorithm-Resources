/**
  *@filename:魔方状态
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-26 20:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 2000000 + 5;
const int mod = 1e9+7;

string cube[8]={"oybbgb","oygbbb","bygbby","bybbgy","obbogb","obgobb","bbgoby","bbbogy"};//代表魔方的初始状态。
set<string> unique_cube;//去重容器。
void uCell(string &s){
    swap(s[0],s[2]);
    swap(s[2],s[5]);
    swap(s[5],s[4]);
}
void fCell(string &s){
    swap(s[2],s[1]);
    swap(s[1],s[4]);
    swap(s[4],s[3]);
}
void rCell(string &s){
    swap(s[1],s[0]);
    swap(s[0],s[3]);
    swap(s[3],s[5]);
}
void uFront(vector<string> &cube){
    //进行顶层顺时针转动。
    uCell(cube[0]);
    uCell(cube[1]);
    uCell(cube[2]);
    uCell(cube[3]);
    swap(cube[0],cube[1]);
    swap(cube[1],cube[2]);
    swap(cube[2],cube[3]); 
}
void uTail(vector<string> &cube){
    //进行底层顺时针转动。
    uCell(cube[4]);
    uCell(cube[5]);
    uCell(cube[6]);
    uCell(cube[7]);
    swap(cube[4],cube[5]);
    swap(cube[5],cube[6]);
    swap(cube[6],cube[7]);
}
void fFront(vector<string> &cube){
    //进行前层顺时针转动。
    fCell(cube[0]);
    fCell(cube[1]);
    fCell(cube[4]);
    fCell(cube[5]);
    swap(cube[1],cube[0]);
    swap(cube[0],cube[4]);
    swap(cube[4],cube[5]);
}
void fTail(vector<string> &cube){
    //进行后层顺时针旋转。
    fCell(cube[2]);
    fCell(cube[3]);
    fCell(cube[6]);
    fCell(cube[7]);
    swap(cube[2],cube[3]);
    swap(cube[3],cube[7]);
    swap(cube[7],cube[6]);
}
void rFront(vector<string> &cube){
    //进行右层顺时针旋转。
    rCell(cube[1]);
    rCell(cube[2]);
    rCell(cube[5]);
    rCell(cube[6]);
    swap(cube[2],cube[1]);
    swap(cube[1],cube[5]);
    swap(cube[5],cube[6]);
}
void rTail(vector<string> &cube){
    //进行左层顺时针旋转。
    rCell(cube[0]);
    rCell(cube[3]);
    rCell(cube[4]);
    rCell(cube[7]);
    swap(cube[3],cube[0]);
    swap(cube[0],cube[4]);
    swap(cube[4],cube[7]);
}
string change_str(vector<string> cube){
    //将二维转化为一维，便于判重。
    string temp;
    for(int i=0;i<8;i++){
        temp+=cube[i];
    }
    return temp;
}
bool check_unique(vector<string> cube){
    //判断是否重复。整体旋转魔方。
    for(int i=0;i<4;i++){
        uFront(cube),uTail(cube);
        for(int j=0;j<4;j++){
            fFront(cube),fTail(cube);
            for(int k=0;k<4;k++){
                rFront(cube),rTail(cube);
                if(unique_cube.count(change_str(cube))==1){
                    return false;
                }
            }
        }
    }
    //说明没有找到，那么我们就并入判重容器。
    unique_cube.insert(change_str(cube));
    return true;
}
void solve(){
    vector<vector<string>> cubes(maxn,vector<string>(8)); 
    copy(cube,cube+8,cubes[0].begin());
    int frontCube=0,tailCube=1;
    unique_cube.insert(change_str(cubes[0]));
    while(frontCube!=tailCube){
        for(int i=0;i<3;i++){
            copy(cubes[frontCube].begin(),cubes[frontCube].end(),cubes[tailCube].begin());
            if(i==0){
                uFront(cubes[tailCube]);
                if(check_unique(cubes[tailCube])){
                    tailCube++;
                }
            }
            else if(i==1){
                fFront(cubes[tailCube]);
                if(check_unique(cubes[tailCube])){
                    tailCube++;
                }
            }
            else{
                rFront(cubes[tailCube]);
                if(check_unique(cubes[tailCube])){
                    tailCube++;
                }
            }
        }
        frontCube++;
    }
    cout<<tailCube<<endl;
}
int main() {
    solve();
    return 0;
}