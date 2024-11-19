#include "PriorityQueue.h"
#include "ShortTest.h"
#include <assert.h>
#include <iostream>

bool rel(TPriority p1, TPriority p2) {
	return p1 <= p2;
}




void testAll() { //call each function and see if it exists
	PriorityQueue pq(10,rel);

	assert(pq.isEmpty() == true);
	//adaugam 5, 3, 10, 2, 12 -> rezultat: 2, 3, 5, 10, 12
	pq.push(5, 5);
	assert(pq.top().first == 5);
	assert(pq.top().second == 5);
	pq.push(3, 3);
	assert(pq.top().first == 3);
	assert(pq.top().second == 3);
	pq.push(10, 10);
	assert(pq.top().first == 3);
	assert(pq.top().second == 3);
	pq.push(2, 2);
	assert(pq.top().first == 2);
	assert(pq.top().second == 2);
	pq.push(12, 12);
	assert(pq.top().first == 2);
	assert(pq.top().second == 2);
	assert(pq.isEmpty() == false);
	assert(pq.pop().second == 2);
	assert(pq.top().second == 3);
	assert(pq.pop().second == 3);
	assert(pq.top().second == 5);
	assert(pq.pop().second == 5);
	assert(pq.top().second == 10);
	assert(pq.pop().second == 10);
	assert(pq.top().second == 12);
	assert(pq.pop().second == 12);
	assert(pq.isEmpty() == true);
}

void testIsFull() {
    std::cout << "Test isFull()" << std::endl;

    PriorityQueue pq1(3, rel);
    pq1.push(1, 1);
    pq1.push(2, 2);
    pq1.push(3, 3);
    assert(pq1.isFull() == true);

    PriorityQueue pq2(3, rel);
    pq2.push(1, 1);
    assert(pq2.isFull() == false);

    PriorityQueue pq3(2, rel);
    pq3.push(1, 1);
    pq3.push(2, 2);
    assert(pq3.isFull() == true);

    PriorityQueue pq4(0, rel);
    assert(pq4.isFull() == false); 

   
    PriorityQueue pq5(1, rel);
    pq5.push(1, 1);
    assert(pq5.isFull() == true);

  
    PriorityQueue pq6(3, rel);
    pq6.push(1, 1);
    pq6.push(2, 2);
    pq6.pop();
    assert(pq6.isFull() == false);
    pq6.push(3, 3);
    assert(pq6.isFull() == true);
}


