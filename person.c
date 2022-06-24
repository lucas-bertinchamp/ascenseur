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

int size(PersonList* p) {
    int taille = 0;
    while (p -> next != NULL) {
        taille++;
        PersonList* p = p-> next;
    }
    return taille;
}