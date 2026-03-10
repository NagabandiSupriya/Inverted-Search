#include "inverted.h"

void save_database(M_node *HT[])
{
    FILE *fp = fopen("database.txt", "w");  // Open file in write mode

    if (fp == NULL)   // Check if file opened successfully
    {
        printf(RED"Error: Unable to open file\n"RESET);
        return;
    }

    // Loop through all hash table indexes
    for (int i = 0; i <= 26; i++)
    {
        if (HT[i] != NULL)
        {
            M_node *mtemp = HT[i];  // Pointer to main list

            // Traverse main linked list
            while (mtemp)
            {
                // Write index, word, and file count into file
               fprintf(fp,"# %d ; %s ; %d", i, mtemp->word, mtemp->file_count);

                S_node *stemp = mtemp->sub_link;  // Pointer to sub list

                // Traverse sub linked list
                while (stemp)
                {
                    // Write filename and word count into file
                    fprintf(fp,"%s %d\n",stemp->filename, stemp->word_count);

                    stemp = stemp->sub_link; // Move to next sub node
                }

                mtemp = mtemp->main_link; // Move to next main node
            }
        }
    }

    fclose(fp);   // Close the file
    printf(GREEN"Database saved successfully into database.txt\n\n"RESET);
}
