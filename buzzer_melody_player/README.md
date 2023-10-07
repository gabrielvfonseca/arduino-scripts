# Arduino Buzzer Melody Player

This Arduino sketch is designed to play a simple melody using a buzzer connected to digital pin 9. The code generates musical notes by producing specific frequencies with the buzzer. The melody consists of seven different notes played one after another, with a delay between each note and a longer pause before repeating the melody.

## Components Used

- Arduino board (e.g., Arduino Uno)
- Buzzer module (connected to digital pin 9)
- Jumper wires

## Circuit Connection

1. Connect the buzzer module's positive (anode) lead to digital pin 9 on the Arduino (BUZZER).
2. Connect the buzzer module's negative (cathode) lead to the ground (GND) on the Arduino.

## Code Explanation

- The `BUZZER` constant is defined as 9, which is the pin to which the buzzer module is connected.
- An array `notas[]` is defined to store the frequencies of musical notes.

In the `setup` function:
- pinMode is set for `BUZZER` as OUTPUT to control the buzzer.

In the `loop` function:
- A `for` loop is used to iterate through the `notas[]` array, playing each note one by one using the `tone` function.
- Each note is played for 1000 milliseconds (1 second).
- A delay of 1000 milliseconds (1 second) is added between each note.
- After all seven notes have been played, there is a longer delay of 1000 milliseconds (1 second) before the melody repeats.

## Usage

1. Upload the code to your Arduino board using the Arduino IDE.
2. Ensure the circuit connections are set up correctly, with the buzzer module connected to pin 9.
3. Listen to the melody produced by the buzzer, which consists of seven musical notes played in sequence.

You can modify the `notas[]` array to create different melodies by changing the frequencies of the musical notes.

## License

This code is provided without any specific license. You are free to use, modify, and distribute it for both personal and commercial use at your own discretion.
