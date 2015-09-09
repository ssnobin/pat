/*
 结构体排序，重载操作符< 
 也可以写个比较函数
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

//ifstream fin("case1.txt");
//#define cin fin

struct stu{
    string id;		//id
    int score;		//分数
    int finalRank;	//总排名
    int locationNum;//考场号
    int localRank;	//考场排名
    stu(string ID,int sco,int fr,int ln,int lr):id(ID),score(sco),finalRank(fr),
    locationNum(ln),localRank(lr){}
    
    bool operator < (const stu &a)const{
        if(score>a.score)
            return true;
        else if(score==a.score&&id<a.id)
            return true;
        
        return false;
    }
};

int main(){
    int N,K;
    cin>>N;
    vector<vector<stu> > r(N);//r[i]表示i-1号考场
    string id;
    int sco;
    for(int i=0;i<N;i++){
        cin>>K;
        for(int j=1;j<=K;j++){
            cin>>id>>sco;
            r[i].push_back(stu(id,sco,0,i+1,0));
        }
        sort(r[i].begin(),r[i].end());
        
        int rank=1;
        r[i][0].localRank=1;
        for(int j=1;j<K;j++){
            if(r[i][j].score<r[i][j-1].score){//新的分数，更新排名，否则并列
                rank=j+1;
            }
            r[i][j].localRank=rank;
        }
    }
    vector<stu> result;
    for(auto it=r.begin();it!=r.end();it++){
        for(auto itt=(*it).begin();itt!=(*it).end();itt++){
            result.push_back(*itt);
        }
    }
    sort(result.begin(),result.end());
    int len=result.size();
    int rank=1;
    result[0].finalRank=1;
    for(int i=1;i<len;i++){
        if(result[i].score<result[i-1].score)
            rank=i+1;
        result[i].finalRank=rank;
    }
    cout<<len<<endl;
    for(int i=0;i<len;i++){
        cout<<result[i].id<<" "<<result[i].finalRank<<" "<<result[i].locationNum<<" "<<result[i].localRank<<endl;
    }
    return 0;
}
