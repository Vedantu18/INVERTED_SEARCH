#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1
#define SIZE 27

/*structure for sub node*/
typedef struct sub_node
{
    int word_count;
    char file_name[50];
    struct sub_node *sub_link;
}sub_node;

/*structure for main node*/
typedef struct main_node
{
    int file_count;
    char word[50];
    struct sub_node *main_sub_link;
    struct main_node*main_link;
}main_node;

/*structure for hash table */
typedef struct hash_table
{
    struct main_node *table[SIZE]; //it is array of pointers
}hash_table;

/*structure of single linked list */
typedef struct valid_file_list
{
    char Files[50];
    struct valid_file_list *link;
}valid_file;

//All are the function declarationsS
int validation_of_file(valid_file **head, int argc, char *argv[]);
int is_duplicate_file(valid_file *head, char *filename);
int is_exists_or_empty(char *filename);
int create_list(valid_file **head, char *filename);
void print_list(valid_file *head);

/*For the database functions*/
int create_database(hash_table *HT, valid_file *head);
int process_single_file(hash_table *HT, char *filename);
int insert_word_to_databse(hash_table *HT, char *word, char *filename);
int get_hash_index(char *word);
#endif