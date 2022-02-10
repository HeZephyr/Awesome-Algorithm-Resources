#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

const int maxn=1e3+5;
const int inf=0x3f3f3f3f;

int n,m;//n个顶点m条边。
int g[maxn][maxn];//适用于稠密图
int dist[maxn];//所指定起点到其余点的最短距离。
bool vis[maxn];//vis[i]判断第i个顶点是否已经是最短距离。
int pre[maxn];//存储路径。pre[i]表示i的上一个顶点。
void print(int st){
    //打印st到各点的最短路径。
    for(int i=1;i<=n;i++){
        if(dist[i]==INT_MIN){
            cout<<"The i place isn't arrive the st place!"<<endl;
        }
        else{
            cout<<"point "<<i<<", The minest distance is "<<dist[i]<<endl;
            cout<<"The path is:";
            //借助栈来输出。
            stack<int> s;
            int temp=i;
            s.push(temp);
            while(temp!=st){
                s.push(pre[temp]);
                temp=pre[temp];
            }
            while(!s.empty()){
                cout<<s.top();
                if(s.size()==1){
                    cout<<endl;
                }
                else{
                    cout<<"->";
                }
                s.pop();
            }
        }
    }
}
void Dijkstra(int st){
    //我们先将dis初始化为已有的边。
    memset(pre,-1,sizeof(pre));
    for(int i=1;i<=n;i++){
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        dist[i]=g[st][i];
        //这里存储顶点。
        pre[i]=st;
    }
    dist[st]=0;//自己到自己的权值根据题目来定，这里默认为 0.
    vis[st]=0;
    int minn,index;//minn表示当前未被确定的最小值，index表示该顶点。
    for(int i=1;i<=n;i++){
        //将n个顶点依次加入判断。
        minn=inf;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dist[j]<minn){
                minn=dist[j];
                index=j;//存储当前未被确定的最小值
            }
        }
        vis[index]=true;
        //以该点去松弛其他位置的距离。
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dist[index]+g[index][j]<dist[j]){
                //进行距离更新。
                dist[j]=dist[index]+g[index][j];
                pre[j]=index;
            }
        }
    }
    print(st);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j]=inf;
        }
    }
    int u,v,w;//以有向图为例。
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;//这里表示u->v有边，边权值为w.
        g[u][v]=w;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    int st;//起点。
    cin>>st;
    Dijkstra(st);
    return 0;
}
/*
5 5
1 2 5
1 5 2
5 2 1
1 3 3
3 4 2
1
*/