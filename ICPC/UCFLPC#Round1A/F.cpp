/**
  *@filename:F
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-22 19:39
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10000 + 5;
const int P = 1e9+7;

int n,m;//飞行员数量和任务数。
struct node{
    double st,ed,score;
    int pos;
    bool operator < (node A){
        if(ed == A.ed){
            return st < A.st;
        }
        return ed < A.ed;
    }
}tasks[N];
double stu[110][N];
double score[110][N];
struct node1{
    double score;
    int pos;
    bool operator < (const node1 A){
        return score > A.score;
    }
}result[N];
int cal(int r, double x){
    int l = 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        //cout << "l:" << l << " r:" << r << endl;
        if(tasks[mid].ed <= x){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return r;
}
void solve(){
    sort(tasks + 1, tasks + 1 + m);
    for(int i = 1; i <= n; ++ i){
        double maxx = 0;
        for(int j = 1; j <= m; ++ j){
            score[i][tasks[j].pos] = max(score[i][tasks[j - 1].pos], score[i][tasks[cal(j - 1,tasks[j].st)].pos] + stu[i][tasks[j].pos]);
            maxx = max(maxx, score[i][tasks[j].pos]);
        }
        result[i].score = maxx;
        result[i].pos = i;
    }
    sort(result + 1, result + 1 + n);
    for(int i = 1; i <= 3; ++ i){
        printf("%d %.2lf\n", result[i].pos, result[i].score);
    }
}
int main(){
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; ++ i){
        scanf("%lf%lf%lf", &tasks[i].st, &tasks[i].ed, &tasks[i].score);
        tasks[i].pos = i;
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            scanf("%lf", &stu[i][j]);
            stu[i][j] *= tasks[j].score;
        }
    }
    solve();
    return 0;
}