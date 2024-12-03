#ifndef __TICKET_H
#define __TICKET_H

#include <stdio.h>

enum item_type_e {
    ENTREE,
    PLAT,
    FROMAGE,
    DESSERT,
    BOISSON,
};

struct ticket_s* ticket_nouveau(void);
void ticket_detruire(struct ticket_s* ticket);
int ticket_ajoute_item(struct ticket_s* ticket, enum item_type_e type, char* description, float prix);
int ticket_supprime_item(struct ticket_s* ticket, int i);
void ticket_afficher(struct ticket_s* ticket, FILE* f);
float ticket_somme_tous(void);

#endif
