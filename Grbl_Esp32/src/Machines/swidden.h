#pragma once
// clang-format off

#define MACHINE_NAME            "swidden"

#define DEFAULT_STEP_PULSE_MICROSECONDS     4
#define DEFAULT_STEPPER_IDLE_LOCK_TIME      255 //  255 = Keep steppers on

#define DEFAULT_DIRECTION_INVERT_MASK    (bit(X_AXIS) | bit(Y_AXIS) | bit(Z_AXIS))

// X:
//  200 * 32 steps per rev (6400 steps per rev)
//  60 tooth motor 40 tooth screw, 5mm screw pitch (5*40/60 mm per rev)
//  6400/3.3 steps per mm (213.33333)
// Y:
//  200 * 32 steps per rev (6400 steps per rev)
//  60 tooth motor 40 tooth screw, 5mm screw pitch (5*60/40 mm per rev)
//  6400/7.5 steps per mm (213.33333)
// Z:
//  200 * 8 steps pre rev (1600 steps per rev)
//  8mm screw lead (8mm per rev)
//  1600 / 8 steps per mm (200)
//#define DEFAULT_X_STEPS_PER_MM (6400.0f / (10 / 3.0f))
//#define DEFAULT_Y_STEPS_PER_MM (6400.0f / (10 / 3.0f))
//#define DEFAULT_Z_STEPS_PER_MM (200.0f)


// X:
#define DEFAULT_X_MAX_TRAVEL    655.0 // mm (0 to 690 right) [$130]
//  200 * 32 steps per rev
#define X_STEPS_PER_REV         (800)
//  40 tooth motor 60 tooth screw, 5mm screw pitch
#define X_MM_PER_REVOLUTION     (5*40/60.0f)
//  240 steps per mm
#define DEFAULT_X_STEPS_PER_MM  (X_STEPS_PER_REV / X_MM_PER_REVOLUTION)
#define X_MAX_RATE_MM_SEC       80     // mm/sec
#define DEFAULT_X_MAX_RATE      (X_MAX_RATE_MM_SEC * 60) // mm/min [$110]
#define DEFAULT_X_ACCELERATION  150.0 // mm/sec^2 [$120]

// Y:
#define DEFAULT_Y_MAX_TRAVEL    625.0 // mm (0 front to 625 back) [$131]
//  200 * 32 steps per rev
#define Y_STEPS_PER_REV         (800)
//  40 tooth motor 60 tooth screw, 5mm screw pitch
#define Y_MM_PER_REVOLUTION     (5*40/60.0f)
//  240 steps per mm
#define DEFAULT_Y_STEPS_PER_MM  (Y_STEPS_PER_REV / Y_MM_PER_REVOLUTION)
#define Y_MAX_RATE_MM_SEC       80     // mm/sec
#define DEFAULT_Y_MAX_RATE      (Y_MAX_RATE_MM_SEC * 60) // mm/min [$111]
#define DEFAULT_Y_ACCELERATION  150.0 // mm/sec^2 [$121]

// Z:
#define DEFAULT_Z_MAX_TRAVEL    225.0 // mm (0 top to -225 bottom). [$132]
//  200 * 8 steps per rev
#define Z_STEPS_PER_REV         (1600)
//  8mm screw lead
#define Z_MM_PER_REVOLUTION     (8)
//  200 steps per mm
#define DEFAULT_Z_STEPS_PER_MM  (Z_STEPS_PER_REV / Z_MM_PER_REVOLUTION)
#define Z_MAX_RATE_MM_SEC       50.0   // mm/sec
#define DEFAULT_Z_MAX_RATE      (Z_MAX_RATE_MM_SEC * 60) // mm/min [$112]
#define DEFAULT_Z_ACCELERATION  100.0  // mm/sec^2 [$122]

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

