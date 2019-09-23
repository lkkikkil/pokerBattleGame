#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

void cardShuffle();
void cardSetting();
void cardShow();
void cardChange();
void playerInformationShow();

string card[40]
{ "♠1", "♠2", "♠3", "♠4", "♠5", "♠6", "♠7", "♠8", "♠9", "♠10",
	"◆1", "◆2", "◆3", "◆4", "◆5", "◆6", "◆7", "◆8", "◆9", "◆10",
	"♥1", "♥2", "♥3", "♥4", "♥5", "♥6", "♥7", "♥8", "♥9", "♥10",
	"♣1", "♣2", "♣3", "♣4", "♣5", "♣6", "♣7", "♣8", "♣9", "♣10" };

vector <int> cardNumber;
vector <int> cardShowNumber;
int player1Hp{ 0 };
int player2Hp{ 0 };
int player1Dia{ 0 };
int player2Dia{ 0 };

void gamePlay() {
	srand((unsigned int)time(0));

	cardShuffle();
	cardSetting();
	playerInformationShow();
	cardShow();
	cardChange();
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

void cardChange() {
	int changeAmount;
	cout << "몇번 바꾸시겠습니까? ";
	cin >> changeAmount;

	for (int cardChangeCounter = 1; cardChangeCounter <= changeAmount; cardChangeCounter++) {
		int changeNumber;
		cout << cardChangeCounter << "번째로 바꾸실 카드의 번호를 입력해주세요 : ";
		cin >> changeNumber;

		cardShowNumber[changeNumber - 1] = cardNumber[0];
		cardNumber.erase(cardNumber.begin());

		system("cls");
		cardShow();
		cout << card[cardShowNumber[changeNumber - 1]] << "로 바뀌었습니다.\n";
	}
}

void playerInformationShow() {
	cout << "----------------------------------------\n\n    "
		<< "player1         |     player2\n    "
		<< setfill(' ') << "체력 : " << setw(3) << player1Hp << "      |     체력 : " << setw(3) << player2Hp << "\n    "
		<< setfill(' ') << "다이아 : " << setw(2) << player1Dia << "     |     다이아 : " << setw(2) << player2Dia
		<< "\n\n----------------------------------------\n";
}
