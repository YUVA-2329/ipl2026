#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll;
    char name[30];
    float marks;
};

void displayRecord(FILE *fp, int m)
{
    struct Student s;

    fseek(fp, (m - 1) * sizeof(struct Student), SEEK_SET);

    fread(&s, sizeof(struct Student), 1, fp);

    printf("\n--- Record %d ---\n", m);
    printf("Roll No : %d\n", s.roll);
    printf("Name    : %s\n", s.name);
    printf("Marks   : %.2f\n", s.marks);
}

void deleteRecord(int recordNo, int totalRecords)
{
    FILE *fp, *temp;
    struct Student s;
    int i;

    fp = fopen("student.dat", "rb");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return;
    }

    temp = fopen("temp.dat", "wb");

    if (temp == NULL)
    {
        printf("Temporary file cannot be opened.\n");
        fclose(fp);
        return;
    }

    for (i = 1; i <= totalRecords; i++)
    {
        fread(&s, sizeof(struct Student), 1, fp);

        if (i != recordNo)
        {
            fwrite(&s, sizeof(struct Student), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat", "student.dat");

    printf("\nRecord %d deleted successfully.\n", recordNo);
}

int main()
{
    FILE *fp;
    struct Student s;
    int n, i, m, del;

    fp = fopen("student.dat", "wb+");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("Enter number of records: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for student %d\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &s.roll);

        printf("Name: ");
        scanf("%s", s.name);

        printf("Marks: ");
        scanf("%f", &s.marks);

        fwrite(&s, sizeof(struct Student), 1, fp);
    }

    printf("\nEnter record number to display: ");
    scanf("%d", &m);

    if (m < 1 || m > n)
    {
        printf("Invalid record number.\n");
    }
    else
    {
        displayRecord(fp, m);
    }

    fclose(fp);

    printf("\nEnter record number to delete: ");
    scanf("%d", &del);

    if (del < 1 || del > n)
    {
        printf("Invalid record number.\n");
    }
    else
    {
        deleteRecord(del, n);
        n--;
    }

    fp = fopen("student.dat", "rb");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("\nRemaining Records\n");

    for (i = 1; i <= n; i++)
    {
        displayRecord(fp, i);
    }

    fclose(fp);

    return 0;
}