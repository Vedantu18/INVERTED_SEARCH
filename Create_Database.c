#include "Header.h"
int create_database(hash_table *HT, valid_file *head)
{
    // firstly intializing all hash table entries to null
    for (int i = 0; i < SIZE; i++)
        HT->table[i] = NULL;

    // handling each file in that list
    valid_file *current = head;

    while (current != NULL)
    {
        printf("Processing file: %s\n", current->Files);
        process_single_file(HT, current->Files);
        current = current->link;
    }
    return SUCCESS;
}

// creating function for Handling a single file
int process_single_file(hash_table *HT, char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: Cannot open file %s\n", filename);
        return FAILURE;
    }
    char word[50];      // it is used for temporarilt stores the one word
    int char_index = 0; // position of the word
    char ch;            // it is used for the store one character from file

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isalnum(ch) || ch == '_' || ch == '-')
        {
            if (char_index < 49) // maximum characters is 49 and last is '\0'
            {
                word[char_index] = tolower(ch);
                char_index++;
            }
        }
        else if (char_index > 0)
        {
            word[char_index] = '\0';

            // Inserting the valid word into the database
            if (strlen(word) > 0)
                insert_word_to_databse(HT, word, filename);

            char_index = 0; // reseting for the new word
        }
    }
    // handling last word in file
    if (char_index > 0)
    {
        word[char_index] = '\0';
        if (strlen(word) > 0)
            insert_word_to_databse(HT, word, filename);
    }
    fclose(fp);
    return SUCCESS;
}

// Creating a function insert word into databse
int insert_word_to_databse(hash_table *HT, char *word, char *filename)
{
    int index = get_hash_index(word);
}

int get_hash_index(char *word)
{
    char first_char = word[0];

    if (first_char >= 'A' && first_char <= 'Z')
        return first_char - 'A'; // here i get the index
    else if (first_char >= 'a' && first_char <= 'z')
        return first_char - 'a'; // here also i get the index
    else
        return SIZE - 1;
}