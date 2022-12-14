#include <iostream>
#include "queue"
#include "stack"

using namespace std;

//BTree类的前向说明
template <class elemType>
class BTree;


template <class elemType>
class Node   // node是每个节点类
{
    friend class BTree<elemType>;
private:
    elemType data;
    Node *left, *right;
    int leftFlag; //用于标识是否线索，0时left为左孩子结点，1时为前驱线索
    int rightFlag; //用于标识是否线索，0时right为右孩子结点，1时为后继线索
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

    int Size (Node<elemType> *t); //求以t为根的二叉树的结点个数。
    int Height (Node<elemType> *t); //求以t为根的二叉树的高度。
    void DelTree(Node<elemType> *t);//删除以t为根的二叉树
    void PreOrder(Node<elemType> *t);
    // 按前序遍历输出以t为根的二叉树的结点的数据值
    void InOrder(Node<elemType> *t);
    // 按中序遍历输出以t为根的二叉树的结点的数据值
    void PostOrder(Node<elemType> *t);
    // 按后序遍历输出以t为根的二叉树的结点的数据值
public:
    BTree(){root=NULL;}  // 构造函数 使得root指向空
    void createTree(const elemType &flag);//创建一棵二叉树
    bool isEmpty () { return (root == NULL);}// 判断叉树是否为空
    Node<elemType> * GetRoot(){ return  root; }

    int Size (); //求二叉树的结点个数。
    int Height (); //求二叉树的高度。
    void DelTree();//删除二叉树
    void PreOrder();// 按前序遍历输出二叉树的结点的数据值
    void InOrder();// 按中序遍历输出二叉树的结点的数据值
    void PostOrder();// 按后序遍历输出二叉树的结点的数据值
    void LevelOrder();// 按层次遍历输出二叉树的结点的数据值

    Node<elemType> *bulid_Tree(vector<elemType> pre, int pl, int pr, vector<elemType> mid, int ml,int mr);
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
//    PreOrder(root);  // 这是递归的写法
//    cout<<endl;

    // 下面是不递归的写法
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

    // 非递归的写法 这是第一种写法
/*    if (!root) return;

    stack<Node<elemType>*> my_stack;
    Node<elemType> *p,*pr,*pl;

    my_stack.push(root);


    p = root;
    while (p->left) //先从根节点开始一路左子压到底，不弹出
    {
        my_stack.push(p->left);
        p = p->left;
    }

    while (!my_stack.empty())  // 然后开始准备弹出
    {
        p = my_stack.top();
        my_stack.pop();
        cout<<p->data<<" ";

        if (p->right)   // 有右子压右子，右子有左子 就一路左子压到底
        {
            my_stack.push(p->right);
            p = p->right;

            while (p->left)
            {
                my_stack.push(p->left);
                p = p->left;
            }

        }
    }*/

    // 非递归的第二种写法，但是有点问题
/*    if (!root) return;
    stack<Node<elemType>*> my_stack;
    Node<elemType> *p;

    my_stack.push(root);

    p = root;
    while (!my_stack.empty())
    {
//        p = my_stack.top();
        if (p->left)
        {
            my_stack.push(p->left);
            p = p->left;
            continue;
        }
        cout<<p->data<<" ";
        my_stack.pop();
        if (p->right)
        {
            my_stack.push(p->right);
            p = p->right;
            continue;
        }
    }*/

    // 第三种写法
    stack<Node<elemType>*> s1;
    stack<int> s2;
    Node<elemType> *p;
    if (!root) return;

    s1.push(root);
    s2.push(0);

    while (!s1.empty())
    {
        if (s2.top()==0)  // 先让左子在头顶出现（压左子）
        {
            p = s1.top();
            s2.top() =1;
            if (p->left)
            {
                s1.push(p->left);
                s2.push(0);
            }
        }
        else  // 是1 表明已经把左子压到了头上
        {
            p = s1.top(); // 然后自己出去 然后让右子进来
            s1.pop();
            s2.pop();
            cout<<p->data<<" ";
            if (p->right)
            {
                s1.push(p->right);
                s2.push(0);
            }

        }
    }

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
/*    PostOrder(root)   ;
    cout<<endl;*/
    stack<Node<elemType>*> s1;
    stack<int> s2;
    Node<elemType> *p;

    if (!root) return;

    s1.push(root);
    s2.push(0);
/*    while (!s1.empty())   // 这种方法是左右子一次一次压,先压左子 左子出去；再压右子 右子出去；然后自己出去
    {
        int flag = s2.top();
        p = s1.top();
        switch (flag) {
            case 0: // 状态为0 所以先压左子在头上
            {
                s2.top()= 1;
                if (p->left)
                {
                    s1.push(p->left);
                    s2.push(0);
                }
                break;
            }
            case 1: // 左子已经压过了（且已经出去了，因为是栈顶） 压右子
            {
                s2.top()=2;
                if (p->right)
                {
                    s1.push(p->right);
                    s2.push(0);
                }
                break;
            }
            case 2: // 左右子都压过了且出去了，此时访问自己
            {
                cout<<p->data<<" ";   // 此时栈里面剩下的都是P的祖先 所以可以用来求一个元素的所有祖先
                s2.pop();
                s1.pop();
                break;
            }
        }
    }*/

    while (!s1.empty())  // 这种方法是左右一起压，那么根据顺序就要先压右子 再压左子
    {
        int flag = s2.top();
        p = s1.top();
        if (flag==0)
        {
            s2.top() = 1;

            if (p->right)
            {
                s1.push(p->right);
                s2.push(0);
            }
            if (p->left)
            {
                s1.push(p->left);
                s2.push(0);
            }
        } else
        {
            cout<<p->data<<" ";
            s1.pop();
            s2.pop();
        }
    }
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

template <class elemType>
Node<elemType> *BTree<elemType>::bulid_Tree(vector<elemType> pre, int pl, int pr, vector<elemType> mid, int ml,int mr)
{
    Node<elemType> *p,*left_root,*right_root;
    int lpl,lpr,lml,lmr;
    int rpl,rpr,rml,rmr;

    if (pl>pr) return NULL; // 相等的时候不能跳出来 因为要把这个null给连进去

    p = new Node<elemType> (pre[pl]);
    if (!root) root = p;

    int i;
    for (i = ml; i <=mr ; ++i) {
        if (mid[i] == pre[pl])
        {
            break;
        }
    }
    int pos = i;
    int num = pos - ml;
    // 找左子树
    lpl = pl+1; lpr = pl+num;
    lml = ml;  lmr = pos-1;

    left_root = bulid_Tree(pre,lpl,lpr,mid,lml,lmr);


    // 找右子树
    rpl = pl+num +1; rpr = pr;
    rml = pos+1; rmr = mr;
    right_root = bulid_Tree(pre,rpl,rpr,mid,rml,rmr);

    p->left = left_root;
    p->right = right_root;

    return p;

}

int main()
{
    BTree<char> tree_1;
//    char flag = '.';
//    tree_1.createTree(flag);
//    tree_1.LevelOrder();
//    cout<<endl;
//    tree_1.PreOrder();
//    cout<<endl;
//    tree_1.InOrder();
//    cout<<endl;
//    tree_1.PostOrder();
//    cout<<tree_1.Size();
//    cout<<tree_1.Height();

    vector<char> pre = {'a','b','d','e','g','f','c'};
    vector<char> in = {'d','b','g','e','f','a','c'};

//    vector<char> pre = {'a','b'};
//    vector<char> in = {'b','a'};

    tree_1.bulid_Tree(pre,0,(int)pre.size()-1,in,0,(int)in.size()-1);
    tree_1.PreOrder();
    cout<<endl;
    tree_1.LevelOrder();


}

