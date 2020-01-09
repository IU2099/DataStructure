#pragma once
#include "utility.h"

struct CNode
{
    int data;
    CNode* prev;
    CNode* next;
};

class CDoubleLinkedList
{
public:
    CDoubleLinkedList()
    {
        pFirstList = 0;
        size = 0;
    }
    ~CDoubleLinkedList()
    {

    }
    //遍历所有元素
    void traverseList()
    {
        CNode* pTmpNode = pFirstList;
        while (pTmpNode != NULL)
        {
            cout << pTmpNode->data<<" ";
            pTmpNode = pTmpNode->next;
        }
    }
    //增
    void addElement(int data, int index)
    {
        CNode* pTmpNode = new CNode;
        pTmpNode->data = data;
        pTmpNode->prev = nullptr;
        pTmpNode->next = nullptr;

        //表为空
        if (isEmpty())
        {
            pFirstList = pTmpNode;
            size++;
            return;
        }
        //插入位置为首个
        if (!isEmpty() && index == 0)
        {
            pTmpNode->prev = pFirstList;
            pTmpNode->next = pFirstList->next;
            pFirstList->next->prev = pTmpNode;
            pFirstList->next = pTmpNode;
            size++;
            return;
        }
        //插中间
        if (!isEmpty() && index > 0 && index <= size - 1)
        {
            CNode* pPreNode = pFirstList;

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
            CNode* pEndNode = pFirstList;

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
    //删
    void delElement(int index)
    {
        if (isEmpty() || index >= size)
        {
            return;
        }
        if (!isEmpty() && index == 0)
        {
            CNode* pTmpNode = pFirstList;

            pFirstList = pFirstList->next;
            delete pTmpNode;
            pTmpNode = 0;
            size--;
            return;
        }
        if (!isEmpty() && index > 0 && index <= size - 1)
        {

            int temp = 0;
            CNode* pTmpNode = pFirstList;
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
    //改
    void changeList(int value, int index)
    {
        CNode* pTmpNode = pFirstList;
        if (index > size || index <= 0)
        {
            cout << "over stack !" << endl;
            return;
        }
        for (int i = 0; i < index - 1; i++)
        {
            pTmpNode = pTmpNode->next;
        }
        pTmpNode->data = value;
    }
    //查
    int checkList(int index)
    {
        CNode* pTmpNode = pFirstList;
        if (index>size || index <= 0)
        {
            cout << "over stack !" << endl;
            return 0;
        }
        for (int i = 0; i < index - 1; i++)
        {
            pTmpNode = pTmpNode->next;
        }
        return pTmpNode->data;
    }
    //判空
    bool isEmpty()
    {
        return size == 0;
    }

private:
    CNode* pFirstList;
    int size;
};

