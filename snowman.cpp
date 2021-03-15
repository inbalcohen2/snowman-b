#include "snowman.hpp"
#include <iostream>
#include <array>
#include <string>
#include <exception>
#include <vector>
#include <unordered_map>

using namespace std;

namespace ariel{

constexpr int MIN_SNOWPART_DIGIT = 1;
constexpr int MAX_SNOWPART_DIGIT = 4;

int ToDigit(char c) noexcept(false)
{
	if(c < '0' || c > '9'){
		throw out_of_range("the given char is not a digit");
	}
	return c - '0';
}

// build and define the snowman parts as class functions
class SnowMan
{
public:
	//For the build of the snowman
	enum Parts
	{
		hat = 0, nose, lefteye, righteye, leftarm, rightarm, torso, base, NUM_OF_SNOWPARTS
	};

	//Build each part individually of the snowman
	SnowMan()
	{
		_snowParts = {{"H",{}}, {"N",{}}, {"LE",{}}, {"RE",{}}, {"LAT",{}}, {"LA",{}},
		              {"RAT",{}}, {"RA",{}}, {"T",{}}, {"B",{}}
		};
//Hats
		_snowParts["H"] += ("      \n _===_\n");
		_snowParts["H"] += ("  ___ \n .....\n");
		_snowParts["H"] += ("   _  \n  /_\\ \n");
		_snowParts["H"] += ("  ___ \n (_*_)\n");
//Noses
		_snowParts["N"] += (",");
		_snowParts["N"] += (".");
		_snowParts["N"] += ("_");
		_snowParts["N"] += (" ");
//Left Eyes
		_snowParts["LE"] += (".");
		_snowParts["LE"] += ("o");
		_snowParts["LE"] += ("O");
		_snowParts["LE"] += ("-");
//Right Eyes
		_snowParts["RE"] += (".");
		_snowParts["RE"] += ("o");
		_snowParts["RE"] += ("O");
		_snowParts["RE"] += ("-");
//Left Arm
		_snowParts["LA"] += ("<");
		_snowParts["LA"] += (" ");
		_snowParts["LA"] += ("/");
		_snowParts["LA"] += (" ");
//Left Arm Top
		_snowParts["LAT"] += (" ");
		_snowParts["LAT"] += ("\\");
		_snowParts["LAT"] += (" ");
		_snowParts["LAT"] += (" ");
//Right Arm
		_snowParts["RA"] += (">");
		_snowParts["RA"] += (" ");
		_snowParts["RA"] += ("\\");
		_snowParts["RA"] += (" ");
//Right Arm  Top

		_snowParts["RAT"] += (" ");
		_snowParts["RAT"] += ("/");
		_snowParts["RAT"] += (" ");
		_snowParts["RAT"] += (" ");
//Torsos
		_snowParts["T"] += (" : ");
		_snowParts["T"] += ("] [");
		_snowParts["T"] += ("> <");
		_snowParts["T"] += ("   ");
//Bases
		_snowParts["B"] += (" : ");
		_snowParts["B"] += ("\" \"");
		_snowParts["B"] += ( "___");
		_snowParts["B"] += ("   ");
	}

	string GetSnowMan(int input) noexcept(false)
	{
		if(input <= 0)
		{
			throw invalid_argument("input cannot be negative number or zero");
		}

		const auto inputStr = to_string(input);		
		if(inputStr.length() != Parts::NUM_OF_SNOWPARTS)
		{
			throw invalid_argument("input size has wrong number of input");
		}

		for(const auto& c : inputStr)
		{
			if(ToDigit(c) < MIN_SNOWPART_DIGIT || ToDigit(c) > MAX_SNOWPART_DIGIT){
				throw out_of_range("the digit is not valid");
			}
		}
		
		return BuildSnowMan(inputStr);
	}

private:
	
	/* inner class */
	class SnowPart
	{
	public:
		void operator+=(const string& typeToAdd)
		{
			_types.push_back(typeToAdd);
		}

		// index should be between 1.....max type size
		string GetType(int index)
		{
			if(index == 0 || index > _types.size()){
				throw out_of_range("index not in range. should be between 1... max type size");
			}
			return _types[index - 1];
		}

	private:
		std::vector<string> _types;
	};

	string BuildSnowMan(const string& input);
	unordered_map<string, SnowPart> _snowParts;
};

//build the snow man (string)
string SnowMan::BuildSnowMan( const string& input)
{
	return  _snowParts["H"].GetType(ToDigit(input[hat])) +
	        _snowParts["LAT"].GetType(ToDigit(input[leftarm])) + "(" +
	        _snowParts["LE"].GetType(ToDigit(input[lefteye])) +
	        _snowParts["N"].GetType(ToDigit(input[nose]))+
	        _snowParts["RE"].GetType(ToDigit(input[righteye])) + ")" +
	        _snowParts["RAT"].GetType(ToDigit(input[rightarm])) + "\n" +
	        _snowParts["LA"].GetType(ToDigit(input[leftarm])) + "(" +
	        _snowParts["T"].GetType(ToDigit(input[torso])) + ")" +
	        _snowParts["RA"].GetType(ToDigit(input[rightarm])) + "\n" + " (" +
	        _snowParts["B"].GetType(ToDigit(input[base])) + ") ";
}

string snowman(int input)
{
	SnowMan mySnowMan;
	return mySnowMan.GetSnowMan(input);
}

} // namespace ariel
