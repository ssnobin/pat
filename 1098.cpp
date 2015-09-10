//heap sort
#include <iostream>
using namespace std;
#define maxn 105
int A[maxn],B[maxn],C[maxn];
int N;
bool isSame(int * arr,int flag)
{
	if (flag == 1)
	{
		for (int i = 1; i <= N; i++)
		{
			if (arr[i] != B[i])
				return false;
		}
		return true;
	}
	else
	{
		for (int i = 0; i <= N-1; i++)
		{
			if (arr[i] != B[i+1])
				return false;
		}
		return true;
	}
}

struct heap
{
	int D[maxn];
	int length;
	void buildHead()
	{
		length = N;
		for (int i = 0; i < length; i++)
		{
			D[i] = A[i+1];
		}
		for (int i = length/2 - 1; i>=0; i--)
		{
			siftdown(i);
		}
	}
	void siftdown(int n)
	{
		if (isLeaf(n)||length==1)
			return;
		int lc = getleft(n);int rc = getright(n);
		int j = lc;
		if (rc < length)
		{
			if (D[rc] > D[lc])
			{
				j = rc;
			}
		}
		if ( D[j] > D[n])
		{
			swap(j,n);
		}
		siftdown(j);
	};
	void swap(int a,int b)
	{
		int tmp = D[a];
		D[a] = D[b];
		D[b] = tmp;
	}
	int getParent(int n)
	{
		return (n-1)/2;
	};
	int getleft(int n)
	{
		return 2*n+1;
	};
	int getright(int n)
	{
		return 2*n+2;
	};
	bool isLeaf(int n)
	{
		return n >= length/2 && n < length;
	};
	void removeMax()
	{
		swap(0,length - 1);
		length--;
		siftdown(0);
	}
}Heap;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i+1];
		C[i+1] = A[i+1];
		Heap.D[i] = A[i+1];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> B[i+1];
	}
	//insertion
	int flag = 0;
	for (int i = 2; i <= N; i++)
	{
		for (int j = i; j >= 2; j--)
		{
			if (C[j] < C[j-1])
			{
				int tmp = C[j];
				C[j] = C[j-1];
				C[j-1] = tmp;
			}
		}
		if (flag==1)
			break;
		if (isSame(C,1))
		{
			flag = 1;
			cout << "Insertion Sort" << endl;
		}
	}
	if (flag == 1)
	{
		for (int i = 1; i <= N - 1; i++)
		{
			cout << C[i] << " ";
		}
		cout << C[N] << endl;
	}
	else
	{
		//heap sort
		int flag = 0;
		Heap.buildHead();
		while (Heap.length > 1)
		{
			Heap.removeMax();
			if (flag == 1)
				break;
			if(isSame(Heap.D,2))
			{
				flag = 1;
				cout << "Heap Sort" << endl;
			}
		}
		if (flag == 1)
		{
			for (int i = 0; i < N-1; i++)
			{
				cout << Heap.D[i] << " ";
			}
			cout << Heap.D[N-1] << endl;
		}
	}
}