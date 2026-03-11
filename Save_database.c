#include "Header.h"

void save_database(hash_table *HT, char *filename)
{
    FILE *fp = fopen(filename, "w");

    if(fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    for(int i = 0; i < SIZE; i++)
    {
        main_node *mtemp = HT->table[i];

        while(mtemp)
        {
            fprintf(fp, "#%d;%s;%d;", i, mtemp->word, mtemp->file_count);

            sub_node *stemp = mtemp->main_sub_link;

            while(stemp)
            {
                fprintf(fp, "%s;%d;", stemp->file_name, stemp->word_count);
                stemp = stemp->sub_link;
            }

            fprintf(fp, "#\n");

            mtemp = mtemp->main_link;
        }
    }

    fclose(fp);

    printf("Database saved successfully\n");
}