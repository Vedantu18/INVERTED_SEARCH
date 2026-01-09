#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1
#define SIZE 26

/*structure for sub node*/
typedef struct sub_node
{
    int word_count;
    char file_name[50];
    struct sub_node *sub_link;
}sub_node;

/*structure for sub main node*/
typedef struct main_node
{
    int file_count;
    char word[50];
    struct sub_node *main_sub_link;
    struct main_node*main_link;
}main_node;

/*structure for hash*/
typedef struct hash
{
    int index;
    struct main_node *hash_link;
}hash;

/*structure of single linked list */
typedef struct valid_file_list
{
    char file_create[50];
    struct valid_file_list *link;
}valid_file;

#endif