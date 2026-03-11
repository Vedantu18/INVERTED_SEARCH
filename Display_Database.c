#include "Header.h"

void display_database(hash_table *HT)
{
    printf("\nDATABASE\n");

    for(int i = 0; i < SIZE; i++)
    {
        if(HT->table[i] != NULL)
        {
            main_node *mtemp = HT->table[i];

            while(mtemp)
            {
                printf("Index[%d] Word: %s Filecount: %d -> ", i, mtemp->word, mtemp->file_count);

                sub_node *stemp = mtemp->main_sub_link;

                while(stemp)
                {
                    printf("File: %s Wordcount: %d -> ", stemp->file_name, stemp->word_count);
                    stemp = stemp->sub_link;
                }

                printf("NULL\n");
                mtemp = mtemp->main_link;
            }
        }
    }
}