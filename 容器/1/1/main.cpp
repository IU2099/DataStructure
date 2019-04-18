#include <iostream>
#include <iomanip>
#include <vector> //����

using namespace std;
int main()
{
    vector<int> arr(10); //���� 10�� int����������
    int n;                //�����ķ�Χ����,����ʱ����;
    int primecount = 0, i, j;
    cout << "Enter a value >= 2 as upper limit for prime numbers: ";
    cin >> n;
    arr[primecount++] = 2;
    for (i = 3; i < n; i++)
    {
        if (primecount == arr.size())     //�������������,������ 10�� Ԫ�ؿռ�
        {
            arr.resize(primecount + 10);
        }
        if (i % 2 == 0)	//���� 2 ��ż����������
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
