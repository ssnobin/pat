//
//  1045.cpp
//  hello world
//
//  Created by Wu bin on 15/9/8.
//  Copyright (c) 2015年 Wu bin. All rights reserved.
//
//最长公共子序列，公共部分可以重复
//最长上升子序列其实是，上升按照给定的下标，而不是大小,n*n 太慢，要优化到nlogn, n*n 发现也可以QAQ
//map 的下标访问不同于普通的数组，logn 级别的耗时
//回溯法超时了。。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
#define maxN 205
#define maxM 205
#define maxL 10005
int faver[maxM];//won't duplicated for each faver[i]
int stripe[maxL];
int stp[maxL];
int dp[maxL];
bool used[maxL];
//map<int,int> NumIndex;
int N,M,L = 0,maxRes = 0; //special M > N
//bool find(int x)
//{
    //map<int,int>::iterator it = NumIndex.find(x);
    //if (it != NumIndex.end())
        //return true;
    //return false;
    //return NumIndex[x] > 0;
//    for (int i = 1; i <= M; i++)
//    {
//        if (faver[i] == x)
//        {
//            return true;
//        }
//    }
//    return false;
//}
//bool ok(int Len)
//{
//    //第Len层都是ok的？
//    int i = 1;
//    int j = 1;
//    for (;j <= Len; j++)
//    {
//        if (used[j])
//        {
//            while(i <= M)
//            {
//                if (faver[i] == stripe[j])
//                {
//                    break;
//                }
//                else
//                {
//                    i++;
//                }
//            }
//            if (i > M)
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//int countUsed()
//{
//    int c = 0;
//    for (int i = 1; i <= L; i++)
//    {
//        if (used[i])
//            c++;
//    }
//    return c;
//}
//void backtrace(int i)
//{
//    if (i > L)
//    {
//        if (countUsed() > maxRes)
//        {
//            maxRes = countUsed();
//        }
//        return;
//    }
//    used[i] = 1;
//    if (ok(i))
//    {
//        backtrace(i+1);
//    }
//    
//    used[i] = 0;
//    backtrace(i+1);
//    
////    for (; i <= L; i++)
////    {
////        used[i] = 1;
////        if (!ok(i))
////        {
////            used[i] = 0;
////        }
////        backtrace(i+1);
////    }
//}
//bool biggerOrEqual(int a,int b)
//{
//    if (a==b)
//        return true;
    //return NumIndex[a] >= NumIndex[b];
//    int aIndex = 0, bIndex = 0;
//    for(int i = 1; i <= L; i++)
//    {
//        if (faver[i] == a)
//        {
//            aIndex = i;
//        }
//        else if (faver[i] == b)
//        {
//            bIndex = i;
//        }
//        if (bIndex == 0 && aIndex != 0)
//        {
//            return false;
//        }
//        if (aIndex != 0 && bIndex != 0)
//            break;
//    }
//    if (aIndex > bIndex)
//        return true;
//    return false;
//}
void dynamicp()
{
    for (int i = 1; i <= L; i++)
    {
        if (stp[stripe[i]] == 0)
            continue;
        int maxi = 0;
        for (int j = 1; j < i; j++)
        {
            if (stp[stripe[j]] == 0)
                continue;
            if (stp[stripe[i]] >= stp[stripe[j]] && dp[j] > maxi
            /*biggerOrEqual(stripe[i], stripe[j])*/)
            {
                maxi = dp[j];
            }
        }
        dp[i] = maxi+1;
    }
    for (int i = 1; i <= L; i++)
    {
        if (dp[i] > maxRes)
            maxRes = dp[i];
    }
    //cout << maxRes << endl;
    printf("%d\n",maxRes);
}
int main()
{
    //cin >> N;
    //cin >> M;
    memset(stp,0,maxL*sizeof(int));
    scanf("%d",&N);
    scanf("%d",&M);
    for (int i = 1; i <= M; i++)
    {
        //cin >> faver[i];
        scanf("%d",&faver[i]);
        stp[faver[i]] = i;
        //int tmp;
        //scanf("%d",&tmp);
        //NumIndex[tmp] = i;
    }
    int tmpL;
    cin >> tmpL;
    for (int i = 1; i <= tmpL; i++)
    {
        //int tmpColor;
        //cin >> tmpColor;
        //scanf("%d",&tmpColor);
//        if (find(tmpColor))
//        {
//            L++;
//            stripe[L] = tmpColor;
//        }
        scanf("%d",&stripe[i]);
    }
    L = tmpL;
    //memset(used,false,maxL * sizeof(bool));
    //backtrace(1);
    //cout << maxRes << endl;
    //printf("%d\n",maxRes);
    dynamicp();
    return 0;
}

//看了一下算法导论，动态规划求X(ABCBDAB)与Y(BDCABA)的最长公共子串LCS。数学模型如下：
//设c[i][j]表示Xi与Yj的LCS，若i==0,则c[i][j]=c[0][j-1],若j==0,则c[i][j]=c[i-1][0];
//若x[i]==y[j]，则c[i][j]=c[i-1][j-1]+1;
//若x[i]!=y[j],则c[i][j]=max(c[i-1][j],c[i][j-1])。
//本题与LCS相比，唯一的差别在于最长公共子串的字符可以连续出现。故我们在x[i]==y[j]，即串尾匹配时，不应像LCS那样c[i][j]=c[i-1][j-1]+1，因为这样表明串尾字符不能参与前面的匹配了，即同一个字符不能连续进行匹配。应该c[i][j]=max(c[i-1][j],c[i][j-1])+1，x[i]和y[j]依然可以参与前面的匹配。
//
///*2015.7.25cyq*/
//#include <iostream>
//#include <vector>
//#include <string>
//#include <fstream>
//using namespace std;
//
////ifstream fin("case1.txt");
////#define cin fin
//
//int main(){
//    int N;
//    cin>>N;
//    int n;
//    cin>>n;
//    vector<int> a(n);
//    for(int i=0;i<n;i++)
//        cin>>a[i];
//    int m;
//    cin>>m;
//    vector<int> b(m);
//    for(int i=0;i<m;i++)
//        cin>>b[i];
//    
//    vector<vector<int> > c(n+1,vector<int>(m+1,0));
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            if(a[i-1]==b[j-1])//串尾相等
//                c[i][j]=max(c[i-1][j],c[i][j-1])+1;//对于LCS，此处是c[i][j]=c[i-1][j-1]+1
//            else
//                c[i][j]=max(c[i-1][j],c[i][j-1]);
//        }
//    }
//    cout<<c[n][m];
//    
//    return 0;
//}