#include <VirtualWire.h>
const int transmit_pin = 8;
void setup()
{
  // Initialise the IO and ISR
  vw_set_tx_pin(transmit_pin);
  vw_set_ptt_inverted(true); // Required
  vw_setup(2000);   // Bits per sec
  Serial.begin(9600);
}
byte count = 1;
void loop()
{
  char msg[2] = {'A', 'B'};
  vw_send((uint8_t *)msg, 2);
  vw_wait_tx(); // Wait until the whole message is gone
  Serial.println("Send");
  delay(1000);
  count = count + 1;
}
