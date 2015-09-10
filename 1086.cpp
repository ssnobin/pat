/*2015.7.30cyq*/
//注意到如果将pop看成数的空结点的话，输入用例只要在后面再加一个pop，该序列就与树的先序遍历一样。
//我们可以用0表示空结点，则先根遍历序列转换为1,2,3,0,0,4,0,0,5,6,0,0,0，利用该序列先根遍历创建树即可。
//还有直接根据输入来建树的，diao
//Node * buildTree()
//{
//    Node * r=NULL;
//    int tmp=0;
//    if(ids<2*n)
//    {
//        scanf("%s",input);
//        if(input[1]=='u')
//        {
//            scanf("%d",&tmp);
//            r = new Node(tmp);
//            ids++;
//        }else if(input[1]=='o')
//        {
//            ids++;
//            return NULL;
//        }
//        r->left = buildTree();
//        r->right = buildTree();
//    }
//    return r;
//}
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//ifstream fin("case1.txt");
//#define cin fin

struct TNode{
    int val;
    TNode *left;
    TNode *right;
    TNode(int x):val(x),left(nullptr),right(nullptr){}//构造函数
};
//根据数组先根遍历创建树
void createTree(TNode *&root,const vector<int> &ivec,int &cur){
    if(ivec[cur]==0){
        cur++;
    }else{//root指针指向一个new的结点，左右子结点先置为nullptr
        root=new TNode(ivec[cur]);
        cur++;
        createTree(root->left,ivec,cur);
        createTree(root->right,ivec,cur);
    }
}
//后序遍历
void postOrder(TNode *root,vector<int> &result){
    if(root!=nullptr){
        postOrder(root->left,result);
        postOrder(root->right,result);
        result.push_back(root->val);
    }
}
int main(){
    int N;
    cin>>N;
    vector<int> ivec;
    string s;
    int x;
    for(int i=0;i<2*N;i++){
        cin>>s;
        if(s=="Push"){
            cin>>x;
            ivec.push_back(x);
        }else
            ivec.push_back(0);//0表示null结点
    }
    ivec.push_back(0);//最后一个null结点
    
    TNode *root=nullptr;
    int cur=0;
    createTree(root,ivec,cur);
    
    vector<int> result;
    postOrder(root,result);
    
    cout<<result[0];
    for(auto it=result.begin()+1;it!=result.end();it++)
        cout<<" "<<*it;
    return 0;
}