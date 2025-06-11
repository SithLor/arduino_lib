// basic libarduino uno r3 code




void setup() {
    // Initialize serial communication at 9600 baud rate
    Serial.begin(9600);
    
    // Set all digital pins as input
    for (int i = 0; i < 20; i++) {
        pinMode(PCINT[i], INPUT);
    }
}

