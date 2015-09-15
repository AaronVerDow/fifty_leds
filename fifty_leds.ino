#include <FastLED.h>
#include "datastructures.h"

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

const int fender_left_length = 17;
const int fender_right_length = 17;
const int fork_left_length = 16;
const int fork_right_length = 16;
const int gas_left_length = 12;
const int gas_right_length = 12;
const int seat_side_left_length = 13;
const int seat_side_right_length = 13;
const int seat_down_left_length = 11;
const int seat_down_right_length = 11;
const int swing_left_length = 6;
const int swing_right_length = 4;
const int chain_length = 24;
const int rear_tire_length = 20;
const int tail_left_length = 4;
const int tail_right_length = 4;
const int unknown_length = 5;

CRGB fender_left_pixels[fender_left_length];
CRGB fender_right_pixels[fender_right_length];
CRGB fork_left_pixels[fork_left_length];
CRGB fork_right_pixels[fork_right_length];
CRGB gas_left_pixels[gas_left_length];
CRGB gas_right_pixels[gas_right_length];
CRGB seat_side_left_pixels[seat_side_left_length];
CRGB seat_side_right_pixels[seat_side_right_length];
CRGB seat_down_left_pixels[seat_down_left_length];
CRGB seat_down_right_pixels[seat_down_right_length];
CRGB swing_left_pixels[swing_left_length];
CRGB swing_right_pixels[swing_right_length];
CRGB chain_pixels[chain_length];
CRGB rear_tire_pixels[rear_tire_length];
CRGB tail_left_pixels[tail_left_length];
CRGB tail_right_pixels[tail_right_length];
CRGB unknown_pixels[unknown_length];

Strip fender_left = {fender_left_pixels, fender_left_length, fender_left_pin};
Strip fender_right = {fender_right_pixels, fender_right_length, fender_right_pin};
Strip fork_left = {fork_left_pixels, fork_left_length, fork_left_pin};
Strip fork_right = {fork_right_pixels, fork_right_length, fork_right_pin};
Strip gas_left = {gas_left_pixels, gas_left_length, gas_left_pin};
Strip gas_right = {gas_right_pixels, gas_right_length, gas_right_pin};
Strip seat_side_left = {seat_side_left_pixels, seat_side_left_length, seat_side_left_pin};
Strip seat_side_right = {seat_side_right_pixels, seat_side_right_length, seat_side_right_pin};
Strip seat_down_left = {seat_down_left_pixels, seat_down_left_length, seat_down_left_pin};
Strip seat_down_right = {seat_down_right_pixels, seat_down_right_length, seat_down_right_pin};
Strip swing_left = {swing_left_pixels, swing_left_length, swing_left_pin};
Strip swing_right = {swing_right_pixels, swing_right_length, swing_right_pin};
Strip chain = {chain_pixels, chain_length, chain_pin};
Strip rear_tire = {rear_tire_pixels, rear_tire_length, rear_tire_pin};
Strip tail_left = {tail_left_pixels, tail_left_length, tail_left_pin};
Strip tail_right = {tail_right_pixels, tail_right_length, tail_right_pin};
Strip unknown = {unknown_pixels, unknown_length, unknown_pin};

const int all_length = 17;
Strip all_strips[all_length];
Group all = {all_strips, all_length};

int hue = 0;
int saturation = 255;
int brightness = 255;

void setup() {
    FastLED.addLeds<NEOPIXEL, fork_left_pin>(fork_left_pixels, fork_left_length);
    FastLED.addLeds<NEOPIXEL, fender_right_pin>(fender_right_pixels, fender_right_length);
    FastLED.addLeds<NEOPIXEL, gas_left_pin>(gas_left_pixels, gas_left_length);
    FastLED.addLeds<NEOPIXEL, fender_left_pin>(fender_left_pixels, fender_left_length);
    FastLED.addLeds<NEOPIXEL, gas_right_pin>(gas_right_pixels, gas_right_length);
    FastLED.addLeds<NEOPIXEL, unknown_pin>(unknown_pixels, unknown_length);
    FastLED.addLeds<NEOPIXEL, fork_right_pin>(fork_right_pixels, fork_right_length);
    FastLED.addLeds<NEOPIXEL, swing_left_pin>(swing_left_pixels, swing_left_length);
    FastLED.addLeds<NEOPIXEL, rear_tire_pin>(rear_tire_pixels, rear_tire_length);
    FastLED.addLeds<NEOPIXEL, seat_side_left_pin>(seat_side_left_pixels, seat_side_left_length);
    FastLED.addLeds<NEOPIXEL, swing_right_pin>(swing_right_pixels, swing_right_length);
    FastLED.addLeds<NEOPIXEL, tail_left_pin>(tail_left_pixels, tail_left_length);
    FastLED.addLeds<NEOPIXEL, tail_right_pin>(tail_right_pixels, tail_right_length);
    FastLED.addLeds<NEOPIXEL, seat_side_right_pin>(seat_side_right_pixels, seat_side_right_length);
    FastLED.addLeds<NEOPIXEL, seat_down_right_pin>(seat_down_right_pixels, seat_down_right_length);
    FastLED.addLeds<NEOPIXEL, seat_down_left_pin>(seat_down_left_pixels, seat_down_left_length);
    FastLED.addLeds<NEOPIXEL, chain_pin>(chain_pixels, chain_length);

    all_strips[0] = fender_left;
    all_strips[1] = fender_right;
    all_strips[2] = fork_left;
    all_strips[3] = fork_right;
    all_strips[4] = gas_left;
    all_strips[5] = gas_right;
    all_strips[6] = seat_side_left;
    all_strips[7] = seat_side_right;
    all_strips[8] = seat_down_left;
    all_strips[9] = seat_down_right;
    all_strips[10] = swing_left;
    all_strips[11] = swing_right; 
    all_strips[12] = chain;
    all_strips[13] = rear_tire;
    all_strips[14] = tail_left;
    all_strips[15] = tail_right;
    all_strips[16] = unknown;

    delay(1000); 
}

void loop() { 
    hue++;
    if (hue > 255 ) {
        hue = 0;
    }
    write_group(all, CHSV(hue, saturation, brightness));
    FastLED.show(); 
    delay(10);
}

//void write_strip(Strip strip, CRGB color) {
    //for (int pixel = 0; pixel < strip.length; pixel++) {
        //strip.pixels[pixel] = color;
        //strip.pixels[pixel] = color;
    //}
    //rear_tire[0] = color;
//}

void write_group(Group group, CRGB color) {
    for (int strip = 0; strip < group.length; strip++) {
        for (int pixel = 0; pixel < group.strips[strip].length; pixel++) {
            group.strips[strip].pixels[pixel] = color;
        }
    }
}
