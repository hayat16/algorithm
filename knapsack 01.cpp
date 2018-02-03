#include <stdio.h>

struct Item {
	char id[5];
	int weight;
	int value;
	float density;
};

void fractionalKnapsack(Item items[], int n, int W);

int main(void) {

	int i, j;
	Item items[4] = {
		{"i1",  3, 100, 0},
		{"i2", 2, 20, 0},
		{"i3",  4, 60, 0},
		{"i4",  1, 40, 0},
	};
	Item temp;
	int n = 4;
	int W = 5;
	for(i = 0; i < n; i++) {
		items[i].density = float(items[i].value) / items[i].weight;
	}
	for(i = 1; i < n; i++) {
		for(j = 0; j < n - i; j++) {
			if(items[j+1].density > items[j].density) {
				temp = items[j+1];
				items[j+1] = items[j];
				items[j] = temp;
			}
		}
	}

	fractionalKnapsack(items, n, W);

	return 0;
}

void fractionalKnapsack(Item items[], int n, int W) {
	int i, wt;
	float value;

	float totalWeight = 0, totalBenefit = 0;

	for(i = 0; i < n; i++) {
		if(items[i].weight + totalWeight <= W) {

			totalWeight += items[i].weight;
			totalBenefit += items[i].value;

			printf("Selected Item: %s\tWeight: %d\tValue: %d\tTotal Weight: %f\tTotal Benefit: %f\n\n", items[i].id, items[i].weight, items[i].value, totalWeight, totalBenefit);

		} else {

			break;
		}
	}

	printf("Total Weight: %f\n", totalWeight);
	printf("Total Benefit: %f\n", totalBenefit);
}

