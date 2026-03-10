#include "inverted.h"

/* Function definitions */
void validate_files(char *argv[], F_node **head)
{
    int i = 1;

    while (argv[i])
    {
        char *res = strstr(argv[i], ".");

        if (res && strcmp(res, ".txt") == 0)
        {
            FILE *fp = fopen(argv[i], "r");
            if (fp != NULL)
            {
                fseek(fp, 0, SEEK_END);
                long count = ftell(fp);
                rewind(fp);

                if (count != 0)
                {
                    if (check_duplicates(*head, argv[i]) == FAILURE)
                    {
                        if (insert_last(head, argv[i]) == SUCCESS)
                        {
                            printf(CYAN"\nINFO : Successful : inserting filename %s into file linked list\n\n"RESET, argv[i]);
                        }
                    }
                    else
                    {
                        printf(RED"INFO : This file is repeated, so it will not be stored\n\n"RESET);
                    }
                }
                else
                {
                    printf(RED"INFO : %s => This file is empty\n\n"RESET, argv[i]);
                }

                fclose(fp);
            }
            else
            {
                printf(RED"INFO : %s => This file not exit in the current directory\n\n"RESET,argv[i]);

            }
        }
        else if (res == NULL)
        {
            printf(RED"INFO : %s has no extension\n\n"RESET, argv[i]);
        }
        else
        {
            printf(RED"INFO : %s is not a .txt file\n\n"RESET, argv[i]);
        }

        i++;
    }
}


int check_duplicates(F_node *head, char *f_name)
{
    F_node *temp=head;
    while(temp)
    {
        if(strcmp(temp->f_name,f_name) ==0)
        {
            return SUCCESS;
        }
        temp=temp->link;
    }
    return FAILURE;

}

int insert_last(F_node **head, char *f_name)
{
    F_node *new = malloc(sizeof(F_node));
    if (new == NULL)
    {
        return FAILURE;
    }

    strcpy(new->f_name, f_name);
    new->link = NULL;

    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    F_node *temp = *head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = new;
    return SUCCESS;
}


int print_filenames(F_node *head)
{
    if (head == NULL)
    {
        printf(YELLOW"INFO : File list is empty\n"RESET);
        return FAILURE;
    }

    F_node *temp = head;
    while (temp)
    {
        printf(CYAN"%s->"RESET, temp->f_name);
        temp = temp->link;
    }
    printf(CYAN"NULL\n\n"RESET);

    return SUCCESS;
}




