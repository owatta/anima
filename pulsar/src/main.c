/* general */
#include <stdio.h>

/* reading the file */
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

  /* parsing the arguments */
  if (argc < 2) {
    printf("ERROR: No files provided.");
    return -1;
  }

  const char *filepath = argv[1];

  /* reading the file */
  int err = 0;
  int fd = 0;
  void *ptr = NULL;
  struct stat st;

  if ((fd = open(filepath, O_RDONLY))
      && (err = fstat(fd, &st)) == 0
      && (ptr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) != MAP_FAILED) {
    const char *lines = ptr;
    printf("%s\n", lines);
    munmap(ptr, st.st_size);
    close(fd);
  }
}
