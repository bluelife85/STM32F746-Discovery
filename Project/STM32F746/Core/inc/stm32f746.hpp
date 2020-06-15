/**
 * @file	stm32f746.h
 * @author	Kyungwoo-Min
 * @date	2020. 6. 14.
 * @brief	Definition of STM32F746NG without Cryptographic and Hash function
 **/


#ifndef STM32F746_H__H__
#define STM32F746_H__H__

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

/*!< APB1 peripherals */
#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000U)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400U)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800U)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00U)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000U)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400U)
#define TIM12_BASE            (APB1PERIPH_BASE + 0x1800U)
#define TIM13_BASE            (APB1PERIPH_BASE + 0x1C00U)
#define TIM14_BASE            (APB1PERIPH_BASE + 0x2000U)
#define LPTIM1_BASE           (APB1PERIPH_BASE + 0x2400U)
#define RTC_BASE              (APB1PERIPH_BASE + 0x2800U)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x2C00U)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x3000U)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800U)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00U)
#define SPDIFRX_BASE          (APB1PERIPH_BASE + 0x4000U)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400U)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800U)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00U)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000U)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400U)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800U)
#define I2C3_BASE             (APB1PERIPH_BASE + 0x5C00U)
#define I2C4_BASE             (APB1PERIPH_BASE + 0x6000U)
#define CAN1_BASE             (APB1PERIPH_BASE + 0x6400U)
#define CAN2_BASE             (APB1PERIPH_BASE + 0x6800U)
#define CEC_BASE              (APB1PERIPH_BASE + 0x6C00U)
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000U)
#define DAC_BASE              (APB1PERIPH_BASE + 0x7400U)
#define UART7_BASE            (APB1PERIPH_BASE + 0x7800U)
#define UART8_BASE            (APB1PERIPH_BASE + 0x7C00U)

/*!< APB2 peripherals */
#define TIM1_BASE             (APB2PERIPH_BASE + 0x0000U)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x0400U)
#define USART1_BASE           (APB2PERIPH_BASE + 0x1000U)
#define USART6_BASE           (APB2PERIPH_BASE + 0x1400U)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2000U)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x2100U)
#define ADC3_BASE             (APB2PERIPH_BASE + 0x2200U)
#define ADC_BASE              (APB2PERIPH_BASE + 0x2300U)
#define SDMMC1_BASE           (APB2PERIPH_BASE + 0x2C00U)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000U)
#define SPI4_BASE             (APB2PERIPH_BASE + 0x3400U)
#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x3800U)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x3C00U)
#define TIM9_BASE             (APB2PERIPH_BASE + 0x4000U)
#define TIM10_BASE            (APB2PERIPH_BASE + 0x4400U)
#define TIM11_BASE            (APB2PERIPH_BASE + 0x4800U)
#define SPI5_BASE             (APB2PERIPH_BASE + 0x5000U)
#define SPI6_BASE             (APB2PERIPH_BASE + 0x5400U)
#define SAI1_BASE             (APB2PERIPH_BASE + 0x5800U)
#define SAI2_BASE             (APB2PERIPH_BASE + 0x5C00U)
#define SAI1_Block_A_BASE     (SAI1_BASE + 0x004U)
#define SAI1_Block_B_BASE     (SAI1_BASE + 0x024U)
#define SAI2_Block_A_BASE     (SAI2_BASE + 0x004U)
#define SAI2_Block_B_BASE     (SAI2_BASE + 0x024U)
#define LTDC_BASE             (APB2PERIPH_BASE + 0x6800U)
#define LTDC_Layer1_BASE      (LTDC_BASE + 0x84U)
#define LTDC_Layer2_BASE      (LTDC_BASE + 0x104U)
/*!< AHB1 peripherals */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000U)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800U)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00U)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000U)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400U)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800U)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00U)
#define GPIOI_BASE            (AHB1PERIPH_BASE + 0x2000U)
#define GPIOJ_BASE            (AHB1PERIPH_BASE + 0x2400U)
#define GPIOK_BASE            (AHB1PERIPH_BASE + 0x2800U)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800U)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x3C00U)
#define UID_BASE              0x1FF0F420U
#define FLASHSIZE_BASE        0x1FF0F442U
#define PACKAGE_BASE          0x1FFF7BF0U
/* Legacy define */
#define PACKAGESIZE_BASE      PACKAGE_BASE

#define DMA1_BASE             (AHB1PERIPH_BASE + 0x6000U)
#define DMA1_Stream0_BASE     (DMA1_BASE + 0x010U)
#define DMA1_Stream1_BASE     (DMA1_BASE + 0x028U)
#define DMA1_Stream2_BASE     (DMA1_BASE + 0x040U)
#define DMA1_Stream3_BASE     (DMA1_BASE + 0x058U)
#define DMA1_Stream4_BASE     (DMA1_BASE + 0x070U)
#define DMA1_Stream5_BASE     (DMA1_BASE + 0x088U)
#define DMA1_Stream6_BASE     (DMA1_BASE + 0x0A0U)
#define DMA1_Stream7_BASE     (DMA1_BASE + 0x0B8U)
#define DMA2_BASE             (AHB1PERIPH_BASE + 0x6400U)
#define DMA2_Stream0_BASE     (DMA2_BASE + 0x010U)
#define DMA2_Stream1_BASE     (DMA2_BASE + 0x028U)
#define DMA2_Stream2_BASE     (DMA2_BASE + 0x040U)
#define DMA2_Stream3_BASE     (DMA2_BASE + 0x058U)
#define DMA2_Stream4_BASE     (DMA2_BASE + 0x070U)
#define DMA2_Stream5_BASE     (DMA2_BASE + 0x088U)
#define DMA2_Stream6_BASE     (DMA2_BASE + 0x0A0U)
#define DMA2_Stream7_BASE     (DMA2_BASE + 0x0B8U)
#define ETH_BASE              (AHB1PERIPH_BASE + 0x8000U)
#define ETH_MAC_BASE          (ETH_BASE)
#define ETH_MMC_BASE          (ETH_BASE + 0x0100U)
#define ETH_PTP_BASE          (ETH_BASE + 0x0700U)
#define ETH_DMA_BASE          (ETH_BASE + 0x1000U)
#define DMA2D_BASE            (AHB1PERIPH_BASE + 0xB000U)
/*!< AHB2 peripherals */
#define DCMI_BASE             (AHB2PERIPH_BASE + 0x50000U)
#define RNG_BASE              (AHB2PERIPH_BASE + 0x60800U)
/*!< FMC Bankx registers base address */
#define FMC_Bank1_R_BASE      (FMC_R_BASE + 0x0000U)
#define FMC_Bank1E_R_BASE     (FMC_R_BASE + 0x0104U)
#define FMC_Bank3_R_BASE      (FMC_R_BASE + 0x0080U)
#define FMC_Bank5_6_R_BASE    (FMC_R_BASE + 0x0140U)

/* Debug MCU registers base address */
#define DBGMCU_BASE           0xE0042000U

/*!< USB registers base address */
#define USB_OTG_HS_PERIPH_BASE               0x40040000U
#define USB_OTG_FS_PERIPH_BASE               0x50000000U

#define USB_OTG_GLOBAL_BASE                  0x000U
#define USB_OTG_DEVICE_BASE                  0x800U
#define USB_OTG_IN_ENDPOINT_BASE             0x900U
#define USB_OTG_OUT_ENDPOINT_BASE            0xB00U
#define USB_OTG_EP_REG_SIZE                  0x20U
#define USB_OTG_HOST_BASE                    0x400U
#define USB_OTG_HOST_PORT_BASE               0x440U
#define USB_OTG_HOST_CHANNEL_BASE            0x500U
#define USB_OTG_HOST_CHANNEL_SIZE            0x20U
#define USB_OTG_PCGCCTL_BASE                 0xE00U
#define USB_OTG_FIFO_BASE                    0x1000U
#define USB_OTG_FIFO_SIZE                    0x1000U

#endif /* STM32F746_H__H__ */
