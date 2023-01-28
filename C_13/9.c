#include <stdlib.h>
#include <stdio.h>
typedef struct student
{
    char name[20];
    int roll;
    float marks;
    char dob[10];
} Student;
int main()
{
    int ch;
    FILE *fp;
    fp=fopen("student.dat","wb");
    Student s;
    system("cls");
    printf("Enter the Student Name :");
    gets(s.name);
    printf("\nEnter the Roll No :");
    scanf("%d", &s.roll);
    printf("\nEnter the marks :");
    scanf("%f", &s.marks);
    printf("\nEnter the DOB");
    fflush(stdin);
    gets(s.dob);
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    // while (1)
    // {
    //     printf("1) Create a file\n2) Add a record\n3) Delete a record\n4) Modify the marks by add grace marks\n5) Exit\n");
    //     printf("Enter Your Choice :\n");
    //     scanf("%d", ch);
    //     switch (ch)
    //     {
    //     case 1:
    //         fp = fopen("student.dat", "rb+");
    //         if (fp == NULL)
    //         {
    //             printf("File not created\n");
    //         }
    //         else
    //         {
    //             printf("File is created\n");
    //         }
    //         break;
    //     case 2:
    //         // fflush(stdin);

    //         break;
    //     case 3:

    //     case 4:

    //     case 5:

    //     default:
    //         printf("Enter a valid choice\n");
    //     }
    // }
    return 0;
}