#include <stdint.h>
#include "bits.h"

struct bits8 {
  struct bit b0; 
  struct bit b1;
  struct bit b2;
  struct bit b3;
  struct bit b4;
  struct bit b5;
  struct bit b6;
  struct bit b7;
};

struct bits8 bits8_from_int(unsigned int x) {

  struct bits8 byte;

  byte.b0 = bit_from_int(x & 1); 
  byte.b1 = bit_from_int((x >> 1) & 1);
  byte.b2 = bit_from_int((x >> 2) & 1); 
  byte.b3 = bit_from_int((x >> 3) & 1); 
  byte.b4 = bit_from_int((x >> 4) & 1); 
  byte.b5 = bit_from_int((x >> 5) & 1); 
  byte.b6 = bit_from_int((x >> 6) & 1); 
  byte.b7 = bit_from_int((x >> 7) & 1);  
  
  return byte;
}

 

unsigned int bits8_to_int(struct bits8 x) {

  unsigned int C;
  
  C = 0;
  C = bit_to_int(x.b0);
  C = C | (bit_to_int(x.b1)<<1);
  C = C | (bit_to_int(x.b2)<<2);
  C = C | (bit_to_int(x.b3)<<3);
  C = C | (bit_to_int(x.b4)<<4);
  C = C | (bit_to_int(x.b5)<<5);
  C = C | (bit_to_int(x.b6)<<6);
  C = C | (bit_to_int(x.b7)<<7);
  return C;

}

void bits8_print(struct bits8 v) {
  printf("bit.b0: %u\n", bit_to_int(v.b0));
  printf("bit.b1: %u\n", bit_to_int(v.b1));
  printf("bit.b2: %u\n", bit_to_int(v.b2));
  printf("bit.b3: %u\n", bit_to_int(v.b3));
  printf("bit.b4: %u\n", bit_to_int(v.b4));
  printf("bit.b5: %u\n", bit_to_int(v.b5));
  printf("bit.b6: %u\n", bit_to_int(v.b6));
  printf("bit.b7: %u\n", bit_to_int(v.b7));
}
struct bits8 bits8_add(struct bits8 x, struct bits8 y) {

  struct bits8 c;
  struct bits8 result;
  

  c.b0.v = false;
  
  result.b0 = bit_xor(x.b0,y.b0);
  
  c.b1 = bit_and(x.b0,y.b0);
  result.b1 = bit_xor(c.b1,bit_xor(x.b1,y.b1));

  c.b2 = bit_or(bit_and(x.b1,y.b1),bit_and(bit_or(x.b1,y.b1),c.b1));
  result.b2 = bit_xor(c.b2,bit_xor(x.b2,y.b2));

  c.b3 = bit_or(bit_and(x.b2,y.b2),bit_and(bit_or(x.b2,y.b2),c.b2));
  result.b3 = bit_xor(c.b3,bit_xor(x.b3,y.b3));

  c.b4 = bit_or(bit_and(x.b3,y.b3),bit_and(bit_or(x.b3,y.b3),c.b3));
  result.b4 = bit_xor(c.b4,bit_xor(x.b4,y.b4));

  c.b5 = bit_or(bit_and(x.b4,y.b4),bit_and(bit_or(x.b4,y.b4),c.b4));
  result.b5 = bit_xor(c.b5,bit_xor(x.b5,y.b5));

  c.b6 = bit_or(bit_and(x.b5,y.b5),bit_and(bit_or(x.b5,y.b5),c.b5));
  result.b6 = bit_xor(c.b6,bit_xor(x.b6,y.b6));

  c.b7 = bit_or(bit_and(x.b6,y.b6),bit_and(bit_or(x.b6,y.b6),c.b6));
  result.b7 = bit_xor(c.b7,bit_xor(x.b7,y.b7));

  return result;

}

struct bits8 bits8_emptyBits8(void) {
  struct bits8 helper;

  helper.b0.v = false;
  helper.b1.v = false;
  helper.b2.v = false;
  helper.b3.v = false;
  helper.b4.v = false;
  helper.b5.v = false;
  helper.b6.v = false;
  helper.b7.v = false;

  return helper;
}



struct bits8 bits8_increment(struct bits8 x) {
  struct bits8 helper;

  helper = bits8_emptyBits8();
  helper.b0.v = true;

  return bits8_add(x,helper);

}

struct bits8 bits8_negate(struct bits8 x) {

  struct bits8 result;
  

  result.b0 = bit_not(x.b0);
  result.b1 = bit_not(x.b1);
  result.b2 = bit_not(x.b2);
  result.b3 = bit_not(x.b3);
  result.b4 = bit_not(x.b4);
  result.b5 = bit_not(x.b5);
  result.b6 = bit_not(x.b6);
  result.b7 = bit_not(x.b7);

  return bits8_increment(result);
}

struct bits8 bits8_and(struct bits8 x, struct bit y) {
  struct bits8 result;
  struct bits8 y_byte;

  y_byte = bits8_negate(bits8_from_int(bit_to_int(y)));

  result.b0 = bit_and(y_byte.b0, x.b0);
  result.b1 = bit_and(y_byte.b1, x.b1);
  result.b2 = bit_and(y_byte.b2, x.b2);
  result.b3 = bit_and(y_byte.b3, x.b3);
  result.b4 = bit_and(y_byte.b4, x.b4);
  result.b5 = bit_and(y_byte.b5, x.b5);
  result.b6 = bit_and(y_byte.b6, x.b6);
  result.b7 = bit_and(y_byte.b7, x.b7);

  return result;

}

struct bits8 bits8_mul(struct bits8 x, struct bits8 y) {
    
  struct bits8 sum;
  unsigned int helper;
  sum = bits8_emptyBits8();

  // i = 0

    helper = bits8_to_int(bits8_and(x,y.b0));
    sum = bits8_add(bits8_from_int(helper), sum);

    // i = 1, shift x by 1 position if y.b1 is 1
    helper = (bits8_to_int(bits8_and(x,y.b1)) << 1);
    sum = bits8_add(bits8_from_int(helper), sum);

    // i = 2, shift x by 2 positions if y.b2 is 1
    helper = (bits8_to_int(bits8_and(x,y.b2)) << 2);
    sum = bits8_add(bits8_from_int(helper), sum);

    // i = 3, shift x by 3 positions if y.b3 is 1
    helper = (bits8_to_int(bits8_and(x,y.b3)) << 3);
    sum = bits8_add(bits8_from_int(helper), sum);

    // i = 4, shift x by 4 positions if y.b4 is 1
    helper = (bits8_to_int(bits8_and(x,y.b4)) << 4);
    sum = bits8_add(bits8_from_int(helper), sum);

    // i = 5, shift x by 5 positions if y.b5 is 1
    helper = (bits8_to_int(bits8_and(x,y.b5)) << 5);
    sum = bits8_add(bits8_from_int(helper), sum);

    // i = 6, shift x by 6 positions if y.b6 is 1
    helper = (bits8_to_int(bits8_and(x,y.b6)) << 6);
    sum = bits8_add(bits8_from_int(helper), sum);

    // i = 7, shift x by 7 positions if y.b7 is 1
    helper = (bits8_to_int(bits8_and(x,y.b7)) << 7);
    sum = bits8_add(bits8_from_int(helper), sum);
  return sum;
}
