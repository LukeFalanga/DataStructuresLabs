#ifndef BEADEDBAG_BEADEDBAG_HPP
#define BEADEDBAG_BEADEDBAG_HPP

#include <regex>
#include <string>
#include <vector>
#include <iostream>

/**
 * \class Shippable
 *
 * Anything that is shippable must have a volume and a name. 
 */

class Shippable {

public:
  

  /**
   * get_volume()
   *
   * Get the volume of the item shipped.
   *
   * \return The volume of the item shipped.
   */
  virtual double get_volume() const = 0;

  /**
   * get_name()
   *
   * Get the name of the item shipped.
   *
   * \return The name of the item shipped.
   */
  virtual std::string get_name() const = 0;

};

/**
 * \class FastFashionPackage
 *
 * A FastFashionPackage is a Shippable item where
 * every item has a name and a volume. 
 *
 */

class FastFashionPackage : public Shippable {
  public:
    FastFashionPackage(std::string item_name, double item_volume) : m_name(item_name), m_volume(item_volume) {}

    double get_volume() const override {
      return m_volume;
    }

    std::string get_name() const override {
      return m_name;
    }

  private:
  const std::string m_name;
  const double m_volume;

};

class Electronics : public Shippable {
  public:
  Electronics(std::string item_name) : m_name(item_name){}
  double get_volume() const override {
    return m_volume;
  }

  std::string get_name() const override {
    return m_name;
  }

  private: 
  const std::string m_name;
  const double m_volume = 4;

};

template <typename T>
class Teu {
public:
  Teu(std::string address, double max_volume) : m_address(address) , m_maxVolume(max_volume)  {}

/*
* get_manifest()
*
* Takes the vector of strings (manifest) and turns it into a single string with each item separated by a comma
*
* \return The item manifest (itemList)
*/

  std::string get_manifest() const {
    std::string itemList;
    for(int i = 0; i < manifest.size(); i++) {
      itemList.append(manifest[i]);
      if(i != manifest.size() - 1) {
        itemList.append(", ");
      }
    }
    
    return itemList;
   
  }

/*
* add_to_container(T to_ship)
*
* Checks the volume of the item to ship, and if it will fit it adds the item to the container, including volume to tonnage and name to the manifest
*
* \return true if the item is able to be added, false if it is not
*/

  bool add_to_container(T to_ship) {
    if((tonnage + to_ship.get_volume()) <= m_maxVolume) {
      manifest.push_back(to_ship.get_name());
      tonnage += to_ship.get_volume();
     
      return true;

    } else {
      return false;
    }
    
  }

/*
* get_tonnage()
*
* Gets the current tonnage of the container
*
* \return The tonnage of the container.
*/

  double get_tonnage() const {
    return tonnage;
  }

private:
  const double m_maxVolume;
  const std::string m_address;
  std::vector<std::string> manifest;
  double tonnage;
};

#endif
