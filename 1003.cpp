#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


int deal() {
	char input[10];
	int i = 0;
	int count = 0;
	printf("input:");
	scanf_s("%s", &input);
	if (strlen(input) >= 100) {
		return 0;
	}
	for (int j = 0; input[j] != '\0'; j++) {
		printf("%c\n", input[j]);
	}
	while (i <= 2) {
		if (input[i] != 'A' && input[i] != 'P' && input[i] != 'T') {
			printf("NO\n");
			return 0;
		}
		else if (input[i] == 'A') {
			count++;
		}
		i++;
	}
	if (count <= strlen(input)) {
		printf("YES\n");
	}
	//printf("%s\n", input);
	return 0;
}

int main() {
	int x;
	printf("you have x dates to solve:");
	scanf_s("%d", &x);
	while (x) {
		deal();
		x--;
	}
	return 0;
}