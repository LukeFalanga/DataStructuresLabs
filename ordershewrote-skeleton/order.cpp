#include <ordershewrote/item.hpp>
#include <ordershewrote/order.hpp>


/** Returns the size of the Bogo order
@return The size of the Bogo order as an int, which will always be 2.
 */

int Bogo::size() const{
    return 2;
}

/** Returns the size of the FlexibleOrder
@return m_size Returns the size of the FlexibleOrder, which will differ based on Items added and removed
*/
 

int FlexibleOrder::size() const {
    return m_size;
}

/**  Adds an item to the FlexibleOrder if it is not already in the list
@param new_item Takes an item to be added to the list by const reference

 */

void FlexibleOrder::add(const Item& new_item) {
    for(auto i = 0; i < m_size; i++){ 
        if(new_item == m_order_list[i]) {
            return;
        }
    }

    Item *new_order_list = new Item[m_size + 1];
    for(auto i = 0; i < m_size; i++) {
        new_order_list[i] = m_order_list[i];
    }

    new_order_list[m_size] = new_item;

    delete[] m_order_list;
    m_order_list = new_order_list;
    m_size++; 

}

/** Removes an item from the FlexibleOrder if it is already in the list
@param old_item Takes an item to be removed from the list by const reference
 */

void FlexibleOrder::remove(const Item& old_item) {
    for(auto i = 0; i < m_size; i++) {
        if(old_item == m_order_list[i]) {

            Item *smaller_list = new Item[m_size - 1];

            for(auto j = 0; j < i; j++) {
                smaller_list[j] = m_order_list[j];
            }
            for(auto j = i; j < m_size - 1; j++) {
                smaller_list[j] = m_order_list[j + 1];
            }

            delete[] m_order_list;
            m_order_list = smaller_list;

            m_size--;
            return;
        }
    }
}
