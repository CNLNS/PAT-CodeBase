#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;
typedef char Elemtype;

typedef struct Node{
	Elemtype name[20];
	Elemtype number[10];
	int score;
	struct Node* next;
}Node, *Lnode;

typedef struct {
	Lnode top;
	Lnode base;
}stack, *Sqstack;

bool Initstack(stack *s) {
	s->base = (Node*)malloc(sizeof(Node));
	s->top = s->base;
	if (s->base == 0) printf("errpr to distribute space!");
	s->top->score = 0;
	return true;
}

bool Push(stack*s, Elemtype *x) {
	Node* p = (Node*)malloc(sizeof(Node));
	//printf("push:%s\n", x);
	int xx = 0;
	int count = 0;
	while (x[xx] != '\0') {
		if (x[xx] == '\a') {
			count++;
		}
		xx++;
	}
	if (count != 2) return false;
	char temp[4];
	int i = 0;
	while (x[i] != '\a') {
		p->name[i] = x[i];
		i++;
	}
	if (i > 10) return false;
	p->name[i] = '\0';
	i++;
	int j = 0;
	while (x[i] != ' ') {
		p->number[j] = x[i];
		i++;
		j++;
	}
	if (j > 10) return false;
	p->number[j] = '\0';
	i++;
	int k = 0;
	while (x[i] != '\0') {
		temp[k] = x[i];
		i++;
		k++;
	}
	temp[k] = '\0';
	int tempscore = 0;
	int t = 0;
	int m = k - 1;
	while (m >= 0) {
		tempscore += (temp[m] - '0')*pow(10, t);
		t++;
		m--;
	}
	if (tempscore > 100 || tempscore < 0) return false;
	//printf("tempscore%d\n", tempscore);
	p->score = tempscore;
	p->next = s->top;
	s->top = p;
	return true;

}
bool deal(stack*s) {
	Lnode p = s->top;
	Lnode min = s->top;
	Lnode max = min;
	//printf("pdate%c\n", p->date[i]);
	while (p != s->base) {
		if (p->score > max->score) {
			max = p;
		}
		if(p->score <min->score) {
			min = p;
		}
		p = p->next;
	}
	cout << max->name << " " << max->number << endl;
	cout <<min->name << " " << min->number << endl;
	return true;
}


bool Input(stack*s) {
	char temp[20];
	cin.getline(temp, 20); 
	Push(s, temp);
	return true;
}

int main() {
	int t;
	stack s;
	Initstack(&s);
	scanf("%d\n", &t);
	while (t) {
		Input(&s);
		t--;
	}
	deal(&s);
	return 0;

}