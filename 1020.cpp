/* 
 后序中序求树的层次遍历，先根据后序中序，建数（递归），再层次遍历，用queue
 */
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

//ifstream fin("case1.txt");
//#define cin fin

struct TNode{
    int val;
    TNode* left;
    TNode* right;
    TNode(int x):val(x),left(nullptr),right(nullptr){}
};
//利用给定的两个序列递归建树
TNode* recur(const vector<int> &post,const vector<int> &in,int pb,int pe,int ib,int ie){
    if(pb>pe)
        return nullptr;
    TNode* root=new TNode(post[pe]);
    int mid=ib;
    while(in[mid]!=root->val)
        mid++;
    int lt=mid-ib;//左子树结点数
    
    root->left=recur(post,in,pb,pb+lt-1,ib,mid-1);
    root->right=recur(post,in,pb+lt,pe-1,mid+1,ie);
    
    return root;
}

vector<int> levelOrder(TNode* root){
    vector<int> result;
    if(root==nullptr)
        return result;
    queue<TNode*> cur,next;
    cur.push(root);
    while(!cur.empty()){
        while(!cur.empty()){
            TNode* tmp=cur.front();
            cur.pop();
            result.push_back(tmp->val);
            if(tmp->left!=nullptr)
                next.push(tmp->left);
            if(tmp->right!=nullptr)
                next.push(tmp->right);
        }
        swap(cur,next);
    }
    return result;
}

int main(){
    int N;
    cin>>N;
    vector<int> post,in;
    int x;
    for(int i=0;i<N;i++){
        cin>>x;
        post.push_back(x);
    }
    for(int i=0;i<N;i++){
        cin>>x;
        in.push_back(x);
    }
    TNode* root=recur(post,in,0,N-1,0,N-1);
    vector<int> result=levelOrder(root);
    
    cout<<result[0];
    for(auto it=result.begin()+1;it!=result.end();++it)
        cout<<" "<<*it;
    return 0;
}