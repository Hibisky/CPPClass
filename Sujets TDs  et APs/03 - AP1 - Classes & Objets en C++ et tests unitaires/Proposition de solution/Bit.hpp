/**
 *	@file	Bit.hpp
 * 	@brief 	Bit class header file
 * 	@author	Alexis ROLLAND
 * 	@date	2023-01
 * 
 */
#ifndef __BIT_H__
#define	__BIT_H__

#include <cstdint>
#include <string>
#include <iostream>

class Bit{
	public:
	/**
	*	Type bit_t 
	* 	enum as imbricated class
	*/
	enum class bit_t:std::int8_t {	SET,	/**< Bit is SET (High, '1',...)		*/
									CLEAR,	/**< Bit is CLEAR (Low, '0',...)	*/
									HIZ,	/**< Bit is in High Impedance state (unconnected)*/
									X		/**< Bit is in unknown state 	*/
	};		
	
	private:
	bit_t	Value{bit_t::X};		/**< bit value, only attribute. Initialized with in-class initializer at X */	
	
	/**
	* Private Setter for Value 
	* 
	* constexpr :	forces the compiler to try to compute at compile time
	* noexcept : this method throws no exception 
	*/
	constexpr void	setValue(bit_t _Value) noexcept {this->Value = _Value;};
	
	
	public:
	/**
	* 	Special Member Funcions (FMR)
	* 	When the rule of Five leads to rule of Zero
	*/
	Bit() = default;														/**<  No explicit default Ctor. Force compiler to provide and use use the "by default" generated */
	explicit Bit(bit_t InitialValue) noexcept :Value{InitialValue}{};		/**<	Ctor with initial bit value. Single argument -> make explicit to avoid implicit conversions */
	
	Bit 	(const Bit&)  = default ;										/**< 	default copy ctor	*/
	Bit& 	operator=(const Bit&) = default ; 								/**< 	Default copy assignment operator	*/
	
	Bit		(Bit&&) noexcept = default;										/**<	Default move Ctor	*/
	Bit&	operator=(Bit&&) = default;										/**< 	Default move assignement operator 	*/
	
	virtual ~Bit() = default;												/**< 	Default Dtor	*/
	//------------------------------------------------------------------
	
	/**
	 * getter (public) for the bit value 
	 * 
	 * constexpr :	forces the compiler to try to compute at compile time
	 * const : callable with a const Bit type  
	 * noexcept : this method throws no exception
	 * [[nodiscard]] here for preventing users to get rid of the return value (compiler warning in this case).
	 * 
	 * @return Bit value (bit_t)
	 */
	[[nodiscard]] constexpr bit_t	getValue() const noexcept {return this->Value;};	
	
	/**
	 *	toString "classic" method 
	 * 	const : callable with a const Bit type  
	 * 	noexcept : this method throws no exception
	 * 	[[nodiscard]] here for preventing users to get rid of the return value (compiler warning in this case).
	 *  
	 *  @return String reprsenting the Bit value. Using the string_view type in place of "classic" string to avoit object copy for const strings.
	 */
	[[nodiscard]] std::string_view	toString() const noexcept;	  
	
	/** 
	 * Public setters for Bit value
	 * 
	 * noexcept : these methods throw no exception
	 * The four services are constexpr to take opportunity to evaluate them at compile time
	 * 
	 */ 
	constexpr void	set() noexcept {this->setValue(bit_t::SET);};			/**< 	set to SET		*/
	constexpr void	clear() noexcept {this->setValue(bit_t::CLEAR);};		/**< 	set to CLEAR	*/
	constexpr void	unregister() noexcept {this->setValue(bit_t::X);};		/**< 	set to X		*/
	constexpr void	disconnect() noexcept {this->setValue(bit_t::HIZ);};	/**< 	set to HIZ		*/

};
/**
 * Overloading of the << operator. Must be obviously outside the class, 
 * but not friend function because calling a public service (toString).
 *
 * noexcept : this method throws no exception
 */  
std::ostream& operator<<(std::ostream& os, const Bit& bit) noexcept;	

#endif

