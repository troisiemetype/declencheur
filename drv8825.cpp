/*
 * This class is intended to drive a DRV8825 stepper stick.
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

 #include "drv8825.h"

void DRV8825::init(byte stepPin, byte dirPin, byte enPin){
	_pinStep = stepPin;
	_pinDir = dirPin;
	_pinEn = enPin;

	_reverse = false;
	pinMode(_pinStep, OUTPUT);
	pinMode(_pinDir, OUTPUT);
	pinMode(_pinEn, OUTPUT);

	pinMode(ENDSTOP_PIN, INPUT_PULLUP);

	pinMode(13, OUTPUT);
}

void DRV8825::moveSteps(int step, bool dir){
	_dir = dir;
	_step = step;

	digitalWrite(_pinDir, (_dir ^ _reverse));

	digitalWrite(13, _dir);
}

void DRV8825::moveDistance(int distance, bool dir){
	int steps = (distance / TRAVEL_REV) * STEPS;
	moveSteps(steps, dir);
}

DRV8825::status_t DRV8825::update(){
	if(_step == 0){
		_status = STOPPED;
		return _status;
	}

	digitalWrite(_pinStep, HIGH);
	delayMicroseconds(5);
	digitalWrite(_pinStep, LOW);

	_step--;

	_status = MOVING;
	return _status;
}

void DRV8825::home(){
	while (digitalRead(ENDSTOP_PIN) == HIGH){
		moveSteps(5, BACKWARD);
	}
	moveSteps(5, FORWARD);
}

void DRV8825::enable(){
	enable(true);
}

void DRV8825::enable(bool value){
	_enable = value;

}

void DRV8825::disable(){
	enable(false);
}

void DRV8825::setReverse(bool value){
	_reverse = value;
}

DRV8825::status_t DRV8825::getStatus(){
	return _status;
}
