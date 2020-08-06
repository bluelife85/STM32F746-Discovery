/**
 * @file	stm32f746_rcc.hpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 21.
 * @brief	
 **/


#ifndef STM32F746_RCC_HPP__H__
#define STM32F746_RCC_HPP__H__

/******************************************************************************
 * Includes
 *****************************************************************************/

#include "stm32f746.hpp"

/******************************************************************************
 * Class Declaration
 *****************************************************************************/

/* Oscillator source */
enum class PLLSource {
    HSE,
    HSI
};

/* Bus */
enum class AHB1 {
    GPIOA                       = 0u,
    GPIOB                       = 1u,
    GPIOC                       = 2u,
    GPIOD                       = 3u,
    GPIOE                       = 4u,
    GPIOF                       = 5u,
    GPIOG                       = 6u,
    GPIOH                       = 7u,
    GPIOI                       = 8u,
    GPIOJ                       = 9u,
    GPIOK                       = 10u,
    BKPSRAM                     = 18u,
    DTCMRAM                     = 20u,
    DMA1                        = 21u,
    DMA2                        = 22u,
    DMA2D                       = 23u,
    ETHMAC                      = 25u,
    ETHMACTX                    = 26u,
    ETHMACRX                    = 27u,
    ETHMACPTP                   = 28u,
    OTGHS                       = 29u,
    OTGHS_ULPI                  = 30u
};

enum class AHB2 {
    DCMI                        = 0u,
    RNG                         = 6u,
    OTGFS                       = 7u
};

enum class AHB3 {
    FMC                         = 0u,
    QSPI                        = 1u
};

enum class APB1 {
    TIM2                        = 0u,
    TIM3                        = 1u,
    TIM4                        = 2u,
    TIM5                        = 3u,
    TIM6                        = 4u,
    TIM7                        = 5u,
    TIM12                       = 6u,
    TIM13                       = 7u,
    TIM14                       = 8u,
    LPTIM1                      = 9u,
    WWDG                        = 11u,
    SPI2                        = 14u,
    SPI3                        = 15u,
    SPDIFRX                     = 16u,
    USART2                      = 17u,
    USART3                      = 18u,
    UART4                       = 19u,
    UART5                       = 20u,
    I2C1                        = 21u,
    I2C2                        = 22u,
    I2C3                        = 23u,
    I2C4                        = 24u,
    CAN1                        = 25u,
    CAN2                        = 26u,
    CEC                         = 27u,
    PWR                         = 28u,
    DAC                         = 29u,
    UART7                       = 30u,
    UART8                       = 31u
};

enum class APB2 {
    TIM1                        = 0u,
    TIM8                        = 1u,
    USART1                      = 4u,
    USART6                      = 5u,
    ADC1                        = 8u,
    ADC2                        = 9u,
    ADC3                        = 10u,
    SDMMC                       = 11u,
    SPI1                        = 12u,
    SPI4                        = 13u,
    SYSCFG                      = 14u,
    TIM9                        = 16u,
    TIM10                       = 17u,
    TIM11                       = 18u,
    SPI5                        = 20u,
    SPI6                        = 21u,
    SAI1                        = 22u,
    SAI2                        = 23u,
    LTDC                        = 26u
};

class ResetClockControl {
public:
    ResetClockControl();
    ResetClockControl(enum PLLSource type, uint32_t HSE, bool bypass);
    
    __INLINE uint32_t getCPUSpeed(void) {
        
        return this->SystemClock;
    }
    
    void swapFMCMapping(bool state);
    
    bool ctrlAHB1(bool state, uint32_t count, ...);
    bool ctrlAHB2(bool state, uint32_t count, ...);
    bool ctrlAHB3(bool state, uint32_t count, ...);
    bool ctrlAPB1(bool state, uint32_t count, ...);
    bool ctrlAPB2(bool state, uint32_t count, ...);
private:
    uint32_t SystemClock = 16000000u;
    
    __INLINE uint8_t findPLLM(uint32_t clockSpeed);
    uint8_t setPLLSource(enum PLLSource type, uint32_t HSE, bool bypass);
} extern RCC;

#endif /* STM32F746_RCC_HPP__H__ */
