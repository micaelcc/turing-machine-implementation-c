#include "turing-machine.h"

TuringMachine *CreateTuringMachine(char *str_file)
{
    size_t index = 0, tape_index = 0, num_transitions = 1, transitions_index = 0;
    char *current_state = malloc(sizeof(char) * 2);
    char *accept_state = malloc(sizeof(char) * 2);
    char *tape = malloc(sizeof(char) * MAX_TAPE_LEN);
    Transition *transitions = NULL;

    for (int write = 0; str_file[index] != '\n'; index++)
    {
        if (!write && str_file[index] == ' ')
        {
            write = 1;
            continue;
        }

        if (write)
        {
            tape[tape_index] = str_file[index];
            tape_index++;
        }
    }

    tape[tape_index] = '\0';
    index++;
    for (int write = 0; str_file[index] != '\n'; index++)
    {
        if (!write && str_file[index] == ' ')
        {
            write = 1;
            continue;
        }

        if (write)
        {
            current_state[0] = str_file[index];
            current_state[1] = str_file[index + 1];
            current_state[2] = '\0';
            break;
        }
    }

    index += 3;
    for (int write = 0; str_file[index] != '\n'; index++)
    {
        if (!write && str_file[index] == ' ')
        {
            write = 1;
            continue;
        }

        if (write)
        {
            accept_state[0] = str_file[index];
            accept_state[1] = str_file[index + 1];
            accept_state[2] = '\0';
            break;
        }
    }

    index += 3;
    for (int i = index; str_file[i] != '\0'; i++)
        if (str_file[i] == '\n')
            num_transitions++;

    transitions = malloc(sizeof(Transition) * num_transitions);

    while (str_file[index] != '\0')
    {
        char *current_state = malloc(sizeof(char) * 2);
        char *next_state = malloc(sizeof(char) * 2);

        current_state[0] = str_file[index];
        current_state[1] = str_file[index + 1];
        current_state[2] = '\0';

        next_state[0] = str_file[index + 5];
        next_state[1] = str_file[index + 6];
        next_state[2] = '\0';

        transitions[transitions_index].current_state = strdup(current_state);
        transitions[transitions_index].read_symbol = str_file[index + 3];
        transitions[transitions_index].next_state = strdup(next_state);
        transitions[transitions_index].write_symbol = str_file[index + 8];
        transitions[transitions_index].movement = str_file[index + 10];

        index += TRANSITION_LINE_LEN + 1;
        transitions_index++;
    }

    TuringMachine *tm = malloc(sizeof(TuringMachine));

    tm->accept_state = strdup(accept_state);
    tm->current_state = strdup(current_state);
    tm->head_position = 0;
    tm->num_transitions = num_transitions;
    tm->tape = strdup(tape);
    tm->transitions = transitions;

    return tm;
}

TuringMachineRun run_turing_machine(TuringMachine *tm)
{
    Transition *oldTransition = NULL;

    while (strcmp(tm->current_state, tm->accept_state) != 0)
    {
        char symbol = tm->tape[tm->head_position];

        Transition *transition = get_transition(tm->current_state, symbol, tm->transitions, tm->num_transitions);

        if (transition == NULL)
        {
            return (TuringMachineRun){0, "No valid transition found", NULL, oldTransition};
        }

        oldTransition = transition;

        tm->tape[tm->head_position] = transition->read_symbol;
        tm->current_state = strdup(transition->next_state);

        if (transition->movement == '>')
        {
            tm->head_position++;

            if (tm->head_position == strlen(tm->tape))
                strcat(tm->tape, "_");
        }
        else if (transition->movement == '<')
        {
            if (tm->head_position > 0)
                tm->head_position--;
            else
                return (TuringMachineRun){0, "Head moved out of tape bounds", NULL, oldTransition};
        }
    }

    return (TuringMachineRun){1, NULL, tm->tape, oldTransition};
}

void print_turing_machine(TuringMachine *tm)
{
    printf("TuringMachine: [\n");

    printf("\tTape: %s\n", tm->tape);
    printf("\tCurrent state: %s\n", tm->current_state);
    printf("\tAccept state: %s\n", tm->accept_state);
    print_transitions(tm->transitions, tm->num_transitions);

    printf("]\n\n");
}