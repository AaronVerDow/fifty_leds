#include <FastLED.h>
#include "datastructures.h"

const int fork_left_pin = 6;
const int fender_right_pin = 7;
const int gas_left_pin = 8;
const int fender_left_pin = 9;
const int gas_right_pin = 10;
const int right_headlight_pin = 5;
const int left_headlight_pin = 4;
const int headlight_pin = 11;
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
const int right_headlight_length = 12;
const int left_headlight_length = 12;
const int headlight_length = 10;

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
CRGB right_headlight_pixels[right_headlight_length];
CRGB left_headlight_pixels[left_headlight_length];
CRGB headlight_pixels[headlight_length];

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
Strip headlight = {headlight_pixels, headlight_length, headlight_pin};
Strip right_headlight = {right_headlight_pixels, right_headlight_length, right_headlight_pin};
Strip left_headlight = {left_headlight_pixels, left_headlight_length, left_headlight_pin};

const int all_length = 19;
Strip all_strips[all_length];
Group all = {all_strips, all_length};

const int brake_length = 2;
Strip brake_strips[brake_length];
Group brake = {brake_strips, brake_length};

const int left_length = 8;
Strip left_strips[left_length];
Group left = {left_strips, left_length};

const int right_length = 8;
Strip right_strips[right_length];
Group right = {right_strips, right_length};

const int headlights_length = 3;
Strip headlights_strips[headlights_length];
Group headlights = {headlights_strips, headlights_length};

int hue = 0;
int saturation = 255;
int brightness = 255;
int counter = 0;

int rand_strip = 0;
int rand_pixel = 0;

void setup() {
    FastLED.addLeds<NEOPIXEL, fork_left_pin>(fork_left_pixels, fork_left_length);
    FastLED.addLeds<NEOPIXEL, fender_right_pin>(fender_right_pixels, fender_right_length);
    FastLED.addLeds<NEOPIXEL, gas_left_pin>(gas_left_pixels, gas_left_length);
    FastLED.addLeds<NEOPIXEL, fender_left_pin>(fender_left_pixels, fender_left_length);
    FastLED.addLeds<NEOPIXEL, gas_right_pin>(gas_right_pixels, gas_right_length);
    FastLED.addLeds<NEOPIXEL, left_headlight_pin>(left_headlight_pixels, left_headlight_length);
    FastLED.addLeds<NEOPIXEL, right_headlight_pin>(right_headlight_pixels, right_headlight_length);
    FastLED.addLeds<NEOPIXEL, headlight_pin>(headlight_pixels, headlight_length);
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

    all_strips[0] = left_headlight;
    all_strips[1] = right_headlight;
    all_strips[2] = headlight;
    all_strips[3] = fender_left;
    all_strips[4] = fender_right;
    all_strips[5] = fork_left;
    all_strips[6] = fork_right;
    all_strips[7] = gas_left;
    all_strips[8] = gas_right;
    all_strips[9] = seat_side_left;
    all_strips[10] = seat_side_right;
    all_strips[11] = seat_down_left;
    all_strips[12] = seat_down_right;
    all_strips[13] = swing_left;
    all_strips[14] = swing_right; 
    all_strips[15] = chain;
    all_strips[16] = rear_tire;
    all_strips[17] = tail_left;
    all_strips[18] = tail_right;

    right_strips[0] = fender_right;
    right_strips[1] = fork_right;
    right_strips[2] = gas_right;
    right_strips[3] = seat_side_right;
    right_strips[4] = seat_down_right;
    right_strips[5] = swing_right; 
    right_strips[6] = rear_tire; 
    right_strips[7] = tail_right;

    left_strips[0] = fender_left;
    left_strips[1] = fork_left;
    left_strips[2] = gas_left;
    left_strips[3] = seat_side_left;
    left_strips[4] = seat_down_left;
    left_strips[5] = swing_left;
    left_strips[6] = chain;
    left_strips[7] = tail_left;

    brake_strips[0] = tail_left;
    brake_strips[1] = tail_right;

    headlights_strips[0] = left_headlight;
    headlights_strips[1] = headlight;
    headlights_strips[2] = right_headlight;


    delay(1000); 
}

void loop() { 
    hue++;
    if (hue > 255 ) {
        hue = 0;
    }
    counter--;
    if (counter < 1) {
        counter = 6;
        rand_strip = random(0,all.length-1);
        rand_pixel = random(0,all.strips[rand_strip].length-1);
    }
    //hue = 40;
    //looks good, decent rolling rainbow
    delay_strip(all, hue, saturation, brightness);

    //similar to above, slight pixel shift
    //delay_strip_and_pixel(all, hue, saturation, brightness, 12, 3);

    //kinda raver plaid-ish, gives a mostly white appearance
    //delay_strip_and_pixel(all, hue, saturation, brightness, 10, 67);

    //delay_strip(all, hue, saturation, brightness);
    //kind of sparkly
    //write_pixel(all, rand_strip, rand_pixel, CRGB::White);
    
    //random strips
    //write_strip(all.strips[rand_strip], CHSV(random(0,255), 255, 255));

    //delay_strip(left, hue, saturation, brightness);
    //delay_strip(right, hue+128, saturation, brightness);
    //write_strip(rear_tire, CHSV(hue+42, saturation, brightness));

    //write_group(all, CRGB::White);
    write_group(brake, CRGB::Red);
    write_group(headlights, CRGB::White);

    CRGB turn_color = CRGB::DarkOrange;

    left_headlight.pixels[left_headlight_length-1] = turn_color;
    left_headlight.pixels[left_headlight_length-2] = turn_color;
    right_headlight.pixels[right_headlight_length-1] = turn_color;
    right_headlight.pixels[right_headlight_length-2] = turn_color;

    FastLED.show(); 
    delay(10);
}

void write_blinky_white() {
    random_pixel(all, CRGB::White);
    random_pixel(all, CRGB::Black);
    random_pixel(all, CRGB::Black);
}

void write_random_pixels() {
    random_pixel(all, CHSV(random(0,255), 255, random(0,255)));
    random_pixel(all, CHSV(random(0,255), 255, random(0,255)));
    random_pixel(all, CHSV(random(0,255), 255, random(0,255)));
    random_pixel(all, CRGB::Black);
    random_pixel(all, CRGB::Black);
    random_pixel(all, CRGB::Black);
    random_pixel(all, CRGB::Black);
    random_pixel(all, CRGB::Black);
    random_pixel(all, CRGB::Black);
}

void write_strip(Strip strip, CRGB color) {
    for (int i = 0; i < strip.length; i++) {
        strip.pixels[i] = color;
    }
}

void write_pixel(Group group, int strip, int pixel, CRGB color) {
    group.strips[strip].pixels[pixel] = color;
}

void random_pixel(Group group, CRGB color) {
    int strip = random(0,group.length-1);
    int pixel = random(0,group.strips[strip].length-1);
    group.strips[strip].pixels[pixel] = color;
}

void write_group(Group group, CRGB color) {
    for (int strip = 0; strip < group.length; strip++) {
        for (int pixel = 0; pixel < group.strips[strip].length; pixel++) {
            group.strips[strip].pixels[pixel] = color;
        }
    }
}

void delay_strip(Group group, int h, int s, int b) {
    for (int strip = 0; strip < group.length; strip++) {
        for (int pixel = 0; pixel < group.strips[strip].length; pixel++) {
            int my_hue = h + (strip * 15);
            group.strips[strip].pixels[pixel] = CHSV(my_hue, s, b);
        }
    }
}

void delay_strip_and_pixel(Group group, int h, int s, int b, int strip_multiplier, int pixel_multiplier) {
    for (int strip = 0; strip < group.length; strip++) {
        for (int pixel = 0; pixel < group.strips[strip].length; pixel++) {
            int my_hue = h + (strip * strip_multiplier) + (pixel * pixel_multiplier);
            group.strips[strip].pixels[pixel] = CHSV(my_hue, s, b);
        }
    }
}
