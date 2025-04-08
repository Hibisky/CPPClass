#ifndef __NETWORK_CAPTEUR_TEMP_HPP__
#define __NETWORK_CAPTEUR_TEMP_HPP__

#include <thread>
#include <netinet/in.h>
#include <iostream>
#include <print>

#include "CapteurTemp.hpp"

constexpr   int16_t     initTemp = 210; /**< Default initial temperature    */
constexpr   uint16_t    defaultUdpPort = 6666;
constexpr   int         MAXLINE = 80;

class   NetworkException : public std::runtime_error{
    public:
        explicit NetworkException(const std::string& what_arg):std::runtime_error(what_arg){};
} ;

class NetworkCapteurTemp : public CapteurTemp{
    private:
        int16_t RawTemp{initTemp};
        std::jthread    udpServerThread;
        uint16_t    udpPort{0};

        int16_t getRawTemp() const {return this->RawTemp;};
        void    setRawTemp(int16_t temp){this->RawTemp = temp;};

        uint16_t    getudpPort() const {return this->udpPort;};

        void    _serverThread();
    public:

        NetworkCapteurTemp(uint16_t port);
        NetworkCapteurTemp():NetworkCapteurTemp(defaultUdpPort){};
        virtual ~NetworkCapteurTemp() = default;

        virtual float getTemp() const noexcept override {return static_cast<float>(this->getRawTemp())/10.0;};   

};



#endif /*   __NETWORK_CAPTEUR_TEMP_HPP__    */