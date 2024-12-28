#ifndef STRUCT_CONTAINER_H
#define STRUCT_CONTAINER_H
#include "publications_rec.h"

typedef struct {
    Node* top; // указатель на верхний элемент стека
    int size;  // кол-во эл-ов в стеке
} PublicationStack;

typedef struct Node {
    PublicationRecords record; // record, не изменяемый тип данных
    struct Node* next;
} Node;

void init_stack(PublicationStack* stack); // инициализация
int get_size(PublicationStack* stack); // размер стека в данный момент
PublicationRecords get_element_at(PublicationStack* stack, int index); // получение элемента по индексу
Node* get_head(PublicationStack* stack); // получение указателя на верхний элемент
Node* get_tail(PublicationStack* stack); // получение указателя на последний элемент
Node* get_next(Node* node); // получение следующего элемента от указателя
Node* get_prev(PublicationStack* stack, Node* node); // получение предыдущего элемента от указателя
void insert_at_beginning(PublicationStack* stack, PublicationRecords record); // добавление элемента в начало стека
void insert_at_end(PublicationStack* stack, PublicationRecords record); // добавление элемента в конец стека
void insert_at_index(PublicationStack* stack, PublicationRecords record, int index); // добавление элемента по индексу
void remove_from_beginning(PublicationStack* stack); // удаление элемента из начала стека
void remove_from_end(PublicationStack* stack); // удаление элемента из конца стека
void remove_at_index(PublicationStack* stack, int index); // удаление элемента по индексу
void swap_elements(PublicationStack* stack, int index1, int index2); // замена пары элементов по индексам
PublicationStack array_to_stack(PublicationRecords* array, int size); // массив в стек
PublicationRecords* stack_to_array(PublicationStack* stack); // стек в массив
void clear_stack(PublicationStack* stack); // очистка стека

#endif 
