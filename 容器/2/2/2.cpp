#include <iostream>
#include <deque>        //˫�˶�������ͷ�ļ�
//#include <algorithm>  //�㷨ͷ�ļ�   
#include <iterator>
using namespace std;

int main()
{
    deque<double> values; //����һ��˫���ȵ�deque��������
    ostream_iterator<double> output(cout, " ");
    values.push_front(2.2);//deque ͷ������Ԫ��
    values.push_front(3.3);
    values.push_front(4.4);
    values.push_front(5.5);
    values.push_front(6.6);
    values.push_back(1.1); //β������Ԫ��

    cout << "values contains:";

    for (int i = 0;i<values.size();i++)
    {
        cout << values[i] << ' ';
    }
    cout << endl;
    values.pop_front();  //ɾ��������һ��Ԫ��
    copy(values.begin(), values.end(), output);
    cout << endl;

    values[0] = 9.9;
    copy(values.begin(), values.end(), output);
    cout << endl;
}