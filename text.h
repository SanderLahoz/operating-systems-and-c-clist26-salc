/**
 * @file text.h
 * @brief Header file for implementing operations on list of strings.
 *
 * Lab for practicing basic C programming skills.
 *
 * Developed for ITU course Operating Systems and C.
 * A fork of the C programming lab developed at CMU for courses
 * 15-213/18-213/15-513 by R. E. Bryant, 2017 (extended w/ strings 2018)
 *
 * Accompanying this header file, is a generic list API, `list.h`.
 * Declarations in `text.h` are defined in terms of said API.
 * Definitions  in `text.c` will be     in terms of said API.
 * We recommend starting with `list.h` and `list.c` first.
 *
 * Now that you are done with `list.h` and `list.c`:
 *
 * The testing facility calls the following functions from `text.c` :
 *
 * - text_list_free
 * - text_list_push_front
 * - text_list_push_back
 * - text_list_pop_front
 *
 * We have included other utility functions in `text.c`.
 * While these will not be called directly by the tester, we do
 * encourage that you implement them, since you can then invoke them
 * from the implementation of tested functions, which simplifies the
 * implementation of those functions.
 *
 * TODO: fill in your name and ITU alias
 * @author Sander Lahoz Christensen <salc@itu.dk>
 */

#include <stdbool.h>
#include <stddef.h>

/**** Text data structure *****************************************************/

/**
 * @brief A text is a string that can be part of one linked list.
 */
struct text
{
  char *value;      // Pointer to a string (sequence of characters).
  list_elem_t elem; // List element.
};

typedef struct text text_t; // a type synonym.

/**** Text API ****************************************************************/

/* Get a pointer to the text_t which has e as its elem. */
text_t *text_list_entry(list_elem_t *e);

/* Attempt to insert a text_t with value s at head of l. */
bool text_list_push_front(list_t *l, const char *s);

/* Attempt to insert a text_t with value s at tail of l. */
bool text_list_push_back(list_t *l, const char *s);

/* Attempt to remove text_t at head of l, writing its value to s */
bool text_list_pop_front(list_t *l, char *s, size_t n);

/* Free ALL storage used by l. */
void text_list_free(list_t *l);
