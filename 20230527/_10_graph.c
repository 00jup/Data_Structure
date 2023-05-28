#include <stdio.h>

const int MAX_VTXS = 100;
typedef char VtxData;
int adj[MAX_VTXS][MAX_VTXS];
VtxData vdata[MAX_VTXS];
int vsize;
void init_graph()
{
  vsize = 0;
  for (int i = 0; i < MAX_VTXS; i++)
  {
    for (int j = 0; j < MAX_VTXS; j++)
    {
      adj[i][j] = 0;
    }
  }
}

void insert_vertex(VtxData name)
{
  if (vsize + 1 > MAX_VTXS)
  {
    fprintf(stderr, "그래프: 정점 개수 초과");
    return;
  }
  vdata[vsize++] = name;
}

void insert_edge(int u, int v, int val)
{
  adj[u][v] = val;
}
void insert_edge2(int u, int v, int val)
{
  adj[u][v] = val;
  adj[v][u] = val;
}

void print_graph(FILE *fp, const char *msg)
{
  fprintf(fp, "%s\n", msg);
  for (int i = 0; i < vsize; i++)
  {
    fprintf(fp, "%c: ", vdata[i]);
    for (int j = 0; j < vsize; j++)
    {
      fprintf(fp, "%2d", adj[i][j]);
    }
    fprintf(fp, "\n");
  }
}

int main()
{
  init_graph();
  for (int i = 0; i < 4; i++)
  {
    insert_vertex('A' + i);
  }
  insert_edge2(0, 1, 1);
  insert_edge2(0, 3, 1);
  insert_edge2(1, 2, 1);
  insert_edge2(1, 3, 1);
  insert_edge2(2, 3, 1);
  print_graph(stdout, "그래프 G1: ");
  return 0;
}