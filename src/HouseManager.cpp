#include <iostream>
#include <fstream>
#include <dirent.h>
#include "HouseManager.h"
using namespace std;

#define HOUSE_EXT ".house"
#define HOUSE_EXT_SIZE 6

HouseManager::HouseManager() {
	// fill the house with hard coded info
	houses.emplace_back(House()); // TODO: should we use emplace?

	House& lastInsertedHouse = houses.back();
	lastInsertedHouse.setName("Simple1");
	cout << lastInsertedHouse.getName() << endl;
	lastInsertedHouse.setDesc("2 Bedrooms + Kitchen Isle");
	lastInsertedHouse.setRows(8);
	lastInsertedHouse.setCols(10);
	string * matrix = new string[lastInsertedHouse.getRows()];
	matrix[0] = "WWWWWWWWWW";
	matrix[1] = "W22  DW59W";
	matrix[2] = "W  W 1119W";
	matrix[3] = "W WWW3WW W";
	matrix[4] = "W6   3W  W";
	matrix[5] = "W78W  W  W";
	matrix[6] = "W99W  W  W";
	matrix[7] = "WWWWWWWWWW";
	lastInsertedHouse.setHouseMatrix(matrix);
}

// for later use

//void HouseManager::getHouses(std::string housesDirPath){
//
//	struct dirent *entry;
//	DIR *dp;
//    dp = opendir(housesDirPath.c_str());
//
//    if (dp == NULL) {
//        perror("opendir: Path does not exist or could not be read.");
//        return;
//    }
//
//    while ((entry = readdir(dp))){
//    	if (hasHouseExtension(entry->d_name)){
//    		numHouses++;
//    		houseVector->resize(numHouses);
//    		houseInput(houseVector->at(numHouses -1), housesDirPath + "/" + entry->d_name);
//    	}
//    }
//    closedir(dp);
//}
//
//void HouseManager::houseInput(House& house, string fileName)
//{
//	ifstream fin(fileName.c_str());
//	std::getline(fin, house.name);
//	std::getline(fin, house.desc);
//	fin >> house.rows;
//	fin >> house.cols;
//	fin.ignore(); //skip newline and go to the beginning of matrix
//	if (house.getHouseMatrix() != NULL){
//		delete [] house.getHouseMatrix();
//	}
//	house.houseMatrix = new string[house.rows];
//	for (int i =0; i < house.rows; ++i)
//	{
//	    std::getline(fin, house.getHouseMatrix()[i]);
//	}
//}
//
//bool HouseManager::hasHouseExtension(char * filename){ // TODO: do this function in a c++ way
//	if (strlen(filename) >= HOUSE_EXT_SIZE
//			&& strcmp(filename + strlen(filename) - HOUSE_EXT_SIZE, HOUSE_EXT) == 0) {
//	  return true;
//	}
//	return false;
//}

