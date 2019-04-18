#include <iostream>
#include <queue>  //����

using namespace std;

template <class T>
struct CTreeNode
{
    T data;
    CTreeNode* pLeftChild;
    CTreeNode* pRigthChild;
};
template <class T>
class CTree
{
public:
    CTree(){}
    ~CTree(){}

    //����
    void initNodeTree(CTreeNode<T>* &pTmpTreeNode)
    {
        T tmp;
        cin >> tmp;
        if (tmp == 0)  //0����սڵ�
        {
            pTmpTreeNode = NULL;
        }
        else
        {
            pTmpTreeNode = new CTreeNode < T > ;
            pTmpTreeNode->data = tmp;
            initNodeTree(pTmpTreeNode->pLeftChild);
            initNodeTree(pTmpTreeNode->pRigthChild);
        }
    }
    //��ӡ
    void preOrderTraveral(CTreeNode<T>* pTmpTreeNode)
    {
        if (pTmpTreeNode == NULL)
        {
            return;
        }
        //cout << pTmpTreeNode->data << "  ";    
        //preOrderTraveral(pTmpTreeNode->pLeftChild);             //ǰ��
        //preOrderTraveral(pTmpTreeNode->pRigthChild);

        //preOrderTraveral(pTmpTreeNode->pLeftChild);
        //cout << pTmpTreeNode->data << "  ";                     //����
        //preOrderTraveral(pTmpTreeNode->pRigthChild);

        //preOrderTraveral(pTmpTreeNode->pLeftChild);             //����
        //preOrderTraveral(pTmpTreeNode->pRigthChild);
        //cout << pTmpTreeNode->data << "  ";

        //����
        queue<CTreeNode<T>*>queue;  
        queue.push(pTmpTreeNode);
        CTreeNode<T>* curNode;

        while (!queue.empty())
        {
            curNode = queue.front();
            cout << curNode->data;
            if (curNode->pLeftChild!=NULL)
            {
                queue.push(curNode->pLeftChild);
            }
            if (curNode->pRigthChild != NULL)
            {
                queue.push(curNode->pRigthChild);
            }

            queue.pop();
        }

    

    }

    //�鿴Ԫ���Ƿ����������             
    CTreeNode<T>* checkElement(CTreeNode<T>* _pTmpRootTreeNode, T _element)
    {
        if (pRootTreeNode == nullptr || _pTmpRootTreeNode == nullptr)
        {
            return nullptr;
        }

        if (_pTmpRootTreeNode->data == _element)
        {
            cout << "����!" << endl;
            return _pTmpRootTreeNode;
        }

        CTreeNode<T>*PTmp1 = checkElement(_pTmpRootTreeNode->pLeftChild, _element);
        if (PTmp1 != nullptr)
        {
            return PTmp1;
        }

        CTreeNode<T>*PTmp2 = checkElement(_pTmpRootTreeNode->pRigthChild, _element);
        if (PTmp2 != nullptr)
        {
            return PTmp2;
        }
        return nullptr;
    }

    //�󸸽ڵ�
    CTreeNode<T>* getFatherNode(CTreeNode<T>* _pTmpRootTreeNode, CTreeNode<T>* _pFoundTreeNode)
    {
        if (_pTmpRootTreeNode == 0 || _pFoundTreeNode == 0 || pRootTreeNode == 0)
        {
            return nullptr;
        }
        if (_pTmpRootTreeNode->pLeftChild == _pFoundTreeNode || _pTmpRootTreeNode->pRigthChild == _pFoundTreeNode)
        {
            return _pTmpRootTreeNode;
        }

        CTreeNode<T>* pTmpTreeNode1 = getFatherNode(_pTmpRootTreeNode->pLeftChild, _pFoundTreeNode);
        if (pTmpTreeNode1)
        {
            return pTmpTreeNode1;
        }

        CTreeNode<T>* pTmpTreeNode2 = getFatherNode(_pTmpRootTreeNode->pRigthChild, _pFoundTreeNode);
        if (pTmpTreeNode2)
        {
            return pTmpTreeNode2;
        }

        return nullptr;
    }

private:
    CTreeNode<T> *pRootTreeNode;

};
int main()

{
    CTreeNode<int>* text;
    CTree<int> tree;

    tree.initNodeTree(text);//����

    tree.preOrderTraveral(text); //���

   // cout << tree.checkElement(text, 5)->data << "�ĸ��ڵ�Ϊ:" << tree.getFatherNode(text, tree.checkElement(text, 5))->data << endl;


}