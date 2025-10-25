#include <ordershewrote/item.hpp>
#include <ordershewrote/order.hpp>
#include <ordershewrote/linkedlist.hpp>

//Implementation of size
int Bogo::size() const{
    return 2;
}

int FlexibleOrder::size() const {
    return m_size;
}

//Implementation of FlexibleOrder add

void FlexibleOrder::add(const Item& new_item) {
    auto iterator = m_head;
    while (iterator) {
        if(iterator->value == new_item) {
            return;
        }
        iterator = iterator->next;
    }

    Node<Item> *addedItem = new Node<Item>{};

    addedItem->value = new_item;
    addedItem->next = m_head;
    m_head = addedItem;
    
    m_size++; 

}

//Implementation of FlexibleOrder remove

void FlexibleOrder::remove(const Item& old_item) {
    auto iterator = m_head;

    if(!iterator) {
        return;
    }

    if(iterator->value == old_item) {
        m_head = iterator->next;
        delete iterator;
        m_size--;
        return;
    }

    while(iterator->next) {
        if(iterator->next->value != old_item) {
            iterator = iterator->next;
            continue;
        }
        auto itemToRemove = iterator->next;
        
        iterator->next = iterator->next->next;
        
        delete itemToRemove;
        m_size--;
        return;
    }

}
    

