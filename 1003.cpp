//输出最短路径的条数，以及最短路径中权值和最大的值
#include <iostream>
#include <cstring>
#define maxn 505
int N,M,C1,C2;
int edges[maxn][maxn];
int weight[maxn];
bool visit[maxn];
int sum = 0,mini = 0x7fffffff,coun = 0,maxi = 0,sumRescueTeam = 0;
using namespace std;
void dfs(int i)
{
    if (i == C2)
    {
        sumRescueTeam+=weight[i];
        if (sum < mini)
        {
            mini = sum;
            maxi = sumRescueTeam;
            coun = 1;
        }
        else if (sum == mini)
        {
            coun++;
            if (sumRescueTeam > maxi)
            {
                maxi = sumRescueTeam;
            }
        }
        sumRescueTeam-=weight[i];
        return;
    }
    visit[i] = true;
    sumRescueTeam += weight[i];
    for (int j = 0; j < N; j++)
    {
        if (!visit[j] && edges[i][j] > 0)
        {
            sum += edges[i][j];
            dfs(j);
            sum -= edges[i][j];
        }
    }
    sumRescueTeam -= weight[i];
    visit[i] = false;
}
int main()
{
    memset(edges,0,maxn*maxn*sizeof(int));
    memset(visit,false,maxn*sizeof(bool));
    cin >> N >> M >> C1 >> C2;
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < M; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edges[a][b] = c;
        edges[b][a] = c;
    }
    dfs(C1);
    cout << coun << " " << maxi << endl;
}
