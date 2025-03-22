# 중위 표기식을 후위 표기식으로 변환하기

## 표기식이란?
- 중위 표기식(Infix): 우리가 일반적으로 사용하는 수식 표기법 (예: A+B, (A+B)*C)
- 후위 표기식(Postfix): 연산자가 피연산자 뒤에 위치하는 표기법 (예: AB+, AB+C*)

## 왜 후위 표기식으로 변환하나요?
- 괄호가 필요 없어 컴퓨터가 처리하기 쉽습니다
- 스택 하나로 계산이 가능합니다
- 컴파일러가 수식을 계산할 때 주로 사용합니다

## 변환 알고리즘의 핵심
1. 피연산자(알파벳)는 바로 출력합니다
2. 연산자는 우선순위에 따라 스택에 저장하고 처리합니다
3. 괄호는 특별히 처리합니다

## 코드 설명

### 1. 준비 단계: 우선순위 설정
```cpp
// 연산자 우선순위 지정
map<char, int> priority = {
    {'(', 3}, {')', 3},  // 괄호는 최우선
    {'*', 2}, {'/', 2},  // 곱셈, 나눗셈은 중간
    {'+', 1}, {'-', 1},  // 덧셈, 뺄셈은 낮음
};
```

### 2. 필요한 자료구조
```cpp
stack<string> variable;  // 피연산자와 결과를 저장
stack<char> oper;        // 연산자를 저장
```

### 3. 핵심 로직
```cpp
for (int i = 0; i < exp.length(); i++) {
    char c = exp[i];
    if (isalpha(c)) {
        // 알파벳인 경우 바로 스택에 넣음
        variable.push({ c });
    } else {
        // 연산자인 경우
        if (!oper.empty() && priority[oper.top()] >= priority[c]) {
            // 스택 맨 위 연산자가 현재보다 우선순위가 높거나 같으면
            // 처리 후 현재 연산자 스택에 추가
            while(!oper.empty() && priority[oper.top()] >= priority[c]){
                if (oper.top() == '(') break;  // 열린 괄호는 예외
                operStart();  // 연산 수행
            }

            if(c == ')'){   
                oper.pop();  // 닫는 괄호만나면 열린 괄호 제거
            } else {
                oper.push(c);  // 다른 연산자는 스택에 추가
            }
        }
        // 다른 경우들 처리 (스택이 비었거나, 우선순위가 더 높은 경우)
        else if (oper.empty()) {
            oper.push(c);  // 스택이 비어있으면 그냥 추가
        }
        else {
            if (c == ')') {
                // 닫는 괄호면 열린 괄호까지 모든 연산 처리
                do {
                    operStart();
                } while (oper.top() != '(');
                oper.pop();  // 열린 괄호 제거
            }
            else {
                oper.push(c);  // 우선순위가 높으면 스택에 추가
            }
        }
    }
}
```

### 4. 연산 처리 함수
```cpp
void operStart() {
    // 피연산자 두 개를 꺼내서 연산자와 함께 후위 표기식 생성
    string v1 = variable.top(), v2;
    variable.pop();
    v2 = variable.top();
    variable.pop();
    // v2 + v1 + 연산자 순서로 저장 (후위 표기식)
    variable.push(v2 + v1 + oper.top());
    oper.pop();
}
```

### 5. 마무리
```cpp
// 남은 모든 연산자 처리
while (!oper.empty()) {
    operStart();
}

// 최종 후위 표기식 출력
cout << variable.top() << endl;
```

## 예시로 이해하기
입력: "A+B*C" 변환과정:
1. A → 변수스택: [A]
2. + → 연산자스택: [+]
3. B → 변수스택: [A, B]
4. * → 연산자스택: [+, *] (우선순위 높음)
5. C → 변수스택: [A, B, C]
6. 스택정리 → "ABC*+" 출력

## 알고리즘 응용 분야
- 계산기 구현
- 컴파일러의 수식 처리
- 프로그래밍 언어 파서 개발
