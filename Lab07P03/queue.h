#pragma once
#include <stdlib.h>
#include "node.h"

Node *first, *last;

void qpush(int value);
void qpop();
int  qtop();
