# Programming homework 4
## Solitaire
Using linked list to implement deck.
Dorp the card according to K to A sequentially.
- Initial Step
  - random shuffle the cards
  - sequentially insert cards to the linked list.
- Main Process
  - Drop the first card in each iteration
    - If the droped card not equal to the correct order then insert back to the end of deck
    - else do nothing
- The program will terminate when all cards are droped out

### Function
#### shuffle
- usage: shuffle the deck(input array) randomly
- parameters: 
  - deck: the array of deck
  - len: the length of array
- no return
#### insertRear
- usage: shift the array left and insert the first element to the specific positision
- parameters:
  - deck: the array of deck
  - aryLen: the length of array
  - left: the specific positision that the first element insert
- no return
#### deleteFront
#### print_deck
- usage: print each card in the deck with specific length
- parameters:
  - deck: the array of deck
  - len: the len of deck(the total number of remaining card)
- no return

