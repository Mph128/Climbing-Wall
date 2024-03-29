int latchPin1 = 5;	// Latch pin of 74HC595 is connected to Digital pin 5
int clockPin1 = 6;	// Clock pin of 74HC595 is connected to Digital pin 6
int dataPin1 = 4;	// Data pin of 74HC595 is connected to Digital pin 4

int latchPin2 = 1;	// Latch pin of 74HC595 is connected to Digital pin 1
int clockPin2 = 2;	// Clock pin of 74HC595 is connected to Digital pin 2
int dataPin2 = 0;	// Data pin of 74HC595 is connected to Digital pin 0

byte ledrow = 0;		// Variable to hold the pattern of which LEDs are currently turned on or off
byte ledcolumn = 0;
int delay_time = 5;
/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup() 
{
  // Set all the pins of 74HC595 as OUTPUT
  pinMode(latchPin1, OUTPUT);
  pinMode(dataPin1, OUTPUT);  
  pinMode(clockPin1, OUTPUT);
  pinMode(latchPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);  
  pinMode(clockPin2, OUTPUT);
}

/*
 * loop() - this function runs over and over again
 */
void loop() 
{

/**
  Row 0 *************************************
*/
  bitSet(ledrow, 0);		// Set the bit that controls that LED in the variable 'leds'
  ledcolumn = 0b00001010;

  updateShiftRegister();

  ledcolumn = 0;
  ledrow = 0;

  delay(delay_time);

  updateShiftRegister();

/**
  Row 1 *************************************
*/

  bitSet(ledrow, 1);		// Set the bit that controls that LED in the variable 'leds'
  ledcolumn = 0b00001001;

  updateShiftRegister();

  delay(delay_time);

  ledcolumn = 0;
  ledrow = 0;

  updateShiftRegister();

/**
  Row 2 *************************************
*/

   bitSet(ledrow, 2);		// Set the bit that controls that LED in the variable 'leds'
  ledcolumn = 0b00000010;

  updateShiftRegister();

  delay(delay_time);

  ledcolumn = 0;
  ledrow = 0;

  updateShiftRegister();

  /**
  Row 3 *************************************
*/

    bitSet(ledrow, 3);		// Set the bit that controls that LED in the variable 'leds'
  ledcolumn = 0b00000100;

  updateShiftRegister();

  delay(delay_time);

  ledcolumn = 0;
  ledrow = 0;

  updateShiftRegister();
  
}
/*
 * updateShiftRegister() - This function sets the latchPin to low, then calls the Arduino function 'shiftOut' to shift out contents of variable 'leds' in the shift register before putting the 'latchPin' high again.
 */
void updateShiftRegister()
{
   digitalWrite(latchPin1, LOW);
   shiftOut(dataPin1, clockPin1, LSBFIRST, ledcolumn);
   digitalWrite(latchPin1, HIGH);  

   digitalWrite(latchPin2, LOW);
   shiftOut(dataPin2, clockPin2, LSBFIRST, ledrow);
   digitalWrite(latchPin2, HIGH);
}