//name:Bader Daka  ID:208219212    ODD WORK
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum Bool
{
    FALSE = 0,
    TRUE = 1,
    ERROR = -1
} Bool;

typedef struct item
{
    char *name;
    int itemnumber;
    int checkfree;
} item;

typedef struct shelv
{
    item *items;
    int TA;
    int MaxTA;
} shelv;
typedef struct storge
{
    shelv *SH;
    int SHnumber;
    int MAXsh;
} storge;
int additem(storge *ST, char *a, int itemnumber, int shelnumber, int TAnumber, int counter)
{

    int m = 0, flag = 0, w = 0, z = 0, counterfree = 0;
    int flag1 = 0, count = 0, flag2 = 0, flag11 = 0, flag22 = 0, flag3 = 0, flag4 = 0, flag44 = 0, flag5 = 0, flag6 = 0;
    if (itemnumber > ST->SH[0].MaxTA)
    {
        printf("ERROR IT IS NOT ALLOWED TO PUT NUMBER OF SIZE ITEMS A BIG OF THE NUMBER THE CELLS");
        return ERROR;
    }

    if ((TAnumber != -1) && (shelnumber != -1))
    {
        int longnameitem = strlen(a) + 1;
        // TAnumber -= 1;
        for (int i = TAnumber; i < ST->SH[shelnumber].MaxTA; i++)
        {
            if (ST->SH[shelnumber].items[i].checkfree == 1)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {

            // printf("%d\n",shelnumber);
            for (int i = TAnumber, j = 0; i < ST->SH[shelnumber].MaxTA; i++, j++)
            {
                if (j < itemnumber)
                {
                    ST->SH[shelnumber].items[i].name = (char *)malloc(longnameitem * sizeof(char));
                    if (ST->SH[shelnumber].items[i].name == NULL)
                    {
                        printf("ERROR MEMORY\n");
                        return ERROR;
                    }
                    strcpy(ST->SH[shelnumber].items[i].name, a);
                    ST->SH[shelnumber].items[i].itemnumber = counter;
                    ST->SH[shelnumber].items[i].checkfree = 1;
                    counter++;
                }
            }

            flag3 = 1;
        }
        if (flag == 1)
        {

            counterfree = 0;
            int x = 0;
            for (int i = 0; i < ST->SH[shelnumber].MaxTA; i++)
            {
                if (ST->SH[shelnumber].items[i].checkfree == 0)
                {
                    counterfree++;
                }
                else
                {
                    counterfree = 0;
                }
                if (counterfree == itemnumber && flag44 == 0)
                {
                    // flag1 = 1;
                    x = (i + 1) - itemnumber;
                    if (x < 0)
                    {
                        x = 0;
                    }
                    for (int r = x; r < itemnumber + x; r++)
                    {
                        ST->SH[shelnumber].items[r].name = (char *)malloc(longnameitem * sizeof(char));
                        if (ST->SH[shelnumber].items[r].name == NULL)
                        {
                            printf("ERROR MEMORY\n");
                            return ERROR;
                        }
                        strcpy(ST->SH[shelnumber].items[r].name, a);
                        ST->SH[shelnumber].items[r].itemnumber = counter;
                        ST->SH[shelnumber].items[r].checkfree = 1;
                        counter++;
                    }

                    flag2 = 1;
                }
            }
        }

        if (flag2 == 0 && flag3 == 0)
        {
            int x = 0;
            shelnumber++;

            for (int i = shelnumber; i < ST->MAXsh; i++)
            {
                counterfree = 0;

                for (int j = 0; j < ST->SH[i].MaxTA; j++)
                {
                    if (flag5 == 1)
                    {
                        break;
                    }

                    if (ST->SH[i].items[j].checkfree == 0)
                    {
                        counterfree++;
                    }
                    else
                    {
                        counterfree = 0;
                    }
                    if (counterfree == itemnumber)
                    {
                        // flag1 = 1;
                        x = j - itemnumber + 1;
                        if (x < 0)
                        {
                            x = 0;
                        }

                        for (int r = x; r < itemnumber + x; r++)
                        {
                            ST->SH[i].items[r].name = (char *)malloc(longnameitem * sizeof(char));
                            if (ST->SH[i].items[r].name == NULL)
                            {
                                printf("ERROR MEMORY\n");
                                return ERROR;
                            }
                            strcpy(ST->SH[i].items[r].name, a);
                            ST->SH[i].items[r].itemnumber = counter;
                            ST->SH[i].items[r].checkfree = 1;
                            counter++;
                            // flag2 = 1;
                            flag4 = 1;
                        }
                        flag5 = 1;
                    }
                }
            }
            // break;
        }

        if (flag4 == 0 && flag3 == 0 && flag2 == 0)
        {
            ST->MAXsh++;
            ST->SH = (shelv *)realloc(ST->SH, ST->MAXsh * sizeof(shelv));
            if (ST->SH == NULL)
            {
                printf("ERROR MEMORY\n");
                return ERROR;
            }
            ST->SHnumber = ST->MAXsh - 1;
            ST->SH[ST->SHnumber].MaxTA = ST->SH[0].MaxTA;
            ST->SH[ST->SHnumber].items = (item *)malloc(ST->SH[ST->SHnumber].MaxTA * sizeof(item));
            if (ST->SH[ST->SHnumber].items == NULL)
            {
                printf("ERROR MEMORY\n");
                return ERROR;
            }
            ST->SH[ST->SHnumber].TA = 0;
            for (int j = 0; j < ST->SH[ST->SHnumber].MaxTA; j++)
            {
                ST->SH[ST->SHnumber].items[j].checkfree = 0;
                ST->SH[ST->SHnumber].items[j].itemnumber = 0;
                ST->SH[ST->SHnumber].items[j].name = (char *)malloc(1 * sizeof(char));
                if (ST->SH[ST->SHnumber].items[j].name == NULL)
                {
                    printf("ERROR MEMORY\n");
                    return ERROR;
                }
                ST->SH[ST->SHnumber].items[j].name = '\0';
            }
            for (int j = 0, k = 0; k < ST->SH[ST->SHnumber].MaxTA; k++, j++)
            {
                if (j < itemnumber)
                {
                    ST->SH[ST->SHnumber].items[k].name = (char *)malloc(longnameitem * sizeof(char));
                    if (ST->SH[ST->SHnumber].items[k].name == NULL)
                    {
                        printf("ERROR MEMORY\n");
                        return ERROR;
                    }
                    strcpy(ST->SH[ST->SHnumber].items[k].name, a);
                    ST->SH[ST->SHnumber].items[k].itemnumber = counter;
                    ST->SH[ST->SHnumber].items[k].checkfree = 1;
                    counter++;
                    // TAnumber++;
                }
            }
        }
    }

    if (TAnumber == -1 && shelnumber != -1)
    {
        int x = 0;
        int longnameitem = strlen(a) + 1;
        counterfree = 0;
        for (int i = 0; i < ST->SH[shelnumber].MaxTA; i++)
        {
            if (ST->SH[shelnumber].items[i].checkfree == 0)
            {
                counterfree++;
            }
            else
            {
                counterfree = 0;
            }
            if (counterfree == itemnumber)
            {
                x = (i + 1) - itemnumber;
                if (x < 0)
                {
                    x = 0;
                }
                for (int r = x; r < itemnumber + x; r++)
                {
                    ST->SH[shelnumber].items[r].name = (char *)malloc(longnameitem * sizeof(char));
                    if (ST->SH[shelnumber].items[r].name == NULL)
                    {
                        printf("ERROR MEMORY\n");
                        return ERROR;
                    }
                    strcpy(ST->SH[shelnumber].items[r].name, a);
                    ST->SH[shelnumber].items[r].itemnumber = counter;
                    ST->SH[shelnumber].items[r].checkfree = 1;
                    counter++;
                }
                flag6 = 1;
            }
        }
        if (flag6 == 0)
        {
            x = 0;
            shelnumber++;

            for (int i = shelnumber; i < ST->MAXsh; i++)
            {
                counterfree = 0;

                for (int j = 0; j < ST->SH[i].MaxTA; j++)
                {
                    if (flag5 == 1)
                    {
                        break;
                    }

                    if (ST->SH[i].items[j].checkfree == 0)
                    {
                        counterfree++;
                    }
                    else
                    {
                        counterfree = 0;
                    }
                    if (counterfree == itemnumber)
                    {
                        // flag1 = 1;
                        x = j - itemnumber + 1;
                        if (x < 0)
                        {
                            x = 0;
                        }

                        for (int r = x; r < itemnumber + x; r++)
                        {
                            ST->SH[i].items[r].name = (char *)malloc(longnameitem * sizeof(char));
                            if (ST->SH[i].items[r].name == NULL)
                            {
                                printf("ERROR MEMORY\n");
                                return ERROR;
                            }
                            strcpy(ST->SH[i].items[r].name, a);
                            ST->SH[i].items[r].itemnumber = counter;
                            ST->SH[i].items[r].checkfree = 1;
                            counter++;
                            // flag2 = 1;
                            flag4 = 1;
                        }
                        flag5 = 1;
                    }
                }
            }
        }
        if (flag4 == 0 && flag6 == 0)
        {
            ST->MAXsh++;
            ST->SH = (shelv *)realloc(ST->SH, ST->MAXsh * sizeof(shelv));
            if (ST->SH == NULL)
            {
                printf("ERROR MEMORY\n");
                return ERROR;
            }
            ST->SHnumber = ST->MAXsh - 1;
            ST->SH[ST->SHnumber].MaxTA = ST->SH[0].MaxTA;
            ST->SH[ST->SHnumber].items = (item *)malloc(ST->SH[ST->SHnumber].MaxTA * sizeof(item));
            if (ST->SH[ST->SHnumber].items == NULL)
            {
                printf("ERROR MEMORY\n");
                return ERROR;
            }
            ST->SH[ST->SHnumber].TA = 0;
            for (int j = 0; j < ST->SH[ST->SHnumber].MaxTA; j++)
            {
                ST->SH[ST->SHnumber].items[j].checkfree = 0;
                ST->SH[ST->SHnumber].items[j].itemnumber = 0;
                ST->SH[ST->SHnumber].items[j].name = (char *)malloc(1 * sizeof(char));
                if (ST->SH[ST->SHnumber].items[j].name == NULL)
                {
                    printf("ERROR MEMORY\n");
                    return ERROR;
                }
                ST->SH[ST->SHnumber].items[j].name = '\0';
            }
            for (int j = 0, k = 0; k < ST->SH[ST->SHnumber].MaxTA; k++, j++)
            {
                if (j < itemnumber)
                {
                    ST->SH[ST->SHnumber].items[k].name = (char *)malloc(longnameitem * sizeof(char));
                    if (ST->SH[ST->SHnumber].items[k].name == NULL)
                    {
                        printf("ERROR MEMORY\n");
                        return ERROR;
                    }
                    strcpy(ST->SH[ST->SHnumber].items[k].name, a);
                    ST->SH[ST->SHnumber].items[k].itemnumber = counter;
                    ST->SH[ST->SHnumber].items[k].checkfree = 1;
                    counter++;
                    // TAnumber++;
                }
            }
        }
    }
    if (TAnumber == -1 && shelnumber == -1)
    {
        int longnameitem = strlen(a) + 1;

        int x = 0;
        x = 0;

        for (int i = 0; i < ST->MAXsh; i++)
        {
            counterfree = 0;

            for (int j = 0; j < ST->SH[i].MaxTA; j++)
            {
                if (flag5 == 1)
                {
                    break;
                }

                if (ST->SH[i].items[j].checkfree == 0)
                {
                    counterfree++;
                }
                else
                {
                    counterfree = 0;
                }
                if (counterfree == itemnumber)
                {
                    // flag1 = 1;
                    x = j - itemnumber + 1;
                    if (x < 0)
                    {
                        x = 0;
                    }

                    for (int r = x; r < itemnumber + x; r++)
                    {
                        ST->SH[i].items[r].name = (char *)malloc(longnameitem * sizeof(char));
                        if (ST->SH[i].items[r].name == NULL)
                        {
                            printf("ERROR MEMORY\n");
                            return ERROR;
                        }
                        strcpy(ST->SH[i].items[r].name, a);
                        ST->SH[i].items[r].itemnumber = counter;
                        ST->SH[i].items[r].checkfree = 1;
                        counter++;
                        // flag2 = 1;
                        flag4 = 1;
                    }
                    flag5 = 1;
                }
            }
        }
        if (flag4 == 0)
        {

            ST->MAXsh++;
            ST->SH = (shelv *)realloc(ST->SH, ST->MAXsh * sizeof(shelv));
            if (ST->SH == NULL)
            {
                printf("ERROR MEMORY\n");
                return ERROR;
            }
            ST->SHnumber = ST->MAXsh - 1;
            ST->SH[ST->SHnumber].MaxTA = ST->SH[0].MaxTA;
            ST->SH[ST->SHnumber].items = (item *)malloc(ST->SH[ST->SHnumber].MaxTA * sizeof(item));
            if (ST->SH[ST->SHnumber].items == NULL)
            {
                printf("ERROR MEMORY\n");
                return ERROR;
            }
            ST->SH[ST->SHnumber].TA = 0;
            for (int j = 0; j < ST->SH[ST->SHnumber].MaxTA; j++)
            {
                ST->SH[ST->SHnumber].items[j].checkfree = 0;
                ST->SH[ST->SHnumber].items[j].itemnumber = 0;
                ST->SH[ST->SHnumber].items[j].name = (char *)malloc(1 * sizeof(char));
                if (ST->SH[ST->SHnumber].items[j].name == NULL)
                {
                    printf("ERROR MEMORY\n");
                    return ERROR;
                }
                ST->SH[ST->SHnumber].items[j].name = '\0';
            }
            for (int j = 0, k = 0; k < ST->SH[ST->SHnumber].MaxTA; k++, j++)
            {
                if (j < itemnumber)
                {
                    ST->SH[ST->SHnumber].items[k].name = (char *)malloc(longnameitem * sizeof(char));
                    if (ST->SH[ST->SHnumber].items[k].name == NULL)
                    {
                        printf("ERROR MEMORY\n");
                        return ERROR;
                    }
                    strcpy(ST->SH[ST->SHnumber].items[k].name, a);
                    ST->SH[ST->SHnumber].items[k].itemnumber = counter;
                    ST->SH[ST->SHnumber].items[k].checkfree = 1;
                    counter++;
                }
            }
        }
    }

    return counter;
}
Bool printitem(storge *ST, int itemnum)
{

    for (int i = 0; i < ST->MAXsh; i++)
    {
        for (int j = 0; j < ST->SH[i].MaxTA; j++)
        {

            if (ST->SH[i].items[j].itemnumber == itemnum)
            {
                printf("item:%s, Number:%d,position:[%d,%d]\n", ST->SH[i].items[j].name, ST->SH[i].items[j].itemnumber, i, j);
                return TRUE;
            }
        }
    }
    fprintf(stderr, "PRINT ITEM- the item number is not legal!\n");
    return ERROR;
}
Bool RemoveItem(storge *ST, int shelvremove, int TAremove)
{

    for (int i = 0; i < ST->MAXsh; i++)
    {
        if (i == shelvremove)
        {
            for (int j = 0; j < ST->SH[i].MaxTA; j++)
            {
                if (j == TAremove && ST->SH[i].items[j].checkfree == 1)
                {
                    ST->SH[i].items[j].checkfree = 0;
                    ST->SH[i].items[j].itemnumber = 0;
                    ST->SH[i].items[j].name = '\0';

                    return TRUE;
                }
                if (ST->SH[i].items[j].checkfree == 0 && j == TAremove)
                {
                    fprintf(stderr, "REMOVE- the item location is not legal!\n");
                    return ERROR;
                }
            }
        }
    }
    fprintf(stderr, "REMOVE- the item location is not legal!\n");
    return ERROR;
}
Bool moveitem(storge *ST, int oldshelv, int oldTA, int newshelv, int newTA)
{
    int flag = 0, flag1 = 0;
    for (int i = 0; i < ST->MAXsh; i++)
    {
        if (i == oldshelv)
        {
            for (int j = 0; j < ST->SH[i].MaxTA; j++)
            {
                if (j == oldTA)
                {
                    flag = 1;
                }
            }
        }
    }
    for (int i = 0; i < ST->MAXsh; i++)
    {
        if (i == newshelv)
        {
            for (int j = 0; j < ST->SH[i].MaxTA; j++)
            {
                if (j == newTA)
                {
                    flag1 = 1;
                }
            }
        }
    }
    if (flag1 == 0 || flag == 0)
    {
        printf("SWAP- one/two of the locations are not legal!\n");
        return ERROR;
    }
    if (ST->SH[newshelv].items[newTA].checkfree == 1 && ST->SH[oldshelv].items[oldTA].checkfree == 0)
    {
        fprintf(stderr, "MOVE- one/two of the locations are not legal!");
        return ERROR;
    }

    int flag2 = 0, z = 0;
    z = strlen(ST->SH[oldshelv].items[oldTA].name) + 1;
    ST->SH[newshelv].items[newTA].name = (char *)malloc(z * sizeof(char));
    if (ST->SH[newshelv].items[newTA].name == NULL)
    {
        printf("ERROR MEMORY\n");
        return ERROR;
    }
    strcpy(ST->SH[newshelv].items[newTA].name, ST->SH[oldshelv].items[oldTA].name);
    ST->SH[newshelv].items[newTA].itemnumber = ST->SH[oldshelv].items[oldTA].itemnumber;
    ST->SH[newshelv].items[newTA].checkfree = ST->SH[oldshelv].items[oldTA].checkfree;
    ////////////////////////////////////////////////
    ST->SH[oldshelv].items[oldTA].name = '\0';
    ST->SH[oldshelv].items[oldTA].itemnumber = 0;
    ST->SH[oldshelv].items[oldTA].checkfree = 0;
    if (ST->SH[newshelv].items[newTA].checkfree == 1)
    {
        flag2 = 1;
    }
    if (flag2 == 0)
    {
        fprintf(stderr, "MOVE- one/two of the locations are not legal!");
        return ERROR;
    }

    return TRUE;
}
Bool swapitem(storge *ST, int oldshelv, int oldTA, int newshelv, int newTA)
{
    int flag = 0, flag1 = 0;
    for (int i = 0; i < ST->MAXsh; i++)
    {
        if (i == oldshelv)
        {
            for (int j = 0; j < ST->SH[i].MaxTA; j++)
            {
                if (j == oldTA)
                {
                    flag = 1;
                }
            }
        }
    }
    for (int i = 0; i < ST->MAXsh; i++)
    {
        if (i == newshelv)
        {
            for (int j = 0; j < ST->SH[i].MaxTA; j++)
            {
                if (j == newTA)
                {
                    flag1 = 1;
                }
            }
        }
    }
    if (flag1 == 0 || flag == 0)
    {
        printf("SWAP- one/two of the locations are not legal!\n");
        return ERROR;
    }

    if (ST->SH[oldshelv].items[oldTA].checkfree == 0 || ST->SH[newshelv].items[newTA].checkfree == 0)
    {
        printf("SWAP- one/two of the locations are not legal!\n");
        return ERROR;
    }

    int Titemnuber = 0, Tcheckfree = 0;
    char *a;
    int z = 0;

    z = strlen(ST->SH[oldshelv].items[oldTA].name) + 1;
    a = (char *)malloc(z * sizeof(char));
    if (a == NULL)
    {
        printf("ERROR MEMORY\n");
        return ERROR;
    }
    strcpy(a, ST->SH[oldshelv].items[oldTA].name);
    Titemnuber = ST->SH[oldshelv].items[oldTA].itemnumber;
    Tcheckfree = ST->SH[oldshelv].items[oldTA].checkfree;
    int m = strlen(ST->SH[newshelv].items[newTA].name) + 1;

    ST->SH[oldshelv].items[oldTA].name = (char *)malloc(m * sizeof(char));
    if (ST->SH[oldshelv].items[oldTA].name == NULL)
    {
        printf("ERROR MEMORY\n");
        return ERROR;
    }
    strcpy(ST->SH[oldshelv].items[oldTA].name, ST->SH[newshelv].items[newTA].name);
    ST->SH[oldshelv].items[oldTA].itemnumber = ST->SH[newshelv].items[newTA].itemnumber;
    ST->SH[oldshelv].items[oldTA].checkfree = ST->SH[newshelv].items[newTA].checkfree;
    ////////////////////////////////////////////////
    ST->SH[newshelv].items[newTA].name = (char *)malloc(z * sizeof(char));
    strcpy(ST->SH[newshelv].items[newTA].name, a);

    ST->SH[newshelv].items[newTA].itemnumber = Titemnuber;
    ST->SH[newshelv].items[newTA].checkfree = Tcheckfree;
    free(a);
    return TRUE;
}
Bool printlist(storge *ST)
{
    int space = 0, totalitem = 0;
    for (int i = 0; i < ST->MAXsh; i++)
    {
        for (int j = 0; j < ST->SH[i].MaxTA; j++)
        {
            if (ST->SH[i].items[j].checkfree == 0)
            {
                space++;
            }
            else
            {
                totalitem++;
            }
        }
    }
    printf("Total space:%d\n", space);
    printf("Shelves:%d\n", ST->MAXsh);
    printf("Total items:%d\n", totalitem);
    for (int i = 0; i < ST->MAXsh; i++)
    {
        for (int j = 0; j < ST->SH[i].MaxTA; j++)
        {
            if (ST->SH[i].items[j].checkfree == 1)
            {
                printf("item:%s, Number:%d,position:[%d,%d]\n", ST->SH[i].items[j].name, ST->SH[i].items[j].itemnumber, i, j);
            }
        }
    }
    return TRUE;
}
Bool matrixprint(storge *ST)
{

    for (int i = 0; i < ST->MAXsh; i++)
    {
        for (int j = 0; j < ST->SH[i].MaxTA; j++)
        {
            if (ST->SH[i].items[j].name != NULL)
            {
                for (int k = 0; ST->SH[i].items[j].name[k] != '\0'; k++)
                {
                    if (ST->SH[i].items[j].name[k] >= 'a' && ST->SH[i].items[j].name[k] <= 'z')
                    {
                        ST->SH[i].items[j].name[k] += -32;
                    }
                }
                ST->SH[i].items[j].name[3] = '\0';
            }
        }
    }
    printf("\n");
    for (int i = 0; i < ST->SH[0].MaxTA; i++)
    {
        printf("    |%d  ", i);
    }
    printf("\n");

    printf("----------------------------------------\n");

    for (int i = 0; i < ST->MAXsh; i++)
    {
        printf("%d", i);
        for (int j = 0; j < ST->SH[i].MaxTA; j++)
        {
            if (ST->SH[i].items[j].name != NULL)
                printf("   |%s ", ST->SH[i].items[j].name);
            if (ST->SH[i].items[j].name == NULL)
                printf("   |X   ");
        }
        printf("\n");
    }
    return TRUE;
}
int matrixitem(storge *ST)
{
    int index = 0, shel = 0, flagg = 0, shel1 = 0, z = 0, counter = 0, freeshelf = 0;
    for (int i = 0; i < ST->MAXsh; i++)
    {
        for (int j = 0; j < ST->SH[i].MaxTA; j++)
        {
            flagg = 0;

            if (ST->SH[i].items[j].checkfree == 0)
            {
                shel = i;
                index = j;
                for (int k = index + 1; k < ST->SH[shel].MaxTA; k++)
                {

                    if (ST->SH[shel].items[k].checkfree == 1)
                    {
                        z = strlen(ST->SH[shel].items[k].name) + 1;
                        ST->SH[shel].items[index].name = (char *)malloc(z * sizeof(char));
                        if (ST->SH[shel].items[index].name == NULL)
                        {
                            printf("ERROR MEMORY\n");
                            return ERROR;
                        }
                        strcpy(ST->SH[shel].items[index].name, ST->SH[shel].items[k].name);
                        ST->SH[shel].items[index].checkfree = ST->SH[shel].items[k].checkfree;
                        ST->SH[shel].items[index].itemnumber = ST->SH[shel].items[k].itemnumber;
                       ST->SH[shel].items[k].name = '\0';
                        ST->SH[shel].items[k].checkfree = 0;
                        ST->SH[shel].items[k].itemnumber = 0;
                        flagg = 1;
                        break;
                    }
                }
                if (flagg == 0)
                {

                    shel1 = shel + 1;
                    if (shel1 < ST->MAXsh)
                    {
                        for (int l = 0; l < ST->SH[shel1].MaxTA; l++)
                        {
                            if (ST->SH[shel1].items[l].name != NULL)
                            {
                                z = strlen(ST->SH[shel1].items[l].name) + 1;
                                ST->SH[shel].items[index].name = (char *)malloc(z * sizeof(char));
                                if (ST->SH[shel].items[index].name == NULL)
                                {
                                    printf("ERROR MEMORY\n");
                                    return ERROR;
                                }

                                strcpy(ST->SH[shel].items[index].name, ST->SH[shel1].items[l].name);
                                ST->SH[shel].items[index].checkfree = ST->SH[shel1].items[l].checkfree;
                                ST->SH[shel].items[index].itemnumber = ST->SH[shel1].items[l].itemnumber;
                               ST->SH[shel1].items[l].name = '\0';
                                ST->SH[shel1].items[l].checkfree = 0;
                                ST->SH[shel1].items[l].itemnumber = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int m = 0; m < ST->MAXsh; m++)
    {
        counter = 0;
        for (int w = 0; w < ST->SH[m].MaxTA; w++)
        {
            if (ST->SH[m].items[w].checkfree == 0)
            {
                counter++;
            }
        }
        if (counter == ST->SH[m].MaxTA)
        {
            ST->MAXsh -= 1;
            freeshelf++;
        }
    }
    printf("\n");
    for (int i = 0; i < ST->SH[0].MaxTA; i++)
    {
        printf("    |%d  ", i);
    }
    printf("\n");

    printf("----------------------------------------\n");

    for (int i = 0; i < ST->MAXsh; i++)
    {
        printf("%d", i);
        for (int j = 0; j < ST->SH[i].MaxTA; j++)
        {
            if (ST->SH[i].items[j].name != NULL)
                printf("   |%s ", ST->SH[i].items[j].name);
            if (ST->SH[i].items[j].name == NULL)
                printf("   |X   ");
        }
        printf("\n");
    }
    return freeshelf;
}
void freeitem(item *a)
{
    free((a)->name);
    free(a);
}

void freeshelv(shelv *e)
{

    for (int i = 0; i < (e)->MaxTA; ++i)
        freeitem(&((e)->items[i]));
    free((e)->items);
    free(e);
}

void freestorge(storge *z, int freeshelf)
{
    for (int i = 0; i < (z)->MAXsh + freeshelf; ++i)
        freeshelv(&((z)->SH[i]));
    free(z);
}
int checkaction(FILE *fp, storge *ST)
{
    char *buff, *token, *a;
    int freeshelf = 0;
    buff = (char *)calloc(256, sizeof(char));
    if (buff == NULL)
    {
        printf("ERROR MEMORY\n");
        return ERROR;
    }
    a = (char *)calloc(256, sizeof(char));
    if (a == NULL)
    {
        printf("ERROR MEMORY\n");
        return ERROR;
    }

    int itemnumber = 0, shelnumber = 0, TAnumber = 0, counter = 1;

    while (fgets(buff, 256, fp) != NULL)
    {
        if (buff[0] == '#')
        {
            continue;
        }
        token = strtok(buff, " \n");
        if (strcmp(token, "_isc") == 0)
        {
            token = strtok(NULL, " ");

            sscanf(token, "%d", &ST->MAXsh);
        }
        if (strcmp(token, "_msps") == 0)
        {
            token = strtok(NULL, " ");
            ST->SH = (shelv *)malloc(ST->MAXsh * sizeof(shelv));
            for (int i = 0; i < ST->MAXsh; i++)
            {
                sscanf(token, "%d", &ST->SH[i].MaxTA);
                ST->SH[i].items = (item *)malloc(ST->SH[i].MaxTA * sizeof(item));
                ST->SH[i].TA = 0;
                for (int j = 0; j < ST->SH[i].MaxTA; j++)
                {
                    ST->SH[i].items[j].checkfree = 0;
                    ST->SH[i].items[j].itemnumber = 0;
                    ST->SH[i].items[j].name = (char *)malloc(1 * sizeof(char));
                    ST->SH[i].items[j].name = '\0';
                }
            }
        }

        if (strcmp(token, "_add") == 0)
        {
            for (int i = 1; i <= 4; i++)
            {
                token = strtok(NULL, " ");
                if (i == 1)
                {

                    strcpy(a, token);
                }
                if (i == 2)
                {
                    sscanf(token, "%d", &itemnumber);
                }
                if (i == 3)
                {
                    sscanf(token, "%d", &shelnumber);
                }
                if (i == 4)
                {
                    sscanf(token, "%d", &TAnumber);
                }
            }
            counter = additem(ST, a, itemnumber, shelnumber, TAnumber, counter);
        }
        if (strcmp(token, "_pi") == 0)
        {
            token = strtok(NULL, " ");
            int z = 0;
            sscanf(token, "%d", &z);

            printitem(ST, z);
        }
        if (strcmp(token, "_rm") == 0)
        {
            token = strtok(NULL, " ");
            int shelvremove = 0;
            sscanf(token, "%d", &shelvremove);
            token = strtok(NULL, " ");
            int TAremove = 0;
            sscanf(token, "%d", &TAremove);
            RemoveItem(ST, shelvremove, TAremove);
        }
        if (strcmp(token, "_mv") == 0)
        {
            int oldshelv = 0, oldTA = 0, newshelv = 0, newTA = 0;
            for (int i = 0; i < 4; i++)
            {
                token = strtok(NULL, " ");
                if (i == 0)
                {
                    sscanf(token, "%d", &oldshelv);
                }
                if (i == 1)
                {
                    sscanf(token, "%d", &oldTA);
                }
                if (i == 2)
                {
                    sscanf(token, "%d", &newshelv);
                }
                if (i == 3)
                {
                    sscanf(token, "%d", &newTA);
                }
            }
            moveitem(ST, oldshelv, oldTA, newshelv, newTA);
        }
        if (strcmp(token, "_sw") == 0)
        {
            int shelfA = 0, TAa = 0, shelfB = 0, TAb = 0;
            for (int i = 0; i < 4; i++)
            {
                token = strtok(NULL, " ");
                if (i == 0)
                {
                    sscanf(token, "%d", &shelfA);
                }
                if (i == 1)
                {
                    sscanf(token, "%d", &TAa);
                }
                if (i == 2)
                {
                    sscanf(token, "%d", &shelfB);
                }
                if (i == 3)
                {
                    sscanf(token, "%d", &TAb);
                }
            }
            swapitem(ST, shelfA, TAa, shelfB, TAb);
        }
        if (strcmp(token, "_ps") == 0)
        {
            printlist(ST);
        }
        if (strcmp(token, "_mtrx") == 0)
        {
            matrixprint(ST);
        }
        if (strcmp(token, "_min") == 0)
        {
            freeshelf = matrixitem(ST);
        }
    }
    free(buff);
    free(a);
    return freeshelf;
}
int main(int argc, char const *argv[])
{

    FILE *fp;
    int freeshelf = 0;
    storge *ST = (storge *)malloc(1 * sizeof(storge));
    if (ST == NULL)
    {
        printf("ERROR MEMORY\n");
        return ERROR;
    }

    if ((fp = fopen("Storage.txt", "r")) == NULL)
    {
        fprintf(stderr, "Error opening the file\n");
        return ERROR;
    }
    freeshelf = checkaction(fp, ST);
    freestorge(ST, freeshelf);

    fclose(fp);

    return 0;
}
