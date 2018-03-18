# include <stdio.h>
# include <stdlib.h>

int **AdjMatrix;

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

int main(){
	int noOfVertices,i,dia;
	printf("Enter No. Of Vertices :");
	scanf("%d",&noOfVertices);
	if(noOfVertices){ printf("The Vertices Are Numbered 1 to %d\n",noOfVertices);}
	printf("Directed/Undirected Graph(1/0) :");
	scanf("%d",&dia);
	createAdjMat(noOfVertices,dia);
	printAdjMat(noOfVertices);
	for(i=0;i<noOfVertices;i++){free(AdjMatrix[i]);}
	free(AdjMatrix);
	return 0;
}
