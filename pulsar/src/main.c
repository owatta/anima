#include <stdio.h>
#include <stdint.h>

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
  char* buf;
  fread(buf, 0xff00, 1, f), fclose(f);
  return 0;
}
