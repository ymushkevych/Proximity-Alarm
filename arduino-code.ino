int alarmPrimed = 1; // prime the alarm
int alarmTriggered = 0; // set the alarm to "not triggered"
int previousValue = 1; // set the previous state of the alarm to primed
// start of copied code (taken from sparkfun)
#include <LiquidCrystal.h> //import the lcd library into the codespace
// gap for readability
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // define the lcd based on the pins
// gap for readability
long readUltrasonicDistance(int triggerPin, int echoPin) { // define the ultrasonic distance based on the time it takes for a signal to return
  pinMode(triggerPin, OUTPUT); // define the trigger pin as an output
  digitalWrite(triggerPin, LOW); // set the trigger pin to off
  delayMicroseconds(5); // wait 5 microseconds; prevents confusing signals from 2 seperate burts
  digitalWrite(triggerPin, HIGH); //turn on the trigger pin
  delayMicroseconds(12); // wait 12 microseconds
  digitalWrite(triggerPin, LOW); // turn off the trigger pin. End of burst
  pinMode(echoPin, INPUT); //define the echo pin as an input
  return pulseIn(echoPin, HIGH)/148; // read the echo pin and divide by 148 to get the rough distance in inches
} // curly brace for functionality
// end of copied code (taken from sparkfun)
// gap for readability
void setup() { // defines the setup of the program
// gap for readability
  pinMode(5, OUTPUT); // define pin 5 (red LED) as an output
  pinMode(4, OUTPUT); // define pin 4 (yellow LED) as an output
  pinMode(3, OUTPUT); // define pin 3 (piezo buzzer) as an output
  pinMode(2, INPUT); // define pin 2 (button) as an input
// gap for readability
  lcd.begin(16, 2); //define the lcd as being 16 characters wide and 2 characters tall
  lcd.clear(); //clear the display
} // curly brace for functionality
// gap for readability
void loop() { // this loop will run indefinitely, it contains the primary program code   
  lcd.clear(); //clear the display
  lcd.setCursor(0, 0); // set cursor at top row, first column
  if (alarmPrimed == 1) { // if the alarm is primed
    lcd.print("ARMED"); // print "ARMED"
  } else if (alarmPrimed == 0) { // otherwise if the alarm is not primed
    lcd.print("DISARMED"); // print "DISARMED"
  } // curly brace for functionality
  lcd.setCursor(0, 1); // move cursor down one row
  lcd.print(readUltrasonicDistance(7, 6));
  delay(400); // wait 0. 4 seconds. This allows the display to be stable and readable
// gap for readability
  if (alarmPrimed == 1) { // if the alarm is primed
    if (readUltrasonicDistance(7, 6) <= 3) { // if the distance is less than or equal to 3 inches,
      digitalWrite(4, LOW); // turn off the warning (yellow) LED
      digitalWrite(5, HIGH); //turn on the alarm (red) LED
      tone(3, 255); //play tone 255 on the piezo
      if (alarmPrimed == 1) { // if the alarm is ARMED
        alarmTriggered = 1; // set the alarm status to "triggered"
        tone(3, 255); // play the alarm tone
      } // curly brace for functionality
    } else if (readUltrasonicDistance(7, 6) > 3) { // if the distance is more than 3 inches
      if (alarmTriggered == 1) { // if the alarm is already triggered
        tone(3, 255); // continue playing the alarm tone
      } else { // otherwise
        noTone(3); // play no tone. Silence the alarm
        if (readUltrasonicDistance(7, 6) < 15) { // if the distance is less than 15 inches,
        digitalWrite(4, HIGH); //turn on the warning (yellow) LED
        digitalWrite(5, LOW); // turn off the alarm (red) LED
        tone(3, 60); //play the warning tone
        delay(100); // wait for 0.1 seconds
        } else { // otherwise
          digitalWrite(5, LOW); //turn of the alarm (red) LED
          digitalWrite(4, LOW); //turn off the warning (yellow) LED
        } // curly brace for functionality
      } // curly brace for functionality
    } // curly brace for functionality
  } // curly brace for functionality
  if (digitalRead(2) == HIGH) { // if the button is pressed 
    while (digitalRead(2) == HIGH) { // while the button continues to be pressed
        alarmTriggered = 0; // de-trigger the alarm
        noTone(3); // silence the buzzer
        digitalWrite(4, LOW); // turn off the yellow LED
        digitalWrite(5, LOW); // turn off the red LED
        if (alarmPrimed == 0 && previousValue == 0) { // if the alarm is not primed and the previous state is also not primed
          alarmPrimed = 1; // re-prime the alarm
        } else if (alarmPrimed == 1 && previousValue == 1) { // if the alarm is primed and the previous state is also primed
          alarmPrimed = 0; // de-prime the alarm
        } // curly brace for functionality
      } // curly brace for functionality
      previousValue = alarmPrimed; // set the previous state to the current state
    } // curly brace for functionality
} // curly brace for functionality
