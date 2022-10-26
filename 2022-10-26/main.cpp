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

    void insert_after(DLNode * p, int key)
    {
        // o -> o
        // p    r
        DLNode * r = p->next_;
        DLNode * q = new DLNode(key, p, r);
        // o -> o -> o
        // p    q    r
        // q points to new node
        p->next_ = q;
        r->prev_ = q;
    }

    void insert_head(int key)
    {
        insert_after(pheadsentinel_, key);
    }

    void delete_at(DLNode * p)
    {
        // o -> o -> o
        // q    p    r
        DLNode * q = p->prev_;
        DLNode * r = p->next_;
        q->next_ = r;
        r->prev_ = q;
        delete p;
    }

    void delete_head()
    {
        delete_at(pheadsentinel_->next_);
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

    list.insert_head(5);
    list.insert_head(3);
    list.insert_head(0);
    std::cout << "list: " << list << '\n';

    list.insert_tail(2);
    list.insert_tail(4);
    list.insert_tail(6);
    std::cout << "list: " << list << '\n';

    list.delete_head();
    std::cout << "list: " << list << '\n';
    list.delete_tail();
    std::cout << "list: " << list << '\n';
        
    return 0;
}
