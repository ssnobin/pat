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
//		//��i �� N-1 �в��ҷ��ϵ�����С�ڵ���A[i]*P
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
//		//�ж��������һ����A[m]��ȡ��_����
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
////��Ϊ�˷����Իᳬ��int, ��longlong �˸��ֽڣ�64λ 2��64�η�-1���