#include "gamePlay.h"
#include "gameRule.h"
#include <iostream>

using namespace std;

int main() {
	cout << "이 게임에서 아니오, 예는 각각 0, 1로 대답합니다.\n";

	int ruleOpen{ 0 };
	cout << "게임 설명을 보시겠습니까? ";
	cin >> ruleOpen;

	if (ruleOpen) {
		gameRule();
	}

	int gameOpen{ 0 };
	cout << "게임을 실행하시겠습니까? ";
	cin >> gameOpen;

	while (gameOpen) {
		gamePlay();

		cout << "게임을 다시하시겠습니까? ";
		cin >> gameOpen;
	}
}
