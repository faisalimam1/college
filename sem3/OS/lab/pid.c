#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  pid_t pid;
  pid = fork();
  if (pid < 0) {
    printf("Error in fork");
    exit(1);
  } else if (pid == 0) {
    printf("Child process ");
    execlp("ls", "ls", "-l", NULL);
  } else {
    wait(NULL);
    printf("Parent process");
    exit(0);
  }
}
