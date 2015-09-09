//先判断是不是连通图 dfs，不是输出有几个连通部件
//然后用所有的叶子节点，看最大的深度，输出最大的叶子节点
//others'
//使用并查集判断子图数目。
//若子图数为1，对每个结点进行dfs可得到最大深度的点。这种写法有一个case超时。
//为了避免大数据超时，只使用两次dfs，第一次对结点1进行dfs，得到一个候选结点集合tbd，第二次对候选结点集合中的随意一个结点进行dfs，得到第二个候选结点集合tbd1，对两个集合进行合并和去重即为结果。（事实上本题可以转换为：对于以1号结点为根的树，输出树中相距最远的两个结点，若有多个结果，将满足条件的结点从小到大输出。易知对根结点进行1次dfs，最深的叶子结点肯定是候选结点，若这些叶子结点分布在根结点的两个子树，则相互匹配；若这些叶子结点分布在根结点的同一颗子树，则其匹配的结点可能在根结点的另一棵子树，这就是原题进行第二次dfs的原因）

//并查集
//int findroot(vector<int> &root,int a){
//    if(root[a]!=a)
//        root[a]=findroot(root,root[a]);//路径压缩，将多跳后的根作为a的直接上级
//    return root[a];
//}
//int graphNum(const vector<vector<bool> > &edges,int N){
//    vector<int> root;
//    for(int i=0;i<=N;i++)
//        root.push_back(i);//一开始每个结点的根结点都是自身
//    int result=N; //最多有N个子图
//    for(int i=1;i<=N;i++){
//        for(int j=i+1;j<=N;j++){
//            if(edges[i][j]){
//                int ar=findroot(root,i);
//                int br=findroot(root,j);
//                if(ar!=br){//不在同一个子图
//                    result--;//该边使得子图数减一
//                    root[ar]=br;//连接两个子图
//                }
//            }
//        }
//    }
//    return result;
//}
#include <string.h>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#define maxn 10005
using namespace std;

bool visit[maxn];
typedef struct vNode
{
    int nodeNum;
    vNode * next;
}vNode;
typedef struct Graph
{
    int n,e;
    vNode adjlist[maxn];
};
Graph G;

typedef struct leafNumDepth
{
    int nodeNum;
    int depth;
};
vector<leafNumDepth> leaves;
deque<int> DQ;
bool bigger(const leafNumDepth & a, const leafNumDepth & b);//不能用引用，不然编译错误,可以常引用
void dfs(vNode * vn);
bool bigger(const leafNumDepth & a, const leafNumDepth & b)
{
    if (a.depth > b.depth)
        return true;
    else if (a.depth == b.depth)
    {
        if (a.nodeNum < b.nodeNum)
            return true;
    }
    return false;
};
void dfs(vNode * vn)
{
    visit[vn->nodeNum] = true;
    while (vn->next!=NULL)
    {
        if (!visit[vn->next->nodeNum])
            dfs(&G.adjlist[vn->next->nodeNum]);
        vn = vn->next;
    }
};
int main()
{
    int a, b, kComponets = 1;
    vNode * vn;
    cin >> G.n;
    G.e = G.n - 1;
    for (int i = 1; i <= G.n; i++)
    {
        G.adjlist[i].nodeNum = i;
        G.adjlist[i].next = NULL;
    }
    for (int i = 1; i <= G.e; i++)
    {
        cin >> a >> b;
        vn = new vNode();
        vn->nodeNum = b;
        vn->next = NULL;
        vNode * tmp;
        tmp = &G.adjlist[a];
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = vn;
        
        vn = new vNode();
        vn->nodeNum = a;
        vn->next = NULL;
        tmp = &G.adjlist[b];
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = vn;
    }
    memset(visit,false,maxn*sizeof(bool));
    vn = &G.adjlist[1];
    while(1)
    {
        dfs(vn);
        int preNodeNum = vn->nodeNum;
        for (int i = 1; i <= G.n; i++)
        {
            if (visit[i] == false)
            {
                vn = &G.adjlist[i];
                kComponets++;
                break;
            }
        }
        if (preNodeNum == vn->nodeNum)
            break;
    }
    if (kComponets > 1)
        cout << "Error: " << kComponets << " components" << endl;
    else if (G.n == 1)
    {
        cout << G.adjlist[1].nodeNum << endl;
    }
    else
    {
        for (int i = 1; i <= G.n; i++)
        {
            if (G.adjlist[i].next != NULL && G.adjlist[i].next->next == NULL)
            {
                leafNumDepth lnd;
                lnd.nodeNum = G.adjlist[i].nodeNum;
                lnd.depth = 0;
                leaves.push_back(lnd);
            }
        }
        for (int i = 0; i < leaves.size(); i++)
        {
            leafNumDepth & lnd = leaves[i];
            //广度优先遍历，计算深度
            memset(visit,false,maxn*sizeof(bool));
            int flag = -1,depth = 0;
            DQ.push_front(flag);
            DQ.push_front(lnd.nodeNum);
            while (!DQ.empty())
            {
                int top = DQ.front();
                DQ.pop_front();
                if (top == -1)
                {
                    depth++;
                    if (!DQ.empty())
                        DQ.push_back(top);
                    continue;
                }
                vn = &G.adjlist[top];
                visit[top] = 1;
                while(vn->next != NULL)
                {
                    if (!visit[vn->next->nodeNum])
                        DQ.push_back(vn->next->nodeNum);
                    vn = vn->next;
                }
            }
            lnd.depth = depth;
        }
        //depth
        sort(leaves.begin(),leaves.end(),bigger);
        int maxDepth = leaves[0].depth;
        for (int i = 0; i < leaves.size(); i++)
        {
            if (maxDepth > leaves[i].depth)
                break;
            else
            {
                if (i!=0)
                    cout << endl;
            }
            cout << leaves[i].nodeNum;
        }
    }
}
//要考虑只有一个节点的特殊情况