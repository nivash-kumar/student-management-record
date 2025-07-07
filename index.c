#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *stdFP;
//  student.bin
FILE *upFP;
// temp.bin
struct student
{
    char name[100];
    int age;
    int admitionYear;
};
long sSize;
char getChoice();
void addRecord(FILE *stdFP);
void updateRecord(FILE *stdFP);
void listRecord(FILE *stdFP);
void deleteRecord(FILE *stdFP);
void exitRecord(FILE *stdFP);
void holdScreen();// this is for hold the screen********************************************************


int main()
{
    stdFP = fopen("student.bin", "rb+");
    if (stdFP == NULL)
    {
        stdFP = fopen("student.bin", "wb+");

        if (stdFP == NULL)
        {
            printf("Error opening file!\n");
            return 1;
        }
    }
    printf("File open successfuly!");
    struct student s;
    sSize = sizeof(s);
    char choice;
    rewind(stdFP);
    // getChoice();
    while (1)
    {
        printf("\n");
        choice = getChoice();
        // manuAction(choice);
        switch (choice - '0') // Convert char to int
        {
        case 0:
            exitRecord(stdFP);
            break;
        case 1:
            addRecord(stdFP);
            break;
        case 2:
            updateRecord(stdFP);
            break;
        case 3:
            listRecord(stdFP);
            break;
        case 4:
            deleteRecord(stdFP);
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    }
    fclose(stdFP);
    return 0;
}

char getChoice()
{
    system("cls");
    char choice;
    printf("\n");
    printf("Choice 1: Add a New Record\n");
    printf("Choice 2: Update Record\n");
    printf("Choice 3: List Record\n");
    printf("Choice 4: Delete Record\n");
    printf("Choice 0: Exit\n");
    printf("Enter your choice:\n");

    scanf(" %c", &choice); // Use " %c" to ignore previous newlines

    if (choice < '0' || choice > '4')
    { // Ensure input is between 0-4
        system("cls");
        printf("Enter a valid number\n");
        return getChoice(); // Recursively call and return the new value
    }

    return choice;
}

void addRecord(FILE *stdFP)
{
    holdScreen();// this is for hold the screen********************************************************
    system("cls");
    struct student s;
    printf("Enter new student name:\n");
    fgets(s.name, 100, stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // Remove the newline character
    printf("Enter student's age:\n");
    scanf("%d", &s.age);
    printf("Enter admission year:\n");
    scanf("%d", &s.admitionYear);
    fseek(stdFP, 0, SEEK_END);
    fwrite(&s, sSize, 1, stdFP);
    fflush(stdFP);
    system("cls");
    printf("Record added successfully.\n");
    getchar();
    holdScreen();// this is for hold the screen****************************************************
}
void deleteRecord(FILE *stdFP)
{
    system("cls");
    char nameSearch[100];
    struct student s;
    rewind(stdFP);
    printf("Enter student who's record want to delete:\n");
    getchar();
    fgets(nameSearch, 100, stdin);
    nameSearch[strcspn(nameSearch, "\n")] = '\0';
    upFP = fopen("temp.bin", "wb");
    int count=0;
    while (fread(&s, sSize, 1, stdFP) == 1)
    {
        if (strcmp(s.name, nameSearch) == 0)
        {
            // system("cls");
            count++;
            printf("Record matched!\n\a ARE YOU CONFIRM TO DELETE THIS RECORD\n\a");
            printf("\n\t\t \a press Y/y for (yes)\n");
            char confirm;
            scanf("%c", &confirm);
            if (confirm == 'Y' || confirm == 'y')
            {
                printf("Your record deleted!\n");
                getchar();
                continue;
            }
            else
            {
                printf("Your record not deleted!\n");
            }
        }
        fwrite(&s, sSize, 1, upFP);
    }
    if(count==0){
        printf("Record not matched!\n");
    }
    fclose(stdFP);
    fclose(upFP);
    remove("student.bin");
    rename("temp.bin", "student.bin");
    stdFP = fopen("student.bin", "rb+");
    holdScreen();// this is for hold the screen****************************************************
    return;
}
void listRecord(FILE *stdFP)
{
    system("cls");
    struct student s;
    rewind(stdFP);
    printf("\n\t\t-----Student Records-----\n");
    while (fread(&s, sSize, 1, stdFP) == 1)
    {
        printf("\t Name:\t%s \tAge:\t%d\t Admition Year:\t%d\n", s.name, s.age, s.admitionYear);
    }
    printf("\n\t\t-----End Records-----\n");
    getchar();
    holdScreen();// this is for hold the screen****************************************************
}
void updateRecord(FILE *stdFP)
{
    system("cls");
    char nameSearch[100];
    struct student s;
    printf("Enter student's name to update:\n");
    getchar();
    fgets(nameSearch, 100, stdin);
    nameSearch[strcspn(nameSearch, "\n")] = '\0';

    rewind(stdFP);
    while (fread(&s, sSize, 1, stdFP) == 1)
    {
        // printf("file name:%s : by input name: %s\n", s.name, nameSearch);
        if (strcmp(nameSearch, s.name) == 0)
        {
            printf("\nRecord matched!\n");
            holdScreen();// this is for hold the screen*************************************************
            system("cls");
            printf("Enter name:\n");
            fgets(s.name, 100, stdin);
            s.name[strcspn(s.name, "\n")] = '\0';
            printf("Enter age of student:\n");
            scanf("%d", &s.age);
            printf("Enter admission year:\n");
            scanf("%d", &s.admitionYear);
            fseek(stdFP, -sSize, SEEK_CUR); // Move the file pointer back to the record location
            fwrite(&s, sSize, 1, stdFP);    // Write the updated record
            fflush(stdFP);
            system("cls");
            printf("\nRecord updated!\n"); 
            holdScreen();// this is for hold the screen********************************************************
            return;
        }
    }
    printf("Record file not found!\n");
    holdScreen();// this is for hold the screen****************************************************
}
void exitRecord(FILE *stdFP)
{
    fclose(stdFP);

    exit(1);
}
void holdScreen(){
    printf("\n\n\n\t Press any key to continue\n");
    getchar();
}
