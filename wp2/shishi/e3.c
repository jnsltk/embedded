// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

/* ----------------------------- Include section ---------------------------- */
#include <stdio.h>
#include <string.h>

/* ------------------------------ Define struct ----------------------------- */
typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13];   // yyyymmddnnnc
} PERSON;

/* -------------------------- Function declaration -------------------------- */
PERSON input_record(void);               // Reads a person's record
void write_new_file(PERSON *inrecord);   // Creates a file and writes the first record
void printfile(void);                    // Prints out all persons in the file
void search_by_firstname(char *name);    // Prints out the person if in the list
void append_file(PERSON *inrecord);      // Appends a new person to the file
void execute_task(PERSON *ppost, int option_num);
int validate_format(char *personnum);   // Validates the format of the input personnummer

/* -------------------------- Main program section -------------------------- */

/**
 * This program manages a database of persons.
 * The database is stored as a binary file.
 */

int main(void) {
    PERSON ppost;
    // PERSON *new_person;
    // new_person = &ppost;
    // ppost.famname = "Jonsson";
    // ppost.firstname = "Mike";

    char *options[] = {"1 Create a new and delete the old file.",
                       "2 Add a new person to the file.",
                       "3 Search for a person in the file.",
                       "4 Print out all in the file.",
                       "5 Exit the program.",
                       "\0"};
    char **ptr = options;
    while (**ptr != '\0') {
        printf("%s\n", *ptr);
        ptr++;
    }

    int i = 0;
    char c;
    int option_num = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            char **p = options;
            while (**p != '\0') {
                printf("%s\n", *p);
                p++;
            }
            i = 0;
        } else if (c == '5') {
            return 0;
        } else {
            i++;
            if ((i > 1) || (c < '1' || c > '5')) {
                printf("Error: Invalid input.\n");
            } else {
                option_num = c - 48;
                execute_task(&ppost, option_num);
            }
        }
    }

    printf("option: %d", option_num);

    // exit the program successfully
    return 0;
}

void execute_task(PERSON *ppost, int option_num) {
    char name[20];
    switch (option_num) {
    case 1:   // Create a new and delete the old file.
        *ppost = input_record();
        write_new_file(ppost);
        break;
    case 2:   // Add a new person to the file
        *ppost = input_record();
        append_file(ppost);
        break;
    case 3:   // Search for a person in the file.
        printf("Enter the firstname to search: ");
        scanf("%s", name);
        search_by_firstname(name);
        break;
    case 4:   // Print out all in file.
        printfile();
        break;
    default:
        break;
    }
}

PERSON input_record(void) {
    PERSON person;
    printf("Enter the firstname: ");
    scanf("%s", person.firstname);
    printf("Enter the lastname: ");
    scanf("%s", person.famname);
    printf("Enter the personnummer(following the format: yyyymmddnnnc): ");
    char personnum[13];
    scanf("%s", personnum);
    while (validate_format(personnum) != 1) {
        printf("Enter the personnummer(following the format: yyyymmddnnnc): ");
        scanf("%s", personnum);
    }
    strcpy(person.pers_number, personnum);

    return person;
}

// The function creates a new file with the specified filename (hardcoded, fixed) and writes a first
// dummy record to
// the file and then close it.
void write_new_file(PERSON *inrecord) {
    FILE *fptr;
    if ((fptr = fopen("persons.dat", "wb")) == NULL) {
        printf("Error: File could not be opened.\n");
    } else {
        int flag = 0;

        flag = fwrite(inrecord, sizeof(PERSON), 1, fptr);
        if (flag) {
            printf("The record has been written successfully.\n");
        } else {
            printf("Error Writing to File!\n");
        }
    }
    // close file
    fclose(fptr);
}

void append_file(PERSON *inrecord) {
    FILE *fptr;
    if ((fptr = fopen("persons.dat", "ab")) == NULL) {
        printf("Error: File could not be opened.\n");
    } else {
        // PERSON second_person = {"Jenny", "Erikson", "199909191113"};
        int flag = 0;
        printf("person: %s %s %s\n", inrecord->firstname, inrecord->famname, inrecord->pers_number);
        flag = fwrite(inrecord, sizeof(PERSON), 1, fptr);
        if (flag) {
            printf("The record has been appened successfully\n");
        } else {
            printf("Error Writing to File!\n");
        }
    }
    // close file
    fclose(fptr);
}

void search_by_firstname(char *name) {
    FILE *fptr;                 // declare a file pointer
    PERSON person;              // declare a PERSON struct
    PERSON *perptr = &person;   // set a pointer to the address of the PERSON struct
    char filename[15];          // declare a variable used to store filename
    if ((fptr = fopen("persons.dat", "rb")) == NULL) {
        printf("Cannot open file\n");
    } else {
        fseek(fptr, 0L, SEEK_END);   // move the cursor to the end of the file
        if (ftell(fptr) == 0) {      // check if the size of the file is 0/empty
            printf("Error: The file is empty.\n");
        }
        rewind(fptr);   // move the cursor to the beginning of the file
        int result_num =
            0;   // define a variable to store the number of the found names in the database
        int status = 0;   // define a variable to indicate the successful status of reading the
                          // file, 0 means succussful, 1 means error
        while (!feof(fptr)) {   // loop until it is the end of the file
            if (fread(perptr, sizeof(PERSON), 1, fptr)) {
                if (strcmp(name, perptr->firstname) ==
                    0) {            // compare if the first name in the record matches the name
                    result_num++;   // increment the number of the found name by 1
                    printf("Name found: %s %s %s\n", perptr->firstname, perptr->famname,
                           perptr->pers_number);
                }
            } else if (!feof(fptr)) {   // if fread failes, and it is not the end of the file,
                                        // output an error message
                status = 1;             // indicate there is an error occured
                printf("Error: Error from reading file\n");
            }
        }
        if (status == 0 &&
            result_num == 0) {   // if no error occured during reading the file and no matched name
                                 // found, output a message that no matched name found
            printf("Name not found in the database.\n");
        }
        // close file
        fclose(fptr);
    }
}

void printfile(void) {
    FILE *fptr;
    PERSON person;
    PERSON *perptr = &person;
    char filename[15];
    fptr = fopen("persons.dat", "rb");
    if (fptr == NULL) {
        printf("Cannot open file\n");
    } else {
        fseek(fptr, 0L, SEEK_END);   // move the cursor to the end of the file
        if (ftell(fptr) == 0) {      // check if the size of the file is 0/empty
            printf("Error: The file is empty.\n");
        }
        rewind(fptr);   // move the cursor to the beginning of the file
        while (!feof(fptr)) {
            if (fread(perptr, sizeof(PERSON), 1, fptr)) {
                printf("%s %s %s\n", perptr->firstname, perptr->famname, perptr->pers_number);
            } else if (!feof(fptr)) {
                printf("Error: Error from reading file\n");
            }
        }
        // close file
        fclose(fptr);
    }
}

// This function validates the format of the input personnummber, return 0 -> false (invalid
// format), return 1 -> true (valid format)
int validate_format(char *personnum) {
    char *c = personnum;
    int counter = 0;
    while (*c) {
        counter++;
        if (*c < '0' || *c > '9') {
            return 0;
        }
        c++;
    }
    if (counter != 12) {
        return 0;
    }
    return 1;
}