//
// Created by MagicBook on 2020/11/15.
//

#include <string.h>

#include "item.h"

Item::Item(const char* name, int type) {
	this->name = (char*)malloc(sizeof(char)*strlen(name)+1);
	sprintf(this->name, "%s", name);
	this->type = type;
	this->store = -1;
	// this->position = 0;
	this->position = NULL;
}

Item::~Item() {
	free(this->position);
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
	printf("HELP! SET STORE in Item %d %s\n", store, position);
	this->store = store;
	if (NULL != position) {
		if (NULL != this->position) {
			free(this->position);
		}
		this->position = (char*)malloc(sizeof(char)*strlen(position)+1);
		sprintf(this->position, "%s", position);
	}
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
