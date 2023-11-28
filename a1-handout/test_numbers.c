#include <stdio.h>
#include <stdlib.h>
#include "numbers.h"

void print_bits(struct bits8 bit) {
  printf("bit.b0: %u\n", bit_to_int(bit.b0));
  printf("bit.b1: %u\n", bit_to_int(bit.b1));
  printf("bit.b2: %u\n", bit_to_int(bit.b2));
  printf("bit.b3: %u\n", bit_to_int(bit.b3));
  printf("bit.b4: %u\n", bit_to_int(bit.b4));
  printf("bit.b5: %u\n", bit_to_int(bit.b5));
  printf("bit.b6: %u\n", bit_to_int(bit.b6));
  printf("bit.b7: %u\n", bit_to_int(bit.b7));
}

void test_bits8_from_int(unsigned int x, struct bits8 expectedBit) {
  struct bits8 bit = bits8_from_int(x);

  
  if (bit_to_int(bit.b0) != bit_to_int(expectedBit.b0) ||
      bit_to_int(bit.b1) != bit_to_int(expectedBit.b1) ||
      bit_to_int(bit.b2) != bit_to_int(expectedBit.b2) ||
      bit_to_int(bit.b3) != bit_to_int(expectedBit.b3) ||
      bit_to_int(bit.b4) != bit_to_int(expectedBit.b4) ||
      bit_to_int(bit.b5) != bit_to_int(expectedBit.b5) ||
      bit_to_int(bit.b6) != bit_to_int(expectedBit.b6) ||
      bit_to_int(bit.b7) != bit_to_int(expectedBit.b7)) {
    printf("Input:     %u\n", x);
    printf("Got:       %u%u%u%u%u%u%u%u\n", bit_to_int(bit.b7), bit_to_int(bit.b6), bit_to_int(bit.b5), bit_to_int(bit.b4), bit_to_int(bit.b3), bit_to_int(bit.b2), bit_to_int(bit.b1), bit_to_int(bit.b0));
    printf("Expected:  %u%u%u%u%u%u%u%u\n", bit_to_int(expectedBit.b7), bit_to_int(expectedBit.b6), bit_to_int(expectedBit.b5), bit_to_int(expectedBit.b4), bit_to_int(expectedBit.b3), bit_to_int(expectedBit.b2), bit_to_int(expectedBit.b1), bit_to_int(expectedBit.b0));

    exit(1);
  }
}

void test_bits8_to_int(struct bits8 bit, unsigned int expectedInt) {
  unsigned int result = bits8_to_int(bit);

  if (result != expectedInt) {
    printf("Input:     %u%u%u%u%u%u%u%u\n", bit_to_int(bit.b7), bit_to_int(bit.b6), bit_to_int(bit.b5), bit_to_int(bit.b4), bit_to_int(bit.b3), bit_to_int(bit.b2), bit_to_int(bit.b1), bit_to_int(bit.b0));
    printf("Got:       %u\n", result);
    printf("Expected:  %u\n", expectedInt);

    exit(1);
  }
}

void test_bits8_to_int_255(void) {
  struct bits8 bit;

  bit.b0 = bit_from_int(1);
  bit.b1 = bit_from_int(1);
  bit.b2 = bit_from_int(1);
  bit.b3 = bit_from_int(1);
  bit.b4 = bit_from_int(1);
  bit.b5 = bit_from_int(1);
  bit.b6 = bit_from_int(1);
  bit.b7 = bit_from_int(1);

  test_bits8_to_int(bit, 255);
}

void test_bits8_to_int_0(void) {
  struct bits8 bit;

  bit.b0 = bit_from_int(0);
  bit.b1 = bit_from_int(0);
  bit.b2 = bit_from_int(0);
  bit.b3 = bit_from_int(0);
  bit.b4 = bit_from_int(0);
  bit.b5 = bit_from_int(0);
  bit.b6 = bit_from_int(0);
  bit.b7 = bit_from_int(0);

  test_bits8_to_int(bit, 0);
}

void test_bits8_to_int_170(void) {
  struct bits8 bit;

  bit.b0 = bit_from_int(0);
  bit.b1 = bit_from_int(1);
  bit.b2 = bit_from_int(0);
  bit.b3 = bit_from_int(1);
  bit.b4 = bit_from_int(0);
  bit.b5 = bit_from_int(1);
  bit.b6 = bit_from_int(0);
  bit.b7 = bit_from_int(1);

  test_bits8_to_int(bit, 170);
}

void test_bits8_from_int_255(void) {
  struct bits8 expectedBit;

  expectedBit.b0 = bit_from_int(1);
  expectedBit.b1 = bit_from_int(1);
  expectedBit.b2 = bit_from_int(1);
  expectedBit.b3 = bit_from_int(1);
  expectedBit.b4 = bit_from_int(1);
  expectedBit.b5 = bit_from_int(1);
  expectedBit.b6 = bit_from_int(1);
  expectedBit.b7 = bit_from_int(1);

  test_bits8_from_int(255, expectedBit);
}

void test_bits8_from_int_0(void) {
  struct bits8 expectedBit;

  expectedBit.b0 = bit_from_int(0);
  expectedBit.b1 = bit_from_int(0);
  expectedBit.b2 = bit_from_int(0);
  expectedBit.b3 = bit_from_int(0);
  expectedBit.b4 = bit_from_int(0);
  expectedBit.b5 = bit_from_int(0);
  expectedBit.b6 = bit_from_int(0);
  expectedBit.b7 = bit_from_int(0);

  test_bits8_from_int(0, expectedBit);
}

void test_bits8_from_int_170(void) {
  struct bits8 expectedBit;

  expectedBit.b0 = bit_from_int(0);
  expectedBit.b1 = bit_from_int(1);
  expectedBit.b2 = bit_from_int(0);
  expectedBit.b3 = bit_from_int(1);
  expectedBit.b4 = bit_from_int(0);
  expectedBit.b5 = bit_from_int(1);
  expectedBit.b6 = bit_from_int(0);
  expectedBit.b7 = bit_from_int(1);

  test_bits8_from_int(170, expectedBit);
}



int main(void) {
  // Call the test functions
  test_bits8_from_int_255();
  test_bits8_from_int_0();
  test_bits8_from_int_170();
  test_bits8_to_int_170();
  test_bits8_to_int_255();
  test_bits8_to_int_0();



  return 0;
}



