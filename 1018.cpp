/*
 dfs 回溯 长度最小，发的单车最少，回收的单车最少
 */

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>
#include <string>
#include <queue>

using namespace std;

int Cmax,N,Sp,M;
int C[505];
int Road[505][505];
bool isReached[505];

int curLen = 0;
int minLen = 1<<30;
int curBike = 0;
int minBike = 1<<30;
int curSend = 0;
int minSend = 1<<30;
vector<int> curRoad;
vector<int> minRoad;

void dfs(int cur)
{
    if(curLen>minLen)
        return;
    if(cur == Sp)
    {
        bool choosed = false;
        if(curLen<minLen)
        {
            choosed = true;
            
        }else if(curLen == minLen)
        {
            if(curSend<minSend)
            {
                choosed = true;
            }else if(curSend == minSend)
            {
                if(curBike<minBike)
                {
                    choosed = true;
                }
            }
        }
        if(choosed)
        {
            minLen =  curLen;
            minSend = curSend;
            minBike = curBike;
            minRoad = curRoad;
        }
        return;
    }
    for(int i=0;i<=N;i++)
    {
        if(!isReached[i] && Road[cur][i]>0)
        {
            isReached[i] = true;
            curLen+= Road[cur][i];
            
            int lastCurSend = curSend;
            int lastCurBike = curBike;
            if(C[i]+curBike<Cmax/2){
                curSend += Cmax/2 - (C[i]+curBike);
                curBike = 0;
            }else{
                curBike = C[i]+curBike-Cmax/2;
            }
            curRoad.push_back(i);
            dfs(i);
            curRoad.pop_back();
            curSend = lastCurSend;
            curBike = lastCurBike;
            curLen-= Road[cur][i];
            isReached[i] = false;
        }
    }
}
int main()
{
    scanf("%d %d %d %d",&Cmax,&N,&Sp,&M);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",C+i);
    }
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        Road[a][b] = c;
        Road[b][a] = c;
    }
    isReached[0] = true;
    dfs(0);
    printf("%d ",minSend);
    printf("%d",0);
    for(int i=0;i<minRoad.size();i++)
    {
        printf("->%d",minRoad[i]);
    }
    printf(" %d",minBike);
    return 0;
}