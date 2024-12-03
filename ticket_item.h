#ifndef __TICKET_ITEM_H
#define __TICKET_ITEM_H

/* Ce fichier doit rester privé, seuls les fichiers ticket_*.c peuvent l'inclure.
 * Les fichiers qui utilisent l'interface ticket ne doivent pas l'inclure. Il a
 * pour but de factoriser du code entre les différentes implémentations de
 * l'interface ticket : peu importe comment vous sotcker des struct
 * ticket_item_s (liste, tableau, ...), vous allez toujours stocker des struct
 * ticket_item_s). */

enum item_type_e {
    ITEM_TYPE_1,
    ITEM_TYPE_2,
    ITEM_TYPE_3
};

struct ticket_item_s {
    enum item_type_e type;
    const char* description;
    float prix;

    /* Ce champ ne sert à rien ici, erreur de ma part, désolé.
    struct ticket_item_s* next_item; */
};

char* item_type_to_str[] = {
    "Entrée",
    "Plat",
    "Fromage",
    "Dessert",
    "Boisson",
};



#endif
