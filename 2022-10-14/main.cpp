#include <iostream>

// SLNode.h -- singly-linked node
class SLNode
{
public:
    SLNode(int key, SLNode * next=NULL)
        : key_(key), next_(next)
    {}
//private:
    int key_;
    SLNode * next_;
};

std::ostream & operator<<(std::ostream & cout, const SLNode & n)
{
    cout << "<SLNode " << &n
         << " key:" << n.key_
         << ", next:" << n.next_
         << '>';
    return cout;
}

int main()
{
    // 5 -> 0 -> 3 -> 1
    SLNode n5(5); std::cout << n5 << '\n';
    SLNode n0(0); std::cout << n0 << '\n';
    SLNode n3(3); std::cout << n3 << '\n';
    SLNode n1(1); std::cout << n1 << '\n';
    n5.next_ = &n0;
    n0.next_ = &n3;
    n3.next_ = &n1;
    std::cout << n5 << '\n';
    std::cout << n0 << '\n';
    std::cout << n3 << '\n';
    std::cout << n1 << '\n';

    std::cout << "print using an iteration\n";
    SLNode * p = &n5;
    while (p != NULL)
    {
        std::cout << (*p) << '\n';
        p = p->next_;
    }
    return 0;
}
