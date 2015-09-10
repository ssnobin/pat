//hash 二次探测法： hi=(h(key)+i*i)％m 0≤i≤m-1
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int MSize,N;
bool isPrime(int x)
{
	if (x == 1)
		return false;
	if (x == 2 || x == 3)
		return true;
	int i = 2;
	while( i*i <= x)
	{
		if ( x % i == 0)
		{
			return false;
		}
		i++;
	}
	return true;
}
int getBiggerPrime(int x)
{
	while (!isPrime(x))
	{
		x++;
	}
	return x;
}
int myHash(int x)
{
	return x % MSize;
}
int main()
{
	cin >> MSize >> N;
	MSize = getBiggerPrime(MSize);
	int * arr = new int[MSize];
	memset(arr,0,MSize*sizeof(int));
	while(N--)
	{
		int tmp,i=0;
		cin >> tmp;
		int address = myHash(tmp);
		while(arr[(address+i*i)%MSize] != 0)
		{
			i++;
			if (i >= MSize/2)//j > MSize/2
			{
				break;
			}
		}
		if (i < MSize)
		{
			arr[(address+i*i)%MSize] = tmp;
			cout << (address+i*i) % MSize << (N == 0 ? "\n" : " ");
			//ans.push_back(address % MSize);
		}
		else
		{
			cout << "-" << (N == 0 ? "\n" : " ");
		}
	}
}