#ifndef SCOREMANAGER_H_
#define SCOREMANAGER_H_

#include <mutex>
#include <string>
#include <map>


class ScoreManager {
	std::string scoreFilePath;
	std::mutex scoreUpdateMutex;
	std::map<std::string, std::map<std::string, int>> algosScoresForHouses; // think of a better container


public:
	ScoreManager(const std::string& _scoreFilePath): scoreFilePath(_scoreFilePath){ }
	~ScoreManager();

	void updateScore(const std::string& algoName, const std::string& houseFileName, int score);

	const std::map<std::string, std::map<std::string, int> >& getAlgosScoresForHouses() const {
		return algosScoresForHouses;
	}
};

#endif /* SCOREMANAGER_H_ */
