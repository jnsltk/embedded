#include <stddef.h>   // includes standard definitions library for offsetof function
#include <stdio.h>    // includes standard input output library for printf, getchar, putchar, etc.
#include <stdlib.h>   // includes standard library for malloc, free
#include <string.h>   // includes string library for strcmp, strcpy, etc.

/* ------------------------- MACROS ------------------------- */

#define FILE_NAME "people.bin"   // defines file name
#define NAME_SIZE 20             // defines max size for the names

// defines the menu text
#define MENU                                                                                       \
    "\n1 Create a new and delete the old file.\n"                                                  \
    "2 Add a new person to the file.\n"                                                            \
    "3 Search for a person in the file.\n"                                                         \
    "4 Print out all in the file.\n"                                                               \
    "5 Exit the program.\n"

/* ------------------------ TYPEDEFS ------------------------ */

typedef struct {                 // defines a person struct
    char firstname[NAME_SIZE];   // char array for the first name
    char famname[NAME_SIZE];     // char array for the family name
    char pers_number[13];        // person number string
} PERSON;                        // names the struct PERSON

/* ------------------ FUNCTION DECLARATIONS ----------------- */

PERSON input_record(void);                       // Reads a person’s record.
void printfile(void);                            // Prints out all persons in the file
void append_file(PERSON *inrecord);              // appends a new person to the file
void write_file(PERSON *inrecord, char *mode);   // appends a new person to the file
void print_person(PERSON *person);               // prints out a PERSON struct
void read_str(char *output, unsigned char s);    // reads a string from stdin
void search_menu();                              // prints out the search menu
void search_by_firstname(char *name);            // searches for a person by first name
void search_by_lastname(char *name);             // searches for a person by last name
char get_one_char();                             // gets one char from stdin, and clears the buffer

// Creates a file and write the first record
void write_new_file(PERSON *inrecord);

// Prints out the person if in list
void search(char *name, size_t offset);

/* ------------------ FUNCTION DEFINITIONS ------------------ */

// Main function
int main(void) {
    char c = '0';   // initializes input char to '0' (arbitraty value)
    PERSON ppost;   // declares a PERSON struct

    printf(MENU);   // prints out the menu

    while ((c = get_one_char()) != '5') {   // while input is not '5'
        switch (c) {                        // switch on input
            case '1':                       // if input is '1'

                // copies arbitrary string to famname of ppost
                strcpy(ppost.famname, "Efternamn");

                // copies arbitrary string to firstname of ppost
                strcpy(ppost.firstname, "Fornamn");

                // copies arbitrary string to pers_number of ppost
                strcpy(ppost.pers_number, "111122334445");

                write_new_file(&ppost);   // writes the ppost to a new file
                break;                    // breaks the switch
            case '2':                     // if input is '2'
                ppost = input_record();   // reads a person from stdin
                append_file(&ppost);      // appends the person the file
                break;                    // breaks the switch
            case '3':                     // if input is '3'
                search_menu();            // enters search function
                break;                    // breaks the switch
            case '4':                     // if input is '4'
                printfile();              // prints out the file
                break;                    // breaks the switch

            default:   // if input is not '1', '2', '3', '4', or '5'
                printf("Invalid choice\n");
                break;   // breaks the switch
        }

        printf(MENU);   // prints out the menu
    }

    return (0);   // returns 0 for success
}

/* --------------------- FILE OPERATIONS -------------------- */

// creates a file and write the first record
void write_new_file(PERSON *inrecord) {
    write_file(inrecord, "wb");   // overwrites the file (or creates a new one) with the new record
}

// appends a new person to the file
void append_file(PERSON *inrecord) {
    write_file(inrecord, "ab");   // appends the new record to the file
}

// writes to people file
void write_file(PERSON *inrecord, char *mode) {
    FILE *file = fopen(FILE_NAME, mode);   // opens the file in the provided mode
    if (file == NULL) {                    // if failed to open file
        fprintf(stderr, "Failed to open file");
        return;   // returns
    }

    // writes the inrecord to the file
    if (fwrite(inrecord, sizeof(PERSON), 1, file) != 1)   // if failed to write to file
        fprintf(stderr, "Failed to write to file");

    fclose(file);   // closes the file
}

// prints out all persons in the file
void printfile(void) {
    PERSON person;               // declares a PERSON struct
    unsigned char results = 0;   // initializes results amount to 0

    FILE *file = fopen(FILE_NAME, "rb");   // opens the file in read binary mode
    if (file == NULL) {                    // if failed to open file
        fprintf(stderr, "Failed to open file\n");
        return;   // exit the function
    }

    // while can read a person from the file
    while (fread(&person, sizeof(PERSON), 1, file) != 0) {
        print_person(&person);   // prints out the person
        results++;               // counts the amount of results
    }

    printf("\n ----- Found %hhu results -----\n", results);

    fclose(file);   // closes the file
}

/* --------------------- READ FROM STDIN -------------------- */

// reads a person’s record from stdin
PERSON input_record(void) {
    PERSON person;   // declares a PERSON struct

    printf("Enter firstname: ");
    read_str(person.firstname, NAME_SIZE);   // reads first name from stdin

    printf("Enter family name: ");
    read_str(person.famname, NAME_SIZE);   // reads last name from stdin

    printf("Enter social security number: ");
    // reads social security number from stdin
    read_str(person.pers_number, sizeof(person.pers_number));

    return person;
}

// reads a string from stdin
void read_str(char *output, unsigned char s) {
    if (s == 0) {   // if s is 0
        fprintf(stderr, "Invalid string size\n");
        return;   // returns
    }

    unsigned char i = 1;   // initializes i (counter variable) to 1
    *output = getchar();   // reads a char from stdin and stores it in output

    // while not reading newline and input is within size bounds
    while (*output != '\n' && i < s) {
        output++;              // increments output pointer
        i++;                   // increments i (counter variable)
        *output = getchar();   // reads a char from stdin and stores it at the output pointer
    }

    if (*output != '\n')            // the whole string did not fit into the output
        while (getchar() != '\n')   // clears the buffer
            ;                       // does nothing

    *output = '\0';   // sets the last char of the string to null terminator
}

// reads one char from stdin and clears the buffer
char get_one_char() {
    char c = getchar();   // reads one char from stdin

    if (c == '\n')     // if the char is newline
        return '\n';   // returns newline

    while (getchar() != '\n')   // clears the buffer
        ;                       // does nothing

    return c;   // returns the character
}
/* ------------------------- SEARCH ------------------------- */

// the search menu
void search_menu() {
    char name[NAME_SIZE];   // declares a char array for the name
    char c;                 // declares a char for the first/last name choice

    printf("Search for (f)irst name or (l)ast name?: ");
    c = get_one_char();   // gets one char from stdin, and clears the buffer

    printf("Enter name to search for:");
    read_str(name, NAME_SIZE);   // reads a string from stdin

    switch (c) {                         // switch on the first/last name choice
        case 'f':                        // if first name
            search_by_firstname(name);   // search by first name
            break;                       // breaks the switch
        case 'l':                        // if last name
            search_by_lastname(name);    // search by last name
            break;                       // breaks the switch
        default:                         // if invalid character input
            printf("Invalid search alternative\n");
            return search_menu();   // returns to the search menu again
    }
}

// searches for a person by first name
void search_by_firstname(char *name) {
    // gets the offset of the first name property in the PERSON struct (0 in this case)
    const size_t offset = offsetof(PERSON, firstname);
    search(name, offset);   // searches for the name in the file
}

// searches for a person by last name
void search_by_lastname(char *name) {
    // gets the offset of the last name property in the PERSON struct (20 in this case)
    const size_t offset = offsetof(PERSON, famname);
    search(name, offset);   // searches for the name in the file
}

// searches for a person in the file
void search(char *name, size_t offset) {
    PERSON person;               // declares a PERSON struct
    unsigned char results = 0;   // initializes results amount to 0

    FILE *file = fopen(FILE_NAME, "rb");   // opens the file in read binary mode
    if (file == NULL) {                    // if failed to open file
        fprintf(stderr, "Failed to open file\n");
        return;   // exit the function
    }

    // while can read a person from the file
    while (fread(&person, sizeof(PERSON), 1, file) != 0) {
        // calculates the pointer to the name in the struct
        char *cPtr = (char *) &person + offset;
        if (strcmp(cPtr, name) == 0) {   // if the name is found
            results++;                   // increments the results counter
            print_person(&person);       // prints out the person
        }
    }

    printf("\n ----- Found %hhu results -----\n", results);

    fclose(file);   // closes the file
}

/* -------------------------- MISC -------------------------- */

// prints out a PERSON struct
void print_person(PERSON *person) {
    printf(" ------ PERSON ------ \nfirstname: %s\nfamname: %s\npers_number: %s\n",
           person->firstname, person->famname, person->pers_number);
}