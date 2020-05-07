#include <stdio.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
	initVM();

	Chunk chunk;
	initChunk(&chunk);

	int constant = addConstant(&chunk, 1.2);
	writeChunk(&chunk, OP_CONSTANT, 123);
	writeChunk(&chunk, constant, 123);

	writeChunk(&chunk, OP_RETURN, 123);

	printf("=================");
	printf("\n");
	printf("== disassembly ==");
	printf("\n");
	printf("=================");
	printf("\n");
	disassembleChunk(&chunk, "test chunk");

	printf("\n\n");
	printf("==============");
	printf("\n");
	printf("== exection ==");
	printf("\n");
	printf("==============");
	printf("\n");
	interpret(&chunk);

	freeVM();
	freeChunk(&chunk);
	return 0;
}