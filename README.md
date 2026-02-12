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