#include "inverted.h"

void search_database(M_node *HT[])
{
    char search[20];

    // Ask user for word
    printf("Enter the word to search : ");
    scanf("%s", search);

    int index = get_index(search);     // Get hash index
    M_node *temp = HT[index];          // Point to main list

    // Traverse main linked list
    while (temp)
    {
        if (strcmp(temp->word, search) == 0)
        {
            printf(GREEN"\nword %s present in %d file "RESET,temp->word, temp->file_count);

            // Traverse sub list since last two are from subnode
            S_node *stemp = temp->sub_link;
            while (stemp)
            {
                printf(GREEN"in file %s %d times\n\n"RESET,stemp->filename, stemp->word_count);

                stemp = stemp->sub_link; //move to next sub node
            }
            return; 
        }

        temp = temp->main_link; // Move to next main node
    }

    // If word not found
    printf(RED"\nword %s is not present in database\n"RESET, search);
}
