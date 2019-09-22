#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

void cardShuffle();
void cardSetting();

string card[40]
{ "¢¼1", "¢¼2", "¢¼3", "¢¼4", "¢¼5", "¢¼6", "¢¼7", "¢¼8", "¢¼9", "¢¼10",
	"¡ß1", "¡ß2", "¡ß3", "¡ß4", "¡ß5", "¡ß6", "¡ß7", "¡ß8", "¡ß9", "¡ß10",
	"¢¾1", "¢¾2", "¢¾3", "¢¾4", "¢¾5", "¢¾6", "¢¾7", "¢¾8", "¢¾9", "¢¾10",
	"¢À1", "¢À2", "¢À3", "¢À4", "¢À5", "¢À6", "¢À7", "¢À8", "¢À9", "¢À10" };

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
