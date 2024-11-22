#include <stdio.h>
#include <stdint.h>

typedef struct {
  uint8_t mem[100];
  uint8_t fp;
} Stack;

typedef struct {
  uint8_t mem[1000];
  Stack *stk;
  uint32_t pc;
} Vm;

typedef enum {
  OP_PUSH,
  OP_POP,
  OP_ADD,
  OP_END,
} OP_CODE;

void push(uint8_t val, Stack *stk) {
  stk->mem[stk->fp] = val;
  stk->fp++;
}

uint8_t pop(Stack *stk) {
  stk->fp--;
  return stk->mem[stk->fp];
}

void add(Stack *stk) {
  uint8_t a, b;
  a = pop(stk);
  b = pop(stk);
  push((a + b), stk);
}

void run(Vm *vm) {
  uint8_t c;
  while ((c = vm->mem[vm->pc]) != OP_END) {
    switch(c) {
    case OP_PUSH:
      push(vm->mem[vm->pc + 1], vm->stk);
      vm->pc++;
      break;
    case OP_POP:
      pop(vm->stk);
      break;
    case OP_ADD:
      push(pop(vm->stk) + pop(vm->stk), vm->stk);
      break;
    default: break;
    }
    vm->pc++;
  }
}

int main() {
  Stack stk;

  Vm vm = {
    .mem = { OP_PUSH, 1, OP_PUSH, 1, OP_ADD, OP_END },
    .stk = &stk,
    .pc = 0
  };

  run(&vm);
  uint8_t result = pop(vm.stk);
  printf("%d\n", result);

  return 0;
}
