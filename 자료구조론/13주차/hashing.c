#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *r_fp;
FILE *w_fp;

typedef struct HashTbl *HashTable;
struct HashTbl
{
  int TableSize;
  int *elements;
};

void insert(HashTable H, int value, int solution);
void deletion(HashTable H, int value, int solution);
int find(HashTable H, int value, int solution);
void print(HashTable H);
int Hash(int value, int size, int i, int solution);
int Hashing(int value, int size);

int main(void)
{

  r_fp = fopen("input.txt", "r");
  w_fp = fopen("output.txt", "w");

  int t_case, value, size, solution;
  char oper[3];
  char collision_solution[30];
  struct HashTbl h;

  fscanf(r_fp, "%d", &t_case);
  int t;
  for (t = 0; t < t_case; t++)
  {
    fscanf(r_fp, "%s", collision_solution);
    if (collision_solution[0] == 'L')
    {
      printf("Linear\n");
      fprintf(w_fp, "Linear\n");
      solution = 1;
    }
    else if (collision_solution[0] == 'Q')
    {
      printf("Quadratic\n");
      fprintf(w_fp, "Quadratic\n");
      solution = 2;
    }
    else if (collision_solution[0] == 'D')
    {
      printf("Double\n");
      fprintf(w_fp, "Double\n");
      solution = 3;
    }

    fscanf(r_fp, "%d", &size);
    h.TableSize = size;
    h.elements = (int *)malloc(sizeof(int) * size);
    memset(h.elements, 0, size * sizeof(int));

    while (fscanf(r_fp, "%s", oper) != EOF)
    {
      if (oper[0] == 'q')
        break;
      else if (oper[0] == 'p')
        print(&h);
      else if (oper[0] == 'i')
      {
        fscanf(r_fp, "%d", &value);
        insert(&h, value, solution);
      }
      else if (oper[0] == 'f')
      {
        fscanf(r_fp, "%d", &value);
        find(&h, value, solution);
      }
      else if (oper[0] == 'd')
      {
        fscanf(r_fp, "%d", &value);
        deletion(&h, value, solution);
      }
    }

    free(h.elements);
    printf("\n");
    fprintf(w_fp, "\n");
  }

  fclose(r_fp);
  fclose(w_fp);
  system("pause");
  return 0;
}

void insert(HashTable H, int value, int solution)
{
  int index, i, size;
  size = H->TableSize;

  i = 0;
  while (i <= 10000) // some limitation
  {
    index = Hash(value, size, i, solution);
    if (H->elements[index] == 0)
    {
      H->elements[index] = value;
      printf("Inserted %d\n", value);
      fprintf(w_fp, "Inserted %d\n", value);
      return;
    }
    else
    {
      if (H->elements[index] == value)
      {
        printf("Already exists\n");
        fprintf(w_fp, "Already exists\n");
        return;
      }
      i++;
    }
  }
}
void deletion(HashTable H, int value, int solution)
{
  int size, i, index;
  size = H->TableSize;

  i = 0;
  while (i <= 10000)
  {
    index = Hash(value, size, i, solution);
    if (H->elements[index] == value)
    {
      H->elements[index] = 0;
      printf("Deleted %d\n", value);
      fprintf(w_fp, "Deleted %d\n", value);
      return;
    }

    else if (H->elements[index] == 0)
    {
      printf("%d not exist\n", value);
      fprintf(w_fp, "%d not exist\n", value);
      return;
    }
    else
    {
      i++;
    }
  }
}
int find(HashTable H, int value, int solution)
{
  int size, i, index;
  size = H->TableSize;

  i = 0;
  while (i <= 10000)
  {
    index = Hash(value, size, i, solution);
    if (H->elements[index] == 0)
    {
      printf("Not found\n");
      fprintf(w_fp, "Not found\n");
      return 0;
    }
    else if (H->elements[index] == value)
    {
      printf("Found %d\n", value);
      fprintf(w_fp, "Found %d\n", value);
      return 1;
    }
    else
    {
      i++;
    }
  }
}
void print(HashTable H)
{
  int size, i;
  size = H->TableSize;
  for (i = 0; i < size; i++)
  {
    printf("%d ", H->elements[i]);
    fprintf(w_fp, "%d ", H->elements[i]);
  }
  printf("\n");
  fprintf(w_fp, "\n");
  return;
}
int Hash(int value, int size, int i, int solution)
{
  int ret;
  if (solution == 1)
  {
    ret = Hashing(value, size) + i;
  }
  else if (solution == 2)
  {
    ret = Hashing(value, size) + i * i;
  }
  else if (solution == 3)
  {
    ret = (Hashing(value, size) + i * (7 - (value % 7)) % size);
  }

  if (ret >= size)
    ret = ret % size;
  return ret;
}
int Hashing(int value, int size)
{
  return value % size;
}
