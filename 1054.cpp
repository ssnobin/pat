// 找过半的数，每次去掉不同的两个数，最后剩下的就是过半的数。一次遍历即可。
//int domi;
//int count=0;
//int x;
//for(int i=0;i<screen;i++){
//    cin>>x;
//    if(count==0){
//        domi=x;
//        count++;
//    }else if(domi==x)
//        count++;
//    else
//        count--;
//}
//cout<<domi;
//  1054.cpp
//  hello world
//
//  Created by Wu bin on 15/9/2.
//  Copyright (c) 2015年 Wu bin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;
#define maxn 480005
map<int,int> record;
class func
{
public:
    func(){};
    bool operator ()( const int i1, const int i2 )
    {
        return i1>i2;
    }
};

typedef map<int,char,func> icMapCmp;
typedef map<int,char,func>::iterator It1;

int main()
{
    icMapCmp c;
    c.insert(make_pair(1,'1'));
    c.insert(make_pair(3,'3'));
    c.insert(make_pair(2,'2'));
    for (It1 it1 = c.begin();it1!=c.end();++it1)
    {
        cout<<it1->first<<"\t"<<it1->second<<endl;
    }
    int M,N;
    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;
            map<int,int>::iterator it = record.find(tmp);
            if (it==record.end())
            {
                record.insert(pair<int,int>(tmp,1));
            }
            else
            {
                it->second++;
            }
        }
    }
    int maxi = 0,ans = 0;
    for (map<int,int>::iterator it = record.begin(); it != record.end(); it++)
    {
        if (it->second > maxi)
        {
            maxi = it->second;
            ans = it->first;
        }
    }
    cout << ans << endl;
    
    
    
}