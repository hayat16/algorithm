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
	Item items[6] = {
		{"i1",  6, 6, 0},
		{"i2", 10, 2, 0},
		{"i3",  3, 1, 0},
		{"i4",  5, 8, 0},
		{"i5",  1, 3, 0},
		{"i6",  3, 5, 0}
	};
	Item temp;
	int n = 6;
	int W = 16;
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
			wt = (W - totalWeight);
			value = wt * (float(items[i].value) / items[i].weight);

			totalWeight += wt;
			totalBenefit += value;

			printf("Selected Item: %s\tWeight: %d\tValue: %f\tTotal Weight: %f\tTotal Benefit: %f\n", items[i].id, wt, value, totalWeight, totalBenefit);

			break;
		}
	}

	printf("Total Weight: %f\n", totalWeight);
	printf("Total Benefit: %f\n", totalBenefit);
}


