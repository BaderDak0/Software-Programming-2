#include <stdio.h>
#include <string.h>
typedef enum Bool
{
    FALSE = 0,
    TRUE = 1,
    ERROR = -1
} Bool;

typedef struct person
{
    char id[50];
    char nameandlast[50];
    char streetandApartment[50];
    char city[50];

} person;
int load(FILE *fptr, person *pe)
{
    char buff[256];
    int k = 0;
    char a[256];
    int counter = 0;
    while (fgets(buff, 256, fptr) != NULL)
    {

        if (buff[0] == '#' || buff[0] == '-' || buff[0] == ' ')
        {
            continue;
        }

        if (counter < 5)
        {
            int count = 0;
            for (int m = 0, i = 0; buff[i] != '\0' && buff[0] != '-'; i++, m++)
            {
                a[m] = buff[i];
                count++;
            }
            a[count] = '\0';
            if (counter == 1)
            {
                strncpy(pe[k].nameandlast, a, 50);
            }

            if (counter == 2)
            {
                strncpy(pe[k].id, a, 50);
            }
            if (counter == 3)
            {
                strncpy(pe[k].streetandApartment, a, 50);
            }
            if (counter == 4)
            {

                strncpy(pe[k].city, a, 50);
            }
        }
        counter++;
        if (counter == 5)
        {
            k++;
            counter = 1;
        }
    }
    return k;
}
int ADD(FILE *fp, person *pe, int np)
{
    np++;
    int w = np;
    long a = 0, z = 0;
    int flag = 0, count = 0;
    gets(pe[w].nameandlast);
    gets(pe[w].id);
    sscanf(pe[w].id, "%ld", &a);
    for (int i = 0; i < np; i++)
    {
        sscanf(pe[i].id, "%ld", &z);

        if (z == a)
        {
            flag++;
            printf("this id is already exists");
            return FALSE;
        }
    }
    gets(pe[w].streetandApartment);
    gets(pe[w].city);
    if (flag == 0)
    {
        fputs(pe[w].nameandlast, fp);
        fprintf(fp, "\n");
        fputs(pe[w].id, fp);
        fprintf(fp, "\n");
        fputs(pe[w].streetandApartment, fp);
        fprintf(fp, "\n");
        fputs(pe[w].city, fp);
        fprintf(fp, "\n-\n");
    }

    return np;
}
void FIND(person *pe, int np, int i)
{
    pe[i].nameandlast[(strlen(pe[i].nameandlast) - 1)] = '\0';
    pe[i].id[(strlen(pe[i].id) - 1)] = '\0';
    pe[i].streetandApartment[(strlen(pe[i].streetandApartment) - 1)] = '\0';
    pe[i].city[(strlen(pe[i].city) - 1)] = '\0';
    printf("name and lastname: %s  ID: %s  streetandApartment: %s   city: %s", pe[i].nameandlast, pe[i].id, pe[i].streetandApartment, pe[i].city);
}
void PRINT(person *pe, int np)
{
    for (int i = 0; i <= np; i++)
    {
        pe[i].nameandlast[(strlen(pe[i].nameandlast) - 1)] = '\0';
        pe[i].id[(strlen(pe[i].id) - 1)] = '\0';
        pe[i].streetandApartment[(strlen(pe[i].streetandApartment) - 1)] = '\0';
        pe[i].city[(strlen(pe[i].city) - 1)] = '\0';
        printf("name and lastname: %s  ID: %s  streetandApartment: %s   city: %s\n", pe[i].nameandlast, pe[i].id, pe[i].streetandApartment, pe[i].city);
    }
}
int main(int argc, char const *argv[])
{
    person pe[1000];
    FILE *fptr;
    FILE *fp;
    if (argc < 3)
    {
        printf("ERROR");
        return ERROR;
    }
    if ((strcmp(argv[1], "add") == 0) || (strcmp(argv[1], "print") == 0))
    {
        if ((fptr = fopen(argv[2], "r")) == NULL)
        {
            fprintf(stderr, "Error opening the file\n");
            return ERROR;
        }
        if ((fp = fopen(argv[2], "a")) == NULL)
        {
            fprintf(stderr, "Error opening the file\n");
            return ERROR;
        }
    }
    if ((strcmp(argv[1], "find") == 0))
    {
        if ((fptr = fopen(argv[3], "r")) == NULL)
        {
            fprintf(stderr, "Error opening the file\n");
            return ERROR;
        }
        if ((fp = fopen(argv[3], "a")) == NULL)
        {
            fprintf(stderr, "Error opening the file\n");
            return ERROR;
        }
    }
    int np = load(fptr, pe) - 1;
    if (strcmp(argv[1], "add") == 0)
    {
        np = ADD(fp, pe, np);
    }
    long z, m;
    int flag = 0;
    for (int i = 0; i <= np; i++)
    {
        sscanf(pe[i].id, "%ld", &z);
        sscanf(argv[2], "%ld", &m);

        if ((strcmp(argv[1], "find") == 0) && (z == m))
        {
            FIND(pe, np, i);
            flag++;
            break;
        }
    }
    if (flag == 0 && (strcmp(argv[1], "find") == 0))
    {
        printf("there not this person\n");
    }

    if (strcmp(argv[1], "print") == 0)
    {
        PRINT(pe, np);
    }

    fclose(fptr);
    fclose(fp);
    return 0;
}
