//각 Probelms는 주석처리하였음


#define GL_SILENCE_DEPRECATION //OPENGL API 사용 경고 메세지 무시(왜인지 적용 안됨) - 특정 버전 이후로 지원 안됨 - Apple은 OPENGL대신 Metal api를 권장 중.
#define slice 100
#include <OpenGL/gl3.h>
#include <GLUT/glut.h>
#include "StackQueue.h"

//그래프를 그리기 위해 전역으로 할당함.
Poly *head;
/*
GLvoid Draw(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
    
    //그래프의 각 점 연결 x : -10~10 범위
    for(double i = -slice ; i <= slice ; i++){ //i : -100 ~ 100
        glVertex2f(i/slice,GetResult(head, i/10)/10);
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
int main(int argc, char * argv[]) {
    //다항식 계산
    int userinput = 0;
    
    
    while(1){
        printf("1: 다항식 계산 프로그램, 2: 큐 구현, 3: 괄호 매칭 확인, 4: Infix2Postfix, 0: 종료\n");
        printf("입력하세요:");
        scanf("%d", &userinput);
        
        switch(userinput){
            case 1 :
            {
                double arr[5][2] = { //선형리스트를 활용한 구현(CreateAbsolPoly함수에 인자로 넣음)
                    {6.7,4},
                    {3.2,3},
                    {-1,2},
                    {1,1},
                    {-2,0}
                };
                head = CreateAbsolPoly(arr, 5);
                ShowPoly(head);
                //근 구하기
                
                int rootcount = 2;
                double *root = FindRoot(head, -10, 10, 100000, rootcount); //2개 구함 div = 100000 1을 100000으로 나눠서 검사
                for(int i = 0 ; i < rootcount ; i++){
                    printf("%d번째 근 : %f ", i+1, root[i]);
                }
                puts("");
                free(root);
                
                //최솟값 구하기
                
                double min = FindMin(head, -10, 10, 100000);
                printf("최솟값 : %f \n", min);
                
                //그래프 그리기
                /*
                printf("그래프를 출력합니다.\n");
                glutInit(&argc, argv);
                glutCreateWindow("OpenGLGraph");
                glutDisplayFunc(Draw);
                glutMainLoop();
                */
                PolyFree(head);
                free(head);
                break;
            }
            case 2 :
            {
                //큐 구현
                Queue *Q = CreateNewQueue(20);
                int userinput2 = 0;
                int loop = 1;
                while(loop){
                    printf("1: 큐 보기, 2: Enqueue, 3: Dequeue, 0: 종료\n");
                    printf("입력:");
                    scanf("%d", &userinput2);
                    switch(userinput2){
                        case 1:
                            ShowQueueDetail(Q);
                            break;
                        case 2:
                        {
                            fflush(stdin);
                            char userchar;
                            printf("입력할 문자 : ");
                            scanf("%c", &userchar);
                            Enqueue(Q, userchar);
                            if(!isQFull(Q)){
                                printf("Enqueue 완료\n");
                            }
                            break;
                        }
                        case 3:
                            Dequeue(Q);
                            if(!isQEmpty(Q)){
                                printf("Dequeue 완료\n");
                            }
                            break;
                        case 0:
                            QFree(Q);
                            loop = 0;
                            break;
                        default:
                            printf("재입력 해주세요\n");
                            break;
                    }
                }
                
                break;
            }
            case 3:
            {
                //ParenthesisMatching구현
                char arr2[100] = "(((a+b)*c+d−e)/(f+g)−(h+j)*(k−l))/(m−n)";
                printf("(((a+b)*c+d−e)/(f+g)−(h+j)*(k−l))/(m−n) ParenthesisMatching 결과\n");
                ParenthesisMatching(arr2, 100);
                
                char arr3[100] = "(a−b*c)+d−(e−(f−g)/h)/(i*j)−k";
                printf("(a−b*c)+d−(e−(f−g)/h)/(i*j)−k ParenthesisMatching 결과\n");
                ParenthesisMatching(arr3, 100);
                break;
            }
            case 4:
            {
                //infix2postfix구현
                
                char *arr4 = (char*)calloc(100,sizeof(char));
                printf("식 입력:");
                scanf("%s", arr4);
                char *result = Infix2Postfix(arr4, MAX_SIZE);
                for(int i = 0 ; i < MAX_SIZE ; i++){
                    printf("%c", result[i]);
                }
                free(result); //반환값으로 받은 result 힙영역에서 해제
                free(arr4);
                puts("");
                break;
            }
            case 0:
                printf("프로그램을 종료합니다\n");
                exit(0);
            
                
        }
    }
    return 0;
}
