#include "utility.h"

template <class T>
struct CNode
{
    T data;
    CNode* prev;
    CNode* next;
};

template <class T>
class CDoubleLinkedList
{
public:
    CDoubleLinkedList();
    ~CDoubleLinkedList();

    bool isEmpty()
    {
        return size == 0;
    }

    void addElement(T data, int index);
    void delElement(int index);

private:
    CNode<T>* header;
    int size;
};



template <class T>
CDoubleLinkedList<T>::CDoubleLinkedList()
{
    header = 0;
    size = 0;
}

template <class T>
CDoubleLinkedList<T>::~CDoubleLinkedList()
{

}


//插入
template <class T>
void CDoubleLinkedList<T>::addElement(T data, int index)
{

    CNode<T>* pTmpNode = new CNode < T > ;
    pTmpNode->data = data;
    pTmpNode->prev = nullptr;
    pTmpNode->next = nullptr;

    //表为空
    if (isEmpty())
    {
        header = pTmpNode;
        size++;
        return;
    }
    //插入位置为首个
    if (!isEmpty() && index == 0)
    {
        pTmpNode->prev = header;
        pTmpNode->next = header->next;
        header->next->prev = pTmpNode;
        header->next = pTmpNode;
        size++;
        return;
    }
    //插中间
    if (!isEmpty() && index > 0 && index <= size - 1)
    {
        CNode<T>* pPreNode = header;

        for (int i = 0; i < index - 1; i++)
        {
            pPreNode = pPreNode->next;
        }
        pTmpNode->prev = pPreNode;
        pTmpNode->next = pPreNode->next;
        pPreNode->next->prev = pTmpNode;
        pPreNode->next = pTmpNode;

        size++;
        return;
    }
    //插后面
    if (index > size - 1)
    {
        CNode<T>* pEndNode = header;

        while (pEndNode->next != nullptr)
        {
            pEndNode = pEndNode->next;
        }

        pEndNode->next = pTmpNode;
        pTmpNode->prev = pEndNode;

        size++;
        return;
    }
    if (pTmpNode)
    {
        delete pTmpNode;
        pTmpNode = 0;
    }

}
//删除
template <class T>
void CDoubleLinkedList<T>::delElement(int index)
{
    if (isEmpty() || index >= size)
    {
        return;
    }
    if (!isEmpty() && index == 0)
    {
        CNode<T>* pTmpNode = header;

        header = header->next;
        delete pTmpNode;
        pTmpNode = 0;
        size--;
        return;
    }
    if (!isEmpty() && index > 0 && index <= size - 1)
    {

        int temp = 0;
        CNode<T>* pTmpNode = header;
        while (temp < index)
        {
            pTmpNode = pTmpNode->next;
            temp++;
        }
        pTmpNode->prev->next = pTmpNode->next;
        if (pTmpNode->next != nullptr)
        {
            pTmpNode->next->prev = pTmpNode->prev;
        }
        delete pTmpNode;
        pTmpNode = 0;
        return;
    }

}