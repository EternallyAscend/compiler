//
// Created by MagicBook on 2020/11/15.
//

#include "item.h"

Item::Item(std::string name, int type) {
	this->name = name;
	this->type = type;
	this->store = -1;
	this->position = 0;
}

Item::~Item() {
	
}

int Item::isEmptyItem() {
	if (-1 == this->store) {
		return 1;
	}
	else {
		return 0;
	}
}

int Item::modifyItemType(int newType) {
	return this->type = newType;
}

int Item::modifyItemStore(int store, int position) {
	this->store = store;
	this->position = position;
	return this->store;
}

int Item::getType() {
	return this->type;
}

int Item::getStore() {
	return this->store;
}

int Item::getPosition() {
	return this->position;
}
