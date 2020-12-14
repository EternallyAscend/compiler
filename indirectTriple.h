//
// Created by MagicBook on 2020/12/14.
//

#ifndef INDIRECTTRIPLE_INDIRECTTRIPLE_H
#define INDIRECTTRIPLE_INDIRECTTRIPLE_H

struct InstructionItem{
    char* operatorType;
    int arg0; // Address.
    int arg1; // Address.
};

struct InstructionItem* generateIndirectTriple(char* operatorType, int arg0, int arg1);

int destroyInstructionItem(struct InstructionItem* instructionItem);

struct Instruction {
    struct InstructionItem** list;
    unsigned long long int size;
    unsigned long long int tail;
};

struct Instruction* generateInstruction();

int makeNewTemp(struct Instruction* instruction, struct InstructionItem* instructionItem);

int destroyInstruction(struct Instruction* instruction);

#endif //INDIRECTTRIPLE_INDIRECTTRIPLE_H
