/*
int str2int(const string s1){
    stringstream ss;
    ss<<s1;
    int k;
    ss>>k;
    return k;
}

bool cmp(const string s1,const string s2){
    return s1+s2<s2+s1;
}
 关键在比较函数
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool smaller(string a, string b)
{
	int aLen = a.length();
	int bLen = b.length();
	int i = 0, j = 0;
	while (i < aLen && j < bLen)
	{
		if (a[i] < b[j])
		{
			return true;
		}
		else if (a[i] > b[i])
		{
			return false;
		}
		else
		{
			i++;
			j++;
		}
	}
	if (i == aLen)
	{
		for (i = 0; i < aLen; i++)
		{
			if (a[i] < b[j])
				return true;
			else if (a[i] > b[j])
				return false;
		}
	}
	else
	{
		for (j = 0; j < bLen; j++)
		{
			if (b[j] > a[i])
				return true;
			else if (b[j] < a[i])
				return false;
		}
	}
	return false;
}
int main()
{
	int n;
	cin >> n;
	vector<string> manyString;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		manyString.push_back(a);
	}
	sort(manyString.begin(), manyString.end(), smaller);
	bool flag = true;
	for (int i = 0; i < manyString.size(); i++)
	{
		while(flag && manyString[i].find('0', 0) == 0 && manyString[i].size())
		{
			manyString[i].erase(0, 1);
		}
		if (manyString[i].find('0' , 0)!=0 && manyString[i] != "")
		{
			flag = false;
		}
		cout << manyString[i];
	}
	if (flag == true)
	{
		cout << 0;
	}
}