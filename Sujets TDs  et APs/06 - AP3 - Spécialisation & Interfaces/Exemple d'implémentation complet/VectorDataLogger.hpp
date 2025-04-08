#ifndef __VECTOR_DATA_LOGGER_HPP__
#define __VECTOR_DATA_LOGGER_HPP__

#include "DataLogger.hpp"
#include <print>

//-----------------------------------------------------------------------------
class   VectorDataLogger : public SortableDataLogger{
    private:
        std::vector<Event>    log{};
    
    public:
        VectorDataLogger() = default;
        virtual ~VectorDataLogger() = default;

        virtual void    AddEvent(Event &evt, bool setInternalTime = false) override;     
        virtual void    dumpLog() override;
        [[nodiscard]] virtual  std::size_t getNbEvents() override {return this->log.size();};
        virtual void    sortByDate(bool ascending = true) override;
        virtual void    sortByCriticity(bool ascending = true) override;
        virtual void    sortByWhat(bool ascending = true) override;
};



#endif

