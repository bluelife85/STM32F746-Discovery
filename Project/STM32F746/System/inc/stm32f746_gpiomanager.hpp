/**
 * @file	stm32f746_gpiomanager.hpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 28.
 * @brief	
 **/


#ifndef STM32F746_GPIOMANAGER_HPP__H__
#define STM32F746_GPIOMANAGER_HPP__H__

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "stm32f746.hpp"

/******************************************************************************
 * Type Declaration
 *****************************************************************************/
typedef void (*GPIOInterruptCallbacks)(void);

/******************************************************************************
 * Class Declaration
 *****************************************************************************/
class GPIOResource {
public:
    GPIOResource();
    bool assign(GPIO_TypeDef* port, uint16_t pin);
    bool release(GPIO_TypeDef* port, uint16_t pin);
    
    bool enableInterrupt(GPIO_TypeDef* port, uint8_t pin,
                         GPIOInterruptCallbacks callback);
    bool disableInterrupt(GPIO_TypeDef* port, uint8_t pin);
private:
    uint16_t assignedState[11u];
    uint8_t assignedInterrupts[16u];
    
    
    uint8_t getIndex(GPIO_TypeDef* port);
    uint8_t getIndex(uint8_t pin);
    bool isAssigned(GPIO_TypeDef* port, uint16_t pin);
};

/******************************************************************************
 * Interrupt Vector Prototype
 *****************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
    void EXTI0_IRQHandler(void);
    void EXTI1_IRQHandler(void);
    void EXTI2_IRQHandler(void);
    void EXTI3_IRQHandler(void);
    void EXTI4_IRQHandler(void);
    void EXTI9_5_IRQHandler(void);
    void EXTI15_10_IRQHandler(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* STM32F746_GPIOMANAGER_HPP__H__ */
