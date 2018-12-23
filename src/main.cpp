
#include "stm32f3xx.h"



#include "dac.h"
#include "spi.h"
//  #include "../sound.c"

#include "diskio.h"
#include "ff.h"
#include "wave.h"
int main(void)
{
  SystemCoreClockUpdate();



  SpiDriver Spi;


  disk_initialize(0);

  	FATFS fatDrive;
  	f_mount( 0, &fatDrive);
  	FIL fp;
  	FRESULT res = 	f_open(&fp, "sound", FA_OPEN_EXISTING | FA_READ);
  	const uint16_t bytesToRead = 1024;
  	uint8_t readBuff[bytesToRead];
  	UINT readBytes;
  	waveHeader_t waveHeader;
  	res = f_read(&fp,  (uint8_t*) &waveHeader, sizeof(waveHeader_t), &readBytes);



  	uint8_t sound_wav[35460];
  	res = f_read(&fp,  (uint8_t*) sound_wav, 35460, &readBytes);
  	f_close(&fp);

    dac dacObj((uint8_t*)sound_wav, 35460);
  while (1)
  {

  }

  return 0;
}
