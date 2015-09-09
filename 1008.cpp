/*
 数电梯上升下降层数就好了
 */
#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int up=0;
    int down=0;
    int pre=0;//起点
    int cur;
    for(int i=1;i<=N;i++){
        cin>>cur;
        if(cur>pre)
            up+=cur-pre;
        if(cur<pre)
            down+=pre-cur;
        pre=cur;
    }
    cout<<up*6+down*4+N*5;
    return 0;
}