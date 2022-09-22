#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int mutex = 1, full = 0, empty = 3, x = 0;
main() {
  int n;
  void producer();
  void consumer();
  int wait(int);
  int signal(int);
  printf("\n 1. Producer \n 2. Consumer \n 3. Exit\n\n");
  while (1) {
    printf("\n Enter your choice : ");
    scanf("%d", & n);
    switch (n) {
    case 1:
      if ((mutex == 1) && (empty != 0))
        producer();
      else
        printf("\n Buffer is full\n");
      break;
    case 2:
      if ((mutex == 1) && (full != 0))
        consumer();
      else
        printf("\n Buffer is empty\n");
      break;
    case 3:
      exit(0);
      break;
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
  printf("\n Producer produces the item %d\n", x);
  mutex = signal(mutex);
}
void consumer() {
  mutex = wait(mutex);
  full = wait(full);
  empty = signal(empty);
  printf("\n Consumer consumes item %d\n", x);
  x--;
  mutex = signal(mutex);
}
