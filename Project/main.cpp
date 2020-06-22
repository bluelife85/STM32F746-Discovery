#include "stm32f746.hpp"
#include "stm32f746_system.hpp"

#include "stm32f746_gpio.hpp"

int main(void) {
    
    GPIO GPIOI(GPIOIReg);
    
    GPIOI.setOutput(GPIO::PULL_STATE_NO, 17, 17);
    while(1) {
    }
}
