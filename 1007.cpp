/*
 最大子串和
 二次遍历也能ac
 
 下面为动态规划，or 累积和
 */
//for (int i = 0; i < n; i++){
//    tmp = 0;
//    for (int j = i; j < n; j++){
//        tmp += a[j];
//        if (tmp > sum){
//            sum = tmp;
//            start = a[i];
//            end = a[j];
//        }
//    }
//}
//
///*2015.7.19cyq*/
//#include <iostream>
//#include <stack>
//#include <vector>
//using namespace std;
//
//int main(){
//    int N;
//    cin>>N;
//    vector<int> a;
//    int x;
//    for(int i=0;i<N;i++){
//        cin>>x;
//        a.push_back(x);
//    }
//    int sum=-1;
//    int max=-2147483648;
//    int end=0;
//    stack<int> begin;
//    for(int i=0;i<N;i++){
//        if(sum<0){
//            sum=a[i];
//            begin.push(i);
//        }else
//            sum+=a[i];
//        if(sum>max){
//            max=sum;
//            end=i;
//        }
//    }
//    if(max<0){
//        cout<<"0 "<<a[0]<<" "<<a[N-1];
//        return 0;
//    }
//    while(begin.top()>end){
//        begin.pop();
//    }
//    cout<<max<<" "<<a[begin.top()]<<" "<<a[end];
//    return 0;
//}
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 10005
int A[maxn];
int B[maxn];
int main()
{
    int K,sum = 0,max = -1,start = 1,end,count = 0;
    cin >> K;
    end = K;
    memset(A,0,maxn*sizeof(int));
    memset(B,0,maxn*sizeof(int));
    for (int i = 1; i <= K; i++)
    {
        cin >> A[i];
        sum += A[i];
        if (sum < 0)
        {
            sum = 0;
            count++;
        }
        B[i] = sum;
        if (B[i] > max)
        {
            max = B[i];
            end = i;
        }
    }
    for (int i = end; i >=1; i--)
    {
        if (B[i] <= 0)
        {
            start = i+1;
            break;
        }
    }
    if (count>=K)
    {
        cout << 0 << " " << A[1] << " " << A[K];
    }
    else
    {
        cout << max << " " << A[start] << " " << A[end];
    }
    
}