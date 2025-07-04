
#define max_char 100
int charIndex;
int scrollspeed = 10; //Set the scroll speed 
int i;
int x;
int y;
char r_char;


char msg[] = "Rj Avro"; //Change the text here.


//Columns
int clockPin1 = 7; //Arduino pin connected to Clock Pin 11 of 74HC595
int latchPin1 = 5; //Arduino pin connected to Latch Pin 12 of 74HC595
int dataPin1 = 6;  //Arduino pin connected to Data Pin 14 of 74HC595

//Rows
int clockPin2 = 12; //Arduino pin connected to Clock Pin 11 of 74HC595
int latchPin2 = 10; //Arduino pin connected to Latch Pin 12 of 74HC595
int dataPin2 = 11;  //Arduino pin connected to Data Pin 14 of 74HC595


byte bitmap[8][7];

int numZones = sizeof(bitmap) / 8; // One Zone refers to one 8 x 8 Matrix ( Group of 8 columns)
int maxZoneIndex = numZones - 1;
int numCols = numZones * 8;


//Font-1
char alphabets[95][8] = {
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // SPACE
  {0x00, 0x00, 0x00, 0x4f, 0x4f, 0x00, 0x00, 0x00}, // !
  {0x00, 0x07, 0x07, 0x00, 0x00, 0x07, 0x07, 0x00}, // "
  {0x14, 0x7f, 0x7f, 0x14, 0x14, 0x7f, 0x7f, 0x14}, // #
  {0x00, 0x24, 0x2e, 0x6b, 0x6b, 0x3a, 0x12, 0x00}, // $
  {0x00, 0x63, 0x33, 0x18, 0x0c, 0x66, 0x63, 0x00}, // %
  {0x00, 0x32, 0x7f, 0x4d, 0x4d, 0x77, 0x72, 0x50}, // &
  {0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00}, // '
  {0x00, 0x00, 0x1c, 0x3e, 0x63, 0x41, 0x00, 0x00}, // (
  {0x00, 0x00, 0x41, 0x63, 0x3e, 0x1c, 0x00, 0x00}, // )
  //{0x08, 0x2a, 0x3e, 0x1c, 0x1c, 0x3e, 0x2a, 0x08}, // *
  {0x0,0xc,0x1e,0x3e,0x7c,0x3e,0x1e,0xc},            //* CORAZON
  {0x00, 0x08, 0x08, 0x3e, 0x3e, 0x08, 0x08, 0x00}, // +
  {0x00, 0x00, 0x80, 0xe0, 0x60, 0x00, 0x00, 0x00}, // ,
  {0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00}, // -
  {0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00}, // .
  {0x00, 0x40, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x02}, // /
  {0x00, 0x3e, 0x7f, 0x49, 0x45, 0x7f, 0x3e, 0x00}, // 0
  {0x00, 0x40, 0x44, 0x7f, 0x7f, 0x40, 0x40, 0x00}, // 1
  {0x00, 0x62, 0x73, 0x51, 0x49, 0x4f, 0x46, 0x00}, // 2
  {0x00, 0x22, 0x63, 0x49, 0x49, 0x7f, 0x36, 0x00}, // 3
  {0x00, 0x18, 0x18, 0x14, 0x16, 0x7f, 0x7f, 0x10}, // 4
  {0x00, 0x27, 0x67, 0x45, 0x45, 0x7d, 0x39, 0x00}, // 5
  {0x00, 0x3e, 0x7f, 0x49, 0x49, 0x7b, 0x32, 0x00}, // 6
  {0x00, 0x03, 0x03, 0x79, 0x7d, 0x07, 0x03, 0x00}, // 7
  {0x00, 0x36, 0x7f, 0x49, 0x49, 0x7f, 0x36, 0x00}, // 8
  {0x00, 0x26, 0x6f, 0x49, 0x49, 0x7f, 0x3e, 0x00}, // 9
  {0x00, 0x00, 0x00, 0x24, 0x24, 0x00, 0x00, 0x00}, // :
  {0x00, 0x00, 0x80, 0xe4, 0x64, 0x00, 0x00, 0x00}, // ;
  {0x00, 0x08, 0x1c, 0x36, 0x63, 0x41, 0x41, 0x00}, // <
  {0x00, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x00}, // =
  {0x00, 0x41, 0x41, 0x63, 0x36, 0x1c, 0x08, 0x00}, // >
  {0x00, 0x02, 0x03, 0x51, 0x59, 0x0f, 0x06, 0x00}, // ?
  {0x00, 0x3e, 0x7f, 0x41, 0x4d, 0x4f, 0x2e, 0x00}, // @
  {0x00, 0x7c, 0x7e, 0x0b, 0x0b, 0x7e, 0x7c, 0x00}, // A
  {0x00, 0x7f, 0x7f, 0x49, 0x49, 0x7f, 0x36, 0x00}, // B
  {0x00, 0x3e, 0x7f, 0x41, 0x41, 0x63, 0x22, 0x00}, // C
  {0x00, 0x7f, 0x7f, 0x41, 0x63, 0x3e, 0x1c, 0x00}, // D
  {0x00, 0x7f, 0x7f, 0x49, 0x49, 0x41, 0x41, 0x00}, // E
  {0x00, 0x7f, 0x7f, 0x09, 0x09, 0x01, 0x01, 0x00}, // F
  {0x00, 0x3e, 0x7f, 0x41, 0x49, 0x7b, 0x3a, 0x00}, // G
  {0x00, 0x7f, 0x7f, 0x08, 0x08, 0x7f, 0x7f, 0x00}, // H
  {0x00, 0x00, 0x41, 0x7f, 0x7f, 0x41, 0x00, 0x00}, // I
  {0x00, 0x20, 0x60, 0x41, 0x7f, 0x3f, 0x01, 0x00}, // J
  {0x00, 0x7f, 0x7f, 0x1c, 0x36, 0x63, 0x41, 0x00}, // K
  {0x00, 0x7f, 0x7f, 0x40, 0x40, 0x40, 0x40, 0x00}, // L
  {0x00, 0x7f, 0x7f, 0x06, 0x0c, 0x06, 0x7f, 0x7f}, // M
  {0x00, 0x7f, 0x7f, 0x0e, 0x1c, 0x7f, 0x7f, 0x00}, // N
  {0x00, 0x3e, 0x7f, 0x41, 0x41, 0x7f, 0x3e, 0x00}, // O
  {0x00, 0x7f, 0x7f, 0x09, 0x09, 0x0f, 0x06, 0x00}, // P
  {0x00, 0x1e, 0x3f, 0x21, 0x61, 0x7f, 0x5e, 0x00}, // Q
  {0x00, 0x7f, 0x7f, 0x19, 0x39, 0x6f, 0x46, 0x00}, // R
  {0x00, 0x26, 0x6f, 0x49, 0x49, 0x7b, 0x32, 0x00}, // S
  {0x00, 0x01, 0x01, 0x7f, 0x7f, 0x01, 0x01, 0x00}, // T
  {0x00, 0x3f, 0x7f, 0x40, 0x40, 0x7f, 0x3f, 0x00}, // U
  {0x00, 0x1f, 0x3f, 0x60, 0x60, 0x3f, 0x1f, 0x00}, // V
  {0x00, 0x7f, 0x7f, 0x30, 0x18, 0x30, 0x7f, 0x7f}, // W
  {0x00, 0x63, 0x77, 0x1c, 0x1c, 0x77, 0x63, 0x00}, // X
  {0x00, 0x07, 0x0f, 0x78, 0x78, 0x0f, 0x07, 0x00}, // Y
  {0x00, 0x61, 0x71, 0x59, 0x4d, 0x47, 0x43, 0x00}, // Z
  {0x00, 0x00, 0x7f, 0x7f, 0x41, 0x41, 0x00, 0x00}, // [
  {0x00, 0x02, 0x06, 0x0c, 0x18, 0x30, 0x60, 0x40}, // \
  
  {0x00, 0x00, 0x41, 0x41, 0x7f, 0x7f, 0x00, 0x00}, // ]
  {0x00, 0x04, 0x06, 0x03, 0x03, 0x06, 0x04, 0x00}, // ^
  {0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80}, // _
  {0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x04, 0x00}, // `
  {0x00, 0x20, 0x74, 0x54, 0x54, 0x7c, 0x78, 0x00}, // a
  {0x00, 0x7e, 0x7e, 0x48, 0x48, 0x78, 0x30, 0x00}, // b
  {0x00, 0x38, 0x7c, 0x44, 0x44, 0x44, 0x00, 0x00}, // c
  {0x00, 0x30, 0x78, 0x48, 0x48, 0x7e, 0x7e, 0x00}, // d
  {0x00, 0x38, 0x7c, 0x54, 0x54, 0x5c, 0x18, 0x00}, // e
  {0x00, 0x00, 0x08, 0x7c, 0x7e, 0x0a, 0x0a, 0x00}, // f
  {0x00, 0x98, 0xbc, 0xa4, 0xa4, 0xfc, 0x7c, 0x00}, // g
  {0x00, 0x7e, 0x7e, 0x08, 0x08, 0x78, 0x70, 0x00}, // h
  {0x00, 0x00, 0x48, 0x7a, 0x7a, 0x40, 0x00, 0x00}, // i
  {0x00, 0x00, 0x80, 0x80, 0x80, 0xfa, 0x7a, 0x00}, // j
  {0x00, 0x7e, 0x7e, 0x10, 0x38, 0x68, 0x40, 0x00}, // k
  {0x00, 0x00, 0x42, 0x7e, 0x7e, 0x40, 0x00, 0x00}, // l
  {0x00, 0x7c, 0x7c, 0x18, 0x38, 0x1c, 0x7c, 0x78}, // m
  {0x00, 0x7c, 0x7c, 0x04, 0x04, 0x7c, 0x78, 0x00}, // n
  {0x00, 0x38, 0x7c, 0x44, 0x44, 0x7c, 0x38, 0x00}, // o
  {0x00, 0xfc, 0xfc, 0x24, 0x24, 0x3c, 0x18, 0x00}, // p
  {0x00, 0x18, 0x3c, 0x24, 0x24, 0xfc, 0xfc, 0x00}, // q
  {0x00, 0x7c, 0x7c, 0x04, 0x04, 0x0c, 0x08, 0x00}, // r
  {0x00, 0x48, 0x5c, 0x54, 0x54, 0x74, 0x24, 0x00}, // s
  {0x00, 0x04, 0x04, 0x3e, 0x7e, 0x44, 0x44, 0x00}, // t
  {0x00, 0x3c, 0x7c, 0x40, 0x40, 0x7c, 0x7c, 0x00}, // u
  {0x00, 0x1c, 0x3c, 0x60, 0x60, 0x3c, 0x1c, 0x00}, // v
  {0x00, 0x1c, 0x7c, 0x70, 0x38, 0x70, 0x7c, 0x1c}, // w
  {0x00, 0x44, 0x6c, 0x38, 0x38, 0x6c, 0x44, 0x00}, // x
  {0x00, 0x9c, 0xbc, 0xa0, 0xe0, 0x7c, 0x3c, 0x00}, // y
  {0x00, 0x44, 0x64, 0x74, 0x5c, 0x4c, 0x44, 0x00}, // z
  {0x00, 0x00, 0x08, 0x3e, 0x77, 0x41, 0x00, 0x00}, // {
  {0x00, 0x00, 0x00, 0x7f, 0x7f, 0x00, 0x00, 0x00}, // |
  {0x00, 0x00, 0x41, 0x77, 0x3e, 0x08, 0x00, 0x00}, // }
  {0x00, 0x08, 0x04, 0x0c, 0x18, 0x01, 0x08, 0x00} // ~
};


////Font-2
//char alphabets[][8] = {
////static unsigned char font5x7[][6] PROGMEM= {
//{0x00,0x00,0x00,0x00,0x00,0x00}, // SPACE
//{0x0,0x0,0x0,0xdf, 0xdf, 0xdf, 0x0,0x0}, // !
//{0x00,0x00,0x07,0x00,0x07,0x00}, // "
//{0x00,0x14,0x7F,0x14,0x7F,0x14}, // #
//{0x00,0x24,0x2A,0x7F,0x2A,0x12}, // $
//{0x00,0x23,0x13,0x08,0x64,0x62}, // %
//{0x00,0x36,0x49,0x55,0x22,0x50}, // &
//{0x00,0x00,0x05,0x03,0x00,0x00}, // '
//{0x00,0x00,0x1C,0x22,0x41,0x00}, // (
//{0x00,0x00,0x41,0x22,0x1C,0x00}, // )
////{0x00,0x14,0x08,0x3E,0x08,0x14}, // *
//{0x0,0xc,0x1e,0x3e,0x7c,0x3e,0x1e,0xc},  //* CORAZON
//{ 0x0,0x18,0x18,0x7e,0x7e,0x18,0x18,0x0 }, // +
//{ 0x0,0x0,0xb0,0xb0,0xf0,0x70,0x0,0x0 }, // ,
//{ 0x0,0x18,0x18,0x18,0x18,0x18,0x18,0x0 }, // -
//{ 0x0,0xe0,0xe0,0xe0,0x0,0x0,0x0,0x0 }, // .
//{ 0x0,0xc0,0xe0,0x70,0x38,0x1c,0xe,0x6 }, // /
// 
//{ 0x0,0x7e,0xff,0xf3,0xdb,0xcf,0xff,0x7e }, // 0
//{ 0x0,0xc0,0xc6,0xff,0xff,0xff,0xc0,0xc0 }, // 1
//{ 0x0,0xc6,0xe7,0xe3,0xf3,0xff,0xdf,0xce }, // 2
//{ 0x0,0x62,0xe3,0xc3,0xdb,0xdb,0xff,0x6e }, // 3
//{ 0x0,0x30,0x38,0x3c,0x36,0xff,0xff,0x30 }, // 4
//{ 0x0,0x67,0xcf,0xdb,0xdb,0xdb,0xfb,0x73 }, // 5
//{ 0x0,0x7e,0xff,0xf3,0xdb,0xdb,0xfb,0x72 }, // 6
//{ 0x0,0xe3,0xf3,0x33,0x1b,0xb,0xf,0x7 },    // 7
//{ 0x0,0x76,0xff,0xdb,0xdb,0xdb,0xff,0x76 }, // 8
//{ 0x0,0x4e,0xdf,0xdb,0xdb,0xfb,0xff,0x7e }, // 9
// 
//{ 0x0,0x0,0x0,0xee,0xee,0xee,0x0,0x0 }, // :
//{ 0x0,0x0,0xb6,0xb6,0xf6,0x76,0x0,0x0 }, // ;
//{ 0x0,0x0,0x18,0x3c,0x66,0xc3,0x81,0x0 }, // <
//{ 0x0,0x6c,0x6c,0x6c,0x6c,0x6c,0x0,0x0 }, // =
//{ 0x0,0x0,0x81,0xc3,0x66,0x3c,0x18,0x0 }, // >
//{0x0,0x0,0x6,0x7,0xd3,0xdb,0x1f,0xe}, // ?
//{ 0x0,0x7e,0xc3,0xbd,0xa5,0xbd,0xa3,0x3e }, // @
// 
//{0x0,0xfe, 0xff, 0x1b, 0x1b, 0x1b, 0xff, 0xfe}, // A 
//{0x0,0xff, 0xff, 0xdb, 0xdb, 0xdb, 0xff, 0x7e}, // B
//{0x0,0x7e, 0xff, 0xc3,0xc3,0xc3,0xe7,0x66}, // C
//{0x0,0xff, 0xff, 0xc3,0xc3,0xc3,0xff, 0x7e}, // D
//{0x0,0xff, 0xff, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb}, // E 
//{0x0,0xff, 0xff, 0x1b, 0x1b, 0x1b, 0x3,0x3}, // F
//{0x0,0x7e, 0xff, 0xc3,0xdb, 0xdb, 0xfb, 0x72}, // G
//{0x0,0xff, 0xff, 0x18,0x18,0x18,0xff, 0xff}, // H
//{0x0,0xc3,0xc3,0xff, 0xff, 0xff, 0xc3,0xc3}, // I
//{0x0,0x60,0xe3,0xc3,0xff, 0x7f, 0x3,0x3}, // J
//{0x0,0xff, 0xff, 0x18,0x3c, 0x66,0xc3,0x81}, // K
//{0x0,0xff, 0xff, 0xc0,0xc0,0xc0,0xc0,0xc0}, // L
//{0x0, 0xff, 0xff, 0x6,0xc, 0x6,0xff, 0xff}, // M
//{0x0,0xff, 0xff, 0xe, 0x1c, 0x70,0xff, 0xff}, // N
//{0x0,0x7e, 0xff, 0xc3,0xc3,0xc3,0xff, 0x7e}, // O
//{0x0,0xff, 0xff, 0x1b, 0x1b, 0x1b, 0x1f, 0xe}, // P
//{0x0,0x7e, 0xff, 0xc3,0xd3,0xe3,0x7f, 0xbe}, // Q
//{0x0,0xff, 0xff, 0x3b, 0x7b, 0x5b, 0x9f, 0x8e}, // R
//{0x0,0x4e, 0xdf, 0xdb, 0xdb, 0xdb, 0xfb, 0x72}, // S
//{0x0,0x3,0x3,0xff, 0xff, 0xff, 0x3,0x3}, // T
//{0x0,0x7f, 0xff, 0xc0,0xc0,0xc0,0xff, 0x7f}, // U
//{0x0,0x3f, 0x7f, 0xe0,0xc0,0xe0,0x7f, 0x3f}, // V
//{0x0, 0x7f, 0xff, 0xe0,0x30,0xe0,0xff, 0x7f}, // W
//{0x00, 0xc3,0xe7,0x7c, 0x18,0x3c, 0xe7,0xc3}, // X
//{0x0,0xf, 0x1f, 0xfc, 0xf8,0xfc, 0x1f, 0xf}, // Y
//{0x0,0xe3,0xf3,0xd3,0xcb, 0xcf, 0xc7,0x0}, // Z
// 
//{0x00,0x00,0x7F,0x41,0x41,0x00}, // [
//{ 0x0,0x6,0xe,0x1c,0x38,0x70,0xe0,0xc0 }, // backslash
//{0x00,0x00,0x41,0x41,0x7F,0x00}, // ]
//{0x00,0x04,0x02,0x01,0x02,0x04}, // ^
//{0x00,0x40,0x40,0x40,0x40,0x40}, // _
//{0x00,0x00,0x01,0x02,0x04,0x00}, // `
// 
//{ 0x0,0x64,0xf6,0xd6,0xd6,0xde,0xfc,0x78 }, // a
//{ 0x0,0xff,0xff,0xd8,0xd8,0xd8,0xf8,0x70 }, // b
//{ 0x0,0x7c,0xfe,0xc6,0xc6,0xc6,0xee,0x6c }, // c
//{ 0x0,0x70,0xf8,0xd8,0xd8,0xd8,0xff,0xff }, // d
//{ 0x0,0x7c,0xfe,0xd6,0xd6,0xd6,0xde,0x4c }, // e
//{ 0x0,0xfe,0xff,0x1b,0x1b,0x3,0x7,0x6 }, // f
////{ 0x0,0x6c,0xde,0x92,0x92,0xd2,0xfe,0x7c }, // g 
//{ 0x0,0xcc,0xde,0x9a,0xba,0xfa,0xde,0xc }, // g
//{ 0x0,0xff,0xff,0x18,0x18,0x18,0xf8,0xf0 }, // h
//{ 0x0,0x0,0xf6,0xf6,0xf6,0x0,0x0 }, // i
//{ 0x0,0x60,0xe0,0xc0,0xc0,0xcb,0xfb,0x78 }, // j
//{ 0x0,0xff,0xff,0x30,0x30,0xcc,0xcc,0x84 }, // k
//{ 0x0,0xc0,0xc0,0xc1,0xff,0xff,0xc0,0xc0 }, // l
//{ 0x0,0xfc,0xfe,0xe,0x1c,0xe,0xfe,0xfc }, // m
//{ 0x0,0xfe,0xfe,0xc,0x6,0x6,0xfe,0xfc }, // n
//{ 0x0,0x7c,0xfe,0xc6,0xc6,0xc6,0xfe,0x7c }, // o
//{ 0x0,0xfc,0xfe,0x36,0x36,0x36,0x3e,0x1c }, // p
//{ 0x0,0x1c,0x3e,0x36,0x36,0x36,0xfe,0xfe }, // q
//{ 0x0,0xfe,0xfc,0xe,0x6,0x6,0xe,0x1c }, // r
//{ 0x0,0x4c,0xde,0xd6,0xd6,0xd6,0xf6,0x74 }, // s
//{ 0x0,0x6,0x7f,0xff,0xc6,0xc0,0xe0,0x70 }, // t
//{ 0x0,0x7e,0xfe,0xc0,0xc0,0xc0,0xfe,0x7e }, // u
//{ 0x0,0x1e,0x7e,0xe0,0xc0,0xe0,0x7e,0x1e }, // v
//{ 0x0,0x7e,0xfe,0xe0,0x70,0xe0,0xfe,0x7e }, // w
//{ 0x0,0xc6,0xee,0x7c,0x38,0x7c,0xee,0xc6 }, // x
//{ 0x0,0x4e,0xde,0xd8,0xd8,0xd8,0xfe,0x7e }, // y
//{ 0x0,0xc6,0xe6,0xf6,0xd6,0xde,0xce,0xc6 }, // z
//{0x00,0x00,0x08,0x36,0x41,0x00}, // {
//};

////Font-3
// char alphabets[][8] = {
//  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x5F, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00},
//  {0x00, 0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00, 0x00}, {0x00, 0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00, 0x00}, {0x00, 0x23, 0x13, 0x08, 0x64, 0x62, 0x00, 0x00},
//  {0x00, 0x36, 0x49, 0x55, 0x22, 0x50, 0x00, 0x00}, {0x00, 0x00, 0x05, 0x03, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x1C, 0x22, 0x41, 0x00, 0x00, 0x00, 0x00},
//  {0x00, 0x41, 0x22, 0x1C, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x08, 0x2A, 0x1C, 0x2A, 0x08, 0x00, 0x00}, {0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, 0x00, 0x00},
//  {0x00, 0xA0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00}, {0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00},
//  {0x00, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00, 0x00}, {0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00, 0x00}, {0x00, 0x00, 0x42, 0x7F, 0x40, 0x00, 0x00, 0x00},
//  {0x00, 0x62, 0x51, 0x49, 0x49, 0x46, 0x00, 0x00}, {0x00, 0x22, 0x41, 0x49, 0x49, 0x36, 0x00, 0x00}, {0x00, 0x18, 0x14, 0x12, 0x7F, 0x10, 0x00, 0x00},
//  {0x00, 0x27, 0x45, 0x45, 0x45, 0x39, 0x00, 0x00}, {0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30, 0x00, 0x00}, {0x00, 0x01, 0x71, 0x09, 0x05, 0x03, 0x00, 0x00},
//  {0x00, 0x36, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00}, {0x00, 0x06, 0x49, 0x49, 0x29, 0x1E, 0x00, 0x00}, {0x00, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00},
//  {0x00, 0x00, 0xAC, 0x6C, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00, 0x00}, {0x00, 0x14, 0x14, 0x14, 0x14, 0x14, 0x00, 0x00},
//  {0x00, 0x41, 0x22, 0x14, 0x08, 0x00, 0x00, 0x00}, {0x00, 0x02, 0x01, 0x51, 0x09, 0x06, 0x00, 0x00}, {0x00, 0x32, 0x49, 0x79, 0x41, 0x3E, 0x00, 0x00},
//  {0x00, 0x7E, 0x09, 0x09, 0x09, 0x7E, 0x00, 0x00}, {0x00, 0x7F, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00}, {0x00, 0x3E, 0x41, 0x41, 0x41, 0x22, 0x00, 0x00},
//  {0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00, 0x00}, {0x00, 0x7F, 0x49, 0x49, 0x49, 0x41, 0x00, 0x00}, {0x00, 0x7F, 0x09, 0x09, 0x09, 0x01, 0x00, 0x00},
//  {0x00, 0x3E, 0x41, 0x41, 0x51, 0x72, 0x00, 0x00}, {0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00, 0x00}, {0x00, 0x41, 0x7F, 0x41, 0x00, 0x00, 0x00, 0x00},
//  {0x00, 0x20, 0x40, 0x41, 0x3F, 0x01, 0x00, 0x00}, {0x00, 0x7F, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00}, {0x00, 0x7F, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00},
//  {0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F, 0x00, 0x00}, {0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00, 0x00}, {0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x00},
//  {0x00, 0x7F, 0x09, 0x09, 0x09, 0x06, 0x00, 0x00}, {0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00, 0x00}, {0x00, 0x7F, 0x09, 0x19, 0x29, 0x46, 0x00, 0x00},
//  {0x00, 0x26, 0x49, 0x49, 0x49, 0x32, 0x00, 0x00}, {0x00, 0x01, 0x01, 0x7F, 0x01, 0x01, 0x00, 0x00}, {0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00, 0x00},
//  {0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F, 0x00, 0x00}, {0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00, 0x00}, {0x00, 0x63, 0x14, 0x08, 0x14, 0x63, 0x00, 0x00},
//  {0x00, 0x03, 0x04, 0x78, 0x04, 0x03, 0x00, 0x00}, {0x00, 0x61, 0x51, 0x49, 0x45, 0x43, 0x00, 0x00}, {0x00, 0x7F, 0x41, 0x41, 0x00, 0x00, 0x00, 0x00},
//  {0x00, 0x02, 0x04, 0x08, 0x10, 0x20, 0x00, 0x00}, {0x00, 0x41, 0x41, 0x7F, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x04, 0x02, 0x01, 0x02, 0x04, 0x00, 0x00},
//  {0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00}, {0x00, 0x01, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x20, 0x54, 0x54, 0x54, 0x78, 0x00, 0x00},
//  {0x00, 0x7F, 0x48, 0x44, 0x44, 0x38, 0x00, 0x00}, {0x00, 0x38, 0x44, 0x44, 0x28, 0x00, 0x00, 0x00}, {0x00, 0x38, 0x44, 0x44, 0x48, 0x7F, 0x00, 0x00},
//  {0x00, 0x38, 0x54, 0x54, 0x54, 0x18, 0x00, 0x00}, {0x00, 0x08, 0x7E, 0x09, 0x02, 0x00, 0x00, 0x00}, {0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C, 0x00, 0x00},
//  {0x00, 0x7F, 0x08, 0x04, 0x04, 0x78, 0x00, 0x00}, {0x00, 0x00, 0x7D, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x80, 0x84, 0x7D, 0x00, 0x00, 0x00, 0x00},
//  {0x00, 0x7F, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00}, {0x00, 0x41, 0x7F, 0x40, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x7C, 0x04, 0x18, 0x04, 0x78, 0x00, 0x00},
//  {0x00, 0x7C, 0x08, 0x04, 0x7C, 0x00, 0x00, 0x00}, {0x00, 0x38, 0x44, 0x44, 0x38, 0x00, 0x00, 0x00}, {0x00, 0xFC, 0x24, 0x24, 0x18, 0x00, 0x00, 0x00},
//  {0x00, 0x18, 0x24, 0x24, 0xFC, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x7C, 0x08, 0x04, 0x00, 0x00, 0x00}, {0x00, 0x48, 0x54, 0x54, 0x24, 0x00, 0x00, 0x00},
//  {0x00, 0x04, 0x7F, 0x44, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x3C, 0x40, 0x40, 0x7C, 0x00, 0x00, 0x00}, {0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00, 0x00},
//  {0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00, 0x00}, {0x00, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00, 0x00}, {0x00, 0x1C, 0xA0, 0xA0, 0x7C, 0x00, 0x00, 0x00},
//  {0x00, 0x44, 0x64, 0x54, 0x4C, 0x44, 0x00, 0x00}, {0x00, 0x08, 0x36, 0x41, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00},
//  {0x00, 0x41, 0x36, 0x08, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x00, 0x00}, {0x00, 0x02, 0x05, 0x05, 0x02, 0x00, 0x00, 0x00}
//}; 


void clearBitmap()
{
  //Clear bitmap
  for (int row = 0; row < 8; row++) {
    for (int zone = 0; zone <= maxZoneIndex; zone++) {
      bitmap[row][zone] = 0;
    }
  }
}

void setup() {
  pinMode(latchPin1, OUTPUT);
  pinMode(clockPin1, OUTPUT);
  pinMode(dataPin1, OUTPUT);

  pinMode(latchPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);
  Serial.begin(9600);

  clearBitmap();

}

//FUNCTIONS
// Displays bitmap array in the matrix
void RefreshDisplay()
{
  for (int row = 0; row < 8; row++) {
    int rowbit = 1 << row;
    digitalWrite(latchPin2, LOW);//Hold latchPin LOW for transmitting data
    shiftOut(dataPin2, clockPin2, LSBFIRST, rowbit);   //Transmit data

    //Start sending column bytes
    digitalWrite(latchPin1, LOW);//Hold latchPin LOW for transmitting data

    //Shift out to each matrix
    for (int zone = maxZoneIndex; zone >= 0; zone--)
    {
      shiftOut(dataPin1, clockPin1, MSBFIRST, bitmap[row][zone]);
    }

    //flip both latches at once to eliminate flicker
    digitalWrite(latchPin1, HIGH);//Return the latch pin 1 high to signal chip
    digitalWrite(latchPin2, HIGH);//Return the latch pin 2 high to signal chip

    //Wait
    delayMicroseconds(300);
  }
}

// Converts row and colum to bitmap bit and turn it off/on
void Plot(int col, int row, bool isOn)
{
  int zone = col / 8;
  int colBitIndex = x % 8;
  byte colBit = 1 << colBitIndex;
  if (isOn)
    bitmap[row][zone] =  bitmap[y][zone] | colBit;
  else
    bitmap[row][zone] =  bitmap[y][zone] & (~colBit);
}

// Plot each character of the message one column at a time, updated the display, shift bitmap left.
void XProcess()
{

  for (charIndex = 0; charIndex < (sizeof(msg) - 1); charIndex++)
  {
    int alphabetIndex = msg[charIndex] - ' ';         // I changed '@' to ' ' to display the different alphabets
    if (alphabetIndex < 0) alphabetIndex = 0;

    //Draw one character of the message
    // Each character is 5 columns wide, loop two more times to create 2 pixel space betwen characters
    for (int col = 0; col < 8; col++)
    {
      for (int row = 0; row < 8; row++)
      {
        // Set the pixel to what the alphabet say for columns 0 thru 4, but always leave columns 5 and 6 blank.
        bool isOn = 0;
        if (col < 8) isOn = bitRead( alphabets[alphabetIndex][col], 7 - row ) == 1;
        Plot( numCols - 1, row, isOn); //Draw on the rightmost column, the shift loop below will scroll it leftward.
      }
      for (int refreshCount = 0; refreshCount < scrollspeed; refreshCount++)
        RefreshDisplay();
      //Shift the bitmap one column to left
      for (int row = 0; row < 8; row++)
      {
        for (int zone = 0; zone < numZones; zone++)
        {
          //This right shift would show as a left scroll on display because leftmost column is represented by least significant bit of the byte.
          bitmap[row][zone] = bitmap[row][zone] >> 1;
          // Shift over lowest bit from the next zone as highest bit of this zone.
          if (zone < maxZoneIndex) bitWrite(bitmap[row][zone], 7, bitRead(bitmap[row][zone + 1], 0));
        }
      }
    }
  }
}

void serialInput() {
  //check if serial is avaible an before reading a new message delete's the old message
  if (Serial.available()) {
    for (i = 0; i < 105; i++) {
      msg[i] = '\0';
    }
    //resests the index
    charIndex = 0;
  }
  //while is reading the message
  while (Serial.available()) {
    //the message can have up to 100 characters
    if (charIndex < (max_char - 1))
    {
      r_char = Serial.read();      // Reads a character
      msg[charIndex] = r_char;     // Stores the character in message array
      charIndex++;                     // Increment position
      msg[charIndex] = '\0';       // Delete the last position
    }
  }
}
void loop() {
  XProcess();
  serialInput();
}
