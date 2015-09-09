/*
 从根节点开始，广度优先遍历，输出每一层的叶子节点数量
 有两种方法来分层，一种是只有一个队列，在队列里面塞入分层的flag
 第二种是有两个队列，一个用来遍历，一个用来临时储存。。
 */
//cur.push(1);
//while(!cur.empty()){
//    int count=0;
//    while(!cur.empty()){
//        int root=cur.front();
//        cur.pop();
//        if(tree[root].empty())//无子结点，说明root为叶子结点
//            count++;
//        for(auto it=tree[root].begin();it!=tree[root].end();it++){
//            next.push(*it);
//        }
//    }
//    result.push_back(level);
//    swap(cur,next);//next 会被清空？嗯，因为cur是空的，所以交换
//}
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int N,M;
struct Node
{
    Node():k(-1),isInNode(false){}
    Node(bool isIn):isInNode(isIn),k(0){}
    //char index[5]; //就成功了。。奇怪
    string index; //会有一个段错误   i don't know why，其实可以用int类型来保存index，因为01 是 1
    int k;//-1表示分割符号，分割每层
    //char (*child)[5];
    vector<string> child;
    bool isInNode;
};
map<string,Node> m;
queue<Node> q;
vector<int> vec;
int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        Node inNode;
        cin >> inNode.index >> inNode.k;
        //inNode.child = new char[inNode.k][5];
        for (int i = 0; i < inNode.k; i++)
        {
            string tmp;
            cin >> tmp;
            inNode.child.push_back(tmp);
            //cin >> inNode.child[i];
        }
        inNode.isInNode = true;
        m.insert(pair<string, Node>(inNode.index, inNode));
    }
    map<string, Node>::iterator it = m.find("01");
    q.push(it->second);
    q.push(Node());
    int count = 0;
    while(!q.empty())
    {
        Node node = q.front();
        q.pop();
        if (node.k == -1)
        {
            vec.push_back(count);
            count = 0;
            if (!q.empty())
                q.push(Node());
            continue;
        }
        else if (node.isInNode == false)
        {
            count++;
            continue;
        }
        for (int i = 0; i < node.k; i++)
        {
            it = m.find(node.child[i]);
            if (it != m.end())
            {
                //内部节点
                q.push(it->second);
            }
            else
            {
                //leaf
                q.push(Node(false));
            }
        }
    }
    for (int i = 0; i < vec.size() - 1; i++)
        cout << vec[i] << " ";
    cout << vec[vec.size()-1] << endl;
}