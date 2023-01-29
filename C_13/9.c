#include <stdlib.h>
#include <stdio.h>
typedef struct student
{
    char name[20];
    int roll;
    float marks;
    char dob[10];
} Student;
void add_record(FILE *fp){
    Student s;
    printf("Enter the Student Name :");
    gets(s.name);
    printf("\nEnter the Roll No :");
    scanf("%d", &s.roll);
    printf("\nEnter the marks :");
    scanf("%f", &s.marks);
    printf("\nEnter the DOB :");
    fflush(stdin);
    gets(s.dob);
    fseek(fp, 0, SEEK_END);
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
}
void del_record(FILE *fp){
    Student s[1000];
    int roll;
    printf("Enter the Roll No. :\n");
    scanf("%d",&roll);
    fseek(fp, 0, SEEK_SET);
    int i=0;
    while(fread(&s[i],sizeof(Student),1,fp)){
        i++;
    }
    int is = 0;
   for (int j = 0; j < i; j++)
   {
      if (s[j].roll == roll)
      {
         s[i].roll = -1;
         is= 1;
         break;
      }
   }
   if(is == 0)
   {
      printf("Student not found...\n");
   }
   else{
      printf("Record deleted successfully\n");

   }
   fseek(fp, 0, SEEK_SET);
   for (int j = 0; j < i; j++)
   {
         fwrite(&s[j], sizeof(Student), 1, fp);

   }
}
int main()
{
    int ch;
    system("cls");
    FILE *fp;
    // fp=fopen("student.dat","wb+");
    while (1)
    {
        printf("1) Create a file\n2) Add a record\n3) Delete a record\n4) Modify the marks by add grace marks\n5) Exit\n");
        printf("Enter Your Choice :\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            fp = fopen("student.dat", "rb+");
            if (fp == NULL)
            {
                printf("File not created\n");
            }
            else
            {
                printf("File is created\n");
            }
            break;
        case 2:
            fflush(stdin);
            add_record(fp);
            printf("Record Added\n");
            break;
        case 3:
            del_record(fp);
            break;
        case 4:

        case 5:
            return 0;
        default:
            printf("Enter a valid choice\n");
        }
    }
    return 0;
}