const int fork_left_pin = 6;
const int fender_right_pin = 7;
const int gas_left_pin = 8;
const int fender_left_pin = 9;
const int gas_right_pin = 10;
const int headlight_right_pin = 5;
const int headlight_left_pin = 4;
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
const int headlight_right_length = 12;
const int headlight_left_length = 12;
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
CRGB headlight_right_pixels[headlight_right_length];
CRGB headlight_left_pixels[headlight_left_length];
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
Strip headlight_right = {headlight_right_pixels, headlight_right_length, headlight_right_pin};
Strip headlight_left = {headlight_left_pixels, headlight_left_length, headlight_left_pin};

const int all_length = 19;
Strip all_strips[all_length];
Group all = {all_strips, all_length};

const int right_length = 9;
Strip right_strips[right_length];
Group right = {right_strips, right_length};

const int left_length = 10;
Strip left_strips[left_length];
Group left = {left_strips, left_length};

const int brake_length = 2;
Strip brake_strips[brake_length];
Group brake = {brake_strips, brake_length};

const int headlights_length = 3;
Strip headlights_strips[headlights_length];
Group headlights = {headlights_strips, headlights_length};

const int mega_brake_length = 8;
Strip mega_brake_strips[mega_brake_length];
Group mega_brake = {mega_brake_strips, mega_brake_length};

const int mega_headlights_length = 7;
Strip mega_headlights_strips[mega_headlights_length];
Group mega_headlights = {mega_headlights_strips, mega_headlights_length};

void led_data_setup() {
    FastLED.addLeds<NEOPIXEL, fork_left_pin>(fork_left_pixels, fork_left_length);
    FastLED.addLeds<NEOPIXEL, fender_right_pin>(fender_right_pixels, fender_right_length);
    FastLED.addLeds<NEOPIXEL, gas_left_pin>(gas_left_pixels, gas_left_length);
    FastLED.addLeds<NEOPIXEL, fender_left_pin>(fender_left_pixels, fender_left_length);
    FastLED.addLeds<NEOPIXEL, gas_right_pin>(gas_right_pixels, gas_right_length);
    FastLED.addLeds<NEOPIXEL, headlight_left_pin>(headlight_left_pixels, headlight_left_length);
    FastLED.addLeds<NEOPIXEL, headlight_right_pin>(headlight_right_pixels, headlight_right_length);
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

    all_strips[0] = headlight_left;
    all_strips[1] = headlight;
    all_strips[2] = headlight_right;
    all_strips[3] = fork_left;
    all_strips[4] = fork_right;
    all_strips[5] = fender_left;
    all_strips[6] = fender_right;
    all_strips[7] = gas_left;
    all_strips[8] = gas_right;
    all_strips[9] = swing_left;
    all_strips[10] = swing_right; 
    all_strips[11] = chain;
    all_strips[12] = rear_tire;
    all_strips[13] = tail_left;
    all_strips[14] = tail_right;
    all_strips[15] = seat_side_left;
    all_strips[16] = seat_side_right;
    all_strips[17] = seat_down_left;
    all_strips[18] = seat_down_right;

    right_strips[0] = headlight_right;
    right_strips[1] = fork_right;
    right_strips[2] = fender_right;
    right_strips[3] = gas_right;
    right_strips[4] = swing_right; 
    right_strips[5] = rear_tire; 
    right_strips[6] = tail_right;
    right_strips[7] = seat_side_right;
    right_strips[8] = seat_down_right;

    left_strips[0] = headlight;
    left_strips[1] = headlight_left;
    left_strips[2] = fork_left;
    left_strips[3] = fender_left;
    left_strips[4] = gas_left;
    left_strips[5] = swing_left;
    left_strips[6] = chain;
    left_strips[7] = tail_left;
    left_strips[8] = seat_side_left;
    left_strips[9] = seat_down_left;
    brake_strips[0] = tail_left;
    brake_strips[1] = tail_right;

    headlights_strips[0] = headlight_left;
    headlights_strips[1] = headlight;
    headlights_strips[2] = headlight_right;

    mega_brake_strips[0] = seat_side_right;
    mega_brake_strips[1] = seat_side_left;
    mega_brake_strips[2] = seat_down_right;
    mega_brake_strips[3] = seat_down_left;
    mega_brake_strips[4] = swing_right;
    mega_brake_strips[5] = swing_left;
    mega_brake_strips[6] = rear_tire;
    mega_brake_strips[7] = chain;

    mega_headlights_strips[0] = headlight_left;
    mega_headlights_strips[1] = headlight;
    mega_headlights_strips[2] = headlight_right;
    mega_headlights_strips[3] = fender_left;
    mega_headlights_strips[4] = fender_right;
    mega_headlights_strips[5] = gas_left;
    mega_headlights_strips[6] = gas_right;
}
