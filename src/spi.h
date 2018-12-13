/*
 * spi.h
 *
 *  Created on: 10.12.2018
 *      Author: tomek
 */

#ifndef SPI_H_
#define SPI_H_

#include "stdint.h"

class SpiDriver{

public:
	SpiDriver();
	uint8_t Transmit (uint8_t data);

};



#endif /* SPI_H_ */
