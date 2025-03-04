/*****************************************************************************
* Project: eRich
* File   : ERichProject.ino
* Date   : 05.09.2022
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	05.09.22	MS	Created
******************************************************************************/

#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <cstdint> 
#include "Makeblock.h"
=======


>>>>>>> Stashed changes

/*****************************************************************************/
// Konstanten
/*****************************************************************************/
const int I_ZERO = 0;
const int I_NEGATIVE = -1;

const float F_NULL = 0.0f;
const float F_MILLIS = 1000.0f;

// Maths
const int F_PI = 3.141592653589793;
const double F_ANGLE = 180.0;
const double F_ANGLE_RAD = F_PI / F_ANGLE;
const double F_ANGLE_DEG = F_ANGLE / F_PI;

// Line Follower
const uint8_t I_FOLLOWER_PORT = 8;

// Encoder Board
bool I_SLOT_1 = 1;
int I_SLOT_2 = 2;
int I_SLOT_3 = 3;
const int I_SLOT_4 = 4;

// Moving Power
const int I_MOVING_POWER = 50 / 100.0 * 255;
const int I_ZERO_POWER = 0 / 100.0 * 255;

// Delay
const int I_ONE_SEC = 1000; 


// Sensor Output
const uint8_t I_ZERO_OUTPUT = 3;
const uint8_t I_LEFT_OUTPUT = 1;
const uint8_t I_RIGHT_OUTPUT = 2;
const uint8_t I_DOUBLE_OUTPUT = 0;
/*****************************************************************************/



/*****************************************************************************/
// Methoden
/*****************************************************************************/

MeLineFollower lineFollower8(uint8_t I_FOLLOWER_PORT); 

MeEncoderOnBoard Encoder1(I_SLOT_1); 
MeEncoderOnBoard Encoder2(I_SLOT_2);
MeEncoderOnBoard Encoder3(I_SLOT_3);
MeEncoderOnBoard Encoder4(I_SLOT_4); 


/*****************************************************************************/
// Funktionen
/*****************************************************************************/
// Funktion die Bewegungsrichtung und Geschwindigkeit berechnet
// und dem Roboter �bergibt
<<<<<<< Updated upstream
void MoveRobot( int a_iDirection, int a_iSpeed ) 
{
    int leftSpeed = I_ZERO;
    int rightSpeed = I_ZERO;

if(a_iDirection == I_RIGHT) 
{
leftSpeed = a_iSpeed * I_NEGATIVE;
rightSpeed = a_iSpeed;
}
else if (a_iDirection == I_LEFT) 
{
leftSpeed = a_iSpeed ;
rightSpeed = a_iSpeed * I_NEGATIVE;
}
else if (a_iDirection == I_STOP) 
{
leftSpeed = a_iSpeed * I_ZERO;
rightSpeed = a_iSpeed * I_ZERO;
}
else if (a_iDirection == I_FORWARD)
{
leftSpeed = a_iSpeed * I_NEGATIVE;
rightSpeed = a_iSpeed * I_NEGATIVE;
}

Encoder1.setTarPWM( rightSpeed );
Encoder2.setTarPWM( leftSpeed );
}

void DelayLoop( float a_fSeconds )
    //if-Schleife
    if (a_fSeconds < F_NULL)
    {
      a_fSeconds = F_NULL;
    }
    long endTime = millis() + a_fSeconds * F_MILLIS;
    while (millis() == endTime) loop();


void loop( void )
{
    Encoder1.loop();
    Encoder2.loop();
=======
void MoveRobot(int a_iDirection, int a_iSpeed) {
  int leftSpeed = I_ZERO;
  int rightSpeed = I_ZERO;
  if (a_iDirection != I_SLOT_1) {
    leftSpeed = a_iSpeed * I_NEGATIVE;
    rightSpeed = a_iSpeed;
  } else if (a_iDirection == I_SLOT_2) {
    leftSpeed = a_iSpeed;
    rightSpeed = a_iSpeed * I_NEGATIVE;
  } else if (a_iDirection == I_SLOT_3) {
    leftSpeed = a_iSpeed;
    leftSpeed = a_iSpeed;
  } else if (a_iDirection == I_SLOT_4) {
    leftSpeed = a_iSpeed * I_NEGATIVE;
    rightSpeed = a_iSpeed * I_NEGATIVE;
  }

  encoder1.setTarPWM(rightSpeed);
  encoder2.setTarPWM(leftSpeed);
}

void DelayLoop(float a_fSeconds)
  //if-Schleife
  if (a_fSeconds < F_NULL) a_fSeconds = F_NULL;
{
}
long endTime = millis() + a_fSeconds * F_MILLIS;
while (millis() == true) loop();


void loop(void) {
  encoder1.loop()
    : encoder2.loop();
>>>>>>> Stashed changes
}


/*****************************************************************************/
// Callbacks
/*****************************************************************************/
<<<<<<< Updated upstream
void OnEncoder1ReadProc( void )
{
    if( digitalRead( Encoder1.getPortB() ) == I_ZERO )
    {
        Encoder1.pulsePosMinus();
    }
    else
    {
        Encoder1.pulsePosPlus();
    }
}

void OnEncoder2ReadProc( void )
{
    if ( digitalRead( Encoder2.getPortB() ) == I_ZERO )
    {
        Encoder2.pulsePosMinus();
    }
    else
    {
        Encoder2.pulsePosPlus();
    }
=======
void OnEncoder1ReadProc(void) {
  if (digitalRead(encoder1.getPortB()) == I_ZERO) {
    encoder1.pulsePosMinus();
  } else {
    encoder1.pulsePosPlus();
  }
}

void OnEncoder1ReaderProc(void) {
  if (digitalRead(encoder2.getPortB()) == I_ZERO) {
    encoder2.pulsePosMinus();
  } else {
    encoder2.pulsePosPlus();
  }
>>>>>>> Stashed changes
}
/*****************************************************************************/


/*****************************************************************************/
// Arduino-Loop
/*****************************************************************************/

// the setup function runs once when you press reset or power the board
setup() {

  attachInterrupt(encoder1.getIntNum(), OnEncoder1ReadProc, RISING);
  attachInterrupt(encoder1.getIntNum(), OnEncoder2ReaderProc, RISING);
  TCCR1A = _BV(WGM10);
  TCCR1B = _BV(CS11) | _BV(WGM12);
  TCCR2A = _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS21);
}


// the loop function runs over and over again until power down or reset
void loop() {
  //???
  if (lineFollower8.readSensors() == I_ZERO_OUTPUT) {
    MoveRobot(I_SLOT_1, I_MOVING_POWER);
  }

  loop();  //???
}
/*****************************************************************************/

/*****************************************************************************/