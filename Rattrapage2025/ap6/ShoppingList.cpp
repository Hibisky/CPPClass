#include "ShoppingList.hpp"
#include <iostream>
#include <exception>
#include <thread>

// Méthode pour ajouter un article
void ShoppingList::addItem(const Item& item) {
    std::lock_guard<std::mutex> lock(mtx); // Verrouiller le mutex
    items.push_back(item);
}

// Méthode pour supprimer un article
void ShoppingList::removeItem(int index) {
    std::lock_guard<std::mutex> lock(mtx); // Verrouiller le mutex
    if (index < 0 || index >= items.size()) {
        throw std::out_of_range("Index hors limites");
    }
    items.erase(items.begin() + index);
}

// Méthode pour afficher la liste
void ShoppingList::displayList() {
    std::lock_guard<std::mutex> lock(mtx); // Verrouiller le mutex
    if (items.empty()) {
        throw std::runtime_error("La liste est vide");
    }
    std::cout << "Liste de Courses :\n";
    for (const auto& item : items) {
        item.displayDetails(); // Afficher les détails de chaque article
    }
}

// Méthode pour mettre à jour la liste en temps réel
void ShoppingList::updateList() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Mettre à jour toutes les 5 secondes
        displayList();
    }
}