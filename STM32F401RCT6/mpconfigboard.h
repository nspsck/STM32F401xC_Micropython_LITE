#define MICROPY_HW_BOARD_NAME       ""
#define MICROPY_HW_MCU_NAME         "STM32F401RC"
#define MICROPY_PY_SYS_PLATFORM     ""

// Disabled network realted functions to save space
// Note STM32F411-series does not have ETH-interface
#define MICROPY_PY_SOCKET                       (0)
#define MICROPY_PY_NETWORK                      (0)
#define MICROPY_PY_ONEWIRE                      (0)
#define MICROPY_EMIT_THUMB                      (0)
#define MICROPY_EMIT_INLINE_THUMB               (0)
#define MICROPY_OPT_COMPUTED_GOTO               (0)
#define MICROPY_PY_BUILTINS_COMPLEX             (0)
#define MICROPY_PY_STM                          (0)
#define MICROPY_PY_PYB_LEGACY                   (0)
#define MICROPY_PY_HEAPQ                        (0)
#define MICROPY_PY_FRAMEBUF                     (0)
#define MICROPY_PY_HASHLIB                      (0)
#define MICROPY_PY_JSON                         (0)
#define MICROPY_PY_PLATFORM                     (0)
#define MICROPY_PY_MATH                         (0)
#define MICROPY_PY_COLLECTIONS                  (0)
#define MICROPY_PY_RE                           (0)
#define MICROPY_PY_DEFLATE                      (0)
#define MICROPY_PY_BINASCII_CRC32               (0)
#define MICROPY_PY_SELECT                       (0)
#define MICROPY_PY_ASYNCIO                      (0)
#define MICROPY_PY_UCTYPES                      (0)


// Enabling hardware related features
// For more details check mpconfigboard_common.h
#define MICROPY_HW_HAS_SWITCH                   (1)
#define MICROPY_HW_HAS_FLASH                    (1)
#define MICROPY_HW_ENABLE_RTC                   (1)
#define MICROPY_HW_ENABLE_USB                   (1)
#define MICROPY_HW_ENABLE_TIMER                 (1)

// HSE is 25MHz
#define MICROPY_HW_CLK_PLLM                     (25)
#define MICROPY_HW_CLK_PLLN                     (336)
#define MICROPY_HW_CLK_PLLP                     (4)
#define MICROPY_HW_CLK_PLLQ                     (7)
#define MICROPY_HW_CLK_LAST_FREQ                (1)

// UART config, 
// 12.5 Mbit/s for USART1 and USART6
// 6.25 Mbit/s for USART2
// Not defining the NAMEs reduces firmware size
// Using USART1 will make USB OTG FS only be able to use in either Host or Device mode.
// #define MICROPY_HW_UART1_NAME       "USART1"
#define MICROPY_HW_UART1_TX                     (pin_A9) // Valid: PA9, PB6
#define MICROPY_HW_UART1_RX                     (pin_A10) // Valid: PA10, PB7
// #define MICROPY_HW_UART2_NAME       "USART2"
#define MICROPY_HW_UART2_TX                     (pin_A2) // Valid: PA2
#define MICROPY_HW_UART2_RX                     (pin_A3) // Valid: PA3
// Disabled because interferes with USB OTG FS.
// #define MICROPY_HW_UART6_NAME       "USART6"
#define MICROPY_HW_UART6_TX                     (pin_A11) // Valid: PA11
#define MICROPY_HW_UART6_RX                     (pin_A12) // Valid: PA12

#define MICROPY_HW_UART_REPL        PYB_UART_1
#define MICROPY_HW_UART_REPL_BAUD   115200

// I2C buses
// #define MICROPY_HW_I2C1_NAME        "I2C1"
#define MICROPY_HW_I2C1_SCL                     (pin_B6) // Valid: PB6, PB8
#define MICROPY_HW_I2C1_SDA                     (pin_B7) // Valid: PB7, PB9
// #define MICROPY_HW_I2C2_NAME        "I2C2"
#define MICROPY_HW_I2C2_SCL                     (pin_B10) // Valid: PB10
#define MICROPY_HW_I2C2_SDA                     (pin_B3) // Valid: PB3
// #define MICROPY_HW_I2C3_NAME        "I2C3"
#define MICROPY_HW_I2C3_SCL                     (pin_A8) // Valid: PA8
#define MICROPY_HW_I2C3_SDA                     (pin_B4) // Valid: PB4

// SPI buses
// #define MICROPY_HW_SPI1_NAME        "SPI1"
#define MICROPY_HW_SPI1_NSS                     (pin_A4) // Valid: PA4, PA15
#define MICROPY_HW_SPI1_SCK                     (pin_A5) // Valid: PA5, PB3
#define MICROPY_HW_SPI1_MISO                    (pin_A6) // Valid: PA6, PB4
#define MICROPY_HW_SPI1_MOSI                    (pin_A7) // Valid: PA7, PB5
// #define MICROPY_HW_SPI2_NAME        "SPI2"
#define MICROPY_HW_SPI2_NSS                     (pin_B12) // Valid: PB9, PB12
#define MICROPY_HW_SPI2_SCK                     (pin_B13) // Valid: PB10, PB13 
#define MICROPY_HW_SPI2_MISO                    (pin_B14) // Valid: PB14
#define MICROPY_HW_SPI2_MOSI                    (pin_B15) // Valid: PB15
// #define MICROPY_HW_SPI3_NAME        "SPI3"
#define MICROPY_HW_SPI3_NSS                     (pin_A15) // Valid: PA4, PA15
#define MICROPY_HW_SPI3_SCK                     (pin_B3) // Valid: PB3, PB12
#define MICROPY_HW_SPI3_MISO                    (pin_B4) // Valid: PB4
#define MICROPY_HW_SPI3_MOSI                    (pin_B5) // Valid: PB5

// USRSW has no pullup or pulldown, and pressing the switch makes the input go low
#define MICROPY_HW_USRSW_PIN                    (pin_A0)
#define MICROPY_HW_USRSW_PULL                   (GPIO_PULLUP)
#define MICROPY_HW_USRSW_EXTI_MODE              (GPIO_MODE_IT_RISING)
#define MICROPY_HW_USRSW_PRESSED                (0)

// The pyboard has 4 LEDs
#define MICROPY_HW_LED1                         (pin_C13) // blue
#define MICROPY_HW_LED_ON(pin)                  (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin)                 (mp_hal_pin_high(pin))

// USB config
#define MICROPY_HW_USB_FS           (1)
#define MICROPY_HW_FLASH_FS_LABEL   "f401rc"

#define MICROPY_HW_USB_MANUFACTURER_STRING      "NB"
#define MICROPY_HW_USB_PRODUCT_FS_STRING        "F401RC"
#define MICROPY_HW_USB_CONFIGURATION_FS_STRING  "cfg"
#define MICROPY_HW_USB_INTERFACE_FS_STRING      "if"
// This is to save a tiny little space taken by strings.
#define MICROPY_HW_USB_PRODUCT_HS_STRING        ""
#define MICROPY_HW_USB_CONFIGURATION_HS_STRING  ""
#define MICROPY_HW_USB_INTERFACE_HS_STRING      ""