#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticket_item.h"

#ifndef MAX_NB_TICKET_ITEMS
#define MAX_NB_TICKET_ITEMS 10
#endif

struct ticket_s {
    struct ticket_item_s items[MAX_NB_TICKET_ITEMS];
    int count;
};

static float total_sum = 0.0;

struct ticket_s* ticket_nouveau(void) {
    struct ticket_s* ticket = (struct ticket_s*)malloc(sizeof(struct ticket_s));
    if (ticket != NULL) {
        ticket->count = 0;
    }
    return ticket;
}

void ticket_detruire(struct ticket_s* ticket) {
    if (ticket != NULL) {
        free(ticket);
    }
}

int ticket_ajoute_item(struct ticket_s* ticket, enum item_type_e type, const char* description, float prix) {
    if (ticket->count < MAX_NB_TICKET_ITEMS) {
        ticket->items[ticket->count].type = type;
        ticket->items[ticket->count].description = description;
        ticket->items[ticket->count].prix = prix;
        ticket->count++;
        return 1;
    }
    return 0;
}

void ticket_afficher(struct ticket_s* ticket, FILE* f) {
    float total = 0.0;
    for (int i = 0; i < ticket->count; i++) {
        fprintf(f, "%s\t%s\t%.2f\n", item_type_to_str[ticket->items[i].type], ticket->items[i].description, ticket->items[i].prix);
        total += ticket->items[i].prix;
    }
    fprintf(f, "%d items\n", ticket->count);
    fprintf(f, "TOTAL: %.2f €\n", total);
    total_sum += total;
}

int ticket_supprime_item(struct ticket_s* ticket, int i) {
    if (i < 0 || i >= ticket->count) {
        return 0;
    }
    for (int j = i; j < ticket->count - 1; j++) {
        ticket->items[j] = ticket->items[j + 1];
    }
    ticket->count--;
    return 1;
}

float ticket_somme_tous(void) {
    return total_sum;
}