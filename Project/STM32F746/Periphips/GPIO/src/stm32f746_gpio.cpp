/**
 * @file	stm32f746_gpio.cpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 21.
 * @brief	
 **/

#include "stm32f746_gpio.hpp"

GPIO::GPIO(GPIO_TypeDef* port, mcuSystem* obj) {
    
    this->object = obj;
    this->port = port;
    this->pinState = this->object->getAssigned(port);
}

void GPIO::setOutput(enum pullState pull, uint8_t nbrOfPin, ...) {
    
    uint8_t i;
    va_list args;
    uint8_t param;
    
    try {
        if(nbrOfPin > 16)
            throw nbrOfPin;
        va_start(args, nbrOfPin);
        
        for(i = 0;i < nbrOfPin; i++) {
            
            param = va_arg(args, int);
            
            if(param > 15)
                throw param;
            else {
                this->port->MODER &= ~(0x03u << (param << 1));
                this->port->MODER |= (0x01u << (param << 1));
                
                this->port->OTYPER &= ~(1 << param);
                
                this->port->OSPEEDR &= ~(0x03u << (param << 1));
                this->port->OSPEEDR |= (0x02u << (param << 1));
                
                switch(pull) {
                case PULL_STATE_NO:
                    this->port->PUPDR &= ~(0x03u << (param << 1));
                    break;
                default:
                    this->port->PUPDR &= ~(0x03u << (param << 1));
                    this->port->PUPDR |= ((uint8_t)pull << (param << 1));
                    break;
                }
            }
        }
    }
    catch(uint8_t e) {
        
        // TODO trace exception
    }
}


