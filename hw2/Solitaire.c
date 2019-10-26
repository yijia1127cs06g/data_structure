#include <stdio.h>
#include <stdlib.h>

void shuffle(int*, int);
void print_deck(int*, int);
void shift_array(int*, int, int);


int main(){
    
    int deck[] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12, 13 };

    const int deck_length = 13;
    int drop = 13;

    shuffle(deck, deck_length);

    while(drop>0){
        print_deck(deck, drop);
        if (deck[0]==drop){
            // drop the card
            shift_array(deck, deck_length, drop);
            drop--;
        }
        else{
            // shift array left
            shift_array(deck, deck_length, drop);
        }
    }

    return 0;
}


void shuffle(int* deck, int len){
    int j, k;
    for(int i=0; i<len; i++){
        do{
            j = rand()%len;
            k = rand()%len;
        }while(j==k);
        // swap j and k
        int temp = deck[j];
        deck[j] = deck[k];
        deck[k] = temp;
    }
}


void print_deck(int* deck, int len){
    for(int i=0; i<len; i++){
        if (deck[i]<11 && deck[i]>1){
            printf("%d ", deck[i]);
        }
        else{
            char display;
            if (deck[i]==1)
                display = 'A';
            else if (deck[i]==11)
                display = 'J';
            else if (deck[i]==12)
                display = 'Q';
            else
                display = 'K';
            printf("%c ", display);
                
        }
    }
    printf("\n");
}


void shift_array(int* deck, int aryLen, int left){
    int first_card = deck[0];
    for(int i = 0; i<aryLen-1; i++){
        deck[i] = deck[(i+1)%aryLen];
    }
    deck[left-1] = first_card;
}

