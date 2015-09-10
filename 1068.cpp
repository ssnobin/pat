//背包，动态规划
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 10001
#define maxm 100
int dp[maxn][maxm];//dp[k][i] 表示以i开头的和为k的最长序列的长度
int A[maxn];
vector<int> ans;
int cmp(const void* ta,const void* tb){  
    int* a=(int*)ta;  
    int* b=(int*)tb;  
    return *a>*b;  
}
int main()
{
	memset(dp,0,maxn*maxm*sizeof(int));
	memset(A,0,maxn*sizeof(int));
	int n,m,tmp,j = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		if (tmp <= m)
		{
			A[j] = tmp;
			j++;
		}
	}
	sort(A+1,A+j);
	//qsort(A+1,n,sizeof(int),cmp);
	for (int i = j - 1; i >= 1; i--)
	{
		for (int k = 1; k <= m; k++)
		{
			if (A[i] > k)
			{
				continue;
			}
			else if (A[i] == k)
			{
				dp[k][i] = 1;
			}
			else
			{
				int maxi = 0,p = i+1;
				while (A[p] <= k - A[i] && p <= j - 1)
				{
					if ( maxi < dp[k - A[i]][p])
					{
						maxi = dp[k - A[i]][p];
					}
					p++;
				}
				if (maxi == 0)
					dp[k][i] = 0;
				else
					dp[k][i] = 1 + maxi;
			}
		}
	}
	int sum = m,i = 1;
	while(sum>0)
	{
		int maxi = 0,find = 0;
		for (; i <= j-1; i++)
		{
			if (maxi < dp[sum][i])
			{
				maxi = dp[sum][i];
				find = i;
			}
		}
		if (maxi == 0)
		{
			cout << "No Solution" << endl;
			return 0;
		}
		ans.push_back(A[find]);
		sum = sum - A[find];
		i = find + 1;
	}
	for (i = 0; i < ans.size() - 1;i++)
		cout << ans[i] << " ";
	cout << ans[ans.size() - 1];
	return 0;
}