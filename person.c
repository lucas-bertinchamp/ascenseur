#include "person.h"

Person* createPerson(int src, int dest) {
    Person* p = malloc(sizeof(Person));
    p -> src = src;
    p -> dest = dest;
    return p;
}

PersonList* insert(Person* p, PersonList* list) {
    PersonList* pl = malloc(sizeof(PersonList));
    pl -> person = p;
    pl -> next = list;
    return pl;
}

PersonList* inversion(PersonList* p) {
    PersonList* new = NULL;
    while (p != NULL) {
        new = insert(p -> person, new);
        p = p -> next;
    }
    return new;
}

int size(PersonList* p) {
    int taille = 0;
    PersonList* p1 = p;
    while (p1 != NULL) {
        taille++;
        p1 = p1-> next;
    }
    return taille;
}