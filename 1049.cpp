#include <iostream>
#include <math.h>
using namespace std;
int A[10];
int countBits(int x)
{
	if (x == 0)
		return 1;
	int numOfBits = 0;
	while(x >= pow(10,numOfBits))
	{
		numOfBits++;
	}
	return numOfBits;
}
int from0ToN9(int N)
{
	int s = 0; 
	for (int i = 0; i <= N; i++)
	{
		s+=A[i];
	}
	return s;
}
int from10nTom10n(int n, int m)
{
	if (m == 1)
		return 1;
	int tmp = 0;
	for (int i = n; i >= 1; i--)
	{
		tmp += A[i];
	}
	int s = tmp*(m-1)+pow(10,n);
	return s;
}
int countSum(int x)
{
	if (x == 0)
		return 0;
	if (countBits(x) == 1)
	{
		if (x == 0)
			return 0;
		else
			return 1;
	}
	int numberOfBits = countBits(x);
	int a = from0ToN9(numberOfBits - 1);
	int remain = pow(10,numberOfBits - 1);
	int topBit = x/remain;
	int b = from10nTom10n(numberOfBits - 1, topBit);
	if (topBit == 1)
	{
		int b2 = x - topBit * pow(10, numberOfBits - 1);
		b += b2;
	}
	int c = x - topBit * remain;
	return a + b + countSum(c);
}
int main()
{
	A[0] = 0;
	int sum = 0;
	for (int i = 1; i <= 11; i++)
	{
		A[i] = 9 * sum + pow(10,i-1);
		sum += A[i];
	}
	int x;cin >> x;
	cout << countSum(x) << endl;
}

//题目的时间限制是10ms，若用遍历的方法检测从1到n每个数中1的个数，在n较大时肯定会超时。
//对于n的每一位，可以分为该位为0，该位为1，和该位大于1三种情况讨论。
//考虑n=15042的百位，由于百位是0，1到n中百位能否为1仅由更高的两位15决定，这两位可以是00到14，即001XX、011XX...141XX，低位XX可以是00到99，故满足条件的共15*100=1500个数。
//考虑n=15142的百位，由于百位是1，在上例15042的基础上，低位42贡献了151XX，XX可以是00到42，共43个数，故满足条件的有15*100+42+1=1543个数。
//考虑n=15242的百位，由于百位大于1，在第一个例子15042的基础上，增添了151XX，XX可以是00到99，故满足条件的有（15+1）*100=1600个数。
//对于n的每一位，都可以通过分析该位数字，以及高位和低位数字，来得到从1到n中该位出现1的次数。
//
//#include <iostream>
//using namespace std;
//
//int main(){
//    int n;
//    cin>>n;
//    int cur,low,high;
//    int count=0;
//    int base=1;
//    while(n/base){
//        low=n%base;		//低位
//        cur=n/base%10;	//当前位
//        high=n/base/10;	//高位
//        switch(cur){
//            case 0:
//                count+=high*base;
//                break;
//            case 1:
//                count+=high*base+low+1;
//                break;
//            default:
//                count+=(high+1)*base;
//                break;
//        }
//        base*=10;
//    }
//    cout<<count<<endl;
//    return 0;
//}