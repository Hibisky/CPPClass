#include <print>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

//#define DUMB_CANCELLATION_VERSION
#define COOPERATIVE_CANCELLATION_VERSION

#ifdef  DUMB_CANCELLATION_VERSION
bool    stop{false};

void Cancelable() 
{
    int i{0};
    std::println("--Cancelable thread starting --");
    while(!stop){
            std::println("Message #{0:d} from Cancelable",i++);
            std::this_thread::sleep_for(1s);
    }
    std::println("--Cancelable thread has been cancelled --");
}

void Cancelator(int Nb)
{
    std::println("--Cancelator thread starting --");
    for(int i=0;i<Nb;++i){
            std::println("Message #{0:d}/{1:d} from Cancelator",i,Nb);
            std::this_thread::sleep_for(1500ms);
    }
    std::println("--Cancelator thread ending - Sets cancellation flag --");
    stop = true;
}

int main(){

    std::println("Demo C++ Thread cancelation - Dumb version (always works!)");

    stop = false;   /**< Ensure cancelation flag is false */
    std::jthread first (Cancelable);     

    std::jthread second (Cancelator,5); 

    while(true){
        std::this_thread::sleep_for(1s);
        std::println("Hello, I'm the main...");
    }

    return 0;
}
#endif  /* DUMB_CANCELLATION_VERSION    */


#ifdef  COOPERATIVE_CANCELLATION_VERSION
void Cancelable(std::stop_token st) 
{
    int i{0};
    std::println("--Cancelable thread starting --");
    while(!st.stop_requested()){
            std::println("Message #{0:d} from Cancelable",i++);
            std::this_thread::sleep_for(1s);
    }
    std::println("--Cancelable thread has been cancelled --");
}

void Cancelator(std::stop_source source, int Nb)
{
    std::println("--Cancelator thread starting --");
    for(int i=0;i<Nb;++i){
            std::println("Message #{0:d}/{1:d} from Cancelator",i,Nb);
            std::this_thread::sleep_for(1500ms);
    }
    std::println("--Cancelator thread ending - Sets cancellation flag --");
    source.request_stop();
}


int main(){
    // Create a stop_source and get its corresponding stop_token
    std::stop_source stopSource;
    std::stop_token stopToken = stopSource.get_token();

    std::println("Demo C++ Thread cancelation - Cooperative cancellation");

    std::jthread first (Cancelable,stopToken);     
    std::jthread second (Cancelator,std::move(stopSource),5); 

    while(true){
        std::this_thread::sleep_for(1s);
        std::println("Hello, I'm the main...");
    }

    return 0;
}




#endif  /*  COOPERATIVE_CANCELLATION_VERSION    */

