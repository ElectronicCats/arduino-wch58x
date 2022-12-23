#include "config.h"
#include "HAL.h"
#include "heartrateservice.h"
#include "heartrate.h"

//#define DEBUG
/*********************************************************************
 * GLOBAL TYPEDEFS
 */
__attribute__((aligned(4))) uint32_t MEM_BUF[BLE_MEMHEAP_SIZE / 4];

#if(defined(BLE_MAC)) && (BLE_MAC == TRUE)
const uint8_t MacAddr[6] = {0x84, 0xC2, 0xE4, 0x03, 0x02, 0x02};
#endif

void blink(){
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
}

void beginBLE() {
  CH58X_BLEInit();
  HAL_Init();
}

static uint8_t heartRate_TaskID; // Task ID for internal task/event processing

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  PRINT("%s\n", VER_LIB);

  beginBLE();
  GAPRole_PeripheralInit();
  
  HeartRate_Init();
  
}

__HIGH_CODE
__attribute__((noinline))
void loop() {
  TMOS_SystemProcess();
}
