/**
 * @file list.h
 * @brief Header file for implementing list operations.
 *
 * Lab for practicing basic C programming skills.
 *
 * Developed for ITU course Operating Systems and C.
 * A fork of the C programming lab developed at CMU for courses
 * 15-213/18-213/15-513 by R. E. Bryant, 2017 (extended w/ strings 2018)
 *
 * The testing facility calls the following functions from `list.h` :
 *
 * - list_new
 * - list_size
 * - list_reverse
 *
 * We have included other utility functions in `list.c`.
 * While these will not be called directly by the tester, we do
 * encourage that you implement them, since you can then invoke them
 * from the implementation of tested functions, which simplifies the
 * implementation of those functions.
 *
 * Notice that this generic list API does not have any function for
 * allocating and deallocating elements.
 *
 * That is because how that is done depends entirely on what data the
 * list stores. We will store strings; we deal with this in `text.h`,
 * which you should head to once you are done with `list.c`.
 *
 * @author Sander Lahoz Christensen <salc@itu.dk>
 */

#include <stdbool.h>
#include <stddef.h>

/************** List data structure ****************/

/**
 * @brief Linked list element.
 */
struct list_elem
{
    struct list_elem *next; /* Next list element. (NULL if end of list.) */
    /*
     * You do not need to change this struct.
     */
};

typedef struct list_elem list_elem_t;

/**
 * @brief Linked list. (NULL if uninitialized.)
 */
struct list
{
    list_elem_t *head; /* Pointer to head. (NULL if list is empty.) */
    list_elem_t *tail; /* Pointer to tail. (NULL if list is empty.) */
    unsigned int size; /* Number of elements in the list. */
};

typedef struct list list_t;

/************** Generic List API ************************/

/* List creation. */
void list_init(list_t *l); // initialize an already-allocated list.
list_t *list_new(void);    // create empty list (allocate & initialize)

/* List traversal. */
list_elem_t *list_begin(list_t *l);     // first element (head)
list_elem_t *list_end(list_t *l);       // last element
list_elem_t *list_next(list_elem_t *l); // next element

/* List insertion. */
void list_push_front(list_t *l, list_elem_t *e); // insert at beginning
void list_push_back(list_t *l, list_elem_t *e);  // insert at end

/* List removal.*/
list_elem_t *list_pop_front(list_t *l); // remove first element (head).

/* Miscellaneous. */
size_t list_size(list_t *l);  // nr. of elements in l.
void list_reverse(list_t *l); // reverses l.
