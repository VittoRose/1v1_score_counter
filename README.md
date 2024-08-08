# 1 vs 1 Score Counter

This is a personal project I created to stop counting the score while playing table tennis.

## Code explanation

The Arduino start with a 0-0 score which is icreased by the two player, both of them have 2 different buttons: one to increase the score and the other to decrease it or reset their own score. 
If the press of the second button is fast the score decrease but if you hold the button for more than 1.1 second the display blinks and the score is reset to zero.
The only library used is TM1637 by Seeed Studio.

## Components

For this project, the following components are required:
* Arduino UNO
* 2x 7-segment 4-digit displays
* 4 buttons, with pull down resistor if necessary
* Passive buzzer

I also used a shield to make all the connections esaier to handle, I will include drill and gerber file necessary to make the shield on your own. The buzzer is not mandatory but i used it to include an acoustic feedback.

## Connections

As you can find in the header of the main file i'm using:
* D2 for the input from the "increase score button" for the score 1
* D3 for the input from the "decrease score button" for the score 1
* D4 for the input from the "increase score button" for the score 2
* D5 for the input from the "decrease score button" for the score 2
* D7 for the display 1 clock
* D8 for the display 1 input/output data transmission
* D9 for the display 2 clock
* D10 for the display 2 input/output data transmission
* A2 for the buzzer

I also used pull-down resistor for a better buttons reading.
