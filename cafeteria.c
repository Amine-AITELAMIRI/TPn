#include <stdio.h>
#include <stdlib.h>
#include "ticket.h"

struct ticket_s* ticket;
FILE* ticket_output;

int main(int argc, char* argv[]) {
    if (argc > 1) {
        ticket_output = fopen(argv[1], "a");
        if (ticket_output == NULL) {
            perror("Error opening file");
            return 1;
        }
    } else {
        ticket_output = stdout;
    }

    ticket = ticket_nouveau();
    ticket_ajoute_item(ticket, ENTREE, "Carottes râpées", 0.90);
    ticket_ajoute_item(ticket, PLAT, "Steak", 3.55);
    ticket_ajoute_item(ticket, PLAT, "Frites", 2.10);
    ticket_ajoute_item(ticket, FROMAGE, "Camembert", 0.70);
    ticket_ajoute_item(ticket, DESSERT, "Pomme", 0.70);
    ticket_afficher(ticket, ticket_output);
    ticket_supprime_item(ticket, 3);
    ticket_supprime_item(ticket, 0);
    ticket_afficher(ticket, ticket_output);
    ticket_detruire(ticket);

    if (ticket_output != stdout) {
        fclose(ticket_output);
    }

    return 0;
}