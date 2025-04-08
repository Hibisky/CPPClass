#ifndef __EVENT_HPP__
#define __EVENT_HPP__


#include <chrono>

using namespace     std::chrono_literals;

//-----------------------------------------------------------------------------
/**
 * Class Event
 * 
 */
class   Event{
    public:
        using date_of_event_t = std::chrono::time_point<std::chrono::system_clock>; /**< Alias to the  std::chrono::time_point<std::chrono::system_clock> type*/
        /**
         * Event criticity level
         */
        enum class level_t {INFO,       /**< Event criticity = INFO */ 
                            WARNING,    /**< Event criticity = WARNING */
                            ERROR};     /**< Event criticity = ERROR */
    private:
        date_of_event_t     date{};     /**< Event's full date (date and time) */
        std::string         what{};     /**< Event's description  */
        level_t             level{};    /**< Event's criticity level */

        /**
         * @brief : creates a string version of the criticity level
         * 
         * @param level_t level : criticity level
         * 
         * @return std::string ("INFO", "WARNING" or "ERROR")
         */
        [[nodiscard]] std::string getStringLevel(level_t level) const noexcept;

    public:
        /**
         * @brief Default CTOR - defaulted
         */
        Event() = default;  
        /**
         * @brief "Standard" CTOR
         * 
         * @param[in]   const date_of_event_t &date : Event's Date/time
         * @param[in]   const std::string &what : Event's description
         * @param[in]   level_t level : Event's criticity level  
         */
        Event(const date_of_event_t &date,const std::string &what, level_t level):date{date},what{what},level{level}{};

        /**
         * DTOR - defaulted
         */
        virtual ~Event() = default;

        /**
         * @brief getters
         */
        [[nodiscard]]   date_of_event_t getDate() const noexcept {return this->date;};
        [[nodiscard]]   std::string getWhat() const noexcept {return this->what;};
        [[nodiscard]]   level_t     getLevel() const noexcept {return this->level;};

        /**
         * @brief setters
         */
        void    setDate(const date_of_event_t &date) noexcept {this->date = date;};
        void    setWhat(const std::string &what) noexcept {this->what = what;};
        void    setLevel(level_t level) noexcept {this->level = level;};

        /** 
         * @brief "converting" the event to a string
         * 
         * @return  std::string : formatted string representing the event (date, message, level)  
         */
        [[nodiscard]]   std::string toString() const noexcept;

};

#endif      /*  __EVENT_HPP__ */
