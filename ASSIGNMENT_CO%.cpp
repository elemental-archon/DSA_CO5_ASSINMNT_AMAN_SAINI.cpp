#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<vector>

#define NUM_VERTICES 6

using namespace std;

struct adjacency_node
{
    char node;
    adjacency_node * next_node = NULL;
};


struct graph
{
    char node;
    vector<graph*> ptr;
};


struct vertex_node
{
    char node_name;
    adjacency_node* list_base_addr = NULL;
    graph* node_addr = NULL;
    vertex_node* next_node = NULL;    
};

adjacency_node* al_head = NULL;
adjacency_node* al_tail = NULL;

vertex_node* va_head = NULL;
vertex_node* va_tail = NULL;
vertex_node* temp_va_tail = NULL;

void create_vertex_array(vertex_node* new_node)
{
    if(va_head == va_tail)
    {
        va_tail = new_node;
        temp_va_tail = va_tail;
    }
    else
    {
        temp_va_tail->next_node = new_node;
        temp_va_tail = new_node;
    }
}

void create_adjacency_linked_list(adjacency_node* new_node, vertex_node* vertex_node_addr)
{
    if(al_head == al_tail)
    {
        vertex_node_addr->list_base_addr = new_node;
        al_tail = new_node;
    }
    else
    {
        al_tail->next_node = new_node;
        al_tail = new_node;
    }
}


void traverse_adjacency_list(adjacency_node* base_addr)
{
    while(base_addr != NULL)
    {
        printf("%c -> ",base_addr->node);
        base_addr = base_addr->next_node;
    }

    printf("NULL");
}


void add_edge(graph* src_node, graph* dst_node)
{

}

int main()
{
    srand(time(NULL));
    bool is_edge;
    adjacency_node* new_al_node = NULL;
    graph* new_graph_node = NULL;
    vertex_node* new_va_node = NULL;

    temp_va_tail = va_tail;

    for(size_t i=0; i<NUM_VERTICES; i++)
    {
        new_va_node = (vertex_node*)calloc(1,sizeof(vertex_node));
        new_va_node->node_name = (65 + i);
        new_graph_node = (graph*)calloc(1,sizeof(graph));
        new_graph_node->node = (65 + i);
        new_va_node->node_addr = new_graph_node;
        create_vertex_array(new_va_node);

        al_head = NULL;
        al_tail = NULL;

        for(size_t j=0; j<NUM_VERTICES; j++)
        {
            if(i == j)
                continue;
            else
            {
                is_edge = rand() % 2;

                if(is_edge == true)
                {
                    new_al_node = (adjacency_node*)calloc(1,sizeof(adjacency_node));
                    new_al_node->node = (65 + j);
                    create_adjacency_linked_list(new_al_node,new_va_node);
                }
            }
        }
    }

    printf("constructed Graph is :\n\n");

    temp_va_tail = va_tail;
    while(temp_va_tail != NULL)
    { 
        printf("Adjacency List of Node %c is: ",temp_va_tail->node_name);
        traverse_adjacency_list(temp_va_tail->list_base_addr);
        printf("\n");
        temp_va_tail = temp_va_tail->next_node;    
    }

    temp_va_tail = va_tail;


    
    return 0;
}
