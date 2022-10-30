#include <iostream>

using namespace std;

char switch_user(char player) { // alternate between players

	if (player == 'X') {
		player = 'O';
	}
	else if (player == 'O') {
		player = 'X';
	}

	return player;
}
char print_map(char map[5][5]) { // printing the map

	for (int i{}; i <= 4; i++) {
		for (int j{}; j <= 4; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

	return 0;
}
int main() {

	bool gameOn{ true };
	bool isFound{}; // checking if the input was found and still a valid place
	char player{ 'X' }; // assigning  player X to start
	int input{}; // input of the location inside the map
	int location[2]{}; // location of the inout inside the map

	char map[5][5] = 	//map drawing
	{
		{'1', '|', '2', '|', '3'},
		{'_', '_', '_', '_', '_'},
		{'4', '|', '5', '|', '6'},
		{'_', '_', '_', '_', '_'},
		{'7', '|', '8', '|', '9'}
	};

	while (gameOn) { //finding the input inside the map 
		print_map(map);
		cout << "Player " << player << ": ";
		cin >> input;
		for (int i{}; i <= 4; i++) {
			for (int j{}; j <= 4; j++) {
				if (input == map[i][j] - 48) {
					location[0] = i;
					location[1] = j;
					isFound = true;
				}
			}
		}

		if (isFound) {
			map[location[0]][location[1]] = player; // replacing the point in map with player according to choice
			player = switch_user(player); // switching user
			isFound = false;
		}

		for (int i{ 0 }; i <= 4; i++) { // wining conditions
			if (map[i][0] == map[i][2] && map[i][0] == map[i][4]) { // checking vertically 
				print_map(map);
				cout << "winner is: " << map[i][0] << endl;
				gameOn = false;
				break;
			}
			else if (map[0][i] == map[2][i] && map[0][i] == map[4][i]) { // checking horizontally 
				print_map(map);
				cout << "winner is: " << map[0][i] << endl;
				gameOn = false;
				break;
			}
			else { // there was a bug where cant make it i+2 in the for condition somade it separate here
				i++;
			}
		}

		if (map[0][0] == map[2][2] && map[2][2] == map[4][4]) { // checking diagonally
			print_map(map);
			cout << "winner is: " << map[2][2] << endl;
			gameOn = false;
			break;
		}
		else if (map[4][0] == map[2][2] && map[2][2] == map[0][4]) {
			print_map(map);
			cout << "winner is: " << map[2][2] << endl;
			gameOn = false;
			break;
		}
	}
	cout << "Game Over" << endl;
	return 0;
}
