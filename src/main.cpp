
#include "stm32f3xx.h"



#include "dac.h"
#include "spi.h"
  #include "../sound.c"

int main(void)
{
  SystemCoreClockUpdate();


  uint32_t soundSize = sizeof(sound_wav);

  dac dacObj((uint8_t*)sound_wav, soundSize);

  SpiDriver Spi;
  uint8_t rec1 =  Spi.Transmit((uint8_t)'x');
  uint8_t rec2 =  Spi.Transmit((uint8_t)'y');
  uint8_t rec3 =  Spi.Transmit((uint8_t)'z');
  uint8_t rec4 =  Spi.Transmit((uint8_t)'a');


  while (1)
  {

  }

  return 0;
}
