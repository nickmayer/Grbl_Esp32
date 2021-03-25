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

#define DEFAULT_HOMING_SQUARED_AXES (bit(X_AXIS) | bit(Z_AXIS))
#define DEFAULT_STEP_PULSE_MICROSECONDS     3
#define DEFAULT_STEPPER_IDLE_LOCK_TIME      255 //  255 = Keep steppers on

// #define DEFAULT_HOMING_ENABLE           1  // false
// #define DEFAULT_HOMING_DIR_MASK         3 // move positive dir Z,negative X,Y
// #define DEFAULT_HOMING_FEED_RATE        100.0 // mm/min
// #define DEFAULT_HOMING_SEEK_RATE        200.0 // mm/min
// #define DEFAULT_HOMING_DEBOUNCE_DELAY   250 // msec (0-65k)
// #define DEFAULT_HOMING_PULLOFF          2.0 // mm

#define DEFAULT_X_STEPS_PER_MM 200.0
#define DEFAULT_Y_STEPS_PER_MM 200.0
#define DEFAULT_Z_STEPS_PER_MM 800.0

#define DEFAULT_X_MAX_RATE 8000.0 // mm/min
#define DEFAULT_Y_MAX_RATE 8000.0 // mm/min
#define DEFAULT_Z_MAX_RATE 3000.0 // mm/min

#define DEFAULT_X_ACCELERATION 200.0 // mm/sec^2
#define DEFAULT_Y_ACCELERATION 200.0 // mm/sec^2
#define DEFAULT_Z_ACCELERATION 100.0 // mm/sec^2

#define DEFAULT_X_MAX_TRAVEL 750.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL 750.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Z_MAX_TRAVEL 100.0 // mm NOTE: Must be a positive value.


#define DEFAULT_LASER_MODE 0 // false

#define STEPPERS_DISABLE_PIN    GPIO_NUM_4

#define X_DIRECTION_PIN         GPIO_NUM_12
#define X2_DIRECTION_PIN        X_DIRECTION_PIN
#define X_STEP_PIN              GPIO_NUM_13
#define X2_STEP_PIN             GPIO_NUM_14
#define X_LIMIT_PIN             GPIO_NUM_27

#define Y_STEP_PIN              GPIO_NUM_16
#define Y_DIRECTION_PIN         GPIO_NUM_17
#define Y_LIMIT_PIN             GPIO_NUM_21

#define Z_STEP_PIN              GPIO_NUM_32
#define Z2_STEP_PIN             GPIO_NUM_33
#define Z_DIRECTION_PIN         GPIO_NUM_25
#define Z2_DIRECTION_PIN        Z_DIRECTION_PIN
#define Z_LIMIT_PIN             GPIO_NUM_22

#define SPINDLE_TYPE            SpindleType::LASER
#define SPINDLE_OUTPUT_PIN      GPIO_NUM_18
#define SPINDLE_ENABLE_PIN      GPIO_NUM_19
#define LASER_OUTPUT_PIN        SPINDLE_OUTPUT_PIN
#define LASER_ENABLE_PIN        SPINDLE_ENABLE_PIN

//#define PROBE_PIN               GPIO_NUM_32

/*
#define CONTROL_RESET_PIN       GPIO_NUM_34  // labeled Reset, needs external pullup
#define CONTROL_FEED_HOLD_PIN   GPIO_NUM_36  // labeled Hold,  needs external pullup
#define CONTROL_CYCLE_START_PIN GPIO_NUM_39  // labeled Start, needs external pullup
*/

