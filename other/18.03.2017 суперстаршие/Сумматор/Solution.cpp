#include <stdio.h>

int t[100000];
int size;

void init(int n) {
	size = n;
	for (int i = 0; i < size; i++) {
		t[i] = 0;
	}
}

int prev(int x) {
	return (x & (x + 1));
}

int next(int x) {
	return (x | (x + 1));
}

int sum(int r) {
	int result = 0;
	while ( r >= 0 ) {
		result += t[r];
		r = prev(r) - 1;
	}
	return result;
}

int sum(int l, int r) {
	return sum(r) - sum(l - 1);
}

void modify(int pos, int value) {
	while ( pos < size ) {
		t[pos] += value;
		pos = next ( pos );
	}
}

int main ( ) {
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	while (! feof(fin) ) {
		int operation = -1;
		fscanf(fin, "%d", &operation);
		switch(operation) {
			case 1 : {
						int newSize;
						fscanf(fin, "%d", &newSize);
						init(newSize);
						break;
					 }
			case 2 : {
						int pos;
						int value;
						fscanf(fin, "%d %d", &pos, &value);
						modify(pos - 1, value);
						break;
					 }
			case 3 : {
						int l;
						int r;
						fscanf(fin, "%d %d", &l, &r);
						fprintf(fout, "%d\n", sum(l - 1,r - 1));
						break;
					 }
		}
	}
	fclose(fin);
	fclose(fout);

	return 0;
}

