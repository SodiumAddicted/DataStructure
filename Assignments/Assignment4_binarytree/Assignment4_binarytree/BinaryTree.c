#include "Header.h"

Node *CreateNode(char data){
       Node* NewNode = (Node*)malloc(sizeof(Node));

       NewNode -> left = NULL;
       NewNode -> right = NULL;
       NewNode -> data = data;

      return NewNode;
}

void DestroyTree(Node *Remove){
      if(NULL == Remove)
       {
           return;
       }

       // 좌 노드 삭제
       DestroyTree(Remove -> left);

       // 우 노드 삭제
       DestroyTree(Remove -> right);

       // 근 노드 삭제
      free(Remove);
}

void InfixOrder(Node *root){ //inorder
    if(root != NULL){
        InfixOrder(root -> left);
        printf("%c ", root -> data);
        InfixOrder(root -> right);
    }
}

void PrefixOrder(Node *root){ //preorder
    if(root != NULL){
        printf("%c ", root -> data);
        PrefixOrder(root -> left);
        PrefixOrder(root -> right);
    }
}

void PostfixOrder(Node *root){ //postorder
    if(root != NULL){
        PostfixOrder(root -> left);
        PostfixOrder(root -> right);
        printf("%c ", root -> data);
    }
}

void LevelOrder(Node *root){ //큐기능 필요
    Queue *Q = QueueInit();
    Node *temp;
    
    Enqueue(Q, root);
    
    while(!isEmpty(Q)){
        temp = Dequeue(Q);
        printf("%c ", temp -> data);
        
        if (temp -> left){
            Enqueue(Q, temp -> left);
        }
        if (temp -> right){
            Enqueue(Q, temp -> right);
        }
    }
}
