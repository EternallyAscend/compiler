#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "file.h"
#include "ass.h"
int main()
{
	int rowNum;
	rowNum = giveRow();
	int cursorOne;
    int cursorTwo;
	char ***threeCode = (char***)malloc(sizeof(char**)*rowNum);
    for(cursorOne = 0; cursorOne < rowNum; cursorOne++) 
	{
	    threeCode[cursorOne] = (char**)malloc(sizeof(char*)*4);
	    for(cursorTwo = 0; cursorTwo < 4; cursorTwo++)
	    {
	    	threeCode[cursorOne][cursorTwo] = (char*)malloc(sizeof(char)*64);
		}
    }
    char ***varyCode = (char***)malloc(sizeof(char**)*rowNum);
    for(cursorOne = 0; cursorOne < rowNum; cursorOne++) 
	{
	    varyCode[cursorOne] = (char**)malloc(sizeof(char*)*2);
	    for(cursorTwo = 0; cursorTwo < 2; cursorTwo++)
	    {
	    	varyCode[cursorOne][cursorTwo] = (char*)malloc(sizeof(char)*64);
		}
    }
    FILE* f = fopen("okk.txt", "r");
	char buf[1024];
	int i = 0;
	int j = 0;
    while((fscanf(f, "%s", buf))!= EOF)
	{
		if(i % 4 == 0)
		{
			sprintf(threeCode[j][0], "%s", buf);
		}
		if(i % 4 == 1)
		{
			strcpy(threeCode[j][1], buf);
		}
		if(i % 4 == 2)
		{
			char* x = buf;
			x += 1;
			if(buf[0] == '#')
			{
				sprintf(threeCode[j][2], "?%s", x);
			}
			else if(buf[0] == '@')
			{
				sprintf(threeCode[j][2], "$%s", x);
			}
			else
			{
				strcpy(threeCode[j][2], buf);
			}
		}
		if(i % 4 == 3)
		{
			char* x = buf;
			x += 1;
			if(buf[0] == '#')
			{
				sprintf(threeCode[j][3], "?%s", x);
			}
			else if(buf[0] == '@')
			{
				sprintf(threeCode[j][3], "$%s", x);
			}
			else
			{
				strcpy(threeCode[j][3], buf);
			}
			j++;
		}
		i++;
		memset(buf, 0, 1024);
	}
	fclose(f); 
    readThree(threeCode, threeCode[0][0], varyCode, rowNum);
    for (cursorOne = 0; cursorOne < rowNum; cursorOne++) 
    {
    	for (cursorTwo = 0;cursorTwo < 4; cursorTwo++)
	    {
		    free(threeCode[cursorOne][cursorTwo]);
	    }
	    free(threeCode[cursorOne]);
    }
    free(threeCode);
    for (cursorOne = 0; cursorOne < rowNum; cursorOne++) 
    {
    	for (cursorTwo = 0;cursorTwo < 2; cursorTwo++)
	    {
		    free(varyCode[cursorOne][cursorTwo]);
	    }
	    free(varyCode[cursorOne]);
    }
    free(varyCode);
	return 0;
}