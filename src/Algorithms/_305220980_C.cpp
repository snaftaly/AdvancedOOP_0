#include "_305220980_C.h"

Direction _305220980_C::step(Direction prevStep) {
	return getStepAndUpdatePrevStep(possibleMoves, prevStep, false);
}

REGISTER_ALGORITHM (_305220980_C)
