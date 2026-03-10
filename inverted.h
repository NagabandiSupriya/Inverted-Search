#ifndef INVERTED_H
#define INVERTED_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS		1
#define FAILURE		0

// Color macros
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

typedef struct file
{
    char f_name[20];
    struct file *link;
}F_node;

typedef struct Sub
{
    int word_count;
    char filename[20];
    struct Sub *sub_link;
}S_node;

typedef struct Main
{
    char word[25];
    int file_count;
    S_node *sub_link;
    struct Main *main_link;
}M_node;


void create_database(M_node *HT[], F_node *head);
void display_database(M_node *HT[]);
void search_database(M_node *HT[]);
void save_database(M_node *HT[]);
int update_database(M_node *HT[],F_node **head);
int insert_first(F_node **head,char * filename);
void validate_files(char *argv[], F_node **head);
int insert_last(F_node **head, char *f_name);
int check_duplicates(F_node *head, char *f_name);
int print_filenames(F_node *head);
int get_index(char *word);

#endif
