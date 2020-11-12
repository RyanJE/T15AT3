typedef struct item {
	int k;
	int j;
	/* ... other fields ...*/
} Item;

int itemCmp(Item a, Item b) { 
	if (a.k < b.k) {
		return -1;
	} else if (a.k > b.k) {
		return 1;
	} else if (a.j < b.j){
		return -1;
	} else if (a.j > b.j) {
		return 1;
	} else {
		return 0;
	}
}