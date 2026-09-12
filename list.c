/**
 * @file list.c
 * @brief Implementation of a list that supports FIFO and LIFO operations.
 *
 * The underlying data structure is a singly-linked list.
 *
 * This is part of a lab on basic C programming skills.
 * Developed for ITU course Operating Systems and C.
 * A fork of the C programming lab developed at CMU for courses
 * 15-213/18-213/15-513 by R. E. Bryant, 2018
 *
 * @author Sander Lahoz Christensen <salc@itu.dk>
 */

#include "list.h"
#include "harness.h"

#include <stdlib.h>
#include <string.h>

/**
 * @brief Returns the first element in the list.
 *
 * @param[in] l The list to examine
 *
 * @return the first element in the list, or NULL if the list is NULL
 * or empty.
 */
list_elem_t *list_begin(list_t *l)
{
  /* What if the list is NULL? */
  if (l == NULL)
  {
    return NULL;
  }

  return l->head;
}

/**
 * @brief Returns the next element.
 *
 * @param[in] e The element to examine
 *
 * @return the next element, or NULL if the element is NULL.
 */
list_elem_t *list_next(list_elem_t *e)
{
  /* What if the element is NULL? */
  if (e == NULL)
  {
    return NULL;
  }

  return e->next;
}

/**
 * @brief Returns the last element in the list.
 *
 * This function runs in O(1) time.
 *
 * @param[in] l The list to examine
 *
 * @return the last element in the list, or NULL if the list is NULL
 * or empty.
 */
list_elem_t *list_end(list_t *l)
{
  /* What if the list is NULL? */
  if (l == NULL)
  {
    return NULL;
  }
  /* Remember: This function should operate in O(1) time. */
  return l->tail;
}

/**
 * @brief Returns the number of elements in the list
 *
 * This function runs in O(1) time.
 *
 * @param[in] l The list to examine
 *
 * @return the number of elements in l, or 0 if l is NULL or empty
 */
size_t list_size(list_t *l)
{
  /* What if the list is NULL? */
  if (l == NULL)
  {
    return 0;
  }

  /* Remember: This function should operate in O(1) time. */
  return l->size;
}

/**
 * @brief Allocates a new list
 *
 * @return The new list, or NULL if memory allocation failed
 */
list_t *list_new(void)
{
  /* Please fix up this code. */
  list_t *l = malloc(sizeof(list_t));
  if (l == NULL)
  {
    return NULL;
  }
  list_init(l);
  return l;
}

/**
 * @brief Initializes the given list.
 *
 * This function neither allocates nor frees memory; depending on what
 * you are doing, you may need to allocate `l` or free its elements
 * before calling this function.
 *
 * @param[in] l The list to initialize
 */
void list_init(list_t *l)
{
  /* Please fix up this code. */
  l->head = NULL;
  l->tail = NULL;
  l->size = 0;
  return;
}

/**
 * @brief Initializes the given list to a singleton list containing
 * only the given element.
 *
 * This function neither allocates nor frees memory; depending on what
 * you are doing, you may need to allocate `l` or free its elements
 * before calling this function.
 *
 * @param[in] l The list to initialize
 */
void list_singleton(list_t *l, list_elem_t *e)
{
  /* Please fix up this code. */
  l->head = e;
  l->tail = e;
  l->size = 1;
  return;
}

/**
 * @brief Insert the given element to the front of the given list.
 *
 * @param[in] l The list to insert into
 * @param[in] e Element to be inserted
 */
void list_push_front(list_t *l, list_elem_t *e)
{
  /* What if l or e are NULL? */
  if (l == NULL || e == NULL)
  {
    return;
  }

  e->next = l->head;
  l->head = e;

  if (l->tail == NULL)
  {
    l->tail = e;
  }

  l->size++;
}

/**
 * @brief Insert the given element to the back of the given list.
 *
 * This function runs in O(1) time.
 *
 * @param[in] l The list to insert into
 * @param[in] e Element to be inserted
 */
void list_push_back(list_t *l, list_elem_t *e)
{
  /* What if l or e are NULL? */
  if (l == NULL || e == NULL)
  {
    return;
  }

  /* Remember: This function should operate in O(1) time. */
  e->next = NULL;

  if (l->head == NULL)
  {
    l->head = e;
    l->tail = e;
  }
  else
  {
    l->tail->next = e;
    l->tail = e;
  }

  l->size++;

  return;
}

/**
 * @brief Removes an element from the front of the list.
 *
 * This function does not free memory; it simply returns a pointer to
 * the front element, and updates the list such that the front element
 * is no longer part of the list.
 *
 * @param[in]  l The list to remove from
 *
 * @return pointer to first element in l (after its removal from l)
 */
list_elem_t *list_pop_front(list_t *l)
{
  /* What if l or e are NULL? */
  if (l == NULL || l->head == NULL)
  {
    return NULL;
  }
  list_elem_t *e = l->head;
  l->head = e->next;
  l->size--;

  return e;
}

/**
 * @brief Reverse the list.
 *
 * This function does not allocate or free any list elements, i.e. it
 * does not call malloc or free, including inside helper functions. It
 * simply rearranges the existing elements of the queue.
 *
 * @param[in] l The list to reverse
 */
void list_reverse(list_t *l)
{
  if (l == NULL || l->head == NULL)
  {
    return;
  }

  /* You need to write the code for this function */
  /* This is challenging; our reference implementation has 12-13 lines
     of code. */
  list_elem_t *prev = NULL;
  list_elem_t *curr = l->head;
  list_elem_t *next = NULL;

  while (curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  l->head = prev;

  while (l->tail->next != NULL)
  {
    l->tail = l->tail->next;
  }

  return;
}

/**
 * @brief Removes an element from the back of the list.
 *
 * This function runs in O(1) time.
 *
 * This function does not free memory; it simply returns a pointer to
 * the front element, and updates the list such that the front element
 * is no longer part of the list.
 *
 * @param[in]  l The list to remove from
 *
 * @return pointer to last element in l (after its removal from l)
 */
list_elem_t *list_pop_back(list_t *l)
{
  /* What if l or e are NULL? */
  /* Remember: This function should operate in O(1) time. */
  /* This is very challenging, and strictly OPTIONAL.
     This function is NOT NEEDED by any function called by the tester.
     We have included this function strictly for students that are up
     for a challenge.
     Existing functions let you get the last element in constant time,
     but not the second-last element. To resolve that issue, you need
     to revisit the definition of the `list_elem` struct. */
  return NULL;
}
