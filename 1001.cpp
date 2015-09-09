/*
 http://blog.csdn.net/tuzigg123
 中使用栈来辅助输出，每次后三位压入栈中，输出的时候从栈顶去，第一次取不用补0，后面的都补齐三位
 */
/*
 我的做法是计算位数，用一个数组保存每一位的数字，从高位扫描下去，看情况输出',', 用％3来输出','
 */
#include <iostream>
#include <cmath>
using namespace std;
int a,b,c;
int A[15];
int main()
{
    cin >> a >> b;
    c = a+b;
    if (c < 0)
    {
        cout << "-";
        c = abs(c);
    }
    if (c == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int bits = 0;
    while(1)
    {
        int rem = pow(10,bits);
        if (c / rem <= 0)
        {
            break;
        }
        bits++;
    }
    if (bits <= 3)
    {
        cout << c << endl;
        return 0;
    }
    for (int i = bits; i >= 1; i--)
    {
        int mod = pow(10,i-1);
        A[i] = c / mod;
        c = c - c/mod * mod;
    }
    
    int comma = bits % 3;
    bool flag = comma > 0 ? true: false;
    while (comma > 0)
    {
        cout << A[bits];
        bits--;
        comma--;
    }
    if (flag)
        cout <<",";
    for (int i = bits; i>=1; i--)
    {
        if (i!=bits&&i % 3 == 0)
            cout << ",";
        cout << A[i];
    }
}