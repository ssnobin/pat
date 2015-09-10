/*2015.7.26cyq 使用一个stack模拟操作，看是否能得到所给序列。*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int check(const vector<int> &ivec,int M,int N){
    stack<int> stk;
    int i=0;//给定的序列的索引
    int j=1;//用来压入的数字
    while(1){
        //持续压入数字直到stk.top()==ivec[i]
        while(stk.empty()||stk.top()!=ivec[i]){
            stk.push(j++);
            if(stk.size()==M){//栈满
                if(stk.top()==ivec[i]){
                    stk.pop();
                    i++;
                    if(i==N){
                        if(stk.empty())
                            cout<<"YES"<<endl;
                        else
                            cout<<"NO"<<endl;
                        return 0;
                    }
                }else{
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
        
        if(!stk.empty()){//弹出栈顶匹配数字
            stk.pop();
            i++;
        }
        
        if(i==N&&stk.empty()){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    return 0;
}

int main(){
    int M,N,K;
    cin>>M>>N>>K;
    vector<int> ivec(N);
    while(K--){
        for(int i=0;i<N;i++)
            cin>>ivec[i];
        check(ivec,M,N);
    }
    return 0;
}