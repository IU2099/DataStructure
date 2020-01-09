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
    //��������Ԫ��
    void traverseList()
    {
        CNode* pTmpNode = pFirstList;
        while (pTmpNode != NULL)
        {
            cout << pTmpNode->data<<" ";
            pTmpNode = pTmpNode->next;
        }
    }
    //��
    void addElement(int data, int index)
    {
        CNode* pTmpNode = new CNode;
        pTmpNode->data = data;
        pTmpNode->prev = nullptr;
        pTmpNode->next = nullptr;

        //��Ϊ��
        if (isEmpty())
        {
            pFirstList = pTmpNode;
            size++;
            return;
        }
        //����λ��Ϊ�׸�
        if (!isEmpty() && index == 0)
        {
            pTmpNode->prev = pFirstList;
            pTmpNode->next = pFirstList->next;
            pFirstList->next->prev = pTmpNode;
            pFirstList->next = pTmpNode;
            size++;
            return;
        }
        //���м�
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
        //�����
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
    //ɾ
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
    //��
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
    //��
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
    //�п�
    bool isEmpty()
    {
        return size == 0;
    }

private:
    CNode* pFirstList;
    int size;
};

