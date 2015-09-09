/*
 判断连通图的内部节点数量大于2，并且内部边的和大于一个阈值， 并且输出节点（从此节点发出的边的和最大）
 有用并查集的，不需要dfs。。不熟悉QAQ
 */

#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define maxInt 0x3fffffff
#define maxn 1005
using namespace std;
int N,K,totalP = 0;//number of phone calls and threshold
map<string, int> mapNameIndex;
int edges[maxn][maxn];
bool visit[maxn];
int totalDegree[maxn];
struct ans
{
    int countN;
    string head;
};
vector<ans> res;
bool bigger(ans a,ans b)
{
    if (a.head < b.head)
        return true;
    return false;
}
int getIndex(string s)
{
    map<string, int>::iterator it = mapNameIndex.find(s);
    if (it == mapNameIndex.end())
    {
        totalP++;
        mapNameIndex[s] = totalP;
        return totalP;
    }
    else
    {
        return it->second;
    }
}
void dfs(int i, int & c, int & s)
{
    c++;
    visit[i] = true;
    int iTotal = 0;
    for (int j = 1; j <= totalP; j++)
    {
        if (edges[i][j] < maxInt && !visit[j])
        {
            s += edges[i][j];
            iTotal += edges[i][j];
            dfs(j,c,s);
        }
        else if (edges[i][j] < maxInt)
        {
            s += edges[i][j];
            iTotal += edges[i][j];
        }
    }
    totalDegree[i] = iTotal;
}
int main()
{
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            edges[i][j] = maxInt;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        string a,b;
        int len;
        cin >> a >> b >> len;
        int aIndex = getIndex(a),bIndex = getIndex(b);
        if (edges[aIndex][bIndex] < maxInt)
            edges[aIndex][bIndex] += len;
        else
            edges[aIndex][bIndex] = len;
        if (edges[bIndex][aIndex] < maxInt)
            edges[bIndex][aIndex] += len;
        else
            edges[bIndex][aIndex] = len;
    }
    int gangCount = 0;
    memset(visit, false, maxn * sizeof(bool));
    for (int i = 1; i <= totalP; i++)
    {
        memset(totalDegree, 0, maxn * sizeof(int));
        int countNum = 0, sum = 0;//sum is double calculate
        if (!visit[i])
            dfs(i,countNum,sum);
        if (countNum > 2)
        {
            if (sum / 2 > K)
            {
                //gang
                gangCount++;
                //find head
                int maximum = 0, maxi = 0;
                for (int j = 1; j <= totalP; j++)//
                {
                    if (totalDegree[j] > maximum)
                    {
                        maximum = totalDegree[j];
                        maxi = j;
                    }
                }
                ans a;
                a.countN = countNum;
                map<string, int>::iterator it = mapNameIndex.begin();
                while (it != mapNameIndex.end())
                {
                    if (it->second == maxi)
                    {
                        a.head = it->first;
                        break;
                    }
                    it++;
                }
                res.push_back(a);
            }
        }
    }
    
    sort(res.begin(),res.end(),bigger);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].head << " " << res[i].countN << endl;
    }
}
//one testcase 段错误
