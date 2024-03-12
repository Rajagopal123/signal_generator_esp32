#define DAC_PIN 25 // Define the DAC pin on the ESP32 (may vary depending on your board)

void setup() {
  // Set the DAC pin as an output
  pinMode(DAC_PIN, OUTPUT);
}

void loop() {
  // Generate a triangular wave
  for(int i = 0; i < 360; i++) {
    int triangularValue;
    if (i < 180) {
      triangularValue = i * 4095 / 180; // Ramp up from 0 to 4095
    } else {
      triangularValue = 4095 - (i - 180) * 4095 / 180; // Ramp down from 4095 to 0
    }
    dacWrite(DAC_PIN, triangularValue); // Write the calculated value to the DAC pin
    delayMicroseconds(10); // Adjust delay as needed for desired frequency
  }
}
