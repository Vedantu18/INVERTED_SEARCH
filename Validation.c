#include "Header.h"
int validation_of_file(valid_file **head, int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        /*File should be .txt extension or not*/
        if (strstr(argv[i], ".txt") == NULL)
            continue;

        /*File should exists or not*/
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            continue;
        }
        fclose(fp);

        /*check the file is duplicate or not*/
        if (is_duplicate_file(*head, argv[i]) == SUCCESS)
            continue;
    }
}

int is_duplicate_file(valid_file *head, char *filename)
{
    valid_file *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->file_create, filename) == 0)
        {
            return SUCCESS;
        }
        temp = temp->link;
    }
    return FAILURE;
}
