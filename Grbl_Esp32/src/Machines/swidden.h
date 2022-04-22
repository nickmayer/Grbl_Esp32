#pragma once
// clang-format off

/*
    3axis_v4.h
    Part of Grbl_ESP32

    Pin assignments for the ESP32 Development Controller, v4.1 and later.
    https://github.com/bdring/Grbl_ESP32_Development_Controller
    https://www.tindie.com/products/33366583/grbl_esp32-cnc-development-board-v35/

    2018    - Bart Dring
    2020    - Mitch Bradley

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

#define MACHINE_NAME            "swidden"

#define DEFAULT_STEP_PULSE_MICROSECONDS     3
#define DEFAULT_STEPPER_IDLE_LOCK_TIME      255 //  255 = Keep steppers on

#define DEFAULT_DIRECTION_INVERT_MASK    (bit(X_AXIS) | bit(Z_AXIS))

// X:
//  200 * 32 steps per rev (6400 steps per rev)
//  20 tooth gear, 2mm belt pitch (40 mm per rev)
//  6400/40 steps per mm (160)
// Y:
//  200 * 16 steps per rev (6400 steps per rev)
//  20 tooth gear, 2mm belt pitch (40 mm per rev)
//  3200/40 steps per mm (160)
// Z:
//  200 * 8 steps pre rev (1600 steps per rev)
//  8mm screw lead (8mm per rev)
//  1600 / 8 steps per mm (200)
#define DEFAULT_X_STEPS_PER_MM 160.0
#define DEFAULT_Y_STEPS_PER_MM 160.0
#define DEFAULT_Z_STEPS_PER_MM 200.0

#define DEFAULT_X_MAX_RATE 8000.0 // mm/min
#define DEFAULT_Y_MAX_RATE 8000.0 // mm/min
#define DEFAULT_Z_MAX_RATE 5000.0 // mm/min

#define DEFAULT_X_ACCELERATION 300.0 // mm/sec^2
#define DEFAULT_Y_ACCELERATION 300.0 // mm/sec^2
#define DEFAULT_Z_ACCELERATION 100.0 // mm/sec^2

#define ENABLE_SOFTWARE_DEBOUNCE 1 // Limit switches seem to falsely trigger when router powers off
#define DEFAULT_INVERT_LIMIT_PINS 0 // Normal Closed buttons
#define DEFAULT_HARD_LIMIT_ENABLE 1
#define DEFAULT_SOFT_LIMIT_ENABLE 1

#define DEFAULT_X_MAX_TRAVEL 660.0 // mm $130 (0 to 660 right)
#define DEFAULT_Y_MAX_TRAVEL 610.0 // mm $131 (0 front to 610 back)
#define DEFAULT_Z_MAX_TRAVEL 225.0 // mm $132 (0 top to -225 bottom).

#define DEFAULT_HOMING_ENABLE 1
#define DEFAULT_HOMING_SQUARED_AXES (bit(Y_AXIS) | bit(Z_AXIS)) // Y & Z have 2 motors and need to be squared
#define DEFAULT_HOMING_DIR_MASK (bit(X_AXIS) | bit(Y_AXIS))
#define DEFAULT_HOMING_FEED_RATE 100.0 // mm/min
#define DEFAULT_HOMING_SEEK_RATE 1200.0 // mm/min
#define DEFAULT_HOMING_DEBOUNCE_DELAY 500 // msec (0-65k)
#define DEFAULT_HOMING_PULLOFF 2 // mm
#define DEFAULT_HOMING_CYCLE_0 bit(Z_AXIS)
#define DEFAULT_HOMING_CYCLE_1 bit(Y_AXIS)
#define DEFAULT_HOMING_CYCLE_2 bit(X_AXIS)

// TODO: Add a NOT gate and invert this so open is disabled
#define STEPPERS_DISABLE_PIN    GPIO_NUM_4

// Left/Right
#define X_STEP_PIN              GPIO_NUM_16
#define X_DIRECTION_PIN         GPIO_NUM_17
#define X_LIMIT_PIN             GPIO_NUM_21

// Back/Forward
#define Y_DIRECTION_PIN         GPIO_NUM_14
#define Y2_DIRECTION_PIN        Y_DIRECTION_PIN
#define Y_STEP_PIN              GPIO_NUM_13
#define Y2_STEP_PIN             GPIO_NUM_12
#define Y_LIMIT_PIN             GPIO_NUM_27

// Up/Down
#define Z_STEP_PIN              GPIO_NUM_25
#define Z2_STEP_PIN             GPIO_NUM_33
#define Z_DIRECTION_PIN         GPIO_NUM_32
#define Z2_DIRECTION_PIN        Z_DIRECTION_PIN
#define Z_LIMIT_PIN             GPIO_NUM_22

#define DEFAULT_LASER_FULL_POWER    1000
#define DEFAULT_SPINDLE_RPM_MAX     1000.0  // rpm $30
#define DEFAULT_SPINDLE_RPM_MIN     0.0     // rpm $31
#define DEFAULT_LASER_MODE          1       // true $32
#define DEFAULT_SPINDLE_MIN_VALUE   0.0     // $35 Percent of full period (extended set)
#define DEFAULT_SPINDLE_MAX_VALUE   100.0   // $36 Percent of full period (extended set)

#define DEFAULT_INVERT_SPINDLE_ENABLE_PIN 0
#define DEFAULT_SPINDLE_ENABLE_OFF_WITH_ZERO_SPEED 1

/*
To switch between laser & spindle you need to change both the mode and spindle type

; LASER (default)
$32=1
$Spindle/Type=LASER

; SPINDLE
$32=0
$Spindle/Type=RELAY
*/

#define DEFAULT_SPINDLE_FREQ    10000.0  // Hz ($33 extended set)
#define SPINDLE_TYPE            SpindleType::LASER
#define SPINDLE_OUTPUT_PIN      GPIO_NUM_2
#define LASER_OUTPUT_PIN        GPIO_NUM_18

#define DEFAULT_INVERT_PROBE_PIN 1
#define PROBE_PIN                GPIO_NUM_19

/*
#define CONTROL_RESET_PIN       GPIO_NUM_34  // labeled Reset, needs external pullup
#define CONTROL_FEED_HOLD_PIN   GPIO_NUM_36  // labeled Hold,  needs external pullup
#define CONTROL_CYCLE_START_PIN GPIO_NUM_39  // labeled Start, needs external pullup
*/

