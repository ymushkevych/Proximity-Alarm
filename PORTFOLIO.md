Arduino UNO-based program for my mechatronics class that detects an intruder and sounds an alarm. 

# Mechatronics 2025-2026: Project 1: Proximity Alarm

Yarema Mushkevych

9/25/2025

# Project Outline

> “Using components sourced from your Sparkfun Arduino kit, create an alarm that triggers when a person approaches your device. Your device should be capable of the following...

> - Detect the presence of a person approaching your device
> - Respond to the presence of this person by blinking and LED , setting off a piezo buzzer, sweeping a servo motor, printing out a warning to an LCD screen, or any combination of light, sound, motion, and text.
> - Reset the alarm by pushing a button”

## Constraints

  For this project, I was limited to using a limited selection of Arduino Parts and using an Arduino Uno. I was given 7 class days as well as extended work time outside of class for a total of around 18 hours of work time. 

# Diagrams

  A collection of diagrams and details for making the project. 

## Fritzing Style

![Fritzing Diagram](https://github.com/ymushkevych/Proximity-Alarm/blob/main/fritzing_diagram.png)

## Schematic

![Schematic](https://github.com/ymushkevych/Proximity-Alarm/blob/main/wiring_diagram.png)

## Parts List

- 1 Arduino UNO r3
- 1 Pushbutton
- 1 Red LED
- 1 Yellow LED
- 2 330Ω resistors
- 1 165x2 LCD display
- 1 4-pin Arduino Ultrasonic Distance Sensor
- 1 250 kΩ potentiometer
- 1 piezo buzzer
- wires 

# Program

![Program](https://github.com/ymushkevych/Proximity-Alarm/blob/main/arduino_code.png)

# Video

[![](https://markdown-videos-api.jorgenkh.no/youtube/8OGUEMUewiM)](https://youtu.be/8OGUEMUewiM)

# Reflection


    How did you breakdown this project and begin your design?
    What worked/did not work as you got going?
    What challenges did you overcome?
    What would you do differently? 

## How did you breakdown this project and begin your design?

  I started by determining what parts I could use and how they would be wired. I knew from the start that I wanted to use an LCD display, so I did research on how to code and wire those up pretty early on.
  Throughout the project, I focused on the important stuff — the actual sensor, the buzzer — first, and added in the more niche features later on. After all, what good is a button if there's no alarm to turn off?
  If I was struggling with something, I would set it aside and work on another part of the project

## What worked/did not work as you got going?

  The code for the button was really hard to get right, but I pushed through in the end
  I wanted to do some extra stuff with the LCD display but couldn't figure some stuff out, so I ended up simplifying my plan. 

##  What challenges did you overcome?

  As I said, the button code was pretty hard to get working, so that was definetely a challenge
  It also took me some time to get used to c++ notation and coding in c++

## What would you do differently? 

  I'd definetly expand on the LCD display, maybe have it print out a bit more info
  I'd also see if I could simplify the wiring, because it's honestly quite a mess to navigate when you need to troubleshoot stuff. 

# Citations

- Coded in and tested using the Desktop IDE for Arduino Uno
- Diagrams and Schematics designed in TinkerCad
- Code for the distance sensor was taken from the arduino webpage
- The video was edited using Google Videos





