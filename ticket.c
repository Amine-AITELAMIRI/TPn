#include "ticket.h"
#include "ticket_item.h"

/* Structure qui représente un ticket de caisse. Le contenu de cette structure
 * n'est connu que de ce fichier. */
struct ticket_s {
    /* À compléter */
};

/* Renvoie un pointeur vers un nouveau ticket et NULL en cas d'erreur. */
struct ticket_s* ticket_nouveau(void)
{
    /* À compléter (et adapter le return) */
    return NULL;
}

/* Libére la mémoire allouée pour un ticket. */
void ticket_detruire(struct ticket_s* ticket)
{
    /* À compléter */
}

/* Ajoute un élément à un ticket. Par exemple :
 *      ticket_ajoute_item(ticket, ENTREE, "Carottes râpées", 0.90);
 * enum item_type_e est défini dans ticket_item.h
 * Renvoie 1 en cas de succès, 0 en cas d'erreur.
 */
int ticket_ajoute_item(struct ticket_s* ticket, enum item_type_e type, char* description, float prix)
{
    /* À compléter (et adapter le return) */

    return 0;
}

/* Affiche le ticket de caisse en écrivant sur le descripteur de fichier f (on
 * pourra prendre stdout pour commencer).
 *
 * Chaque ligne du ticket doit contenir, dans cet ordre :
 * - le type d'élément (utiliser item_type_to_str défini dans ticket_item.h)
 * - le nom de l'élément
 * - le prix (avec deux chiffres après la virgule et sans symbole monétaire)
 * Ensuite, il doit être affiché le nombre d'éléments.
 * La dernière ligne contient le montant total du ticket de caisse (avec deux
 * chiffres après la virgule et le symbole '€').
 *
 * Exemple d'affichage d'un ticket de caisse (sans les astérisques au début) :
 *
 * Entrée	Carottes râpées		 0.90
 * Plat	Steak		 3.55
 * Plat	Frites		 2.10
 * Fromage	Camembert		 0.70
 * Dessert	Salade de fruits		 0.70
 * 5 items
 * TOTAL:  7.95 €
 */
void ticket_afficher(struct ticket_s* ticket, FILE* f)
{
    /* À compléter */
}

/* Supprime l'élément qui est en ième position (numérotation commençant à zéro) dans le ticket.
 * Renvoie 1 en cas de succès, zéro en cas d'erreur. */
int ticket_supprime_item(struct ticket_s* ticket, int i)
{
    /* À compléter (et adapter le return) seulement à la fin du TP. */

    return 0;
}

/* Renvoie la somme du montant de tous les tickets qui ont été affichés.*/
float ticket_somme_tous(void)
{
    /* À compléter (et adapter le return) seulement à la fin du TP. */

    return 0.;
}
