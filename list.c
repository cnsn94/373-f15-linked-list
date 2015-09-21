#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	list_t* temp = head;
	list_t* tempb;
	if (new_element->index < head->index) {
		// make new_element the new head
		new_element->next = head;
		return new_element;
	}
	for (int i = 0; temp != NULL && new_element->index > temp->index; ++i) {
		tempb = temp;
		temp = temp->next;
	}
	if (temp != NULL) {
		new_element->next = temp;
	} else {
		new_element->next = NULL;
	}
	tempb->next = new_element;
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	
	list_t* temp1 = head;
	list_t* temp2;
	list_t* temp3 = head;
	uint32_t t;
	
	while (temp3 != NULL) {
		temp1 = head;
		for (int i = 0; temp1->next != NULL; ++i) {
			if (temp1->index < temp1->next->index) {
				t = temp1->index;
				temp1->index = temp1->next->index;
				temp1->next->index = t;
				temp1 = temp1->next;
			} else {
				break;
			}
		}
		temp3 = temp3->next;
	}

	return head;
}

