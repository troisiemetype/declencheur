/*
 * This class is intended to define behavior for photographic pose.
 * Copyright (C) 2017  Pierre-Loup Martin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "function.h"

int8_t Function::_instances = 0;
int8_t Function::_active = 0;

int8_t Function::addFunction(){
	return ++_instances;
}

Function::Function(){
	_instanceNumber = addFunction();
}

void Function::init(byte pin, byte mode, int delay = 0){
	_pin = pin;
	_mode = mode;
	_delay = delay;

	_status = STATUS_IDLE;
//	Function::_globalStatus = _status;

	_pinState = _prevPinState = LOW;

	pinMode(_pin, INPUT_PULLUP);

}

Function::action_t Function::update(){
	if(_mode == 0) return ACTION_IDLE;

	_prevPinState = _pinState;
	_pinState = digitalRead(_pin);

//	Serial.print("pin state: ");
//	Serial.println(_pinState);


//	Serial.println(_pinState);
	if(_status == STATUS_IDLE){
//		Serial.println("idle");
		if((_prevPinState != _pinState) && (_pinState == HIGH)){
			_prevTime = _time = millis();
			_status = STATUS_DELAY;
			_active = _instanceNumber;
			return ACTION_PENDING;
		}
		return ACTION_IDLE;
	} else if (_status == STATUS_DELAY){
//		Serial.println("delay");
		return updateDelay();
	} else if(_status == STATUS_POSE){
//		Serial.println("pose");
		_status = STATUS_IDLE;
		_active = 0;
		return ACTION_STOP;
	} else if(_status == STATUS_POSE_B){
//		Serial.println("pose B");
		if((_prevPinState != _pinState) && (_pinState == LOW)){
			_status = STATUS_IDLE;
			_active = 0;
			return ACTION_STOP;
		} else {
			return ACTION_PENDING;
		}
	} else if (_status == STATUS_POSE_T){
//		Serial.println("pose T");
		if((_prevPinState != _pinState) && (_pinState == HIGH)){
			_status = STATUS_IDLE;
			_active = 0;
			return ACTION_STOP;
		} else {
			return ACTION_PENDING;
		}
	} else {
//		Serial.println("default");
		return ACTION_IDLE;
	}
}

Function::action_t Function::updateDelay(){
//	Serial.println("update delay");

	_time = millis();
	if((_time - _prevTime) >= _delay){
//		Serial.print("Active button: ");
//		Serial.println(_instanceNumber);
		if(_mode == 1){
			_status = STATUS_POSE;
		} else if(_mode == 2){
			_status = STATUS_POSE_B;
		} else if(_mode == 3){
			_status = STATUS_POSE_T;
		}

		return ACTION_START;
	}
	return ACTION_PENDING;
}

int8_t Function::getActive(){
	return _active;
}
