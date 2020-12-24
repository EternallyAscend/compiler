//
// Created by MagicBook on 2020/12/14.
//

#ifndef INDIRECTTRIPLE_INDIRECTTRIPLE_H
#define INDIRECTTRIPLE_INDIRECTTRIPLE_H

#define CONST_NUMBER_VALUE 0
#define SYMBOL_TABLE_ADDRESS 10
#define TEMPORARY_ADDRESS 20
#define THREE_COMMAND_ADDRESS 30

struct InstructionItem{
    char* operatorType;
    char* arg0; // int arg0; // Address.
    char* arg1; // int arg1; // Address.
    // int type0;
    // int type1;
};

// struct InstructionItem* generateIndirectTriple(char* operatorType, int arg0, int arg1);
struct InstructionItem* generateIndirectTriple(char* operatorType, char* arg0, char* arg1);

// struct InstructionItem* generateIndirectTripleWithType(char* operatorType, int arg0, int arg1, int type0, int type1);
// struct InstructionItem* generateIndirectTripleWithType(char* operatorType, char* arg0, char* arg1, int type0, int type1);

int destroyInstructionItem(struct InstructionItem* instructionItem);

struct Instruction {
    struct InstructionItem** list;
    char** values;
    unsigned long long int size;
    unsigned long long int tail;
};

struct Instruction* generateInstruction();

int makeNewTemp(struct Instruction* instruction, struct InstructionItem* instructionItem);

int destroyInstruction(struct Instruction* instruction);

#endif //INDIRECTTRIPLE_INDIRECTTRIPLE_H
