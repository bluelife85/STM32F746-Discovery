#include "stm32f746.hpp"

#include "stm32f746_gpio.hpp"

int main(void) {
    
    GPIO GPIOI(AHB1::GPIOI);
    
    GPIOI.setOutMode(PIN1, gpioOutType::PUSH_PULL,
                     gpioSpeed::SPEED_100MHz, gpioPullState::NO_PULL);
    
    while(1) {
    }
}
