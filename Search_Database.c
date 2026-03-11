#include "Header.h"

void search_database(hash_table *HT, char *word)
{
    int index = get_hash_index(word);

    main_node *mtemp = HT->table[index];

    while(mtemp)
    {
        if(strcmp(mtemp->word, word) == 0)
        {
            printf("Word found: %s\n", word);
            printf("File count: %d\n", mtemp->file_count);

            sub_node *stemp = mtemp->main_sub_link;

            while(stemp)
            {
                printf("File: %s -> Count: %d\n", stemp->file_name, stemp->word_count);
                stemp = stemp->sub_link;
            }
            return;
        }

        mtemp = mtemp->main_link;
    }

    printf("Word not found\n");
}