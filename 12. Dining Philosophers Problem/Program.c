#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define LEFT (i + 4) % 5
#define RIGHT (i + 1) % 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
int state[5];
void put_forks(int);
void test(int);
void take_forks(int);
void philosopher(int i) {
    if (state[i] == 0) {
        take_forks(i);
        if (state[i] == EATING)
            printf("\n Eating in progress..");
        put_forks(i);
    }
}
void take_forks(int i) {
    state[i] = HUNGRY;
    test(i);
}
void put_forks(int i) {
    state[i] = THINKING;
    printf("\n Philosopher %d has completed its work", i);
    test(LEFT);
    test(RIGHT);
}
void test(int i) {
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        printf("\n Philosopher %d can eat", i);
        state[i] = EATING;
    }
}
int main() {
    int i;
    for (i = 1; i <= 5; i++)
        state[i] = 0;
    printf("\n\n\t\t\t DINING PHILOSOPHERS PROBLEM");
    printf("\n\t\t\t~~~~~~~~~~~~");
    printf("\n ALL THE PHILOSOPHERS ARE THINKING !!....\n", i);
    for (i = 1; i <= 5; i++) {
        printf("\n\n The philosophers %d falls hungry\n", i);
        philosopher(i);
    }
}
