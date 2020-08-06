/**
 * @file	stm32f746_gpio.cpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 21.
 * @brief	
 **/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "stm32f746_gpio.hpp"

/******************************************************************************
 * Local variable
 *****************************************************************************/
InterruptCallbacks GPIOInterruptCallbacks[16];

/******************************************************************************
 * Private Methods
 *****************************************************************************/
void GPIO::init(uint32_t pin) {
    
    uint32_t i;
    
    for(i = 0u;i < 16; i++,pin >>= 1u){
        
        if(pin & 0x01u) {
            
            if(this->port == GPIOAReg) {
                
                if((i == 13u) || (i == 14u) || (i == 15u))
                    continue;
                
                this->regInit(i);
            }
            else if(this->port == GPIOBReg) {
                
                if((i == 3u) || (i == 4u))
                    continue;
                
                this->regInit(i);
            }
            else {
                
                this->regInit(i);
            }
        }
    }
}

void GPIO::regInit(uint32_t pin) {
    
    this->port->MODER &= ~(0x03u << (pin << 1u));
    this->port->MODER |= ((uint32_t)this->var.mode << (pin << 1u));
    
    this->port->OTYPER &= ~(0x01u << pin);
    this->port->OTYPER |= ((uint32_t)this->var.out << pin);
    
    this->port->OSPEEDR &= ~(0x03u << (pin << 2u));;
    this->port->OSPEEDR |= ((uint32_t)this->var.speed << (pin << 1u));
    
    this->port->PUPDR &= ~(0x03u << (pin << 2u));
    this->port->PUPDR |= ((uint32_t)this->var.pull << (pin << 1u));
}

/******************************************************************************
 * Public Methods
 *****************************************************************************/

GPIO::GPIO(enum AHB1 bus) {
    
    this->port = (GPIO_TypeDef*) (AHB1PERIPH_BASE + (0x400 * (uint32_t) bus));
    this->ctrlAHB1(true, 1, bus);
    
    this->bus = bus;
}

void GPIO::setOutMode(uint32_t pin, enum gpioOutType type, 
                      enum gpioSpeed speed, enum gpioPullState pull) {
    
    this->var.mode = gpioMode::MODE_GPIO;
    this->var.out = type;
    this->var.speed = speed;
    this->var.pull = pull;
    
    this->init(pin);
}

void GPIO::setInMode(uint32_t pin, enum gpioPullState pull) {
    
    this->var.mode = gpioMode::MODE_INPUT;
    this->var.out = gpioOutType::PUSH_PULL;
    this->var.speed = gpioSpeed::SPEED_8MHz;
    this->var.pull = pull;
    
    this->init(pin);
}

void GPIO::setAnalogMode(uint32_t pin) {
    
    this->var.mode = gpioMode::MODE_ANALOG;
    this->var.out = gpioOutType::PUSH_PULL;
    this->var.speed = gpioSpeed::SPEED_8MHz;
    this->var.pull = gpioPullState::NO_PULL;
    
    this->init(pin);
}

void GPIO::enableInterrupt(uint32_t pinNumber,
                    InterruptCallbacks callback, enum gpioTrigger trigger) {
    
    SYSCFGReg->EXTICR[pinNumber / 4u] &= ~(0x0Fu << ((pinNumber % 4u) * 4u));
    SYSCFGReg->EXTICR[pinNumber / 4u] |= (uint32_t) bus << ((pinNumber % 4u) * 4u);
    
    if(trigger == gpioTrigger::TRIGGER_RISING) {
        
        EXTIReg->RTSR |= (1u << pinNumber);
    }
    else if(trigger == gpioTrigger::TRIGGER_FALLING) {
        
        EXTIReg->FTSR |= (1u << pinNumber);
    }
    else if(trigger == gpioTrigger::TRIGGER_BOTH) {
        
        EXTIReg->FTSR |= (1u << pinNumber);
        EXTIReg->RTSR |= (1u << pinNumber);
    }
    
    EXTIReg->IMR |= (1u << pinNumber);
    
    if(pinNumber < 5u) {
        
        NVIC_EnableIRQ((IRQn_Type) (pinNumber + 6u));
    }
    else if((pinNumber >= 5u) && (pinNumber < 10u)) {
        
        NVIC_EnableIRQ(EXTI9_5_IRQn);
    }
    else {
        
        NVIC_EnableIRQ(EXTI15_10_IRQn);
    }
}

void GPIO::disableInterrupt(uint32_t pinNumber) {
    
    EXTIReg->IMR &= ~(1u << pinNumber);
}

void GPIO::control(uint32_t pin, bool state) {
    
    if(state) {
        
        this->port->BSRR |= pin;
    }
    else {
        
        this->port->BSRR |= (pin << 16);
    }
}

bool GPIO::read(uint32_t pin) {
    
    return ((this->port->IDR & pin) == pin) ? true : false;
}

/******************************************************************************
 * Interrupt Vectors
 *****************************************************************************/
void EXTI0_IRQHandler(void) {
    
    if(GPIOInterruptCallbacks[0u] != 0u) {
        
        GPIOInterruptCallbacks[0u]();
    }
    
    EXTIReg->PR |= 0x01u;
}

void EXTI1_IRQHandler(void) {
    
    if(GPIOInterruptCallbacks[1u] != 0u) {
        
        GPIOInterruptCallbacks[1u]();
    }
    
    EXTIReg->PR |= (1u << 1u);
}

void EXTI2_IRQHandler(void) {
    
    if(GPIOInterruptCallbacks[2u] != 0u) {
        
        GPIOInterruptCallbacks[2u]();
    }
    
    EXTIReg->PR |= (1u << 2u);
}

void EXTI3_IRQHandler(void) {
    
    if(GPIOInterruptCallbacks[3u] != 0u) {
        
        GPIOInterruptCallbacks[3u]();
    }
    
    EXTIReg->PR |= (1u << 3u);
}

void EXTI4_IRQHandler(void) {
    
    if(GPIOInterruptCallbacks[4u] != 0u) {
        
        GPIOInterruptCallbacks[4u]();
    }
    
    EXTIReg->PR |= (1u << 4u);
}

void EXTI9_5_IRQHandler(void) {
    
    if(EXTIReg->PR & (1u << 5u)) {
        
        if(GPIOInterruptCallbacks[5u] != 0u) {
            
            GPIOInterruptCallbacks[5u]();
        }
        
        EXTIReg->PR |= (1u << 5u);
    }
    
    if(EXTIReg->PR & (1u << 6u)) {
        
        if(GPIOInterruptCallbacks[6u] != 0u) {
            
            GPIOInterruptCallbacks[6u]();
        }
        
        EXTIReg->PR |= (1u << 6u);
    }
    
    if(EXTIReg->PR & (1u << 7u)) {
        
        if(GPIOInterruptCallbacks[7u] != 0u) {
            
            GPIOInterruptCallbacks[7u]();
        }
        
        EXTIReg->PR |= (1u << 7u);
    }
    
    if(EXTIReg->PR & (1u << 8u)) {
        
        if(GPIOInterruptCallbacks[8u] != 0u) {
            
            GPIOInterruptCallbacks[8u]();
        }
        
        EXTIReg->PR |= (1u << 8u);
    }
    
    if(EXTIReg->PR & (1u << 9u)) {
        
        if(GPIOInterruptCallbacks[9u] != 0u) {
            
            GPIOInterruptCallbacks[9u]();
        }
        
        EXTIReg->PR |= (1u << 9u);
    }
}

void EXTI15_10_IRQHandler(void) {
    
    if(EXTIReg->PR & (1u << 10u)) {
        
        if(GPIOInterruptCallbacks[10u] != 0u) {
            
            GPIOInterruptCallbacks[10u]();
        }
        
        EXTIReg->PR |= (1u << 10u);
    }
    
    if(EXTIReg->PR & (1u << 11u)) {
        
        if(GPIOInterruptCallbacks[11u] != 0u) {
            
            GPIOInterruptCallbacks[11u]();
        }
        
        EXTIReg->PR |= (1u << 11u);
    }
    
    if(EXTIReg->PR & (1u << 12u)) {
        
        if(GPIOInterruptCallbacks[12u] != 0u) {
            
            GPIOInterruptCallbacks[12u]();
        }
        
        EXTIReg->PR |= (1u << 12u);
    }
    
    if(EXTIReg->PR & (1u << 13u)) {
        
        if(GPIOInterruptCallbacks[13u] != 0u) {
            
            GPIOInterruptCallbacks[13u]();
        }
        
        EXTIReg->PR |= (1u << 13u);
    }
    
    if(EXTIReg->PR & (1u << 14u)) {
        
        if(GPIOInterruptCallbacks[14u] != 0u) {
            
            GPIOInterruptCallbacks[14u]();
        }
        
        EXTIReg->PR |= (1u << 14u);
    }
    
    if(EXTIReg->PR & (1u << 15u)) {
        
        if(GPIOInterruptCallbacks[15u] != 0u) {
            
            GPIOInterruptCallbacks[15u]();
        }
        
        EXTIReg->PR |= (1u << 15u);
    }
}
