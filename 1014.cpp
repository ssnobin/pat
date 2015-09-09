/*
 排队模拟题， 别人的写得比我好感觉，用int来表示时间，stringstream可以<<字符串，也可以<<int
 */
#include <iostream>
#include <cstring>
using namespace std;
#define maxn 25
#define maxm 12
#define maxk 1005
#define maxq 1005
int A[maxm][maxn],N,M,K,Q,transaction[maxk],question[maxq];
typedef struct mytime
{
public:
    mytime(){
        HH = 0;
        MM = 0;
    };
    mytime(int a,int b)
    {
        HH = a;
        MM = b;
    };
    int HH;
    int MM;
}mytime;
mytime res[maxk];
void addOneMinute(mytime & t)
{
    t.MM++;
    if (t.MM==60)
    {
        t.MM = 0;
        t.HH++;
    }
};
bool timeequal(mytime t1, mytime t2)
{
    if (t1.HH == t2.HH && t1.MM == t2.MM)
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> N >> M >> K >> Q;
    memset(A,0,sizeof(int)*maxn*maxm);
    mytime t(8,0),endTime(17,0);
    for (int i = 0; i < K; i++)
    {
        cin >> transaction[i+1];
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> question[i+1];
    }
    int customerIndex = 1,waitIndex = 0;
    bool full = false;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            A[i][j] = customerIndex;
            customerIndex++;
            if (customerIndex > K)
            {
                full = true;
                break;
            }
        }
        if (full)
        {
            break;
        }
    }
    if (N * M < K)
    {
        waitIndex = N * M + 1;
    }
    while(1)
    {
        addOneMinute(t);
        for (int i = 1; i <= N; i++)
        {
            int currCustom = A[1][i];
            if (currCustom == 0)
                continue;
            transaction[currCustom]--;
            if (transaction[currCustom] <= 0)
            {
                for (int j = 1; j <= M-1; j++)
                {
                    A[j][i] = A[j+1][i];
                }
                A[M][i] = 0;//ø’≥ˆ¿¥“ª∏ˆŒª÷√
                if (waitIndex > 0 && waitIndex <= K)
                {
                    A[M][i] = waitIndex;
                    waitIndex++;
                }
                res[currCustom] = t;
            }
        }
        if (timeequal(t,endTime))
        {
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= M; j++)
                {
                    int remain = A[j][i];
                    if (A[j][i] > 0)
                    {
                        //ªπ‘⁄transactionµƒ
                        if (i == 1)
                        {
                            res[remain] = endTime;
                        }
                        else
                        {
                            res[remain].HH = -1;
                            res[remain].MM = 0;//not served
                        }
                    }
                }
            }
            if(waitIndex > 0 &&waitIndex <= K)
            {
                res[waitIndex].HH = -1;
                res[waitIndex].MM = 0;//not served
            }
            break;
        }
    }
    for (int i = 1; i <= Q; i++)
    {
        int which = question[i];
        mytime & tmp = res[which];
        if (timeequal(tmp,mytime(-1,0)))
        {
            cout << "Sorry" << endl;
            continue;
        }
        if (tmp.HH < 10)
            cout << 0;
        cout << tmp.HH << ":";
        if (tmp.MM < 10)
            cout << 0;
        cout << tmp.MM <<endl;
    }
}

///*2015.7.20cyq*/
//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//#include <fstream>
//#include <sstream>
//using namespace std;
//
////ifstream fin("case1.txt");
////#define cin fin
//
//string intToString(int n,int t){
//    if(n-t>=540)//结束服务的时间减服务时间，即开始服务的时间
//        return "Sorry";
//    stringstream ss;
//    string s;
//    int h=n/60+8;
//    int m=n%60;
//    if(h<10)
//        ss<<"0";//补零
//    ss<<h<<":";
//    if(m<10)
//        ss<<"0";
//    ss<<m;
//    ss>>s;
//    return s;
//}
//
//const int MAX=2147483647;
//int main(){
//    int N,M,K,Q;
//    cin>>N>>M>>K>>Q;
//    vector<queue<pair<int,int> > > q(N);//N个窗口，记录顾客时间和序号
//    vector<int> custime;
//    int x;
//    for(int i=0;i<K;i++){//K个顾客的服务时间，这里从0开始编号
//        cin>>x;
//        custime.push_back(x);
//    }
//
//    int cusNum;
//    for(cusNum=0;cusNum<M*N&&cusNum<K;cusNum++)//队列长度为M，窗口为N，最初的顾客入队
//        q[cusNum%N].push(make_pair(custime[cusNum],cusNum));
//    
//    vector<int> qtime(N,0);//每个窗口的当前时间，初始化为0
//    vector<int> result(K);//K个顾客结束服务的时间
//    
//    int count=0;
//    int quickWindow;
//    int quickTime;
//    while(count<K){
//        quickTime=MAX;
//        for(int i=0;i<N;i++){//检测哪个窗口最快
//            if(!q[i].empty()){
//                if(qtime[i]+q[i].front().first<quickTime){
//                    quickTime=qtime[i]+q[i].front().first;
//                    quickWindow=i;
//                }
//            }
//        }
//        int tmp=q[quickWindow].front().first+qtime[quickWindow];
//        result[q[quickWindow].front().second]=tmp;//更新结果
//        qtime[quickWindow]=tmp;//更新最快窗口的当前时间
//        q[quickWindow].pop();
//        if(cusNum<K)//新顾客排队
//            q[quickWindow].push(make_pair(custime[cusNum],cusNum));
//        cusNum++;
//        count++;
//    }
//    
//    while(Q--){
//        cin>>x;
//        cout<<intToString(result[x-1],custime[x-1])<<endl;
//    }
//    return 0;
//}