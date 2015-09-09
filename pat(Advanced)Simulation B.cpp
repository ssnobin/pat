//
//  B.cpp
//  hello world
//
//  Created by Wu bin on 15/9/9.
//  Copyright (c) 2015年 Wu bin. All rights reserved.
//
//乘法会越界，要模拟乘法， p (≤10
//​9
//​​ ) is the parameter. In the second line there are N positive integers, each is no greater than 10
//​9
//​​ .
// 数太大，会报警。。
// long long is ok!!!
//#include<string.h>
//#include<stdio.h>
//#include<stdlib.h>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//int main(){
//    vector<int>vec;
//    int n,p,i,ans,tmp,x;
//    long long xx;
//    while(scanf("%d%d",&n,&p)!=EOF){
//        vec.clear();
//        ans=0;
//        for(i=0;i<n;i++){
//            scanf("%d",&x);
//            vec.push_back(x);
//        }
//        sort(vec.begin(),vec.end());
//        for(i=0;i<n;i++){
//            xx=(long long)((long long)vec[i]*(long long)p);
//            int maxpos;
//            if(xx>1000000000) maxpos=n-1;
//            else maxpos=upper_bound(vec.begin(),vec.end(),(int)xx)-vec.begin()-1;
//            //printf("maxpos:%d i=%d\n",maxpos,i);
//            tmp=maxpos-i+1;
//            if(ans<tmp){
//                ans=tmp;
//            }
//        }
//        printf("%d\n",ans);
//        
//    }
//    return 0;
//}
/*
 4 2
 4 3 3 2
 
 6 3
 3 6 9 10 11 13
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#define maxn 100005
using namespace std;
int a[maxn];
int N,p,maxi = 1;
int main()
{
    cin >> N >> p;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+N+1);
    
    //
//    int i = 1,j=1;
//    while (a[j] <= a[i]*p)
//    {
//        j++;
//    }
//    j--;
//    int coun = j - i + 1;
//    i++;
//    j++;
//    for(;i <= N;i++)
//    {
//        coun = j - i;
//        for (; j <= N;j++)
//        {
//            if (a[j] > a[i] * p)
//            {
//                break;
//            }
//            else
//            {
//                coun++;
//            }
//            if (coun > maxi)
//            {
//                maxi = coun;
//            }
//        }
//    }
    
    //
    int j = 1;
    //int coun = 0;
    for (int i = 1; i <= N; i++)
    {
        //coun = j - i;
        for (; j <= N; j++)
        {
            if (a[j] > a[i]*p)
            {
                break;
            }
//            else
//            {
//                coun++;
//            }
            if (j-i+1 > maxi)
            {
                maxi = j-i+1;
            }
        }
    }
    cout << maxi << endl;
}