//각 Probelms는 주석처리하였음


#define GL_SILENCE_DEPRECATION //OPENGL API 사용 경고 메세지 무시(왜인지 적용 안됨) - 특정 버전 이후로 지원 안됨 - Apple은 OPENGL대신 Metal api를 권장 중.
#define slice 100
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "StackQueue.h"

//그래프를 그리기 위해 전역으로 할당함.
Poly *head;
/*
GLvoid Draw() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
    
    //그래프의 각 점 연결 x : -10~10 범위
    for(double i = -slice ; i <= slice ; i++){ //i : -100 ~ 100
        glVertex2f(i/slice,GetResult(&head, i/10)/10);
    }
    glEnd();
    glFinish();
    
    glBegin(GL_LINES);
    glVertex2f(-1,0);
    glVertex2f(1,0);
    glEnd();
    glFinish();
    
    glBegin(GL_LINES);
    glVertex2f(0,1);
    glVertex2f(0,-1);
    glEnd();
    glFinish();
}
*/
int main(int argc, const char * argv[]) {
    //다항식 계산
    
    double arr[5][2] = { //선형리스트를 활용한 구현(CreateAbsolPoly함수에 인자로 넣음)
        {6.7,4},
        {3.2,3},
        {-1,2},
        {1,1},
        {-2,0}
    };
    head = CreateAbsolPoly(arr, 5);
    ShowPoly(head);
    
    //그래프 그리기
    /*
    glutInit(&argc, argv);
    glutCreateWindow("OpenGLGraph");
    glutDisplayFunc(Draw);
    glutMainLoop();
    
    PolyFree(head);
    free(head);
    */
    //근 구하기
    /*
    int rootcount = 2;
    double *root = FindRoot(head, -10, 10, 100000, rootcount); //2개 구함 div = 100000 1을 100000으로 나눠서 검사
    for(int i = 0 ; i < rootcount ; i++){
        printf("%d번째 근 : %f ", i+1, root[i]);
    }
    puts("");
    free(root);
    */
    //최솟값 구하기
    /*
    double min = FindMin(head, -10, 10, 100000);
    printf("최솟값 : %f \n", min);
    */
    
    
    
    
    //큐 구현
    /*
    Queue *Q = CreateNewQueue(20);
    ShowQueueDetail(Q);
    Enqueue(Q, 'a');
    ShowQueueDetail(Q);
    Enqueue(Q, 'b');
    ShowQueueDetail(Q);
    Enqueue(Q, 'c');
    ShowQueueDetail(Q);
    QFree(Q);
    */
    
    //스택 구현
    /*
    Stack *S = CreateNewStack(4);
    Push(S, 'a');
    ShowStackDetail(S);
    Push(S, 'b');
    ShowStackDetail(S);
    Push(S, 'c');
    ShowStackDetail(S);
    Push(S, 'd');
    ShowStackDetail(S);
    Push(S, 'd');
    ShowStackDetail(S);
    Pop(S);
    ShowStackDetail(S);
    Pop(S);
    ShowStackDetail(S);
    Pop(S);
    ShowStackDetail(S);
    Pop(S);
    ShowStackDetail(S);
    */
    
    //ParenthesisMatching구현
    
    char arr2[100] = "(((a+b)*c+d−e)/(f+g)−(h+j)*(k−l))/(m−n)";
    ParenthesisMatching(arr2, 100);
    
    char arr3[100] = "(a−b*c)+d−(e−(f−g)/h)/(i*j)−k";
    ParenthesisMatching(arr3, 100);
    
    
    //infix2postfix구현
    /*
    char arr4[100] = "(a−b*c)+d−(e−(f−g)/h)/(i*j)−k";
    char *result = Infix2Postfix(arr4, MAX_SIZE);
    for(int i = 0 ; i < MAX_SIZE ; i++){
        printf("%c", result[i]);
    }
    free(result);
    puts("");
    */
    return 0;
}
