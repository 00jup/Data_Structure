#include <stdio.h>
#include <stdlib.h>
#define MAX_VTXS 256
void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}
typedef struct GraphNode
{
    int id;
    struct GraphNode *link;
} GNode;
typedef char VtxData;
GNode *adj[MAX_VTXS];
int vsize;
VtxData vdata[MAX_VTXS];
int is_empty_graph() { return (vsize == 0); }
int is_full_graph() { return (vsize >= MAX_VTXS); }

void init_graph()
{
    int i;
    vsize = 0;
    for (i = 0; i < MAX_VTXS; i++)
        adj[i] = NULL;
}
void reset_graph()
{
    int i;
    GNode *n;
    for (i = 0; i < vsize; i++)
    {
        while (adj[i] != NULL)
        {
            n = adj[i];
            adj[i] = n->link;
            free(n);
        }
    }
    vsize = 0;
}

void insert_vertex(VtxData name)
{
    if (is_full_graph())
        error("Error: 그래프 정점의개수 초과\n");
    else
        vdata[vsize++] = name;
}
void insert_edge(int u, int v)
{
    GNode *n =
        (GNode *)malloc(sizeof(GNode));
    n->link = adj[u];
    n->id = v;
    adj[u] = n;
}

void print_graph(char *msg)
{
    int i;
    GNode *v;
    printf("%s%d\n", msg, vsize);
    for (i = 0; i < vsize; i++)
    {
        printf("%c  ", vdata[i]);
        for (v = adj[i]; v != NULL; v = v->link)
            printf(" %c", vdata[v->id]);
        printf("\n");
    }
}

void load_graph(char *filename)
{
    int i, j, val, n;
    char str[80];
    FILE *fp;
    fp = fopen(filename, "r");
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
                insert_edge(i, j);
        }
    }
    fclose(fp);
}

int main()
{
    load_graph("graph.txt"); // console 에서 텍스트 파일내용이 보이지 않으면, 파일명 앞에 파일경로 추가
    print_graph("그래프(인접리스트)\n");
    return 0;
}