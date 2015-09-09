//10 进制转 13进制
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int r,g,b;
    cin>>r>>g>>b;
    
    vector<int> ivec;
    ivec.push_back(r/13);
    ivec.push_back(r%13);
    ivec.push_back(g/13);
    ivec.push_back(g%13);
    ivec.push_back(b/13);
    ivec.push_back(b%13);
    
    cout<<"#";
    for(int i=0;i<6;i++){
        if(ivec[i]<10)
            cout<<ivec[i];
        else 
            cout<<char(ivec[i]-10+'A');
    }
    return 0;
}