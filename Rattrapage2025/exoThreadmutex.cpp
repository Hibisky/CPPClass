#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
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
std::uniform_int_distribution<int> distrib(10,50);
 
template <typename Duration>
int    AddData(int sizeVector){
    for (int i = nb; i > 0; ++i){
       
        int nb = distrib(gen);
       
        std::unique_lock lock(mutex_shared_data);
        std::println("--> Add data : {0:d} - From : {1:}",nb,std::this_thread::get_id());
        sharedData.push_back(nb);
        lock.unlock();
 
        // Notifier le consommateur que les données sont prêtes
        cv.notify_one();
    }
    return
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
 
void decomptor(std::stop_token st, std::stop_source source) {
    while (!st.stop_requested()) {
        for (int i = nb; i > 0; --i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        source.request_stop();
    }
    std::cout << "Comptor finished with nb: " << nb << std::endl; // Message de fin
}
 
void comptVector(std::stop_token st, std::stop_source source)
{
   
}
 
void decomptVector(std::stop_token st, std::stop_source source)
{
   
}
 
int main() {
    std::stop_source stopSource;
    std::stop_token stopToken = stopSource.get_token();
 
    auto sizeVector = distrib(gen);
   
    std::vector<int>    {};
 
    std::jthread creaVector(AddData<std::chrono::seconds>, sizeVector, std::chrono::seconds{1});
    creaVector.join();
   
    std::jthread decompteur_1([=, &stopSource](std::stop_token st) { decomptor( st, stopSource); }, stopToken);
    std::jthread decompteur_2([=, &stopSource](std::stop_token st) { decomptor( st, stopSource); }, stopToken);
 
    decompteur_1.join();
    decompteur_2.join();
   
    return 0;
}