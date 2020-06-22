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
    enum pullState {
        PULL_STATE_NO           = 0x00u,
        PULL_STATE_PULL_UP      = 0x01u,
        PULL_STATE_PULL_DOWN    = 0x02u
    };
    GPIO(GPIO_TypeDef* port, mcuSystem* obj = &System);
    void setOutput(enum pullState pull, uint8_t nbrOfPin, ...);
private:
    uint16_t pinState;
    mcuSystem* object;
    GPIO_TypeDef* port;
};



#endif /* STM32F746_GPIO_HPP__H__ */
