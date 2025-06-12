#include <Wire.h>

void setup()
{
    Serial.begin(9600);
    Wire.begin();
}

void sendPWM(int value)
{
    Wire.beginTransmission(9); // transmit to device #9
    Wire.write(value);         // sends PWM value (0-255)
    Wire.endTransmission();    // stop transmitting
    Serial.print("Sent: ");
    Serial.println(value);
}

void loop()
{
    // Ramp up
    for (int pwm = 0; pwm <= 255; pwm += 5)
    {
        sendPWM(pwm);
        delay(30); // Adjust for ramp speed
    }
    // Ramp down
    for (int pwm = 255; pwm >= 0; pwm -= 5)
    {
        sendPWM(pwm);
        delay(30);
    }
}