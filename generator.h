//
// Created by MagicBook on 2020/12/26.
//

#ifndef INDIRECTTRIPLE_GENERATOR_H
#define INDIRECTTRIPLE_GENERATOR_H

#include "grammerTree.h"
#include "indirectTriple.h"

int indirectTripleCodeGenerator(GrammarTree root, struct Instruction* instruction);

enum OPERATORS {
    _ERROR=-1,
    _VOID=0,
    _INT=1,
    _FOR=10,
    _FOR_INIT=11,
    _FOR_CONDITION=12,
    _FOR_ACTION=13,
    _FOR_EXPRESSION=14,

    _WHILE_CONDITION=16,
    _DO_WHILE=17,
    _DO=18,
    _WHILE=19,
    _CONTINUE=999,
    _BREAK=1000,
    _IF=20,
    _ELSE=21,
    _IF_STMT=22,
    _IF_CONDITION=23,
    _RETURN=30,
    _ADDRESS=40,
    _ARRAY=50,
    _LPRP=60,
    _LP=61,
    _RP=62,
    _SLPRP=63,
    _LSP=64,
    _RSP=65,
    _BLPRP=66,
    _LBP=67,
    _RBP=68,
    _LOOP=70,
    _POINTER=80,
    _ASSIGN=100,
    _DECLARATION=101,
    _ARGUMENT_DECLARATION_LIST=102,
    _DECLARATION_BODY=103,
    _ARGUMENT_DECLARATION_UNIT=104,
    _EQUAL=200,
    _NOTEQUAL=201,
    _GT=202,
    _LT=203,
    _GE=204,
    _LE=205,
    _AND=300,
    _OR=301,
    _NOT=302,
    _ADD=400,
    _MINUS=401,
    _TIMES=402,
    _DIVIDE=403,
    _MOD=404,
    _POW=405,
    _COMMA=500,
    _STMT_BODY=600,
    _INPUT=65000,
    _PRINT_CONTENT=65001,
    _PRINT=65002,
    _START=65500,
    _MAIN=65532,
    _ID=65533,
    _STRING=65534,
    _CONST=65535,
} op;

#endif //INDIRECTTRIPLE_GENERATOR_H
