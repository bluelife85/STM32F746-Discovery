/**
 * @file	stm32f746_gpio.hpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 21.
 * @brief	
 **/


#ifndef STM32F746_GPIO_HPP__H__
#define STM32F746_GPIO_HPP__H__

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "stm32f746.hpp"
#include "stm32f746_rcc.hpp"

/******************************************************************************
 * public definition
 *****************************************************************************/
#define PIN0                                        (0x00000001u)
#define PIN1                                        (0x00000002u)
#define PIN2                                        (0x00000004u)
#define PIN3                                        (0x00000008u)
#define PIN4                                        (0x00000010u)
#define PIN5                                        (0x00000020u)
#define PIN6                                        (0x00000040u)
#define PIN7                                        (0x00000080u)
#define PIN8                                        (0x00000100u)
#define PIN9                                        (0x00000200u)
#define PIN10                                       (0x00000400u)
#define PIN11                                       (0x00000800u)
#define PIN12                                       (0x00001000u)
#define PIN13                                       (0x00002000u)
#define PIN14                                       (0x00004000u)
#define PIN15                                       (0x00008000u)

#define PIN_NUMBER0                                 (0u)
#define PIN_NUMBER1                                 (1u)
#define PIN_NUMBER2                                 (2u)
#define PIN_NUMBER3                                 (3u)
#define PIN_NUMBER4                                 (4u)
#define PIN_NUMBER5                                 (5u)
#define PIN_NUMBER6                                 (6u)
#define PIN_NUMBER7                                 (7u)
#define PIN_NUMBER8                                 (8u)
#define PIN_NUMBER9                                 (9u)
#define PIN_NUMBER10                                (10u)
#define PIN_NUMBER11                                (11u)
#define PIN_NUMBER12                                (12u)
#define PIN_NUMBER13                                (13u)
#define PIN_NUMBER14                                (14u)
#define PIN_NUMBER15                                (15u)

/******************************************************************************
 * Class Declaration
 *****************************************************************************/
enum class gpioMode {
    MODE_INPUT                      = 0u,
    MODE_GPIO                       = 1u,
    MODE_AF                         = 2u,
    MODE_ANALOG                     = 3u,
};

enum class gpioOutType {
    PUSH_PULL                       = 0u,
    OPEN_DRAIN                      = 1u
};

enum class gpioSpeed {
    SPEED_8MHz                      = 0u,
    SPEED_50MHz                     = 1u,
    SPEED_100MHz                    = 2u,
    SPEED_180MHz                    = 3u
};

enum class gpioPullState {
    NO_PULL                         = 0u,
    PULL_UP                         = 1u,
    PULL_DOWN                       = 2u
};

enum class gpioTrigger {
    TRIGGER_NONE                    = 0u,
    TRIGGER_RISING                  = 1u,
    TRIGGER_FALLING                 = 2u,
    TRIGGER_BOTH                    = 3u
};

class GPIO : private ResetClockControl{
public:
    GPIO(enum AHB1 bus);
    void setOutMode(uint32_t pin, enum gpioOutType type,
                    enum gpioSpeed speed, enum gpioPullState pull);
    void setAnalogMode(uint32_t pin);
    void setInMode(uint32_t pin, enum gpioPullState pull);
    void enableInterrupt(uint32_t pinNumber,
                    InterruptCallbacks callback, enum gpioTrigger trigger);
    void disableInterrupt(uint32_t pinNumber);
    
    void control(uint32_t pin, bool state);
    bool read(uint32_t pin);
private:
    GPIO_TypeDef* port;
    enum AHB1 bus;
    
    struct initStruct {
        gpioMode mode;
        gpioOutType out;
        gpioSpeed speed;
        gpioPullState pull;
    } var;
    
    void init(uint32_t pin);
    void regInit(uint32_t pin);
};

#ifdef __cplusplus
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
void EXTI9_5_IRQHandler(void);
void EXTI15_10_IRQHandler(void);
#endif /* __cplusplus */
#endif /* STM32F746_GPIO_HPP__H__ */
