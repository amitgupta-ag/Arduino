
void setup() {
  Serial.begin(9600);
  pmc_enable_periph_clk(ID_TRNG);
  trng_enable(TRNG);
 
  NVIC_DisableIRQ(TRNG_IRQn); //disables the specified device specific interrupt IRQn
  NVIC_ClearPendingIRQ(TRNG_IRQn); //removes the pending state of the specified device specific interrupt IRQn
  NVIC_SetPriority(TRNG_IRQn, 0); //Sets the priority for the interrupt specified by IRQn.IRQn can can specify any device specific interrupt, or processor exception. The priority specifies the interrupt priority value, whereby lower values indicate a higher priority. The default priority is 0 for every interrupt. This is the highest possible priority.
  NVIC_EnableIRQ(TRNG_IRQn); //enables the specified device specific interrupt IRQn
  trng_enable_interrupt(TRNG); //Enable TRNG interrupt
}
 
void TRNG_Handler(void) {
  uint32_t stat = trng_get_interrupt_status(TRNG);
  Serial.println(stat);

  if ((stat & TRNG_ISR_DATRDY) == TRNG_ISR_DATRDY) { //data ready interrupt
    int r = trng_read_output_data(TRNG);    
    Serial.println(r);
  }

}
 
void loop() {  
  
}
