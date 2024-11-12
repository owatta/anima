#include <stdio.h>
#include <stdint.h>

typedef struct Stack {
  uint8_t mem[100];
  uint8_t fp;
} Stack;

void push(uint8_t val, Stack* stk) {
  stk->mem[stk->fp] = val;
  stk->fp++;
}

uint8_t pop(Stack* stk) {
  stk->fp--;
  return stk->mem[stk->fp];
}

void add(Stack* stk) {
  uint8_t a, b;
  a = pop(stk);
  b = pop(stk);
  push((a + b), stk);
}

int main() {
  Stack stk;
  stk.fp = 0;
  push(1, &stk);
  push(1, &stk);
  add(&stk);
  uint8_t result = pop(&stk);
  printf("%d\n", result);

  return 0;
}
