typedef struct {
    CRGB* pixels;
    int length;
    int pin;
} Strip;

typedef struct {
    Strip* strips;
    int length;
} Group;
