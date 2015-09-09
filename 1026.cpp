
#include <stdio.h>
//模拟队列。copy 代码
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

struct VIPdata{//vip队列
    int starts;
    int startget;
    int lasts;
    int VIP;
    int id;
    
    friend bool operator <(VIPdata x,VIPdata y){
        if(x.VIP==y.VIP)
            return x.starts>y.starts;
        else
            return x.VIP<y.VIP;
    }
}s[10099];

struct Ordata{//普通队列
    int starts;
    int startget;
    int lasts;
    int VIP;
    int id;
    Ordata(int a,int b,int c,int d,int e){
        starts=a;startget=b;lasts=c;VIP=d;id=e;
    }
    friend bool operator <(Ordata x,Ordata y){
        return x.starts>y.starts;
    }
};

int ifplay[10999];//某人是否已经玩过

int cmp(VIPdata x,VIPdata y){
    return x.starts<y.starts;
}

struct Table{
    int ifuse;
    int end;
    int vip;
    int useNum;
}table[109];

int main(){
    int n,tableNum,VipNum,PuNum;
    while(scanf("%d",&n)!=EOF){
        int i,hh,mm,ss,j;
        for(i=1;i<=n;i++){
            ifplay[i]=0;
            scanf("%d:%d:%d",&hh,&mm,&ss);
            s[i].starts=hh*3600+mm*60+ss;
            scanf("%d",&mm);
            if(mm>120)mm=120;//不要超过2个小时
            s[i].lasts=mm*60;
            scanf("%d",&s[i].VIP);
            s[i].id=i;
        }
        scanf("%d",&tableNum);
        scanf("%d",&VipNum);
        PuNum=tableNum-VipNum;
        
        for(i=1;i<=tableNum;i++){
            table[i].ifuse=0;
            table[i].end=0;
            table[i].vip=0;
            table[i].useNum=0;
        }
        int temp;
        for(i=1;i<=VipNum;i++){
            scanf("%d",&temp);
            table[temp].vip=1;
        }
        
        sort(&s[1],&s[1+n],cmp);
        //for(i=1;i<=n;i++){
        //    printf("%02d:%02d:%02d %d\n",s[i].starts/3600,(s[i].starts%3600)/60,s[i].starts%60,s[i].VIP);
        //}
        int first=8*3600,end=21*3600;
        int Vipnow=0,Punow=0;
        priority_queue<Ordata>Orqq;
        priority_queue<VIPdata>VIPqq;
        
        j=1;
        int k,x;
        for(i=first;i<end;i++){
            for(k=1;k<=tableNum;k++){//退台球桌
                if(table[k].ifuse==0)continue;
                if(table[k].end==i){
                    table[k].ifuse=0;
                    if(table[k].vip==1)Vipnow--;
                    else Punow--;
                    table[k].ifuse=0;
                }
            }
            
            //到点的人排队
            while(s[j].starts==i&&j<=n){
                Orqq.push(Ordata(s[j].starts,s[j].startget,s[j].lasts,s[j].VIP,s[j].id));
                VIPqq.push(s[j]);j++;
            }
            
            if((Vipnow+Punow)==tableNum)continue;
            for(k=Vipnow+1;k<=VipNum;k++){//排队中的人进台球桌 有VIP桌先满足VIP
                if(VIPqq.empty())break;
                if(VIPqq.top().VIP==0)break;
                
                while(!VIPqq.empty()&&ifplay[VIPqq.top().id]==1/*||(VIPqq.top().lasts+i)>end)*/){
                    VIPqq.pop();
                }if(VIPqq.empty())break;
                
                int rx=-1;
                for(x=1;x<=tableNum;x++){
                    if(table[x].ifuse==1)continue;
                    if(table[x].vip==0)continue;
                    rx=x;break;
                }if(rx==-1)break;
                
                printf("%02d:%02d:%02d",(VIPqq.top().starts/3600),(VIPqq.top().starts%3600)/60,VIPqq.top().starts%60);
                printf(" %02d:%02d:%02d",(i/3600),(i%3600)/60,i%60);
                printf(" %d\n",(i-VIPqq.top().starts+30)/60);//这里注意+30
                
                table[rx].end=VIPqq.top().lasts+i;
                table[rx].ifuse=1;
                table[rx].useNum++;
                Vipnow++;
                ifplay[VIPqq.top().id]=1;
                VIPqq.pop();
                
            }
            
            //排队中的人进台球桌 现在按普通队列排
            if((Vipnow+Punow)==tableNum)continue;
            for(k=1;k<=tableNum;k++){//普通人也可以玩VIP桌子
                if(Orqq.empty())break;
                
                while(!Orqq.empty()&&ifplay[Orqq.top().id]==1){
                    Orqq.pop();
                }if(Orqq.empty())break;
                
                int rx=-1;
                for(x=1;x<=tableNum;x++){
                    if(table[x].ifuse==1)continue;
                    rx=x;break;
                }if(rx==-1)break;
                
                printf("%02d:%02d:%02d",(Orqq.top().starts/3600),(Orqq.top().starts%3600)/60,Orqq.top().starts%60);
                printf(" %02d:%02d:%02d",(i/3600),(i%3600)/60,i%60);
                printf(" %d\n",(i-Orqq.top().starts+30)/60);//这里注意+30
                
                table[rx].end=Orqq.top().lasts+i;
                table[rx].ifuse=1;
                table[rx].useNum++;
                if(table[rx].vip==1)Vipnow++;
                else
                    Punow++;
                ifplay[Orqq.top().id]=1;
                Orqq.pop();
            }
        }
        int ok=0;
        for(i=1;i<=tableNum;i++){
            if(ok==0)ok=1;
            else printf(" ");
            printf("%d",table[i].useNum);
        }printf("\n");
    }
    return 0;
}