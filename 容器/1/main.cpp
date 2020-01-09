#include <iostream>
#include <iomanip>
#include <vector> //容器

using namespace std;
int main()
{
    vector<int> arr(10); //申请 10个 int型容器向量
    int n;                //质数的范围上限,运行时输入;
    int primecount = 0, i, j;
    cout << "Enter a value >= 2 as upper limit for prime numbers: ";
    cin >> n;
    arr[primecount++] = 2;
    for (i = 3; i < n; i++)
    {
        if (primecount == arr.size())     //如果质数表满了,在申请 10个 元素空间
        {
            arr.resize(primecount + 10);
        }
        if (i % 2 == 0)	//大于 2 的偶数不是质数
        {
            continue;
        }
        j = 3;
        while (j <= i / 2 && i%j != 0)
        {
            j += 2;
        }
        if (j>i / 2)
        {
            arr[primecount++] = i;
        }
    }
    for (i = 0; i < primecount; i++)
    {
        cout << setw(5) << arr[i];
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}
