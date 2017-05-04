/*
 * This program is intended to control a wireless photo trigger
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

/*
 * This program runs a wireless photo trigger.
 * It is based on the following main components:
 * Arduino nano as the system brain,
 * DRV8825 stepper control board from pololu, or equivalent,
 * Micro stepper motor with leadscrew, from DVD player, or equivalent,
 * Wireless transmiter and receiver, with four buttons,
 * 9V cell/battery for autonomous power,
 * Main power switch, trigger button,
 * eventually more, following needs (screen, more buttons, rotary encoder, etc.)
 *
 * Following functionalities are implemented:
 * Simple tringering
 * Pose T triggering
 * Above with short or long temporisation
 */

#include "settings.h"
#include "drv8825.h"
#include "function.h"

DRV8825 stepper;

Function* fn[4] = {0, 0, 0, 0};


void setup(){

	stepper.init(STEP_PIN, DIR_PIN, ENABLE_PIN);

//	stepper.home();
	for(byte i = 0; i < 4; i++){
		fn[i] = new Function();
	}

	fn[0]->init(FN1_BUTTON, FN1_MODE, FN1_DELAY);
	fn[1]->init(FN2_BUTTON, FN2_MODE, FN2_DELAY);
	fn[2]->init(FN3_BUTTON, FN3_MODE, FN3_DELAY);
	fn[3]->init(FN4_BUTTON, FN4_MODE, FN4_DELAY);

	Serial.begin(115200);
}

void loop(){
	if(stepper.update() != DRV8825::STOPPED) return;

	Function::action_t action = Function::ACTION_IDLE;
	for(byte i = 0; i < 4; i++){
//		Serial.print("function ");
//		Serial.println(i);
		action = fn[i]->update();
		if(action != Function::ACTION_IDLE){
			break;
		}
	}

	if(action == Function::ACTION_START){
//		Serial.println("action start");
		stepper.moveDistance(TRAVEL, DRV8825::FORWARD);
	} else if(action == Function::ACTION_STOP){
//		Serial.println("action stop");
		stepper.moveDistance(TRAVEL, DRV8825::BACKWARD);
	}
}