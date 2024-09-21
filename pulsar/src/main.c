#include <stdio.h>
#include <stdint.h>

typedef struct Vm {
  uint8_t memory[0x10000];
  uint8_t stack[0x100];
  uint32_t pc;
} Vm;

Vm vm;

int wasm_eval(uint32_t pc) {
  for(;;) {
    switch (vm.memory[pc++]) {
    case 0x00: {printf("Working!\n"); return 1;};
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stdout, "Usage: %s file.wasm\n", argv[0]);
    return 0;
  }

  FILE* f = fopen(argv[1], "rb");
  if(!f) {
    fprintf(stderr, "ERROR: %s\n", argv[1]);
    return 0;
  }

  vm.pc = 0;
  fread(vm.memory, 0xff00, 1, f), fclose(f);

  wasm_eval(vm.pc);
  return 0;
}
