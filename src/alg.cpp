// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n != 0) {
    return 0;
  } 
  else {
    return value * pown(value, n-1);
  }
}

uint64_t fact(uint16_t n) {
  if ((n == 0) || (n == 1)) {
    return 1;
  }
  return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double result = 1;
  for (int i = 0; i <= count; ++i) {
    result += calcItem(x, i);
  }
  return result;
}

double sinn(double x, uint16_t count) {
  double result = 1;
  for (int i = 0; i < count; i++) {
    result += pown(-1, i + 1) * calcItem(x, 2 * i - 1);
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 1;
  for (int i = 0; i <= count; i++) {
    result += pown(-1, i + 1) * calcItem(x, 2 * i - 2);
  }
  return result;
}
