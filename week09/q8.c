typedef struct item {
	int k;
	int j;
	/* ... other fields ...*/
} Item;
int isStableSort(Item original[], Item sorted[], int size) { 
    Item *new = malloc(sizeof(Item)*size);
    stableSort(new,original)
    for (int i = 0; i < size; ++i) {
        if (new[i] != sorted[i]) return false;
    }
    return true;
}

int isStableSort(Item original[], Item sorted[], int size) { 
    for (int i = 0 ; i < size;++i) {
        Item tmp = sorted[i];
        int orig_ind;
        for (int j = i; j < size;++j) {
            if (tmp == original[j]) {
                orig_ind = j;
                break;
            }
        }
        int count = 0;
        for (int j = i; j < size;++j) {
            if (sorted[j].k == tmp.k) count++;
        }
        for (int j = orig_ind; j < size;++j) {
            if (original[j].k == tmp.k) count--;
        }
        if (count != 0) {
            return false;
        }
    }
    return true;
}

