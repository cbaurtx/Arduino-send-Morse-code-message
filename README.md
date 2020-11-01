# Arduino-send-Morse-code-message
There are multiple Arduino sketches available, but I found the to be overly cumbersome. We write too much code. So I rolled my own. 
Encoding to Morse code is accomplished with a table. The 3 most significant bits hold the length, the other 5 bits indicate dashes (bit set) or dots to be sent. The least significant bit holds the bit to be sent first. An entry of 0x00 is used for invalid codes. As an example the entry for the character 'A' is 0x42 or 0b01000010: The length is 0b010 = 2 and the code to be sent 0b10 which equals (from right ti left) .- 

The sketch was tested on an Arduino Uno 
