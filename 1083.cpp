/* struct sort 2015.7.30cyq*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

//ifstream fin("case1.txt");
//#define cin fin

struct stu{
    string name;
    string id;
    int score;
};

bool cmp(const stu &a,const stu &b){
    return a.score>b.score;
}
int main(){
    int N;
    cin>>N;
    vector<stu> stus(N);
    for(int i=0;i<N;i++){
        cin>>stus[i].name>>stus[i].id>>stus[i].score;
    }
    sort(stus.begin(),stus.end(),cmp);
    int low,high;
    cin>>low>>high;
    vector<stu> result;
    for(int i=0;i<N;i++){
        if(stus[i].score>=low&&stus[i].score<=high)
            result.push_back(stus[i]);
    }
    if(result.empty())
        cout<<"NONE";
    else{
        for(auto it=result.begin();it!=result.end();++it)
            cout<<(*it).name<<" "<<(*it).id<<endl;
    }
    return 0;
}