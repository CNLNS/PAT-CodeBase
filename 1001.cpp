#include<stdio.h>

int main(){
	int s;
	int count = 0;
	scanf_s("%d", &s);
	while (s != 1) {
		if (s % 2 == 0) {
			s = s / 2;
			count++;
		}
		else {
			s = (3*s + 1) / 2;
			count++;
		}
	}
	printf("%d", count);
	return 0;
}