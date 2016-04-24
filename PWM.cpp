/*
  PWM.cpp - PWM library v1.0.0 - 10-04-2016
  Copyright (c) 2006-2008 Dani Gonzalez.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.
*/

//******************************************************************************
//* Includes
//******************************************************************************

#include "Arduino.h"
#include "PWM.h"

//******************************************************************************
//* Constructors
//******************************************************************************

PWM::PWM(int pin){
   pinMode(pin, OUTPUT);
   _pin = pin;
}

//******************************************************************************
//* Public Methods
//******************************************************************************

/* handler method that use a timer and a counter to make the cycle */
int PWM::handler(){
	_tempActual = micros();
  if (_tempActual - _tempVell >= _retard) {
    _tempVell = _tempActual;
    _counter++;
    if (_counter == 101) {
      _counter = 0;
    }
    if (_dutyCicle > _counter || _dutyCicle == 100) {
      digitalWrite(_pin, HIGH);
    } else {
      digitalWrite(_pin, LOW);
    }
  }
  return digitalRead(_pin);
}

/* setDuty method to set the time period in which the output is on */
void PWM::setDuty(int dutyCicle){
	_dutyCicle=dutyCicle;
}
/* setRetard method to set the period of the time cycle */
void PWM::setRetard(unsigned long retard){
	_retard=retard;
}

/* getCounter method to get the actual value of the progressive 1-100 counter */
int PWM::getCounter(){
   return _counter;
}



