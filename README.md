# Arduino-send-Morse-code-message
This sketch sends a constant, null terminated string message.
There are multiple Arduino Morse code sketches available, but I found them to be overly cumbersome and have lots of code. So I rolled my own. 
Encoding to Morse code is accomplished with a table. For each entry, the 3 most significant bits hold the length, the other 5 bits indicate dashes (bit set) or dots to be sent. The least significant bit holds the bit to be sent first. An entry of 0x00 is used for invalid codes. As an example the entry for the character 'A' is 0x42 or B01000010: The length is B010 = 2 and the code to be sent B10 which equals (from right to left) .- 

This sketch was tested on an Arduino Uno and a Digispark.
