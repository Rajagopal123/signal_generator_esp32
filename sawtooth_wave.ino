#define DAC_PIN 25 // Define the DAC pin on the ESP32 (may vary depending on your board)

void setup() {
  // Set the DAC pin as an output
  pinMode(DAC_PIN, OUTPUT);
}

void loop() {
  // Generate a sawtooth wave
  for(int i = 0; i < 360; i++) {
    int sawtoothValue = i * 4095 / 360; // Linear ramp from 0 to 4095 within each period
    dacWrite(DAC_PIN, sawtoothValue); // Write the calculated value to the DAC pin
    delayMicroseconds(10); // Adjust delay as needed for desired frequency
  }
}
