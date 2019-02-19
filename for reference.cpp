#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct player{
	int wood;
	int brick;
	int sheep;
	int point;
	vector< pair < int, int > > settlements;
        vector< pair < int, int > > cities;
};

int woodrep = 1;
int brickrep = 2;
int sheeprep = 3;

vector< pair<int, int> > buildingsaroundresource(int i, int j){
	vector< pair <int, int> > buildings;
	if(i < 2){
		buildings.push_back(make_pair(i, j + j));
        	buildings.push_back(make_pair(i, j + j + 1));
        	buildings.push_back(make_pair(i, j + j + 2));
        	buildings.push_back(make_pair(i + 1, j + j + 1));
        	buildings.push_back(make_pair(i + 1, j + j + 1 + 1));
        	buildings.push_back(make_pair(i + 1, j + j + 1 + 2));
	}
	else if(i > 2){
		buildings.push_back(make_pair(i, j + j + 1));
                buildings.push_back(make_pair(i, j + j + 1 + 1));
                buildings.push_back(make_pair(i, j + j + 1 + 2));
                buildings.push_back(make_pair(i + 1, j + j));
                buildings.push_back(make_pair(i + 1, j + j + 1));
                buildings.push_back(make_pair(i + 1, j + j + 2));
	}
	else{
		buildings.push_back(make_pair(i, j + j));
                buildings.push_back(make_pair(i, j + j + 1));
                buildings.push_back(make_pair(i, j + j + 2));
                buildings.push_back(make_pair(i + 1, j + j));
                buildings.push_back(make_pair(i + 1, j + j + 1));
                buildings.push_back(make_pair(i + 1, j + j + 2));

	}
	return buildings;
}

int rando(int max, int min){
	return rand() % (max - min + 1) + min;
}

int rolldice(){
	return rando(6, 1) + rando(6, 1);
}

void addresourcestoplayers(vector < pair < int, int > > buildings, vector < player > Players){
	for(int i = 0; i < buildings.size(); i++){
		for(int j = 0; j < Players.size(); j++){
			if(find(Players[j].settlements.begin(), Players[j].settlements.end(), buildings[i]) != Players[j].settlements.end()){
				Players[j].wood++;
                                Players[j].brick++;
                                Players[j].sheep++;
				break;
			}
                        else if(find(Players[j].cities.begin(), Players[j].cities.end(), buildings[i]) != Players[j].cities.end()){
                                Players[j].wood += 2;
                                Players[j].brick += 2;
                                Players[j].sheep += 2;
                                break;
                        }

		}
	}
}

void turn(vector < vector < pair < int, int > > > map, vector < player > Players){
	int rolled = rolldice();
	vector < pair< int, int > > resourcecoordinates;
	for(int i = 0; i < map.size(); i++){
		for(int j = 0; j < map[i].size(); j++){
			if(rolled == map[i][j].second){
				resourcecoordinates.push_back(make_pair(i, j));
			}
		}
	}
	vector < pair < int, int > > buildings;
	for(int i = 0; i < resourcecoordinates.size(); i++){
		buildings = buildingsaroundresource(resourcecoordinates[i].first, resourcecoordinates[i].second);
		addresourcestoplayers(buildings, Players);
	}
}

int main(){

	vector < vector < pair < int, int > > * > map; // need to remove the star later
	//vector < pair < int, int > > temp;
	//temp = new vector < pair < int, int > >(3, make_pair(rando(3, 1), rando(12, 2)));
	//map.push_back(temp);

	map.push_back(new vector < pair < int, int > >(3, make_pair(rando(3, 1), rando(12, 2))));
        map.push_back(new vector < pair < int, int > >(4, make_pair(rando(3, 1), rando(12, 2))));
        map.push_back(new vector < pair < int, int > >(5, make_pair(rando(3, 1), rando(12, 2))));
        map.push_back(new vector < pair < int, int > >(4, make_pair(rando(3, 1), rando(12, 2))));
        map.push_back(new vector < pair < int, int > >(3, make_pair(rando(3, 1), rando(12, 2))));

	int numberofplayers;
	cout << "How many players?" << endl;
	cin >> numberofplayers;
	vector< player > Players;
	for(int i = 0; i < numberofplayers; i++){
		int vertical, horizontal;
		Players.push_back(player());
		Players[i].wood = 0;
        	Players[i].brick = 0;
        	Players[i].sheep = 0;
        	Players[i].point = 2;
		cout << "Choose settlement coordinates for player " << i << ":" << endl;
		cin >> vertical >> horizontal;
		Players[i].settlements.push_back(make_pair(vertical, horizontal));
	}

	//Demo
	cout << "These are the first player's stats." << endl;
	cout << Players[0].wood << endl;
	cout << Players[0].brick << endl;
	cout << Players[0].sheep << endl;
	cout << Players[0].point << endl;
	vector < pair < int, int > > buildings = buildingsaroundresource(3, 3);
	cout << "These are the coordinates for buildings around a resource." << endl;
	for(int i = 0; i < buildings.size(); i++){
		cout << buildings[i].first << ", " << buildings[i].second << endl;
	}
	cout << "These are the results for rolling 2 dices." << endl;
	for(int i = 0; i < 10; i++){
		cout << rolldice() << endl;
	}
}
