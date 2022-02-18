# Code Reviewer Agent 
# Dynamic Team 

## Ground Rule

1. 아침에 인사하기
2. 한 커밋(PR)에 리뷰 하나 이상씩 꼭 달기 (LGTM)이라도
3. 지각하지 않기
4. 기분나쁘지 않게 Review Comment 작성하기
5. 수업에 열심히 참여하기


## Coding Style

- 클래스, 함수, 조건, 반복문 등의 ‘{‘ 시작은 내리지 않고 옆에 붙인다.
<pre><code>void funcName() {
    //…
}
</code></pre>

- Class 의 멤버 변수는 가장 아래에 정의한다.

- 표기법은 아래와 같이 한다.
    - File 명: ManagerTest.cpp
    - Class명: ClassName { }
    - 함수명: funcName()
    - 변수명: varName;
    - 멤버변수명: varName_;
    - 포인터변수: pVarName;
    - 포인터멤버변수: pVarName_;
    - ENUM: enum class OPTION1 { NONE = -1, P, MAX };



## Review Policy
- PR  시에 Code Review를 받는다.
- 3인 중 2인 이상의 Approve 시 Push 가능하다.
- Code Review를 요청 받으면, 하루 이내에 Review를 제출한다.


## Branch Policy
### branch name 규칙
- main: (master branch)
- dev/XXX: 개발자별 개발 브랜치

### PR Prefix
- [Feature]
- [BugFix]
- [Refactoring]

### Other
- 각자 개발 후에, main branch에 PR을 통해서 merge한다
- PR 이 완료된 dev branch 는 origin 에서 삭제한다.

- Master Branch 로 Push
  - Rebase and Merge
  - Squash x Option 으로 Push 한다. (TDD 흔적을 보여주기 위해 commit 이력 남기기)

- Master Branch에는 설정파일을 제외한 순수코드파일만 업로드한다.

## Reference (논의 초안) 
- [Ground Rule, Coding Style, Review Policy, Branch Policy ](https://docs.google.com/document/d/1ahdYhARbr3EIO93Ff9pFI-a4S5cdZEMCG_9dCmnLb94)
- [설계](https://docs.google.com/document/d/1srNSrLoiIQ3xV9rZasybC_zsNvoSkJQEDHHrVvZZCgk/edit?usp=sharing)
