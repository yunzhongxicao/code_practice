#include <iostream>
#include "queue"
#include "stack"

using namespace std;

//BTree���ǰ��˵��
template <class elemType>
class BTree;


template <class elemType>
class Node   // node��ÿ���ڵ���
{
    friend class BTree<elemType>;
private:
    elemType data;
    Node *left, *right;
    int leftFlag; //���ڱ�ʶ�Ƿ�������0ʱleftΪ���ӽ�㣬1ʱΪǰ������
    int rightFlag; //���ڱ�ʶ�Ƿ�������0ʱrightΪ�Һ��ӽ�㣬1ʱΪ�������
public:
    Node(){left=NULL; right=NULL; leftFlag= 0; rightFlag=0;};
    Node(const elemType&e, Node* L=NULL, Node *R=NULL)
    { data = e;
        left=L; right=R; leftFlag= 0; rightFlag=0;
    };
};



template <class elemType>
class BTree
{
private:
    Node<elemType> *root;
    elemType stopFlag;

    int Size (Node<elemType> *t); //����tΪ���Ķ������Ľ�������
    int Height (Node<elemType> *t); //����tΪ���Ķ������ĸ߶ȡ�
    void DelTree(Node<elemType> *t);//ɾ����tΪ���Ķ�����
    void PreOrder(Node<elemType> *t);
    // ��ǰ����������tΪ���Ķ������Ľ�������ֵ
    void InOrder(Node<elemType> *t);
    // ��������������tΪ���Ķ������Ľ�������ֵ
    void PostOrder(Node<elemType> *t);
    // ��������������tΪ���Ķ������Ľ�������ֵ
public:
    BTree(){root=NULL;}  // ���캯�� ʹ��rootָ���
    void createTree(const elemType &flag);//����һ�ö�����
    bool isEmpty () { return (root == NULL);}// �жϲ����Ƿ�Ϊ��
    Node<elemType> * GetRoot(){ return  root; }

    int Size (); //��������Ľ�������
    int Height (); //��������ĸ߶ȡ�
    void DelTree();//ɾ��������
    void PreOrder();// ��ǰ���������������Ľ�������ֵ
    void InOrder();// �������������������Ľ�������ֵ
    void PostOrder();// �������������������Ľ�������ֵ
    void LevelOrder();// ����α�������������Ľ�������ֵ
};

template <class elemType>
void BTree<elemType>::createTree(const elemType &flag) {
    Node<elemType>  *p,*pl,*pr;
    elemType x,xl,xr;

    queue<Node<elemType>*> my_queue;
    
    cout<<"please input the root: ";
    cin>>x;

    if (x == flag)
    {
        root = NULL;
        return;
    }
    
    p = new Node<elemType>(x);

    root = p;
    my_queue.push(root);

    while (!my_queue.empty())
    {
        p = my_queue.front();
        my_queue.pop();
        cout<<"please input left and right of "<<p->data;
        cin>>xl>>xr;

        if (xl != flag)
        {
            pl= new Node<elemType>(xl);
            my_queue.push(pl);
            p->left = pl;
        }
        if(xr != flag)
        {
            pr = new Node<elemType>(xr);
            p ->right = pr;
            my_queue.push(pr);
        }

    }
}

template <class elemType>
void BTree<elemType>::LevelOrder() {
    queue<Node<elemType>*> my_queue;
    Node<elemType> *p,*pl,*pr;
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    my_queue.push(root);
    while (!my_queue.empty())
    {
        p = my_queue.front();
        my_queue.pop();
        if (p->left != NULL)
        {
            my_queue.push(p->left);
            cout<<p->left->data<<" ";
        }
        if(p->right != NULL)
        {
            my_queue.push(p->right);
            cout<<p->right->data<<" ";
        }
    }
}


template <class elemType>
void BTree<elemType>::PreOrder() {
//    PreOrder(root);  // ���ǵݹ��д��
//    cout<<endl;

    // �����ǲ��ݹ��д��
    stack<Node<elemType>*> my_stack;
    Node<elemType> *p, *pl,*pr;
    if (!root)
        return;
//    cout<<root->data<<" ";
    my_stack.push(root);
    while (!my_stack.empty())
    {
        p = my_stack.top();
        my_stack.pop();
        cout<<p->data<<" ";
        if (p->right)
        {
            pr = p->right;
            my_stack.push(pr);
        }
        if (p->left)
        {
            pl = p->left;
            my_stack.push(pl);
        }

    }

}

template <class elemType>
void BTree<elemType>::PreOrder(Node<elemType> *t) {
    if (t== NULL)
        return;
    cout<<t->data;
    PreOrder(t->left);
    PreOrder(t->right);
}

template <class elemType>
void BTree<elemType>::InOrder() {
//    InOrder(root)   ;
//    cout<<endl;

    // �ǵݹ��д��

}

template <class elemType>
void BTree<elemType>::InOrder(Node<elemType> *t) {
    if (t==NULL)
        return;
    InOrder(t->left);
    cout<<t->data;
    InOrder(t->right);
}

template <class elemType>
void BTree<elemType>::PostOrder() {
    PostOrder(root)   ;
    cout<<endl;
}

template <class elemType>
void BTree<elemType>::PostOrder(Node<elemType> *t) {
    if (t==NULL)
        return;
    PostOrder(t->left);
    PostOrder(t->right);
    cout<<t->data;

}

template <class elemType>
int BTree<elemType>::Size() {
    Size(root);
}

template <class elemType>
int BTree<elemType>::Size(Node<elemType> *t) {
    if (t == NULL)
        return 0;
    return 1 + Size(t->left) + Size(t->right);
}

template <class elemType>
int BTree<elemType>::Height() {
    return Height(root);
}

template <class elemType>
int BTree<elemType>::Height(Node<elemType> *t) {
    if (!t)
        return 0;
    int hl= Height(t->left);
    int hr = Height(t->right);
    if (hl>hr)
        return 1+hl;
    else
        return 1+hr;
}

template <class elemType>
void BTree<elemType>::DelTree() {
    DelTree(root);
}

template <class elemType>
void BTree<elemType>::DelTree(Node<elemType> *t) {
    if (!t) return;
    DelTree(t->left);
    DelTree(t->right);
    delete t;
}

int main()
{
    BTree<char> tree_1;
    char flag = '.';
    tree_1.createTree(flag);
    tree_1.LevelOrder();
    cout<<endl;
    tree_1.PreOrder();
    tree_1.InOrder();
    tree_1.PostOrder();
    cout<<tree_1.Size();
    cout<<tree_1.Height();
}

