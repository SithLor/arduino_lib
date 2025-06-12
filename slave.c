#include <Wire.h>

// Define constants
#define LED_PIN 13
#define SLAVE_ADDRESS 9

// Variables
int receivedValue = 0;
bool newDataReceived = false;

void setup()
{
    // Initialize serial communication
    Serial.begin(9600);
    Serial.println("I2C Slave Starting...");

    // Configure the LED pin as an output
    pinMode(LED_PIN, OUTPUT);

    // Initialize I2C as a slave device at address 9
    Wire.begin(SLAVE_ADDRESS);

    // Register event handler for receiving data
    Wire.onReceive(receiveEvent);

    Serial.println("Slave ready and listening on address 9");
}

// Function that executes whenever data is received from master
void receiveEvent(int byteCount)
{
    Serial.print("Received ");
    Serial.print(byteCount);
    Serial.print(" bytes: ");

    // Read all bytes from the Wire buffer
    while (Wire.available())
    {
        receivedValue = Wire.read();
        Serial.println(receivedValue);
        newDataReceived = true;
    }
}

void loop()
{
    // Process newly received data
    if (newDataReceived)
    {
        Serial.print("Processing value: ");
        Serial.println(receivedValue);

        // Blink LED based on received value
        if (receivedValue > 0)
        {
            // Flash LED quickly to indicate data reception
            digitalWrite(LED_PIN, HIGH);
            delay(50);
            digitalWrite(LED_PIN, LOW);

            // Now blink the LED based on the received value
            for (int i = 0; i < 3; i++)
            { // Blink 3 times
                digitalWrite(LED_PIN, HIGH);
                delay(receivedValue);
                digitalWrite(LED_PIN, LOW);
                delay(100);
            }
        }

        newDataReceived = false;
    }

    // Small delay to prevent serial output from being too fast
    delay(100);
}