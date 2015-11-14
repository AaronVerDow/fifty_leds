#include <FastLED.h>
#include "datastructures.h"
#include "led_data.h"

const int turn_left_button = 25;
const int turn_right_button = 28;
const int safety_button = 24;
const int animation_button = 26;
//const int party_hard_button = 27;

int hue = 0;
int saturation = 255;
int brightness = 255;
int counter = 0;

const int dim = 70;

int rand_strip = 0;
int rand_pixel = 0;

const int turn_speed = 20;
const int turn_blinks = 10;
int turn_left_count = turn_speed;
int turn_right_count = turn_speed;
int turn_left_blink = 0;
int turn_right_blink = 0;

const int party_speed = 2;
const int party_blinks = 30;
int party_hard_count = party_speed;
int party_hard_blink = 0;

const CRGB headlight_on = CRGB::White;
const CRGB headlight_off = CRGB::Black;
CRGB headlight_color = headlight_off;

const CRGB party_on = CRGB::White;
const CRGB party_off = CRGB::Black;
CRGB party_hard_color = party_off;

const CRGB turn_on = CRGB(255,40,0);
const CRGB turn_off = CRGB::Black;
CRGB turn_left_color = turn_off;
CRGB turn_right_color = turn_off;

const CRGB tail_on = CRGB::Red;
const CRGB tail_off = CRGB::Black;
CRGB tail_color = tail_off;

Cycle_Actions animation = {animation_button, 0, false};
Cycle_Actions safety = {safety_button, 0, false};

void setup() {
    led_data_setup();

    //pinMode(party_hard_button, INPUT);
    pinMode(animation_button, INPUT);
    pinMode(safety_button, INPUT);
    pinMode(turn_right_button, INPUT);
    pinMode(turn_left_button, INPUT);

    //do something on power up
    //turn_left_blink = turn_blinks;
    //turn_right_blink = turn_blinks;
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

    write_animation();
    write_party();
    write_safety();
    write_turn_signals();

    FastLED.show(); 
    delay(10);
}


void write_animation() {
    check_for_button_presses(animation);
    switch (animation.counter) {
        case 0:
            //nothing
            write_group(all, CRGB::Black);
            break;
        case 1:
            //Sparkles
            write_group(all, CRGB::Black);
            write_pixel(all, rand_strip, rand_pixel, CRGB::White);
            break;
        case 2:
            write_group(all, CRGB(dim,dim,dim));
            break;
        case 3:
            write_group(all, CRGB::White);
            break;
        case 4:
            //rotate colors
            write_group(all, CHSV(hue, saturation, brightness));
            break;
        case 5:
            //rainbow
            delay_strip(all, hue, saturation, brightness);
            break;
        case 6:
            //contrast rainbow
            delay_strip(left, hue, saturation, brightness);
            delay_strip(right, hue+128, saturation, brightness);
            break;
        default:
            animation.counter = 0;
    }
}

void write_party() {
    //if (digitalRead(party_hard_button) == HIGH) {
        //party_hard_blink = party_blinks;
    //}

    if (party_hard_blink > 0) {
        if (party_hard_count == 0) {
            if (party_hard_color == party_on) {
                party_hard_color = party_off;
            } else {
                party_hard_color = party_on;
            }
            party_hard_count = party_speed;
            party_hard_blink--;
        } else {
            party_hard_count--;
        }
        if (party_hard_color == party_on) {
            write_group(all, party_hard_color);
        }
    }
}


void write_safety() {
    check_for_button_presses(safety);
    switch (safety.counter) {
        case 0:
            write_group(headlights, CRGB::Black);
            write_group(brake, CRGB::Black);
            tail_color = tail_off;
            break;
        case 1:
            //this number above needs to be changed in turn
            write_group(mega_headlights, CRGB::White);
            write_group(mega_brake, CRGB::Red);
            write_strip(fork_left, CRGB(dim,dim,dim));
            write_strip(fork_right, CRGB(dim,dim,dim));
            write_end(headlight_left, 2, turn_on);
            write_end(headlight_right, 2, turn_on);
            write_strip(tail_left, turn_on);
            write_strip(tail_right, turn_on);
            break;
        case 2:
            write_group(headlights, CRGB(dim,dim,dim));
            write_group(brake, CRGB(dim,0,0));
            write_end(headlight_left, 2, CRGB::Black);
            write_end(headlight_right, 2, CRGB::Black);
            break;
        case 3:
            write_group(headlights, CRGB::White);
            write_group(brake, CRGB::Red);
            write_end(headlight_left, 2, CRGB::Black);
            write_end(headlight_right, 2, CRGB::Black);
            break;
       case 4:
            //do nothing so animations take over
            break;
        default:
            safety.counter = 0;

    }
}

void write_turn_signals() {
    if (digitalRead(turn_left_button) == HIGH) {
        turn_left_blink = turn_blinks;
        turn_right_color = turn_off;
        turn_right_blink = 0;
    }

    if (digitalRead(turn_right_button) == HIGH) {
        turn_right_blink = turn_blinks;
        turn_left_color = turn_off;
        turn_left_blink = 0;
    }

    if (turn_right_blink > 0) {
        blink_right_color();
        write_right_turn();
    }

    if (turn_left_blink > 0) {
        blink_left_color();
        write_left_turn();
    }

}

void blink_left_color() {
    if (turn_left_count == 0) {
        if (turn_left_color == turn_on) {
            turn_left_color = turn_off;
        } else {
            turn_left_color = turn_on;
            //prevent turn signals being stuck on
            if (turn_left_blink == 1) {
                turn_left_blink++;
            }
        }
        turn_left_count = turn_speed;
        turn_left_blink--;
    } else {
        turn_left_count--;
    }
}

void blink_right_color() {
    if (turn_right_count == 0) {
        if (turn_right_color == turn_on) {
            turn_right_color = turn_off;
        } else {
            turn_right_color = turn_on;
            //prevent turn signals being stuck on
            if (turn_right_blink == 1) {
                turn_right_blink++;
            }
        }
        turn_right_count = turn_speed;
        turn_right_blink--;
    } else {
        turn_right_count--;
    }
}

void write_left_turn() {
    if (safety.counter == 1) {
        //mega safe
        write_end(headlight_left, 2, turn_left_color);
        write_strip(tail_left, turn_left_color);
        //if (turn_left_color == turn_on) {
            write_strip(gas_left, turn_left_color);
            write_strip(fork_left, turn_left_color);
            write_strip(chain, turn_left_color);
            write_strip(swing_left, turn_left_color);
            write_end(rear_tire, 6, turn_left_color);
        //}
    } else {
        //regular safe
        write_end(headlight_left, 2, turn_left_color);
        write_end(tail_left, 2, turn_left_color);
    }
}

void write_right_turn() {
    if (safety.counter == 1) {
        //mega safe
        write_end(headlight_right, 2, turn_right_color);
        write_strip(tail_right, turn_right_color);
        //if (turn_right_color == turn_on) {
            write_strip(gas_right, turn_right_color);
            write_strip(fork_right, turn_right_color);
            write_strip(swing_right, turn_right_color);
            write_begin(rear_tire, 6, turn_right_color);
        //}
    } else {
        //regular safe
        write_end(headlight_right, 2, turn_right_color);
        write_end(tail_right, 2, turn_right_color);
    }
}
void check_for_button_presses(Cycle_Actions &action) {
    if (digitalRead(action.button) == HIGH) {
        if (action.lock == false) {
            action.lock = true;
            action.counter++;
        }
    } else {
        action.lock = false;
    }
}


void write_end(Strip strip, int count, CRGB color) {
    for (int i=1; i<=count; i++) {
        strip.pixels[strip.length-i] = color;
    }
}

void write_begin(Strip strip, int count, CRGB color) {
    for (int i=0; i<count; i++) {
        strip.pixels[i] = color;
    }
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

