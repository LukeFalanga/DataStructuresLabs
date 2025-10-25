#ifndef ORDERSHEWROTE_CANCOURIERTAKE_HPP
#define ORDERSHEWROTE_CANCOURIERTAKE_HPP

#include <ordershewrote/order.hpp>

bool canCourierTake(const Order &to_deliver, int fit) {
    if(to_deliver.size() <= fit) {
        return true;
    } else {
        return false;
    }
}

#endif
