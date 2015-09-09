//
//  D.cpp
//  hello world
//
//  Created by Wu bin on 15/9/9.
//  Copyright (c) 2015年 Wu bin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define maxn 105
int tree[maxn][3];//0 key 1 left 2 right
int arr[maxn];
int N;
vector<int> seq,ans;
queue<int> q;
void inOrder(int x)
{
    if (x==-1)
        return;
    inOrder(tree[x][1]);
    seq.push_back(x);
    inOrder(tree[x][2]);
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a,b;
        cin >> a >> b;
        tree[i][1] = a;
        tree[i][2] = b;
    }
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr,arr+N);
    inOrder(0);
    for (int i = 0; i < seq.size(); i++)
    {
        tree[seq[i]][0] = arr[i];
    }
    //fulfill then..
    q.push(0);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        ans.push_back(tree[cur][0]);
        if (tree[cur][1] != -1)
        {
            q.push(tree[cur][1]);
        }
        if (tree[cur][2] != -1)
        {
            q.push(tree[cur][2]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0)
            cout << ans[i];
        else
            cout << " " << ans[i];
    }
    cout << endl;
}
