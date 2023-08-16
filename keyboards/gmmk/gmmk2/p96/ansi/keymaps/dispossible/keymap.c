/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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

#include QMK_KEYBOARD_H
#include "math.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
enum custom_layers {
    _BL,
    _FL,
    _CL,
};

// Unicode characters
#define POUND UC(0xA3)
#define EURO  UC(0x20AC)


// Use this tool to figure out what the keycodes are called
// https://config.qmk.fm/#/gmmk/gmmk2/p96/ansi/LAYOUT

// If you add a new layer you must increase the number in the config.h file
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer) */
  [_BL] = LAYOUT(
    KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,             KC_F12,   KC_NUM,   KC_HOME,  KC_END,   KC_PSCR,  KC_MPLY,
    KC_GRV,             KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,            KC_EQL,   KC_BSPC,  KC_DEL,   KC_PSLS,  KC_PAST,  KC_PMNS,
    KC_TAB,             KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,            KC_RBRC,  KC_BSLS,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
    KC_CAPS,            KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_P4,    KC_P5,    KC_P6,
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,                      KC_UP,    KC_P1,    KC_P2,    KC_P3,    KC_PENT,
    LM(_CL, MOD_LCTL),  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FL),  LM(_CL, MOD_RCTL),  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT),

  /* Keymap _FL: Function Layer */
  [_FL] = LAYOUT(
    _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_VAD,   RGB_VAI,   _______,  _______,  _______,  _______,  _______,
    _______,  _______,  EURO,     POUND,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   QK_BOOT,  _______,  _______,  _______,  _______,
    _______,  RGB_HUI,  RGB_SAI,  RGB_VAI,   RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,  _______,  _______,
    _______,  RGB_HUD,  RGB_SAD,  RGB_VAD,   RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              RGB_HUI,  _______,  _______,  _______,  _______,
    _______,  UC_WIN,   _______,                       _______,                                _______,  _______,  _______,   RGB_RMOD,  RGB_HUD,  RGB_MOD,  _______,  _______),
  /* Keymap _CL: Control Layer */
  [_CL] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,  KC_MNXT,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,                      _______,                                _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______)
};

// All these numbers match up with the indexed positions in the keymap above.
const uint8_t NUM_LOCK_KEY_INDEX = 13;
const uint8_t CAPS_LOCK_KEY_INDEX = 54;
const uint8_t ALPHA_KEYS[] = { 
  37, 38, 39, 40, 41, 42, 43, 44, 45, 46,
   55, 56, 57, 58, 59, 60, 61, 62, 63,
    71, 72, 73, 74, 75, 76, 77
};
const uint8_t NUM_PAD_KEYS[] = {
  50, 51, 52,
  67, 68, 69,
  83, 84, 85,
      97, 98
};

int clamp(int x, int lower, int upper) {
  if(x > upper){
    return upper;
  }
  if(x < lower){
    return lower;
  }
  return x;
}

// vars for tracking the animation state
double caps_flood_position = 0;
double num_flood_position = 0;
uint32_t last_frame_time;

// This is basically the amount of mills to wait between frames
// Bigger number, slower the animation. 16 == 60fps
const int FLOOD_SPEED_DIVISOR = 16;

// This sets the order that the keys turn on, plus 2 variables to hold the array sizes
// -1 is used as null because C doesn't like variable sized 2D arrays
 // The first grouping is intentionally empty as that is where the lock key itself turns off/on
const int CAPS_FLOOD_STEPS = 12;
const int CAPS_FLOOD_HEIGHT = 3;
const uint8_t ALPHA_KEY_GROUPS[12][3] = {
  { -1, -1, -1 },
  { 55, -1, -1 },
  { 37, 56, 71 },
  { 38, 57, 72 },
  { 39, 58, 73 },
  { 40, 59, 74 },
  { 41, 60, 75 },
  { 42, 61, 76 },
  { 43, 62, 77 },
  { 44, 63, -1 },
  { 45, -1, -1 },
  { 46, -1, -1 }
};

const int NUM_FLOOD_STEPS = 9;
const int NUM_FLOOD_HEIGHT = 3;
const uint8_t NUM_PAD_KEY_GROUPS[9][3] = {
  { -1, -1, -1 },
  { -1, -1, -1 },
  { -1, -1, -1 },
  { 50, -1, -1 },
  { 51, 67, -1 },
  { 52, 68, 83 },
  { 69, 84, -1 },
  { 85, 97, -1 },
  { 98, -1, -1 },
};

/**
 * Get the current hues complimentary color
 */
RGB getComplimentColor(void){
  // Get the inverted hue as RGB values
  HSV hsv = {0, 255, 255};
  hsv.h = (rgb_matrix_get_hue() + 128) % 256;
  hsv.s = rgb_matrix_get_sat();
  hsv.v = rgb_matrix_get_val();
  RGB rgb = hsv_to_rgb(hsv);
  return rgb;
}

/**
 * A helper function that can be called while capslock is on or animating to progress
 * or maintain the state of the LEDs
 */
void update_cap_flood(void){
  int flood_index = clamp(floor(caps_flood_position), 0, CAPS_FLOOD_STEPS);

  RGB rgb = getComplimentColor();
  rgb_matrix_set_color(CAPS_LOCK_KEY_INDEX, rgb.r, rgb.g, rgb.b);

  for (int i = 0; i < flood_index; i++) {
    for (int ii = 0; ii < CAPS_FLOOD_HEIGHT; ii++) {
      uint8_t key = ALPHA_KEY_GROUPS[i][ii];
      if (g_led_config.flags[key] & LED_FLAG_KEYLIGHT) {
        if( key > -1 ){
          rgb_matrix_set_color(key, rgb.r, rgb.g, rgb.b);
        }
      }
    }
  }
}

/**
 * A helper function that can be called while numlock is on or animating to progress
 * or maintain the state of the LEDs
 */
void update_num_flood(void){
  int flood_index = clamp(floor(num_flood_position), 0, NUM_FLOOD_STEPS);

  RGB rgb = getComplimentColor();
  rgb_matrix_set_color(NUM_LOCK_KEY_INDEX, rgb.r, rgb.g, rgb.b);

  for (int i = 0; i < flood_index; i++) {
    for (int ii = 0; ii < NUM_FLOOD_HEIGHT; ii++) {
      uint8_t key = NUM_PAD_KEY_GROUPS[i][ii];
      if (g_led_config.flags[key] & LED_FLAG_KEYLIGHT) {
        if( key > -1 ){
          rgb_matrix_set_color(key, rgb.r, rgb.g, rgb.b);
        }
      }
    }
  }
}

/* Abstracted the increment logic so it can be reused between keys */
double updateFloodPosition(double flood_position, double flood_amount, bool lock_state, int max_flood){
  double next_position = flood_position;
  if (lock_state) {
    if(next_position < 0){
      next_position = 0;
    }
    if(next_position <= max_flood){
      next_position = next_position + flood_amount;
    }
  } else {
    if(next_position > max_flood){
      next_position = max_flood;
    }
    if( next_position >= 0 ){
      next_position = next_position - flood_amount;
    }
  }
  return next_position;
}


/**
 * This is invoked once every cycle by the firmware and is used to set the Caps/Num/Scroll lock indicators
 */
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

  // Use the time difference between invokes to set how far to advance the animation
  uint32_t delta = timer_elapsed32(last_frame_time);
  double flood_amount = (double) delta / (double) FLOOD_SPEED_DIVISOR;
  
  // Deal with CapsLock
  caps_flood_position = updateFloodPosition(
    caps_flood_position,
    flood_amount,
    host_keyboard_led_state().caps_lock,
    CAPS_FLOOD_STEPS
  );
  if (host_keyboard_led_state().caps_lock || caps_flood_position > 0) {
    update_cap_flood();
  }

  // Deal with NumLock
  num_flood_position = updateFloodPosition(
    num_flood_position,
    flood_amount,
    !host_keyboard_led_state().num_lock,
    NUM_FLOOD_STEPS
  );
  if (!host_keyboard_led_state().num_lock || num_flood_position > 0) {
    update_num_flood();
  }
  
  last_frame_time = timer_read32();
  return false;
}