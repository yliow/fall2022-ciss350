#include <iostream>
#include <string>

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

// SLList.h, SLList.cpp
class SLList
{
public:
    SLList()
        : phead_(NULL)
    {}
    void insert_head(int key);
    void delete_head();
    SLNode * phead_;
};

void SLList::insert_head(int key)
{
    phead_ = new SLNode(key, phead_);
}

void SLList::delete_head()
{
    if (phead_ != NULL)
    {
        SLNode * t = phead_->next_;
        delete phead_;
        phead_ = t;
    }
}

std::ostream & operator<<(std::ostream & cout,
                          const SLList & list)
{
    // cout << "<SList " << &list << '\n';
    // SLNode * p = list.phead_;
    // while (p != NULL)
    // {
    //     cout << "  " << (*p) << '\n';
    //     p = p->next_;
    // }
    // cout << '>';

    cout << "<SList [";
    std::string delim = ""; 
    SLNode * p = list.phead_;
    while (p != NULL)
    {
        cout << delim << p->key_;
        delim = ", ";
        p = p->next_;
    }
    cout << "]>";

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

    SLList list;
    // std::cout << list.phead_  << '\n';
    // list.insert_head(42);
    // std::cout << list.phead_  << '\n';
    // std::cout << ((*(list.phead_)).key_) << '\n';
    list.insert_head(3);
    list.insert_head(1);
    list.insert_head(0);
    list.insert_head(5);
    std::cout << list << '\n';

    list.delete_head();
    std::cout << list << '\n';
    list.delete_head();
    std::cout << list << '\n';
    list.delete_head();
    std::cout << list << '\n';
    list.delete_head();
    std::cout << list << '\n';
    list.delete_head();
    std::cout << list << '\n';
    
    return 0;
}
