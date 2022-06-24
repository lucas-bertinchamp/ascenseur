#ifndef PERSON_H
#define PERSON_H

#include <stdlib.h>

typedef struct _Person {
    int src;
    int dest;
} Person;

typedef struct _PersonList {
    Person* person;
    struct _PersonList *next;
} PersonList;

Person* createPerson(int src, int dest);
PersonList* insert(Person *p, PersonList *list);
int size(PersonList* p);

#endif
