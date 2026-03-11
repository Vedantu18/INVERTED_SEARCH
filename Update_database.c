#include "Header.h"

void update_database(hash_table *HT, char *filename)
{
    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("File not found\n");
        return;
    }

    char line[200];

    while(fgets(line, sizeof(line), fp))
    {
        if(line[0] != '#')
            continue;

        int index;
        char word[50];
        int file_count;

        sscanf(line, "#%d;%[^;];%d;", &index, word, &file_count);

        main_node *new_main = malloc(sizeof(main_node));

        strcpy(new_main->word, word);
        new_main->file_count = file_count;
        new_main->main_link = NULL;
        new_main->main_sub_link = NULL;

        if(HT->table[index] == NULL)
        {
            HT->table[index] = new_main;
        }
        else
        {
            main_node *temp = HT->table[index];

            while(temp->main_link)
                temp = temp->main_link;

            temp->main_link = new_main;
        }
    }

    fclose(fp);

    printf("Database updated successfully\n");
}