#include <thread>
#include <mutex>
#include <array>
#include <chrono>
#include <print>
#include <random>

using namespace std::chrono_literals;

// Random generators
std::random_device rd;  
std::default_random_engine gen(rd()); 
std::uniform_int_distribution<int> distrib(0,20);

// Shared Data
constexpr   unsigned int    ARRAY_SIZE{5};
std::array<int,ARRAY_SIZE>    sharedData{}; 
unsigned int    wrIndex{0};

// Mutex et condition_variable pour synchroniser les threads
std::mutex mutex_shared_data{};

void    addData(){
    while(true){
        std::this_thread::sleep_for(500ms);

        int Nb = distrib(gen);

        if (wrIndex < (ARRAY_SIZE-1)) wrIndex++;
        else wrIndex = 0;

        std::scoped_lock lock(mutex_shared_data);
        std::println("Writing {0:d} at index {1:d}.",Nb,wrIndex);
        sharedData.at(wrIndex) = Nb;
    }
}
void    Moyenneur(){
    while(true){
        std::this_thread::sleep_for(1300ms);

        std::scoped_lock lock(mutex_shared_data);
        float Moyenne = (std::accumulate(sharedData.begin(), sharedData.end(),0) / static_cast<float>(ARRAY_SIZE));
        std::println ("Moyenne = {:0.2f}",Moyenne);

    }
}

int main() {
    std::jthread t1(Moyenneur);
    std::jthread t2(addData);

return 0;
}





