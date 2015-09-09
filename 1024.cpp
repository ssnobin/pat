//字符翻转，相加，判断是否回文
//模拟加法
#include <iostream>
#include <cstring>
using namespace std;
char ch[1005];
void add(char * b)
{
	int up = 0;
	for(int i = strlen(b) - 1; i >= 0; i--)
	{
		int tmp = ch[i] + b[i] - 96 + up;
		char here = '0' + tmp % 10;
		//cout << here << endl;
		up = tmp / 10;
		ch[i] = here;
	}
	if (up == 0)
		return;
	for(int i = strlen(b); i >= 1; i--)
	{
		ch[i] = ch[i-1];
	}
	ch[0] = '0' + up;
};
bool palin(char * a)
{
	int i = 0, j = strlen(a) - 1;
	while (i < j)
	{
		if (a[i] != a[j])
			return false;
		i++;
		j--;
	}
	return true;
};
char * reverse(char * a)
{
	int n = strlen(a);
	char * ans = new char[n];
	for (int i = 0; i < n; i++)
	{
		ans[i] = a[n-1-i];
	}
	ans[n] = '\0';
	//cout << ans << endl;
	return ans;
};
int main()
{
	int times;
	cin >> ch;
	cin >> times;
	int i = 0;
	while(i < times && !palin(ch))
	{
		char * cpy = new char[strlen(ch)];
		strcpy(cpy, ch);
		//cpy = strrev(cpy);
		cpy = reverse(cpy);
		add(cpy);
		i++;
	}
	cout << ch << endl;
	cout << i << endl;
}