#include "Header.h"
int main(int argc, char *argv[])
{
    valid_file *head = NULL;
    if(validation_of_file(&head, argc, argv))
    {
        return SUCCESS;
    }
}