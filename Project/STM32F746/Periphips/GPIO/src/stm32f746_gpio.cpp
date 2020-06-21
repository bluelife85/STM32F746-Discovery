/**
 * @file	stm32f746_gpio.cpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 21.
 * @brief	
 **/

#include "stm32f746_gpio.hpp"

GPIO::GPIO(GPIO_TypeDef* port, mcuSystem* obj) {
    
    this->object = obj;
    this->pinState = this->object->getAssigned(port);
}



