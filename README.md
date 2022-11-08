# Arduino-line-tracker
An arduino robot embedded with ultra-sonic sensor to detect and follow the drawn lines.

An arduino mega board embedded with ulta-sonic sensor to measure distance, 5 channels line tracker to track the drawn line, 6v dc motor for movement, motor driver using H-bridge to control the direction and speed dc motors and LCD graphic screen to display information.

![b1](https://user-images.githubusercontent.com/102859856/200693687-10f63f4f-264f-4b6b-9ffb-977db5b61353.jpeg)

Each ultrasonic sensor is connected by 4 wires, 1 for the vcc and 1 for the ground, and the other 2 wires one for the trig and the other for the echo as digital connection with the Arduino.
The 5-channel line tracker is connected with 7 wires, 1 for the vcc and 1 for the ground, and the last 5 wires are the five sensors as digital connection with the Arduino, we neglect the last 2 port; CLP and Near, because we don’t need to sense the thickness, of line.

For the 6v dc motor we connect the +ve of each side together and the same for the –ve because we are using one motor driver and we don’t need to use each motor separately, if we need to have a turn, each side turn in an opposite side.
For the Arduino mega, we use it because we need a large number of pins, to connect the LCD with the other component

![b2](https://user-images.githubusercontent.com/102859856/200693696-35d09035-aa92-4dbd-9b50-b35caaf5e28a.jpeg)

![b3](https://user-images.githubusercontent.com/102859856/200694264-8eb9093a-c930-4af8-a8c6-99df072fb6dd.jpeg)
