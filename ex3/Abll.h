#ifndef ABLL_H
#define ABLL_H

typedef struct _link
{
    struct _link *next;
} LINK;
typedef enum _bool
{
    FALSE,
    TRUE
} BOOL;
void *Abll_push(void *this, void *element);
void *Abll_pop(void *this, void **element);
void *Abll_shift(void *this, void *element);
void *Abll_unshift(void *this, void **element);
int Abll_size(void *this);
void *AbFilter(void *this, BOOL (*FilterElement)(void *, int), int val, void **removed);

#endif /* ABLL_H */