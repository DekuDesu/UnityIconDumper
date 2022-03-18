// IconDumper.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define is ==
#define isnt !=
#define null NULL

size_t DumpIcons(FILE* stream);
bool StreamEquals(FILE* stream, const char* target, size_t length);

#define BUFFER_SIZE 1024

int main(int argc, char** argv)
{
	if (argc <= 1)
	{
		fprintf(stdout, "Path to catalog.json must be provided usage ./IconDumper.exe \"<path>/catalog.json\"\n");
		exit(-1);
	}

	const char* path = argv[1];

	FILE* stream;
	errno_t error = fopen_s(&stream, path, "rb");

	if (stream is null)
	{
		char errorBuffer[BUFFER_SIZE];
		strerror_s(errorBuffer, BUFFER_SIZE, error);

		fprintf(stderr, "Failed to open file %s\n\t%s", path, errorBuffer);
		exit(-1);
	}

	size_t count = DumpIcons(stream);

	fclose(stream);

	fprintf(stdout, "Found %lli icons\n", count);
}

size_t DumpIcons(FILE* stream)
{
	// pattern "*.png"
	
	char buffer[BUFFER_SIZE];
	size_t index = 0;

	int c;

	/*
		parse until we encounter "
		read all chars until .
		ensure ends in .png"
		if it does output to stdout
	*/

	char target[] = "png\"";

	size_t endIndex = 0;

	size_t count = 0;

	bool searching = false;

	// parse until end of file
	while ((c = fgetc(stream)) != EOF)
	{
		buffer[index] = c;

		// check to see if we are looking for start of target char
		if (searching is false && c == '"')
		{
			searching = true;
			index = 0;
			continue;
		}else if(searching)
		{
			// check to see if it's the beginning of end of target
			if (c == '.' && StreamEquals(stream, target, sizeof(target)-1))
			{
				// null terminate the current character
				buffer[index] = '\0';
				fprintf(stdout, "%s.png\n", buffer);
				++count;
				index = 0;
				searching = false;
				continue;
			}

			// if .png" wasn't found but " was found we found an invalid string, start over
			if (c == '"')
			{
				index = 0;
				searching = false;
				continue;
			}
		}

		++index;

		if (index >= BUFFER_SIZE)
		{
			index = 0;
		}
	}

	return count;
}

bool StreamEquals(FILE* stream, const char* target, size_t length)
{
	size_t index = 0;
	
	int c;
	while ((c = fgetc(stream)) != EOF)
	{
		if (index > length)
		{
			return false;
		}

		if (c != target[index])
		{
			return false;
		}
		
		if(index == (length - 1))
		{
			return true;
		}

		++index;
	}

	return false;
}