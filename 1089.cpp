//
//  1089.cpp
//  hello world
//
//  Created by Wu bin on 15/9/2.
//  Copyright (c) 2015年 Wu bin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
#define maxn 105
int init[maxn],init2[maxn],temp[maxn],target[maxn];
int N,flag = 0;
bool same(int A[],int B[])
{
    for (int i = 0; i < N; i++)
    {
        if (A[i] != B[i])
            return false;
    }
    return true;
}
void mergeSort(int A[],int temp[],int left,int right)
{
    if (left == right)
        return;
    int mid = (left + right) / 2;
    mergeSort(A,temp,left,mid);
    mergeSort(A,temp,mid+1,right);
    //merge
    for (int i = left; i <= right; i++)
    {
        temp[i] = A[i];
    }
    int curr = left, i = left,j  = mid+1;
    for (;curr <= right;curr++)
    {
        if (i == mid+1)
        {
            A[curr] = temp[j];
            j++;
        }
        else if (j == right+1)
        {
            A[curr] = temp[i];
            i++;
        }
        else if (temp[i] < temp[j])
        {
            A[curr] = temp[i];
            i++;
        }
        else
        {
            A[curr] = temp[j];
            j++;
        }
    }
}
void mergeSort2(int A[],int temp[])
{
    int every = 1;
    while (1)
    {
        int i = 0;
        for (; i < N; i+=every)
        {
            int left = i, right = i+every-1, mid = (left+right)/2;
            if (right >= N)
                right = N-1;
            if (right < mid)
                mid = (left+right)/2;
            for (int j = left; j <= right; j++)
            {
                temp[j] = A[j];
            }
            int curr = left,p = left,q = mid+1;
            for (;curr <= right;curr++)
            {
                if (p == mid+1)
                {
                    A[curr] = temp[q];
                    q++;
                }
                else if (q == right+1)
                {
                    A[curr] = temp[p];
                    p++;
                }
                else if (temp[p] < temp[q])
                {
                    A[curr] = temp[p];
                    p++;
                }
                else
                {
                    A[curr] = temp[q];
                    q++;
                }
            }
            
        }
        every = every << 1;
        if (every>>1 > N)
            break;
        if (flag==1)
        {
            for (int i = 0; i < N-1; i++)
            {
                cout << A[i] << " ";
            }
            cout << A[N-1] << endl;
            flag = 0;
            return ;
        }
        if (same(A,target))
        {
            cout << "Merge Sort" << endl;
            flag = 1;
        }
    }
}
void insertSort()
{
    for (int i = 1; i <= N-1;i++)
    {
        for (int j = i;j >= 1;j--)
        {
            if (init2[j] < init2[j-1])
            {
                int tmp = init2[j];
                init2[j] = init2[j-1];
                init2[j-1] = tmp;
            }
        }
        if (flag == 1)
        {
            for (int i = 0; i < N-1; i++)
            {
                cout << init2[i] << " ";
            }
            cout << init2[N-1] << endl;
            flag = 0;
            return;
        }
        if (same(init2,target))
        {
            cout << "Insertion Sort" << endl;
            flag = 1;
        }
    }
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> init[i];
        init2[i] = init[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> target[i];
    }
    //mergeSort(init, temp, 0, N-1);
    mergeSort2(init, temp);
    insertSort();
}

//有inplace merge这种东西。。。

//这个也很nice啊
//bool checkinsert()
//{
//    int flag=0;
//    for(int i=2;i<=n;i++){
//        if(flag&&!isequal(aa,b)){
//            puts("Insertion Sort");
//            output(aa);
//            return true;
//        }
//        sort(aa,aa+i);
//        if(isequal(aa,b))flag=1;
//    }
//    return false;
//}
//void checkmerge()
//{
//    int flag=0;
//    for(int i=2;i<=n;i*=2)
//    {
//        int j;
//        for(j=0;j+i<=n;j+=i)
//        {
//            if(isequal(a,b))flag=1;
//            sort(a+j,a+j+i);
//        }
//        sort(a+j,a+n);
//        if(isequal(a,b))flag=1;
//        if(flag&&!isequal(a,b)){
//            puts("Merge Sort");
//            output(a);
//            return;
//        }
//    }
//}