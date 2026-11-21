#include <iostream>
#include <string>
#include <thread>
#include <chrono>

const short HEIGHT{ 29 };
const short WIDTH{ 120 };

std::string window[WIDTH][HEIGHT];

void draw();
void physics();
void create();

int main() {
	for (short h = 0; h < HEIGHT; h++) {
		for (short w = 0; w < WIDTH; w++) {
			if (h == 0 or h == 29 or w == 0 or w == WIDTH - 1 or (h == 20 and w != 10 and w != 60 and w != 110 and w != 30 and w != 90))
				window[w][h] = "\033[47m ";
			else
				window[w][h] = "\033[40m ";
		}
	}


	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(30));
		physics();
		draw();
		create();
	}
	return 0; 
}


void draw() {
	std::string buff;

	for (short h = 0; h < HEIGHT; h++) {
		for (short w = 0; w < WIDTH; w++) {
			buff += window[w][h];
		}
		buff += '\n';
	}
	std::cout << buff;
}


void physics() {
	for (short h = HEIGHT-1; h > 1; h--) {
		for (short w = 1; w < WIDTH-1; w++) {
			if (window[w][h] == "\033[43m ") {
				if (window[w][h + 1] == "\033[40m ") {
					window[w][h] = "\033[40m ";
					window[w][h + 1] = "\033[43m ";
				}
				else if (window[w - 1][h + 1] == "\033[40m ") {
					window[w][h] = "\033[40m ";
					window[w - 1][h + 1] = "\033[43m ";
				}
				else if (window[w + 1][h + 1] == "\033[40m ") {
					window[w][h] = "\033[40m ";
					window[w + 1][h + 1] = "\033[43m ";
				}
			}

		}
	}
}

void create() {
	window[1+std::rand() % (118)][2] = "\033[43m ";
}