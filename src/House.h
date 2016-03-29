#ifndef HOUSE_H
#define HOUSE_H

#include <string>
#include <iostream>
#include <tuple>

class House
{
	std::string name;
	std::string desc;
	int rows;
	int cols;
	std::string * houseMatrix;
public:

	// House c'tor signature
	House();

	// House d'tor signature
	~House();

	// House copy c'tor
    House(const House& house);

	// House assignment operator
    House& operator=(const House& house);

    // House << operator
    friend std::ostream& operator<<(std::ostream& out, const House& p);

    int calcDirtLevel() const;

    std::tuple<int, int> getHouseDockPlace() const;

    bool readFromFile(std::string fileName);

    // getters
	const std::string& getDesc() const {
		return desc;
	}

	const std::string& getName() const {
		return name;
	}

	int getRows() const {
		return rows;
	}

	int getCols() const {
		return cols;
	}

	std::string* getHouseMatrix() const {
		return houseMatrix;
	}

	std::string getHouseMatrixStr() const;

	void fixHouse();

	void fixMissingRowsAndCols();

	void fixWalls();

	bool isHouseValid();

	// setters

	void setDesc(const std::string& desc) {
		this->desc = desc;
	}

	void setName(const std::string& name) {
		this->name = name;
	}

	void setRows(int rows) {
		this->rows = rows;
	}

	void setCols(int cols) {
		this->cols = cols;
	}

	void setHouseMatrix(std::string* houseMatrix) {
		this->houseMatrix = houseMatrix;
	}
};

#endif
