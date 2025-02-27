#ifndef _CLOX_CHUNK_H_
#define _CLOX_CHUNK_H_

#include "common.h"
#include "value.h"

typedef enum {
  OP_CONSTANT,
  OP_CONSTANT_LONG,
  OP_NIL,
  OP_TRUE,
  OP_FALSE,
  OP_EQUAL,
  OP_GREATER,
  OP_LESS,
  OP_ADD,
  OP_SUBTRACT,
  OP_MULTIPLY,
  OP_DIVIDE,
  OP_NOT,
  OP_NEGATE,
  OP_RETURN,
} OpCode;

typedef struct {
  int count;
  int capacity;
  uint8_t *code;
  int *lines;
  ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);

void freeChunk(Chunk *chunk);

void writeChunk(Chunk *chunk, uint8_t byte, int line);

void writeConstant(Chunk *chunk, Value value, int line);

// for long constant
void writeConstantLong(Chunk *chunk, Value value, int line);

int addConstant(Chunk *chunk, Value value);

// int getLine(Chunk* chunk, int offset);

#endif