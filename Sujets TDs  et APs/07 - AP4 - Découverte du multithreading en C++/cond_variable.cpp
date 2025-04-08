#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <print>
#include <random>
#include <algorithm>

// Shared Data
std::vector<int>    sharedData{}; 

// Mutex et condition_variable pour synchroniser les threads
std::mutex mutex_shared_data{};
std::condition_variable cv{};

// Random generators
std::random_device rd;  
std::mt19937 gen(rd()); 
std::uniform_int_distribution<int> distrib(-5000,+5000);

template <typename Duration>
void    AddData(Duration period){
    while(true){
        std::this_thread::sleep_for(period);
        int Nb = distrib(gen);
        
        std::unique_lock lock(mutex_shared_data);
        std::println("--> Add data : {0:d} - From : {1:}",Nb,std::this_thread::get_id());
        sharedData.push_back(Nb);
        lock.unlock();

        // Notifier le consommateur que les données sont prêtes
        cv.notify_one();
    }
}

void    SortData(){
    while(true){
        std::println("Sorting thread waiting...");

        std::unique_lock lock(mutex_shared_data);
        // Attendre que la condition 
        cv.wait(lock);
        std::println("--< Sorting thread acting >--");
       
        //std::sort(sharedData.begin(),sharedData.end());   // Non range version
        std::ranges::sort(sharedData);      // ranges version

        std::println("Result : ");
        for(auto Value : sharedData) std::print(" {0:d} ",Value);
        std::println("");
    }
}

int main(){

    std::jthread SortData_th(SortData);
    std::jthread AddData_th1(AddData<std::chrono::seconds>, std::chrono::seconds{1});
    std::jthread AddData_th2(AddData<std::chrono::seconds>, std::chrono::seconds{2});
    return 0;
}



