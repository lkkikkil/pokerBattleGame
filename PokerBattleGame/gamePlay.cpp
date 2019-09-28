#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

void cardShuffle();
void cardSetting();
void cardShow();
void cardChange(int*);
void playerInformationShow();
void gameSet();
void playerChange();
void turnShow();
void cardUseCheck();

string card[40]
{ "��1", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10",
	"��1", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10",
	"��1", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10",
	"��1", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10" };

vector <int> cardNumber;
vector <int> cardShowNumber;
int player1Hp{ 0 };
int player2Hp{ 0 };
int player1Dia{ 0 };
int player2Dia{ 0 };
int playerNumber{ 0 };
int turn{ 0 };
int cardUseAmount{ 0 };

void gamePlay() {
	srand((unsigned int)time(0));

	gameSet();
	while (true) {
		if (playerNumber == 1) {
			cardChange(&player1Dia);
			cardUseCheck();
		}
		else {
			cardChange(&player2Dia);
			cardUseCheck();
		}
		playerChange();
		turn++;
	}
}

void gameSet() {
	cardShuffle();
	cardSetting();
	player1Hp = 100;
	player1Dia = 10;
	player2Hp = 110;
	player2Dia = 15;
	playerNumber = 1;
	turn = 1;

	playerInformationShow();
	turnShow();
	cardShow();
}

void cardShuffle() {
	int number = rand() % 40;
	for (int cardCounter = 0; cardCounter < 40; cardCounter++) {
		while (count(cardNumber.begin(), cardNumber.end(), number)) {
			number = rand() % 40;
		}
		cardNumber.push_back(number);
	}
}

void cardSetting() {
	cardShowNumber.clear();
	for (int cardSetCounter = 0; cardSetCounter < 7; cardSetCounter++) {
		cardShowNumber.push_back(cardNumber[0]);
		cardNumber.erase(cardNumber.begin());
	}
}

void cardShow() {
	cout << "----------------------------------------\n\n   ";
	for (int cardShowCounter = 0; cardShowCounter < 7; cardShowCounter++) {
		cout << card[cardShowNumber[cardShowCounter]] << "  ";
	}
	cout << "\n\n----------------------------------------\n";
}

void cardChange(int *dia) {
	int changeAmount;
	cout << "��� �ٲٽðڽ��ϱ�? ";
	cin >> changeAmount;

	while (changeAmount > *dia / 3) {
		cout << *dia / 3 << " ������ ���� �Է����ּ���. ";
		cin >> changeAmount;
	}

	*dia -= 3 * changeAmount;

	for (int cardChangeCounter = 1; cardChangeCounter <= changeAmount; cardChangeCounter++) {
		int changeNumber;
		cout << cardChangeCounter << "��°�� �ٲٽ� ī���� ��ȣ�� �Է����ּ��� : ";
		cin >> changeNumber;

		cardShowNumber[changeNumber - 1] = cardNumber[0];
		cardNumber.erase(cardNumber.begin());

		system("cls");
		playerInformationShow();
		turnShow();
		cardShow();
		cout << card[cardShowNumber[changeNumber - 1]] << "�� �ٲ�����ϴ�.\n";
	}
}

void playerInformationShow() {
	cout << "----------------------------------------\n\n    "
		<< "player1         |     player2\n    "
		<< setfill(' ') << "ü�� : " << setw(3) << player1Hp << "      |     ü�� : " << setw(3) << player2Hp << "\n    "
		<< setfill(' ') << "���̾� : " << setw(2) << player1Dia << "     |     ���̾� : " << setw(2) << player2Dia
		<< "\n\n----------------------------------------\n";
}

void playerChange() {
	if (playerNumber == 1) {
		playerNumber = 2;
	}
	else {
		playerNumber = 1;
	}
}

void turnShow() {
	cout << turn << "��° �� �Դϴ�.\n"
		<< "player" << playerNumber << "�� ��\n";
}

void cardUseCheck() {
	int backNumber[10]{ 0 };
	for (int checkCounter = 0; checkCounter < 7; checkCounter++) {
		backNumber[cardNumber[checkCounter] % 10]++;
	}

	cardUseAmount = 1;
	for (int cardUseCheck = 0; cardUseCheck < 10; cardUseCheck++) {
		switch (backNumber[cardUseCheck])
		{
		case 2:
			cardUseAmount += 1;
			break;
		case 3:
			cardUseAmount += 2;
			break;
		case 4:
			cardUseAmount += 4;
			break;
		default:
			break;
		}
	}

	cout << "����� " << cardUseAmount << "���� ī�带 ����� �� �ֽ��ϴ�.\n";
}
