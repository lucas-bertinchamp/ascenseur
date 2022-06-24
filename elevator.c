#include "elevator.h"
#include "person.h"

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
        if (b -> elevator -> currentFloor > b -> elevator -> targetFloor) {
            b -> elevator -> currentFloor --;
        } else {
            b -> elevator -> currentFloor ++;
        }
    }
    b -> elevator -> persons = exitElevator(b -> elevator);
    b -> elevator -> persons = enterElevator(b -> elevator, b -> waitingLists[b -> elevator -> currentFloor]);
}

PersonList* exitElevator(Elevator *e) {
    PersonList* p = e -> persons;
    PersonList* p2 = malloc(sizeof(PersonList));

    while (p -> next != NULL){
        if (p -> person -> dest == e -> currentFloor) {
            insert(p -> person, p2);
        }
        PersonList* p = p -> next;
    }

}

PersonList* enterElevator(Elevator *e, PersonList *list){
    //while (size(e -> persons) < e -> capacity) {
        //
    //}
}