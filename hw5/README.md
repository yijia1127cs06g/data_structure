# Data Structure Assignment 5
## Monk And Champions League
## Height Union
implement two functions: collapsingFind that find node with the collapsing rule, heightUnion that uses the height rule for union operations.

### Function
#### collapsingFind
- parameters:
  - node: vector
  - heightOrParent: vector
  - findingNode: the node that we finding
- usage:
  - if the findingNode is not a root, it traveses its parent until finding the root of the tree it belongs
  - reset the parent of findingNode to the root
- return nums of the operations of link traversed and reset
#### unionHeight
- parameters:
  - node: vector
  - heightOrParent: vector
  - first: the first root that we union
  - second: the second root that we union
- usage:
  - compare the height of two tree
  - set the parent of the root with lower height to the root with higher height
  - no return
#### findIdxOfNode
- parameters:
  - node: vector
  - findingNode: the node that we want to find
### Compare with weightedUnion and heightUnion
The performance of collapsingFind in weightedUnion and heightUnion is similar. But when a tree is skew, the performance of collapsingFind in weightedUnion may slower than in heightUnion.
