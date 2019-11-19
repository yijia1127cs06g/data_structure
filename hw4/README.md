# Programming homework 4
## Solitaire
Using linked list to implement deck.
Dorp the card according to K to A sequentially.
- Initial Step
  - random shuffle the cards.
  - sequentially insert cards to the linked list.
- Main Process
  - Drop the first card in each iteration.
    - If the droped card not equal to the correct order then insert back to the end of deck.
    - else do nothing.
- The program will terminate when all cards are droped out

### Function
#### shuffle
- usage: shuffle the deck(input array) randomly.
- parameters: 
  - deck: the array of deck.
  - len: the length of array.
- no return
#### insertRear
- usage: insert the given card to the rear of the linked list.
- parameters:
  - deck: linked list.
  - card: the number of card.
- no return
#### deleteFront
- usage: delete the first card at the linked list.
- parameters:
  - deck: linked list.
- return: int
#### printDeck
- usage: print the linked list.
- parameters:
  - deck: the array of deck.
- no return

## Bouns - Compare with homework 2
- In HW2, when the droped card is inserted back to array (i.e. the droped card isn't in correct order), it needs to shift all element to the left.
- While in HW4, it only needs to insert the rear of the linked list.
