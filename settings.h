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

//Buttons definition
#define POSE 				0
#define POSE_T 				1
#define POSE_1 				2
#define POSE_2				3

//Functions linked to buttons
#define BUTTON1 			POSE
#define BUTTON2 			POSE_T
#define BUTTON3 			POSE_1
#define BUTTON4 			POSE_2

//Tempo lengths, in milliseconds (1 s == 1000 ms)
#define TEMPO_1 			2000
#define TEMPO_2 			10000

//Default settings of stepper motor
#define SPEED 				20			//travelling speed in mm/s
#define STEPS 				20			//Number of steps/full rotation
#define TRAVEL 				25 			//Standard travel for triggering
#define TRAVEL_MAX 			40 			//Max travel for the stepper
#define REVERSE 			0 			//Motor turning direction

#endif