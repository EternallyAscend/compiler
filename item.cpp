//
// Created by MagicBook on 2020/11/15.
//

#include <string.h>

#include "item.h"

Item::Item(std::string name, int type) {
	this->name = name;
	this->type = type;
	this->store = -1;
	// this->position = 0;
	this->position = NULL;
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

// int Item::modifyItemStore(int store, int position) {
int Item::modifyItemStore(int store, char* position) {
	this->store = store;
	this->position = std::string(position);
	return this->store;
}

int Item::getType() {
	return this->type;
}

int Item::getStore() {
	return this->store;
}

// int Item::getPosition() {
char* Item::getPosition() {
	return this->position;
}
