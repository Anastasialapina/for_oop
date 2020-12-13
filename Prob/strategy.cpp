#include "strategy.h"

Context::Context (Square *square, Strategy *strategy = nullptr) : square(square), strategy(strategy) {}

Context::~Context () {
	delete this->strategy;
}

element *Context::logic (Player &player, element *item) {
	if (this->strategy != nullptr) 
		item = this->strategy->set(square, player, item);
	return item;
}

Creator *setLive::set (Square *square, Player &player, element *item) {
	if (player.GetLive() < 3) {
		player += *item;
		delete item;
		item = nullptr;
		//square->getField()[player.y()][player.x()]->setInfo('n');
	}
	return item;
}

element *setMoney::set (Square *square, Player &player, element *item) {
	if (player.GetMoney() < 4) {
		player += *item;
		delete item;
		item = nullptr;
		//field->getField()[player.y()][player.x()]->setInfo('n');
	}
	return item;
}

element *setTeleport::set (Square *square, Player &player, element *item) {
	player += *item;
	delete item;
	item = nullptr;
	field->getField()[player.y()][player.x()]->setInfo('n');//
	return item;
}
