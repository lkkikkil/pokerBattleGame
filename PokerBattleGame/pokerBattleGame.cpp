#include "gamePlay.h"
#include "gameRule.h"
#include <iostream>

using namespace std;

int main() {
	cout << "�� ���ӿ��� �ƴϿ�, ���� ���� 0, 1�� ����մϴ�.\n";

	int ruleOpen{ 0 };
	cout << "���� ������ ���ðڽ��ϱ�? ";
	cin >> ruleOpen;

	if (ruleOpen) {
		gameRule();
	}

	int gameOpen{ 0 };
	cout << "������ �����Ͻðڽ��ϱ�? ";
	cin >> gameOpen;

	while (gameOpen) {
		gamePlay();

		cout << "������ �ٽ��Ͻðڽ��ϱ�? ";
		cin >> gameOpen;
	}
}
