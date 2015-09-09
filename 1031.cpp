//字符串打印，n1=n3=(n+2)/3。
//让三边均分，多余的放在底边。
// 字符串输出U形状
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    int n1=(n+2)/3;
    int n3=n1;
    int n2=n-n1-n3;//一行中间的空格数
    for(int i=0;i<n1-1;i++){
        cout<<s[i];
        for(int j=1;j<=n2;j++)
            cout<<" ";
        cout<<s[n-1-i]<<endl;
    }
    for(int j=0;j<n2+2;j++){
        cout<<s[n1-1+j];
    }
    return 0;
}