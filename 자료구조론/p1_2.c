#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    char name[30];
    int studentID;
    char major[30];
}studentT;

int main(void)
{
    FILE *fp;
    int N = 1;

    fp = fopen("student_information.txt", "r");
    fscanf(fp, "%d", &N);
    studentT *arr = (studentT*)malloc(sizeof(studentT) * N);
    for(int i = 0; i < N; i++)
    {
        fscanf(fp, "%s", arr[i].name);
        fscanf(fp, "%d", &arr[i].studentID);
        fscanf(fp, "%s", arr[i].major);
    }
    fclose(fp);
    
    fp = fopen("output.txt", "w+");
    for(int i = 0; i < N; i++)
    {
        fprintf(fp, "%s ", arr[i].name);
        fprintf(fp, "%d ", arr[i].studentID);
        fprintf(fp, "%s\n", arr[i].major);
    }

    fclose(fp);
    free(arr);
    system("pause");
    return 0;
}