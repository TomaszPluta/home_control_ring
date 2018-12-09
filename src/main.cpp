
#include "stm32f3xx.h"



#include "dac.h"


int main(void)
{
  SystemCoreClockUpdate();


  #include "../sound.c"
  uint32_t soundSize = sizeof(sound_wav);

  dac dacObj((uint8_t*)sound_wav, soundSize);



  while (1)
  {

  }

  return 0;
}
