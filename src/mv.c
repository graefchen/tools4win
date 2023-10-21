#include <Windows.h>
#include <WinBase.h>
#include <stdio.h>

int main(int argc, char** argv) {
	if (argc < 3) {
		printf("Usage: %s <old filename / dirname> <new filename/ dirname>\n", argv[0]);
		printf("    Moves a file or a directory");
		return 1;
	}

	BOOL flag = MoveFileA(argv[1], argv[2]);

	if (!flag) {
		switch(GetLastError()) {
			case ERROR_FILE_NOT_FOUND:
				printf("File '%s' not found\n", argv[1]);
				break;
			case ERROR_FILE_EXISTS:
				printf("File '%s' already exists\n", argv[2]);
				break;
			default:
				printf("Error: %lu", GetLastError());
				break;
		}
		return 1;
	}
	return 0;
}
