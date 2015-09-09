////
////  Simulation A.cpp
////  hello world
////
////  Created by Wu bin on 15/9/9.
////  Copyright (c) 2015年 Wu bin. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//#define maxN 0x7fffffff
//int N,maxi = 0;
//vector<int> ans,res,tmp,allF;
//int getConseLen(const vector<int> & a, int & index)
//{
//    int i = 0, maxLen = 0, currLen = 1;
//    for (; i < a.size() - 1; i++)
//    {
//        if (a[i+1] - a[i] == 1)
//        {
//            currLen++;
//        }
//        else
//        {
//            currLen = 1;
//        }
//        if (currLen > maxLen)
//        {
//            maxLen = currLen;
//            index = i+1;
//        }
//    }
//    return maxLen;
//}
//int getConseLen2(const vector<int> & a,int & index)//找到最长的，并且返回开始下标index和长度
//{
//    int maxLen = 1,sum = 1;
//    int j;
//    for (int i = 0; i < a.size(); i=j)
//    {
//        for (j = i+1; j < a.size();j++)
//        {
//            if (a[j]-a[j-1]==1)
//            {
//                sum++;
//                if(sum > maxLen)
//                {
//                    maxLen = sum;
//                    index = i;
//                }
//            }
//            else
//            {
//                sum = 1;
//                break;
//            }
//        }
//    }
//    return maxLen;
//}
//bool isPrime(int x)
//{
//    if (x == 2||x==3)
//        return true;
//    for (int i = 2; i <= sqrt(x); i++)
//    {
//        if (x % i == 0)
//            return false;
//    }
//    return true;
//}
//void calAllFactor(int x)
//{
//    while (x > 1)
//    {
//        for (int i = 2; i <= x; i++)
//        {
//            if (x%i==0)
//            {
//                allF.push_back(i);
//                x/=i;
//                break;
//            }
//        }
//    }
//}
//void backtarce(int x)
//{
//    if (x == 1)
//    {
//        int startIndex = 0;
//        tmp = ans;
//        sort(tmp.begin(),tmp.end());
//        int len = getConseLen2(tmp, startIndex);
//        if (len > maxi)
//        {
//            res.clear();
//            maxi = len;
//            for (int i = startIndex; i < startIndex + len; i++)
//            {
//                res.push_back(tmp[i]);
//            }
//        }
//        else if (len == maxi && tmp[startIndex] < res[0])
//        {
//            res.clear();
//            maxi = len;
//            for (int i = startIndex; i < startIndex + len; i++)
//            {
//                res.push_back(tmp[i]);
//            }
//        }
//        return;
//    }
//    for (int i = 2; i <= x; i++)
//    {
//        if (x%i == 0)
//        {
//            ans.push_back(i);
//            backtarce(x/i);
//            ans.pop_back();
//        }
//    }
//}
//int main()
//{
//    cin >> N;
//    if (N == 1)
//    {
//        cout << 1 << endl;
//        //cout << 1 << endl; //难道需要这一行。。
//        return 0;
//    }
//    if (isPrime(N))
//    {
//        cout << 1 << endl;
//        cout << N << endl;
//        return 0;
//    }
//    //calAllFactor(N);
//    backtarce(N);
//    cout << res.size() << endl;
//    for (int i = 0; i < res.size(); i++)
//    {
//        if (i == 0)
//            cout << res[0];
//        else
//            cout << "*" << res[i];
//    }
//    cout << endl;
//}

#include<cstdio>
int main(){
    int N, i , j, max_no, temp, left;
    scanf("%d", &N);
    for(i = 2, max_no = 0; i <= N; i ++){//这也行，日了狗，🐶我还回溯，我还算一个数组里最大的conse。的长度，我sb呀。。直接暴力求解，遍历。。。
        temp = N;
        for(j = i; j <= N; j ++){
            if(temp % j != 0){
                break;
            }else{
                temp = temp / j;
            }
        }
        if(max_no < j - i) {
            max_no = j - i;
            left = i;
        }
    }
    printf("%d\n", max_no);
    for(i = 0; i < max_no; i ++){
        printf("%d", left ++);
        if(i != max_no - 1) {
            printf("*");
        }
    }
    return 0;
}