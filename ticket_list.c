#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticket_item.h"

struct ticket_item_node_s {
    struct ticket_item_s item;
    struct ticket_item_node_s* next;
};

struct ticket_s {
    struct ticket_item_node_s* head;
    int count;
};

static float total_sum = 0.0;

struct ticket_s* ticket_nouveau(void) {
    struct ticket_s* ticket = (struct ticket_s*)malloc(sizeof(struct ticket_s));
    if (ticket != NULL) {
        ticket->head = NULL;
        ticket->count = 0;
    }
    return ticket;
}

void ticket_detruire(struct ticket_s* ticket) {
    if (ticket != NULL) {
        struct ticket_item_node_s* current = ticket->head;
        while (current != NULL) {
            struct ticket_item_node_s* next = current->next;
            free((void*)current->item.description); // Free the allocated description
            free(current);
            current = next;
        }
        free(ticket);
    }
}

int ticket_ajoute_item(struct ticket_s* ticket, enum item_type_e type, const char* description, float prix) {
    struct ticket_item_node_s* new_node = (struct ticket_item_node_s*)malloc(sizeof(struct ticket_item_node_s));
    if (new_node == NULL) {
        return 0;
    }
    new_node->item.type = type;
    new_node->item.description = strdup(description); // Allocate memory for the description
    if (new_node->item.description == NULL) {
        free(new_node);
        return 0;
    }
    new_node->item.prix = prix;
    new_node->next = NULL;

    if (ticket->head == NULL) {
        ticket->head = new_node;
    } else {
        struct ticket_item_node_s* current = ticket->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    ticket->count++;
    return 1;
}

void ticket_afficher(struct ticket_s* ticket, FILE* f) {
    float total = 0.0;
    struct ticket_item_node_s* current = ticket->head;
    while (current != NULL) {
        fprintf(f, "%s\t%s\t%.2f\n", item_type_to_str[current->item.type], current->item.description, current->item.prix);
        total += current->item.prix;
        current = current->next;
    }
    fprintf(f, "%d items\n", ticket->count);
    fprintf(f, "TOTAL: %.2f €\n", total);
    total_sum += total;
}

int ticket_supprime_item(struct ticket_s* ticket, int i) {
    if (i < 0 || i >= ticket->count) {
        return 0;
    }
    struct ticket_item_node_s* current = ticket->head;
    struct ticket_item_node_s* previous = NULL;
    for (int j = 0; j < i; j++) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        ticket->head = current->next;
    } else {
        previous->next = current->next;
    }
    free((void*)current->item.description); // Free the allocated description
    free(current);
    ticket->count--;
    return 1;
}

float ticket_somme_tous(void) {
    return total_sum;
}