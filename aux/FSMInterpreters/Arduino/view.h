#define NEOPIX_PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      64

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIX_PIN, NEO_GRB + NEO_KHZ800);

typedef enum {question_mark = 0, home_colors, p1_mask, p2_mask, p3_mask, p4_mask,
              layer1_mask, layer2_mask, layer3_mask, layer4_mask, animate_swirl} Patterns;

unsigned char pix[3][8][8] = {{
{ 0, 0, 0,42,42, 0, 0, 0},
{ 0, 0,42, 0, 0,42, 0, 0},
{ 0, 0, 0, 0, 0, 42, 0, 0},
{ 0, 0, 0, 0, 0, 42, 0, 0},
{ 0, 0, 0, 42, 42, 0, 0, 0},
{ 0, 0, 0, 42, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 42, 0, 0, 0, 0}
},
{
{0b111100,12,12,12,12,12,12, 0b101110},
{0b110000, 0, 0, 0, 0, 0, 0, 0b101010},
{0b110000, 0, 0, 0, 0, 0, 0, 0b101010},
{0b110000, 0, 0, 0, 0, 0, 0, 0b101010},
{0b110000, 0, 0, 0, 0, 0, 0, 0b101010},
{0b110000, 0, 0, 0, 0, 0, 0, 0b101010},
{0b110000, 0, 0, 0, 0, 0, 0, 0b101010},
{0b111011, 3, 3, 3, 3, 3, 3, 0b101011}
},
{
{0b01111110,0b00000000,0b00000000,0b00000000,0b11111111,0b00000000,0b00000000,0b00000000},
{0b00111100,0b00000001,0b00000000,0b10000000,0b10000001,0b01111110,0b00000000,0b00000000},
{0b00011000,0b00000011,0b00000000,0b11000000,0b10000001,0b01000010,0b00111100,0b00000000},
{0b00000000,0b00000111,0b00000000,0b11100000,0b10000001,0b01000010,0b00100100,0b00011000},
{0b00000000,0b00000111,0b00000000,0b11100000,0b10000001,0b01000010,0b00100100,0b00011000},
{0b00000000,0b00000011,0b00011000,0b11000000,0b10000001,0b01000010,0b00111100,0b00000000},
{0b00000000,0b00000001,0b00111100,0b10000000,0b10000001,0b01111110,0b00000000,0b00000000},
{0b00000000,0b00000000,0b01111110,0b00000000,0b11111111,0b00000000,0b00000000,0b00000000}
}};
int swirl_i = 0;

// pixel map of where the indexes fall
//  0  1  2  3  4  5  6  7
//  8  9 10 11 12 13 14 15
// 16 17 18 19 20 21 22 23
// 24 25 26 27 28 29 30 31
// 32 33 34 35 36 37 38 39
// 40 41 42 43 44 45 46 47
// 48 49 50 51 52 53 54 55
// 56 57 58 59 60 61 62 63
#define SWIRL_SIZE 66
unsigned char swirl_path[SWIRL_SIZE] =
{0, 1, 2, 3, 4, 5, 6, 7
,15,23,31,39, 47, 55, 63
,62,61,60,59,58, 57,56
,48,40,32,24,16
,17,18,19,20,21
,29,37,45, 44, 43,42
,34,35
,43, 44, 36, 28
,27,26,25, 33,41,49, 50,51,52,53,54
,46,38,30,22,14, 13,12,11,10,9,8};

void display(int p) {
  if (p == animate_swirl) {
    pixels.setPixelColor(swirl_path[swirl_i], pixels.Color(0, 0, 0));
    swirl_i = (swirl_i+1)%SWIRL_SIZE;
    pixels.setPixelColor(swirl_path[(swirl_i+1)%SWIRL_SIZE], pixels.Color(4, 3, 4));
    pixels.setPixelColor(swirl_path[(swirl_i+2)%SWIRL_SIZE], pixels.Color(6, 6, 20));
    pixels.setPixelColor(swirl_path[(swirl_i+3)%SWIRL_SIZE], pixels.Color(10, 8, 10));
    pixels.setPixelColor(swirl_path[(swirl_i+4)%SWIRL_SIZE], pixels.Color(20, 10, 8));
    pixels.setPixelColor(swirl_path[(swirl_i+5)%SWIRL_SIZE], pixels.Color(10, 20, 4));
    pixels.setPixelColor(swirl_path[(swirl_i+6)%SWIRL_SIZE], pixels.Color(4, 8, 2));
  }
  else if (p < p1_mask) {
    unsigned char red_filter = 0b110000;
    unsigned char blu_filter = 0b001100;
    unsigned char gre_filter = 0b000011;
    unsigned char red_shift = 4;
    unsigned char blu_shift = 2;
    unsigned char gre_shift = 0;
    for(int i=0;i<8;i+=1) {
      for(int j=0;j<8;j+=1) {
        unsigned char red = ((pix[p][i][j]&red_filter)>>red_shift)*3;
        unsigned char blu = ((pix[p][i][j]&blu_filter)>>blu_shift)*3;
        unsigned char gre = ((pix[p][i][j]&gre_filter)>>gre_shift)*3;
        pixels.setPixelColor(i*8+j, pixels.Color(red, blu, gre));
      }
    }
  }
  pixels.show();
}

void mask(int mask, uint32_t overlay_color) {
  unsigned char offset = mask - p1_mask;
  for(int i=0;i<8;i+=1) {
    unsigned char row = pix[p1_mask][i][offset];
    for(int j=0;j<8;j+=1) {
      if ((row >> j) & 1) {
        if (overlay_color) {
          pixels.setPixelColor(i*8+j, overlay_color);
       }
      }
      else {
        if (!overlay_color) {
          pixels.setPixelColor(i*8+j, pixels.Color(0,0,0));
        }
      }
    }
  }
  pixels.show();
}
