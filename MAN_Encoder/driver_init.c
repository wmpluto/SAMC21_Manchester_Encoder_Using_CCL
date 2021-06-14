/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>

struct spi_m_dma_descriptor SPI_0;

void DIGITAL_GLUE_LOGIC_0_PORT_init(void)
{

	gpio_set_pin_function(PA09, PINMUX_PA09I_CCL_IN4);

	gpio_set_pin_function(PA11, PINMUX_PA11I_CCL_OUT1);
}

void DIGITAL_GLUE_LOGIC_0_CLOCK_init(void)
{
	hri_mclk_set_APBCMASK_CCL_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, CCL_GCLK_ID, CONF_GCLK_CCL_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
}

void DIGITAL_GLUE_LOGIC_0_init(void)
{
	DIGITAL_GLUE_LOGIC_0_CLOCK_init();
	custom_logic_init();
	DIGITAL_GLUE_LOGIC_0_PORT_init();
}

void SPI_0_PORT_init(void)
{

	gpio_set_pin_level(PA16,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA16, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA16, PINMUX_PA16C_SERCOM1_PAD0);

	gpio_set_pin_level(PA17,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA17, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA17, PINMUX_PA17C_SERCOM1_PAD1);

	// Set pin direction to input
	gpio_set_pin_direction(PA18, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PA18,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PA18, PINMUX_PA18C_SERCOM1_PAD2);
}

void SPI_0_CLOCK_init(void)
{
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM1_GCLK_ID_CORE, CONF_GCLK_SERCOM1_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM1_GCLK_ID_SLOW, CONF_GCLK_SERCOM1_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_mclk_set_APBCMASK_SERCOM1_bit(MCLK);
}

void SPI_0_init(void)
{
	SPI_0_CLOCK_init();
	spi_m_dma_init(&SPI_0, SERCOM1);
	SPI_0_PORT_init();
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA19

	gpio_set_pin_level(SPI_SS,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(SPI_SS, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(SPI_SS, GPIO_PIN_FUNCTION_OFF);

	DIGITAL_GLUE_LOGIC_0_init();

	SPI_0_init();
}
