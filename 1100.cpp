//日了火星人了
//做题要细心，火星人说13 不是说tam tret，直接就是tam
//不要纠结于cin.getline getchar stringstream,caocaocao!!!

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define maxn 105
const char lowDigit[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const char highDigit[13][5] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int N;
void earthToMars(int x)
{
    if (x <= 12)
    {
        cout << lowDigit[x] << endl;
    }
    else
    {
        int lowerdigit = x % 13;
        x = x / 13;
        int higherdigit = x % 13;
        if (lowerdigit != 0)
            cout << highDigit[higherdigit] << " " << lowDigit[lowerdigit] << endl;
        else
            cout << highDigit[higherdigit] << endl;
    }
}
void marsToEarth(string x)
{
    for (int i = 0; i <= 12; i++)
    {
        if (x.compare(highDigit[i])==0)
        {
            cout << i * 13 << endl;
            return;
        }
    }
    for (int i = 0; i <= 12; i++)
    {
        if (x.compare(lowDigit[i])==0)
        {
            cout << i << endl;
            return;
        }
    }
}
void marsToEarth(string h,string l)
{
    int high = 0,low = 0;
    for (int i = 0; i <= 12; i++)
    {
        if (h.compare(highDigit[i])==0)
        {
            high = i;
            break;
        }
    }
    for (int i = 0; i <= 12; i++)
    {
        if (l.compare(lowDigit[i])==0)
        {
            low = i;
            break;
        }
    }
    cout << high * 13 + low << endl;
}
int main()
{
    cin >> N;
    while (N--)
    {
        string a;
        cin >> a;
        char c = getchar();
        if (c=='\n')
        {
            if (a[0]<'0' || a[0]>'9')
            {
                //1 mars language
                marsToEarth(a);
            }
            else
            {
                //1 earth int
                int b;
                stringstream s;
                s << a;
                s >> b;
                earthToMars(b);
                //earthToMars(atoi(a.c_str()));
            }
        }
        else
        {
            string b;
            cin >> b;
            marsToEarth(a,b);
        }
    }
    return 0;
}
