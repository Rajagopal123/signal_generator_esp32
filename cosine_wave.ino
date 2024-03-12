#define DAC_PIN 25 // Define the DAC pin on the ESP32 (may vary depending on your board)

void setup() {
  // Set the DAC pin as an output
  pinMode(DAC_PIN, OUTPUT);
}

void loop() {
  // Generate a cosine wave
  for(float i = 0; i < 360; i += 0.1) {
    float cosValue = (cos(i * PI / 180.0) + 1) * 2047.5; // Scale cosine wave to 0-4095 range (12-bit DAC)
    dacWrite(DAC_PIN, int(cosValue)); // Write the scaled value to the DAC pin
    delayMicroseconds(10); // Adjust delay as needed for desired frequency
  }
}
