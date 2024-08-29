#ifndef __BST_H__
#define __BST_H__

#include <stddef.h>

/* type of iterator */
typedef struct node *bst_iter_t;

/* type of the bst management struct */
typedef struct bst bst_t;



/* type of compare_func_t function:
Description - comparison func the user should implemnt as sort criteria.
Params:
	void *data - data from the list.
	void *param - parameter from the user
return value - int.
time complexity - O(n)
space complexity - O(1)
*/
typedef int (*compare_func_t)(const void *data, const void *param);


/* type of action_t functions:
Description - action function implemented by the user return count of errors.
Params:
	void *data - data from the ssl.
	void *param - parameter from the user
return value - size_t - number of errors.
*/
typedef int (*action_func_t)(void *data, const void *param);


/* BSTCreate:
Description - create binary search tree managemet structure.
Params:
	compare_func_t compare_func - sort criteria.
return value - bst_t *
time complexity - O(1)
space complexity - O(1)
*/
bst_t *BSTCreate(compare_func_t cmp_func);


/* BSTDestroy:
Description - destroy binary search tree managemet structure.
Params:
	compare_func_t compare_func - sort criteria.
return value - NONE.
time complexity - O(n)
space complexity - O(1)
*/
void BSTDestroy(bst_t *bst);


/* BSTInsert:
Description - insert node to binary search tree.
Params:
	bst_t *bst - binary search tree.
    const void *data - data from the user.
return value - NONE.
time complexity - O(log n)
space complexity - O(1)
*/
bst_iter_t BSTInsert(bst_t *bst, const void *data);


/* BSTRemove:
Description - insert node to binary search tree.
Params:
	bst_t *bst - binary search tree.
    bst_iter_t iter - binary search tree iterator.
return value - bst_iter_t.
time complexity - O(log n)
space complexity - O(1)
*/
bst_iter_t BSTRemove(bst_iter_t iter);
/* swap with the left node*/


/* BSTFind:
Description - insert node to binary search tree.
Params:
	bst_t *bst - binary search tree.
    const void *data - data from the user.
return value - NONE.
time complexity - O(log n)
space complexity - O(1)
*/
bst_iter_t BSTFind(const bst_t *bst, const void *data);


/* BSTSize:
Description - size of binary search tree.
Params:
	bst_t *bst - binary search tree.
return value - NONE.
time complexity - O(n)
space complexity - O(1)
*/
size_t BSTSize(const bst_t *bst);


/* BSTIsEmpty:
Description - is binary search tree empty.
Params:
	bst_t *bst - binary search tree.
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/
int BSTIsEmpty(const bst_t *bst);


/* BSTForEach:
Description - implement user function on binary search tree.
Params:
	const bst_iter_t from - binary search tree iterator to iterate from.
    const bst_iter_t to - binary search tree iterator to iterate to.
    action_func_t action_func - user action func.
    const void *param - optional param for user.
return value - NONE.
time complexity - O(n)
space complexity - O(1)
*/
int BSTForEach(bst_iter_t from, bst_iter_t to, action_func_t action_func, const void *param);


/* BSTGetData:
Description - get data for node.
Params:
    bst_iter_t iter - binary search tree iterator.
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/
void *BSTGetData(bst_iter_t iter);


/* BSTNext:
Description - get next node in binary search tree.
Params:
    bst_iter_t iter - binary search tree iterator.
return value - NONE.
time complexity - O(n)
space complexity - O(1)
*/
bst_iter_t BSTNext(bst_iter_t iter);


/* BSPrev:
Description - get previous node in binary search tree.
Params:
    bst_iter_t iter - binary search tree iterator.
return value - NONE.
time complexity - O(n)
space complexity - O(1)
*/
bst_iter_t BSTPrev(bst_iter_t iter);


/* BSTBegin:
Description - get root node in binary search tree.
Params:
    const bst_t *bst - binary search tree.
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/
bst_iter_t BSTBegin(const bst_t *bst);


/* BSTEnd:
Description - get dummy node in binary search tree.
Params:
    const bst_t *bst - binary search tree.
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/
bst_iter_t BSTEnd(const bst_t *bst); /*O(log(n))*/


/* BSTIsEqual:
Description - compare two nodes.
Params:
    const bst_t *bst - binary search tree.
return value - NONE.
time complexity - O(1)
space complexity - O(1)
*/
int BSTIsEqual(bst_iter_t iter1, bst_iter_t iter2);


#endif /*__BST_H__*/














