#include "Header.h"
int validation_of_file(valid_file **head, int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        /*File should be .txt extension or not*/
        if (strstr(argv[i], ".txt") == NULL)
            continue;

        /*File should exists or not*/
        if (is_exists_or_empty(argv[i]) == FAILURE)
            continue;

        /*check the file is duplicate or not*/
        if (is_duplicate_file(*head, argv[i]) == FAILURE)
            continue;

        create_list(head, argv[i]);
    }
    return SUCCESS;
}

int is_duplicate_file(valid_file *head, char *filename)
{
    valid_file *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->Files, filename) == 0)
        {
            return FAILURE; // File is Duplicate
        }
        temp = temp->link;
    }
    return SUCCESS; // File Not Duplicate
}

int is_exists_or_empty(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("ERROR : File not opened\n");
        return FAILURE;
    }
    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0)
    {
        fclose(fp);
        return FAILURE; // File is Empty
    }
    fclose(fp);
    return SUCCESS; // File exists and it is not empty
}

int create_list(valid_file **head, char *filename)
{
    valid_file *new = malloc(sizeof(valid_file));
    if(new == NULL)
    {
        return FAILURE;
    }
    strcpy(new->Files, filename);
    new->link = NULL;
    
    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    valid_file *temp = *head;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}