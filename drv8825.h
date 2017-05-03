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

#ifndef DRV8825_H
#define DRV8825_H

#include <Arduino.h>

#include "settings.h"

ISR(TIMER1_COMPA_vect){

}

class DRV8825{
public:
	DRV8825();

	void init(byte stepPin, byte dirPin, byte enPin);
	void moveSteps(int step, byte dir);
	void moveDistance(int distance, byte dir);
	void update();

	void home();

	void enable();
	void enable(bool value);
	void disable();

	void setReverse(bool value);

	byte getStatus();

private:
	byte _pinStep;
	byte _pinDir;
	byte _pinEn;

	bool _dir;
	int _step;
	bool _reverse;

	byte _enable;
	byte _status;

	enum direction{
		Backward = 0,
		Forward,
	};

	enum status{
		Stopped = 0,
		Moving,
	};
}

#endif