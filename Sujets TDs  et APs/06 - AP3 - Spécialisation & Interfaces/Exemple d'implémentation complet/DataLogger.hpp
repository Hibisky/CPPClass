#ifndef __DATALOGGER_HPP__
#define __DATALOGGER_HPP__

#include "Event.hpp"

#include <exception>
#include <chrono>
#include <algorithm>
#include <print>

using namespace     std::chrono_literals;

//-----------------------------------------------------------------------------
/**
 * Class DataLogger
 * 
 * Non Sortable generic data logger
 */
class   DataLogger{
    private:
        std::chrono::system_clock   internalClock{}; 
    protected:
        [[nodiscard]]   Event::date_of_event_t getInternalClock() noexcept {return this->internalClock.now();};
    public:
        DataLogger() = default;
        virtual ~DataLogger() = default;

        virtual void    AddEvent(Event &evt , bool setInternalTime = false) = 0;
        virtual void    dumpLog() = 0;
        virtual std::size_t    getNbEvents() = 0;
};
//-----------------------------------------------------------------------------
/**
 * Class SortableDataLogger
 * 
 * Sortable generic data logger - Data structure MUST be sortable
 * (ie Vector...)
 */
class SortableDataLogger : public DataLogger{
    private:

    protected:

    public:
        SortableDataLogger() = default;
        virtual ~SortableDataLogger() = default;

        virtual void    sortByDate(bool ascending = true) = 0;
        virtual void    sortByCriticity(bool ascending = true) = 0;
        virtual void    sortByWhat(bool ascending = true) = 0;
};
//-----------------------------------------------------------------------------











#endif  /*  __DATALOGGER_HPP__  */