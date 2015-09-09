/*
 质数按给定进制逆序后，再转为十进制，仍为质数。使用一个数组/stack作辅助，简单题。
 */
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
stack<int> st;
bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    while(1)
    {
        int N,D;
        cin >> N;
        if (N < 0)
        {
            break;
        }
        cin >> D;
        if (!isPrime(N))
        {
            cout << "No" << endl;
            continue;
        }
        while (N > 0)
        {
            st.push(N%D);
            N = N / D;
        }
        int i = 0,reverse = 0;
        while(!st.empty())
        {
            int bit = st.top();
            reverse = reverse + bit * int(pow(D,i));
            i++;
            st.pop();
        }
        if (!isPrime(reverse))
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}