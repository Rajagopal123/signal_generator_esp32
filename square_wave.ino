#define DAC_PIN 25 // Define the DAC pin on the ESP32 (may vary depending on your board)

void setup() {
  // Set the DAC pin as an output
  pinMode(DAC_PIN, OUTPUT);
}

void loop() {
  // Generate a square wave
  for(int i = 0; i < 360; i++) {
    if (i < 180) {
      dacWrite(DAC_PIN, 4095); // Write maximum value (high)
    } else {
      dacWrite(DAC_PIN, 0); // Write minimum value (low)
    }
    delayMicroseconds(10); // Adjust delay as needed for desired frequency
  }
}
