#include "Items.hpp"

// Constructeur
Item::Item(const std::string& itemName, const std::string& itemBrand, 
           const std::string& itemPurchaseLocation, const std::string& itemTag, 
           const std::string& itemExpirationDate)
    : name(itemName), brand(itemBrand), purchaseLocation(itemPurchaseLocation), 
      tag(itemTag), expirationDate(itemExpirationDate) {}

// Méthodes pour obtenir les attributs
std::string Item::getName() const {
    return name;
}

std::string Item::getBrand() const {
    return brand;
}

std::string Item::getPurchaseLocation() const {
    return purchaseLocation;
}

std::string Item::getTag() const {
    return tag;
}

std::string Item::getExpirationDate() const {
    return expirationDate;
}

// Méthode pour afficher les détails de l'article
void Item::displayDetails() const {
    std::cout << "Article: " << name << ", Marque: " << brand 
              << ", Lieu d'achat: " << purchaseLocation 
              << ", Tag: " << tag 
              << ", Date de péremption: " << expirationDate << std::endl;
}