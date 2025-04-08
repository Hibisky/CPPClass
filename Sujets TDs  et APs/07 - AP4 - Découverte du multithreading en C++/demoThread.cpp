#include <print>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

#define THREAD_VERSION
//#define JTHREAD_VERSION

void foo() 
{
  for(int i=0;i<10;++i){
        std::println("Message #{0:d} from foo",i);
        std::this_thread::sleep_for(1s);
  }
}

void bar(int Nb)
{
  for(int i=0;i<Nb;++i){
        std::println("Message #{0:d}/{1:d} from bar",i,Nb);
        std::this_thread::sleep_for(1500ms);
  }
}


#ifdef  THREAD_VERSION
int main(){

    std::println("Demo C++ Thread (STL)");

    std::thread first (foo);     // spawn new thread that calls foo()
    std::thread second (bar,5);  // spawn new thread that calls bar(5)

    // synchronize threads - try without joining... :)
    first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes
    

    return 0;
}
#endif


#ifdef  JTHREAD_VERSION
int main(){

    std::println("Demo C++ Thread (STL)");

    std::jthread first (foo);     // spawn new thread that calls foo()
    std::jthread second (bar,5);  // spawn new thread that calls bar(5)

    return 0;
}
#endif
