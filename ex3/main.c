#include <stdio.h>
#include "Abll.h"
// typedef struct _linkable_person
// {
//     LINK link;
//     int id;
//     char first[20], last[40];
//     struct _date
//     {
//         int d, m, y;
//     } born;
// } Person, *PPerson;

// int main(void)
// {
//     Person people[] = {
//         {{NULL}, 1111111, "Israel", "Israeli", {5, 5, 1988}},
//         {{NULL}, 2222222, "Douglas", "Adams", {1, 11, 1948}},
//         {{NULL}, 3333333, "Tuval", "Shem Tov", {15, 7, 1992}},
//         {{NULL}, 4444444, "Shimrit", "Cohen", {3, 12, 1980}}};
//     PPerson guild = NULL, p; // A guild is an association of craftsmen or merchants (it has a list of members)

//     // guild =

//     guild = Abll_push(guild, &people[0]);
//     guild = Abll_push(guild, &people[1]);
//     guild = Abll_shift(guild, &people[2]);
//     guild = Abll_shift(guild, &people[3]);
//     p = guild;
//     printf("The members of the guild are:\n");
//     for (int i = 0; i < 4; ++i, p = (PPerson)p->link.next)
//         printf("id:%d[%s %s] =>\n", p->id, p->first, p->last);
//     printf("(END)\n");
//     for (int i = 0; i < 2; ++i)
//     {
//         guild = Abll_pop(guild, (void **)&p);
//         printf("id:%d[%s %s]\n", p->id, p->first, p->last);
//         guild = Abll_unshift(guild, (void **)&p);
//         printf("id:%d[%s %s]\n", p->id, p->first, p->last);
//     }
//     if (guild)
//         printf("And now guild contains: %p\n", guild);
//     else
//         printf("And now guild is EMPTY\n");
// }
BOOL filterCourses(void *ele, int val);
BOOL filterGrade(void *ele, int val);
typedef struct _linkable_student
{
    LINK link;
    int student_id;
    char first[10], last[12];
    int numberOfCourses;
    double average;
} Student, *PStudent;
void displayList(PStudent studentL)
{
    if (!studentL)
        printf(" <<Empty>>\n");
    for (; studentL; studentL = (PStudent)studentL->link.next)
        printf("%d %-10s %-12s has %d courses Avg:%g\n",
               studentL->student_id, studentL->first, studentL->last,
               studentL->numberOfCourses, studentL->average);
    printf("\n");
}
int main(void)
{
    Student shenkar[] = {
        {{NULL}, 1111111, "Amos", "Levi", 1, 82.8},
        {{NULL}, 2222222, "Tanchum", "Haroea", 4, 92.5},
        {{NULL}, 3333333, "Gali", "Shabat",14, 62.9},
        {{NULL}, 4444444, "Hanoch", "Cohen", 6, 73.3},
        {{NULL}, 5555555, "Tali", "Bahat", 2, 72.2},
        {{NULL}, 6666666, "Sharon", "Shalev", 3, 81.4}};

    PStudent Tashaf = NULL;
    for (int i = 0; i < sizeof(shenkar) / sizeof(Student); ++i)
        Tashaf = Abll_shift(Tashaf, &shenkar[i]);
    printf("Original List:\n");
    displayList(Tashaf);
    PStudent filtered, removed;
    filtered = AbFilter(Tashaf, filterCourses, 10, (void **)&removed);
    printf("\nAfter filtering for courses>10:\n");
    displayList(filtered);
    printf("Removed:\n");
    displayList(removed);
    filtered = AbFilter(filtered, filterGrade, 80, (void **)&removed);
    printf("\nAfter filtering the above for grade Average > 80:\n");
    displayList(filtered);
    printf("Removed:\n");
    displayList(removed);
}
BOOL filterCourses(void *ele, int val)
{
    PStudent student = (PStudent)ele;
    return student->numberOfCourses > val;
}
BOOL filterGrade(void *ele, int val)
{
    PStudent student = (PStudent)ele;
    return student->average > (double)val;
}