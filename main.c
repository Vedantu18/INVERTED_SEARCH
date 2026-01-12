#include "Header.h"
int main(int argc, char *argv[])
{
    valid_file *head = NULL;

    if (validation_of_file(&head, argc, argv) == FAILURE)
    {
        return 1;
    }

    print_list(head);
    return 0;
}


void print_list(valid_file *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	    while (head)		
	    {
		    printf("%s -> ", head -> Files);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}