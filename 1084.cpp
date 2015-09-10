//  字符串处理
//  1084.cpp
//  hello world
//
//  Created by Wu bin on 15/9/11.
//  Copyright (c) 2015年 Wu bin. All rights reserved.
//

#include <stdio.h>
/*2015.7.30cyq*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//ifstream fin("case1.txt");
//#define cin fin

int main(){
    string s1,s2,res;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    int i=0,j=0;
    while(i<n&&j<m){
        if(s1[i]!=s2[j]){
            res+=s1[i];
            i++;
        }else{
            i++;
            j++;
        }
    }
    while(i<n)
        res+=s1[i++];
    
    vector<bool> visited(256,false);
    for(auto it=res.begin();it!=res.end();++it){
        char tmp=toupper(*it);
        if(!visited[tmp]){
            visited[tmp]=true;
            cout<<tmp;
        }
    }
    return 0;
}