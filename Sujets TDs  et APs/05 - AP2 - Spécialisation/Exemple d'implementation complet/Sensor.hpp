#ifndef __SENSOR_HPP__
#define __SENSOR_HPP__

#include <cstdint>
#include <string>
#include <concepts>
#include <print>
#include <random>   // for the "fakes" sensors 

//----------------------------------------------------------------------------
template <typename OutputType>
concept Numeric = std::is_arithmetic_v<OutputType>; /**< Use of concepts to ensure Output value is a numeric type */

/**
 * Class Sensor
 *  Abstract class - Template 
 */
template <Numeric OutputType>
class Sensor{

private:
    const uint32_t UID{};           /**< Each Sensor has a Unique ID (32 bits) */
    const std::string   Unit{};     /**< Unit of the output, or any message helping to interpret Output Value  */
    OutputType outputValue{};       /**< OutputValue type is linked to the template type  */
protected:
    
    /**
     * Setter for OutputValue.
     */
    void setOutputValue(OutputType newValue) noexcept {this->outputValue = newValue;};
    
public:
    Sensor() = delete;  /**< Ctor by default is deleted */
    /**
     * @brief   "Standard" Ctor
     * 
     * @param   uint32_t uid : uid for the new Sensor
     * @param   const std::string &unit : unit for the new sensor     * 
     *     
     */
    Sensor(uint32_t uid, const std::string &unit):UID{uid},Unit{unit}{};

    virtual ~Sensor() = default;    /**< Dtor is defaulted */

    /**
     * Getters
     */
    [[nodiscard]] const std::string getUnit() const noexcept {return this->Unit;};
    [[nodiscard]] uint32_t  getUID() const noexcept {return this->UID;};
    [[nodiscard]] OutputType getOutputValue() const noexcept {return this->outputValue;};

    /**
     * @brief Call to this function manages the real (physical) sensor to get a new output value. 
     */
    virtual void    elaborateNewValue() = 0;   /**< Pure virtual method -> class is now abract */ 

    /**
     *  @brief  Prints the outout value and the unit message.
     */
    void    dump() const noexcept {std::println("{} {}",this->getOutputValue,this->getUnit());};
};
//----------------------------------------------------------------------------
/**
 * ADT7310 concrete Sensor class
 */
class ADT7310 : public Sensor<uint16_t>{
    public:
        enum class ADT7310Mode {    MODE13BITS,     /**< Sensor is used in 13 bits mode */
                                    MODE16BITS      /**< Sensor is used in 16 bits mode */
        };
    private:
        ADT7310Mode  Mode{ADT7310Mode::MODE13BITS}; /**< Sensor mode (13/13 bits) */
    public:
        ADT7310() = delete;     /**< Default Ctor is deleted */
        explicit ADT7310(uint32_t uid):Sensor<uint16_t>(uid,"LSB 0.0625°C (Signed 13 bits mode) or LSB 0.0078°C (Signed 16 bits mode)"){};  
        virtual ~ADT7310() = default;

        void        setMode(ADT7310Mode Mode) noexcept {this->Mode = Mode;};
        ADT7310Mode getMode() const noexcept {return this->Mode;}; 

        virtual void    elaborateNewValue() override;

        double  getConvertedTemperature() const noexcept;
};
//----------------------------------------------------------------------------
template <Numeric OutputType>
class GenericTempCelciusSensor : public Sensor<OutputType>{
    private:

    public:
        GenericTempCelciusSensor() = delete;
        virtual ~GenericTempCelciusSensor() = default;

        explicit GenericTempCelciusSensor(uint32_t uid):Sensor<OutputType>(uid,"°C"){};

        virtual void    elaborateNewValue() = 0;
};
//----------------------------------------------------------------------------
constexpr   uint32_t    TC74_UUID{0x7400484F};

class TC74 : public GenericTempCelciusSensor<int8_t>{
    private:
        const uint8_t i2c_address{};
    public:
        TC74() = delete;
        virtual ~TC74() = default;
        explicit TC74(uint8_t addr):GenericTempCelciusSensor<int8_t>{TC74_UUID},i2c_address{addr}{};

        uint8_t getI2Caddress() const noexcept {return this->i2c_address;};

        virtual void    elaborateNewValue() override;
};
//----------------------------------------------------------------------------
constexpr   uint32_t    LM35_UUID{0x35000000};

class LM35 : public GenericTempCelciusSensor<double>{
    private:
        
    public:
        LM35():GenericTempCelciusSensor<double>{LM35_UUID}{};
        virtual ~LM35() = default;
        
        virtual void    elaborateNewValue() override;
};
//----------------------------------------------------------------------------


#endif  /*  __SENSOR_HPP__  */