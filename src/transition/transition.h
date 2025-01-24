#include <stdio.h>
#include <string.h>
#include <stddef.h>

typedef struct
{
    char *current_state;
    char read_symbol;
    char *next_state;
    char write_symbol;
    char movement;
} Transition;

void print_transitions(Transition *, size_t);
Transition *get_transition(char *, char, Transition *, size_t);