//
//  1095.cpp
//  hello world
//
//  Created by Wu bin on 15/9/8.
//  Copyright (c) 2015年 Wu bin. All rights reserved.
//

//#include <stdio.h>
//基本功题目，纯模拟，删除无效的in or out，连续的in，后者有效，连续的out，前者有效，单独的inorout都无效，map<carId,timeVector> 下面的代码是copy的。
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
#define maxn 10050
using namespace std;
struct node2         //每个车的状态
{
    string id;        //  车牌
    int state;        //  1:in  0:out
    int sum;
    int in_time;
    int loc;          // 上一个in语句的位置
} ID[maxn];

struct node          //所有语句信息
{
    int time;
    string id;
    int state;
    int flag;        // 该语句是否正确
} s[maxn];

map<string,int>q;
set<string>w;

int cmp(node a,node b)
{
    return a.time<b.time;
}

int main()
{
    //    freopen("in.txt","r",stdin);
    int n,m;
    int query[maxn*8];
    string str1,str2;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        cin>>s[i].id>>str1>>str2;
        s[i].flag=0;
        s[i].time=((str1[0]-'0')*10+str1[1]-'0')*3600+((str1[3]-'0')*10+str1[4]-'0')*60+((str1[6]-'0')*10+str1[7]-'0');
        s[i].state=str2.compare("in")==0?1:0;
    }
    
    for(int i=1; i<=m; i++)
    {
        cin>>str1;
        query[i]=((str1[0]-'0')*10+str1[1]-'0')*3600+((str1[3]-'0')*10+str1[4]-'0')*60+((str1[6]-'0')*10+str1[7]-'0');
    }
    
    sort(s+1,s+1+n,cmp);
    
    int num=1,Que=1,ss=0,d;
    int ans=0;
    for(int i=1; i<=n; i++)         //标记错误的语句
    {
        str1=s[i].id;
        if(q[str1]==0)                            //当前车牌没出现过
        {
            ID[num]= {s[i].id,s[i].state,0,s[i].time,i};
            q[str1]=num++;
        }
        else
        {
            d=q[str1];
            if(ID[d].state==1&&s[i].state==1)      //多个in取最后一个 前面的in语句不合法
            {
                s[ID[d].loc].flag=1;
                ID[d].loc=i;
            }
            else if(ID[d].state==1&&s[i].state==0) //出去
                ID[d].state=0;
            else if(ID[d].state==0&&s[i].state==1)   //再次进入
            {
                ID[d].state=1;
                ID[d].loc=i;
            }
            else if(ID[d].state==0&&s[i].state==0)  //多个out取最前一个
                s[i].flag=1;
        }
    }
    for(int i=1;i<num;i++)
    {
        if(ID[i].state==1)         //进去没出来 不合法
        {
            s[ID[i].loc].flag=1;
            ID[i].state=0;
        }
    }
    for(int i=1; i<=n; i++)         //遍历所有语句
    {
        if(s[i].flag)
            continue;
        while(Que<m+1&&query[Que]<s[i].time)  //  while 切记
        {
            Que++;
            printf("%d\n",ss);
        }
        str1=s[i].id;
        d=q[str1];
        if(ID[d].state==1&&s[i].state==0) //进入 出去
        {
            ss--;
            ID[d].state=0;
            ID[d].sum+=s[i].time-ID[d].in_time;
            if(ID[d].sum>ans){
                ans=ID[d].sum;
                w.clear();
                w.insert(ID[d].id);
            }
            else if(ID[d].sum==ans)
                w.insert(ID[d].id);
            
        }
        else if(ID[d].state==0&&s[i].state==1)   //再次进入
        {
            ss++;
            ID[d].state=1;
            ID[d].in_time=s[i].time;
        }
        
    }
    while(Que<m+1)
    {
        printf("%d\n",ss);
        Que++;
    }
    set<string>::iterator ii;
    for(ii=w.begin();ii!=w.end();ii++)
        cout<<*ii<<" ";
    printf("%02d:%02d:%02d\n",ans/3600,ans%3600/60,ans%60);
    return 0;
}
