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

#ifndef FUNCTION_H
#define FUNCTION_H

#include <Arduino.h>

#include "settings.h"

class Function{
public:

	Function();

	enum status_t{
		STATUS_IDLE = 0,
		STATUS_DELAY,
		STATUS_POSE,
		STATUS_POSE_B,
		STATUS_POSE_T,
	};

	enum action_t{
		ACTION_IDLE = 0,
		ACTION_PENDING,
		ACTION_START,
		ACTION_STOP,
	};

	void init(byte pin, byte mode, int delay);

	action_t update();

	static int8_t getActive();

protected:

	action_t updateDelay();

private:
	static int8_t addFunction();

	int8_t _instanceNumber;

	int8_t _pin;
	int8_t _mode;
	int _delay;

	status_t _status;

	bool _pinState, _prevPinState;

	int32_t _time, _prevTime;

	static int8_t _instances;
	static int8_t _active;
};

#endif