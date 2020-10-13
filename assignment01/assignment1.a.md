# Embedded System Example

- describe an embedded system. what challenges is the design likely trying to solve?

Thinking about a smart lightbulb. It is controlled via Bluetooth and can be set to any RGB color and brightness.

Challenges/conditions that this system has to solve:
1. Make Bluetooth connection with a mobile device (iOS/Android)
1. Handle incoming Bluetooth messages
1. Translate these messages into an RGB color
1. Drive onboard RGB LEDs
1. Heat sensitivity
1. Remember the previously set color, so that if the light is turned off at the switch, it will be the same color when it turns on.

