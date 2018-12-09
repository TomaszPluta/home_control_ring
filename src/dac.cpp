/*
 * dac.c
 *
 *  Created on: 09.12.2018
 *      Author: tomek
 */

#include "dac.h"

#include "stm32f3xx.h"


dac::dac(){

  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  RCC->AHBENR |= RCC_AHBENR_DMA2EN;
  RCC->APB1ENR |= RCC_APB1ENR_DAC1EN;
  RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;

  GPIOA->MODER |= GPIO_MODER_MODER4_1;
  GPIOA->AFR[0] |= (1<<16) | (1<<19);

}


dac::dac(uint8_t * waveSampleArray, uint32_t  waveSampleNb){
	  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	  RCC->AHBENR |= RCC_AHBENR_DMA2EN;
	  RCC->APB1ENR |= RCC_APB1ENR_DAC1EN;
	  RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;

	  GPIOA->MODER |= GPIO_MODER_MODER4_1;
	  GPIOA->AFR[0] |= (1<<16) | (1<<19);

	  DAC->CR = DAC_CR_DMAEN1 | DAC_CR_TEN1 |  DAC_CR_EN1;

	  TIM6->ARR = 30;       // sampling freq (with prescaler)
	  TIM6->PSC = 30;       //prescaler
	  TIM6->CR2 |= TIM_CR2_MMS_1; // TRGO generated while timer overrun
	  TIM6->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // TIM6 enable


	  DMA2_Channel3->CNDTR = waveSampleNb; // number of data to transfer
	  DMA2_Channel3->CPAR = (uint32_t)&(DAC->DHR8R1);
	  DMA2_Channel3->CMAR = (uint32_t)waveSampleArray; //memory address register
	  DMA2_Channel3->CCR = DMA_CCR_MINC | DMA_CCR_CIRC  | DMA_CCR_DIR | DMA_CCR_EN; // enable circular, memory increment,  dir from memory to dac
}


