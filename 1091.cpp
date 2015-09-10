// 三维bfs，or dfs
//  1091.cpp
//  hello world
//
//  Created by Wu bin on 15/9/1.
//  Copyright (c) 2015年 Wu bin. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define maxSlice 65
#define maxM 1290
#define maxN 132
int brain[maxSlice][maxM][maxN];
bool visit[maxSlice][maxM][maxN];
int M,N,L,T;
int total = 0,tmpCount = 0;
struct Node
{
    Node(int a,int b,int c)
    {
        l = a;
        m = b;
        n = c;
    }
    int l,m,n;
};
queue<Node> que;
void dfs(int l,int m,int n)
{
    if (l < 0 || l >= L || m < 0 || m >= M || n < 0 || n >= N)
        return;
    if (visit[l][m][n])
        return;
    if (brain[l][m][n] == 0)
        return;
    visit[l][m][n] = true;
    tmpCount++;
    if (l>0)
        dfs(l-1,m,n);
    if (l<L-1)
        dfs(l+1,m,n);
    if (m<M-1)
        dfs(l,m+1,n);
    if (m>0)
        dfs(l,m-1,n);
    if (n<N-1)
        dfs(l,m,n+1);
    if (n>0)
        dfs(l,m,n-1);
}
void bfs(int l,int m,int n)
{
    que.push(Node(l,m,n));
    while(!que.empty())
    {
        Node curr = que.front();
        que.pop();
        int l = curr.l, m = curr.m, n = curr.n;
        visit[l][m][n] = true;
        tmpCount++;
        if (l > 0 && brain[l-1][m][n]==1 && !visit[l-1][m][n])
        {
            visit[l-1][m][n] = true;
            que.push(Node(l-1,m,n));
        }
        if (l < L-1 && brain[l+1][m][n]==1 && !visit[l+1][m][n])
        {
            visit[l+1][m][n] = true;
            que.push(Node(l+1,m,n));

        }
        if (m > 0 && brain[l][m-1][n]==1 && !visit[l][m-1][n])
        {
            visit[l][m-1][n] = true;
            que.push(Node(l,m-1,n));
        }
        if (m < M-1 && brain[l][m+1][n]==1 && !visit[l][m+1][n])
        {
            visit[l][m+1][n] = true;
            que.push(Node(l,m+1,n));
        }
        if (n > 0 && brain[l][m][n-1]==1 && !visit[l][m][n-1])
        {
            visit[l][m][n-1] = true;
            que.push(Node(l,m,n-1));
        }
        if (n < N-1 && brain[l][m][n+1]==1 && !visit[l][m][n+1])
        {
            visit[l][m][n+1] = true;
            que.push(Node(l,m,n+1));
        }
        
    }
}
int main()
{
    memset(brain,0,sizeof(int)*maxSlice*maxM*maxN);
    memset(visit,false,sizeof(bool)*maxSlice*maxM*maxN);
    cin >> M >> N >> L >> T;
    for (int l = 0; l < L; l++)
    {
        for (int m = 0; m < M; m++)
        {
            for (int n = 0; n < N; n++)
            {
                cin >> brain[l][m][n];
            }
        }
    }
    for (int l = 0; l < L; l++)
    {
        for (int m = 0; m < M; m++)
        {
            for (int n = 0; n < N; n++)
            {
                if (brain[l][m][n] == 1 && !visit[l][m][n])
                {
                    bfs(l,m,n);
                    if (tmpCount >= T)
                        total += tmpCount;
                    tmpCount = 0;
                }
            }
        }
    }
    cout << total << endl;
}

//dfs 段错误，数据太多，递归挂了，听说有10M，要改成bfs
