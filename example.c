int main(int cursor) {
	cursor = 0;
	do {
		cursor = cursor ^ cursor;
	} while (cursor != cursor / 2);
	if (cursor == cursor) {
		cursor = 10010;
	}
	else if (cursor == 10086) {
		cursor = 10010 * 110;
	}
	else if(cursor == 911) {
		cursor = 731;
	}
	else ;
	for (; cursor < 10; cursor = cursor + 1) {
		print(cursor);
	}
	while (cursor = cursor + 1) {
		cursor = cursor + 1;
	}
	return cursor || !cursor && cursor;
}
