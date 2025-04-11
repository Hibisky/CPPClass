#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>

class Item {
private:
    std::string name;          // Nom de l'article
    std::string brand;         // Marque de l'article
    std::string purchaseLocation; // Lieu d'achat
    std::string tag;           // Tag pour catégoriser l'article
    std::string expirationDate; // Date de péremption

public:
    // Constructeur
    Item(const std::string& itemName, const std::string& itemBrand, 
         const std::string& itemPurchaseLocation, const std::string& itemTag, 
         const std::string& itemExpirationDate);

    // Méthodes pour obtenir les attributs
    std::string getName() const;
    std::string getBrand() const;
    std::string getPurchaseLocation() const;
    std::string getTag() const;
    std::string getExpirationDate() const;

    // Méthode pour afficher les détails de l'article
    void displayDetails() const;
};

#endif // ITEM_HPP