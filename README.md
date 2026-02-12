# C-STOCK 프로젝트

C 언어와 Oracle DB를 이용한 계좌 관리 프로그램

## 현재 진행 상황
 - 리눅스 개발 환경 구축 (WSL2)
 - Oracle 21c DB 서버 구축 (Docker)
 - 기본 계좌 테이블 (`ACCOUNT`) 생성 완료
 - C 언어 파일 입출력 로직 구현

## 환경 설정 로그
### 1. 필수 라이브러리 설치
C 언어와 Oracle의 통신을 위해 `libaio1` 패키지 설치.
```bash
sudo apt-get update
sudo apt-get install -y libaio1

### 2026-02-12 환경 구축 완료 내역
- [x] Oracle 21c XE Docker 컨테이너 설치 및 실행
- [x] SQL*Plus를 통한 `ACCOUNT` 테이블 설계 및 데이터 인서트 (`COMMIT` 완료)
- [x] Ubuntu `libaio1` 패키지 설치 및 `sudo` 권한 문제 해결
- [x] Oracle Instant Client 21.13 SDK/Basic 설정
- [x] `.bashrc` 환경 변수 최적화 및 공유 라이브러리(`so`) 링크 검증 완료

### 2. Pro*C 컴파일 및 실행 가이드
- **컴파일 순서**:
  1. `.pc` 파일 작성 후 Docker 컨테이너로 전송 (`docker cp`)
  2. 컨테이너 내부에서 `proc` 명령어로 `.c` 파일 생성
  3. 생성된 `.c` 파일을 다시 호스트(WSL)로 가져와 `gcc`로 빌드
- **주요 컴파일 옵션**:
  - `-I.`: 현재 디렉토리의 헤더 파일(`sqlca.h`, `sqlcxt.h`) 포함
  - `-L$ORACLE_HOME -lclntsh`: 오라클 클라이언트 공유 라이브러리 링크

### 3. 트러블슈팅 로그 (2026-02-12)
- **에러 ORA-12514 (TNS:listener...)**: 
  - 원인: 접속 문자열의 서비스 이름(`xe`)이 실제 리스너에 등록된 이름과 불일치.
  - 해결: 오라클 21c XE의 PDB 서비스 이름인 `xepdb1`으로 접속 문자열 수정.
- **파일 누락 (sqlcxt.h)**:
  - 현상: `docker cp` 시 오라클 엔진 내에서 `sqlcxt.h`를 찾지 못함.
  - 해결: `sqlcxt` 함수 선언이 포함된 더미 헤더 파일을 직접 생성하여 컴파일 성공.
- **사용자 권한 문제**:
  - `SYS` 계정 접속 시 반드시 `AS SYSDBA` 문구를 접속 문자열 끝에 포함해야 함.