#include "file.h"

char *get_file_str(char *path)
{
    FILE *file = fopen(path, "r");

    if (file == NULL)
    {
        printf("Failed to open file.\n\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = malloc(sizeof(char) * (file_size + 1));

    if (content == NULL)
    {
        printf("Failed to allocate memory.\n\n");
        exit(1);
    }

    char buffer[MAX_LINE_LEN];

    while (fgets(buffer, sizeof(buffer), file) != NULL)
        strcat(content, buffer);

    content[file_size] = '\0';

    return content;
}