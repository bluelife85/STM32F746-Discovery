/**
 * @file	stm32f746_busmanager.cpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 23.
 * @brief	
 **/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "stm32f746_busmanager.hpp"

/******************************************************************************
 * Private Methods
 *****************************************************************************/
bool BusManager::checkAHB1List(int32_t bus) {
    
    bool res = false;
    
    switch((enum AHB1List)bus){
    case AHB1List::GPIOA:
    case AHB1List::GPIOB:
    case AHB1List::GPIOC:
    case AHB1List::GPIOD:
    case AHB1List::GPIOE:
    case AHB1List::GPIOF:
    case AHB1List::GPIOG:
    case AHB1List::GPIOH:
    case AHB1List::GPIOI:
    case AHB1List::GPIOJ:
    case AHB1List::GPIOK:
    case AHB1List::BKPSRAM:
    case AHB1List::DTCMRAM:
    case AHB1List::DMA1:
    case AHB1List::DMA2:
    case AHB1List::DMA2D:
    case AHB1List::ETHMAC:
    case AHB1List::ETHMACTX:
    case AHB1List::ETHMACRX:
    case AHB1List::ETHMACPTP:
    case AHB1List::OTGHS:
    case AHB1List::OTGHS_ULPI:
        res = true;
        break;
    default:
        res = false;
        break;
    }
    
    return res;
}

bool BusManager::checkAHB2List(int32_t bus) {
    
    bool res = false;
    
    switch((enum AHB2List)bus){
    case AHB2List::DCMI:
    case AHB2List::RNG:
    case AHB2List::OTGFS:
        res = true;
        break;
    default:
        res = false;
        break;
    }
    
    return res;
}

bool BusManager::checkAHB3List(int32_t bus) {
    
    bool res = false;
    switch((enum AHB3List)bus) {
    case AHB3List::FMC:
    case AHB3List::QSPI:
        res = true;
        break;
    default:
        res = false;
        break;
    }
    return res;
}

bool BusManager::checkAPB1List(int32_t bus) {
    
    bool res = false;
    
    switch((enum APB1List)bus){
    case APB1List::TIM2:
    case APB1List::TIM3:
    case APB1List::TIM4:
    case APB1List::TIM5:
    case APB1List::TIM6:
    case APB1List::TIM7:
    case APB1List::TIM12:
    case APB1List::TIM13:
    case APB1List::TIM14:
    case APB1List::LPTIM1:
    case APB1List::WWDG:
    case APB1List::SPI2:
    case APB1List::SPI3:
    case APB1List::SPDIFRX:
    case APB1List::USART2:
    case APB1List::USART3:
    case APB1List::UART4:
    case APB1List::UART5:
    case APB1List::I2C1:
    case APB1List::I2C2:
    case APB1List::I2C3:
    case APB1List::I2C4:
    case APB1List::CAN1:
    case APB1List::CAN2:
    case APB1List::CEC:
    case APB1List::PWR:
    case APB1List::DAC:
    case APB1List::UART7:
    case APB1List::UART8:
        res = true;
        break;
    default:
        res = false;
        break;
    }
    
    return res;
}

bool BusManager::checkAPB2List(int32_t bus) {
    
    bool res = false;
    
    switch((enum APB2List)bus){
    case APB2List::TIM1:
    case APB2List::TIM8:
    case APB2List::USART1:
    case APB2List::USART6:
    case APB2List::ADC1:
    case APB2List::ADC2:
    case APB2List::ADC3:
    case APB2List::SDMMC:
    case APB2List::SPI1:
    case APB2List::SPI4:
    case APB2List::SYSCFG:
    case APB2List::TIM9:
    case APB2List::TIM10:
    case APB2List::TIM11:
    case APB2List::SPI5:
    case APB2List::SPI6:
    case APB2List::SAI1:
    case APB2List::SAI2:
    case APB2List::LTDC:
        res = true;
        break;
    default:
        res = false;
        break;
    }
    
    return res;
}

/******************************************************************************
 * Public Methods
 *****************************************************************************/
BusManager::BusManager() {
    
    /* enable SYSCFG bit */
    RCCReg->APB2ENR |= (1u << 14u);
}

bool BusManager::ctrlAHB1(bool state, uint32_t count, ...) {
    
    bool res = true;
    uint32_t i;
    va_list ap;
    int list;
    
    va_start(ap, count);
    
    for(i = 0u;i < count; i++){
        
        list = va_arg(ap, int);
        if(!this->checkAHB1List(list)) {
            
            return false;
        }
        
        if(state) {
            
            if((RCCReg->AHB1ENR & (1u << list)) == 0u)
                RCCReg->AHB1ENR |= (1u << list);
        }
        else
            RCCReg->AHB1ENR &= ~(1u << list);
    }
    
    return res;
}

bool BusManager::ctrlAHB2(bool state, uint32_t count, ...) {
    
    bool res = true;
    uint32_t i;
    va_list ap;
    int list;
    
    va_start(ap, count);
    
    for(i = 0u;i < count; i++){
        
        list = va_arg(ap, int);
        if(!this->checkAHB2List(list)) {
            
            return false;
        }
        
        if(state) {
            
            if((RCCReg->AHB2ENR & (1u << list)) == 0u)
                RCCReg->AHB2ENR |= (1u << list);
        }
        else
            RCCReg->AHB2ENR &= ~(1u << list);
    }
    
    return res;
}

bool BusManager::ctrlAHB3(bool state, uint32_t count, ...) {
    
    bool res = true;
    uint32_t i;
    va_list ap;
    int list;
    
    va_start(ap, count);
    
    for(i = 0u;i < count; i++){
        
        list = va_arg(ap, int);
        if(!this->checkAHB3List(list)) {
            
            return false;
        }
        
        if(state)
            if((RCCReg->AHB3ENR & (1u << list)) == 0u)
                RCCReg->AHB3ENR |= (1u << list);
        else
            RCCReg->AHB3ENR &= ~(1u << list);
    }
    
    return res;
}

bool BusManager::ctrlAPB1(bool state, uint32_t count, ...) {
    
    bool res = true;
    uint32_t i;
    va_list ap;
    int list;
    
    va_start(ap, count);
    
    for(i = 0u;i < count; i++){
        
        list = va_arg(ap, int);
        if(!this->checkAPB1List(list)) {
            
            return false;
        }
        
        if(state)
            if((RCCReg->APB1ENR & (1u << list)) == 0u)
                RCCReg->APB1ENR |= (1u << list);
        else
            RCCReg->APB1ENR &= ~(1u << list);
    }
    
    return res;
}

bool BusManager::ctrlAPB2(bool state, uint32_t count, ...) {
    
    bool res = true;
    uint32_t i;
    va_list ap;
    int list;
    
    va_start(ap, count);
    
    for(i = 0u;i < count; i++){
        
        list = va_arg(ap, int);
        if(!this->checkAPB2List(list)) {
            
            return false;
        }
        
        if(state)
            if((RCCReg->APB2ENR & (1u << list)) == 0u)
                RCCReg->APB2ENR |= (1u << list);
        else
            RCCReg->APB2ENR &= ~(1u << list);
    }
    
    return res;
}
