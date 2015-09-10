// 求树到叶子节点的路径上的权值最大，回溯，dfs，排序
//  1053.cpp
//  hello world
//
//  Created by Wu bin on 15/9/8.
//  Copyright (c) 2015年 Wu bin. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 105
int N,M,S;
int W[maxn];
int edges[maxn][maxn];
//bool visit[maxn];
int sum = 0;
vector<int> vec;
vector<vector<int>> ans;
bool bigger(const vector<int> & a,const vector<int> & b)
{
    int aLen = int(a.size());
    int bLen = int(b.size());
    int i = 0,j = 0;
    while (i < aLen && j < bLen)
    {
        if (a[i] < b[j])
        {
            return false;
        }
        else if (a[i] > b[j])
        {
            return true;
        }
        i++;
        j++;
    }
    if (i >= aLen)
    {
        //a over
        return false;
    }
    else
    {
        return true;
    }
}
void dfs(int x)
{
    //visit[x] = true;
    int num = edges[x][0];
    if (num == 0)
    {
        //leaf
        sum += W[x];
        vec.push_back(W[x]);
        if (sum == S)
        {
            ans.push_back(vec);
        }
        sum -= W[x];
        vec.pop_back();
        return;
    }
    sum += W[x];
    vec.push_back(W[x]);
    for (int i = 1; i <= N; i++)
    {
        if (edges[x][i] > 0)
        {
            dfs(i);
        }
    }
    sum -= W[x];
    vec.pop_back();
}
int main()
{
    memset(edges,0,maxn*maxn*sizeof(int));
    //memset(visit,0,maxn*sizeof(bool));
    cin >> N >> M >> S;
    for (int i = 1; i <= N; i++)
    {
        cin >> W[i];
    }
    for (int i = 1; i <= M; i++)
    {
        int index,num;
        cin >> index >> num;
        index++;//root start from 1
        edges[index][0] = num;
        for (int j = 1; j <= num; j++)
        {
            int childIndex;
            cin >> childIndex;
            childIndex++;
            edges[index][childIndex] = 1;
        }
    }
    dfs(1);
    sort(ans.begin(),ans.end(),bigger);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            if (j < ans[i].size() - 1)
                cout << ans[i][j] << " ";
            else
                cout << ans[i][j] << endl;
        }
    }
}