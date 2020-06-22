/**
 * @file	stm32f746_system.cpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 21.
 * @brief	
 **/

#include "stm32f746_system.hpp"

/**
 * system object
 */
mcuSystem System;

/**
 * private methods
 */

/**
 * public methods
 */

uint8_t mcuSystem::getPortPosition(GPIO_TypeDef* port) {
    
    return ((uint32_t)port - AHB1PERIPH_BASE) >> 0x0Au;
}

void mcuSystem::setPinAssignment(GPIO_TypeDef* port, uint16_t pin) {
    
    uint8_t index = this->getPortPosition(port);
    
    this->pinAssignment[index] |= pin;
}

void mcuSystem::clearPinAssignment(GPIO_TypeDef* port, uint16_t pin) {
    
    uint8_t index = this->getPortPosition(port);
    
    this->pinAssignment[index] &= (uint16_t)(~(pin));
}

bool mcuSystem::isAssigned(GPIO_TypeDef* port, uint16_t pin) {
    
    uint8_t index = this->getPortPosition(port);
    
    return (this->pinAssignment[index] & pin) ? true : false;
}

uint16_t mcuSystem::getAssigned(GPIO_TypeDef* port) {
    
    uint8_t index = this->getPortPosition(port);
    
    return this->pinAssignment[index];
}

