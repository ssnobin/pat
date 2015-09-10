// bfs
//  1076.cpp
//  hello world
//
//  Created by Wu bin on 15/9/8.
//  Copyright (c) 2015年 Wu bin. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
#define maxN 1005
#define maxL 7
using namespace std;

int N,L,K,counT = 0,currL = 0;
int edges[maxN][maxN];
bool visit[maxN];
queue<int> q;
vector<int> ans;
void bfs(int i)
{
    visit[i] = true;
    q.push(i);
    q.push(0);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == 0)
        {
            //level flag
            currL++;
            if (currL >= L)
            {
                break;
            }
            if (!q.empty())
            {
                q.push(0);
                continue;
            }
        }
        int sum = edges[0][curr],tmpSum = 0;
        for (int j = 1; j <= N; j++)
        {
            if (edges[j][curr] == 1 && !visit[j])//交换判断，最后一个case才能按时通过，这样子过不了。。有刹那么多么，换了是700ms，没换超过3000ms
            {
                //point to the curr
                visit[j] = true;
                counT++;
                q.push(j);
                tmpSum++;
                if (tmpSum > sum)
                    break;
            }
        }
    }
    ans.push_back(counT);
    //printf("%d\n",counT);
    //cout << counT << endl;
}
int main()
{
    memset(edges,0,maxN*maxN*sizeof(int));
    //cin >> N >> L;
    scanf("%d%d",&N,&L);
    for (int i = 1; i <= N; i++)
    {
        int num;
        //cin >> num;
        scanf("%d",&num);
        edges[i][0] = num;
        for (int j = 1; j <= num; j++)
        {
            int vertex;
            //cin >> vertex;
            scanf("%d",&vertex);
            edges[i][vertex] = 1;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            if (edges[j][i] == 1)
            {
                sum++;
            }
        }
        edges[0][i] = sum;
    }
    //cin >> K;
    scanf("%d",&K);
    for (int i = 1; i <= K; i++)
    {
        memset(visit,false,maxN*sizeof(bool));
        currL = 0, counT = 0;
        while(!q.empty())
            q.pop();
        int start;
        //cin >> start;
        scanf("%d",&start);
        bfs(start);
    }
    for (int i = 0; i < K; i++)
    {
        printf("%d\n",ans[i]);
    }
}