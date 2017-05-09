#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

#define max_size 100

int n;
int visited[max_size];
int matrix[max_size][max_size];

void DFS(int value);
void BFS(int value);
