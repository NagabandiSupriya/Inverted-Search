#include "inverted.h" 
void display_database(M_node *HT[])
{
    // Header in CYAN
    printf(CYAN "\n%-5s | %-12s | %-10s | %-11s | %-10s\n" RESET,
           "INDEX", "WORD", "FILE_COUNT", "FILE_NAME", "WORD_COUNT");

    printf(CYAN "-----------------------------------------------------------\n" RESET);

    // Loop through hash table
    for (int i = 0; i < 27; i++)
    {
        M_node *mtemp = HT[i];

        while (mtemp)
        {
            S_node *stemp = mtemp->sub_link;
            int first = 1;

            while (stemp)
            {
                if (first)
                {
                    // Index & Word in GREEN, counts in YELLOW
                    printf(GREEN "%-5d" RESET " | "
                           BLUE "%-12s" RESET " | "
                           YELLOW "%-10d" RESET " | "
                           MAGENTA "%-11s" RESET " | "
                           YELLOW "%-10d\n" RESET,
                           i,
                           mtemp->word,
                           mtemp->file_count,
                           stemp->filename,
                           stemp->word_count);
                    first = 0;
                }
                else
                {
                    // File details only
                    printf("%-5s | %-12s | %-10s | "
                           MAGENTA "%-11s" RESET " | "
                           YELLOW "%-10d\n" RESET,
                           "",
                           "",
                           "",
                           stemp->filename,
                           stemp->word_count);
                }

                stemp = stemp->sub_link;
            }

            mtemp = mtemp->main_link;
        }
    }
}
