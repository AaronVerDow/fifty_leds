#include <FastLED.h>

const int number_of_strips = 17;

const int fork_left_pin = 6;
const int fender_right_pin = 7;
const int gas_left_pin = 8;
const int fender_left_pin = 9;
const int gas_right_pin = 10;
const int unknown_pin = 11;
const int fork_right_pin = 12;
const int swing_left_pin = 13;
const int rear_tire_pin = 14;
const int seat_side_left_pin = 15;
const int swing_right_pin = 16;
const int tail_left_pin = 17;
const int tail_right_pin = 18;
const int seat_side_right_pin = 19;
const int seat_down_right_pin = 20;
const int seat_down_left_pin = 21;
const int chain_pin = 22;

const int fender_left_length = 15;
const int fender_right_length = 15;
const int fork_left_length = 10;
const int fork_right_length = 10;
const int gas_left_length = 12;
const int gas_right_length = 12;
const int seat_side_left_length = 13;
const int seat_side_right_length = 13;
const int seat_down_left_length = 11;
const int seat_down_right_length = 11;
const int swing_left_length = 6;
const int swing_right_length = 4;
const int chain_length = 20;
const int rear_tire_length = 20;
const int tail_left_length = 4;
const int tail_right_length = 4;
const int unknown_length = 5;

CRGB fender_left[fender_left_length];
CRGB fender_right[fender_right_length];
CRGB fork_left[fork_left_length];
CRGB fork_right[fork_right_length];
CRGB gas_left[gas_left_length];
CRGB gas_right[gas_right_length];
CRGB seat_side_left[seat_side_left_length];
CRGB seat_side_right[seat_side_right_length];
CRGB seat_down_left[seat_down_left_length];
CRGB seat_down_right[seat_down_right_length];
CRGB swing_left[swing_left_length];
CRGB swing_right[swing_right_length];
CRGB chain[chain_length];
CRGB rear_tire[rear_tire_length];
CRGB tail_left[tail_left_length];
CRGB tail_right[tail_right_length];
CRGB unknown[unknown_length];

CRGB* leds[number_of_strips];
int leds_length[number_of_strips];

void setup() {
    FastLED.addLeds<NEOPIXEL, fork_left_pin>(fork_left, fork_left_pin);
    FastLED.addLeds<NEOPIXEL, fender_right_pin>(fender_right, fender_right_pin);
    FastLED.addLeds<NEOPIXEL, gas_left_pin>(gas_left, gas_left_pin);
    FastLED.addLeds<NEOPIXEL, fender_left_pin>(fender_left, fender_left_pin);
    FastLED.addLeds<NEOPIXEL, gas_right_pin>(gas_right, gas_right_pin);
    FastLED.addLeds<NEOPIXEL, unknown_pin>(unknown, unknown_pin);
    FastLED.addLeds<NEOPIXEL, fork_right_pin>(fork_right, fork_right_pin);
    FastLED.addLeds<NEOPIXEL, swing_left_pin>(swing_left, swing_left_pin);
    FastLED.addLeds<NEOPIXEL, rear_tire_pin>(rear_tire, rear_tire_pin);
    FastLED.addLeds<NEOPIXEL, seat_side_left_pin>(seat_side_left, seat_side_left_pin);
    FastLED.addLeds<NEOPIXEL, swing_right_pin>(swing_right, swing_right_pin);
    FastLED.addLeds<NEOPIXEL, tail_left_pin>(tail_left, tail_left_pin);
    FastLED.addLeds<NEOPIXEL, tail_right_pin>(tail_right, tail_right_pin);
    FastLED.addLeds<NEOPIXEL, seat_side_right_pin>(seat_side_right, seat_side_right_pin);
    FastLED.addLeds<NEOPIXEL, seat_down_right_pin>(seat_down_right, seat_down_right_pin);
    FastLED.addLeds<NEOPIXEL, seat_down_left_pin>(seat_down_left, seat_down_left_pin);
    FastLED.addLeds<NEOPIXEL, chain_pin>(chain, chain_pin);

    leds[0] = fender_left;
    leds[1] = fender_right;
    leds[2] = fork_left;
    leds[3] = fork_right;
    leds[4] = gas_left;
    leds[5] = gas_right;
    leds[6] = seat_side_left;
    leds[7] = seat_side_right;
    leds[8] = seat_down_left;
    leds[9] = seat_down_right;
    leds[10] = swing_left;
    leds[11] = swing_right; 
    leds[12] = chain;
    leds[13] = rear_tire;
    leds[14] = tail_left;
    leds[15] = tail_right;
    leds[16] = unknown;

    leds_length[0] = fender_left_length;
    leds_length[1] = fender_right_length;
    leds_length[2] = fork_left_length;
    leds_length[3] = fork_right_length;
    leds_length[4] = gas_left_length;
    leds_length[5] = gas_right_length;
    leds_length[6] = seat_side_left_length;
    leds_length[7] = seat_side_right_length;
    leds_length[8] = seat_down_left_length;
    leds_length[9] = seat_down_right_length;
    leds_length[10] = swing_left_length;
    leds_length[11] = swing_right_length; 
    leds_length[12] = chain_length;
    leds_length[13] = rear_tire_length;
    leds_length[14] = tail_left_length;
    leds_length[15] = tail_right_length;
    leds_length[16] = unknown_length;

    delay(1000); 
}

void loop() { 

    for (int strip = 0; strip < 17; strip++) {
        for (int pixel = 0; pixel < leds_length[strip]; pixel++) {
            leds[strip][pixel] = CRGB::Magenta; 
        }
        leds[strip][0] = CRGB::Blue;
        leds[strip][leds_length[strip]-1] = CRGB::Red;
    }

    for (int pixel = 0; pixel < rear_tire_length; pixel++) {
        rear_tire[pixel] = CRGB::Green;
    }
    rear_tire[rear_tire_length-1] = CRGB::Red;
    FastLED.show(); 
    delay(1000);
}

