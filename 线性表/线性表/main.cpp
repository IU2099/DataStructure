#include <iostream>
using namespace std;

template<typename T>
class ArrayList
{
public:
    ArrayList()
    {
        length = 0;
        MAX_LENGTH = 1024;
        datas = new T[MAX_LENGTH];
    }
    ~ArrayList(){
        delete[] datas; 
        datas = 0;
    }
    //����
    void insert(T e, int index)
    {
        if (length < MAX_LENGTH && index <= length)
        {
            for (int i = length; i > index; i--)
            {
                datas[i] = datas[i - 1];
            }
            datas[index] = e;
            length++;
        }
        else
        {
            cout << "����ʧ��!\n";
        }
    }
    //ɾ��
    void remove(int index)
    {
        if (index < length)
        {
            for (int i = index; i < length - 1; i++)
            {
                datas[i] = datas[i + 1];
            }
            datas[length - 1] = NULL;
            length--;
        }
        else
        {
            cout << "ɾ��ʧ��!\n";
        }
    }
    void print()
    {
        for (int i = 0; i < length; i++)
        {
            cout << datas[i];
        }
        cout << length;
    }
    
    T* datas;
    int length;
    int MAX_LENGTH;
};



int main()
{
    ArrayList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 3);

    list.insert(5, 5);
    list.remove(5);

    list.print();
} 