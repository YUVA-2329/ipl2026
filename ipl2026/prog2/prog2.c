#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

void writeRecords(Student students[], int n, const char *filename) {
    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("File error\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %.2f\n",
                students[i].id,
                students[i].name,
                students[i].marks);
    }

    fclose(fp);
}

long *createSeekPositions(const char *filename, int *count) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File error\n");
        return NULL;
    }

    long *positions = malloc(sizeof(long) * 100);

    *count = 0;

    while (1) {
        long pos = ftell(fp);

        int id;
        char name[50];
        float marks;

        if (fscanf(fp, "%d %s %f",
                   &id,
                   name,
                   &marks) != 3) {
            break;
        }

        positions[*count] = pos;
        (*count)++;
    }

    fclose(fp);

    return positions;
}

void displayRecord(const char *filename, long position) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File error\n");
        return;
    }

    fseek(fp, position, SEEK_SET);

    Student s;

    fscanf(fp, "%d %s %f",
           &s.id,
           s.name,
           &s.marks);

    printf("\nRecord Found\n");
    printf("ID    : %d\n", s.id);
    printf("Name  : %s\n", s.name);
    printf("Marks : %.2f\n", s.marks);

    fclose(fp);
}

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    Student students[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    writeRecords(students, n, "students.txt");

    int count;

    long *positions = createSeekPositions("students.txt", &count);

    printf("\nSeek Positions\n");

    for (int i = 0; i < count; i++) {
        printf("Record %d -> %ld\n", i + 1, positions[i]);
    }

    int choice;

    printf("\nEnter record number to display: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= count) {
        displayRecord("students.txt", positions[choice - 1]);
    } else {
        printf("Invalid record number\n");
    }

    free(positions);
//return
    return 0;
}