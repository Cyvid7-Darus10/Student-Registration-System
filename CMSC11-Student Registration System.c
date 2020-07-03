#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
//declarations
struct student
{
    int studentID;
    char fName[100];
    char lName[100];
    char section[100];
    int hex1;
    int hex2;
    int hex3;
    float ttl;
    char grade[2];
    struct subject *sub;
    struct subject *subs2;
    struct subject *subs3;
};
struct subject
{
    int subjectID;
    char subjectCode[10];
    char subjectTitle[100];
};
struct subject def =
{
    11,
    "CMSC11",
    "Intro to Computer science"
    };
struct subject def2 = {
    1,
    "None",
    "None"};
int student;
//prototypes
int enterPass(struct student p1[]);
int toInteger(char st[]);
void displayinf(struct student *stud, int no);
struct student create(struct student stud, struct student studs[]);
struct subject createSub(struct subject subs, struct subject subj[]);
void updateSub(struct subject subs[]);
void updatestud(struct student stud[]);
void dispSub(struct subject subs, int no);
char toLower(char);
int stringCompare(char *, char *);
void stringCopy(char *, char *);
void enrollStud(struct student s1[], struct subject s2[]);
void deletestud(struct student s1[]);
void dropStud(struct student s1[], struct subject s2[]);
void searchstud(struct student s1[]);
void searchsub(struct subject s2[]);
void delsub(struct subject s2[]);
void readsub(struct subject Sub[]);
void sortarr(struct student cmsc11[]);
void readstud(struct student s1[], struct subject Sub[]);
void writedata(char filename[], struct student s1[]);
void writeSubdata(char filename[], struct subject Sub[]);
void display(struct student *stud);
void dropsub(struct student s1[], struct subject s2[]);
//char *grades(int x);
void maxim(struct student stud[], int no);
void low(struct student stud[], int no);
void aver(struct student stud[], int no);
void grades(struct student stud,float x);
int power(int x,int y);
double sqroot(double square);
void header(void);
void clearSpace(void);
void studBox(void);
void subBox(void);
void enroll1(struct student s1[], struct subject s2[]);
void displaySub(struct subject sub,int no);
void updateSingle(struct student studs[]);
int substring(char s1[], char  s2[]);
void searchsubject(struct subject s2[]);
void menuBox(void);
void gotoxy(int column, int line);
COORD coord = { 0, 0 };
void gotoxy(int x, int y){
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//main
int main(void)
{
    //declarations
    system("COLOR F0");
    int access;
    int num;
    struct student stud[100];
    struct subject Sub[100];
    Sub[0] = def2;
    Sub[1] = def;
    char s1[10];
    char s2[10];
    char s3[10];
    //file reading and writing;

    //for subjects file reading
    char fn[100];
    FILE *subjects;
    subjects = fopen("subjectlist.csv", "r+");
    if (subjects == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    int Subtail;
    for (Subtail = 0; Sub[Subtail].subjectID != 0; Subtail++)
    {
    }
    int i = Subtail; //start of file reading
    while (1)
    {
        if (feof(subjects))
        {
            break;
        }
        fscanf(subjects, "%d, %[^,], %[^\n]", &Sub[i].subjectID, Sub[i].subjectCode, Sub[i].subjectTitle);
        i++;
    }

    //for students
    FILE *Studs;
    Studs = fopen("data.csv", "r+");
    if (Studs == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    i = 0; //start of file reading
    while (1)
    {
        if (feof(Studs))
        {
            break;
        }
        fscanf(Studs, "%d, %[^,], %[^,], %[^,], %d, %d, %d, %[^,], %[^,], %[^\n]s", &stud[i].studentID, stud[i].lName, stud[i].fName, stud[i].section, &stud[i].hex1, &stud[i].hex2, &stud[i].hex3, s1, s2, s3);
        stud[i].ttl = stud[i].hex1 + stud[i].hex2 + stud[i].hex3;
        //grades(stud[i],stud[i].ttl);
        for (Subtail = 0; Sub[Subtail].subjectID != 0; Subtail++)
        {
        }
        for (int j = 0; j < Subtail; j++)
        {
            if (stringCompare(s1, Sub[j].subjectCode) == 0)
            {
                stud[i].sub = &Sub[j];
            }
            if (stringCompare(Sub[j].subjectCode, s2) == 0)
            {
                stud[i].subs2 = &Sub[j];
            }
            if (stringCompare(Sub[j].subjectCode, s3) == 0)
            {
                stud[i].subs3 = &Sub[j];
            }
        }
        i++;
    }
gotoxy(79,14);
printf("%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,187);
gotoxy(79,15);
printf("%c WELCOME! %c",186,186);
gotoxy(79,16);
printf("%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,188);
printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
system("pause");
system("cls");
header();

access = enterPass(stud);
if(access==2){
    system("cls");
    header();
    gotoxy(70,10);
    printf("Access Granted! Welcome ADMIN");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
    system("pause");
    system("cls");

    //main menu
    int mainMenu = 1;

    while (mainMenu != 0) {
        int registerMenu = 1;
        int subjectMenu = 1;
        int studentMenu = 1;
        int searchMenu = 1;
        int displayMenu = 1;
        int importMenu = 1;
        int no;

        int tail;
        for (tail = 0; stud[tail].studentID != 0; tail++)
        {
        }
        int Subtail;
        for (Subtail = 0; Sub[Subtail].subjectID != 0; Subtail++)
        {
        }

        header();
        menuBox();
        gotoxy(12,10);
        printf("1: DISPLAY");
        gotoxy(12,11);
        printf("2: REGISTER");
        gotoxy(12,12);
        printf("3: SEARCH");
        gotoxy(12,13);
        printf("4: IMPORT");
        gotoxy(12,14);
        printf("5: DELETE ALL");
        gotoxy(12,15);
        printf("0: EXIT");
        gotoxy(12,18);
        printf(">>>| ");
        scanf(" %d", &mainMenu);
        switch (mainMenu) {

            case 1:
                //display
                while (displayMenu != 0) {

                    header();
                    clearSpace();
                    menuBox();
                    gotoxy(12,10);
                    printf("1: STUDENT");
                    gotoxy(12,11);
                    printf("2: SUBJECT");
                    gotoxy(12,12);
                    printf("0: EXIT");
                    gotoxy(12,18);
                    printf(">>>| ");
                    scanf(" %d", &displayMenu);
                     switch (displayMenu) {

                        case 1:
                            if (tail == 0)
                            {
                                printf("\n\n\t\t\t\t\t\t\t\t\t");
                                printf("No students found!\n");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                                system("pause");
                                system("cls");
                                break;
                            }
                            studBox();
                            no = 0;
                            for (int i = 0; i < tail; i++)
                            {
                                gotoxy(40,11+i);
                                printf("%c",186);
                                gotoxy(159,11+i);
                                printf("%c",186);
                                gotoxy(43,11+no);
                                printf(" %d", no+1);
                                displayinf(&stud[i], no);
                                no++;
                            }
                            gotoxy(40,11+no);
                            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
                            no++;
                            gotoxy(40,11+no);
                            printf("%c",186);
                            gotoxy(159,11+no);
                            printf("%c",186);
                            maxim(stud, no);
                            no++;
                            gotoxy(40,11+no);
                            printf("%c",186);
                            gotoxy(159,11+no);
                            printf("%c",186);
                            low(stud, no);
                            no++;
                            gotoxy(40,11+no);
                            printf("%c",186);
                            gotoxy(159,11+no);
                            printf("%c",186);
                            aver(stud, no);
                            no++;
                            gotoxy(40,11+no);
                            printf("%c",186);
                            gotoxy(159,11+no);
                            printf("%c",186);
                            gotoxy(40,11+no+1);
                            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            if (Subtail == 0)
                            {
                                printf("\n\n\t\t\t\t\t\t\t\t\t");
                                printf("No records found\n");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                                system("pause");
                                system("cls");
                                break;
                            }
                            subBox();
                            no = 0;
                            for (int i = 1; i < Subtail; i++)
                            {
                                if (Sub[i].subjectID != 0 && Sub[i].subjectID != 1)
                                {
                                    gotoxy(40,10+no);
                                    printf("%c",186);
                                    gotoxy(159,10+no);
                                    printf("%c",186);
                                    gotoxy(43,10+no);
                                    printf(" %d", no+1);
                                    dispSub(Sub[i], no);
                                    no++;
                                }
                            }
                            gotoxy(40,10+no);
                            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                            system("pause");
                            system("cls");
                            break;
                        default:
                            system("cls");
                            break;
                     }
                }

                system("cls");
                break;
            case 2:

                while (registerMenu != 0) {

                    header();
                    clearSpace();
                    menuBox();
                    gotoxy(12,10);
                    printf("1: STUDENT");
                    gotoxy(12,11);
                    printf("2: SUBJECT");
                    gotoxy(12,12);
                    printf("0: EXIT");
                    gotoxy(12,18);
                    printf(">>>| ");
                    scanf(" %d", &registerMenu);
                    switch (registerMenu) {

                        case 1:

                            while (studentMenu != 0) {

                                header();
                                clearSpace();
                                menuBox();
                                gotoxy(12,10);
                                printf("1: Register New Student");
                                gotoxy(12,11);
                                printf("2: Enroll Student");
                                gotoxy(12,12);
                                printf("3: Drop Student");
                                gotoxy(12,13);
                                printf("4: Update Student");
                                gotoxy(12,14);
                                printf("5: Delete Student Record");
                                gotoxy(12,15);
                                printf("0: EXIT");
                                gotoxy(12,18);
                                printf(">>>| ");
                                scanf(" %d", &studentMenu);
                                switch (studentMenu) {

                                    case 1:
                                    //create new student
                                        stud[tail] = create(stud[tail], stud);
                                        stud[tail].sub = &Sub[1];
                                        stud[tail].subs2 = &Sub[0];
                                        stud[tail].subs3 = &Sub[0];
                                        sortarr(stud);
                                        writedata("data.csv", stud);
                                        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                                        system("pause");
                                        system("cls");
                                        break;
                                    case 2:
                                        //enroll
                                        enrollStud(stud, Sub);
                                        writedata("data.csv", stud);
                                        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                                        system("pause");
                                        system("cls");
                                        break;
                                    case 3:
                                        //drop
                                        dropStud(stud, Sub);
                                        writedata("data.csv", stud);
                                        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                                        system("pause");
                                        system("cls");
                                        break;
                                    case 4:
                                        //update
                                        updatestud(stud);
                                        writedata("data.csv", stud);
                                        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                                        system("pause");
                                        system("cls");
                                        break;
                                    case 5:
                                        //delete
                                        deletestud(stud);
                                        sortarr(stud);
                                        writedata("data.csv", stud);
                                        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                                        system("pause");
                                        system("cls");
                                        break;
                                    default:
                                        system("cls");
                                        break;
                                }

                            }

                            system("cls");
                            break;
                        case 2:
                            //subject
                            while (subjectMenu != 0){

                                header();
                                clearSpace();
                                menuBox();
                                gotoxy(12,10);
                                printf("1: Register New Subject");
                                gotoxy(12,11);
                                printf("2: Update Subject");
                                gotoxy(12,12);
                                printf("3: Delete Subject");
                                gotoxy(12,13);
                                printf("0: EXIT");
                                gotoxy(12,18);
                                printf(">>>| ");
                                scanf(" %d", &subjectMenu);

                                switch (subjectMenu) {

                                    case 1:
                                        //new subject
                                        Sub[Subtail] = createSub(Sub[Subtail], Sub);
                                        writeSubdata("subjectlist.csv", Sub);
                                        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                                        system("pause");
                                        system("cls");
                                        break;
                                    case 2:
                                        //update
                                        updateSub(Sub);
                                        writeSubdata("subjectlist.csv", Sub);
                                        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                                        system("pause");
                                        system("cls");
                                        break;
                                    case 3:
                                        //delete
                                        delsub(Sub);
                                        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                                        system("pause");
                                        system("cls");
                                        break;
                                    default:
                                        system("cls");
                                        break;
                                }
                            }
                            system("cls");
                            break;
                        default:
                            system("cls");
                            break;
                    }
                }
                system("cls");
                break;
            case 3:
                //search
                while (searchMenu != 0) {

                    header();
                    clearSpace();
                    menuBox();
                    gotoxy(12,10);
                    printf("1: STUDENT");
                    gotoxy(12,11);
                    printf("2: SUBJECT");
                    gotoxy(12,12);
                    printf("0: EXIT");
                    gotoxy(12,18);
                    printf(">>>| ");
                    scanf(" %d", &searchMenu);
                    switch (searchMenu) {

                        case 1:
                            //student
                            searchstud(stud);
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            //subject
                            searchsub(Sub);
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                            system("pause");
                            system("cls");
                            break;
                        default:
                            system("cls");
                            break;
                    }
                }
                system("cls");
                break;
            case 4:
                //import
                while (importMenu != 0) {

                    header();
                    clearSpace();
                    menuBox();
                    gotoxy(12,10);
                    printf("1: STUDENT");
                    gotoxy(12,11);
                    printf("2: SUBJECT");
                    gotoxy(12,12);
                    printf("0: EXIT");
                    gotoxy(12,18);
                    printf(">>>| ");
                    scanf(" %d", &importMenu);
                    switch (importMenu) {

                        case 1:
                            readstud(stud, Sub);
                            sortarr(stud);
                            writedata("data.csv", stud);
                            writeSubdata("subjectlist.csv", Sub);
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            readsub(Sub);
                            writeSubdata("subjectlist.csv", Sub);
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                            system("pause");
                            system("cls");
                            break;
                        default:
                            system("cls");
                            break;
                    }
                }
                system("cls");
                break;
            case 5:
                deleteAll(stud, Sub);
                writeSubdata("subjectlist.csv",Sub);
                writedata("data.csv",stud);
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                system("pause");
                system("cls");
                break;
            case 0:
                system("cls");
                gotoxy(78,14);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,187);
                gotoxy(78,15);
                printf("%c LOGGED OUT!%c",186,186);
                gotoxy(78,16);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,188);
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
                writeSubdata("subjectlist.csv",Sub);
                writedata("data.csv",stud);
                break;
            default:
                system("cls");
                break;
        }
    }

    fclose(Studs);
    fclose(subjects);
    }else if(access==1){
        system("cls");
        header();
        gotoxy(71,10);
        printf("Access Granted! Welcome %s\n",stud[student].fName);
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
        system("pause");
        system("cls");
        int choice1 = 1;
    while(choice1 != 0){
        header();
        display(&stud[student]);
        menuBox();
        gotoxy(12,10);
        printf("1: Drop Subject");
        gotoxy(12,11);
        printf("2: Enroll Subject");
        gotoxy(12,12);
        printf("3: Update Records");
        gotoxy(12,13);
        printf("4: Display Subjects");
        gotoxy(12,14);
        printf("5: Search Subject");
        gotoxy(12,15);
        printf("0: EXIT");
        gotoxy(12,18);
        printf(">>>| ");
        scanf(" %d",&choice1);
    switch(choice1){
        int no;

        case 1:
            for (int i = 0; i < 20; i++) {
                gotoxy(40,8+i);
                printf("                                                                                                                        ");
            }
            actLog();
            gotoxy(43,8);
            printf("DROP A SUBJECT");
            dropsub(stud,Sub);
            writedata("data.csv",stud);
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
            system("pause");
            system("cls");
            break;
        case 2:
            for (int i = 0; i < 20; i++) {
                gotoxy(40,8+i);
                printf("                                                                                                                        ");
            }
            actLog();
            gotoxy(43,8);
            printf("ENROLL TO A CLASS");
            enroll1(stud,Sub);
            writedata("data.csv",stud);
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
            system("pause");
            system("cls");
            break;
        case 3:
            for (int i = 0; i < 20; i++) {
                gotoxy(40,8+i);
                printf("                                                                                                                        ");
            }
            actLog();
            gotoxy(43,8);
            printf("UPDATE RECORD");
            updateSingle(stud);
            writedata("data.csv",stud);
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
            system("pause");
            system("cls");
            break;
        case 4:
            for (int i = 0; i < 20; i++) {
                gotoxy(40,8+i);
                printf("                                                                                                                        ");
            }
            no = 0;
            actLog();
            gotoxy(43,8);
            printf("DISPLAY ALL SUBJECTS");
            if (Subtail == 0)
            {
                gotoxy(40,10+no);
                printf("No Records Found\n");
                no++;
                break;
            }
            subBox();
            for (int i = 1; i < Subtail; i++)
            {
                if (Sub[i].subjectID != 0 && Sub[i].subjectID != 1)
                {
                    gotoxy(40,10+no);
                    printf("%c",186);
                    gotoxy(159,10+no);
                    printf("%c",186);
                    gotoxy(43,10+no);
                    printf(" %d", no+1);
                    displaySub(Sub[i], no);
                    no++;
                }
            }
            gotoxy(40,10+no);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
            system("pause");
            system("cls");
            break;
        case 5:
            for (int i = 0; i < 20; i++) {
                gotoxy(40,8+i);
                printf("                                                                                                                        ");
            }
            actLog();
            gotoxy(43,8);
            printf("SEARCH");
            searchsubject(Sub);
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            gotoxy(78,14);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,187);
            gotoxy(78,15);
            printf("%c LOGGED OUT!%c",186,186);
            gotoxy(78,16);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,188);
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
            writeSubdata("subjectlist.csv",Sub);
            writedata("data.csv",stud);
            break;
        default:
            system("cls");
            break;
        }
     }
    }else{
        system("cls");
        header();
        gotoxy(75,10);
        printf("Invalid Credentials");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
    }
}

void displayinf(struct student *stud, int no)
{
    gotoxy(51,11+no);
    printf("%d", stud->studentID);
    gotoxy(58,11+no);
    printf("%s,", stud->lName);
    printf(" %s", stud->fName);
    gotoxy(83,11+no);
    printf("  %s", stud->section);
    gotoxy(90,11+no);
    printf(" %s,", stud->sub->subjectCode);
    printf(" %s,", stud->subs2->subjectCode);
    printf(" %s", stud->subs3->subjectCode);
    gotoxy(120,11+no);
    printf("%d     ", stud->hex1);
    printf("  %d     ", stud->hex2);
    printf("  %d  ", stud->hex3);
    gotoxy(144,11+no);
    printf(" %.2f", stud->ttl);
    //gotoxy(153,20+no);
    //printf(" %c", stud->grade);
    if (stud->ttl >= 135) {
        gotoxy(153,11+no);
        printf(" HD\n");
    } else if (stud->ttl >= 120 && stud->ttl < 135) {
        gotoxy(153,11+no);
        printf(" D\n");
    } else if (stud->ttl >= 100 && stud->ttl < 120) {
        gotoxy(153,11+no);
        printf(" P\n");
    } else if (stud->ttl >= 75 && stud->ttl < 100) {
        gotoxy(153,11+no);
        printf(" C\n");
    } else {
        gotoxy(153,11+no);
        printf(" F\n");
    }

}
struct student create(struct student stud, struct student studs[])
{
    actLog();
    gotoxy(43,8);
    printf("REGISTER NEW STUDENT RECORDS");
    for (int m = 0; m < 7; m++) {
        gotoxy(40,10+m);
        printf("%c",186);
        gotoxy(159,10+m);
        printf("%c",186);
    }
    gotoxy(40,17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    reinput:
    gotoxy(43,10);
    printf("Enter a student ID: ");
    scanf(" %d", &stud.studentID);
    int tail;
    for (tail = 0; studs[tail].studentID != 0; tail++)
    {
    }
    for (int i = 0; i < tail; i++)
    {
        if (stud.studentID == studs[i].studentID)
        {
            gotoxy(43,11);
            printf("Student ID already taken enter another one!");
            system("pause");
            gotoxy(43,10);
            printf("                                                                                                              ");
            gotoxy(43,11);
            printf("                                                                                                              ");
            goto reinput;
        }
    }
    gotoxy(43,11);
    printf("Enter Last Name: ");
    scanf(" %99[^\n]s", stud.lName);
    gotoxy(43,12);
    printf("Enter First Name: ");
    scanf(" %99[^\n]s", stud.fName);
    gotoxy(43,13);
    printf("Enter Section: ");
    scanf(" %99[^\n]s", stud.section);
    gotoxy(43,14);
    printf("Enter a score for exam 1: ");
    scanf("%d", &stud.hex1);
    gotoxy(43,15);
    printf("Enter a score for exam 2: ");
    scanf("%d", &stud.hex2);
    gotoxy(43,16);
    printf("Enter a score for exam 3: ");
    scanf("%d", &stud.hex3);
    stud.ttl = (stud.hex1 + stud.hex2 + stud.hex3);
    //grades(stud,stud.ttl);
    return stud;
}
void updatestud(struct student studs[])
{
    int tail, updChoice = 1;
    for (tail = 0; studs[tail].studentID != 0; tail++)
    {
    }
    int num;
    actLog();
    gotoxy(43,8);
    printf("UPDATE STUDENT RECORDS");
    for (int m = 0; m < 7; m++) {
        gotoxy(40,10+m);
        printf("%c",186);
        gotoxy(159,10+m);
        printf("%c",186);
    }
    gotoxy(40,17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(43,10);
    printf("Enter a Student ID to modify: ");
    scanf(" %d", &num);
    for (int i = 0; i <= tail; i++)
    {

        if (num == studs[i].studentID)
        {
            while (updChoice != 0) {
                gotoxy(10,21);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
                gotoxy(10,22);
                printf("%c",186);
                gotoxy(12,22);
                printf("UPDATE MENU");
                gotoxy(37,22);
                printf("%c",186);
                gotoxy(10,23);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
                for (int k =0; k < 7; k++) {
                    gotoxy(10,24+k);
                    printf("%c",186);
                    gotoxy(37,24+k);
                    printf("%c",186);
                }
                gotoxy(10,31);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
                gotoxy(10,32);
                printf("%c",186);
                gotoxy(37,32);
                printf("%c",186);
                gotoxy(10,33);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
                gotoxy(12,24);
                printf("1: Last Name");
                gotoxy(12,25);
                printf("2: First Name");
                gotoxy(12,26);
                printf("3: Section");
                gotoxy(12,27);
                printf("4: Exam 1");
                gotoxy(12,28);
                printf("5: Exam 2");
                gotoxy(12,29);
                printf("6: Exam 3");
                gotoxy(12,30);
                printf("0: Exit");
                gotoxy(12,32);
                printf(">>>| ");
                scanf(" %d", &updChoice);
                gotoxy(12,32);
                printf(">>>| ");
                switch (updChoice) {
                    case 1:
                        gotoxy(43,11);
                        printf("Enter Last Name: ");
                        scanf(" %99[^\n]s", studs[i].lName);
                        break;
                    case 2:
                        gotoxy(43,12);
                        printf("Enter First Name: ");
                        scanf(" %99[^\n]s", studs[i].fName);
                        break;
                    case 3:
                        gotoxy(43,13);
                        printf("Enter Section: ");
                        scanf(" %99[^\n]s", studs[i].section);
                        break;
                    case 4:
                        gotoxy(43,14);
                        printf("Enter a score for exam 1: ");
                        scanf("%d", &studs[i].hex1);
                        break;
                    case 5:
                        gotoxy(43,15);
                        printf("Enter a score for exam 2: ");
                        scanf("%d", &studs[i].hex2);
                        break;
                    case 6:
                        gotoxy(43,16);
                        printf("Enter a score for exam 3: ");
                        scanf("%d", &studs[i].hex3);
                        break;
                    default:
                        break;
                }
            }
            studs[i].ttl = (studs[i].hex1 + studs[i].hex2 + studs[i].hex3);
            //grades(studs[i],studs[i].ttl);
            break;
        }
        if (i == tail - 1)
        {
            gotoxy(43,11);
            printf("Record Not Found!");
            break;
        }
    }
}
struct subject createSub(struct subject subs, struct subject subj[])
{
    actLog();
    gotoxy(43,8);
    printf("REGISTER NEW SUBJECT RECORDS");
    gotoxy(40,10);
    printf("%c",186);
    gotoxy(159,10);
    printf("%c",186);
    gotoxy(40,11);
    printf("%c",186);
    gotoxy(159,11);
    printf("%c",186);
    gotoxy(40,12);
    printf("%c",186);
    gotoxy(159,12);
    printf("%c",186);
    gotoxy(40,13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    reinput:
        gotoxy(43,10);
        printf("                                                                                        ");
        gotoxy(43,10);
        printf("Enter a subject ID: ");
        scanf(" %d", &subs.subjectID);
        int tail;
        for (tail = 0; subj[tail].subjectID != 0; tail++)
        {
        }
        for (int i = 0; i < tail; i++)
        {
            if (subs.subjectID == subj[i].subjectID)
            {
                gotoxy(43,11);
                printf("                                                                                        ");
                gotoxy(43,11);
                printf("Subject ID already taken enter another one!\t\t");
                system("pause");
                gotoxy(43,10);
                printf("                                                                                                              ");
                gotoxy(43,11);
                printf("                                                                                                              ");
                goto reinput;
            }
        }
    reinput1:
    gotoxy(43,11);
    printf("                                                                                        ");
    gotoxy(43,11);
    printf("Enter a subject code: ");
    scanf(" %99[^\n]s", subs.subjectCode);
    for (tail = 0; subj[tail].subjectID != 0; tail++)
    {
    }
    for (int i = 0; i < tail; i++)
    {
        if (stringCompare(subs.subjectCode, subj[i].subjectCode) == 0)
        {

            gotoxy(43,12);
            printf("                                                                                        ");
            gotoxy(43,12);
            printf("Subject ID already taken enter another one!\t\t");
            system("pause");
            gotoxy(43,12);
            printf("                                                                                                              ");
            gotoxy(43,12);
            printf("                                                                                                              ");
            goto reinput1;
        }
    }
    gotoxy(43,12);
    printf("                                                                                        ");
    gotoxy(43,12);
    printf("Enter a subject title: ");
    scanf(" %99[^\n]s", subs.subjectTitle);
    return subs;
}
void updateSub(struct subject subs[])
{
    char a[100];
    int num, subChoice = 1;
    int Subtail;
    for (Subtail = 0; subs[Subtail].subjectID != 0; Subtail++)
    {
    }
    actLog();
    gotoxy(43,8);
    printf("UPDATE SUBJECT RECORDS");
    gotoxy(40,10);
    printf("%c",186);
    gotoxy(159,10);
    printf("%c",186);
    gotoxy(40,11);
    printf("%c",186);
    gotoxy(159,11);
    printf("%c",186);
    gotoxy(40,12);
    printf("%c",186);
    gotoxy(159,12);
    printf("%c",186);
    gotoxy(40,13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(43,10);
    printf("Enter a subject ID to modify: ");
    scanf(" %d", &num);
    for (int i = 0; i < Subtail; i++)
    {

        if (num == subs[i].subjectID)
        {
             while (subChoice != 0) {
                gotoxy(10,21);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
                gotoxy(10,22);
                printf("%c",186);
                gotoxy(12,22);
                printf("UPDATE MENU");
                gotoxy(37,22);
                printf("%c",186);
                gotoxy(10,23);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
                for (int k =0; k < 3; k++) {
                    gotoxy(10,24+k);
                    printf("%c",186);
                    gotoxy(37,24+k);
                    printf("%c",186);
                }
                gotoxy(10,27);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
                gotoxy(10,28);
                printf("%c",186);
                gotoxy(37,28);
                printf("%c",186);
                gotoxy(10,29);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
                gotoxy(12,24);
                printf("1: Subject Code");
                gotoxy(12,25);
                printf("2: Subject Title");
                gotoxy(12,26);
                printf("0: Exit");
                gotoxy(12,28);
                printf(">>>| ");
                scanf(" %d", &subChoice);
                gotoxy(12,28);
                printf(">>>| ");
                switch (subChoice) {
                    case 1:
                        reinputz:
                        gotoxy(43,11);
                        printf("Enter a new subject code: ");
                        scanf(" %99[^\n]s", a);
                        gotoxy(43,12);
                        printf("                                                                                                              ");
                        int tail,cntr=0;
                        for(tail=0;subs[tail].subjectID!=0;tail++){
                        }
                                    for (int j = 0; j < tail; j++)
                                    {
                                        if (stringCompare(subs[j].subjectCode,a) == 0)
                                        {
                                            gotoxy(43,12);
                                            printf("Subject ID already taken enter another one!\t\t");
                                            cntr++;
                                            system("pause");
                                            gotoxy(43,12);
                                            printf("                                                                                                              ");
                                            gotoxy(43,11);
                                            printf("                                                                                                              ");
                                            goto reinputz;
                                        }
                                    }
                                    if(cntr==0){
                                        stringCopy(a,subs[i].subjectCode);
                                        break;
                                    }
                            break;
                    case 2:
                        gotoxy(43,12);
                        printf("Enter a new subject title: ");
                        scanf(" %99[^\n]s", subs[i].subjectTitle);
                        break;
                    default:
                        break;
                }
            }
            break;
        }
        if (i == Subtail - 1)
        {
            gotoxy(43,11);
            printf("Record Not Found!");
            break;
        }
    }
}
void dispSub(struct subject subs, int no)
{
    gotoxy(50,10+no);
    printf("%d\t\t", subs.subjectID);
    gotoxy(64,10+no);
    printf("%s\t\t", subs.subjectCode);
    gotoxy(80,10+no);
    printf("%s\n", subs.subjectTitle);
}
int stringCompare(char s1[], char s2[])
{
    int i = 0;
    int cnt = 0;
    while (s1[i] != '\0' || s2[i] != '\0')
    {
        if (toLower(s1[i]) > toLower(s2[i]))
        {
            return 1;
            cnt++;
            break;
        }
        else if (toLower(s1[i]) < toLower(s2[i]))
        {
            return -1;
            cnt++;
            break;
        }
        i++;
    }
    if (cnt == 0)
    {
        return 0;
    }
}
char toLower(char x)
{
    int y = (int)x;
    if (x <= 'Z' && x >= 'A')
    {
        y = y + 32;
    }
    return (char)y;
}
void enrollStud(struct student s1[], struct subject s2[])
{
    char id[100];
    int num;
    int Subtail;
    for (Subtail = 0; s2[Subtail].subjectID != 0; Subtail++)
    {
    }
    int tail;
    for (tail = 0; s1[tail].studentID != 0; tail++)
    {
    }
    actLog();
    gotoxy(43,8);
    printf("ENROLL STUDENT");
    gotoxy(40,10);
    printf("%c",186);
    gotoxy(159,10);
    printf("%c",186);
    gotoxy(40,11);
    printf("%c",186);
    gotoxy(159,11);
    printf("%c",186);
    gotoxy(40,12);
    printf("%c",186);
    gotoxy(159,12);
    printf("%c",186);
    gotoxy(40,13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(43,10);
    printf("Enter a student ID you want to enroll: ");
    scanf("%d", &num);
    for (int i = 0; i < tail; i++)
    {
        if (num == s1[i].studentID)
        {
            gotoxy(43,11);
            printf("Enter a subject code: ");
            scanf(" %99[^\n]s", id);
            for (int j = 0; j < Subtail; j++)
            {
                if (stringCompare(id, s2[j].subjectCode) == 0)
                {
                    if (stringCompare(s1[i].sub->subjectCode, s2[j].subjectCode) == 0 || stringCompare(s1[i].subs2->subjectCode, s2[j].subjectCode) == 0 || stringCompare(s1[i].subs3->subjectCode, s2[j].subjectCode) == 0)
                    {
                        gotoxy(43,12);
                        printf("Student already enrolled in the subject!");
                        break;
                    }
                    if (s1[i].sub->subjectID == 1)
                    {
                        s1[i].sub = &s2[j];
                        gotoxy(43,12);
                        printf("Successfully Enrolled!");
                        break;
                    }
                    else if (s1[i].subs2->subjectID == 1)
                    {
                        s1[i].subs2 = &s2[j];
                        gotoxy(43,12);
                        printf("Successfully Enrolled!");
                        break;
                    }
                    else if (s1[i].subs3->subjectID == 1)
                    {
                        s1[i].subs3 = &s2[j];
                        gotoxy(43,12);
                        printf("Successfully Enrolled!");
                        break;
                    }
                    else
                    {
                        gotoxy(43,12);
                        printf("No other available slots!");
                        break;
                    }
                }
                if (j == Subtail - 1)
                {
                    gotoxy(43,12);
                    printf("Subject Not Found!");
                    break;
                }
            }
            break;
        }
        if (i == tail - 1)
        {
            gotoxy(43,12);
            printf("Record Not Found!");
            break;
        }
    }
}
void deletestud(struct student s1[])
{
    int num;
    int limit,cnt=0;
    int tail;
    for (tail = 0; s1[tail].studentID != 0; tail++)
    {
    }
    actLog();
    gotoxy(43,8);
    printf("DELETE STUDENT RECORD");
    gotoxy(40,10);
    printf("%c",186);
    gotoxy(159,10);
    printf("%c",186);
    gotoxy(40,11);
    printf("%c",186);
    gotoxy(159,11);
    printf("%c",186);
    gotoxy(40,12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(43,10);
    printf("Enter a student ID you want to delete: ");
    scanf("%d", &num);
    for (int i = 0; i < tail; i++)
    {
        if (num == s1[i].studentID)
        {
            limit = i;
            cnt++;
            break;
        }
        if (i == tail - 1)
        {
            gotoxy(43,11);
            printf("Student Not Found!");
            break;
        }
    }
    if(cnt>0){
        s1[limit].studentID = 0;
        for (int j = limit; j < tail-1; j++)
        {
            s1[j] = s1[j + 1];
        }
        s1[tail-1].studentID = 0;
        gotoxy(43,11);
        printf("Successfully Deleted Student Record!");
    }
}
void searchstud(struct student s1[])
{
    int tail, no = 0,num=0, clear = 0;
    for (tail = 0; s1[tail].studentID != 0; tail++)
    {
    }
    char a[100];
    actLog();
    gotoxy(43,8);
    printf("SEARCH STUDENT RECORD");
    gotoxy(40,10);
    printf("%c",186);
    gotoxy(159,10);
    printf("%c",186);
    no++;
    gotoxy(40,10+no);
    printf("%c",186);
    gotoxy(159,10+no);
    printf("%c",186);
    gotoxy(40,10+no+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(43,10);
    printf("Enter Last Name: ");
    scanf(" %99[^\n]s", a);
    for (int i = 0; i < tail; i++)
    {
        if (stringCompare(a, s1[i].lName) == 0)
        {
            for (int z=0; z<10 && clear == 0; z++) {
                gotoxy(40,8+z);
                printf("                                                                                                                        ");
            }
            clear++;
            no++;
            studBox();
            gotoxy(43,9+no);
            printf(" %d", num+1);
            displayinf(&s1[i], no-2);
            gotoxy(40,9+no);
            printf("%c",186);
            gotoxy(159,9+no);
            printf("%c",186);
            num++;
        }
    }
    if (num==0)
    {
        gotoxy(43,10+no);
        printf("Student Not Found!\n");
    } else {
        gotoxy(40,9+no+1);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    }
}
void delsub(struct subject s2[])
{
    struct subject temp;
    int num, no = 0;
    int limit=0;
    int Subtail;
    for (Subtail = 0; s2[Subtail].subjectID != 0; Subtail++)
        ;
    char a[100];
    actLog();
    gotoxy(43,8);
    printf("DELETE SUBJECT RECORD");
    gotoxy(40,10+no);
    printf("%c",186);
    gotoxy(159,10+no);
    printf("%c",186);
    no++;
    gotoxy(40,10+no);
    printf("%c",186);
    gotoxy(159,10+no);
    printf("%c",186);
    gotoxy(40,10+no+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(43,10);
    printf("Enter a subject code you want to delete: ");
    scanf(" %99[^\n]s", a);
    if(stringCompare(a,"none")==0){
            gotoxy(43,10+no);
            printf("Not Found!\n");
            goto lol;
        }
     if(stringCompare(a,"cmsc11")==0){
            gotoxy(43,10+no);
            printf("Unable to delete");
            goto lol;
        }
    for (int i = 0; i < Subtail; i++)
    {
        if (stringCompare(s2[i].subjectCode,a) == 0)
        {
            limit = i;
            break;
        }else{
            limit++;
        }
    }

        if (limit == Subtail)
        {
            gotoxy(43,10+no);
            printf("Not Found!\n");
        }else{
            gotoxy(43,10+no);
            printf("Subject Deleted Successfully");
            s2[limit] = def2;
            writeSubdata("subjectlist.csv",s2);
        }
        lol:
        printf("");
}
void searchsub(struct subject s2[])
{
    int Subtail, choice, found = 0;
    for (Subtail = 0; s2[Subtail].subjectID != 0; Subtail++)
    {
    }
    char a[100];
    int no = 0, clear = 0, num = 0;
    actLog();
    gotoxy(43,8);
    printf("SEARCH SUBJECT RECORD");
    gotoxy(40,10+no);
    printf("%c",186);
    gotoxy(159,10+no);
    printf("%c",186);
    no++;
    gotoxy(40,10+no);
    printf("%c",186);
    gotoxy(159,10+no);
    printf("%c",186);
    gotoxy(40,10+no+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(43,10);
    printf("Enter a subject code you want to search: ");
    scanf(" %99[^\n]s", a);
    for (int i = 0; i < Subtail; i++)
    {
        if (stringCompare(a, s2[i].subjectCode) == 0||substring(s2[i].subjectCode,a)==1)
        {
            for (int z=0; z<10 && clear == 0; z++) {
                gotoxy(40,8+z);
                printf("                                                                                                                        ");
            }
            clear++;
            no++;
            subBox();
            gotoxy(43,8+no);
            printf(" %d", num+1);
            dispSub(s2[i], no-2);
            gotoxy(40,8+no);
            printf("%c",186);
            gotoxy(159,8+no);
            printf("%c",186);
            num++;
        }
        if (i == Subtail - 1&&num==0)
        {
            found = 1;
            gotoxy(43,10+no);
            printf("Subject Not Found!");
            printf("\t\tDo you want to [1]Create subject [2]Import Data [0]Exit | ");
            scanf(" %d", &choice);
            if (choice == 1)
            {
                s2[Subtail] = createSub(s2[Subtail], s2);
                writeSubdata("subjectlist.txt", s2);
            }
            if (choice == 2)
            {
                readsub(s2);
                writeSubdata("subjectlist.txt", s2);
            }
            break;
        }
    }
    if (found == 0) {
            gotoxy(40,8+no+1);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
            printf("\n\n\n\n\n\n\n\n\n");
        }
}
void dropStud(struct student s1[], struct subject s2[])
{
    char id[100];
    int num;
    int tail;
    for (tail = 0; s1[tail].studentID != 0; tail++)
    {
    }
    actLog();
    gotoxy(43,8);
    printf("DROP STUDENT");
    gotoxy(40,10);
    printf("%c",186);
    gotoxy(159,10);
    printf("%c",186);
    gotoxy(40,11);
    printf("%c",186);
    gotoxy(159,11);
    printf("%c",186);
    gotoxy(40,12);
    printf("%c",186);
    gotoxy(159,12);
    printf("%c",186);
    gotoxy(40,13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(43,10);
    printf("Enter a student ID: ");
    scanf("%d", &num);
    for (int i = 0; i < tail; i++)
    {
        if (num == s1[i].studentID)
        {
            gotoxy(43,11);
            printf("Enter a subject you want to drop(Subject Code): ");
            scanf(" %99[^\n]s", id);
            if (stringCompare(id, def.subjectCode) == 0)
            {
                gotoxy(43,12);
                printf("Unable to drop in the subject!");
                break;
            }
            if (stringCompare(id, s1[i].sub->subjectCode) == 0)
            {
                s1[i].sub = s1[i].subs2;
                s1[i].subs2 = s1[i].subs3;
                s1[i].subs3 = &s2[0];
                gotoxy(43,12);
                printf("Drop Success!");
                break;
            }
            if (stringCompare(id, s1[i].subs2->subjectCode) == 0)
            {
                s1[i].subs2 = s1[i].subs3;
                s1[i].subs3 = &s2[0];
                gotoxy(43,12);
                printf("Drop Success!");
                break;
            }
            if (stringCompare(id, s1[i].subs3->subjectCode) == 0)
            {
                s1[i].subs3 = &s2[0];
                gotoxy(43,12);
                printf("Drop Success!");
                break;
            }
            else
            {
                gotoxy(43,12);
                printf("Student not enrolled in the subject!");
                break;
            }
        }
        if (i == tail - 1)
        {
            gotoxy(43,12);
            printf("Record Not Found!");
            break;
        }
    }
}
void readsub(struct subject Sub[])
{
    char fn[100];
    char s1[100];
    char s2[100];
    int s3;
    FILE *subjects;
    actLog();
    gotoxy(43,8);
    printf("IMPORT SUBJECT RECORDS");
    gotoxy(40,10);
    printf("%c",186);
    gotoxy(159,10);
    printf("%c",186);
    gotoxy(40,11);
    printf("%c",186);
    gotoxy(159,11);
    printf("%c",186);
    gotoxy(40,12);
    printf("%c",186);
    gotoxy(159,12);
    printf("%c",186);
    gotoxy(40,13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(43,10);
    printf("Enter file name: ");
    scanf(" %99[^\n]", fn);
    subjects = fopen(fn, "r+");
    if (subjects == NULL)
    {
        gotoxy(43,11);
        printf("Error Opening File!");
        goto skips;
    }
    int Subtail;
    for (Subtail = 0; Sub[Subtail].subjectID != 0; Subtail++)
    {
    }
    int i = Subtail ; //start of file reading
    while (1)
    {
        end:
        if (feof(subjects))
        {
            break;
        }
        fscanf(subjects, "%d, %[^,], %[^\n]s", &s3, s1, s2);
        for (int j = 0; j < Subtail ; j++)
        {
            if (s3 == Sub[j].subjectID || stringCompare(s1,Sub[j].subjectCode) == 0)
            {
                gotoxy(43,12);
                printf("Error some subject is already registered!");
                goto end;
            }
        }
        Sub[i].subjectID = s3;
        stringCopy(s1, Sub[i].subjectCode);
        stringCopy(s2, Sub[i].subjectTitle);
        Subtail++;
        i++;
        }
        Sub[i].subjectID = 0;
        skips:
        printf("");
}
void readstud(struct student s1[], struct subject Sub[])
{ //unfinished
    int num, Subtail,choice;
    char ss1[100];
    char s2[100];
    char s3[100];
    char fn[100];
    FILE *stud;
    actLog();
    gotoxy(43,8);
    printf("IMPORT STUDENT RECORDS");
    for (int m = 0; m < 5; m++) {
        gotoxy(40,10+m);
        printf("%c",186);
        gotoxy(159,10+m);
        printf("%c",186);
    }
    gotoxy(40,15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(43,10);
    printf("Enter file name: ");
    scanf(" %99[^\n]", fn);
    stud = fopen(fn, "r+");
    if (stud == NULL)
    {
        gotoxy(43,11);
        printf("Error Opening File!");
        goto skips;
    }
    int tail,i;
    for (tail = 0; s1[tail].studentID != 0; tail++)
    {
    }

    i = tail;
    while (1)
    {
        if (feof(stud))
        {
            skips:
            break;
        }
        rerun:
        fscanf(stud, " %d, %[^,], %[^,], %[^,], %d, %d, %d, %[^,], %[^,], %[^\n]", &s1[i].studentID, s1[i].lName, s1[i].fName, s1[i].section, &s1[i].hex1, &s1[i].hex2, &s1[i].hex3, ss1, s2, s3);
        s1[i].ttl = s1[i].hex1 + s1[i].hex2 + s1[i].hex3;
        //grades(s1[i],s1[i].ttl);
        for(int k = 0;k<tail;k++){
            if(s1[i].studentID==s1[k].studentID){
                gotoxy(43,12);
                printf("                                                                                                                            ");
                gotoxy(43,12);
                printf("The student ID is already registered!",i+1-tail);
                s1[i].studentID=0;
                goto rerun;
            }
        }
        int err1=0,err2=0,err3=0;
        recheck:
        err1=0,err2=0,err3=0;
        for (Subtail = 0; Sub[Subtail].subjectID != 0; Subtail++)
        {
        }
        int checker = 0;
        if(stringCompare(ss1,"CMSC11")==0||stringCompare(s2,"CMSC11")==0||stringCompare(s3,"CMSC11")==0){
            checker++;
        }
        if(checker==0){
            int determiner = 0;
            gotoxy(43,12);
            printf("Student Not Enrolled in CMSC11!\t\t");
            int enroll;
            printf("[1]Enroll [0]Exit | ");
            scanf("%d",&enroll);
            if(enroll==1){
                if(stringCompare(ss1,"None")==0){
                    stringCopy("CMSC11",ss1);
                    determiner++;
                }else if(stringCompare(s2,"None")==0){
                    stringCopy("CMSC11",s2);
                    determiner++;
                }else if(stringCompare(s3,"None")==0){
                    stringCopy("CMSC11",s3);
                    determiner++;
                }
                if(determiner==0){
                    gotoxy(43,13);
                    printf("                                                                                                ");
                    gotoxy(43,13);
                    printf("No slots for enrollment left!");
                    s1[i].studentID=0;
                    goto rerun;
                }
            }else{
                s1[i].studentID=0;
                goto skip;
            }
        }
            for (int j = 0; j < Subtail; j++)
                {
                    if (stringCompare(Sub[j].subjectCode, ss1) == 0)
                    {
                        s1[i].sub = &Sub[j];
                        err1++;
                    }
                    if (stringCompare(Sub[j].subjectCode, s2) == 0)
                    {
                        if(stringCompare(ss1,s2)==0){
                            s1[i].subs2 = &Sub[0];
                            err2++;
                        }else{
                            s1[i].subs2 = &Sub[j];
                            err2++;
                        }
                    }
                    if (stringCompare(Sub[j].subjectCode, s3) == 0)
                    {
                        if(stringCompare(ss1,s3)==0||stringCompare(s3,s2)==0){
                            s1[i].subs3 = &Sub[0];
                            err3++;
                        }else{
                            s1[i].subs3 = &Sub[j];
                            err3++;
                        }
                    }
                }
                if(err1==0||err2==0||err3==0){
                    if(err1==0){
                        for (int i = 0; i < 20; i++) {
                            gotoxy(40,8+i);
                            printf("                                                                                                                        ");
                        }
                        actLog();
                        gotoxy(43,8);
                        printf("IMPORT STUDENT RECORDS");
                        for(int k = 0; k < 5; k++) {
                             gotoxy(40,10+k);
                            printf("%c",186);
                            gotoxy(159,10+k);
                            printf("%c",186);
                        }
                        gotoxy(40,15);
                        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
                        gotoxy(43,10);
                        printf("Error! Subject %s Unknown!",ss1);
                        printf("\t\t\t[1]Create a subject [2]Import [0]Exit | ");
                        scanf(" %d",&choice);
                        if(choice==0){
                            stringCopy("none",ss1);
                            goto recheck;
                        }
                        if(choice==1){
                        for (int i = 0; i < 20; i++) {
                            gotoxy(40,8+i);
                            printf("                                                                                                                           ");
                        }
                        Sub[Subtail]=createSub(Sub[Subtail],Sub);
                        goto recheck;
                        }
                        if(choice==2){
                            for (int i = 0; i < 20; i++) {
                                gotoxy(40,8+i);
                                printf("                                                                                                                           ");
                            }
                            readsub(Sub);
                            writeSubdata("subjectlist.csv",Sub);
                            goto recheck;
                        }
                        }
                        if(err2==0){
                            for (int i = 0; i < 20; i++) {
                                gotoxy(40,8+i);
                                printf("                                                                                                                           ");
                            }
                        actLog();
                        gotoxy(43,8);
                        printf("IMPORT STUDENT RECORDS");
                         for(int k = 0; k < 5; k++) {
                             gotoxy(40,10+k);
                            printf("%c",186);
                            gotoxy(159,10+k);
                            printf("%c",186);
                        }
                        gotoxy(40,15);
                        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
                        gotoxy(43,10);
                        printf("Error! Subject %s Unknown",s2);
                        printf("\t\t\t[1]Create a subject [2]Import [0]Exit | ");
                        scanf(" %d",&choice);
                        if(choice==0){
                           stringCopy("none",s2);
                            goto recheck;
                        }
                        if(choice==1){
                        for (int i = 0; i < 20; i++) {
                            gotoxy(40,8+i);
                            printf("                                                                                                                           ");
                        }
                        Sub[Subtail]=createSub(Sub[Subtail],Sub);
                        goto recheck;
                        }
                        if(choice==2){
                            for (int i = 0; i < 20; i++) {
                                gotoxy(40,8+i);
                                printf("                                                                                                                           ");
                            }
                            readsub(Sub);
                            writeSubdata("subjectlist.csv",Sub);
                            goto recheck;
                        }
                    }
                    if(err3==0){
                        for (int i = 0; i < 20; i++) {
                            gotoxy(40,8+i);
                            printf("                                                                                                                        ");
                        }
                        actLog();
                        gotoxy(43,8);
                        printf("IMPORT STUDENT RECORDS");
                         for(int k = 0; k < 5; k++) {
                             gotoxy(40,10+k);
                            printf("%c",186);
                            gotoxy(159,10+k);
                            printf("%c",186);
                        }
                        gotoxy(40,15);
                        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
                        gotoxy(43,10);
                        printf("Error! Subject %s Unknown!",s3);
                        printf("\t\t\t[1]Create a subject [2]Import [0]Exit | ");
                        scanf(" %d",&choice);
                        if(choice==0){
                            stringCopy("none",s3);
                            goto recheck;
                        }
                        if(choice==1){
                        for (int i = 0; i < 20; i++) {
                            gotoxy(40,8+i);
                            printf("                                                                                                                           ");
                        }
                        Sub[Subtail]=createSub(Sub[Subtail],Sub);
                        goto recheck;
                        }
                        if(choice==2){
                            for (int i = 0; i < 20; i++) {
                                gotoxy(40,8+i);
                                printf("                                                                                                                           ");
                            }
                            readsub(Sub);
                            writeSubdata("subjectlist.csv",Sub);
                            goto recheck;
                        }
                    }
                }
            skip:
            i++;
        }
    }
void sortarr(struct student cmsc11[])
{
    int tail;
    for (tail = 0; cmsc11[tail].studentID != 0; tail++)
    {
    }
    int j = 0;
    struct student temp;
    for (int i = 0; i < tail; i++)
    {
        for (int j = 0; j < tail; j++)
        {
            if (stringCompare(cmsc11[i].lName, cmsc11[j].lName) == -1)
            {
                temp = cmsc11[j];
                cmsc11[j] = cmsc11[i];
                cmsc11[i] = temp;
            }
        }
    }
}
void writedata(char filename[], struct student s1[])
{
    FILE *fpointer;
    fpointer = fopen(filename, "w+");
    int tail;
    for (tail = 0; s1[tail].studentID != 0; tail++)
    {
    }
    for (int i = 0; i < tail; i++)
    {
        fprintf(fpointer, "%d, %s, %s, %s, %d, %d, %d, %s, %s, %s\n", s1[i].studentID, s1[i].lName, s1[i].fName, s1[i].section, s1[i].hex1, s1[i].hex2, s1[i].hex3, s1[i].sub->subjectCode, s1[i].subs2->subjectCode, s1[i].subs3->subjectCode);
    }

    fclose(fpointer);
}
void writeSubdata(char filename[], struct subject Sub[])
{
    FILE *fpointer;
    fpointer = fopen(filename, "w+");
    int Subtail;
    for (Subtail = 0; Sub[Subtail].subjectID != 0; Subtail++)
    {
    }
    for (int i = 2; i < Subtail; i++)
    {
        fprintf(fpointer, "%d, %s, %s\n", Sub[i].subjectID, Sub[i].subjectCode, Sub[i].subjectTitle);
    }
    fclose(fpointer);
}
void stringCopy(char src[], char dest[])
{
    int size;
    for (size = 0; src[size] != '\0'; size++)
    {
    }
    int size2;
    for (size2 = 0; dest[size2] != '\0'; size2++)
    {
    }
    for (int i = 0; i < size2; i++)
    {
        dest[i]='\0';
    }
    for (int i = 0; i < size; i++)
    {
        dest[i] = src[i];
    }
}
void maxim(struct student stud[], int no){
    int tail, max1 = 0, max2 = 0, max3 = 0;
    for(tail = 0; stud[tail].studentID != 0; tail++){
    }
    for(int i = 0; i < tail; i++){
        if(max1 < stud[i].hex1){
            max1 = stud[i].hex1;
        }
    }
    for(int i = 0; i < tail; i++){
        if(max2 < stud[i].hex2){
            max2 = stud[i].hex2;
        }
    }
    for(int i = 0; i < tail; i++){
        if(max3 < stud[i].hex3){
            max3 = stud[i].hex3;
        }
    }
    gotoxy(108, 11+no);
    printf("HIGHEST");
    gotoxy(120,11+no);
    printf("%d  ", max1);
    printf("     %d  ", max2);
    printf("     %d  ", max3);
}
void low(struct student stud[], int no){
    int tail,low1=stud[0].hex1,low2=stud[0].hex2,low3=stud[0].hex3;
    for(tail=0;stud[tail].studentID!=0;tail++){
    }
    for(int i = 0;i<tail;i++){
        if(low1>stud[i].hex1){
            low1=stud[i].hex1;
        }
    }
    for(int i = 0;i<tail;i++){
        if(low2>stud[i].hex2){
            low2=stud[i].hex2;
        }
    }
    for(int i = 0;i<tail;i++){
        if(low3>stud[i].hex3){
            low3=stud[i].hex3;
        }
    }
    gotoxy(109, 11+no);
    printf("LOWEST");
    gotoxy(120,11+no);
    printf("%d  ", low1);
    printf("     %d  ", low2);
    printf("     %d  ", low3);
}
void aver(struct student stud[], int no){
    int tail;
    float sum1=0,sum2=0,sum3=0;
    double std1=0,std2=0,std3=0;
    for(tail=0;stud[tail].studentID!=0;tail++){
    }
    for(int i = 0;i<tail;i++){
        sum1=sum1+stud[i].hex1;
    }
    for(int i = 0;i<tail;i++){
        sum2=sum2+stud[i].hex2;
    }
    for(int i = 0;i<tail;i++){
        sum3=sum3+stud[i].hex3;
    }
    gotoxy(108, 11+no);
    printf("AVERAGE");
    gotoxy(118,11+no);
    printf("%.3f    ", sum1/(tail));
    gotoxy(127,11+no);
    printf("%.3f    ", sum2/(tail));
    gotoxy(137,11+no);
    printf("%.3f", sum3/(tail));

    for(int i = 0;i<tail;i++){
        std1+=power(stud[i].hex1-(sum1/tail),2);
    }
    for(int i = 0;i<tail;i++){
        std2+=power(stud[i].hex2-(sum2/tail),2);
    }
    for(int i = 0;i<tail;i++){
        std3+=power(stud[i].hex3-(sum3/tail),2);
    }
    gotoxy(97, 12+no);
    printf("STANDARD DEVIATION");
    gotoxy(118,12+no);
    printf("%.3lf    ", sqroot(std1/tail));
    gotoxy(127,12+no);
    printf("%.3lf     ", sqroot(std2/tail));
    gotoxy(137,12+no);
    printf("%.3lf", sqroot(std3/tail));
}
int power(int x,int y)
{
    int num = x;
    for(int i = 1;i<y;i++){
        num=num*x;
    }
    return num;
}
double sqroot(double square)
{
    double rt=square/3;
    int i;
    if (square <= 0) return 0;
    for (i=0; i<32; i++)
        rt = (rt + square / rt) / 2;
    return rt;
}
void header(void) {
    gotoxy(10,2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(10,3);
    printf("%c",186);
    gotoxy(71,3);
    printf("STUDENT REGISTRATION SYSTEM\n");
    gotoxy(159,3);
    printf("%c",186);
    gotoxy(10,4);
    printf("%c",186);
    gotoxy(40,4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(159,4);
    printf("%c",186);
    gotoxy(10,5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c Pastelero, Cyrus David | Sanico, Joshua | Valde, Carl Michael | BSCS | AY: 2019 - 2020 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185,204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(40,6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}
void studBox(void) {
    gotoxy(40,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(40,8);
    printf("%c",186);
    gotoxy(159,8);
    printf("%c",186);
    gotoxy(40,9);
    printf("%c",186);
    gotoxy(159,9);
    printf("%c",186);
    gotoxy(43,8);
    printf("No.");
    gotoxy(49,8);
    printf("STUDENT");
    gotoxy(49,9);
    printf("  ID");
    gotoxy(67,8);
    printf("NAME");
    gotoxy(82,8);
    printf("SECTION");
    gotoxy(94,8);
    printf("SUBJECTS ENROLLED");
    gotoxy(127,8);
    printf("SCORES");
    gotoxy(115,9);
    printf("    HEX1     HEX2     HEX3");
    gotoxy(144,8);
    printf(" TOTAL");
    gotoxy(152,8);
    printf("GRADE");
    gotoxy(40,10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
}
void subBox(void) {
    gotoxy(40,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(40,8);
    printf("%c",186);
    gotoxy(159,8);
    printf("%c",186);
    gotoxy(43,8);
    printf("No.");
    gotoxy(50,8);
    printf("SUBJECT ID");
    gotoxy(64,8);
    printf("SUBJECT CODE");
    gotoxy(80,8);
    printf("SUBJECT TITLE");
    gotoxy(40,9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
}
void clearSpace(void) {
    for (int i = 0; i < 7; i++) {
        gotoxy(12,10+i);
        printf("                         ");
    }
    gotoxy(12,18);
    printf("                         ");
}
void menuBox(void) {
    gotoxy(10,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(10,8);
    printf("%c",186);
    gotoxy(12,8);
    printf("MENU");
    gotoxy(37,8);
    printf("%c",186);
    gotoxy(10,9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    for (int k =0; k < 7; k++) {
        gotoxy(10,10+k);
        printf("%c",186);
        gotoxy(37,10+k);
        printf("%c",186);
    }
    gotoxy(10,17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    gotoxy(10,18);
    printf("%c",186);
    gotoxy(37,18);
    printf("%c",186);
    gotoxy(10,19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}
void actLog(void) {
    gotoxy(40,7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(40,8);
    printf("%c",186);
    gotoxy(159,8);
    printf("%c",186);
    gotoxy(40,9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);

}
int toInteger(char st[])
{
    int i = 0;
    int cntr = 0;
    int x;
    while(st[i]!='\0'){
            if(st[i]=='-'){
                i++;
            }
     x = st[i] -'0';
     cntr = cntr*10;
     cntr = cntr+x;
     i++;
    }
    if (st[0]=='-'){
        return cntr*-1;
    }else{
        return cntr;
    }
}
int enterPass(struct student p1[])
{
    char userName[100];
    char userPass[100];
    char ch;
    int i, k;
    for( i = 0;p1[i].studentID!=0;i++){
    }
    gotoxy(74,10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    for(int f = 0; f < 5; f++) {
        gotoxy(74,11+f);
        printf("%c",186);
        gotoxy(95,11+f);
        printf("%c",186);
    }
    gotoxy(74,16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(76,12);
    printf("USERNAME: ");
    scanf(" %99[^\n]s",userName);
    gotoxy(76,14);
    printf("PASSWORD: ");
        int h = 0;
        skip:
        while(1){
            ch =getch();

            if(ch==8){
                if(h<=0){
                    h = 0;
                    goto over;
                }
                userPass[h-1]='\0';
                h--;
                printf("\b \b");
                goto skip;
            }
            over:
            if(ch==13){
                break;
            }
            if(ch!=13||(ch!=8&&i!=0)){
            userPass[h]=ch;
            ch = '*';
            printf("%c",ch);
            h++;
            }
        }
    userPass[h]='\0';
    printf("\n");
    if(stringCompare(userName,"admin")==0){

        if(stringCompare(userPass,"admin")==0){
            return 2;
        }else {
            return 0;
        }
    }else{
    for(k = 0;k<i;k++){
        if(toInteger(userName)==p1[k].studentID){
        student=k;
        break;
            }
    }
    if(stringCompare(userPass,p1[student].lName)==0){
        return 1;
    }else{
        return 0;
        }
     }
}
void display(struct student *stud)
{
    studBox();
    gotoxy(40,11);
    printf("%c",186);
    gotoxy(159,11);
    printf("%c",186);
    gotoxy(51,11);
    printf("%d", stud->studentID);
    gotoxy(58,11);
    printf("%s,", stud->lName);
    printf(" %s", stud->fName);
    gotoxy(83,11);
    printf("  %s", stud->section);
    gotoxy(90,11);
    printf(" %s,", stud->sub->subjectCode);
    printf(" %s,", stud->subs2->subjectCode);
    printf(" %s", stud->subs3->subjectCode);
    gotoxy(120,11);
    printf("%d     ", stud->hex1);
    printf("  %d     ", stud->hex2);
    printf("  %d  ", stud->hex3);
    gotoxy(144,11);
    printf(" %d\n", stud->hex1+stud->hex2+stud->hex3);
    //gotoxy(153,20+no);
    //printf(" %c", stud->grade);
    if (stud->ttl >= 135) {
        gotoxy(153,11);
        printf(" HD\n");
    } else if (stud->ttl >= 120 && stud->ttl < 135) {
        gotoxy(153,11);
        printf(" D\n");
    } else if (stud->ttl >= 100 && stud->ttl < 120) {
        gotoxy(153,11);
        printf(" P\n");
    } else if (stud->ttl >= 75 && stud->ttl < 100) {
        gotoxy(153,11);
        printf(" C\n");
    } else {
        gotoxy(153,11);
        printf(" F\n");
    }
    gotoxy(40,12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}
void enroll1(struct student s1[], struct subject s2[])
{
    char id[100];
    int Subtail;
    gotoxy(40,10);
    printf("%c",186);
    gotoxy(159,10);
    printf("%c",186);
    gotoxy(40,11);
    printf("%c",186);
    gotoxy(159,11);
    printf("%c",186);
    gotoxy(40,12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(43,10);
    printf("Enter a subject code: ");
    scanf(" %99[^\n]s", id);
    for (int j = 0; j < Subtail; j++)
    {
        if (stringCompare(id, s2[j].subjectCode) == 0)
        {
                    if (stringCompare(s1[student].sub->subjectCode, s2[j].subjectCode) == 0 || stringCompare(s1[student].subs2->subjectCode, s2[j].subjectCode) == 0 || stringCompare(s1[student].subs3->subjectCode, s2[j].subjectCode) == 0)
                    {
                        gotoxy(43,11);
                        printf("Student already enrolled in the subject!");
                        break;
                    }
                    if (s1[student].sub->subjectID == 1)
                    {
                        s1[student].sub = &s2[j];
                        gotoxy(43,11);
                        printf("Successfully Enrolled!");
                        break;
                    }
                    else if (s1[student].subs2->subjectID == 1)
                    {
                        s1[student].subs2 = &s2[j];
                        gotoxy(43,11);
                        printf("Successfully Enrolled!");
                        break;
                    }
                    else if (s1[student].subs3->subjectID == 1)
                    {
                        s1[student].subs3 = &s2[j];
                        gotoxy(43,11);
                        printf("Successfully Enrolled!");
                        break;
                    }
                    else
                    {
                        gotoxy(43,11);
                        printf("No other available slots!");
                        break;
                    }
        }
        if (j == Subtail - 1)
        {
            gotoxy(43,11);
            printf("Subject Not found!");
            break;
        }
    }
}
void dropsub(struct student s1[], struct subject s2[])
{
    char id[100];
    int tail;
            gotoxy(40,10);
            printf("%c",186);
            gotoxy(159,10);
            printf("%c",186);
            gotoxy(40,11);
            printf("%c",186);
            gotoxy(159,11);
            printf("%c",186);
            gotoxy(40,12);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
            gotoxy(43,10);
            printf("Enter a subject you want to drop(Subject Code): ");
            scanf(" %99[^\n]s", id);
            if (stringCompare(id, def.subjectCode) == 0)
            {
                gotoxy(43,11);
                printf("Unable to drop in the subject!");
            }
            else if (stringCompare(id, s1[student].sub->subjectCode) == 0)
            {
                s1[student].sub = s1[student].subs2;
                s1[student].subs2 = s1[student].subs3;
                s1[student].subs3 = &s2[0];
                gotoxy(43,11);
                printf("Drop Success!");
            }
            else if (stringCompare(id, s1[student].subs2->subjectCode) == 0)
            {
                s1[student].subs2 = s1[student].subs3;
                s1[student].subs3 = &s2[0];
                gotoxy(43,11);
                printf("Drop Success!");
            }
            else if (stringCompare(id, s1[student].subs3->subjectCode) == 0)
            {
                s1[student].subs3 = &s2[0];
                gotoxy(43,11);
                printf("Drop Success!");
            }
            else
            {
                gotoxy(43,11);
                printf("Student not enrolled in the subject!");
            }

}
void displaySub(struct subject subs, int no)
{
    gotoxy(50,10+no);
    printf("%d\t\t", subs.subjectID);
    gotoxy(64,10+no);
    printf("%s\t\t", subs.subjectCode);
    gotoxy(80,10+no);
    printf("%s\n", subs.subjectTitle);
}
void updateSingle(struct student studs[])
{
    for (int m = 0; m < 6; m++) {
        gotoxy(40,10+m);
        printf("%c",186);
        gotoxy(159,10+m);
        printf("%c",186);
    }
    gotoxy(40,16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(43,10);
    printf("Enter Last Name: ");
    scanf(" %99[^\n]s", studs[student].lName);
    gotoxy(43,11);
    printf("Enter First Name: ");
    scanf(" %99[^\n]s", studs[student].fName);
    gotoxy(43,12);
    printf("Enter Section: ");
    scanf(" %99[^\n]s", studs[student].section);
    gotoxy(43,13);
    printf("Enter a score for exam 1: ");
    scanf("%d", &studs[student].hex1);
    gotoxy(43,14);
    printf("Enter a score for exam 2: ");
    scanf("%d", &studs[student].hex2);
    gotoxy(43,15);
    printf("Enter a score for exam 3: ");
    scanf("%d", &studs[student].hex3);
    studs[student].ttl = (studs[student].hex1 + studs[student].hex2 + studs[student].hex3);
}
void searchsubject(struct subject s2[])
{
    int Subtail, cnt=0, no = 0, clear = 0;
    for (Subtail = 0; s2[Subtail].subjectID != 0; Subtail++)
    {
    }
    char a[100];
    gotoxy(40,10);
    printf("%c",186);
    gotoxy(159,10);
    printf("%c",186);
    gotoxy(40,11);
    printf("%c",186);
    gotoxy(159,11);
    printf("%c",186);
    gotoxy(40,12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(43,10);
    printf("Enter a subject code you want to search: ");
    scanf(" %99[^\n]s", a);
    for (int i = 0; i < Subtail; i++)
    {
        if (stringCompare(a, s2[i].subjectCode) == 0||substring(s2[i].subjectCode,a)==1)
        {
            for (int m = 0; clear == 0 && m < 6; m++) {
                gotoxy(40,10+m);
                printf("                                                                                                                        ");
            }
            clear++;
            gotoxy(40,10+no);
            printf("%c",186);
            gotoxy(159,10+no);
            printf("%c",186);
            gotoxy(43,10+no);
            printf(" %d", no+1);
            displaySub(s2[i], no);
            no++;
            cnt++;
        }

    }
    if (cnt==0)
        {
            gotoxy(43,11);
            printf("Subject Not Found!");
        } else {
            gotoxy(40,10+no);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
        }
}
int substring(char s1[], char  s2[]){
    int size1;
for (size1= 0; s1[size1] != '\0'; size1++){
}
 int size2;
    for (size2= 0; s2[size2] != '\0'; size2++){
}
int cnt = 0;
if(size2==1){//bug fix
    for(int k = 0;k<=size1;k++){
        if(toLower(s2[0])==toLower(s1[k])){
                cnt ++;
            break;
        }else {
        }
    }
    if(cnt!=size2){
    return 0;
}else {
    return 1;
}//bug fix end
}else{
for(int i = 0;i<size2-1;i++){
    for(int k = 0;k<size1-1;k++){
        if(toLower(s2[i])==toLower(s1[k])&&toLower(s1[k+1])==toLower(s2[i+1])){
            cnt++;
            break;
        }
    }
}
if(cnt!=size2-1){
    return 0;
}else {
    return 1;
}
}
}

void deleteAll(struct student arr[],struct subject sub[]){
    char choice[100];
    char userPass[100];
    char ch;
    actLog();
    gotoxy(43,8);
    printf("DELETE ALL FILES");
    gotoxy(40,10);
    printf("%c",186);
    gotoxy(159,10);
    printf("%c",186);
    gotoxy(40,11);
    printf("%c",186);
    gotoxy(159,11);
    printf("%c",186);
    gotoxy(40,12);
    printf("%c",186);
    gotoxy(159,12);
    printf("%c",186);
    gotoxy(40,13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(43,10);
    printf("Are you sure you want to delete  everything! ");
    scanf(" %99[^\n]s",choice);
    if(stringCompare(choice,"yes")==0){
        gotoxy(43,11);
        printf("Enter Admin Password: ");
        int h = 0;
        skip:
        while(1){
            ch =getch();

                if(ch==8){
                    if(h<=0){
                        h = 0;
                        goto over;
                    }
                    userPass[h-1]='\0';
                    h--;
                    printf("\b \b");
                    goto skip;
                }
                over:
                if(ch==13){
                    break;
                }
                if(ch!=13||(ch!=8&&h!=0)){
                userPass[h]=ch;
                ch = '*';
                printf("%c",ch);
                h++;
                }
            }
        userPass[h]='\0';
        if(stringCompare(userPass,"admin")==0){
        int tail;
        for(tail=0;arr[tail].studentID!=0;tail++){
        }
        for(int i = 0;i<tail;i++){
            arr[i].studentID=0;
        }
        int subtail;
        for(subtail=0;sub[subtail].subjectID!=0;subtail++){
        }
        for(int j = 2;j<subtail;j++){
            sub[j].subjectID=0;
            }
        }
    }else{
        gotoxy(43,12);
        printf("OK Sure!");
    }
}
