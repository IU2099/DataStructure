#include <iostream>
#include <string>

using namespace std;
//链表节点定义
template<class T>
struct CNode
{
    T data;
    CNode<T>* pNextNode;
};

//链表类结构
template<class T>
class CLinkedStack
{
public:
    CLinkedStack()
    {
        head = new CNode<T>();
        head->pNextNode = NULL;
        tail = head;
    }
    CLinkedStack(T _element)
    {
        push_End(_element);
    }
    ~CLinkedStack()
    {
        CNode<T>*pTmpNode = NULL;
        while (head!=tail)
        {
            pTmpNode = head;
            head = head->pNextNode;
            delete pTmpNode;
        }
        delete head;
        head = NULL;
        tail = NULL;
    }
    //判断链表是否空
    bool empty()
    {
        if (head==tail)
        {
            return true;
        }
        return false;
    }
    //判断链表长度
    int size()
    {
        int count = 0;
        CNode<T>*pTmpNode = NULL;
        pTmpNode = head;
        while (pTmpNode != tail)
        {
            pTmpNode = pTmpNode->pNextNode;
            count++;
        }
        return count;
    }
    //查某个位置
    T check(int index)
    {
        CNode<T>*p = NULL;
        p = head->pNextNode;
        if (index < size() && (!empty()))
        {
            while (index--)
            {
                p = p->pNextNode;
            }
            return p->data;
        }
        else
        {
            string str = "error \"check()\"";
            throw str;
        }
    }
    //返回第一个元素
    T ofHome()
    {
        return head->pNextNode->data;
    }
    //最后一个元素
    T ofEnd()
    {
        return tail->data;
    }
    //从链表尾部插入元素
    void push_End(T _elenemt)
    {
        tail->pNextNode = new CNode < T > ;
        tail = tail->pNextNode;
        tail->data = _elenemt;
        tail->pNextNode = NULL;
    }
    //从链表头部插入元素
    void push_Home(T _elenemt)
    {
        CNode<T>* pTmpNode = new CNode < T >;
        pTmpNode->pNextNode = head;
        head = pTmpNode;
        pTmpNode->pNextNode->data = _elenemt;
    }
    //从链表尾部删除元素
    void pop_End()
    {
        if (empty())
        {
            string str = "error pop_End(),这是一个空表";
            throw str;
        }
        CNode<T>*pTmpNode = head;
        while (pTmpNode->pNextNode != tail)
        {
            pTmpNode = pTmpNode->pNextNode;
        }
        delete tail;
        tail = pTmpNode;
        tail->pNextNode = NULL;
    }
    //从链表头部删除元素
    void pop_Home()
    {
        if (empty())
        {
            string str = "error pop_Home(),这是一个空表";
            throw str;
        }
        CNode<T>*pTmpNode = head;
        head = head->pNextNode;
        delete pTmpNode;
    }
    // 指定位置删除
    void delElement(int index)
    {
        if((index<0)||index>=size())
        {
            string str = "error delElement(int)";
            throw str;
        }
        CNode<T>*pTmpNode = head;
       // CNode<T>*qTmpNode = NULL;
        while (index--)
        {
            pTmpNode = pTmpNode->pNextNode;
        }
        qTmpNode = pTmpNode->pNextNode;
        pTmpNode->pNextNode = qTmpNode->pNextNode;
        delete qTmpNode;
        qTmpNode = 0;
    }
    //指定位置插入
    void addElement(int index,T _element)
    {
        if ((index < 0) || index > size())
        {
            string str = "error addElement(int ,T)";
            throw str;
        }
        if (empty()||(!empty() && index == 0))
        {
            push_Home(_element);
            return;
        }
        if (index==size())
        {
            push_End(_element);
            return;
        }
        else
        {
            CNode<T>* pTmpNode = head;
            while (index--)
            {
                pTmpNode = pTmpNode->pNextNode;
            }
            CNode<T>*qTmpNode = new CNode < T >;
            qTmpNode->data = _element;
            qTmpNode->pNextNode = pTmpNode->pNextNode;
            pTmpNode->pNextNode = qTmpNode;
        }
    }

private:
    CNode<T>* head;
    CNode<T>* tail;
};



int main()
{
    CLinkedStack<int> stu;
    stu.addElement(0, 10);
    stu.addElement(1, 20);
    stu.addElement(2, 30);
    stu.addElement(3, 40);
    stu.addElement(4, 50);
    stu.addElement(5, 60);
    stu.delElement(5);
}