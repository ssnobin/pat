/*洗牌数组，字符串替换*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//ifstream fin("case1.txt");
//#define cin fin

int main(){
    string a[54]={"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
        "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
        "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
        "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
        "J1","J2"};
    vector<string> data(a,a+54);
    int N;
    cin>>N;
    vector<int> index(54);//洗牌数组
    for(int i=0;i<54;i++)
        cin>>index[i];
    
    vector<string> tmp(54);
    while(N--){
        for(int i=0;i<54;i++){
            tmp[index[i]-1]=data[i];//映射到tmp数组
        }
        swap(tmp,data);
    }
    for(int i=0;i<53;i++)
        cout<<data[i]<<" ";
    cout<<data[53];
    return 0;
}