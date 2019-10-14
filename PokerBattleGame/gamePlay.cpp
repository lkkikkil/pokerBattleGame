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
void cardUse(int*, int*, int*);
void randomEffectShow(int, int);
void playerHpCheck();

string card[40]
{ "��1", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10",
	"��1", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10",
	"��1", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10",
	"��1", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10" };

vector <int> player1Deck;
vector <int> player2Deck;
vector <int> cardShowNumber;
vector<int> useCheck;

int player1Hp{ 0 };
int player2Hp{ 0 };
int player1Dia{ 0 };
int player2Dia{ 0 };
int playerNumber{ 0 };
int turn{ 0 };
int cardUseAmount{ 0 };
int nextTurn{ 0 };

void gamePlay() {
	srand((unsigned int)time(0));

	gameSet();
	while (nextTurn) {
		system("cls");

		cardSetting();

		playerInformationShow();
		turnShow();
		cardShow();

		if (playerNumber == 1) {
			cardChange(&player1Dia);
			cardUseCheck();
			cardUse(&player1Hp, &player1Dia, &player2Hp);
		}
		else {
			cardChange(&player2Dia);
			cardUseCheck();
			cardUse(&player2Hp, &player2Dia, &player1Hp);
		}
		playerHpCheck();
	}
}

void gameSet() {
	cardShuffle();
	player1Hp = 100;
	player1Dia = 10;
	player2Hp = 110;
	player2Dia = 15;
	playerNumber = 1;
	turn = 1;
	nextTurn = 1;
}

void cardShuffle() {
	int number = rand() % 40;
	if (playerNumber == 1) {
		for (int cardCounter = 0; cardCounter < 40; cardCounter++) {
			while (count(player1Deck.begin(), player1Deck.end(), number)) {
				number = rand() % 40;
			}
			player1Deck.push_back(number);
		}
	}
	else {
		for (int cardCounter = 0; cardCounter < 40; cardCounter++) {
			while (count(player2Deck.begin(), player2Deck.end(), number)) {
				number = rand() % 40;
			}
			player2Deck.push_back(number);
		}
	}
	
}

void cardSetting() {
	cardShowNumber.clear();

	if (playerNumber == 1) {
		for (int cardSetCounter = 0; cardSetCounter < 7; cardSetCounter++) {
			if (player1Deck.empty()) {
				cardShuffle();
			}

			cardShowNumber.push_back(player1Deck[0]);
			player1Deck.erase(player1Deck.begin());
		}
	}
	else {
		for (int cardSetCounter = 0; cardSetCounter < 7; cardSetCounter++) {
			if (player2Deck.empty()) {
				cardShuffle();
			}

			cardShowNumber.push_back(player2Deck[0]);
			player2Deck.erase(player2Deck.begin());
		}
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

	if (playerNumber == 1) {
		for (int cardChangeCounter = 1; cardChangeCounter <= changeAmount; cardChangeCounter++) {
			if (player1Deck.empty()) {
				cardShuffle();
			}

			int changeNumber;
			cout << cardChangeCounter << "��°�� �ٲٽ� ī���� ��ȣ�� �Է����ּ��� : ";
			cin >> changeNumber;

			cardShowNumber[changeNumber - 1] = player1Deck[0];
			player1Deck.erase(player1Deck.begin());

			system("cls");
			playerInformationShow();
			turnShow();
			cardShow();
			cout << card[cardShowNumber[changeNumber - 1]] << "�� �ٲ�����ϴ�.\n";
		}
	}
	else {
		for (int cardChangeCounter = 1; cardChangeCounter <= changeAmount; cardChangeCounter++) {
			if (player2Deck.empty()) {
				cardShuffle();
			}

			int changeNumber;
			cout << cardChangeCounter << "��°�� �ٲٽ� ī���� ��ȣ�� �Է����ּ��� : ";
			cin >> changeNumber;

			cardShowNumber[changeNumber - 1] = player2Deck[0];
			player2Deck.erase(player2Deck.begin());

			system("cls");
			playerInformationShow();
			turnShow();
			cardShow();
			cout << card[cardShowNumber[changeNumber - 1]] << "�� �ٲ�����ϴ�.\n";
		}
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
		backNumber[cardShowNumber[checkCounter] % 10]++;
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

void cardUse(int* attackerHp, int* attackerDia, int* victimHp) {
	int useInformation[3]{ 0 };

	useCheck.clear();

	for (int useCounter = 1; useCounter <= cardUseAmount; useCounter++) {
		int useNumber;
		cout << useCounter << "��°�� ����Ͻ� ī���� ��ȣ�� �Է����ּ��� : ";
		cin >> useNumber;

		while (count(useCheck.begin(), useCheck.end(), useNumber)) {
			cout << useNumber << "�� ī��� �̹� ����߽��ϴ�. �ٸ� ī�带 �Է��� �ּ��� : ";
			cin >> useNumber;
		}

		useCheck.push_back(useNumber);

		int randomEffect = rand() % 3;

		switch (cardShowNumber[useNumber - 1] / 10)
		{
		case 0:
			useInformation[0] += (cardShowNumber[useNumber - 1] % 10) + 1; // damage
			break;
		case 1:
			useInformation[1] += (cardShowNumber[useNumber - 1] % 10) + 1; // dia
			break;
		case 2:
			useInformation[2] += (cardShowNumber[useNumber - 1] % 10) + 1; //heal
			break;
		case 3:
			useInformation[randomEffect] += (cardShowNumber[useNumber - 1] % 10) + 1; // random effect
			randomEffectShow(randomEffect, (cardShowNumber[useNumber - 1] % 10) + 1);
			break;
		default:
			break;
		}
	}

	cout << "������ : " << useInformation[0] << "\n"
		<< "�߰� ���̾� : " << useInformation[1] << "\n"
		<< "ü�� ȸ�� : " << useInformation[2] << "\n";

	*victimHp -= useInformation[0];
	*attackerDia += useInformation[1];
	*attackerHp += useInformation[2];
}

void randomEffectShow(int randomEffectNumber, int _cardNumber) {
	switch (randomEffectNumber)
	{
	case 0:
		cout << "��";
		break;
	case 1:
		cout << "��";
		break;
	case 2:
		cout << "��";
		break;
	default:
		break;
	}
	cout << _cardNumber << "�� �ٲ�����ϴ�.\n";
}

void playerHpCheck() {
	if (player1Hp == 0) {
		playerInformationShow();
		cout << "player1�� ü���� 0�� �Ǿ����ϴ�.\n"
			<< "player2�� �¸��Ͽ����ϴ�.\n";
		nextTurn = 0;
	}
	else if (player2Hp == 0) {
		playerInformationShow();
		cout << "player2�� ü���� 0�� �Ǿ����ϴ�.\n"
			<< "player1�� �¸��Ͽ����ϴ�.\n";
		nextTurn = 0;
	}
	else {
		cout << "���� �ѱ�ðڽ��ϱ�? ";
		cin >> nextTurn;

		turn++;
		playerChange();
	}
}
