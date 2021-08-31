#include "Abll.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void *Abll_push(void *this, void *element)
{
    if (this == NULL)
    {
        return element;
    }
    if (element == NULL)
    {
        fprintf(stderr, "ERROR Push ILLgal Elment\n");
        return this;
    }

    LINK *tmp = (LINK *)this;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = (LINK *)element;
    ((LINK *)element)->next = NULL;
    return this;
}
void *Abll_shift(void *this, void *element)
{
    // LINK *tmp = (LINK*)thiss;
    // if (tmp == NULL)
    //     return element;
    // tmp = (LINK*)element;
    // tmp->next = thiss;
    // return tmp;

    if (this == NULL)
        return element;
    if (element == NULL)
    {
        fprintf(stderr, "ERROR SHIFT ILLgal Elment\n");
        return this;
    }
    ((LINK *)element)->next = this;
    return element;
}
void *Abll_pop(void *this, void **element)
{
    if (this == NULL)
    {
        return NULL;
    }

    LINK *tmp = (LINK *)this;
    LINK *prev = NULL;
    while (tmp->next != NULL)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    *((LINK **)element) = tmp;
    prev->next = NULL;

    return this;
}
void *Abll_unshift(void *this, void **element)
{
    if (this == NULL)
    {
        return NULL;
    }

    LINK *tmp = ((LINK *)this)->next;
    ((LINK *)this)->next = NULL;
    *((LINK **)element) = ((LINK *)this);

    return tmp;
}
int Abll_size(void *this)
{
    int counter = 0;
    if (this == NULL)
    {
        return 0;
    }
    LINK *tmp = ((LINK *)this);
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        counter++;
    }

    return counter;
}

void *deleteelemnt(void *this, void *tmp, int counter, void **removed)
{

    LINK *tmpp = ((LINK *)this);
    LINK *temp = ((LINK *)tmp);
    LINK *t = ((LINK *)this);

    for (int i = 0; i < counter - 1; i++)
    {
        tmpp = tmpp->next;
    }
    if (temp->next != NULL)
    {

        tmpp->next = temp->next;
        temp->next = NULL;
        *removed = Abll_push(*removed, temp);
    }
    else
    {

        tmpp->next = NULL;

        *removed = Abll_push(*removed, temp);
    }

    return this;
}

void *AbFilter(void *this, BOOL (*FilterElement)(void *, int), int val, void **removed)
{

    if (this == NULL)
    {
        *removed = NULL;
        return NULL;
    }
    *removed = NULL;
    int counter = 0;
    BOOL y = TRUE;
    LINK *tmp = ((LINK *)this);
    LINK *tmpp = ((LINK *)this);
    if (tmp->next == NULL)
    {
        y = FilterElement(tmp, val);
        if (y == FALSE)
        {
            *removed = Abll_push(*removed, tmp);

            tmpp = NULL;
        }
    }

    while (tmp->next != NULL)
    {

        y = FilterElement(tmp, val);
        if (y == FALSE)
        {

            //delete tmp from this
            //add tmp to *removed
            if (counter == 0)
            {
                LINK *tmpxx = tmp->next;
                this = tmpxx;
                tmpp = this;
                tmp->next = NULL;
                *removed = Abll_push(*removed, tmp);
                tmp = tmpxx;
            }
            else
            {
                LINK *tmpx = tmp->next;
                tmpp = deleteelemnt(this, tmp, counter, removed);
                tmp = tmpx;
            }
            counter--;
        }
        else
        {
            tmp = tmp->next;
        }
        counter++;
        if (tmp->next == NULL)
        {
            y = FilterElement(tmp, val);
            if (y == FALSE && counter != 0)
            {
                tmpp = deleteelemnt(this, tmp, counter, removed);
            }
            if (y == FALSE && counter == 0)
            {
                *removed = Abll_push(*removed, tmp);

                tmpp = NULL;
            }
        }
    }

    return tmpp;
}
