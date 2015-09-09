/*
 求图中起点到终点的最短距离，最小花费，可以用djtsla，也可以用dfs回溯法
 */

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define maxn 505
int N,M,start,terminal;
int dist[maxn][maxn], cost[maxn][maxn];
bool visit[maxn];
int distanc[maxn],cos[maxn];
int path[maxn];
vector<vector<int>> ans;
bool allVisit()
{
    for (int i = 0; i < N; i++)
    {
        if (!visit[i])
            return false;
    }
    return true;
}
void dj(int s)
{
    memset(visit,false,maxn*sizeof(bool));
    visit[s] = true;
    for (int i = 0; i < N; i++)
    {
        distanc[i] = dist[s][i];
        cos[i] = cost[s][i];
        if (distanc[i] < 0x3fffffff)
            path[i] = s;
        else
            path[i] = -1;
    }
    while(1)
    {
        int mini = 0x7fffffff, miniI = 0;
        for (int i = 0; i < N; i++)
        {
            if (mini > distanc[i] && !visit[i])
            {
                mini = distanc[i];
                miniI = i;
            }
        }
        visit[miniI] = true;
        for (int i = 0; i < N; i++)
        {
            if (distanc[i] > distanc[miniI] + dist[miniI][i] && !visit[i])
            {
                distanc[i] = distanc[miniI] + dist[miniI][i];
                cos[i] = cos[miniI] + cost[miniI][i];
                //path[i].clear();
                //path[i].push_back(miniI);
                path[i] = miniI;
            }
            else if (distanc[i] == distanc[miniI] + dist[miniI][i] && !visit[i])
            {
                if (cos[i] > cos[miniI] + cost[miniI][i])
                {
                    cos[i] = cos[miniI] + cost[miniI][i];
                    path[i] = miniI;
                }
                //path[i].push_back(miniI);
            }
        }
        if (allVisit())
        {
            break;
        }
    }
}
void printRoute(int t)
{
    vector<int> tmp;
    tmp.push_back(t);
    while(t!=start)
    {
        t = path[t];
        tmp.push_back(t);
    }
    for (int i = int(tmp.size()) - 1; i >= 0; i--)
    {
        cout << tmp[i] << " ";
    }
}
int main()
{
    //memset(dist,0,maxn*maxn*sizeof(int));
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
        {
            dist[i][j] = 0x3fffffff;
            cost[i][j] = 0x3fffffff;
        }
    //memset(cost,0,maxn*maxn*sizeof(int));
    cin >> N >> M >> start >> terminal;
    for (int i = 0; i < N; i++)
    {
        //vector<int> tmp;
        //path[i] = tmp; // do not do this
        //path.push_back(tmp);
    }
    for (int i = 0; i < M; i++)
    {
        int a,b,d,c;
        cin >> a >> b >> d >> c;
        dist[a][b] = d;
        dist[b][a] = d;
        cost[a][b] = c;
        cost[b][a] = c;
    }
    dj(start);
    printRoute(terminal);
    cout << distanc[terminal]  << " " << cos[terminal] << endl;
}

//两个权值的dj特斯拉。。。。
//下面这个dfs碉堡了 回溯法

//#include<stdio.h>
//#include<stdlib.h>
//#include<vector>
//#include<string.h>
//using namespace std;
//
//
//int n,m,s,d,mindist,mincost,sum_dist,sum_cost;
//int mat[505][505];
//int cost[505][505];
//int vis[505];
//vector<int> v,res;
//
//void dfs(int x){
//    if(x==d){
//        if(mindist>sum_dist){
//            mindist=sum_dist;
//            mincost=sum_cost;
//            res.clear();
//            for(int j=0;j<v.size();j++)
//                res.push_back(v[j]);
//        }else if(mindist==sum_dist){
//            if(mincost>sum_cost){
//                mincost=sum_cost;
//                res.clear();
//                for(int j=0;j<v.size();j++)
//                    res.push_back(v[j]);
//            }
//        }
//        return;
//    }
//    for(int i=0;i<n;i++){
//        if(vis[i]==0&&mat[x][i]!=-1){
//            sum_dist+=mat[x][i];
//            sum_cost+=cost[x][i];
//            vis[i]=1;
//            v.push_back(i);
//            dfs(i);
//            v.pop_back();
//            vis[i]=0;
//            sum_cost-=cost[x][i];
//            sum_dist-=mat[x][i];
//        }
//    }
//}
//
//int main(){
//    scanf("%d%d%d%d",&n,&m,&s,&d);
//    memset(mat,-1,sizeof(mat));
//    memset(vis,0,sizeof(vis));
//    int a,b,c,d;
//    for(int i=0;i<m;i++){
//        scanf("%d%d%d%d",&a,&b,&c,&d);
//        mat[a][b]=mat[b][a]=c;
//        cost[a][b]=cost[b][a]=d;
//    }
//    vis[s]=1;
//    mindist=0x7fffffff;
//    mincost=0x7fffffff;
//    sum_dist=0;
//    sum_cost=0;
//    v.push_back(s);
//    dfs(s);
//    for(int i=0;i<res.size();i++){
//        if(i==0)
//            printf("%d",res[i]);
//        else
//            printf(" %d",res[i]);
//    }
//    printf(" %d %d",mindist,mincost);
//    //system("pause");
//    return 0;
//}
