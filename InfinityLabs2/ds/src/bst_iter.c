#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */

#include "bst_iter.h"

enum children {
    LEFT = 0,
    RIGHT = 1,
    NUM_OF_CHILD = 2
};

typedef struct node node_t;

struct node
{
    void *data;
    node_t *parent;
    node_t *child_node[NUM_OF_CHILD];
};

struct bst
{
    node_t root_dummy;
    compare_func_t cmp_func;
};

static bst_iter_t LocateInsert(const bst_t *bst, const void *data);
static bst_iter_t LeftMost(bst_iter_t node);
static bst_iter_t RightMost(bst_iter_t node);


bst_t *BSTCreate(compare_func_t cmp_func)
{
    bst_t *new_bst = (bst_t *)malloc(sizeof(bst_t));
    if (NULL == new_bst)
    {
        return NULL;
    }
    
    new_bst->root_dummy.data = NULL;
    new_bst->root_dummy.child_node[LEFT] = NULL;
    new_bst->root_dummy.child_node[RIGHT] = NULL;
    new_bst->cmp_func = cmp_func;

    return new_bst;
}


void BSTDestroy(bst_t *bst)
{
    bst_iter_t runner = bst->root_dummy.child_node[LEFT];

    assert(NULL != bst);

    while(0 == BSTIsEmpty(bst))
    {
        runner = bst->root_dummy.child_node[LEFT];
        BSTRemove(runner);
    }

    free(bst);
}


bst_iter_t BSTInsert(bst_t *bst, const void *data)
{
    bst_iter_t runner = LocateInsert(bst, data);

    assert(NULL != bst);
    assert(NULL != data);

    if (NULL == runner)
    {
        bst->root_dummy.child_node[LEFT] = (node_t *)malloc(sizeof(node_t));
        runner = bst->root_dummy.child_node[LEFT];
        if (NULL == runner)
        {
            return NULL;
        }

        runner->data = (void *)data;
        runner->parent = &bst->root_dummy;
        runner->child_node[LEFT] = NULL;
        runner->child_node[RIGHT] = NULL;

        return runner;
    }
    else if (bst->cmp_func(runner->data,data) > 0)
    {
        runner->child_node[LEFT] = (node_t *)malloc(sizeof(node_t));
        if (NULL == runner->child_node[LEFT])
        {
            return NULL;
        }

        runner->child_node[LEFT]->data = (void *)data;
        runner->child_node[LEFT]->parent = runner;
        runner->child_node[LEFT]->child_node[LEFT] = NULL;
        runner->child_node[LEFT]->child_node[RIGHT] = NULL;

        return runner->child_node[LEFT];
    }
    else
    {
        runner->child_node[RIGHT] = (node_t *)malloc(sizeof(node_t));
        if (NULL == runner->child_node[RIGHT])
        {
            return NULL;
        }

        runner->child_node[RIGHT]->data = (void *)data;
        runner->child_node[RIGHT]->parent = runner;
        runner->child_node[RIGHT]->child_node[LEFT] = NULL;
        runner->child_node[RIGHT]->child_node[RIGHT] = NULL;

        return runner->child_node[RIGHT];
    }
}


bst_iter_t BSTRemove(bst_iter_t iter)
{
    bst_iter_t remove = (node_t *)iter;
    bst_iter_t right= NULL;
    bst_iter_t ret_val = NULL;
    enum children prev = (remove == remove->parent->child_node[LEFT])? LEFT : RIGHT;

    assert(NULL != iter);

    if (NULL != remove->child_node[LEFT])
    {
        right = RightMost(remove->child_node[LEFT]);
        right->child_node[RIGHT] = remove->child_node[RIGHT];
        remove->parent->child_node[prev] = remove->child_node[LEFT];
        remove->child_node[LEFT]->parent = remove->parent;

        if (NULL != remove->child_node[RIGHT])
        {
            remove->child_node[RIGHT]->parent = right;
        }
    }
    else
    {
        remove->parent->child_node[prev] = remove->child_node[RIGHT];
        if (NULL != remove->child_node[RIGHT])
        {
            remove->child_node[RIGHT]->parent = remove->parent;
        }
    }

    ret_val = remove->parent->child_node[prev];

    free(remove);
    
    return ret_val;
}


bst_iter_t BSTFind(const bst_t *bst, const void *data)
{
    bst_iter_t ret_val = LocateInsert(bst, data);

    assert(NULL != bst);
    assert(NULL != data);

    if (0 == bst->cmp_func(ret_val->data, data))
    {
        return ret_val;
    }

    return NULL;
}


size_t BSTSize(const bst_t *bst)
{
    bst_iter_t iter = BSTBegin(bst);
    size_t count = 0;

    assert(NULL != bst);

    while (NULL != iter)
    {
        iter = BSTNext(iter);
        ++count;
    }

    return count;
}


int BSTIsEmpty(const bst_t *bst)
{
    assert(NULL != bst);

    return (NULL == bst->root_dummy.child_node[LEFT]);
}


int BSTForEach(bst_iter_t from, bst_iter_t to, action_func_t action_func, const void *param)
{
    bst_iter_t runner = from;
	int failure_counter = 0;
	
	assert(NULL != from);
	assert(NULL != to);
	assert(NULL != param);
	
	while (runner != to && NULL != runner)
	{
        if (0 == action_func(runner->data, (void *)param))
        {
            ++failure_counter;
        }

        runner = BSTNext(runner);
	}
	
	return failure_counter;
}


void *BSTGetData(bst_iter_t iter)
{
    assert(NULL != iter);
    
    return iter->data;
}


bst_iter_t BSTNext(bst_iter_t iter)
{
    node_t *runner = (node_t *)iter;

    assert(NULL != iter);

    if(NULL != runner->child_node[RIGHT])
    {
        return (bst_iter_t)LeftMost(runner->child_node[RIGHT]);
    }

    while(NULL != runner->parent->data && 1 == BSTIsEqual(runner, runner->parent->child_node[RIGHT]))
    {
        runner = runner->parent;
    }

    if (NULL != runner->parent->data)
    {
        return (bst_iter_t)runner->parent;
    }
    else
    {
        return NULL;
    }
}


bst_iter_t BSTPrev(bst_iter_t iter)
{
    bst_iter_t runner = iter;

    assert(NULL != iter);

    if(NULL != iter->child_node[LEFT])
    {
        return RightMost(iter->child_node[LEFT]);
    }

    while(NULL != runner->parent->data && 1 == BSTIsEqual(runner, runner->parent->child_node[LEFT]))
    {
        runner = runner->parent;
    }

    if ((NULL != runner->parent->data))
    {
        return runner->parent;
    }
    else
    {
        return NULL;
    }
}


bst_iter_t BSTBegin(const bst_t *bst)
{
    bst_iter_t runner = bst->root_dummy.child_node[LEFT];

    assert(NULL != bst);

    if (NULL == runner)
    {
        return NULL;
    }

    return LeftMost(runner);
}


bst_iter_t BSTEnd(const bst_t *bst)
{
    assert(NULL != bst);

    return (bst_iter_t)(&bst->root_dummy);
}


int BSTIsEqual(bst_iter_t iter1, bst_iter_t iter2)
{
    return iter1 == iter2;
}




static bst_iter_t LeftMost(bst_iter_t iter)
{
    while (NULL != iter->child_node[LEFT])
    {
        iter = iter->child_node[LEFT];
    }

    return iter;
}


static bst_iter_t RightMost(bst_iter_t iter)
{
    while (NULL != iter->child_node[RIGHT])
    {
        iter = iter->child_node[RIGHT];
    }

    return iter;
}


static node_t *LocateInsert(const bst_t *bst, const void *data)
{
    node_t *runner = bst->root_dummy.child_node[LEFT];
    node_t *prev = runner;
    while(NULL != runner)
    {
        prev = runner;
        if (bst->cmp_func(runner->data,data) > 0)
        {
            runner = runner->child_node[LEFT];
        }
        else if (bst->cmp_func(runner->data,data) < 0)
        {
            runner = runner->child_node[RIGHT];
        }
        else
        {
            return runner;
        }
    }
    return prev;
}




