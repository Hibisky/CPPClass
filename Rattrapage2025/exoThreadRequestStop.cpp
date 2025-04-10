#include <thread>
#include <random>
#include <algorithm>
#include <iostream>
#include <format>

// Random generators
std::random_device rd;  
std::mt19937 gen(rd()); 
std::uniform_int_distribution<int> distrib(10, 50);

void decomptor(int nb, std::stop_token st, std::stop_source source) {
    while (!st.stop_requested()) {
        for (int i = nb; i > 0; --i) {
            // Simulate some work
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        source.request_stop();
    }
    std::cout << "Comptor finished with nb: " << nb << std::endl; // Message de fin
}

void comptor(int nb, std::stop_token st, std::stop_source source) {
    while (!st.stop_requested()) {
        for (int i = 0; i < nb; ++i) {
            // Simulate some work
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        source.request_stop();
    }
    std::cout << "Comptor finished with nb: " << nb << std::endl; // Message de fin
}

int main() {
    std::stop_source stopSource;
    std::stop_token stopToken = stopSource.get_token();

    auto nb1 = distrib(gen);
    int nb2 = distrib(gen);

    std::jthread decompteur_1([=, &stopSource](std::stop_token st) { decomptor(nb1, st, stopSource); }, stopToken);
    std::jthread decompteur_2([=, &stopSource](std::stop_token st) { comptor(nb2, st, stopSource); }, stopToken);

    decompteur_1.join();
    decompteur_2.join();
    
    return 0;
}