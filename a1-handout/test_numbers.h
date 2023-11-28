#include <stdio.h>
#include <stdlib.h>
#include "numbers.h"

void test_bits8_from_int(unsigned int x, struct bits8 expectedBit) {
  struct bits8 bit = bits8_from_int(x);

  // Check if the converted bits match the expected bits
  if (bit.b0.v != expectedBit.b0.v ||
      bit.b1.v != expectedBit.b1.v ||
      bit.b2.v != expectedBit.b2.v ||
      bit.b3.v != expectedBit.b3.v ||
      bit.b4.v != expectedBit.b4.v ||
      bit.b5.v != expectedBit.b5.v ||
      bit.b6.v != expectedBit.b6.v ||
      bit.b7.v != expectedBit.b7.v) {
    printf("Input:     %u\n", x);
    printf("Got:       %u%u%u%u%u%u%u%u\n", bit.b7.v, bit.b6.v, bit.b5.v, bit.b4.v, bit.b3.v, bit.b2.v, bit.b1.v, bit.b0.v);
    printf("Expected:  %u%u%u%u%u%u%u%u\n", expectedBit.b7.v, expectedBit.b6.v, expectedBit.b5.v, expectedBit.b4.v, expectedBit.b3.v, expectedBit.b2.v, expectedBit.b1.v, expectedBit.b0.v);

    exit(1);
  }
}



void test_bits8_to_int(struct bits8 bit, unsigned int expectedInt) {
  unsigned int result = bits8_to_int(bit);

  // Check if the converted integer matches the expected integer
  if (result != expectedInt) {
    printf("Input:     %u%u%u%u%u%u%u%u\n", bit.b7.v, bit.b6.v, bit.b5.v, bit.b4.v, bit.b3.v, bit.b2.v, bit.b1.v, bit.b0.v);
    printf("Got:       %u\n", result);
    printf("Expected:  %u\n", expectedInt);

    exit(1);
  }
}

void test_bits8_add(struct bits8 x, struct bits8 y, struct bits8 expectedSum) {
  struct bits8 sum = bits8_add(x, y);

  // Check if the sum matches the expected sum
  if (sum.b0.v != expectedSum.b0.v ||
      sum.b1.v != expectedSum.b1.v ||
      sum.b2.v != expectedSum.b2.v ||
      sum.b3.v != expectedSum.b3.v ||
      sum.b4.v != expectedSum.b4.v ||
      sum.b5.v != expectedSum.b5.v ||
      sum.b6.v != expectedSum.b6.v ||
      sum.b7.v != expectedSum.b7.v) {
    printf("Input:     %u%u%u%u%u%u%u%u + %u%u%u%u%u%u%u%u\n", x.b7.v, x.b6.v, x.b5.v, x.b4.v, x.b3.v, x.b2.v, x.b1.v, x.b0.v, y.b7.v, y.b6.v, y.b5.v, y.b4.v, y.b3.v, y.b2.v, y.b1.v, y.b0.v);
    printf("Got:       %u%u%u%u%u%u%u%u\n", sum.b7.v, sum.b6.v, sum.b5.v, sum.b4.v, sum.b3.v, sum.b2.v, sum.b1.v, sum.b0.v);
    printf("Expected:  %u%u%u%u%u%u%u%u\n", expectedSum.b7.v, expectedSum.b6.v, expectedSum.b5.v, expectedSum.b4.v, expectedSum.b3.v, expectedSum.b2.v, expectedSum.b1.v, expectedSum.b0.v);

    exit(1);
  }
}

void test_bits8_increment(struct bits8 x, struct bits8 expectedIncrement) {
  struct bits8 increment = bits8_increment(x);

  // Check if the incremented value matches the expected increment
  if (increment.b0.v != expectedIncrement.b0.v ||
      increment.b1.v != expectedIncrement.b1.v ||
      increment.b2.v != expectedIncrement.b2.v ||
      increment.b3.v != expectedIncrement.b3.v ||
      increment.b4.v != expectedIncrement.b4.v ||
      increment.b5.v != expectedIncrement.b5.v ||
      increment.b6.v != expectedIncrement.b6.v ||
      increment.b7.v != expectedIncrement.b7.v) {
    printf("Input:     %u%u%u%u%u%u%u%u\n", x.b7.v, x.b6.v, x.b5.v, x.b4.v, x.b3.v, x.b2.v, x.b1.v, x.b0.v);
    printf("Got:       %u%u%u%u%u%u%u%u\n", increment.b7.v, increment.b6.v, increment.b5.v, increment.b4.v, increment.b3.v, increment.b2.v, increment.b1.v, increment.b0.v);
    printf("Expected:  %u%u%u%u%u%u%u%u\n", expectedIncrement.b7.v, expectedIncrement.b6.v, expectedIncrement.b5.v, expectedIncrement.b4.v, expectedIncrement.b3.v, expectedIncrement.b2.v, expectedIncrement.b1.v, expectedIncrement.b0.v);

    exit(1);
  }
}

void test_bits8_negate(struct bits8 x, struct bits8 expectedNegate) {
  struct bits8 negate = bits8_negate(x);

  // Check if the negated value matches the expected negate
  if (negate.b0.v != expectedNegate.b0.v ||
      negate.b1.v != expectedNegate.b1.v ||
      negate.b2.v != expectedNegate.b2.v ||
      negate.b3.v != expectedNegate.b3.v ||
      negate.b4.v != expectedNegate.b4.v ||
      negate.b5.v != expectedNegate.b5.v ||
      negate.b6.v != expectedNegate.b6.v ||
      negate.b7.v != expectedNegate.b7.v) {
    printf("Input:     %u%u%u%u%u%u%u%u\n", x.b7.v, x.b6.v, x.b5.v, x.b4.v, x.b3.v, x.b2.v, x.b1.v, x.b0.v);
    printf("Got:       %u%u%u%u%u%u%u%u\n", negate.b7.v, negate.b6.v, negate.b5.v, negate.b4.v, negate.b3.v, negate.b2.v, negate.b1.v, negate.b0.v);
    printf("Expected:  %u%u%u%u%u%u%u%u\n", expectedNegate.b7.v, expectedNegate.b6.v, expectedNegate.b5.v, expectedNegate.b4.v, expectedNegate.b3.v, expectedNegate.b2.v, expectedNegate.b1.v, expectedNegate.b0.v);

    exit(1);
  }
}

void test_bits8_mul(struct bits8 x, struct bits8 y, struct bits8 expectedProduct) {
  struct bits8 product = bits8_mul(x, y);

  // Check if the product matches the expected product
  if (product.b0.v != expectedProduct.b0.v ||
      product.b1.v != expectedProduct.b1.v ||
      product.b2.v != expectedProduct.b2.v ||
      product.b3.v != expectedProduct.b3.v ||
      product.b4.v != expectedProduct.b4.v ||
      product.b5.v != expectedProduct.b5.v ||
      product.b6.v != expectedProduct.b6.v ||
      product.b7.v != expectedProduct.b7.v) {
    printf("Input:     %u%u%u%u%u%u%u%u * %u%u%u%u%u%u%u%u\n", x.b7.v, x.b6.v, x.b5.v, x.b4.v, x.b3.v, x.b2.v, x.b1.v, x.b0.v, y.b7.v, y.b6.v, y.b5.v, y.b4.v, y.b3.v, y.b2.v, y.b1.v, y.b0.v);
    printf("Got:       %u%u%u%u%u%u%u%u\n", product.b7.v, product.b6.v, product.b5.v, product.b4.v, product.b3.v, product.b2.v, product.b1.v, product.b0.v);
    printf("Expected:  %u%u%u%u%u%u%u%u\n", expectedProduct.b7.v, expectedProduct.b6.v, expectedProduct.b5.v, expectedProduct.b4.v, expectedProduct.b3.v, expectedProduct.b2.v, expectedProduct.b1.v, expectedProduct.b0.v);

    exit(1);
  }
}

#include <stdio.h>
#include <stdlib.h>
#include "numbers.h"

// Declare bits8 objects

// 11111111 => 255
struct bits8 bits8_obj1 = { .b0 = { .v = true }, .b1 = { .v = true }, .b2 = { .v = true }, .b3 = { .v = true }, .b4 = { .v = true }, .b5 = { .v = true }, .b6 = { .v = true }, .b7 = { .v = true } };

// 00000000 => 0
struct bits8 bits8_obj2 = { .b0 = { .v = false }, .b1 = { .v = false }, .b2 = { .v = false }, .b3 = { .v = false }, .b4 = { .v = false }, .b5 = { .v = false }, .b6 = { .v = false }, .b7 = { .v = false } };

// 10101010 => 170
struct bits8 bits8_obj3 = { .b0 = { .v = false }, .b1 = { .v = true }, .b2 = { .v = false }, .b3 = { .v = true }, .b4 = { .v = false }, .b5 = { .v = true }, .b6 = { .v = false }, .b7 = { .v = true } };

int main(void) {
  // Call the test functions
  test_bits8_from_int(255, bits8_obj1);
  test_bits8_from_int(0, bits8_obj2);
  test_bits8_from_int(170, bits8_obj3);

  test_bits8_to_int(bits8_obj3, 170);
  test_bits8_to_int(bits8_obj1, 255);
  test_bits8_to_int(bits8_obj2, 0);


  return 0;
}