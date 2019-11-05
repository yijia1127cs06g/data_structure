# Programming homework 3
## Queue
Using vector (and Class) to implement a circular queue.
The queue has 3 attribute
- front
- rear
- vector
and 6 method
- isFull
  - determine the queue is full or not ((rear+1)%size == front)
- isEmpty:
  - determine the queue is empty or not (rear == front)
- dequeue:
  - output the person at the front of queue
- enqueue:
  - insert the person to the rear of queue
- search_first_mem_idx
  - search the index of the headmost friend that belongs to the same group with the given person 
- queue_or_cut
  - call the "search_first_mem_idx" function
  - decide whether the given person should be enqueue or be the front of it's headmost friend
  - if the person cuts the line, the queue needs to move the element in the queue

### Other Function
#### in_group
- usage: determine the given person belongs to the given group or not
- parameters: 
  - c: char (person)
  - group
- return bool

### Process block
- If "ENQUEUE" a person, process will first find the group he belongs
  - If the person doesn't belong to any group -> enqueue
  - Else find the headmost friend in the group
    - If no friend in the queue -> enqueue
    - Else set the person to the front of the headmost friend and move all person in the queue that behind him -> cut the line
- Else "DEQUEUE"
  - output the person at the front of queue
