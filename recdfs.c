# include <stdio.h>
# include <stdlib.h>

typedef struct node{
	int value;
	struct node *next;
}Node;

Node **AdjList;

int isEmpty(Node *head){ return (head==NULL); }

Node *createNode(int data){
	Node *t = (Node *)(malloc(sizeof(struct node)));
	t->value = data;
	t->next=NULL;
	return t;
}

void addFront(Node **head,Node *target){
	if(!isEmpty(*head)){ target->next=(*head);}
	*head=target;
	target=NULL;
}

void printList(Node *head){
	if(isEmpty(head)){ printf("\n");}
	else{
		printf("%3d\t",head->value);
		printList(head->next);
	}
}

void createAdjList(int noOfVertices,int dia){
	AdjList=(Node **)(malloc(noOfVertices*sizeof(Node *)));
	int i,j;
	printf("Enter pairs of vertices to have an edge between them(End by entering a string)\n");
	while(scanf("%d%d",&i,&j)){
		addFront(&AdjList[i-1],createNode(j));
		if(!dia){addFront(&AdjList[j-1],createNode(i));}
	}
	for(i=0;i<noOfVertices;i++){
		printf("%3d -> ",i+1);
		printList(AdjList[i]);
	}
	printf("End\n");
}

void recDfs(int *visited,int u){
	printf("%d\t",u);
	visited[u-1]=1;
	Node *cur;
	for(cur=AdjList[u-1];cur!=NULL;cur=cur->next){
		if(!visited[(cur->value)-1]){ recDfs(visited,cur->value);}
	}
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
	createAdjList(noOfVertices,dia);
	recDfs(visited,start);
	printf("\n");
	free(visited);
	free(AdjList);
	return 0;
}



