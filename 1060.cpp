//自己写得太复杂了，字符串转成科学计数法
//字符串转科学计数法，转换函数需要根据输入的字符串和有效位数返回两个值：n位底数，指数次数。
//result返回n位有效数字，函数返回值为指数次数
//int toStdForm(const string s,int n,string &result){
//    int len=s.size();
//    //获取有效数字
//    int i=0;
//    while(i<len&&(s[i]=='0'||s[i]=='.'))//去掉前缀0和.
//        i++;
//    if(i==len){
//        for(int j=0;j<n;j++)
//            result+='0';
//        return 0;
//    }
//    int count=0;//n个有效数字
//    while(i<len){
//        if(s[i]!='.'){
//            result+=s[i];
//            count++;
//            if(count==n)
//                break;
//        }
//        i++;
//    }
//    while(count<n){
//        result+='0';
//        count++;
//    }
//    //获取指数次数
//    i=0;
//    int exp=0;
//    while(i<len&&s[i]=='0')//去掉前缀0
//        i++;
//    while(i<len&&s[i]!='.'){
//        exp++;
//        i++;
//    }
//    if(exp>0)//整数部分有exp位
//        return exp;
//    if(s[i]=='.')
//        i++;
//    while(i<len&&(s[i]=='0')){//小数部分的前缀0个数
//        exp--;
//        i++;
//    }
//    return exp;
//}


#include <iostream>
#include <string>
using namespace std;
#define maxn 105
string a,b;
int main()
{
    int N;
    cin >> N;
    cin >> a;
    cin >> b;
    
    unsigned long aPos = a.find('.');
    if (aPos == -1)
    {
        a.append(".");
        aPos = a.find('.');
    }
    unsigned long aFinal = 0;
    bool aIsZero = true;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] > '0')
        {
            aFinal = i;
            aIsZero = false;
            break;
        }
    }
    int aExp = 0;
    if (aPos > aFinal)
    {
        while(aPos > aFinal)
        {
            char tmp = a[aPos];
            a[aPos] = a[aPos-1];
            a[aPos-1] = tmp;
            aPos--;
            aExp++;
        }
    }
    else
    {
        while(aPos < aFinal - 1)
        {
            char tmp = a[aPos];
            a[aPos] = a[aPos+1];
            a[aPos+1] = tmp;
            aPos++;
            aExp--;
        }
    }
    if (aIsZero)
        aExp = 0;
    
    unsigned long bPos = b.find('.');
    if (bPos == -1)
    {
        b.append(".");
        bPos = b.find('.');
    }
    unsigned long bFinal = 0;
    bool bIsZero = true;
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i] > '0')
        {
            bFinal = i;
            bIsZero = false;
            break;
        }
    }
    int bExp = 0;
    if (bPos > bFinal)
    {
        while(bPos > bFinal)
        {
            char tmp = b[bPos];
            b[bPos] = b[bPos-1];
            b[bPos-1] = tmp;
            bPos--;
            bExp++;
        }
    }
    else
    {
        while(bPos < bFinal - 1)
        {
            char tmp = b[bPos];
            b[bPos] = b[bPos+1];
            b[bPos+1] = tmp;
            bPos++;
            bExp--;
        }
    }
    if (bIsZero)
        bExp = 0;
    
    //compare
    int digit = 1;
    bool equal = true;
    while (digit <= N)
    {
        if (a[aPos+digit] != b[bPos+digit])
        {
            equal = false;
            break;
        }
        digit++;
    }
    if (equal)
    {
        cout << "YES" << " 0.";
        for (int i = 1; i <= N; i++)
        {
            cout << a[aPos+i];
        }
        cout << "*10^" << aExp << endl;
    }
    else
    {
        cout << "NO" << " 0.";
        for (int i = 1; i <= N; i++)
        {
            cout << a[aPos+i];
        }
        cout << "*10^" << aExp << " 0.";
        for (int i = 1; i <= N; i++)
        {
            cout << b[bPos+i];
        }
        cout << "*10^" << bExp << endl;
    }
}