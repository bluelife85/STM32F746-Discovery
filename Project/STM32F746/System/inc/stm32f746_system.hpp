/**
 * @file	stm32f746_system.hpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 21.
 * @brief	
 **/


#ifndef STM32F746_SYSTEM_HPP__H__
#define STM32F746_SYSTEM_HPP__H__

/******************************************************************************
 * Includes
 *****************************************************************************/

#include "stm32f746.hpp"
#include "stm32f746_resourcemanager.hpp"

/******************************************************************************
 * Class Declaration
 *****************************************************************************/

/* Oscillator source */
enum class PLLSource {
    HSE,
    HSI
};

class Microcontroller : public ResourceManager {
public:
    Microcontroller(enum PLLSource type, uint32_t HSE, bool bypass);
    __INLINE uint32_t getCPUSpeed(void) {
        
        return this->SystemClock;
    }
    
    void swapFMCMapping(bool state);
private:
    uint32_t SystemClock = 16000000u;
    
    inline uint8_t findPLLM(uint32_t clockSpeed);
    uint8_t setPLLSource(enum PLLSource type, uint32_t HSE, bool bypass);
} extern System;

#endif /* STM32F746_SYSTEM_HPP__H__ */
