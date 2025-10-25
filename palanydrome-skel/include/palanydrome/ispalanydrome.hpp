#ifndef PALANYDROME_ISPALANYDROME_HPP
#define PALANYDROME_ISPALANYDROME_HPP
#include <vector>

/** Takes a vector of type T and checks if the vector is a palanydrome
@param userList The vector the user wishes to check
@return a boolean value depending on whether or not the vector is a palanydrome
*/


template<typename T>
bool isPalanydrome(std::vector<T> userList) {
    if( userList.size() <= 1 && userList.size() >= 0) {
        return true;
    }
    if(userList[0] != userList[userList.size()-1]) {
        return false;
    } 
    
    std::vector<T> newList;
    for (int i = 1; i < userList.size()-2; i++) {
            newList.push_back(userList[i]);
        }
        
    if(isPalanydrome(newList)) {
        return true;
    }
}



#endif