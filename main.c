/* 
NAME            : NAGABANDI SUPRIYA
DATE            : 09-01-2026

DESCRIPTION     : This program implements an Inverted Index using a Hash Table.
                  It accepts multiple text files as command-line arguments,
                  validates them, and creates a database of unique words.
                  Each word is stored along with the file names and the number 
                  of times it appears in each file.

                  The program provides a menu-driven interface to:
                  1. Create Database
                  2. Display Database
                  3. Save Database
                  4. Search Word
                  5. Update Database
                  6. Exit

                  A hash table of size 27 is used where:
                  - Index 0–25 represent alphabets (a–z)
                  - Index 26 represents special characters

SAMPLE INPUT    : ./a.out file1.txt file2.txt
                  (User selects option 1 to create database)

SAMPLE OUTPUT   : Database created successfully
                  Word details displayed based on user operation
*/

#include "inverted.h"
//#include <string.h>

int update_flag=0;
int create_flag=0;

int main(int argc, char *argv[])
{
    F_node *head = NULL;
    M_node *HT[27];

    // Validate_files
	if(argc >1)
	{
		validate_files(argv,&head);
		print_filenames(head);
	}
	else
	{
		printf(RED"INFO :Insufficient arguments\n");
		printf("Please  pass the arguments like a.out <txt file>\n"RESET);
		return FAILURE;
	}
	for(int i=0;i<=26;i++)
	{
		HT[i]=NULL; //putting all the hash values as NULL
		
	}
    int option;
    do
    {
	printf("Select your choice among following operations:\n1. Create Database\n2. Display Database\n3. Save Database\n4. Search\n5. Update Database\n6. Exit\n\nEnter your choice : ");
	scanf("%d", &option);

	switch (option)
	{
	    case 1:
		
		create_database(HT, head);
		create_flag=1;
		break;

	    case 2:
			display_database(HT);
			break;

	    case 3:
			save_database(HT);
		    break;

	    case 4:
			search_database(HT);
			break;

	    case 5:
			if(create_flag ==0)
			{
				printf(MAGENTA"Database not created\n"RESET);
				break;
			}
			create_flag=0;
			update_flag=1;
			update_database(HT, &head);
			break;

	    case 6:
		break;

	    default:
		printf(RED"INFO : Please enter the valid option\n"RESET);
	}
    }while( option != 6 );

    return 0;
}
