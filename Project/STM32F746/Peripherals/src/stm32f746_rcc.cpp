/**
 * @file	stm32f746_rcc.cpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 21.
 * @brief	
 **/

/******************************************************************************
 * Includes
 *****************************************************************************/

#include "stm32f746_rcc.hpp"

/******************************************************************************
 * System Object Declaration
 *****************************************************************************/

ResetClockControl RCC(PLLSource::HSE, 25000000u, true);


/******************************************************************************
 * Private Methods
 *****************************************************************************/

__INLINE uint8_t ResetClockControl::findPLLM(uint32_t clockSpeed) {
    
    return (clockSpeed / 1000000u);
}

uint8_t ResetClockControl::setPLLSource(enum PLLSource type, uint32_t HSE,
                                      bool bypass) {
    
    uint8_t PLLM;
    
    if(type == PLLSource::HSI) {
        
        PLLM = this->findPLLM(16000000u);
        
        RCCReg->PLLCFGR &= 0xFFBFFFFFu;
    }
    else {
        
        PLLM = this->findPLLM(HSE);
        
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
 * Public Methods
 *****************************************************************************/
ResetClockControl::ResetClockControl() {
}

ResetClockControl::ResetClockControl(enum PLLSource type, uint32_t HSE,
                                 bool bypass) {
    
    uint8_t PLLM;
    uint32_t PLLN = 432u;
    uint32_t PLLP = 0u;
    uint32_t PLLQ = 9u;
    
#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));
#endif
    RCCReg->CR |= (uint32_t)0x00000001;
    
    RCCReg->CFGR = 0x00000000;
    
    RCCReg->CR &= (uint32_t)0xFEF6FFFF;
    
    RCCReg->PLLCFGR = 0x24003010;
    
    RCCReg->CR &= (uint32_t)0xFFFBFFFF;
    
    RCCReg->CIR = 0x00000000;
    
#ifdef VECT_TAB_SRAM
    SCB->VTOR = SRAM1_BASE;
#else
    SCB->VTOR = FLASH_BASE;
#endif
    
    SCB_EnableICache();
    SCB_EnableDCache();
    
    PLLM = this->setPLLSource(type, HSE, bypass);
    
    RCCReg->PLLCFGR |= PLLM;
    RCCReg->PLLCFGR |= (PLLN << 6u);
    RCCReg->PLLCFGR |= (PLLP << 16u);
    RCCReg->PLLCFGR |= (PLLQ << 24u);
    
    RCCReg->CR |= (0x01000000u);
    while((RCCReg->CR & 0x02000000u) != 0x02000000u) {}
    
    this->ctrlAPB1(true, 1, APB1::PWR);
    
    PWRReg->CR1 |= (1u << 16u);
    while((PWRReg->CSR1 & 0x00010000u) != 0x00010000u) {}
    PWRReg->CR1 |= (1u << 17u);
    while((PWRReg->CSR1 & 0x00020000u) != 0x00020000u) {}
    
    this->SystemClock = 216000000u;
    
    FLASHReg->ACR |= 0x00000100u;
    FLASHReg->ACR |= 0x07u;
    
    RCCReg->CFGR &= 0xFFFFFF0Fu;
    RCCReg->CFGR |= (0x000000005u << 10u);
    RCCReg->CFGR |= (0x000000004u << 13u);
    
    RCCReg->CFGR |= 0x02u;
    while((RCCReg->CFGR & 0x00000008u) != 0x00000008u) {}
    
    this->ctrlAPB2(true, 1, APB2::SYSCFG);
}

void ResetClockControl::swapFMCMapping(bool state) {
    
    if(state) 
        SYSCFGReg->MEMRMP |= (1u << 10u);
    else
        SYSCFGReg->MEMRMP &= ~(1u << 10u);
}

bool ResetClockControl::ctrlAHB1(bool state, uint32_t count, ...) {
    
    bool res = true;
    uint32_t i;
    va_list ap;
    int list;
    
    va_start(ap, count);
    
    for(i = 0u;i < count; i++){
        
        list = va_arg(ap, int);
        
        if(state) {
            
            if((RCCReg->AHB1ENR & (1u << list)) == 0u)
                RCCReg->AHB1ENR |= (1u << list);
        }
        else
            RCCReg->AHB1ENR &= ~(1u << list);
    }
    
    return res;
}

bool ResetClockControl::ctrlAHB2(bool state, uint32_t count, ...) {
    
    bool res = true;
    uint32_t i;
    va_list ap;
    int list;
    
    va_start(ap, count);
    
    for(i = 0u;i < count; i++){
        
        list = va_arg(ap, int);
        
        if(state) {
            
            if((RCCReg->AHB2ENR & (1u << list)) == 0u)
                RCCReg->AHB2ENR |= (1u << list);
        }
        else
            RCCReg->AHB2ENR &= ~(1u << list);
    }
    
    return res;
}

bool ResetClockControl::ctrlAHB3(bool state, uint32_t count, ...) {
    
    bool res = true;
    uint32_t i;
    va_list ap;
    int list;
    
    va_start(ap, count);
    
    for(i = 0u;i < count; i++){
        
        list = va_arg(ap, int);
        
        if(state)
            if((RCCReg->AHB3ENR & (1u << list)) == 0u)
                RCCReg->AHB3ENR |= (1u << list);
        else
            RCCReg->AHB3ENR &= ~(1u << list);
    }
    
    return res;
}

bool ResetClockControl::ctrlAPB1(bool state, uint32_t count, ...) {
    
    bool res = true;
    uint32_t i;
    va_list ap;
    int list;
    
    va_start(ap, count);
    
    for(i = 0u;i < count; i++){
        
        list = va_arg(ap, int);
        
        if(state)
            if((RCCReg->APB1ENR & (1u << list)) == 0u)
                RCCReg->APB1ENR |= (1u << list);
        else
            RCCReg->APB1ENR &= ~(1u << list);
    }
    
    return res;
}

bool ResetClockControl::ctrlAPB2(bool state, uint32_t count, ...) {
    
    bool res = true;
    uint32_t i;
    va_list ap;
    int list;
    
    va_start(ap, count);
    
    for(i = 0u;i < count; i++){
        
        list = va_arg(ap, int);
        
        if(state)
            if((RCCReg->APB2ENR & (1u << list)) == 0u)
                RCCReg->APB2ENR |= (1u << list);
        else
            RCCReg->APB2ENR &= ~(1u << list);
    }
    
    return res;
}
