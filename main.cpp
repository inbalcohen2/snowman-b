#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <thread>
#include <random>
#include <chrono>

#define EVER ; ;

using namespace std;

namespace ariel
{

constexpr int INPUT_DIGIT_SIZE = 8;
constexpr int INPUT_DIGIT_RANGE = 4;
constexpr int MAX_COLOR_NUM = 3;

const string RED_COLOUR = "\e[1;31m";
const string PURPLE_COLOUR = "\e[1;95m";
const string GREEN_COLOUR = "\e[1;92m";

string DrawRandomSnowman()
{
	auto input = 0;
	for (int i = 0; i < INPUT_DIGIT_SIZE; i++)
	{
		input *= 10;
		input += (rand() % INPUT_DIGIT_RANGE) + 1;
	}

	cout << endl << " Generating random snowman" << endl;
	return snowman(input);
}

} // namespace ariel

using namespace ariel;
c
int main()
{
	srand((unsigned) time(nullptr));
	string colors[] = {RED_COLOUR, PURPLE_COLOUR, GREEN_COLOUR};
	auto colorNum = 0;

	for (EVER)
	{
		colorNum = (rand() % MAX_COLOR_NUM);
		cout << colors[colorNum] << DrawRandomSnowman();
		this_thread::sleep_for(chrono::milliseconds(500));
		cout << endl << endl;
	}

    return 0;
}

