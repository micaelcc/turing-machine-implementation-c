#include "./file/file.h"
#include "./turing-machine/turing-machine.h"

void main()
{
    char *fileStr = get_file_str("source.mt");

    TuringMachine *tm = CreateTuringMachine(fileStr);

    TuringMachineRun tmr = run_turing_machine(tm);

    print_turing_machine(tm);

    printf("Machine Result: [\n");

    if (tmr.accept)
    {
        printf("\033[0;32m\tStatus: Accepted.\033[0m\n");
        if (tmr.transition != NULL)
        {
            printf("\tReading: %c\n", tmr.transition->read_symbol);
            printf("\tQcurrent: %s\n", tmr.transition->current_state);
            printf("\tMove: %c\n", tmr.transition->movement);
            printf("\tWriting: %c\n", tmr.transition->write_symbol);
            printf("\tQnext: %s\n", tmr.transition->next_state);
        }
        printf("\tTape: %s\n", tmr.final_tape);
    }
    else if (tmr.error)
    {
        printf("\033[0;31m\tStatus: Not accepted.\033[0m\n");
        if (tmr.transition != NULL)
        {
            printf("\tReading: %c\n", tmr.transition->read_symbol);
            printf("\tQcurrent: %s\n", tmr.transition->current_state);
            printf("\tMove: %c\n", tmr.transition->movement);
            printf("\tWriting: %c\n", tmr.transition->write_symbol);
            printf("\tQnext: %s\n", tmr.transition->next_state);
        }
        printf("\tError: %s\n", tmr.error);
    }

    printf("]\n\n");

    free(tm);
    free(fileStr);
}