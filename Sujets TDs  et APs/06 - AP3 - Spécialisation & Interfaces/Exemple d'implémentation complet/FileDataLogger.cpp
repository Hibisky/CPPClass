#include "FileDataLogger.hpp"

//-----------------------------------------------------------------------------
void    FileDataLogger::AddEvent(Event &evt, bool setInternalTime){
    if (setInternalTime){
        evt.setDate(this->getInternalClock());
    }
    else{
        if (evt.getDate() == Event::date_of_event_t{}) throw std::invalid_argument{"Date of event not provided."};
    }   

    std::ofstream logstream(this->getFilePath(), std::ios::app);  /** Open in append mode - No need to close : RAII object */
    logstream << evt.toString() << std::endl;
}
//-----------------------------------------------------------------------------
void    FileDataLogger::dumpLog(){
    std::ifstream logstream(this->getFilePath());
    std::string line{};

    while (std::getline(logstream, line)) std::println("{}",line);

}
//-----------------------------------------------------------------------------
std::size_t FileDataLogger::getNbEvents(){
    std::ifstream logstream(this->getFilePath());
    std::string line{};

    unsigned int nbLines= 0;  // Initializing a variable to count lines

    while (std::getline(logstream, line)) nbLines++;

    return nbLines;
}
//-----------------------------------------------------------------------------
