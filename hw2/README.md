# Programming homework 2
## Solitaire
Using array to implement deck.
Dorp the card according to K to A sequentially.
- If the first card not equal to the drop card then insert it to the end of deck
  - shift each element to the left
  - insert the first element to the end of desk(the total number of remaining card).
- Else draw out the card

### Function
#### shuffle
- usage: shuffle the deck(input array) randomly
- parameters: 
  - deck: the array of deck
  - len: the length of array
- no return
#### shift_array
- usage: shift the array left and insert the first element to the specific positision
- parameters:
  - deck: the array of deck
  - aryLen: the length of array
  - left: the specific positision that the first element insert
- no return
#### print_deck
- usage: print each card in the deck with specific length
- parameters:
  - deck: the array of deck
  - len: the len of deck(the total number of remaining card)
- no return

