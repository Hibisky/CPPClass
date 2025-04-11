/**
 *	@file		appThermostat_main.cpp
 * 	@brief 		main for the Thermostat App 
 * 	@author		
 * 	@date		
 * 
 */
#include <iostream>
#include <memory>
#include <thread>
#include <random>
#include <algorithm>
#include <format>
#include <chrono>
#include "Items.hpp"
#include "ShoppingList.hpp"


#include "ShoppingList.hpp"
#include <thread>
#include <iostream>

int main() {
    ShoppingList myList;

    // Ajout d'articles
    myList.addItem(Item("Pommes", "Golden", "Supermarché A", "Fruits", "2023-12-01"));
    myList.addItem(Item("Bananes", "Chiquita", "Supermarché B", "Fruits", "2023-11-15"));
    myList.addItem(Item("Lait", "Laiterie X", "Supermarché C", "Dairy", "2023-10-30"));

    // Lancer le thread pour mettre à jour la liste
    std::jthread updater(&ShoppingList::updateList, &myList);

    // Suppression d'un article
    try {
        myList.removeItem(1); // Supprime "Bananes"
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    // Afficher la liste
    try {
        myList.displayList();
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    // Attendre que l'utilisateur termine
    std::this_thread::sleep_for(std::chrono::seconds(20)); // Laisser le thread s'exécuter pendant 20 secondes

    return 0;
}