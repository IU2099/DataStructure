#include <iostream>
#include <deque>        //双端队列容器头文件
//#include <algorithm>  //算法头文件   
#include <iterator>
using namespace std;

int main()
{
    deque<double> values; //声明一个双精度的deque序列容器
    ostream_iterator<double> output(cout, " ");
    values.push_front(2.2);//deque 头部插入元素
    values.push_front(3.3);
    values.push_front(4.4);
    values.push_front(5.5);
    values.push_front(6.6);
    values.push_back(1.1); //尾部插入元素

    cout << "values contains:";

    for (int i = 0;i<values.size();i++)
    {
        cout << values[i] << ' ';
    }
    cout << endl;
    values.pop_front();  //删除容器第一个元素
    copy(values.begin(), values.end(), output);
    cout << endl;

    values[0] = 9.9;
    copy(values.begin(), values.end(), output);
    cout << endl;
}