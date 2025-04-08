#include "Event.hpp"

//-----------------------------------------------------------------------------
std::string Event::getStringLevel(level_t level) const noexcept{
    switch (level)
    {
    case level_t::ERROR : return "ERROR";break;
    case level_t::INFO : return "INFO";break;
    case level_t::WARNING : return "WARNING";break;
    default: return "__err__level_not_defined__";
    }
}
//-----------------------------------------------------------------------------
std::string Event::toString() const noexcept{
    std::string msg = std::format("{:%Y-%m-%d %H:%M:%S}", this->getDate());;

    msg = msg + " -> " + this->getWhat() + "(" + this->getStringLevel(this->getLevel()) + ")";

    return msg;
}
//-----------------------------------------------------------------------------


