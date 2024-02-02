#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------- MACROS ------------------------- */

#define FILE_NAME "people.bin"
#define NAME_SIZE 20

#define MENU                                                                                       \
    "\n1 Create a new and delete the old file.\n"                                                  \
    "2 Add a new person to the file.\n"                                                            \
    "3 Search for a person in the file.\n"                                                         \
    "4 Print out all in the file.\n"                                                               \
    "5 Exit the program.\n"

/* ------------------------ TYPEDEFS ------------------------ */

typedef struct {
    char firstname[NAME_SIZE];
    char famname[NAME_SIZE];
    char pers_number[13];   // yyyymmddnnnc
} PERSON;

/* ------------------ FUNCTION DECLARATIONS ----------------- */

PERSON input_record(void);                       // Reads a person’s record.
void printfile(void);                            // Prints out all persons in the file
void append_file(PERSON *inrecord);              // appends a new person to the file
void write_file(PERSON *inrecord, char *mode);   // appends a new person to the file
void print_person(PERSON *person);
void read_str(char *output, unsigned char s);
void search_menu();
void search_by_firstname(char *name);
void search_by_lastname(char *name);
char get_one_char();

// Creates a file and write the first record
void write_new_file(PERSON *inrecord);

// Prints out the person if in list
void search(char *name, size_t offset);

/* ------------------ FUNCTION DEFINITIONS ------------------ */

int main(void) {
    char c = '0';
    PERSON ppost;

    printf(MENU);

    while ((c = get_one_char()) != '5') {
        switch (c) {
            case '1':
                strcpy(ppost.firstname, "Fornamn");
                strcpy(ppost.famname, "Efternamn");
                strcpy(ppost.pers_number, "111122334445");
                write_new_file(&ppost);
                break;
            case '2':
                ppost = input_record();
                append_file(&ppost);
                break;
            case '3':
                search_menu();
                break;
            case '4':
                printfile();
                break;

            default:
                printf("Invalid choice\n");
                break;
        }

        printf(MENU);
    }

    return (0);
}

/* --------------------- FILE OPERATIONS -------------------- */

void write_new_file(PERSON *inrecord) {
    write_file(inrecord, "wb");
}

void append_file(PERSON *inrecord) {
    write_file(inrecord, "ab");
}

void write_file(PERSON *inrecord, char *mode) {
    FILE *file = fopen(FILE_NAME, mode);
    if (file == NULL) {
        fprintf(stderr, "Failed to open file");
        return;
    }

    if (fwrite(inrecord, sizeof(PERSON), 1, file) != 1)
        fprintf(stderr, "Failed to write to file");

    fclose(file);
}

void printfile(void) {
    PERSON person;
    unsigned char results = 0;

    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file\n");
        return;
    }

    while (fread(&person, sizeof(PERSON), 1, file) != 0) {
        print_person(&person);
        results++;
    }

    printf("\n ----- Found %hhu results -----\n", results);

    fclose(file);
}

/* --------------------- READ FROM STDIN -------------------- */

PERSON input_record(void) {
    PERSON person;

    printf("Enter firstname: ");
    read_str(person.firstname, NAME_SIZE);

    printf("Enter family name: ");
    read_str(person.famname, NAME_SIZE);

    printf("Enter social security number: ");
    read_str(person.pers_number, sizeof(person.pers_number));

    return person;
}

void read_str(char *output, unsigned char s) {
    unsigned char i = 1;
    *output = getchar();
    while (*output != '\n' && i < s) {
        output++;
        i++;
        *output = getchar();
    }

    if (*output != '\n')
        while (getchar() != '\n')
            ;

    *output = '\0';
}

char get_one_char() {
    char c = getchar();

    if (c == '\n')
        return '\n';

    while (getchar() != '\n')
        ;

    return c;
}
/* ------------------------- SEARCH ------------------------- */

void search_menu() {
    char name[NAME_SIZE];
    char c;
    size_t offset;

    printf("Search for (f)irst name or (l)ast name?: ");
    c = get_one_char();

    printf("Enter name to search for:");
    read_str(name, NAME_SIZE);

    switch (c) {
        case 'f':
            search_by_firstname(name);
            break;
        case 'l':
            search_by_lastname(name);
            break;
        default:
            printf("Invalid alternative\n");
            return search_menu();
    }

    search(name, offset);
}

void search_by_firstname(char *name) {
    const size_t offset = offsetof(PERSON, firstname);
    search(name, offset);
}

void search_by_lastname(char *name) {
    const size_t offset = offsetof(PERSON, famname);
    search(name, offset);
}

void search(char *name, size_t offset) {
    PERSON person;
    unsigned char results = 0;

    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file\n");
        return;
    }

    while (fread(&person, sizeof(PERSON), 1, file) != 0) {
        char *cPtr = (char *) &person + offset;
        results++;
        if (strcmp(cPtr, name) == 0)
            print_person(&person);
    }

    printf("\n ----- Found %hhu results -----\n", results);

    fclose(file);
}

/* -------------------------- MISC -------------------------- */

void print_person(PERSON *person) {
    printf(" ------ PERSON ------ \nfirstname: %s\nfamname: %s\npers_number: %s\n",
           person->firstname, person->famname, person->pers_number);
}