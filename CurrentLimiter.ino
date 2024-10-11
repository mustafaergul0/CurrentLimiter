const int analogInPin = A0;  // Analog input pin for current sensor
const float sensitivity = 0.066;  // Sensitivity factor for ACS712-30 (66 mV/A)
const float currentLimit = 2.0;  // Current limit (2A)

void setup() {
  // Set ports for PWM
  DDRB |= (1 << DDB1) | (1 << DDB2);                     // Set PB1 (OC1A) and PB2 (OC1B) as output pins
  
  // Configure Timer1 for Fast PWM mode, higher frequency
  TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11); // Fast PWM, clear OC1A/OC1B on compare match, set at bottom
  TCCR1B = (1 << WGM12) | (1 << WGM13) | (1 << CS10);    // Fast PWM, no prescaling (CS10 = 1), max frequency

  ICR1 = 1600;  // Set TOP value to get higher frequency (this will set PWM period, smaller value = higher frequency)
  OCR1A = 1600; // Start with 100% duty cycle (full on)

  Serial.begin(9600);  // Start communication with the serial monitor
}

void loop() {
  int sensorValue = analogRead(analogInPin);  // Read the value from the current sensor
  // Convert the sensor value to voltage and then to current
  float current = ((sensorValue - 512) * (5.0 / 1023.0)) / sensitivity;

  // Print the measured current to the serial monitor
  Serial.print("Measured Current: ");
  Serial.print(current);
  Serial.println(" A");

  // If the current exceeds the limit of 2A, cut off the PWM output (turn off the MOSFET)
  if (current > currentLimit) {
    OCR1A = 0;  // Set PWM duty cycle to zero, turning off the MOSFET
    Serial.println("Current exceeded limit! Power cut.");
  } else {
    OCR1A = 1600;  // Set duty cycle to 100%, turning on the MOSFET
    Serial.println("Current is within limit.");
  }

  delay(500);  // Delay for the current measurement and control loop
}
