typedef struct Node *List;
struct Node {
	int value;
	List next;
};

List selectionSort(List ls) { 
	List old = ls;
	List sorted = NULL; // result
	
	while (old != NULL) {
		// find largest node in old list
		List max = listMax(old);
		
		// unlink largest node in old list
		old = listUnlinkNode(old, max);
		
		// add node to beginning of list
		max->next = sorted;
		sorted = max;
	}
	
	return sorted;
}

// Returns a pointer to the node containing the largest
// element of the given list.
static List listMax(List ls) {
	List max = ls;
	for (List curr = ls; curr != NULL; curr = curr->next) {
		if (curr->value > max->value) {
			max = curr;
		}
	}
	return max;
}

// Removes a given node from a list without freeing it.
static List listUnlinkNode(List ls, List node) {
	if (ls == node) {
		return ls->next;
	} else {
		ls->next = listUnlinkNode(ls->next, node);
		return ls;
	}
}
