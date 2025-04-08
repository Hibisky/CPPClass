#ifndef __FILEDATALOGGER_HPP__
#define __FILEDATALOGGER_HPP__

#include <fstream>
#include <filesystem>
#include <ranges>
#include <exception>
#include "DataLogger.hpp"

/**
 * Class FileDataLogger
 * 
 * If the log file doesn't exist, it's created, otherwise Events are appended to the file. 
 */
class FileDataLogger : public DataLogger{
private:
    const   std::filesystem::path logFilePath{};   
    std::filesystem::path getFilePath() const noexcept {return this->logFilePath;}; 
public:
    FileDataLogger() = delete;
    explicit FileDataLogger(const std::string &FileName):logFilePath{FileName}{};
    virtual ~FileDataLogger() = default;

    virtual void    AddEvent(Event &evt, bool setInternalTime = false) override;     
    virtual void    dumpLog() override;
    [[nodiscard]] virtual  std::size_t getNbEvents() override;    
};


#endif  /*  __FILEDATALOGGER_HPP__  */


