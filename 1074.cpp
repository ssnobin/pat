//模拟翻转链表
#include<iostream>
using namespace std;
#define maxn 100005
struct Node
{
	Node():address(0),data(0),next(0){}
	Node(int a,int d,int n)
	{
		address = a;
		data = d;
		next = n;
	}
	int address;
	int data;
	int next;
};
void swapNode(Node & a, Node & b)
{
	Node tmp = a;
	a = b;
	b = tmp;
}
Node nodes[maxn];
int main()
{
	int start, N, K;
	cin >> start >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> nodes[i].address;
		cin >> nodes[i].data;
		cin >> nodes[i].next;
	}
	int tmp = start;
	for (int i = 1; i < N; i++)
	{
		bool find = false;
		for (int j = i-1; j < N; j++)
		{
			if (nodes[j].address == tmp)
			{
				//swap nodes[i-1] nodes[j]
				find = true;
				swapNode(nodes[i-1],nodes[j]);
				tmp = nodes[i-1].next;
				break;
			}
		}
		if (!find)
		{
			N=i;
			break;
		}
	}
	for (int i = 0,j = 0; j < N && j < K && i+j < N; j++)
	{
		if (j == K - 1)
		{
			int lastAddress = nodes[i+j].next;
			for (int begin = i, end = i + j; begin < end; begin++,end--)
			{
				swapNode(nodes[begin],nodes[end]);
			}
			for (int begin = i; begin <= i + j - 1;begin++)
			{
				nodes[begin].next = nodes[begin+1].address;
			}
			nodes[i+j].next = lastAddress;
			i += K;
			j = 0;
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		printf("%05d %d %05d\n",nodes[i].address,nodes[i].data,nodes[i].next);
	}
	printf("%05d %d %d\n",nodes[N-1].address,nodes[N-1].data,nodes[N-1].next);
}

// ‰»Îø…ƒ‹≤ª÷π“ª∏ˆlink list