#include <cstdlib>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>

/*

 _( )_
(_)@(_)
  (_)\
    '|/
    \|
     |
  \\|//
^^^^^^^^^^^^
*/

int randInt(int range) {
	return (std::rand() / (RAND_MAX / range));
}

std::string repeat(int amount, char c) {
	std::string str;
	for (int i = 0; i < amount; i++) {
		str = str + c;
	}
	return (str);
}

class flower {
public:
	char type;
	std::vector<std::string> picture;
	std::vector<std::string> stemTop, stemMid, stemBot, stemRoot;
	int length;

	flower(int l, char t) {
		length = l;

		std::cout << length << "\n";

		type = t;

		loadParts();

		generateFlower();
		generateStem();
	}

	void loadParts() {
		std::string line;
		std::ifstream parts("parts");

		getline(parts, line);
		getline(parts, line);

		while (line != "Middle:") {
			stemTop.push_back(line);
			getline(parts, line);
		} 
		getline(parts, line);
		while (line != "Bottom:") {
			stemMid.push_back(line);
			getline(parts, line);
		}
		getline(parts, line);
		while (line != "Root:") {
			stemBot.push_back(line);
			getline(parts, line);
		}
		getline(parts, line);
		while (getline(parts, line)) {
			stemRoot.push_back(line);
		}
	}

	void generateFlower() {
		/* Marigold
		      (ww	
		     (W*W)
		      """
		       |/
		*/
		if (type == 'm') {
			std::string layer;
			picture.push_back(" (" + repeat(randInt(3) + 1, 'w'));
			std::cout << " " << picture[0] << "\n";

			layer = (repeat(randInt(3) + 4, 'W'));
			layer[layer.length() / 2] = '0';
			layer[0] = '(';
			layer[layer.length() - 1] = ')';
			picture.push_back(layer);
			std::cout << " " << picture[1] << "\n";

			layer = (" " + repeat(randInt(3) + 1, '\"'));
			picture.push_back(layer);
			std::cout << " " << picture[2] << "\n";
		}

		if (type == 'd') {
			picture.push_back(" wWWWw");
			std::cout << picture[0] << "\n";
			picture.push_back(" (___)");
			std::cout << picture[1] << "\n";
		}

	}

	void generateStem() {
		std::vector<std::string> stem;
		stem.push_back(stemTop[randInt(stemTop.size())]);
		std::cout << stem[0] << "\n";

		for(int i = 0; i < length - 3; i++) {
			stem.push_back(stemMid[randInt(stemMid.size())]);
			std::cout << stem[i + 1] << "\n";
		}

		stem.push_back(stemBot[randInt(stemBot.size())]);

		std::cout << stem[length - 2] << "\n";

		stem.push_back(stemRoot[randInt(stemRoot.size())]);
		std::cout << stem[length - 1] << "\n";
	}
};

int main() {
	std::srand(std::time(nullptr));

	flower def(5, 'm');

	std::cout << "^^^^^^^^^^^^^";
}
