/**
 * @file	stm32f746_resourcemanager.hpp
 * @author	Kyungwoo-Min
 * @date	2020. 6. 23.
 * @brief	
 **/


#ifndef STM32F746_RESOURCEMANAGER_HPP__H__
#define STM32F746_RESOURCEMANAGER_HPP__H__

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "stm32f746.hpp"
#include "stm32f746_busmanager.hpp"
#include "stm32f746_gpiomanager.hpp"

/******************************************************************************
 * Class Declaration
 *****************************************************************************/
class ResourceManager {
public:
    BusManager BusController;
    GPIOResource GPIOManager;
private:
};



#endif /* STM32F746_RESOURCEMANAGER_HPP__H__ */
