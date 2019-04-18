#include <iostream>
#include <list>
#include <iterator>  //迭代器
using namespace std;
int main()
{
    list<int>Link;  //创建一个整型 链表 
    int i, key, item;
    for (i = 0; i < 10; i++)
    {
        cin >> item;
        //Link.push_front(item);  //表头插入
        Link.push_back(item);   //表尾插入
    }
    cout << "List:";
    list<int>::iterator  p = Link.begin(); //遍历链表
    while (p!=Link.end())
    {
        cout << *p << " ";
        p++;  //指向下一个节点
    }
    cout << endl;

    cout << "请输入一个需要删除的整数: ";
    cin >> key;
    Link.remove(key);

    cout << "List:";
    p = Link.begin();  //p重新指向表头
    while (p!=Link.end())  // 输出各节点数据，直到链表尾
    {
        cout << *p << " ";
        p++;  //指向下一个节点
    }
    cout << endl;
}