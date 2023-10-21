#include <Windows.h>
#include <WinBase.h>
#include <stdio.h>

int main(int argc, char** argv) {
	if (argc == 1) {
		printf("Usage: %s <old filename> <new filename>\n", argv[0]);
		printf("    Copies a file to another location");
		return 1;
	}

	BOOL flag = CopyFileA(argv[1], argv[2], TRUE);

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
