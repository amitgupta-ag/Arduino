#include <stdint.h>
void setup() { 
  Serial.begin(9600);
  pmc_enable_periph_clk(ID_TRNG); //used to enable specified peripheral clock
  trng_enable(TRNG); //enable trng
}
 
void loop() {  
  uint32_t t = trng_read_output_data(TRNG);
  Serial.println(t);
  delay(1000);
}
