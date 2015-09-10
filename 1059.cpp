//找所有质数因子，输出
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct PF
{
	PF(int p)
	{
		prime = p;
		times = 1;
	}
	int prime;
	int times;
};
vector<PF> ans;
bool isPrime(int n)
{
	if (n == 1)
		return false;
	if (n == 2 || n == 3)
		return true;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
bool smaller(PF a, PF b)
{
	if (a.prime < b.prime)
		return true;
	return false;
}
int main()
{
	int N;
	cin >> N;
	int constN = N;
	if (isPrime(N))
	{
		ans.push_back(PF(N));
	}
	else
	{
		while(!isPrime(N))
		{
			for (int i = 2; i * i <= N;i++)
			{
				if (isPrime(i) && N % i == 0)
				{
					//i  « “ª∏ˆÀÿ ˝factor
					bool find = false;
					for (vector<PF>::iterator it = ans.begin(); it != ans.end(); it++)
					{
						if (it->prime == i)
						{
							find = true;
							it->times++;
							break;
						}
					}
					if(!find)
						ans.push_back(PF(i));
					N = N / i;
					i = 1;
				}
				if (isPrime(N))
				{
					//i  « “ª∏ˆÀÿ ˝factor
					bool find = false;
					for (vector<PF>::iterator it = ans.begin(); it != ans.end(); it++)
					{
						if (it->prime == N)
						{
							find = true;
							it->times++;
							break;
						}
					}
					if(!find)
						ans.push_back(PF(N));
					break;
				}	
			}
		}
	}
	
	sort(ans.begin(),ans.end(),smaller);
	cout << constN << "=";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].prime;
		if (ans[i].times > 1)
		{
			cout << "^" << ans[i].times;
		}
		if (i < ans.size() - 1)
			cout << "*";
	}
}


//’‚∏ˆÀŸ∂»øÏ£¨≤ªƒ‹”√isPrime »•≈–∂œ2147483647
//#include<cstdio>
//#include<iostream>
//#include<cstring>
//#include<cmath>
//#include<string>
//#include<vector>
//#include<map>
//#include<set>
//#include<algorithm>
//#include<sstream>
//using namespace std;
//bool isPrime(int x)
//{
//    int len=sqrt(x)+1;
//    for(int i=3;i<=len;++i)
//    {
//        if(x%i==0)
//            return false;
//    }
//    return true;
//}
//int main()
//{
//    int n,len;
//    scanf("%d",&n);
//    printf("%d=",n);
//    if(n==1)
//    {
//        printf("1\n");
//    }
//    else
//    {
//        len=n;
//        for(int i=2,j;i<=len;++i)
//        {
//            j=0;
//            if(isPrime(i))
//            {
//                for(;n%i==0;)
//                {
//                    n/=i;
//                    ++j;
//                }
//            }
//            if(j>1)
//                printf("%d^%d",i,j);
//            else if(j==1)
//                printf("%d",i);
//            if(n>1&&j>0)
//                printf("*");
//            if(n==1)
//                break;
//        }
//    }
//    return 0;
//}
