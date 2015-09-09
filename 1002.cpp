/*
 模拟多项式的加法，合并同列项，系数等于0的项舍去，输出一位的小数 printf("%.1f",B[i]);
 */
#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
#define INF 99999
#define maxn 1005
float A[maxn],B[maxn];
int main()
{
    int Ak,Bk;
    int ANk,BNk;
    float Aank,Bank;
    memset(A,0,maxn*sizeof(float));
    memset(B,0,maxn*sizeof(float));
    cin >> Ak;
    for (int i = 1; i <= Ak; i++)
    {
        cin >> ANk;
        cin >> Aank;
        A[ANk] = Aank;
    }
    cin >> Bk;
    for (int i = 1; i <= Bk; i++)
    {
        cin >> BNk;
        cin >> Bank;
        B[BNk] = Bank;
    }
    int count = 0;
    for (int i = 0; i < maxn; i++)
    {
        B[i] = A[i] + B[i];
        if (B[i] > 0)
            count++;
    }
    cout << count ;
    for (int i = maxn-1; i >= 0; i--)
    {
        if (B[i] > 0)
        {
            cout << " ";
            cout << i;
            cout << " ";
            printf("%.1f",B[i]);
        }
    }
}