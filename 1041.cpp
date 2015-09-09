//find the first unique ， use set or array
#include <iostream>
#include <set>
using namespace std;
#define maxn 100005
int A[maxn];
set<int> s;
set<int> dupli;
int main()
{
	int N,preSize;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		preSize = s.size();
		s.insert(A[i]);
		if (s.size() == preSize)
		{
			dupli.insert(A[i]);
		}
	}
	bool find = false;
	for (int i = 0; i < N; i++)
	{
		if (dupli.find(A[i]) == dupli.end())
		{
			find = true;
			cout << A[i] << endl;
			break;
		}
	}
	if (!find)
	{
		cout << "None" << endl;
	}
}


#include<stdio.h>
int rcd[10008];
int num[100008];
int main(){
	int i,j,n;
	for(i=0;i<=10000;i++){
		rcd[i]=0;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
		rcd[num[i]]++;
	}
	for(i=0;i<n;i++){
		if(rcd[num[i]]==1){
			printf("%d\n",num[i]);
			break;
		}
	}
	if(i==n) printf("None\n");
	return 0;	
}