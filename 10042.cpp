#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
typedef struct student {
	char name[10];
	char number[10];
	int score;
}stu[];

int stoint(char s[]){//字符串转换为数组
	int i = 0;
	int result = 0;
	while (s[i] !=  '\0') {
		i++;
	}
	int j = i - 1;
	i = 0;
	while (j >= 0) {
		result += (s[j] - '0')* pow(10, i++);
		j--;
	}
	return result;
}

bool Input(student *stu) {//输入信息
	char temp[20];	
	cin.getline(temp, 20);
	int i = 0;//控制数组
	while (temp[i] != ' ') {
		stu->name[i] = temp[i];
		i++;
	}
	if (i > 10) return false;
	stu->name[i] = '\0';
	i++;
	int j = 0;
	char s[10];
	while (temp[i] != ' ') {
		stu->number[j] = temp[i];
		//s[k] = temp[j];
		j++;
		i++;
	}
	if (j > 10) return false;
	stu->number[j] = '\0';
	j = 0;
	//stu[i].number = stoint(s);
	i++;
	while (temp[i] != '\0') {
		s[j] = temp[i];
		j++;
		i++;
	}
	s[j] = '\0';
	stu->score = stoint(s);
	if (stu->score > 100 || stu->score < 0) return false;
	return true;
}

bool deal(student*stu, int t,int *minx, int *maxx) {
	int min = 0;
	int max = 0;
	if (t == 0) {
		min = stu[0].score;
		max = stu[0].score;
	}
	if (stu->score < min) {
		min = stu->score;
		*minx = t;
	}
	if (stu->score > max) {
		max = stu->score;
		*maxx = t;
	}
	return true;
}

bool deal00(student *stu) {//找出最小最大分数
	int t = 0;
	int min = stu[0].score;
	int max = stu[0].score;
	int i = 0;
	int minx = 0;
	int maxx = 0;
	while (i < t) {
		if (stu[i].score < min) {
			min = stu[i].score;
			minx = i;
		}
		if (stu[i].score > max) {
			max = stu[i].score;
			maxx = i;
		}
		i++;
	}
	cout << stu[maxx].name << " " << stu[maxx].number << endl;
	cout << stu[minx].name << " " << stu[minx].number << endl;
	return true;
}
int main() {//主函数
	student stu[30];
	int x = 0;
	int i = 0;
	cin >> x;
	cin.ignore();
	while (i < x) {
		Input(&stu[i]);
		i++;
	}
	i = 0;
	int max= 0, min=0;
	while (i < x) {
	deal(&stu[i],i,&min,&max);
	i++;
	}
	//cout << stu[max].name << " " << stu[max].number <<" "<<stu[max].score<< endl;
	//cout << stu[min].name << " " << stu[min].number <<" "<<stu[min].score<<endl;
	cout << stu[max].name << " " << stu[max].number << endl;
	cout << stu[min].name << " " << stu[min].number << endl;
	return 0;
}