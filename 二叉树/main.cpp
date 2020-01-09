#include <iostream>
#include <queue> //队列

using namespace std;

template <class T>
struct CTreeNode
{
    T data;
    CTreeNode *pLeftChild;
    CTreeNode *pRigthChild;
};
template <class T>
class CTree
{
public:
    CTree() {}
    ~CTree() {}

    //输入
    void initNodeTree(CTreeNode<T> *&pTmpTreeNode)
    {
        T tmp;
        cin >> tmp;
        if (tmp == 0) //0代表空节点
        {
            pTmpTreeNode = NULL;
        }
        else
        {
            pTmpTreeNode = new CTreeNode<T>;
            pTmpTreeNode->data = tmp;
            initNodeTree(pTmpTreeNode->pLeftChild);
            initNodeTree(pTmpTreeNode->pRigthChild);
        }
    }
    //打印
    void preOrderTraveral(CTreeNode<T> *pTmpTreeNode)
    {
        if (pTmpTreeNode == NULL)
        {
            return;
        }
        //cout << pTmpTreeNode->data << "  ";
        //preOrderTraveral(pTmpTreeNode->pLeftChild);             //前序
        //preOrderTraveral(pTmpTreeNode->pRigthChild);

        //preOrderTraveral(pTmpTreeNode->pLeftChild);
        //cout << pTmpTreeNode->data << "  ";                     //中序
        //preOrderTraveral(pTmpTreeNode->pRigthChild);

        //preOrderTraveral(pTmpTreeNode->pLeftChild);             //后序
        //preOrderTraveral(pTmpTreeNode->pRigthChild);
        //cout << pTmpTreeNode->data << "  ";

        //层序
        queue<CTreeNode<T> *> queue;
        queue.push(pTmpTreeNode);
        CTreeNode<T> *curNode;

        while (!queue.empty())
        {
            curNode = queue.front();
            cout << curNode->data;
            if (curNode->pLeftChild != NULL)
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

    //查看元素是否存在于树中
    CTreeNode<T> *checkElement(CTreeNode<T> *_pTmpRootTreeNode, T _element)
    {
        if (pRootTreeNode == nullptr || _pTmpRootTreeNode == nullptr)
        {
            return nullptr;
        }

        if (_pTmpRootTreeNode->data == _element)
        {
            cout << "存在!" << endl;
            return _pTmpRootTreeNode;
        }

        CTreeNode<T> *PTmp1 = checkElement(_pTmpRootTreeNode->pLeftChild, _element);
        if (PTmp1 != nullptr)
        {
            return PTmp1;
        }

        CTreeNode<T> *PTmp2 = checkElement(_pTmpRootTreeNode->pRigthChild, _element);
        if (PTmp2 != nullptr)
        {
            return PTmp2;
        }
        return nullptr;
    }

    //求父节点
    CTreeNode<T> *getFatherNode(CTreeNode<T> *_pTmpRootTreeNode, CTreeNode<T> *_pFoundTreeNode)
    {
        if (_pTmpRootTreeNode == 0 || _pFoundTreeNode == 0 || pRootTreeNode == 0)
        {
            return nullptr;
        }
        if (_pTmpRootTreeNode->pLeftChild == _pFoundTreeNode || _pTmpRootTreeNode->pRigthChild == _pFoundTreeNode)
        {
            return _pTmpRootTreeNode;
        }

        CTreeNode<T> *pTmpTreeNode1 = getFatherNode(_pTmpRootTreeNode->pLeftChild, _pFoundTreeNode);
        if (pTmpTreeNode1)
        {
            return pTmpTreeNode1;
        }

        CTreeNode<T> *pTmpTreeNode2 = getFatherNode(_pTmpRootTreeNode->pRigthChild, _pFoundTreeNode);
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
    CTreeNode<int> *text;
    CTree<int> tree;

    tree.initNodeTree(text); //输入

    tree.preOrderTraveral(text); //输出

    // cout << tree.checkElement(text, 5)->data << "的父节点为:" << tree.getFatherNode(text, tree.checkElement(text, 5))->data << endl;
}