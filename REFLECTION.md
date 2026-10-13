# Reflection Questions

## 1. Why does concat only need to work between two lists of the same representation?

`concat` receives a `List<T>*`, but an `ArrayList` stores its elements in an array while a `LinkedList` stores them in nodes. The implementation uses `dynamic_cast` to check that `other` has the same concrete representation before accessing its private storage. If the representations do not match, it prints an error and leaves both lists unchanged.

## 2. Walk through reverse() on your linked list.

The three pointers are `previous`, `current`, and `next`. `next` saves the rest of the list before `current->next` is changed to point backward; then `previous` and `current` advance. Losing `next` would lose access to the unprocessed nodes, while losing track of `previous` or `current` would prevent correct relinking.

## 3. What are the valid bounds for addAnywhere and deleteAnywhere?

For `addAnywhere`, valid positions are from `0` through `size`, inclusive, because inserting at `size` appends. For `deleteAnywhere`, valid positions are from `0` through `size - 1`, because an existing element must be removed. An invalid insertion prints a message and does not change the list; an invalid deletion prints a message and returns without changing the list.

## 4. Why does LinkedList::concat walk to the end? What if it tracked a tail pointer?

Without a tail pointer, `LinkedList::concat` must start at `head_` and follow `next` pointers until it finds the final node, making the append step O(n). A maintained tail pointer could make appending O(1), but it would need to be updated when adding to or deleting from the list, reversing it, and concatenating another list. The implementation here follows the assignment's requirement not to keep a tail pointer.

## 5. Explain shifting in ArrayList.

In `ArrayList::addAnywhere`, elements are shifted one position to the right, starting at the last element and moving backward toward the insertion position. Moving backward preserves each original element until it has been copied into its new slot. If the loop moved forward, it could overwrite an element before that element had been shifted.

## 6. Where does the Reverse card change the direction of play?

In `main.cpp`, the call `table->reverse();` changes the turn order. The list is printed before and after this call so the reversed order is visible. If the call were missing, the displayed order would remain unchanged and the scene would not demonstrate the Reverse action.
