#pragma once

#define MK_3_SPEED
#define MK_C_INTERVAL_0 7
#define MK_C_OFFSET_1 3
#define MK_C_INTERVAL_1 7
#define MK_C_OFFSET_2 8
#define MK_C_INTERVAL_2 7
#define TAPPING_TOGGLE 2
#undef RGBLIGHT_ANIMATIONS
#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)
    #define NOINPUT_SOUND Q__NOTE(_C4), E__NOTE(_REST), Q__NOTE(_C4)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#define RGBLIGHT_SLEEP
