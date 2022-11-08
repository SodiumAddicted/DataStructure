#define GL_SILENCE_DEPRECATION //OPENGL API 사용 경고 메세지 무시(왜인지 적용 안됨) - 특정 버전 이후로 지원 안됨
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
}*/

int main(int argc, const char * argv[]) {
    //다항식 계산
    /*
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
    glutInit(&argc, argv);
    glutCreateWindow("OpenGLGraph");
    glutDisplayFunc(Draw);
    glutMainLoop();
    
    PolyFree(head);
    free(head);
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
    
    
    return 0;
}
