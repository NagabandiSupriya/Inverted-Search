#include "inverted.h"
extern int create_flag;
extern int update_flag;
void create_database(M_node *HT[], F_node *head)
{
    if(create_flag==1)
    {
        printf(RED"Database already created \n"RESET);
        return;
    }
    char str[100];
    while (head)
    {
        FILE *fp = fopen(head->f_name, "r");

        if (fp != NULL)
        {
            while (fscanf(fp, "%s", str) != EOF)
            {
                int index = get_index(str);

                /* Case 1: Hash index empty */
                if (HT[index] == NULL)
                {
                    M_node *new_main = malloc(sizeof(M_node));
                    strcpy(new_main->word, str);
                    new_main->file_count = 1;
                    new_main->main_link = NULL;

                    S_node *new_sub = malloc(sizeof(S_node));
                    strcpy(new_sub->filename, head->f_name);
                    new_sub->word_count = 1;
                    new_sub->sub_link = NULL;

                    new_main->sub_link = new_sub;
                    HT[index] = new_main;
                }
                else
                {
                    M_node *temp = HT[index];
                    M_node *prev = NULL;

                    /* Search main list */
                    while (temp && strcmp(temp->word, str) != 0)
                    {
                        prev = temp;
                        temp = temp->main_link;
                    }

                    /* Word NOT found */
                    if (temp == NULL)
                    {
                        M_node *new_main = malloc(sizeof(M_node));
                        strcpy(new_main->word, str);
                        new_main->file_count = 1;
                        new_main->main_link = NULL;

                        S_node *new_sub = malloc(sizeof(S_node));
                        strcpy(new_sub->filename, head->f_name);
                        new_sub->word_count = 1;
                        new_sub->sub_link = NULL;

                        new_main->sub_link = new_sub;
                        prev->main_link = new_main;
                    }
                    else
                    {
                        /* Word FOUND → check sub list */
                        S_node *sub_temp = temp->sub_link;
                        S_node *sub_prev = NULL;

                        while (sub_temp &&
                               strcmp(sub_temp->filename, head->f_name) != 0)
                        {
                            sub_prev = sub_temp;
                            sub_temp = sub_temp->sub_link;
                        }

                        /* Same word in NEW file */
                        if (sub_temp == NULL)
                        {
                            S_node *new_sub = malloc(sizeof(S_node));
                            strcpy(new_sub->filename, head->f_name);
                            new_sub->word_count = 1;
                            new_sub->sub_link = NULL;

                            sub_prev->sub_link = new_sub;
                            temp->file_count++;     // FILE COUNT++
                        }
                        /* Same word in SAME file */
                        else
                        {
                            sub_temp->word_count++; // WORD COUNT++
                        }
                    }
                }
            }
            fclose(fp);
            if(update_flag)
                break;
        }
        head = head->link;
    }
}


// Function to calculate hash index based on first character of word
int get_index(char *str)
{
    int index;

    if(str[0] >= 'a' && str[0] <= 'z')        // If lowercase letter
        index = str[0] - 'a';
    else if(str[0] >= 'A' && str[0] <= 'Z')   // If uppercase letter
        index = str[0] - 'A';
    else                                      // If special character
        index = 26;

    return index;   
}


