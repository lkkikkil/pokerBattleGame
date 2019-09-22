#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

void cardShuffle();
void cardSetting();

string card[40]
{ "��1", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10",
	"��1", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10",
	"��1", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10",
	"��1", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10" };

vector <int> cardNumber;
vector <int> cardShowNumber;

void gamePlay() {
	srand((unsigned int)time(0));

	cardShuffle();
	cardSetting();
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
