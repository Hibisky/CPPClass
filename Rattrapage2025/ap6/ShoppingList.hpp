#ifndef SHOPPINGLIST_HPP
#define SHOPPINGLIST_HPP

#include <vector>
#include <mutex>
#include "Items.hpp"

class ShoppingList {
private:
    std::vector<Item> items; // Utilisation de la classe Item
    std::mutex mtx; // Mutex pour la synchronisation

public:
    // Méthode pour ajouter un article
    void addItem(const Item& item);

    // Méthode pour supprimer un article
    void removeItem(int index);

    // Méthode pour afficher la liste
    void displayList();

    // Méthode pour mettre à jour la liste en temps réel
    void updateList();
};

#endif // SHOPPINGLIST_HPP