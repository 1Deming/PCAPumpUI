/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once


#include <stdint.h>
#include <stdbool.h>
/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif

int8_t ERT_drv_gpio_init(void);

#define ERT_drv_gpio_set_dir_output bsp_gpio_set_dir_output
#define ERT_drv_gpio_set_dir_input bsp_gpio_set_dir_input
#define ERT_drv_gpio_output_set bsp_gpio_output_set
#define ERT_drv_gpio_output_clear bsp_gpio_output_clear
#define ERT_drv_gpio_input_is_high bsp_gpio_input_is_high
#define ERT_drv_gpio_output_is_high bsp_gpio_output_is_high


#ifdef __cplusplus
}
#endif

















  




#ifdef __cplusplus
}
#endif

