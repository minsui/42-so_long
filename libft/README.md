*This project has been created as part of the 42 curriculum by [mkim2].*

## Description (설명)
**Libft** 프로젝트의 목표는 C 표준 라이브러리(`libc`)의 주요 함수들을 직접 재구현하여 나만의 C 라이브러리를 만드는 것입니다. 이 과정은 C 언어의 기초를 다지고, 메모리 관리 및 데이터 구조(Linked List 등)의 원리를 깊이 있게 이해하기 위한 42 첫 과정입니다. 계속해서 과제를 진행해나아가며 배운 지식들로 함수들을 업데이트 할 생각입니다. 

### 상세 라이브러리 설명
본 라이브러리는 다음과 같은 기능을 포함합니다:
- **Libc 함수 재구현**: 문자열 처리(`strlen`, `strlcpy`), 메모리 조작(`memset`, `memcpy`), 타입 변환(`atoi`, `itoa`) 등.
- **추가 유틸리티**: 문자열 자르기(`ft_split`), 결합(`ft_strjoin`), 부분 문자열 생성(`ft_substr`) 등.
- **연결 리스트 관리**: 노드 생성, 추가, 삭제 등 리스트 구조를 다루는 함수들.

---

## Instructions (사용 방법)

### 컴파일 및 빌드
제공된 `Makefile`을 통해 다음과 같은 명령어를 사용할 수 있습니다:
- `make`: 모든 소스 파일을 컴파일하여 `libft.a` 라이브러리를 생성합니다.
- `make clean`: 빌드 과정에서 생성된 오브젝트 파일(`.o`)들을 삭제합니다.
- `make fclean`: 오브젝트 파일과 `libft.a` 파일을 모두 삭제합니다.
- `make re`: 모든 파일을 삭제한 후 처음부터 다시 빌드합니다.

### 프로젝트 적용
본 라이브러리를 다른 C 프로젝트에서 사용하려면 다음 단계를 따릅니다:
1. 소스 코드 상단에 헤더를 포함합니다: `#include "libft.h"`
2. 컴파일 시 라이브러리 경로와 이름을 링크합니다: `cc main.c -L. -lft`

---

## Resources (참고 자료)
- [42 Seoul Subject PDF](https://42seoul.kr/)
- [C Standard Library Reference (cppreference.com)](https://en.cppreference.com/w/c)

### AI 활용 기술 기술
본 프로젝트의 완성도를 높이기 위해 AI(Gemini)를 다음과 같이 활용하였습니다:
- **컴파일 프로세스 이해**: 전처리, 컴파일, 어셈블, 링킹의 4단계 메커니즘 학습.
- **Makefile 설계 및 디버깅**: `missing separator` 에러 해결 및 자동 변수(`$@`, `$<`) 활용법 습득.
- **함수 로직 검증**: `ft_lstdelone` 등의 함수에서 메모리 해제 순서 및 함수 포인터의 기술적 검토.
- **문서화 보조**: 가이드라인의 요구사항(이탤릭체 표시, 필수 섹션 포함 등)에 맞춘 README 구조 설계.