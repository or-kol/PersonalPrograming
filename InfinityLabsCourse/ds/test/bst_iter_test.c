#include <stdio.h> /* print */
#include <string.h> /* memcmp */



#include "bst_iter.h"

static int IsMatch(const void *val1, const void *val2);
static int operation_add(void *current_val, const void *add_val);

void TestCreate();
void TestInsert();
void TestBegin();
void TestNext();
void TestPrev();
void TestIsEmpty();
void TestIsEqual();
void TestEnd();
void TestGetData();
void TestSize();
void TestRemove();
void TestFind();
void TestForEach();


int main()
{
	TestCreate();
	TestBegin();
	TestNext();
	TestPrev();
	TestInsert();
	TestIsEmpty();
	TestIsEqual();
	TestEnd();
	TestGetData();
	TestSize();
	TestRemove();
	TestFind();
	TestForEach();

	return 0;
}




void TestCreate()
{
	bst_t *bst = BSTCreate(IsMatch);

	bst_iter_t iter1 = BSTBegin(bst);

	if (NULL == iter1)
	{
		printf("Create Success\n");
	}
	else
	{
		printf("Create failed\n");
	}
	
	BSTDestroy(bst);
}


void TestBegin()
{
	bst_t *bst = BSTCreate(IsMatch);

	int z = 50, x = 20, c = 30, v = 70, b = 90, n = 25;
	bst_iter_t iter1 = BSTBegin(bst);

	iter1 = BSTInsert(bst, &z);
	iter1 = BSTInsert(bst, &x);
	iter1 = BSTInsert(bst, &c);
	iter1 = BSTInsert(bst, &v);
	iter1 = BSTInsert(bst, &b);
	iter1 = BSTInsert(bst, &n);

	if (x == *(int *)BSTGetData(BSTBegin(bst)))
	{
		printf("Begin Success\n");
	}
	else
	{
		printf("Begin failed\n");
	}
	
	BSTDestroy(bst);
}


void TestRemove()
{
	bst_t *bst = BSTCreate(IsMatch);

	int z = 50, x = 20, c = 30, v = 70, b = 90, n = 25;
	bst_iter_t iter1 = BSTBegin(bst);
	bst_iter_t iter2 = BSTBegin(bst);

	iter1 = BSTInsert(bst, &z);
	iter1 = BSTInsert(bst, &x);
	iter1 = BSTInsert(bst, &c);
	iter1 = BSTInsert(bst, &v);
	iter1 = BSTInsert(bst, &b);
	iter1 = BSTInsert(bst, &n);
	
	iter2 = BSTRemove(iter1);
	if (5 == BSTSize(bst))
	{
		printf("Remove Success\n");
	}
	else
	{
		printf("Remove failed\n");
	}
	
	BSTDestroy(bst);
}


void TestSize()
{
	bst_t *bst = BSTCreate(IsMatch);

	int z = 50, x = 20, c = 30, v = 70, b = 90, n = 25;
	bst_iter_t iter1 = BSTBegin(bst);

	iter1 = BSTInsert(bst, &z);
	iter1 = BSTInsert(bst, &x);
	iter1 = BSTInsert(bst, &c);
	iter1 = BSTInsert(bst, &v);
	iter1 = BSTInsert(bst, &b);
	iter1 = BSTInsert(bst, &n);

	if (6 == BSTSize(bst))
	{
		printf("Size Success\n");
	}
	else
	{
		printf("Size failed\n");
	}
	
	BSTDestroy(bst);
}


void TestGetData()
{
	bst_t *bst = BSTCreate(IsMatch);

	int z = 50;
	bst_iter_t iter1 = BSTBegin(bst);

	iter1 = BSTInsert(bst, &z);

	if (z == *(int *)BSTGetData(iter1))
	{
		printf("Get Data Success\n");
	}
	else
	{
		printf("Get Data failed\n");
	}
	
	BSTDestroy(bst);
}


void TestEnd()
{
	bst_t *bst = BSTCreate(IsMatch);

	int z = 50, x = 20, c = 30, v = 70, b = 90, n = 25;
	bst_iter_t iter1 = BSTBegin(bst);

	iter1 = BSTInsert(bst, &z);
	iter1 = BSTInsert(bst, &x);
	iter1 = BSTInsert(bst, &c);
	iter1 = BSTInsert(bst, &v);
	iter1 = BSTInsert(bst, &b);
	iter1 = BSTInsert(bst, &n);

	if (NULL == BSTGetData(BSTEnd(bst)))
	{
		printf("End Success\n");
	}
	else
	{
		printf("End failed\n");
	}
	
	BSTDestroy(bst);
}


void TestNext()
{
	bst_t *bst = BSTCreate(IsMatch);

	int z = 50, x = 20, c = 30, v = 70, b = 90, n = 25;
	int q, w, e, r, t, y;
	bst_iter_t iter1 = BSTBegin(bst);

	iter1 = BSTInsert(bst, &z);
	iter1 = BSTInsert(bst, &x);
	iter1 = BSTInsert(bst, &c);
	iter1 = BSTInsert(bst, &v);
	iter1 = BSTInsert(bst, &b);
	iter1 = BSTInsert(bst, &n);

	iter1 = BSTBegin(bst);
	q = *(int *)BSTGetData(iter1);

	iter1 = BSTNext(iter1);
	w = *(int *)BSTGetData(iter1);

	iter1 = BSTNext(iter1);
	e = *(int *)BSTGetData(iter1);

	iter1 = BSTNext(iter1);
	r = *(int *)BSTGetData(iter1);
	
	iter1 = BSTNext(iter1);
	t = *(int *)BSTGetData(iter1);

	iter1 = BSTNext(iter1);
	y = *(int *)BSTGetData(iter1);

	if (x == q && n == w && c == e && z == r && v == t && b == y)
	{
		printf("Next Success\n");
	}
	else
	{
		printf("Next failed\n");
	}
	
	BSTDestroy(bst);
}


void TestPrev()
{
	bst_t *bst = BSTCreate(IsMatch);

	int z = 50, x = 20, c = 30, v = 70, b = 90, n = 25;
	int q, w;
	bst_iter_t iter1 = BSTBegin(bst);
	bst_iter_t iter2 = BSTBegin(bst);

	iter1 = BSTInsert(bst, &z);
	iter1 = BSTInsert(bst, &x);
	iter1 = BSTInsert(bst, &c);
	iter1 = BSTInsert(bst, &v);
	iter2 = BSTInsert(bst, &b);
	iter1 = BSTInsert(bst, &n);

	q = *(int *)BSTGetData(iter2);

	iter2 = BSTPrev(iter2);
	w = *(int *)BSTGetData(iter2);

	if (90 == q && 70 == w)
	{
		printf("Prev Success\n");
	}
	else
	{
		printf("Prev failed\n");
	}
	
	BSTDestroy(bst);
}


void TestInsert()
{
	bst_t *bst = BSTCreate(IsMatch);

	int z = 50, x = 20, c = 30, v = 70, b = 90, n = 25;
	bst_iter_t iter1 = BSTBegin(bst);

	iter1 = BSTInsert(bst, &z);
	iter1 = BSTInsert(bst, &x);
	iter1 = BSTInsert(bst, &c);
	iter1 = BSTInsert(bst, &v);
	iter1 = BSTInsert(bst, &b);
	iter1 = BSTInsert(bst, &n);

	if (n == *(int *)BSTGetData(iter1))
	{
		printf("Insert Success\n");
	}
	else
	{
		printf("Insert failed\n");
	}
	
	BSTDestroy(bst);
}


void TestIsEmpty()
{
	bst_t *bst = BSTCreate(IsMatch);

	int z = 50, x = 20, c = 30, v = 70, b = 90, n = 25;
	bst_iter_t iter1 = BSTBegin(bst);

	if (1 == BSTIsEmpty(bst))
	{
		printf("Is Empty <Empty> Success\n");
	}
	else
	{
		printf("Is Empty <Empty> failed\n");
	}

	iter1 = BSTInsert(bst, &z);
	iter1 = BSTInsert(bst, &x);
	iter1 = BSTInsert(bst, &c);
	iter1 = BSTInsert(bst, &v);
	iter1 = BSTInsert(bst, &b);
	iter1 = BSTInsert(bst, &n);

	if (0 == BSTIsEmpty(bst))
	{
		printf("Is Empty <Not Empty> Success\n");
	}
	else
	{
		printf("Is Empty <Not Empty> failed\n");
	}
	
	BSTDestroy(bst);
}


void TestIsEqual()
{
	bst_t *bst = BSTCreate(IsMatch);

	bst_iter_t iter1 = BSTBegin(bst);
	bst_iter_t iter2 = BSTBegin(bst);
	
	int z = 50;

	if (1 == BSTIsEqual(iter1, iter2))
	{
		printf("Is Equal <Positive Test> success\n");
	}
	else
	{
		printf("Is Equal <Positive Test> fail\n");
	}

	iter1 = BSTInsert(bst, &z);

	if (0 == BSTIsEqual(iter1, iter2))
	{
		printf("Is Equal <Negative Test> success\n");
	}
	else
	{
		printf("Is Equal <Negative Test> fail\n");
	}

	BSTDestroy(bst);
}


void TestFind()
{
	bst_t *bst = BSTCreate(IsMatch);

	int z = 50, x = 20, c = 30, v = 70, b = 90, n = 25, q = 100;
	bst_iter_t iter1 = BSTBegin(bst);

	iter1 = BSTInsert(bst, &z);
	iter1 = BSTInsert(bst, &x);
	iter1 = BSTInsert(bst, &c);
	iter1 = BSTInsert(bst, &v);
	iter1 = BSTInsert(bst, &b);
	iter1 = BSTInsert(bst, &n);

	iter1 = BSTFind(bst, &x);
	if (x == *(int *)BSTGetData(iter1))
	{
		printf("Find <Positive Test> Success\n");
	}
	else
	{
		printf("Find <Positive Test> failed\n");
	}

	iter1 = BSTFind(bst, &q);
	if (NULL == iter1)
	{
		printf("Find <Negative Test> Success\n");
	}
	else
	{
		printf("Find <Negative Test> failed\n");
	}
	
	BSTDestroy(bst);
}


void TestForEach()
{
	bst_t *bst = BSTCreate(IsMatch);

	int z = 50, x = 20, c = 30, v = 70, b = 90, n = 25, a = 3;
	int q, w, e, r, t, y;
	bst_iter_t iter1 = BSTBegin(bst);
	bst_iter_t iter2 = BSTEnd(bst);
	
	iter1 = BSTInsert(bst, &z);
	iter1 = BSTInsert(bst, &x);
	iter1 = BSTInsert(bst, &c);
	iter1 = BSTInsert(bst, &v);
	iter1 = BSTInsert(bst, &b);
	iter1 = BSTInsert(bst, &n);

	iter1 = BSTBegin(bst);
	iter2 = BSTEnd(bst);

	BSTForEach(iter1, iter2, operation_add, &a);

	iter1 = BSTBegin(bst);
	q = *(int *)BSTGetData(iter1);

	iter1 = BSTNext(iter1);
	w = *(int *)BSTGetData(iter1);

	iter1 = BSTNext(iter1);
	e = *(int *)BSTGetData(iter1);

	iter1 = BSTNext(iter1);
	r = *(int *)BSTGetData(iter1);
	
	iter1 = BSTNext(iter1);
	t = *(int *)BSTGetData(iter1);

	iter1 = BSTNext(iter1);
	y = *(int *)BSTGetData(iter1);
	
	if (23 == q && 28 == w && 33 == e && 53 == r && 73 == t && 93 == y)
	{
		printf("For Each Success\n");
	}
	else
	{
		printf("For Each failed\n");
	}
	
	BSTDestroy(bst);
}




static int IsMatch(const void *val1, const void *val2)
{
	return *(int *)val1 - *(int *)val2;
}

static int operation_add(void *current_val, const void *add_val)
{
	*(int *)current_val += *(int *)add_val;
	return 0;
}