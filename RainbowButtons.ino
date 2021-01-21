/*
  Rainbow Button Keyboard
  Nigel James Brown - September 17th 2020

  Each pin of the Pro-Micro should be connected to one side of a button
  The other side of all the buttons should be connected to the ground pin

  Each of the pins - listed in buttonPinMap are set as inputs with the built in pull-up resistors
  When one of the pins changes state a key value for press or release will be sent from the buttonKeyMap array

  To expand this - change the NUM_BUTTONS value and increase the size of the three arrays
  buttonKeyMap, buttonPinMap and keyState.

  Note: keyState values should all be initialised to true to match the pull-up value
  
*/

#include "Keyboard.h"

#define NUM_BUTTONS 6

uint8_t buttonKeyMap[NUM_BUTTONS] = {KEY_F19, KEY_F20, KEY_F21, KEY_F22, KEY_F23, KEY_F24};
uint8_t buttonPinMap[NUM_BUTTONS] = {2,3,4,5,6,7};
bool keyState[NUM_BUTTONS] = {true, true, true, true, true, true};

void setup() {
  //start serial connection
  // Serial.begin(9600);

  for (int i=0; i<NUM_BUTTONS; i++)
  {
    pinMode(buttonPinMap[i], INPUT_PULLUP);
  }

  Keyboard.begin();

}


void loop() {
  //read the pushbutton value into a variable
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    int sensorVal = digitalRead(buttonPinMap[i]);
    if (sensorVal != keyState[i])
    {
      // The value has changed
      if (sensorVal == 0)
      {
        // Key has been pressed
        Keyboard.press(buttonKeyMap[i]);

        // delay here
        delay(100);

      }
      else
      {
        // Key has been released
        Keyboard.release(buttonKeyMap[i]);

        // delay here
        delay(100);

      }
      keyState[i] = sensorVal;
    }
    //print out the value of the pushbutton
    // Serial.println(sensorVal);

  }
}
