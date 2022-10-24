#include <iostream>

// DLNode.h
class DLNode
{
public:
    DLNode(int key, DLNode * prev=NULL, DLNode * next=NULL);
//private:
    int key_;
    DLNode * prev_; 
    DLNode * next_;
};

std::ostream & operator<<(std::ostream & cout, const DLNode & node)
{
    cout << "<DLNode " << &node
         << " key:" << node.key_
         << ", prev:" << node.prev_
         << ", next:" << node.next_ << '>';
    return cout;
}

// DLNode.cpp
DLNode::DLNode(int key, DLNode * prev, DLNode * next)
    : key_(key), prev_(prev), next_(next)
{}

// DLList.h
class DLList
{
public:
    DLList()
        : pheadsentinel_(new DLNode(-99)),
          ptailsentinel_(new DLNode(+99))
    {
        pheadsentinel_->next_ = ptailsentinel_;
        ptailsentinel_->prev_ = pheadsentinel_;
    }
//private:
    DLNode * pheadsentinel_;
    DLNode * ptailsentinel_;
};

std::ostream & operator<<(std::ostream & cout,
                          const DLList & list)
{
    cout << "<DLList " << &list << '\n';
    DLNode * p = list.pheadsentinel_;
    while (p != NULL)
    {
        cout << "  " << (*p) << '\n';
        p = p->next_;
    }
    cout << '>';
    return cout;
}

int main()
{
    DLNode n5(5);
    std::cout << "n5:" << n5 << '\n';
    DLList list;
    std::cout << "list: " << list << '\n';
    return 0;
}
