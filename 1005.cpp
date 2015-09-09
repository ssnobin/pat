/*
 求一个数的各个位之和，并将结果spell出来，结果小于1000，所以三个if else
 stringstream 将int转成string
 */
/*
 string f(string s){
 int sum=0;
 int n=s.size();
 for(int i=0;i<n;i++)
 sum+=s[i]-'0';
 stringstream ss;//将int转为string
 ss<<sum;
 string result;
 ss>>result;
 return result;
 }
 */
#include<stdio.h>
int main(){
    char str[110];
    char dtoe[10][20]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int i,sum=0;
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++){
        sum=sum+str[i]-'0';
    }
    if(sum<10){
        printf("%s\n",dtoe[sum]);
    }
    else if(sum<100){
        printf("%s ",dtoe[sum/10]);
        printf("%s\n",dtoe[sum%10]);
    }
    else if(sum<1000){
        printf("%s ",dtoe[sum/100]);
        printf("%s ",dtoe[sum%10/10]);
        printf("%s\n",dtoe[sum%10]);
    }
    return 0;
}
