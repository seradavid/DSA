#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "queue.h"
//#include "stack.h"

int g[100][100];
int visited[100];
int cost[100];
int n, m;
int directed = 0;
int weighted = 0;

void read_matrix(char *filename);
void read_edges(char *filename);
void dfs();
void bfs();
void dijkstra_dfs();
void dijkstra_bfs();
