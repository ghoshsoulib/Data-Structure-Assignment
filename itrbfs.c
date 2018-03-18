# include <stdio.h>
# include <stdlib.h>
# define MAX 100 

typedef struct Q{
	int val[MAX];
	int front;
	int rear;
};

typedef struct Q *queue;

int **AdjMatrix;

// Initializing an empty queue
queue initQ(){
	queue q1;
	if(q1=(queue)(malloc(sizeof(struct Q)))) { 
		q1->front=-1;
		q1->rear=-1;
		return q1;
	}
	else{
		printf("initQ:malloc error\n");
		exit(0);
	}
}
int isEmpty(queue q1){
	return (q1->front==-1 && q1->rear==-1);
}

int isFull(queue q1){
	return ((q1->rear+1)%MAX==q1->front);
}

int frontQ(queue q1){
	if(isEmpty(q1)){
		printf("frontQ:queue is empty\n");
		exit(0);
	}
	else return q1->val[q1->front];
}

void enqueue(queue q1,int value){
	if(isFull(q1)){
		printf("enqueue:queue is full\n");
		exit(0);
	}
	else if(isEmpty(q1)){
		q1->rear=0;
		q1->front=0;
	}
	else{
		q1->rear=(q1->rear+1)%MAX;
	}
	q1->val[q1->rear]=value;
}

int dequeue(queue q1){
	int data;
	if(isEmpty(q1)){
		printf("dequeue:queue is empty\n");
		exit(0);
	}
	else if(q1->front==q1->rear){
		data=frontQ(q1);
		q1->front=-1;
		q1->rear=-1;
	}
	else{
		data=frontQ(q1);
		q1->front=(q1->front+1)%MAX;
	}
	return data;
}

void printQ(queue q1){
	int i;
	for(i=q1->front;i<=q1->rear;i++){ printf("%d\t",q1->val[i]);}
	printf("\n");
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

void itrBfs(int *visited,int noOfVertices,int u){
	queue qu=initQ();
	int i,v;
	enqueue(qu,u);
	do{
//		printf("Current Status Of Queue is :");
//		printQ(qu);
		v=dequeue(qu);
		if(!visited[v-1]){
			printf("%d\t",v);
			visited[v-1]=1;
		}
		for(i=1;i<=noOfVertices;i++){
			if(AdjMatrix[v-1][i-1] && !visited[i-1]){enqueue(qu,i);}
		}
	}while(!isEmpty(qu));
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
	itrBfs(visited,noOfVertices,start);
	printf("\n");
	free(visited);
	free(AdjMatrix);
	return 0;
}