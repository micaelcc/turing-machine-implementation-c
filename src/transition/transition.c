#include "./transition.h"

void print_transitions(Transition *list, size_t size)
{
    printf("\tTransitions [\n");

    for (size_t i = 0; i < size; i++)
    {
        printf("\t\t [%s,%c,%s,%c,%c]\n", list[i].current_state, list[i].read_symbol, list[i].next_state, list[i].write_symbol, list[i].movement);
    }

    printf("\t]\n\n");
}

Transition *get_transition(char *current_state, char symbol, Transition *list, size_t num_transitions)
{
    for (size_t i = 0; i < num_transitions; i++)
        if (strcmp(list[i].current_state, current_state) == 0 && symbol == list[i].read_symbol)
            return (Transition *)&list[i];

    return NULL;
}