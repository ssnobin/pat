/*结构体排序*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

//ifstream fin("case1.txt");
//#define cin fin

struct stu{
    string name;
    string mf;
    string id;
    int score;
};
bool cmp(const stu &x,const stu &y){
    if(x.mf=="F"&&y.mf=="M")
        return true;
    else if(x.mf=="F"&&y.mf=="F"||x.mf=="M"&&y.mf=="M")
        return x.score>y.score;
    
    return false;
}
int main(){
    int N;
    cin>>N;
    vector<stu> a(N);
    for(int i=0;i<N;i++){
        cin>>a[i].name>>a[i].mf>>a[i].id>>a[i].score;
    }
    sort(a.begin(),a.end(),cmp);
    bool noF=false;
    bool noM=false;
    if(a[0].mf!="F")
        noF=true;
    if(a[N-1].mf!="M")
        noM=true;
    if(noF){
        cout<<"Absent"<<endl;
        if(noM)
            cout<<"Absent"<<endl;
        else
            cout<<a[N-1].name<<" "<<a[N-1].id<<endl;
        cout<<"NA"<<endl;
    }else{
        cout<<a[0].name<<" "<<a[0].id<<endl;
        if(noM){
            cout<<"Absent"<<endl;
            cout<<"NA"<<endl;
        }else{
            cout<<a[N-1].name<<" "<<a[N-1].id<<endl;
            cout<<a[0].score-a[N-1].score<<endl;
        }
    }
    return 0;
}