/**
 * @file	stm32f746_gpio.hpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 21.
 * @brief	
 **/


#ifndef STM32F746_GPIO_HPP__H__
#define STM32F746_GPIO_HPP__H__

#include "stm32f746_system.hpp"

class GPIO : mcuSystem {
public:
    GPIO(GPIO_TypeDef* port, mcuSystem* obj = &System);
private:
    uint16_t pinState;
    mcuSystem* object;
};



#endif /* STM32F746_GPIO_HPP__H__ */
