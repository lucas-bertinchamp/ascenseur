#include "elevator.h"
#include "person.h"

#include <stdio.h>
#include <stdlib.h>

Elevator *create_elevator(int capacity, int currentFloor, PersonList* persons){
    Elevator* e = malloc(sizeof(Elevator));
    e -> capacity = capacity;
    e -> currentFloor = currentFloor;
    e -> targetFloor = currentFloor;
    e -> persons = persons;
    return e;
}

Building* create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists){
    Building* b = malloc(sizeof(Building));
    b -> nbFloor = nbFloor;
    b -> elevator = elevator;
    b -> waitingLists = waitingLists;
    return b;
}

void stepElevator(Building *b){
    while (b -> elevator -> currentFloor != b -> elevator -> targetFloor) {
        printf("%d\n", b-> elevator -> currentFloor);
        if (b -> elevator -> currentFloor > b -> elevator -> targetFloor) {
            b -> elevator -> currentFloor --;
        } else {
            b -> elevator -> currentFloor ++;
        }
    }
    b -> waitingLists[b -> elevator -> currentFloor] = enterElevator(b -> elevator, b -> waitingLists[b -> elevator -> currentFloor]);
    exitElevator(b -> elevator);

}

PersonList* exitElevator(Elevator *e) {
    PersonList* debut = e -> persons;
    PersonList* sortie = malloc(sizeof(PersonList));
    PersonList* fin = NULL;
    while (debut != NULL){
        if (debut -> person -> dest == e -> currentFloor) {
            sortie = insert(debut -> person, sortie);
        } else {
            fin = insert(debut -> person, fin);
        }
        debut = debut -> next;
    }
    e -> persons = inversion(fin);
    return sortie;
}

PersonList* enterElevator(Elevator *e, PersonList *waitingList){
    PersonList* wList = waitingList;
    if (waitingList != NULL){
        if (size(e -> persons) < e -> capacity) {
            e -> persons = insert(waitingList -> person ,e -> persons);
            return wList -> next;
        }
    }
    return waitingList;
}