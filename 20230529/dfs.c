#include <stdio.h>
#include <stdlib.h>
#define MAX_VTXS 256

void error(char str[])
{
  printf("%s\n", str);
  exit(1);
}
typedef char VtxData;
int adj[MAX_VTXS][MAX_VTXS];
int vsize;

VtxData vdata[MAX_VTXS];

int is_empty_graph() { return (vsize == 0); }
int is_full_graph() { return (vsize >= MAX_VTXS); }
void init_graph()
{
  int i, j;
  vsize = 0;
  for (i = 0; i < MAX_VTXS; i++)
    for (j = 0; j < MAX_VTXS; j++)
      adj[i][j] = 0;
}
void insert_vertex(VtxData name)
{
  if (is_full_graph())
    error("Error: 그래프 정점의 개수 초과\n");
  else
    vdata[vsize++] = name;
}

void insert_edge(int u, int v, int val)
{
  adj[u][v] = val;
}

void insert_edge2(int u, int v, int val)
{
  adj[u][v] = adj[v][u] = val;
}

void print_graph(char *msg)
{
  int i, j;
  printf("%s", msg);
  printf("%d\n", vsize);
  for (i = 0; i < vsize; i++)
  {
    printf("%c  ", vdata[i]);
    for (j = 0; j < vsize; j++)
      printf(" %3d", adj[i][j]);
    printf("\n");
  }
}
void load_graph(char *filename)
{
  int i, j, val, n;
  char str[80];
  FILE *fp = fopen(filename, "r"); // int로 해도 되나

  init_graph();
  fscanf(fp, "%d", &n);

  for (i = 0; i < n; i++)
  {
    fscanf(fp, "%s", str);
    insert_vertex(str[0]);
    for (j = 0; j < n; j++)
    {
      fscanf(fp, "%d", &val);
      if (val != 0)
        insert_edge(i, j, val);
    }
  }

  fclose(fp);
}

visited[MAX_VTXS];
void reset_visited()
{
  int i;
  for (i = 0; i < vsize; i++)
    visited[i] = 0;
}
void DFS(int v)
{
  int w;
  visited[v] = 1;
  printf("%c ", vdata[v]);
  for (w = 0; w < vsize; w++)
    if (adj[v][w] != 0 && visited[w] == 0)
      DFS(w);
}

int main()
{
  load_graph("graph.txt"); // console에서 텍스트 파일내용이 보이지 않으면, 파일명 앞에 파일경로 추가
  reset_visited();
  printf("DFS ==> ");
  DFS(0);
  printf("\n");
  return 0;
}