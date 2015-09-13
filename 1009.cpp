//
//  1009.cpp
//  hello world
//
//  Created by Wu bin on 15/9/11.
//  Copyright (c) 2015年 Wu bin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 11
int ALen,BLen;
struct unit
{
    unit():coefficient(0.0),exp(0){}
    unit(int a,float b):coefficient(b),exp(a){}
    float coefficient;
    int exp;
    unit operator * (const unit & b)const
    {
        unit tmp;
        tmp.exp = exp + b.exp;
        tmp.coefficient = coefficient * b.coefficient;
        return tmp;
    }
    bool operator < (const unit & b)const
    {
        return exp < b.exp;
    }
};
unit A[maxn],B[maxn];
vector<unit> C;
vector<unit> ans;
int main()
{
    cin >> ALen;
    for (int i = 0; i < ALen; i++)
    {
        int a;
        float b;
        cin >> a >> b;
        unit tmp(a,b);
        A[i] = tmp;
    }
    cin >> BLen;
    for (int i = 0; i < BLen; i++)
    {
        int a;
        float b;
        cin >> a >> b;
        unit tmp(a,b);
        B[i] = tmp;
    }
    for (int i = 0; i < ALen; i++)
    {
        for (int j = 0; j < BLen; j++)
        {
            unit tmp = A[i] * B[j];
            if (tmp.coefficient != 0)
                C.push_back(tmp);
        }
    }
    if (C.empty())
    {
        cout << 0 << endl;
        return 0;
    }
    sort(C.begin(),C.end());
    int len = int(C.size());
    float sum = 0.0;
    for (int i = 0; i < len; i++)
    {
        if (i == 0 || C[i].exp == C[i-1].exp)
        {
            sum+=C[i].coefficient;
        }
        else
        {
            unit res(C[i-1].exp,sum);
            if (sum != 0)
                ans.push_back(res);
            sum = C[i].coefficient;
        }
    }
    unit res(C[len-1].exp,sum);
    if (sum != 0)
        ans.push_back(res);
    cout << ans.size();
    cout.setf(ios::fixed);
    cout.precision(1);
    for (int i = int(ans.size())-1; i >= 0; i--)
    {
        if (i > 0)
            //printf(" %d %.1f",ans[i].exp,ans[i].coefficient);
            cout << " " << ans[i].exp << " " << ans[i].coefficient;
        else
            //printf(" %d %.1f\n",ans[i].exp,ans[i].coefficient);
            cout << " " << ans[i].exp << " " << ans[i].coefficient << endl;
    }
}
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct
//{
//    int expo;//指数
//    double coef;//系数
//}poly;
//
//int main()
//{
//    int k1, k2;
//    poly *a, *b;
//    int i,j;
//    int max;//能够出现的最大指数
//    poly *c;
//    int zhishu, xishu;
//    int count;
//    
//    while(scanf("%d", &k1) != EOF)
//    {
//        a = (poly *)malloc(k1 * sizeof(poly));
//        for(i = 0; i < k1; i ++)
//        {
//            scanf("%d %lf", &a[i].expo, &a[i].coef);
//        }
//        scanf("%d", &k2);
//        b = (poly *)malloc(k2 * sizeof(poly));
//        for(i = 0; i < k2; i ++)
//        {
//            scanf("%d %lf", &b[i].expo, &b[i].coef);
//        }
//        max = a[0].expo + b[0].expo;
//        c = (poly *)malloc((max + 1) * sizeof(poly));
//        for(i = 0; i <= max; i ++)
//        {
//            c[i].expo = i;
//            c[i].coef = 0;
//        }//初始化结果
//        for(i = 0; i < k1; i ++)
//        {
//            for(j = 0; j < k2; j ++)
//            {
//                zhishu = a[i].expo + b[j].expo;
//                c[zhishu].coef += a[i].coef * b[j].coef;
//            }
//        }
//        count = 0;
//        for(i = 0; i <= max; i ++)
//        {
//            if(c[i].coef != 0)
//            {
//                count ++;
//            }
//        }
//        printf("%d", count);
//        for(i = max; i >= 0; i --)
//        {
//            if(c[i].coef != 0)
//            {
//                printf(" %d %.1lf", i, c[i].coef);
//            }
//        }
//        printf("\n");
//    }
//    return 0;
//}