
// getline(cin,astring) istringstream >> unfamiliar.... getchar 那里也不懂。。 getline 前面得getchar？
// getchar 去掉回车
#include <stdio.h>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

struct Book{
    string id;
    string title;
    string author;
    vector<string> v;
    string publisher;
    string publish_year;
};
Book book[10005];
int cmp(Book a,Book b){
    return a.id<b.id;
}
int n,m;
int main(){
    scanf("%d",&n);getchar();
    string str,tmp;
    for(int i=0;i<n;i++){
        getline(cin,book[i].id);
        getline(cin,book[i].title);
        getline(cin,book[i].author);
        getline(cin,str);
        istringstream is(str);
        while(is>>tmp)
            book[i].v.push_back(tmp);
        getline(cin,book[i].publisher);
        getline(cin,book[i].publish_year);
    }
    
    sort(book,book+n,cmp);
    scanf("%d",&m);getchar();
    string search;
    for(int i=0;i<m;i++){
        bool res=false;
        getline(cin,search);
        cout<<search<<endl;
        int kind=search[0]-'0';
        int len=search.length();
        string compare=search.substr(3,len-3);
        if(kind==1){
            for(int j=0;j<n;j++){
                if(book[j].title==compare){
                    res=true;
                    cout<<book[j].id<<endl;
                }
            }
        }else if(kind==2){
            for(int j=0;j<n;j++){
                if(book[j].author==compare){
                    res=true;
                    cout<<book[j].id<<endl;
                }
            }
        }else if(kind==3){
            for(int j=0;j<n;j++){
                for(int k=0;k<book[j].v.size();k++){
                    if(book[j].v[k]==compare){
                        res=true;
                        cout<<book[j].id<<endl;
                    }
                }
            }
        }else if(kind==4){
            for(int j=0;j<n;j++){
                if(book[j].publisher==compare){
                    res=true;
                    cout<<book[j].id<<endl;
                }
            }
        }else if(kind==5){
            for(int j=0;j<n;j++){
                if(book[j].publish_year==compare){
                    res=true;
                    cout<<book[j].id<<endl;
                }
            }
        }
        if(res==false)
            cout<<"Not Found"<<endl;
    }
    //system("pause");
    return 0;
}
