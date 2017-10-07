#include<string>
using namespace std;
struct PlayerNode {
	int player_index;
	string player_name;
	struct PlayerNode * next_node;
};

struct Teams {
	string team_name;
	string city;
	string stadium;
	int team_player_count;
	struct PlayerNode * next_player_node;
	struct Teams * next_team;
};