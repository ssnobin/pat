//
//  C.cpp
//  hello world
//
//  Created by Wu bin on 15/9/9.
//  Copyright (c) 2015年 Wu bin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define maxn 12
using namespace std;

int N,E;
int edges[maxn][maxn];
bool visit[maxn];
vector< vector<int> > DFS,BFS;
vector<int> tmp;
queue<int> q;
void dfs(int i)
{
    visit[i] = true;
    tmp.push_back(i);
    for (int j = 1; j < N; j++)
    {
        if (!visit[j] && edges[i][j] == 1)
        {
            dfs(j);
        }
    }
}
void bfs(int i)
{
    visit[i] = true;
    q.push(i);
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        tmp.push_back(cur);
        for (int j = 1; j < N; j++)
        {
            if (!visit[j] && edges[cur][j] == 1)
            {
                visit[j] = true;
                q.push(j);
            }
        }
    }
}
int main()
{
    memset(edges,0,maxn*maxn*sizeof(int));
    
    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        int a,b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    memset(visit,0,maxn*sizeof(bool));
    for (int i = 0; i < N; i++)
    {
        if (!visit[i])
        {
            dfs(i);
            DFS.push_back(tmp);
            tmp.clear();
        }
    }
    memset(visit,0,maxn*sizeof(bool));
    for (int i = 0; i < N; i++)
    {
        if (!visit[i])
        {
            bfs(i);
            BFS.push_back(tmp);
            tmp.clear();
        }
    }
    for (int i = 0; i < DFS.size(); i++)
    {
        cout << "{ ";
        for (int j = 0; j < DFS[i].size(); j++)
        {
            cout << DFS[i][j] << " ";
        }
        cout<< "}" << endl;
    }
    for (int i = 0; i < BFS.size(); i++)
    {
        cout << "{ ";
        for (int j = 0; j < BFS[i].size(); j++)
        {
            cout << BFS[i][j] << " ";
        }
        cout<< "}" << endl;
    }
}