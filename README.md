# Gas-cylinder-explosion-prevention-system

Gas Leakage Detection and Automatic Cylinder Shut-Off System
Components
Arduino Uno
MQ-2 Gas Sensor
Servo Motor
Relay Module
Exhaust Fan
Buzzer


Working;
When the MQ-2 sensor value exceeds 800:
Servo motor closes the gas cylinder valve.
Relay turns on the exhaust fan.
Buzzer sounds an alarm.


Connections:
MQ-2 AO -> A0
Relay IN -> D7
Buzzer -> D8
Servo Signal -> D9
