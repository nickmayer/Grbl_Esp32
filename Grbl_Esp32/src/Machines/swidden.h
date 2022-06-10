#pragma once
// clang-format off

#define MACHINE_NAME            "swidden"

#define DEFAULT_STEP_PULSE_MICROSECONDS     8
#define DEFAULT_STEPPER_IDLE_LOCK_TIME      255 //  255 = Keep steppers on

#define DEFAULT_DIRECTION_INVERT_MASK    (bit(X_AXIS) | bit(Y_AXIS) | bit(Z_AXIS))


// X:
#define DEFAULT_X_MAX_TRAVEL    655.0 // mm $130 (0 to 690 right)
//  200 * 32 steps per rev
#define X_STEPS_PER_REV         (6400)
//  40 tooth motor 60 tooth screw, 5mm screw pitch
#define X_MM_PER_REVOLUTION     (5*40/60.0f)
//  213.33333 steps per mm
#define DEFAULT_X_STEPS_PER_MM  (X_STEPS_PER_REV / X_MM_PER_REVOLUTION)

// Y:
#define DEFAULT_Y_MAX_TRAVEL    625.0 // mm $131 (0 front to 625 back)
//  200 * 32 steps per rev
#define Y_STEPS_PER_REV         (6400)
//  40 tooth motor 60 tooth screw, 5mm screw pitch
#define Y_MM_PER_REVOLUTION     (5*40/60.0f)
//  213.33333 steps per mm
#define DEFAULT_Y_STEPS_PER_MM  (Y_STEPS_PER_REV / Y_MM_PER_REVOLUTION)

// Z:
#define DEFAULT_Z_MAX_TRAVEL    225.0 // mm $132 (0 top to -225 bottom).
//  200 * 8 steps per rev
#define Z_STEPS_PER_REV         (1600)
//  8mm screw lead
#define Z_MM_PER_REVOLUTION     (8)
//  200 steps per mm
#define DEFAULT_Z_STEPS_PER_MM  (Z_STEPS_PER_REV / Z_MM_PER_REVOLUTION)

#define DEFAULT_X_MAX_RATE      7000.0 // mm/min
#define DEFAULT_Y_MAX_RATE      7000.0 // mm/min
#define DEFAULT_Z_MAX_RATE      4000.0 // mm/min

#define DEFAULT_X_ACCELERATION  300.0 // mm/sec^2
#define DEFAULT_Y_ACCELERATION  300.0 // mm/sec^2
#define DEFAULT_Z_ACCELERATION  150.0 // mm/sec^2

#define ENABLE_SOFTWARE_DEBOUNCE    1 // Limit switches seem to falsely trigger when router powers off
#define DEFAULT_INVERT_LIMIT_PINS   0 // Normal Closed buttons
#define DEFAULT_HARD_LIMIT_ENABLE   1
#define DEFAULT_SOFT_LIMIT_ENABLE   1


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

// TODO: Add a NOT gate and invert this so open is disabled?
#define STEPPERS_DISABLE_PIN    GPIO_NUM_15

// Left/Right
#define X_STEP_PIN              GPIO_NUM_16
#define X_DIRECTION_PIN         GPIO_NUM_5
#define X_LIMIT_PIN             GPIO_NUM_32

// Back/Forward
#define Y_STEP_PIN              GPIO_NUM_19
#define Y2_STEP_PIN             GPIO_NUM_17
#define Y_DIRECTION_PIN         GPIO_NUM_18
#define Y2_DIRECTION_PIN        Y_DIRECTION_PIN
#define Y_LIMIT_PIN             GPIO_NUM_33

// Up/Down
#define Z_STEP_PIN              GPIO_NUM_23
#define Z2_STEP_PIN             GPIO_NUM_21
#define Z_DIRECTION_PIN         GPIO_NUM_22
#define Z2_DIRECTION_PIN        Z_DIRECTION_PIN
#define Z_LIMIT_PIN             GPIO_NUM_25

#define DEFAULT_LASER_FULL_POWER    1000
#define DEFAULT_SPINDLE_RPM_MAX     1000.0  // rpm $30
#define DEFAULT_SPINDLE_RPM_MIN     0.0     // rpm $31
#define DEFAULT_LASER_MODE          1       // true $32
#define DEFAULT_SPINDLE_MIN_VALUE   0.0     // $35 Percent of full period (extended set)
#define DEFAULT_SPINDLE_MAX_VALUE   100.0   // $36 Percent of full period (extended set)

// TODO: Add a NOT gate and invert this so open is disabled
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
#define SPINDLE_OUTPUT_PIN      GPIO_NUM_13

#define LASER_OUTPUT_PIN        GPIO_NUM_27

#define DEFAULT_INVERT_PROBE_PIN 1
#define PROBE_PIN                GPIO_NUM_26

/*
#define CONTROL_RESET_PIN       GPIO_NUM_34  // labeled Reset, needs external pullup
#define CONTROL_FEED_HOLD_PIN   GPIO_NUM_36  // labeled Hold,  needs external pullup
#define CONTROL_CYCLE_START_PIN GPIO_NUM_39  // labeled Start, needs external pullup
*/

