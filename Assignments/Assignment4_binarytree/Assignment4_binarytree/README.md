# [Data Structure]Assignment4_BinaryTree

Status: 진행 중
담당자: 익명
마감일: 2022년 12월 9일

## 목적

- 이진트리의 ADT 설계와 구현
- 이진트리의 노드 방문 방법을 이용한 산술식의 다른 표기
- 산술식의 이진트리 표현과 컴파일러의 처리방법의 이해
- 이진트리를 이용한 문자열 압축 알고리즘의 설계와 구현

---

## 설계 문제(Design Problem)

### Problem1

 연산자 우선순위를 반영하는 산술식의 이진트리를 만드는 프로그램을 구현하시오. 만들어진 이진트리는 다음 순환 탐색 방법에 따라 출력된다.

1. Infix order
2. Prefix order
3. Postfix order
4. Level order

### Problem2

 Huffman 트리를 이용한 문자열의 압축 알고리즘을 구현하시오.

1. 입력 문단에서 선택된 5개 단어에 대한 Huffman 코드를 출력
2. Huffman 코드와 ASCII 코드의 길이 비교

---

## 기능과 사양 (Function & Specification)

### 산술식의 이진트리 설계와 구현

(1) Infix 표기의 산술식을 입력받아 이진트리로 나타내는 프로그램의 작성

(2) 컴퓨터 내부에서 이진트리의 자료구조 표현을 제공해야 함

(3) 이진트리 관련 ADT가 C/C++ 함수로 작성되어야 함

(4)선택한 이진트리에 대한 infix, prefix, postfix, level 순서에 대한 트리의 방문 함수 제공

### 문자열 압축 알고리즘의 설계와 구현

(1) 50 글자 이상이 포함되는 좋아하는 문단을 입력받아 Huffman tree를 생성

(2) 입력 받은 글의 Huffman 코드를 출력

(3) 출력된 코드를 입력받아 문자열을 출력