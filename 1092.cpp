/*hash 用一个哈希表记录目标串s2每个字符出现的次数。遍历待检测串s1，若字符命中，该字符在哈希表中的次数减一，命中次数与s2长度相等时输出YES。*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//ifstream fin("case2.txt");
//#define cin fin

int main(){
    string s1,s2;
    cin>>s1>>s2;
    vector<int> h(256,0);
    int n=s1.size();
    int m=s2.size();
    
    for(int i=0;i<m;i++)
        h[s2[i]]++;
    int miss=m;
    for(int i=0;i<n;i++){
        if(h[s1[i]]>0){
            h[s1[i]]--;
            miss--;
        }
    }
    if(miss==0){
        cout<<"Yes "<<n-m;
    }else{
        cout<<"No "<<miss;
    }
    return 0;
}