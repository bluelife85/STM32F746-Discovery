/**
 * @file	stm32f746_system.hpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 21.
 * @brief	
 **/


#ifndef STM32F746_SYSTEM_HPP__H__
#define STM32F746_SYSTEM_HPP__H__

#include "stm32f746.hpp"

class mcuSystem {
public:
    
protected:
    void setPinAssignment(GPIO_TypeDef* port, uint16_t pin);
    void clearPinAssignment(GPIO_TypeDef* port, uint16_t pin);
    bool isAssigned(GPIO_TypeDef* port, uint16_t pin);
    uint16_t getAssigned(GPIO_TypeDef* port, uint16_t pin);
    
private:
    uint16_t pinAssignment[11];
    uint8_t getPortPosition(GPIO_TypeDef* port);
} extern System;


#endif /* STM32F746_SYSTEM_HPP__H__ */
