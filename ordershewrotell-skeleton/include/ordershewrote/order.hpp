#ifndef ORDERSHEWROTE_ORDER_HPP
#define ORDERSHEWROTE_ORDER_HPP

#include <iostream>
#include <ordershewrote/item.hpp>
#include <ordershewrote/linkedlist.hpp>

class Order {
    public:

    /** Returns the size of the Order as a virtual int that = 0
    @return 0 
    */

    virtual int size() const = 0;
    };

class Bogo : public Order {
    public:

    /** Constructs a Bogo order
    @param paid The item that the user is paying for
    @param free The item that the user is receiving for free
     */

    Bogo(const Item& paid, const Item& free) : m_paid(paid), m_free(free) {}

    /** Returns the size of the Bogo order
    @return The size of the Bogo order, which will always be 2
     */

    int size() const override;

    private:
    Item m_paid;
    Item m_free;

};

class FlexibleOrder : public Order {
    public:


    /** Constructs a flexible order with size 0 and a head node equal to a null pointer
     */
    FlexibleOrder() : m_size(0), m_head{nullptr} {}

    /** Adds an item to the FlexibleOrder if it does not already exist within it, and increments m_size by 1.
    @param new_item Is the item to be added to the linked list
    */

    void add(const Item& new_item);

    /** Removes an item from the FlexibleOrder linked list if it already exists within it, and decrements m_size by 1
    @param old_item is the item to be removed from the linked list
    */

    void remove(const Item& old_item);

    /** Overrides the Order size() function and returns the size of the FlexibleOrder linked list
    @return m_size, the size of the linked list
     */

    int size() const override;

    /** Destructor that frees the linked list of FlexibleOrder
     */

    ~FlexibleOrder() {
        auto iterator = m_head;
        while(iterator) {
            auto temp = iterator;
            iterator = iterator->next;
            delete temp;
        }
    }
    

    private:
    int m_size;
    Node<Item> *m_head;

};

#endif
