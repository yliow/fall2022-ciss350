#include <iostream>
#include <stack>
#include <queue>

// binary tree

class BTNode
{
public:
    BTNode(int key, BTNode * parent=NULL, BTNode * left=NULL, BTNode * right=NULL)
        : key_(key), parent_(parent), left_(left), right_(right)
    {}
    int key_;
    BTNode * parent_;
    BTNode * left_;
    BTNode * right_;
};
std::ostream & operator<<(std::ostream & cout, const BTNode & n)
{
    cout << "<BTNode " << &n
         << " key:" << n.key_
         << ", parent:" << n.parent_
         << ", left:" << n.left_
         << ", right:" << n.right_
         << '>';
    return cout;
}

/*
                10

           0          5

        3    6           7

                       2


 */

void preorder_print(BTNode * proot)
{
    if (proot == NULL) // i.e. this tree is empty
    {
        std::cout << "* ";
    }
    else
    {
        std::cout << proot->key_ << ' '; // root
        preorder_print(proot->left_);    // left
        preorder_print(proot->right_);   // right
    }
}

void postorder_print(BTNode * proot)
{
    if (proot == NULL) // i.e. this tree is empty
    {
        std::cout << "* ";
    }
    else
    {
        postorder_print(proot->left_);   // left
        postorder_print(proot->right_);  // right
        std::cout << proot->key_ << ' '; // root
    }
}

void inorder_print(BTNode * proot)
{
    if (proot == NULL) // i.e. this tree is empty
    {
        std::cout << "* ";
    }
    else
    {
        inorder_print(proot->left_);    // left
        std::cout << proot->key_ << ' '; // root
        inorder_print(proot->right_);   // right
    }
}

void preorder_with_stack_print(BTNode * proot)
{
    std::stack< BTNode * > stk;
    stk.push(proot);
    while (stk.size() != 0)
    {
        BTNode * p = stk.top();
        stk.pop();
        if (p == NULL)
        {
            std::cout << "* ";
        }
        else
        {
            std::cout << p->key_ << ' ';
            stk.push(p->right_);
            stk.push(p->left_);
        }
    }
}

void bf_print(BTNode * proot)
{
    std::queue< BTNode * > queue;
    queue.push(proot);
    while (queue.size() != 0)
    {
        BTNode * p = queue.front();
        queue.pop();
        if (p == NULL)
        {
            std::cout << "* ";
        }
        else
        {
            std::cout << p->key_ << ' ';
            queue.push(p->left_);
            queue.push(p->right_);
        }
    }
}

int max(int a, int b)
{
    return (a <= b ? b : a);
}
    
int height(BTNode * proot)
{
    if (proot == NULL)
    {
        return -1;
    }
    else
    {
        int lheight = height(proot->left_);
        int rheight = height(proot->right_);
        return max(lheight, rheight) + 1;
    }
}

int main()
{
    BTNode * p10 = new BTNode(10);
    BTNode * p0 = new BTNode(0);
    BTNode * p5 = new BTNode(5);
    BTNode * p3 = new BTNode(3);
    BTNode * p6 = new BTNode(6);
    BTNode * p7 = new BTNode(7);
    BTNode * p2 = new BTNode(2);
    p10->left_ = p0; p10->right_ = p5; 
    p0->parent_ = p10; p0->left_ = p3; p0->right_ = p6; 
    p5->parent_ = p10; p5->right_ = p7; 
    p7->parent_ = p5; p7->left_ = p2; 
    p3->parent_ = p0;
    p6->parent_ = p0;
    p2->parent_ = p7;
    
    std::cout << "*p10: " << (*p10) << '\n';
    std::cout << "*p0: " << (*p0) << '\n';
    std::cout << "*p5: " << (*p5) << '\n';
    std::cout << "*p3: " << (*p3) << '\n';
    std::cout << "*p6: " << (*p6) << '\n';
    std::cout << "*p7: " << (*p7) << '\n';
    std::cout << "*p2: " << (*p2) << '\n';

    std::cout << "preorder at 10 ... \n";
    preorder_print(p10);
    std::cout << "\n\n";;
    std::cout << "preorder at 5 ... \n";
    preorder_print(p5);
    std::cout << "\n\n";

    std::cout << "inorder at 10 ... \n";
    inorder_print(p10);
    std::cout << "\n\n";

    std::cout << "postorder at 10 ... \n";
    postorder_print(p10);
    std::cout << "\n\n";

    std::cout << "h(10): " << height(p10) << '\n';
    std::cout << "h(5): " << height(p5) << '\n';
    std::cout << "h(0): " << height(p0) << '\n';
    std::cout << "h(2): " << height(p2) << '\n';
    std::cout << "h(NULL): " << height(NULL) << '\n';

    std::cout << "preorder (with stack) at 10 ... \n";
    preorder_with_stack_print(p10);
    std::cout << "\n\n";;

    // EXERCISE: Make sure you do inorder using stack and postorder using stack

    std::cout << "bf at 10 ... \n";
    bf_print(p10);
    std::cout << "\n\n";;

    
    return 0;
}
