
#include "stm32f3xx.h"


#include "../sound.c"



int main(void)
{
	SystemCoreClockUpdate();
  uint32_t ii = 0;

  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  RCC->APB1ENR |= RCC_APB1ENR_DAC1EN;

  GPIOA->MODER |= GPIO_MODER_MODER4_1;
  GPIOA->AFR[0] |= (1<<16) | (1<<19);


  DAC->CR |= DAC_CR_EN1;
  DAC->CR |=DAC_CR_TSEL1;
  DAC->CR |= DAC_CR_TEN1;

  DAC->SWTRIGR |= DAC_SWTRIGR_SWTRIG1;
  DAC->DHR12L1 =0xFFFF;
  DAC->SWTRIGR |= DAC_SWTRIGR_SWTRIG1;
  DAC->DHR12L1 =0x1111;
  DAC->SWTRIGR |= DAC_SWTRIGR_SWTRIG1;


  while (1)
  {
       ii++;
  }

  return 0;
}
