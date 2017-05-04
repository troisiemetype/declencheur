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
 * This file is part of Declencheur, it contains system settings.
 */

#ifndef SETTINGS_H
#define SETTINGS_H

//Pins definition
#define BUTTON_A 			5
#define BUTTON_B 			4
#define BUTTON_C 			3
#define BUTTON_D 			2

#define STEP_PIN			6
#define DIR_PIN 			7
#define ENABLE_PIN			8

#define ENDSTOP_PIN			9

//Function definition
#define FN1_BUTTON 			BUTTON_A 	//Wich button is linked to this function
#define FN1_MODE 			1			//0=disable, 1=pose, 2=pose B, 3=pose T
#define FN1_DELAY 			0			//Delay between button press and triggering

#define FN2_BUTTON 			BUTTON_B
#define FN2_MODE 			1
#define FN2_DELAY 			1000

#define FN3_BUTTON 			BUTTON_C
#define FN3_MODE 			2
#define FN3_DELAY 			0

#define FN4_BUTTON 			BUTTON_D
#define FN4_MODE 			3
#define FN4_DELAY 			0

//Default settings of stepper motor
#define SPEED 				20			//travelling speed in mm/s
#define STEPS 				20			//Number of steps/full rotation
#define TRAVEL_REV 			3			//Travel per revolution
#define TRAVEL 				25 			//Standard travel for triggering
#define TRAVEL_MAX 			40 			//Max travel for the stepper
#define REVERSE 			0 			//Motor turning direction

#endif