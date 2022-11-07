#include <iostream>

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

    return 0;
}
