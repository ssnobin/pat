//都排好序了，数数就好了，数到中间那个数
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	int n,m,index = 0,count = 0,res;
	int tmp,tmp2;
	cin >> n;
	vector<int> vec1,vecFinal,vec2;
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&tmp);
		vec1.push_back(tmp);
	}
	vec1.push_back(0x7fffffff);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d",&tmp);
		while(vec1[index] <= tmp)
		{
			index++;
			count++;
			if (count == (n+m+1)/2)
			{
				res = vec1[index - 1];
			}
		}
		count++;
		if (count == (n+m+1)/2)
		{
			res = tmp;
		}
	}
	//vec2.push_back(0x7fffffff);

	//int i = 0, j = 0, med = (n + m - 1) / 2, count = 0;//med = (n + m - 1) >> 1
	//while (count != med)
	//{
	//	if (vec1[i] < vec2[j])
	//	{
	//		i++;
	//	}
	//	else
	//	{
	//		j++;
	//	}
	//	count++;
	//}
	//if(vec1[i]<vec2[j])
 //       printf("%d\n",vec1[i]);
 //   else
 //       printf("%d\n",vec2[j]);

	printf("%d\n", res);
}