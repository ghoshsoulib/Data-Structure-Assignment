#include <stdio.h>
#include <stdlib.h>

int **AdjMatrix;

typedef struct Node{
	int data;
	struct Node * next;
}Node;

typedef Node *Stack;

Stack initStack(){
	return NULL;
}

Stack createNode(int info){
	Stack node=(Stack)(malloc(sizeof(Stack)));
	node->data=info;
	node->next=NULL;
	return node;
}

int empty(Stack top){
	return (top==NULL);
}

void push(Stack *p2top,int input){
	Stack target=createNode(input);
	target->next=*p2top;
	*p2top=target;
	target=NULL;
}

int pop(Stack *p2top){
	if(empty(*p2top)){
		printf("pop(p2top):Stack Underflow\n");
		exit(0);
	}
	else{
		int val;
		Stack temp=*p2top;
		*p2top=temp->next;
		val=temp->data;
		free(temp);
		return val;

	}
}


void createAdjMat(int noOfVertices,int dia){
	int i,j;
	AdjMatrix=(int **)(malloc(noOfVertices*sizeof(int *)));
	for(i=0;i<noOfVertices;i++){AdjMatrix[i]=(int *)(malloc(noOfVertices*sizeof(int)));}
	printf("Enter pairs of vertices to have an edge between them(End by entering a string)\n");
	while(scanf("%d%d",&i,&j)){
		if(AdjMatrix[i-1][j-1]){printf("They are already connected\n");}
		else{
			AdjMatrix[i-1][j-1]=1;
			if(!dia){AdjMatrix[j-1][i-1]=1;}
		}
	}	
}

void printAdjMat(int noOfVertices){
	int i,j;
	for(i=0;i<noOfVertices;i++){
		for(j=0;j<noOfVertices;j++){printf("%3d\t",AdjMatrix[i][j]);}
		printf("\n");
	}	
}

void itrDfs(int *visited,int noOfVertices,int u){
	Stack stk=initStack();
	int v,i;
	push(&stk,u);
	do{
		v=pop(&stk);
		if(!visited[v-1]){
			printf("%d\t",v);
			visited[v-1]=1;
		}
		for(i=1;i<=noOfVertices;i++){
			if(AdjMatrix[v-1][i-1] && !visited[i-1]){ push(&stk,i);}
		}
	}while(!empty(stk));
}

int main(){
	int noOfVertices,i,dia,start;
	int *visited;
	printf("Enter No. Of Vertices :");
	scanf("%d",&noOfVertices);
	visited=(int *)(malloc(noOfVertices*sizeof(int)));
	for(i=0;i<noOfVertices;i++){visited[i]=0;}
	if(noOfVertices){ printf("The Vertices Are Numbered 1 to %d\n",noOfVertices);}
	printf("Directed/Undirected Graph(1/0) :");
	scanf("%d",&dia);
	printf("Enter Start of DFS:");
	scanf("%d",&start);
	createAdjMat(noOfVertices,dia);
	printAdjMat(noOfVertices);
	itrDfs(visited,noOfVertices,start);
	printf("\n");
	free(visited);
	free(AdjMatrix);
	return 0;
}