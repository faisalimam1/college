/*4. Develop a C program which demonstrates interprocess communication between a
reader process and a writer process. Use mkfifo, open, read, write and close
APIs in your program.
*/
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  int fd;
  char buf[1024];
  char* myfifo = "/tmp/myfifo";
  mkfifo(myfifo, 0666);
  printf("Run reader process to read the FIFO file \n");
  fd = open(myfifo, O_WRONLY);
  write(fd, "Hello", sizeof("Hello"));
  close(fd);
  unlink(myfifo);
  return 0;
}
