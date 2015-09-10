// 最短路径
//  1072.cpp
//  hello world
//
//  Created by Wu bin on 15/9/5.
//  Copyright (c) 2015年 Wu bin. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
//#include <iomanip>
using namespace std;
#define maxn 1005
#define maxm 12
#define maxk 1017
int N,M,K,DS;
int edges[maxk][maxk];
char location[maxm][3];
bool visit[maxk];
int dist[maxk];
struct ans
{
    ans(int a,int b,int c):index(a),sum(b),mini(c){}
    int index;
    int sum;
    int mini;
};
vector<ans> res;
bool bigger(const ans & a,const ans & b)
{
    if (a.mini > b.mini)
        return true;
    else if (a.mini == b.mini)
    {
        if (a.sum < b.sum)
            return true;
        else if (a.sum == b.sum && a.index < b.index)
            return true;
    }
    return false;
}
int getIndex(const char * ch)
{
    if (ch[0] == 'G')
    {
        int i = 1;
        for (;i <= M; i++)
        {
            if (ch[1] == char('0' + i))
            {
                break;
            }
        }
        return N + i;
    }
    else
    {
        int i = 1;
        for (;i <= N; i++)
        {
            if (ch[0] == char('0' + i))
            {
                break;
            }
        }
        return i;
    }
}
bool allvisit()
{
    for (int j = 1; j <= M+N; j++)
    {
        if (!visit[j])
            return false;
    }
    return true;
}
void djstar(int i)
{
    for (int k = 1; k <= M+N; k++)
    {
        dist[k] = edges[i][k];
    }
    visit[i] = true;
    while(1)
    {
        int mini = 0x7ffffff;
        int miniJ = 0;
        for (int j = 1; j <= N+M; j++)
        {
            if (dist[j] < mini && !visit[j])
            {
                mini = dist[j];
                miniJ = j;
            }
        }
        visit[miniJ] = true;
        for (int j = 1; j <= M+N; j++)
        {
            if (dist[miniJ] + edges[miniJ][j] < dist[j] && !visit[j])
            {
                dist[j] = dist[miniJ] + edges[miniJ][j];
            }
        }
        if (allvisit())
        {
            break;
        }
    }
}
int main()
{
    for (int i = 0;i < maxk; i++)
    {
        for (int j = 0; j < maxk; j++)
        {
            edges[i][j] = 0x3ffffff;
        }
    }
    cin >> N >> M >> K >> DS;
    for (int i = 1; i <= M; i++)
    {
        location[i][0] = 'G';
        location[i][1] = char('0'+i);
    }
    for (int i = 0; i < K; i++)
    {
        char a[3],b[3];
        int ds;
        cin >> a >> b >> ds;
        int aIndex = getIndex(a), bIndex = getIndex(b);
        edges[aIndex][bIndex] = ds;
        edges[bIndex][aIndex] = ds;
    }
    for (int i = N + 1; i <= N + M; i++)
    {
        memset(visit,false,maxk*sizeof(bool));
        djstar(i);
        bool ok = true;
        for (int j = 1; j <= N; j++)
        {
            if (dist[j] > DS)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            int sum = 0, mini = 0x7fffffff;
            for (int j = 1; j <= N; j++)
            {
                sum += dist[j];
                if (mini > dist[j])
                    mini = dist[j];
            }
            res.push_back(ans(i,sum,mini));
        }
    }
    if (res.empty())
    {
        cout << "No Solution" << endl;
        return 0;
    }
    sort(res.begin(),res.end(),bigger);
    cout << location[res[0].index - N] << endl;
    //cout.setf(ios::fixed);
    //cout.precision(1);
    //cout << float(res[0].mini) << " " << float(res[0].sum) / N << endl;
    //cout<<setiosflags(ios::fixed)<<setprecision(1)<<float(res[0].mini)<<" "<<float(res[0].sum)/N<<endl;
    printf("%.1f %.1f\n",res[0].mini*1.0,res[0].sum*1.0/N);
}