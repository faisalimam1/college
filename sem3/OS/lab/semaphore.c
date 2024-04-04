/*3. Develop a C program to simulate producer-consumer problem using semaphores.
 */
#include <stdio.h>
#include <stdlib.h>
int mutex = 1, empty = 3, full = 0, x = 0;
int main() {
  int n;
  void producer();
  void consumer();
  int wait(int);
  int signal(int);
  printf("\n 1.PRODUCER \n 2.CONSUMER \n 3.EXIT\n");
  while (1) {
    printf("\n Enter your choice : ");
    scanf("%d", &n);
    switch (n) {
      case 1:
        if ((mutex == 1) && (empty != 0))
          producer();
        else
          printf("BUFFER IS FULL");
        break;
      case 2:
        if ((mutex == 1) && (full != 0))
          consumer();
        else
          printf("BUFFER IS EMPTY");
        break;
      case 3:
        exit(0);
      default:
        printf("INVALID INPUT");
    }
  }
}
int wait(int s) {
  return (--s);
}
int signal(int s) {
  return (++s);
}
void producer() {
  mutex = wait(mutex);
  full = signal(full);
  empty = wait(empty);
  x++;
  printf("\n Producer produces the item %d ", x);
  mutex = signal(mutex);
}
void consumer() {
  mutex = wait(mutex);
  full = wait(full);
  empty = signal(empty);
  printf("\n Consumer consumes item %d ", x);
  x--;
  mutex = signal(mutex);
}
