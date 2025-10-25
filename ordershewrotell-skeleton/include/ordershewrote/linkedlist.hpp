#ifndef ORDERSHEWROTE_LINKEDLIST_HPP
#define ORDERSHEWROTE_LINKEDLIST_HPP

#include <ordershewrote/item.hpp>

template <typename Item>
class Node {
    public:
    Item value;
    Node *next;
};

#endif