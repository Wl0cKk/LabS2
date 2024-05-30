#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define INADMISSIBLE_GRADE 4

struct Student {
    char lastname[MAX_NAME_LENGTH];
    int groupNumber;
    int physicsGrade;
    int mathGrade;
    int computerScienceGrade;
    float averageGrade;
};

void createRecord(struct Student* students, int *totalStudents);
void viewRecords(struct Student* students, int totalStudents);
void addRecord(struct Student* students, int *totalStudents);
void solveTask(struct Student *students, int totalStudents);
void saveRecordsToFile(struct Student* students, int totalStudents);
void loadRecordsFromFile(struct Student* students, int *totalStudents);

void createRecord(struct Student* students, int *totalStudents) {
    struct Student newStudent;
    printf("\nLast name: ");
    scanf("%s", newStudent.lastname);
    printf("Student group number: ");
    scanf("%d", &newStudent.groupNumber);
    printf("Grade PHYSICS: ");
    scanf("%d", &newStudent.physicsGrade);
    printf("Grade Math: ");
    scanf("%d", &newStudent.mathGrade);
    printf("Grade IT: ");
    scanf("%d", &newStudent.computerScienceGrade);

    newStudent.averageGrade = (newStudent.physicsGrade + newStudent.mathGrade + newStudent.computerScienceGrade) / 3.0;

    students[(*totalStudents)++] = newStudent;
    
    saveRecordsToFile(students, *totalStudents);
}

void viewRecords(struct Student* students, int totalStudents) {
    printf("\nList of students:\n");
    for(int i = 0; i < totalStudents; i++) {
        printf("Last name: %s, Group: %d, GPA: %.2f\n",
               students[i].lastname, students[i].groupNumber, students[i].averageGrade);
    }
}

void addRecord(struct Student* students, int *totalStudents) {
    if (*totalStudents < MAX_STUDENTS) {
        createRecord(students, totalStudents);
    } else {
        printf("The school ran out of chairs\n");
    }
}

void saveRecordsToFile(struct Student* students, int totalStudents) {
    FILE *file = fopen("base.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < totalStudents; i++) {
        fprintf(file, "%s %d %d %d %d %.2f\n", students[i].lastname, students[i].groupNumber,
                students[i].physicsGrade, students[i].mathGrade, students[i].computerScienceGrade, students[i].averageGrade);
    }

    fclose(file);
}

void loadRecordsFromFile(struct Student* students, int *totalStudents) {
    FILE *file = fopen("base.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fscanf(file, "%s %d %d %d %d %f", students[*totalStudents].lastname, &students[*totalStudents].groupNumber,
                  &students[*totalStudents].physicsGrade, &students[*totalStudents].mathGrade, &students[*totalStudents].computerScienceGrade, &students[*totalStudents].averageGrade) == 6) {
        (*totalStudents)++;
    }

    fclose(file);
}

void solveTask(struct Student *students, int totalStudents) {
    FILE *file = fopen("base.txt", "a");
    fprintf(file, "\n-----------------------------------------------------------------------------------\n");
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].mathGrade < INADMISSIBLE_GRADE && students[i].computerScienceGrade < INADMISSIBLE_GRADE) {
            char *res = "---\nLast name: %s, Group: %d, math grade: %d, IT grade: %d\n---\n";
            printf(res, students[i].lastname, students[i].groupNumber, students[i].mathGrade, students[i].computerScienceGrade);
            fprintf(file, res, students[i].lastname, students[i].groupNumber, students[i].mathGrade, students[i].computerScienceGrade);
        }
    }

    fclose(file);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int totalStudents = 0;
    char ch;

    loadRecordsFromFile(students, &totalStudents);

    while(1) {
        printf("\nMenu\n");
        printf("1. Create record\n");
        printf("2. View records\n");
        printf("3. Solve\n");
        printf("4. Exit\n");

        printf("Option: ");
        scanf(" %c", &ch);
        switch(ch) {
            case '1':
                createRecord(students, &totalStudents);
                break;
            case '2':
                viewRecords(students, totalStudents);
                break;
            case '3':
                solveTask(students, totalStudents);
                break;
            case '4':
                exit(0);
            default:
                printf("Wrong option\n");
        }
    }

    return 0;
}
