#include "Header.h"
int create_database(hash_table *HT, valid_file *head)
{
    //firstly intializing all hash table entries to null
    for(int i = 0; i < SIZE; i++)
        HT -> table[i] = NULL;

    //handling each file in that list
    valid_file *current = head;

    while(current != NULL)
    {
        printf("Processing file: %s\n", current -> Files);
        process_single_file(HT, current -> Files);
        current = current -> link;
    }
    return SUCCESS;
}
int process_single_file(hash_table *HT, char *filename)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error: Cannot open file %s\n", filename);
        return FAILURE;
    }
    char word[50];  // it is used for temporarilt stores the one word
    int char_index = 0; // position of the word
    char ch;  // it is used for the store one character from file

}