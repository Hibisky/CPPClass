#include "VectorDataLogger.hpp"

//-----------------------------------------------------------------------------
void    VectorDataLogger::AddEvent(Event &evt, bool setInternalTime){
    if (setInternalTime){
        evt.setDate(this->getInternalClock());
    }
    else{
        if (evt.getDate() == Event::date_of_event_t{}) throw std::invalid_argument{"Date of event not provided."};
    }   

    this->log.push_back(evt);
}
//-----------------------------------------------------------------------------
void    VectorDataLogger::dumpLog(){
    for(auto it : this->log){
        std::println("{}",it.toString());
    }
}
//-----------------------------------------------------------------------------
void    VectorDataLogger::sortByDate(bool ascending){
    if (ascending){
        std::sort(this->log.begin(), this->log.end(), [](const Event &a, const Event &b)
                                                    {
                                                    return a.getDate() < b.getDate();
                                                    });
    }
    else{
        std::sort(this->log.begin(), this->log.end(), [](const Event &a, const Event &b)
                                                    {
                                                    return a.getDate() > b.getDate();
                                                    });
    }
}
//-----------------------------------------------------------------------------    
void    VectorDataLogger::sortByCriticity(bool ascending) {
    if (ascending){
        std::sort(this->log.begin(), this->log.end(), [](const Event &a, const Event &b)
                                                    {
                                                    return a.getLevel() < b.getLevel();
                                                    });
    }
    else{
        std::sort(this->log.begin(), this->log.end(), [](const Event &a, const Event &b)
                                                    {
                                                    return a.getLevel() > b.getLevel();
                                                    });
    }
}
//-----------------------------------------------------------------------------
void    VectorDataLogger::sortByWhat(bool ascending){
    if (ascending){
        std::sort(this->log.begin(), this->log.end(), [](const Event &a, const Event &b)
                                                    {
                                                    return a.getWhat() < b.getWhat();
                                                    });
    }
    else{
        std::sort(this->log.begin(), this->log.end(), [](const Event &a, const Event &b)
                                                    {
                                                    return a.getWhat() > b.getWhat();
                                                    });
    }
    
}
//-----------------------------------------------------------------------------


