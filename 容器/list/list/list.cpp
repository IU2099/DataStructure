#include <iostream>
#include <list>
#include <iterator>  //������
using namespace std;
int main()
{
    list<int>Link;  //����һ������ ���� 
    int i, key, item;
    for (i = 0; i < 10; i++)
    {
        cin >> item;
        //Link.push_front(item);  //��ͷ����
        Link.push_back(item);   //��β����
    }
    cout << "List:";
    list<int>::iterator  p = Link.begin(); //��������
    while (p!=Link.end())
    {
        cout << *p << " ";
        p++;  //ָ����һ���ڵ�
    }
    cout << endl;

    cout << "������һ����Ҫɾ��������: ";
    cin >> key;
    Link.remove(key);

    cout << "List:";
    p = Link.begin();  //p����ָ���ͷ
    while (p!=Link.end())  // ������ڵ����ݣ�ֱ������β
    {
        cout << *p << " ";
        p++;  //ָ����һ���ڵ�
    }
    cout << endl;
}