#ifndef COMPILER_NODETYPES_H
#define COMPILER_NODETYPES_H

enum NodeTypes {
    PROG,
    DECL,
    DECLS,
    STATEMENT,
	STATEMENT2,
	STATEMENT3,
	STATEMENT4,
	STATEMENT5,
	STATEMENT6,
    STATEMENTS,
    ARRAY,
    EPSILON,
    EXP,
    EXP2,
	EXP2_2,
	EXP2_3,
	EXP2_4,
	EXP2_5,
    OPEXP,
    OP,
	OP2,
	OP3,
	OP4,
	OP5,
	OP6,
	OP7,
	OP8,
	OP9,
    INDEX
};
// für typeCheck
enum Types {
	noType,
	errorType,
	intType,
	arrayType,
	intArrayType,
	opPlus,
	opMinus,
	opMult,
	opDiv,
	opLess,
	opGreater,
	opEqual,
	opUnequal,
	opAnd
};

#endif //COMPILER_NODETYPES_H
