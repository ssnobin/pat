//模拟栈,求栈中中间大的数
//树状数组
//或者是用multiset， 由于要O(1)输出栈的中位数，想到利用set的自动排序，将栈中的元素都哈希到set。如果题目条件保证栈中元素不重复，只用一个set辅助即可，set最中间的元素即为中位数。由于栈中元素可能重复，所以用两个multiset进行辅助，set1存储小于等于当前中位数mid的，set2存储大于mid的，set1中最大的数即为mid。set1的大小必须与set2相等(栈的大小为偶数），或多1（栈的大小为奇数），这是平衡态。每次栈push或者pop后，调整两个set平衡，重新计算mid。
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100005
int stack[MAXN], c[MAXN], top = 0;
int lowbit(int x)
{
	return x & (-x);
};
void modify(int pos, int delta)
{
	while (pos < MAXN)
	{
		c[pos] += delta;
		pos += lowbit(pos);
	}
};
int sum(int pos)
{
	int s = 0;
	while (pos > 0)
	{
		s += c[pos];
		pos -= lowbit(pos);
	}
	return s;
};
//int findIndex(int n)
//{
//	int l = 1, r = MAXN - 1;
//	while (l < r)
//	{
//		int med = (l + r) / 2;
//		int s = sum(med);
//		if (s >= n)
//		{
//			r = med;
//		}
//		else
//		{
//			l = med + 1;
//		}
//	}
//	return l;
//};

int findIndex(int x)        // binary search to find first x
{
	int low = 0, high = MAXN - 1, mid;
	while(low < high)
	{
		mid = (low + high) / 2;
		int s = sum(mid);
		if (s >= x)
		{
			high = mid;
		}else
			low = mid + 1;
	}
	return high;
};
//int findMedian()
//{
//	int * arr = new int[top + 1];
//	
//	for (int i = 0; i < top + 1; i++)
//	{
//		arr[i] = stack[i];
//	}
//	sort(arr,arr + top + 1);
//	return arr[(top + 1 - 1) / 2];
//}

int main()
{
	int N,tmp;
	cin >> N;
	memset(c, 0, MAXN * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		char command[11];
		//cin >> command;
		scanf("%s", command);
		switch (command[1])
		{
			case 'u':      // push
				top++;
				scanf("%d", &tmp);
				//cin >> stack[top];
				stack[top] = tmp;
				modify(stack[top], 1);
				break;
			case 'o':      // pop
				if (top == 0)
				{
					//cout << "Invalid" << endl;
					printf("Invalid\n");
				}
				else
				{
					//cout << stack[top] << endl;
					printf("%d\n", stack[top]);
					modify(stack[top], -1);
					top--;
				}
				break;
			case 'e':      // peekMedian
				if (top == 0)
				{
					//cout << "Invalid" << endl;
					printf("Invalid\n");
				}
				else
				{
					//cout << findIndex((top + 1) / 2) << endl;
					printf("%d\n",findIndex((top + 1) / 2));
				}
				break;
		};
	}
}

//cin cout ª·≥¨ ±£¨Œ“»’∞°

