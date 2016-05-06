#include "_305220980_A.h"

Direction _305220980_A::step(Direction prevStep) {
	counter = (counter + 1) % 10;
	if (counter == 1){
		Direction temp = possibleMoves[0];
		possibleMoves[0] = possibleMoves[3];
		possibleMoves[3] = temp;
	}
	if (counter == 6){
		Direction temp = possibleMoves[1];
		possibleMoves[1] = possibleMoves[2];
		possibleMoves[2] = temp;
	}
	return getStepAndUpdatePrevStep(possibleMoves, prevStep);
}

void _305220980_A::setSensor(const AbstractSensor& sensor){
	counter = 0;
	possibleMoves = {Direction::North, Direction::West, Direction::South, Direction::East, Direction::Stay};

	GenericAlgorithm::setSensor(sensor);
}

REGISTER_ALGORITHM (_305220980_A)

