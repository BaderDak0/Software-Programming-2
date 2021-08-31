#include "stringADT.h"
struct string
{
    char *data;
    int length;
    int capacity;
    //for to foreach
    char *data2;
    int length2;
    int capacity2;
    int iterator;
    char *tmp;
    char *data2_Start;
};

String string_create(char *a)
{
    assert(a != NULL);
    String str1 = (String)malloc(sizeof(struct string));
    assert(str1 != NULL);
    str1->length = strlen(a);
    str1->capacity = strlen(a) + 1;
    str1->iterator = 0;
    str1->data = (char *)malloc(str1->capacity * sizeof(char));
    assert(str1->data != NULL);
    strcpy(str1->data, a);

    return str1;
}
void string_create1(String str, char *a)                                   // dowing a creating to str->data2
{
    str->length2 = strlen(a);
    str->capacity2 = strlen(a) + 1;
    str->data2 = (char *)malloc(str->capacity2 * sizeof(char));
    str->data2_Start = str->data2;
    assert(str->data2 != NULL);
    strcpy(str->data2, a);
}

String multString_create(String str1, int n)
{
    assert(str1 != NULL);
    assert(str1->data != NULL);
    String tmp = (String)malloc(sizeof(struct string));
    assert(tmp != NULL);
    tmp->length = str1->length * n;
    tmp->capacity = (str1->length * n) + 1;
    tmp->data = (char *)malloc(tmp->capacity * sizeof(char));
    assert(tmp->data != NULL);
    strcpy(tmp->data, str1->data);
    for (int i = 1; i < n; i++)
    {
        strcat(tmp->data, str1->data);
    }

    return tmp;
}
void string_print(String s)
{
    printf("%s\n", s->data);
}
void string_destroy(String source)
{
    free(source->data);
    free(source);
}
int string_length(String str)
{
    assert(str != NULL);
    return str->length;
}
char *string_chars(String str)
{
    assert(str != NULL);
    assert(str->data != NULL);
    return str->data;
}
String string_dup(String str)
{
    assert(str != NULL || str->data != NULL);
    String new = string_create(str->data);
    return new;
}
char string_charByIndex(String str, int index)
{
    assert(str != NULL || str->data != NULL);
    assert(0 <= index || index < str->length);
    return str->data[index];
}
int string_findIndexByChar(String str, char c)
{
    assert(str != NULL || str->data != NULL);
    for (int i = 0; i < str->length; i++)
    {
        if (str->data[i] == c)
        {
            return i;
        }
    }
    return -1;
}
bool string_isEqual(String str, String str1)
{
    assert(str != NULL || str->data != NULL);
    assert(str1 != NULL || str1->data != NULL);
    if (strcmp(str->data, str1->data) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
String string_addString(String dest, String src)
{
    assert(src != NULL || src->data != NULL);
    assert(dest != NULL || dest->data != NULL);
    dest->length = dest->length + src->length;
    dest->capacity = dest->length + 1;
    dest->data = (char *)realloc(dest->data, dest->capacity);

    strcat(dest->data, src->data);
    return dest;
}
String string_copy(String dest, String src)
{
    assert(src != NULL || src->data != NULL);
    assert(dest != NULL || dest->data != NULL);
    if (src->capacity > dest->capacity)
    {
        dest->capacity = src->capacity;
        dest->length = src->length;
        dest->data = (char *)realloc(dest->data, dest->capacity);
        strcpy(dest->data, src->data);
        return dest;
    }
    else
    {
        for (int i = 0; i < src->length; i++)
        {
            dest->data[i] = src->data[i];
        }

        return dest;
    }
}
void string_convertCase(String str, CASE x)
{
    assert(str != NULL || str->data != NULL);

    if (x == LOWER_CASE)
    {
        for (int i = 0; i < str->length; i++)
        {
            if (str->data[i] >= 'A' && str->data[i] <= 'Z')
            {
                str->data[i] += +('a' - 'A');
            }
        }
    }
    if (x == UPPER_CASE)
    {
        for (int i = 0; i < str->length; i++)
        {
            if (str->data[i] >= 'a' && str->data[i] <= 'z')
            {
                str->data[i] += -('a' - 'A');
            }
        }
    }
}
int string_findString(String dest, String sub)
{

    assert(sub != NULL || sub->data != NULL);
    assert(dest != NULL || dest->data != NULL);
    int flag = 0;
    for (int i = 0; i < dest->length; i++)
    {
        if (dest->data[i] == sub->data[0])
        {

            for (int j = i + 1, k = 1; k < sub->length; j++, k++)
            {
                if (dest->data[j] != sub->data[k])
                {
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                return i;
            }
            else
            {
                return -1;
            }
        }
    }
}

void string_removeString(String dest, String sub)
{
    assert(sub != NULL || sub->data != NULL);
    assert(dest != NULL || dest->data != NULL);
    int index = string_findString(dest, sub);
    if (index >= 0)
    {

        int lastindex = index + sub->length - 1;
        String dub = string_dup(dest);
        int j = 0;
        dest->length = (dest->length) - (sub->length);
        dest->capacity = (dest->length) + 1;
        dest->data = (char *)realloc(dest->data, dest->capacity);
        for (int i = 0; i < index; i++)
        {
            dest->data[j] = dub->data[i];
            j++;
        }
        for (int i = lastindex + 1; i < dub->length; i++)
        {
            dest->data[j] = dub->data[i];
            j++;
        }

        dest->data[j] = '\0';
    }
    else
    {
        fprintf(stderr, "there is not sub STRING!!\n");
    }
}
bool string_isAllDigits(String str)
{
    assert(str != NULL || str->data != NULL);
    int flag = 0;
    for (int i = 0; i < str->length; i++)
    {
        if (str->data[i] > '9' || str->data[i] < '0')
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
String string_dup2(String str)                           /// copying from str->data2 to String new
{
    assert(str != NULL || str->data != NULL);
    String new = string_create(str->data2);
    return new;
}
String StringGetFirst(String str)
{
    assert(str != NULL || str->data != NULL);
    string_create1(str, str->data);
    char *token;
    token = strtok(str->data2, " ");
    String word = string_create(token);
    str->length2 = str->length - strlen(token);
    str->capacity2 = str->length - strlen(token) + 1;
    str->data2 = (char *)realloc(str->data2, str->capacity2);
    int j = 0;
    for (int i = strlen(token); i < str->length; i++)
    {
        str->data2[j] = str->data[i];
        j++;
    }
    str->data2[j] = '\0';

    return word;
}

String StringGetNext(String str)
{
    assert(str != NULL || str->data != NULL);
    String dub = string_dup2(str);
    if (str->iterator == 0)
        str->tmp = strtok(str->data2, " ");
    else
        str->tmp = strtok(NULL, " ");

    if (str->tmp == NULL)
    {
        str->data2 = (char *)realloc(str->data2, 1);
        str->data2 = '\0';
        return NULL;
    }

    String word = string_create(str->tmp);
    str->iterator++;
    return word;
}
bool StringIsEmpty(String str)
{
    assert(str != NULL);
    if (str->data2 == NULL)
    {
        free(str->data2_Start);
        return true;
    }
    else
    {
        return false;
    }
}
