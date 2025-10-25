#ifndef ORDERSHEWROTE_ORDER_HPP
#define ORDERSHEWROTE_ORDER_HPP

#include <iostream>
#include <ordershewrote/item.hpp>

class Order {
    public:
    virtual int size() const = 0;
    };

class Bogo : public Order {
    public:
    Bogo(const Item& paid, const Item& free) : m_paid(paid), m_free(free) {}

    int size() const override;

    private:
    Item m_paid;
    Item m_free;

};

class FlexibleOrder : public Order {
    public:
    FlexibleOrder() : m_size(0), m_order_list{nullptr} {}

    void add(const Item& new_item);

    void remove(const Item& old_item);

    int size() const override;

    ~FlexibleOrder() {
        delete[] m_order_list;
        m_size = 0;
    }

    private:
    int m_size;
    Item *m_order_list;

};

#endif
