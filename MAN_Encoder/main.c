#include <atmel_start.h>
#include "driver_examples.h"

/*
Note: SAMC21 only support selecting SPI MOSI as CCL input and MOSI should be SERCOM PAD[0]. So SPI CLK must use hardware connection. DMAC needs to be enabled and set correctly when using SPI_MASTER_DMA.
Hardware connection: PA09(CCL In[1]) - PA17(SPI CLK)
MANCHSTER OUTPUT: PA11

PA16:MOSI, PA17:SCK, PA18:MISO, PA19:SS
REF:
Manchester Encoder Using USART and CCL on ATtiny817
*/
int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	DIGITAL_GLUE_LOGIC_0_example();
	SPI_0_example();
	/* Replace with your application code */
	while (1) {
	}
}
