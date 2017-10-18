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

class DRV8825{
public:
	enum direction_t{
		BACKWARD = 0,
		FORWARD,
	};

	enum status_t{
		STOPPED = 0,
		MOVING,
	};

	void init(byte stepPin, byte dirPin, byte enPin);
	void moveSteps(int step, bool dir);
	void moveDistance(int distance, bool dir);
	status_t update();

	void home();
	
	void enable(bool value = true);
	void disable();

	void setReverse(bool value);

	status_t getStatus();


private:
	uint8_t _pinStep;
	uint8_t _pinDir;
	uint8_t _pinEn;

	bool _dir;
	uint16_t _step;
	bool _reverse;

	bool _enable;
	status_t _status;
};

#endif