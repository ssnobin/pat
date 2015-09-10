//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//#define maxn 100005
//long long A[maxn];
//int main()
//{
//	memset(A,0,sizeof(int)*maxn);
//	int N, P, maxLength = 0;
//	cin >> N >> P;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> A[i];
//	}
//	sort(A,A+N);
//	for (int i = 0; i < N; i++)
//	{
//		//在i 到 N-1 中查找符合的最大的小于等于A[i]*P
//		int l = i, r = N-1, m;
//		long long target = A[i]*P;
//		bool find = false;
//		while(l <= r)
//		{
//			m = (l+r)/2;
//			if (A[m] < target)
//				l = m+1;
//			else if (A[m] > target)
//				r = m-1;
//			else
//			{
//				find = true;
//				break;
//			}
//		}
//		//有多个连续的一样的A[m]，取→_→的
//		if (find)
//		{
//			int end = m;
//			while(A[end] == A[m])
//			{
//				end++;
//			}
//			m = end-1;
//		}
//		else
//		{
//			if (A[m] > target)
//				m = m-1;
//			else
//				m = m;
//		}
//		if (maxLength < m-i+1)
//		{
//			maxLength = m-i+1;
//		}
//	}
//	cout << maxLength << endl;
//}
//
////因为乘法所以会超过int, 用longlong 八个字节，64位 2的64次方-1最大