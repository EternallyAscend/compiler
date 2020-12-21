//
// Created by MagicBook on 2020/12/14.
//

#include <stdio.h>
#include <stdlib.h>

#include "indirectTriple.h"

//struct InstructionItem{
//    char* operatorType;
//    int arg0; // Address.
//    int arg1; // Address.
//};

struct InstructionItem* generateIndirectTriple(char* operatorType, int arg0, int arg1) {
    struct InstructionItem* instructionItem = (struct InstructionItem*)malloc(sizeof(struct InstructionItem));
    instructionItem->operatorType = operatorType;
    instructionItem->arg0 = arg0;
    instructionItem->arg1 = arg1;
    return instructionItem;
}

int destroyInstructionItem(struct InstructionItem* instructionItem) {
    if (NULL != instructionItem) {
        free(instructionItem);
        return 1;
    }
    return 0;
}

//struct Instruction {
//    struct InstructionItem** list;
//    int tail;
//};

struct Instruction* generateInstruction() {
    struct Instruction* instruction = (struct Instruction*)malloc(sizeof(struct Instruction));
    instruction->list = (struct InstructionItem**)malloc(sizeof(struct InstructionItem*)*256);
    instruction->size = 256;
    instruction->tail = 0;
    return instruction;
}

int makeNewTemp(struct Instruction* instruction, struct InstructionItem* instructionItem) {
    if (instruction->size == instruction->tail) {
        struct InstructionItem** temporary = instruction->list;
        instruction->list = (struct InstructionItem**)malloc(sizeof(struct InstructionItem*)*instruction->size*2);
        int cursor = 0;
        for (; cursor < instruction->size; cursor++) {
            instruction->list[cursor] = temporary[cursor];
        }
        free(temporary);
        instruction->size *= 2;
    }
    instruction->list[instruction->tail] = instructionItem;
//    return (int&)instruction->list[instruction->tail++];
    return (int)instructionItem;
}

int destroyInstruction(struct Instruction* instruction) {
    if (NULL != instruction) {
        if (NULL != instruction->list) {
            int cursor = 0;
            for (; cursor < instruction->tail; cursor++) {
                destroyInstructionItem(instruction->list[cursor]);
            }
            free(instruction->list);
            return 1;
        }
        return -1;
    }
    return 0;
}
