#include <stdio.h>
#include <stdlib.h>
#include "../transition/transition.h"
#define MAX_TAPE_LEN 256
#define TRANSITION_LINE_LEN 11
typedef struct
{
    char *tape;
    int head_position;
    char *current_state;
    char *accept_state;
    int num_transitions;
    Transition *transitions;
} TuringMachine;

typedef struct
{
    int accept;
    char *error;
    char *final_tape;
    Transition *transition;
} TuringMachineRun;

TuringMachine *CreateTuringMachine(char *);
void print_turing_machine(TuringMachine *tm);
TuringMachineRun run_turing_machine(TuringMachine *tm);