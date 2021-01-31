#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

int check(card_t c1, card_t c2)
{
    if(c1.value==c2.value && c1.suit == c2.suit)
    {
        return 1;
    }
    return 0;
}
void print_hand(deck_t * hand){
    card_t **card=hand->cards;
    card_t card1;
    for(int i=0; i<(hand->n_cards); i++)
    {
        card1=**(card+i);
        print_card(card1);
    }
    

}

int deck_contains(deck_t * d, card_t c) {
    card_t **cards=d->cards;
    for(int i=0; i<d->n_cards; i++)
    {
        if(check(**(cards+i), c)) return 1;
    }
    return 0;
}

void shuffle(deck_t * d){

    card_t **card=d->cards;
    size_t n=d->n_cards;
    card_t *temp;
    int rand;

    for(int i=0; i<n; i++)
    {
        rand=random()%(n-i)+i;
        temp=card[i];
        card[i]=card[rand];
        card[rand]=temp;
    }
}

void assert_full_deck(deck_t * d) {
    card_t **card=d->cards;
    card_t c;
    int count;

    for(int i=0; i<d->n_cards; i++)
    {
        c=**(card+i);
        count=0;
        for(int j=0; j<d->n_cards; j++)
        {
            if(check(**(card+j), c))
            {
                count++;
            }
        }
        assert(count==1);
    }

}
