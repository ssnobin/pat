#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 100005
int A[maxn];//B【i】表示从i开始满足条件的最小的j，使得bi到bj的和大于等于M
struct node
{
	int index;
	bool bigger,equal;
	int sum;
}B[maxn];
int main()
{
	memset(A,0,sizeof(int)*maxn);
	memset(B,0,sizeof(node)*maxn);
	int N,M,mini = 0x7fffffff;
	scanf("%d%d",&N,&M);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d",&A[i]);
	}
	bool find = false;
	for (int i = 1; i <= N; i++)
	{
		int j = i,sum=0;
		if (i==1)
		{
			sum = 0;
			j = 1;
		}
		else if (B[i-1].equal)
		{
			sum = M - A[i-1];
			j = B[i-1].index + 1;
		}
		else if (B[i-1].bigger)
		{
			sum = B[i-1].sum - A[i-1] - A[B[i-1].index];
			j = B[i-1].index;
		}
		else
		{
			break;
		}
		while(1)
		{
			if (j>N)
			{
				B[i].index = 0;
				B[i].sum = sum;
				B[i].equal = false;
				B[i].bigger = false;
				break;
			}
			sum += A[j];
			if (sum == M)
			{
				B[i].index = j;
				B[i].sum = sum;
				B[i].equal = true;
				B[i].bigger = false;
				find = true;
				break;
			}
			else if (sum > M)
			{
				B[i].index = j;
				B[i].sum = sum;
				B[i].equal = false;
				B[i].bigger = true;
				if (sum - M < mini)
				{
					mini = sum - M;
				}
				break;
			}
			j++;
		}
	}
	if (find)
	{
		for (int i = 1; i <= N; i++)
		{
			if (B[i].equal)
			{
				printf("%d-%d\n",i,B[i].index);
				//cout << i << "-" << B[i].index << endl;
			}
		}
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (B[i].bigger && B[i].sum - M == mini)
			{
				printf("%d-%d\n",i,B[i].index);
				//cout << i << "-" << B[i].index << endl;
			}
		}
	}
}

////cout 会超时我日

//贪心算法。可以看成一条贪吃蛇从左往右。头部尽可能的向右延伸直到钱够，若此方案最便宜，则记下头部和尾部位置。一旦钱够，尾部一点点收缩（同时判断方案是否最便宜），尾部收缩到钱不够后，头部继续向右延伸直到钱够。当头部到达终点，且尾部收缩到钱不够后，退出循环。复杂度O(N)。
///*2015.7.25cyq*/
//#include <iostream>
//#include <vector>
//using namespace std;
////贪心算法
//int main(){
//    int N,M;
//    scanf("%d%d",&N,&M);
//    vector<int> ivec(N);
//    for(int i=0;i<N;i++)
//        scanf("%d",&ivec[i]);
//    
//    int MIN=2147483647;
//    vector<pair<int,int> > result;
//    int left=0,right=-1;
//    int sum=0;//记录当前总价值
//    while(1){
//        while(sum<M){//头部尽可能向右延伸直到钱够
//            right++;
//            if(right==N)
//                break;
//            sum+=ivec[right];
//        }
//        if(sum<MIN){//比最省方案还便宜
//            MIN=sum;
//            result.clear();
//            result.push_back(make_pair(left,right));
//        }else if(sum==MIN)
//            result.push_back(make_pair(left,right));
//        
//        while(sum>=M){//尾部收缩直到钱不够
//            sum-=ivec[left];
//            left++;
//            if(sum>=M){//收缩过程中也要判断
//                if(sum<MIN){
//                    MIN=sum;
//                    result.clear();
//                    result.push_back(make_pair(left,right));
//                }else if(sum==MIN)
//                    result.push_back(make_pair(left,right));
//            }
//        }
//        if(right==N-1)//头部到达终点，且尾部收缩到钱不够
//            break;
//    }
//    for(auto it=result.begin();it!=result.end();it++)
//        printf("%d-%d\n",(*it).first+1,(*it).second+1);
//    return 0;
//}