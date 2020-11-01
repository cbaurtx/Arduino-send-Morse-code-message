
const char* MESSAGE = "My morse code message \0";

const int DASH_LNG = 300;
const int DOT_LNG = 100;
const int DASHDOT_GAP = 100;

const int CHARCHAR_GAP = 300;
const int WORDWORD_GAP = 700;

const int TONE_PITCH = 440;
const int TONE_OUT = 13;


/* first element refers to 0 (0x30), last one to Z (0x5a)
The most significant 3 bits are the aggregate number of dots and dashes. The lower 5 bits indicate
dash (1) ot dot (0). The dash or dot to be sent 1st is assigned to the lowest bit */ 
const byte MORSECODE[0x4f] = {B10111111, B10111110, B10111100, B10111000, B10110000, B10100000, // 0 to 5
                              B10100001, B10100011, B10100111, B10101111,  // 6 to 9
                              B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, // : to @
                              B01000010, B10000001, B01000101, B01100001, B00100000, B10000100, B01100011, // A to G
                              B10000000, B01000000, B10001110, B01100101, B10000010, B01000001, B01100111, // H to O
                              B10000110, B10001011, B01100010, B01100000, B00100001, B01100100, B10001000, // P to V 
                              B01100110, B10001001, B10001011, B10000011, // W to Z
                              B00000000, B00000000, B00000000, B00000000, B00000000, B00000000 // [ to `
                             };  

void xmit_char(byte code) {
  // send the morse code
  static byte cnt;
  static byte enc;

  if (code == 0x20) {  // space indicates new word
    delay(WORDWORD_GAP);
    return;
    }

  if (code < 0x30 || code > 0x7a) // invalid skip
    return;
 
  if (code >= 0x61)  // to upper
    code -= 0x20;
 
  code -= 0x30;  // ascii 0x30 is 1st in table
  enc = MORSECODE[code];
  
  for (cnt = enc >> 5; cnt > 0; cnt--) {
    tone(TONE_OUT, TONE_PITCH);
    if (enc & 0x01)
      delay(DASH_LNG);
    else
      delay(DOT_LNG);
    noTone(TONE_OUT);
    delay(DASHDOT_GAP);
    enc >>= 1;
    };

  delay(CHARCHAR_GAP - DASHDOT_GAP);
  }


void setup() {
  pinMode(TONE_OUT, OUTPUT);
  noTone(TONE_OUT);
  }

void loop() {
  static char * msg_pnt; 

  msg_pnt = MESSAGE;
  while(* msg_pnt)
    xmit_char(* msg_pnt++);
  }
  
