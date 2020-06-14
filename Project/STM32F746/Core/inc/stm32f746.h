/**
 * @file	stm32f746.h
 * @author	Kyungwoo-Min
 * @date	2020. 6. 14.
 * @brief	Definition of STM32F746NG without Cryptographic and Hash function
 **/


#ifndef STM32F746_H__H__
#define STM32F746_H__H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum {
	/******  Cortex-M7 Processor Exceptions Numbers ****************************************************************/
	NonMaskableInt_IRQn         = -14,
	MemoryManagement_IRQn       = -12,
	BusFault_IRQn               = -11,
	UsageFault_IRQn             = -10,
	SVCall_IRQn                 = -5,
	DebugMonitor_IRQn           = -4,
	PendSV_IRQn                 = -2,
	SysTick_IRQn                = -1,
	/******  STM32 specific Interrupt Numbers **********************************************************************/
	WWDG_IRQn                   = 0,
	PVD_IRQn                    = 1,
	TAMP_STAMP_IRQn             = 2,
	RTC_WKUP_IRQn               = 3,
	FLASH_IRQn                  = 4,
	RCC_IRQn                    = 5,
	EXTI0_IRQn                  = 6,
	EXTI1_IRQn                  = 7,
	EXTI2_IRQn                  = 8,
	EXTI3_IRQn                  = 9,
	EXTI4_IRQn                  = 10,
	DMA1_Stream0_IRQn           = 11,
	DMA1_Stream1_IRQn           = 12,
	DMA1_Stream2_IRQn           = 13,
	DMA1_Stream3_IRQn           = 14,
	DMA1_Stream4_IRQn           = 15,
	DMA1_Stream5_IRQn           = 16,
	DMA1_Stream6_IRQn           = 17,
	ADC_IRQn                    = 18,
	CAN1_TX_IRQn                = 19,
	CAN1_RX0_IRQn               = 20,
	CAN1_RX1_IRQn               = 21,
	CAN1_SCE_IRQn               = 22,
	EXTI9_5_IRQn                = 23,
	TIM1_BRK_TIM9_IRQn          = 24,
	TIM1_UP_TIM10_IRQn          = 25,
	TIM1_TRG_COM_TIM11_IRQn     = 26,
	TIM1_CC_IRQn                = 27,
	TIM2_IRQn                   = 28,
	TIM3_IRQn                   = 29,
	TIM4_IRQn                   = 30,
	I2C1_EV_IRQn                = 31,
	I2C1_ER_IRQn                = 32,
	I2C2_EV_IRQn                = 33,
	I2C2_ER_IRQn                = 34,
	SPI1_IRQn                   = 35,
	SPI2_IRQn                   = 36,
	USART1_IRQn                 = 37,
	USART2_IRQn                 = 38,
	USART3_IRQn                 = 39,
	EXTI15_10_IRQn              = 40,
	RTC_Alarm_IRQn              = 41,
	OTG_FS_WKUP_IRQn            = 42,
	TIM8_BRK_TIM12_IRQn         = 43,
	TIM8_UP_TIM13_IRQn          = 44,
	TIM8_TRG_COM_TIM14_IRQn     = 45,
	TIM8_CC_IRQn                = 46,
	DMA1_Stream7_IRQn           = 47,
	FMC_IRQn                    = 48,
	SDMMC1_IRQn                 = 49,
	TIM5_IRQn                   = 50,
	SPI3_IRQn                   = 51,
	UART4_IRQn                  = 52,
	UART5_IRQn                  = 53,
	TIM6_DAC_IRQn               = 54,
	TIM7_IRQn                   = 55,
	DMA2_Stream0_IRQn           = 56,
	DMA2_Stream1_IRQn           = 57,
	DMA2_Stream2_IRQn           = 58,
	DMA2_Stream3_IRQn           = 59,
	DMA2_Stream4_IRQn           = 60,
	ETH_IRQn                    = 61,
	ETH_WKUP_IRQn               = 62,
	CAN2_TX_IRQn                = 63,
	CAN2_RX0_IRQn               = 64,
	CAN2_RX1_IRQn               = 65,
	CAN2_SCE_IRQn               = 66,
	OTG_FS_IRQn                 = 67,
	DMA2_Stream5_IRQn           = 68,
	DMA2_Stream6_IRQn           = 69,
	DMA2_Stream7_IRQn           = 70,
	USART6_IRQn                 = 71,
	I2C3_EV_IRQn                = 72,
	I2C3_ER_IRQn                = 73,
	OTG_HS_EP1_OUT_IRQn         = 74,
	OTG_HS_EP1_IN_IRQn          = 75,
	OTG_HS_WKUP_IRQn            = 76,
	OTG_HS_IRQn                 = 77,
	DCMI_IRQn                   = 78,
	RNG_IRQn                    = 80,
	FPU_IRQn                    = 81,
	UART7_IRQn                  = 82,
	UART8_IRQn                  = 83,
	SPI4_IRQn                   = 84,
	SPI5_IRQn                   = 85,
	SPI6_IRQn                   = 86,
	SAI1_IRQn                   = 87,
	LTDC_IRQn                   = 88,
	LTDC_ER_IRQn                = 89,
	DMA2D_IRQn                  = 90,
	SAI2_IRQn                   = 91,
	QUADSPI_IRQn                = 92,
	LPTIM1_IRQn                 = 93,
	CEC_IRQn                    = 94,
	I2C4_EV_IRQn                = 95,
	I2C4_ER_IRQn                = 96,
	SPDIF_RX_IRQn               = 97,
} IRQn_Type;

#define __CM7_REV                 0x0001U
#define __MPU_PRESENT             1
#define __NVIC_PRIO_BITS          4
#define __Vendor_SysTickConfig    0
#define __FPU_PRESENT             1
#define __ICACHE_PRESENT          1
#define __DCACHE_PRESENT          1

#include "core_cm7.h"
#include <stdint.h>

/* Memory information */
#define RAMITCM_BASE           0x00000000U
#define FLASHITCM_BASE         0x00200000U
#define FLASHAXI_BASE          0x08000000U
#define RAMDTCM_BASE           0x20000000U
#define PERIPH_BASE            0x40000000U
#define BKPSRAM_BASE           0x40024000U
#define QSPI_BASE              0x90000000U
#define FMC_R_BASE             0xA0000000U
#define QSPI_R_BASE            0xA0001000U
#define SRAM1_BASE             0x20010000U
#define SRAM2_BASE             0x2004C000U
#define FLASH_END              0x080FFFFFU
#define FLASH_OTP_BASE         0x1FF0F000U
#define FLASH_OTP_END          0x1FF0F41FU

/* Legacy define */
#define FLASH_BASE     FLASHAXI_BASE

/* Peripheral bus address */
#define APB1PERIPH_BASE        PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000U)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000U)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000U)

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* STM32F746_H__H__ */
