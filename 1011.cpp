/* 
 简单题，保留两位小数点后输出
 */
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


//ifstream fin("case1.txt");
//#define cin fin


double findMax(double a,double b,double c){
    if(a>b)
        return a>c ? a : c;
    else
        return b>c ? b : c;
    return -1;
}


int main(){
    double result=1.0;
    double w,t,l;
    while(cin>>w>>t>>l){
        double tmp=findMax(w,t,l);
        result*=tmp;
        if(tmp==w)
            cout<<"W ";
        else if(tmp==t)
            cout<<"T ";
        else if(tmp==l)
            cout<<"L ";
        else
            return 0;
    }
    result=(result*0.65-1)*2;
    printf("%0.2f",result);
    return 0;
}