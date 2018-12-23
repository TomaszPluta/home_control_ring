
#include "stm32f3xx.h"



#include "dac.h"
#include "spi.h"
  #include "../sound.c"

#include "diskio.h"
#include "ff.h"
#include "wave.h"
int main(void)
{
  SystemCoreClockUpdate();


  uint32_t soundSize = sizeof(sound_wav);

  dac dacObj((uint8_t*)sound_wav, soundSize);

  SpiDriver Spi;
//  uint8_t rec1 =  Spi.Transmit((uint8_t)'x');
//  uint8_t rec2 =  Spi.Transmit((uint8_t)'y');
//  uint8_t rec3 =  Spi.Transmit((uint8_t)'z');
//  uint8_t rec4 =  Spi.Transmit((uint8_t)'a');

  disk_initialize(0);

  //	uint8_t inputBuff[128];
  //	memset(inputBuff, 'x', 128);
  //	disk_write(0,inputBuff,0, 1);
  //	disk_read(0,buffSD,0, 1);

  	FATFS fatDrive;
  	f_mount( 0, &fatDrive);
  	FIL fp;
  	FRESULT res = 	f_open(&fp, "sound", FA_OPEN_EXISTING | FA_READ);
  	const uint16_t bytesToRead = 1024;
  	uint8_t readBuff[bytesToRead];
  	UINT readBytes;
  	waveHeader_t waveHeader;
  	res = f_read(&fp,  (uint8_t*) &waveHeader, sizeof(waveHeader_t), &readBytes);

  	f_close(&fp);

  while (1)
  {

  }

  return 0;
}
