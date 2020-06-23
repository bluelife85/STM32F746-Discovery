/**
 * @file	stm32f746_system.cpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 21.
 * @brief	
 **/

/******************************************************************************
 * Includes
 *****************************************************************************/

#include "stm32f746_system.hpp"

/******************************************************************************
 * System Object Declaration
 *****************************************************************************/

Microcontroller System(PLLSource::HSE, 25000000u, true);

/******************************************************************************
 * Private Methods
 *****************************************************************************/

inline uint8_t Microcontroller::FindPLLM(uint32_t clockSpeed) {
    
    return (clockSpeed / 1000000u);
}

uint8_t Microcontroller::setPLLSource(enum PLLSource type, uint32_t HSE, bool bypass) {
    
    uint8_t PLLM;
    
    if(type == PLLSource::HSI) {
        
        PLLM = this->FindPLLM(16000000u);
        
        RCCReg->PLLCFGR &= 0xFFBFFFFFu;
    }
    else {
        
        PLLM = this->FindPLLM(HSE);
        
        if(bypass) {
            
            RCCReg->CR |= 0x00040000u;
        }
        
        RCCReg->CR |= 0x00010000u;
        
        while((RCCReg->CR & 0x00020000u) != 0x00020000u) {}
        
        RCCReg->PLLCFGR |= 0x00400000u;
    }
    
    return PLLM;
}

/******************************************************************************
 * Private Methods
 *****************************************************************************/

Microcontroller::Microcontroller(enum PLLSource type, uint32_t HSE, bool bypass) {
    
    uint8_t PLLM;
    uint32_t PLLN = 432u;
    uint32_t PLLP = 0u;
    uint32_t PLLQ = 9u;
    
    SCB_EnableICache();
    SCB_EnableDCache();
    
    PLLM = this->setPLLSource(type, HSE, bypass);
    
    RCCReg->PLLCFGR |= PLLM;
    RCCReg->PLLCFGR |= (PLLN << 6u);
    RCCReg->PLLCFGR |= (PLLP << 16u);
    RCCReg->PLLCFGR |= (PLLQ << 24u);
    
    RCCReg->CR |= (0x01000000u);
    
    this->SystemClock = 216000000u;
}