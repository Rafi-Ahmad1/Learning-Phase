#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

/********************************************************************************************
 * create: Dynamically Creates the Queue ADT and returns pointer to the created Queue ADT   *
 *                                                                                          *
 ********************************************************************************************/
Queue create(void);
/**********************************************************
 * destroy: Destroys the Created Queue ADT using create   *
 *                                                        *
 **********************************************************/
void destroy(Queue Q);

/******************************************************************
 * queue_insert: Inserts the given Item in the Queue at the top   *
 *                                                                *
 ******************************************************************/
void queue_insert(Queue Q, Item i);
/**********************************************************************
 * queue_remove: Removes an Item from the Queue from the bottom and   * 
 *               Returns the removed Item.                            *
 *                                                                    *
 **********************************************************************/
Item queue_remove(Queue Q);
/****************************************************************
 * first_item: Returns the first(to be removed == bottom)       *
 *             Item from the Queue without changing the Queue   *
 *                                                              *
 ***************************************************************/
Item first_item(const Queue Q);
/***************************************************************
 * last_item: Returns the last(to be removed == top)           *
 *            Item from the Queue without changing the Queue   *
 *                                                             *
 ***************************************************************/
Item last_item(const Queue Q);

/***************************************************************
 * make_empty: Makes the Queue Empty by and frees the memory   *
 *             allocated by the nodes.                         *
 *                                                             *
 ***************************************************************/
void make_empty(Queue Q);
/********************************************************
 * is_empty: Check whether the Queue is empty or not    *
 *                                                      *
 ********************************************************/
bool is_empty(const Queue Q);

#endif