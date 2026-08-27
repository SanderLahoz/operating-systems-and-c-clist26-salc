/**
 * @file text.c
 * @brief Implementation of a list of strings.
 *
 * The underlying data structure is the list defined in list.h.
 *
 * This is part of a lab on basic C programming skills.
 * Developed for ITU course Operating Systems and C.
 * A fork of the C programming lab developed at CMU for courses
 * 15-213/18-213/15-513 by R. E. Bryant, 2018
 *
 * TODO: fill in your name and ITU alias
 * @author FIRSTNAME LASTNAME <ALIAS@itu.dk>
 */

#include "list.h"
#include "text.h"
#include "harness.h"

#include <stdlib.h>
#include <string.h>

/**
 * @brief Converts a pointer to a list element `e` into a pointer to
 * the text that has `e` as its `elem`.
 *
 * @param[in] e Pointer to the list element
 *
 * @return Pointer to the `text_t` which has `e` as its elem.
 */
text_t* text_list_entry(list_elem_t* e) {
  /* Sorcery?!
     Actually not:
     Suppose you have the memory address to (start of) a text_t.
     I.e. a pointer t to said text_t. 
     What is, then, the memory address of t->next?
     (Look at how text_t and list_elem_t are defined).
     Now instead,
     Suppose you have the memory address to a list_elem_t
     that is the elem of some text_t, t.
     I.e. a pointer e to said list_elem_t.
     What is, then, the memory address of t?
     Make a serious attempt at finding the answer,
     by debugging and educating yourself about pointer arithmetic.
     For debugging, if ptr is a pointer, then you can use
       printf("Memory address of ptr is %p\n", ptr);
     Once you have an answer, or get hard-stuck finding one,
     then you may use the answer from ptr-sol.txt . */
  return NULL;
}

/**
 * @brief Allocates memory for a new `text_t` `t`, and copies the contents 
 * of `s` into `t->value`.
 *
 * @param[in] s Pointer to a string.
 *
 * @return Pointer to a freshly allocated text_t containing a copy of `s`
 * as its value, or `NULL` if allocation failed.
 */
text_t* text_malloc ( const char* s ) {
  text_t* t = malloc(sizeof(text_t));
  /* Don't forget to allocate space for the string and copy it */
  /* What if either call to malloc returns NULL? */
  return t;
}

/**
 * @brief Frees memory for a given text_t t, and copies the first n
 * characters of t->value into s.
 *
 * @param[in] t Pointer to a text_t
 * @param[in] s Pointer to a string
 * @param[in] n Size of s
 */
void text_free ( text_t* t, char* s, size_t n ) {
  /* What if t is NULL? */
  /* What if s is NULL? */
  /* Does the following statement free everything that got allocated 
     when t was allocated? */
  free ( t );
}

/**
 * @brief Insert an element to the front of the list.
 *
 * This function explicitly allocates space to create a copy of `s`.
 * The inserted element points to a copy of `s`, not `s` itself.
 *
 * @param[in] l The list to insert into
 * @param[in] s String to be copied and inserted into the list
 *
 * @return true if insertion was successful
 * @return false if l or s are NULL, or memory allocation failed
 */
bool text_list_push_front(list_t* l, const char* s) {
  /* You do not need to change this code in any way. 
     But you do need to implement
      - text_malloc     (in this file), and
      - list_push_front (in list.c). */
  if ( s == NULL ) { return false; } // nothing to insert
  if ( l == NULL ) { return false; } // list undefined
  text_t* t = text_malloc ( s );
  if ( t == NULL ) { return false; } // malloc failed
  list_push_front(l, &(t->elem));
  return true;
}

/**
 * @brief Insert a element to the back of the list.
 *
 * This function explicitly allocates space to create a copy of `s`.
 * The inserted element points to a copy of `s`, not `s` itself.
 *
 * @param[in] l The list to insert into
 * @return false if l or s are NULL, or memory allocation failed
 *
 * @return true if insertion was successful
 * @return false if l is NULL, or memory allocation failed
 */
bool text_list_push_back(list_t* l, const char* s) {
  /* You do not need to change this code in any way. 
     But you do need to implement
      - text_malloc     (in this file), and
      - list_push_back  (in list.c). */
  if ( s == NULL ) { return false; } // nothing to insert
  if ( l == NULL ) { return false; } // list undefined
  text_t* t = text_malloc ( s );
  if ( t == NULL ) { return false; }
  list_push_back(l, &(t->elem));
  return true;
}

/**
 * @brief Removes an element from the front of the list.
 *
 * If removal succeeds, this function frees all memory used by the
 * removed list element and its string value before returning.
 *
 * If removal succeeds and `c` is non-NULL, this function copies up to
 * `n - 1` characters from the removed string into `c`, and writes a
 * null terminator '\0' after the copied string.
 *
 * @param[in]  l The list to remove from
 * @param[out] c Output string buffer to write to
 * @param[in]  n Size of buffer c points to
 *
 * @return true if removal succeeded
 * @return false if l is NULL or empty
 */
bool text_list_pop_front(list_t* l, char* s, size_t n) {
  /* You do not need to change this code in any way. 
     But you do need implement
      - text_free       (in this file), and
      - list_pop_front  (in list.c). */
  if ( l == NULL ) { return false; } // list undefined
  list_elem_t* e = list_pop_front ( l );
  if ( e == NULL ) { return false; } // list was empty
  text_free ( text_list_entry( e ), s, n );
  return true;
}

/**
 * @brief Frees all memory used by a list
 *
 * @param[in] l The list to free
 */
void text_list_free( list_t* l ) {
  /* Free list structure */
  free ( l );
  /* How about the list elements, and the strings within each? */
}
