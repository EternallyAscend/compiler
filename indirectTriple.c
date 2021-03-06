//
// Created by MagicBook on 2020/12/14.
//

#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "indirectTriple.h"

//struct InstructionItem{
//    char* operatorType;
//    int arg0; // Address.
//    int arg1; // Address.
//};

// struct InstructionItem* generateIndirectTriple(char* operatorType, int arg0, int arg1) {
struct InstructionItem* generateIndirectTriple(char* operatorType, char* arg0, char* arg1) {
    struct InstructionItem* instructionItem = (struct InstructionItem*)malloc(sizeof(struct InstructionItem));
    if (NULL != operatorType) {
        instructionItem->operatorType = (char*)malloc(sizeof(char)*16);
        sprintf(instructionItem->operatorType, "%s", operatorType);
    }
    else {
        instructionItem->operatorType = NULL;
    }
    if (NULL != arg0) {
        instructionItem->arg0 = (char*)malloc(sizeof(char)*128);
        sprintf(instructionItem->arg0, "%s", arg0);
    }
    else {
        instructionItem->arg0 = NULL;
    }
    if (NULL != arg1) {
        instructionItem->arg1 = (char*)malloc(sizeof(char)*128);
        sprintf(instructionItem->arg1, "%s", arg1);
    }
    else {
        instructionItem->arg1 = NULL;
    }
    return instructionItem;
}

// struct InstructionItem* generateIndirectTripleWithType(char* operatorType, int arg0, int arg1, int type0, int type1) {
//     struct InstructionItem* instructionItem = (struct InstructionItem*)malloc(sizeof(struct InstructionItem));
//     instructionItem->operatorType = operatorType;
//     instructionItem->arg0 = arg0;
//     instructionItem->arg1 = arg1;
//     instructionItem->type0 = type0;
//     instructionItem->type1 = type1;
//     return instructionItem;
// }

int destroyInstructionItem(struct InstructionItem* instructionItem) {
    if (NULL != instructionItem) {
        if (NULL != instructionItem->operatorType) {
            free(instructionItem->operatorType);
        }
        if (NULL != instructionItem->arg0) {
            free(instructionItem->arg0);
        }
        if (NULL != instructionItem->arg1) {
            free(instructionItem->arg1);
        }
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
    // instruction->values = (char**)malloc(sizeof(char*)*256);
    instruction->size = 256;
    instruction->tail = 0;
    int cursor = 0;
    // for (; cursor < 256; cursor++) {
    //     instruction->values[cursor] = (char*)malloc(sizeof(char)*64);
    // }
    return instruction;
}

int makeNewTemp(struct Instruction* instruction, struct InstructionItem* instructionItem) {
    //printf("HELP! MakeNewTemp: %s %s %s\n", instructionItem->operatorType, instructionItem->arg0, instructionItem->arg1);
    if (instruction->size == instruction->tail) {
        struct InstructionItem** temporary = instruction->list;
        // char** lists = instruction->values;
        instruction->list = (struct InstructionItem**)malloc(sizeof(struct InstructionItem*)*instruction->size*2);
        // instruction->values = (char**)malloc(sizeof(char*)*instruction->size*2);
        int cursor = 0;
        for (; cursor < instruction->size; cursor++) {
            instruction->list[cursor] = temporary[cursor];
            // instruction->values[cursor] = lists[cursor];
        }
        free(temporary);
        // free(lists);
        instruction->size *= 2;
    }
    instruction->list[instruction->tail] = instructionItem;
//    return (int&)instruction->list[instruction->tail++];
    // return (int)instructionItem;
    return instruction->tail++;
}

int rewriteTemp(struct Instruction* instruction, int index, int pos, char* arg) {
    if (0 > index || index >= instruction->tail) {
        //printf("Wrong index.\n");
        return -1;
    }
    //printf("HELP! Rewrite %d code at %d with %s.\n", index, pos, arg);
    struct InstructionItem* item = instruction->list[index];
    switch (pos)
    {
        case 0:
            sprintf(item->operatorType, "%s", arg);
            break;
        case 1:
            sprintf(item->arg0, "%s", arg);
            break;
        case 2:
            sprintf(item->arg1, "%s", arg);
            break;
        default:
            return -1;
    }
    return 1;
}

int destroyInstruction(struct Instruction* instruction) {
    generateCENTER();
    char* appendContent = (char*)malloc(sizeof(char)*1024);
    if (NULL != instruction) {
        if (NULL != instruction->list) {
            int cursor = 0;
            for (; cursor < instruction->tail; cursor++) {
                sprintf(appendContent, "%4d %s %s %s\n", cursor,
                 instruction->list[cursor]->operatorType,
                 instruction->list[cursor]->arg0,
                 instruction->list[cursor]->arg1);
                appendCENTER(appendContent);
                destroyInstructionItem(instruction->list[cursor]);
            }
            free(instruction->list);
            // return 1;
        }
        // if (NULL != instruction->values) {
        //     int cursor = 0;
        //     for (; cursor < instruction->tail; cursor++) {
        //         if (NULL != instruction->values[cursor]) {
        //             free(instruction->values[cursor]);
        //         }
        //     }
        //     free(instruction->values);
        // }
        // return -1;
    }
    free(appendContent);
    closeCENTER();
    return 0;
}
