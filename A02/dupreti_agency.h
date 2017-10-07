#include <stdio.h>
#include <string>
#include <iostream>
#include "dupreti_player.h"
#include "dupreti_team.h"
using namespace std;

void add_team(struct Teams **pointer_to_head);

struct PlayerNode * createPlayerNode(int i, string s);

void deleteList(struct Teams** pointer_to_head);

int add_player(struct Players *A);

void find_player(int count);

int display_team(string name);

int players_to_team(struct Teams **pointer_to_head);

void printplayerArray();

void swap(struct Players *A, struct Players *B);

void sortPlayers();

void sortPlayersbyTeam();

void update(struct Teams **pointer_to_head);

void add_team_test1(struct Teams **pointer_to_head);

void add_team_test2(struct Teams **pointer_to_head);

int add_player_test1(struct Players *A);

int add_player_test2(struct Players *A);

int add_player_test3(struct Players *A);

void sortPlayers_test();

void sortPlayersbyTeam_test();

int players_to_team_test(struct Teams **pointer_to_head)

void test();