#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{
    int card;
    struct Node *next;
};
typedef struct Node Node;


void shuffle(int*, int);
void insertRear(Node*, int);
int deleteFront(Node*);
void printDeck(Node*);


int main(){
    int cards[] = {
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10,
        11, 12, 13
    };

    const int CARD_LENGTH = 13;
    int drop = 13;

    shuffle(cards, CARD_LENGTH);

    Node *deck = (Node *)malloc(sizeof(Node));
    deck->next  = NULL;

    for (int i = 0; i < CARD_LENGTH; i++){
        insertRear(deck, cards[i]);
    }
    while(drop>0){
        printDeck(deck);
        int temp = deleteFront(deck);
        if (temp != drop){
            insertRear(deck, temp);
        }
        else{
            drop--;
        }
    }
    return 0;
}


void shuffle(int* deck, int len){
    srand(time(NULL));
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


void insertRear(Node* deck, int card){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->card = card;
    newNode->next = NULL;
    if (deck){
        Node *ptr = deck;
        while(ptr->next)
            ptr = ptr->next;
        ptr->next = newNode;
    }
    else{
        deck = newNode;
    }
}


int deleteFront(Node* deck){
    if (deck->next){
        Node *temp = deck->next;
        int card = temp->card;
        deck->next = temp->next;
        free(temp);
        return card;
    }else{
        exit(-1);
    }
}


void printDeck(Node* deck){
    Node *ptr = deck->next;
    while(ptr){
        if (ptr->card == 1)
            printf("A ");
        else if (ptr->card == 11)
            printf("J ");
        else if (ptr->card == 12)
            printf("Q ");
        else if (ptr->card == 13)
            printf("K ");
        else
            printf("%d ", ptr->card);
        ptr = ptr->next;
    }
    printf("\n");
}

