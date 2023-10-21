#include <Windows.h>
#include <fileapi.h>
#include <stdio.h>

int main(int argc, char** argv) {
	if (argc == 1) {
		printf("Usage: %s <directionary name>\n", argv[0]);
		printf("    Creates a new directory");
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		BOOL flag = CreateDirectoryA(argv[i], NULL);

		if (!flag) {
			switch(GetLastError()) {
				case ERROR_ALREADY_EXISTS:
					printf("Directory already exists\n");
					break;
				case ERROR_PATH_NOT_FOUND:
					printf("Path not found\n");
					break;
				default:
					break;
			}
			return 1;
		}
	}
	return 0;
}
