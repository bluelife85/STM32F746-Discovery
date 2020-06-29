/**
 * @file	stm32f746_gpiomanager.cpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 28.
 * @brief	
 **/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "stm32f746_gpiomanager.hpp"

/******************************************************************************
 * Local variable
 *****************************************************************************/
static GPIOInterruptCallbacks EXTICallbacks[16u];

/******************************************************************************
 * Private Methods
 *****************************************************************************/
uint8_t GPIOResource::getIndex(GPIO_TypeDef* port) {
    
    return ((uint32_t)port - AHB1PERIPH_BASE) >> 0x0Au;
}

bool GPIOResource::isAssigned(GPIO_TypeDef* port, uint16_t pin) {
    
    uint8_t index = this->getIndex(port);
    
    return ((this->assignedState[index] & pin) ? true : false);
}

uint8_t GPIOResource::getIndex(uint8_t pin) {
    
    uint8_t ret = 255u;
    
    switch(pin){
    case 0u:
    case 1u:
    case 2u:
    case 3u:
        ret = 0u;
        break;
    case 4u:
    case 5u:
    case 6u:
    case 7u:
        ret = 1u;
        break;
    case 8u:
    case 9u:
    case 10u:
    case 11u:
        ret = 2u;
        break;
    case 12u:
    case 13u:
    case 14u:
    case 15u:
        ret = 3u;
        break;
    default:
        break;
    }
    
    return ret;
}

/******************************************************************************
 * Public Methods
 *****************************************************************************/
GPIOResource::GPIOResource() {
    
    /* DO NOT  CHANGE THIS */
    this->assignedState[0u] = 0xE000u;
    this->assignedState[1u] = 0x0018u;
}

bool GPIOResource::assign(GPIO_TypeDef* port, uint16_t pin) {
    
    uint8_t index = this->getIndex(port);
    
    if(this->isAssigned(port, pin))
        return false;
    
    this->assignedState[index] |= pin;
    return true;
}

bool GPIOResource::release(GPIO_TypeDef* port, uint16_t pin) {
    
    uint8_t index = this->getIndex(port);
    
    if((index == 0u) && (pin & 0xE000u))
        return false;
    
    if((index == 1u) && (pin & 0x0018u))
        return false;
    
    this->assignedState[index] &= ~pin;
    return true;
}

bool GPIOResource::enableInterrupt(GPIO_TypeDef* port, uint8_t pin, 
                                   GPIOInterruptCallbacks callback) {
    
    uint8_t regIndex = this->getIndex(pin);
    uint8_t portIndex = this->getIndex(port);
    
    if(this->isAssigned(port, pin))
        return false;
    
    if(regIndex == 255u)
        return false;
    
    if((port == GPIOAReg) && (pin & 0xE000u))
        return false;
    
    if((port == GPIOBReg) && (pin & 0x0018u))
        return false;
    
    SYSCFGReg->EXTICR[regIndex] |= portIndex << ((pin % 4u) << 2u);
    this->assignedInterrupts[pin] = portIndex + 1u;
    
    this->assign(port, pin);
    EXTICallbacks[pin] = callback;
    
    return true;
}

bool GPIOResource::disableInterrupt(GPIO_TypeDef* port, uint8_t pin) {
    
    uint8_t regIndex = this->getIndex(pin);
    uint8_t portIndex = this->getIndex(port);
    
    if(this->isAssigned(port, pin))
        return false;
    
    if(regIndex == 255u)
        return false;
    
    if((port == GPIOAReg) && (pin & 0xE000u))
        return false;
    
    if((port == GPIOBReg) && (pin & 0x0018u))
        return false;
    
    SYSCFGReg->EXTICR[regIndex] &= ~(0x0Fu << ((pin % 4u)<< 2u));
    this->assignedInterrupts[pin] = 0u;
    
    this->release(port, pin);
    EXTICallbacks[pin] = 0u;
    
    return true;
}

/******************************************************************************
 * Interrupt Vectors
 *****************************************************************************/
void EXTI0_IRQHandler(void) {
    
    if(EXTICallbacks[0u] != 0u) {
        
        EXTICallbacks[0u]();
    }
    
    EXTIReg->PR |= 0x01u;
}

void EXTI1_IRQHandler(void) {
    
    if(EXTICallbacks[1u] != 0u) {
        
        EXTICallbacks[1u]();
    }
    
    EXTIReg->PR |= (1u << 1u);
}

void EXTI2_IRQHandler(void) {
    
    if(EXTICallbacks[2u] != 0u) {
        
        EXTICallbacks[2u]();
    }
    
    EXTIReg->PR |= (1u << 2u);
}

void EXTI3_IRQHandler(void) {
    
    if(EXTICallbacks[3u] != 0u) {
        
        EXTICallbacks[3u]();
    }
    
    EXTIReg->PR |= (1u << 3u);
}

void EXTI4_IRQHandler(void) {
    
    if(EXTICallbacks[4u] != 0u) {
        
        EXTICallbacks[4u]();
    }
    
    EXTIReg->PR |= (1u << 4u);
}

void EXTI9_5_IRQHandler(void) {
    
    if(EXTIReg->PR & (1u << 5u)) {
        
        if(EXTICallbacks[5u] != 0u) {
            
            EXTICallbacks[5u]();
        }
        
        EXTIReg->PR |= (1u << 5u);
    }
    
    if(EXTIReg->PR & (1u << 6u)) {
        
        if(EXTICallbacks[6u] != 0u) {
            
            EXTICallbacks[6u]();
        }
        
        EXTIReg->PR |= (1u << 6u);
    }
    
    if(EXTIReg->PR & (1u << 7u)) {
        
        if(EXTICallbacks[7u] != 0u) {
            
            EXTICallbacks[7u]();
        }
        
        EXTIReg->PR |= (1u << 7u);
    }
    
    if(EXTIReg->PR & (1u << 8u)) {
        
        if(EXTICallbacks[8u] != 0u) {
            
            EXTICallbacks[8u]();
        }
        
        EXTIReg->PR |= (1u << 8u);
    }
    
    if(EXTIReg->PR & (1u << 9u)) {
        
        if(EXTICallbacks[9u] != 0u) {
            
            EXTICallbacks[9u]();
        }
        
        EXTIReg->PR |= (1u << 9u);
    }
}

void EXTI15_10_IRQHandler(void) {
    
    if(EXTIReg->PR & (1u << 10u)) {
        
        if(EXTICallbacks[10u] != 0u) {
            
            EXTICallbacks[10u]();
        }
        
        EXTIReg->PR |= (1u << 10u);
    }
    
    if(EXTIReg->PR & (1u << 11u)) {
        
        if(EXTICallbacks[11u] != 0u) {
            
            EXTICallbacks[11u]();
        }
        
        EXTIReg->PR |= (1u << 11u);
    }
    
    if(EXTIReg->PR & (1u << 12u)) {
        
        if(EXTICallbacks[12u] != 0u) {
            
            EXTICallbacks[12u]();
        }
        
        EXTIReg->PR |= (1u << 12u);
    }
    
    if(EXTIReg->PR & (1u << 13u)) {
        
        if(EXTICallbacks[13u] != 0u) {
            
            EXTICallbacks[13u]();
        }
        
        EXTIReg->PR |= (1u << 13u);
    }
    
    if(EXTIReg->PR & (1u << 14u)) {
        
        if(EXTICallbacks[14u] != 0u) {
            
            EXTICallbacks[14u]();
        }
        
        EXTIReg->PR |= (1u << 14u);
    }
    
    if(EXTIReg->PR & (1u << 15u)) {
        
        if(EXTICallbacks[15u] != 0u) {
            
            EXTICallbacks[15u]();
        }
        
        EXTIReg->PR |= (1u << 15u);
    }
}
