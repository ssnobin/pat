//求环中两点的距离 ， 将起点到i的距离和记录下来。。。我写得太复杂了。。
//for(int i=0;i<N;i++){
//    ivec.push_back(sum);//第一个点到原点距离为0
//    cin>>x;
//    sum+=x;
//}
//int M;
//cin>>M;
//int a,b;
//while(M--){
//    cin>>a>>b;
//    a--;
//    b--;
//    if(a>b)
//        swap(a,b);
//        int len=ivec[b]-ivec[a];
//        len=min(len,sum-len);
//        cout<<len<<endl;
        }
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define maxn 100005
int A[maxn];
vector<int> ans;
int main()
{
	int N,sum=0;
	memset(A,0,maxn*sizeof(int));
	cin >> N;
	for (int i = 1; i <=N; i++)
	{
		cin >> A[i];
		sum+=A[i];
	}
	int ncase;
	cin >> ncase;
	while(ncase--)
	{
		int a,b,res = 0;
		cin >> a >> b;
		if (a > b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		int interval = b - a;
		int another = N - interval;
		if (interval > N/2)
		{
			for (int i = b; i < b+another; i++)
			{
				if (i <= N)
					res+=A[i];
				else
				{
					res+=A[i - N];
				}
			}
		}
		else
		{
			for (int i = a; i < b; i++)
			{
				res += A[i];
			}
		}
		if (res > sum / 2)
		{
			res = sum - res;
		}
		ans.push_back(res);
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}