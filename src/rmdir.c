#include <Windows.h>
#include <fileapi.h>
#include <stdio.h>

int main(int argc, char** argv) {
	if (argc == 1) {
		printf("Usage: %s <file>\n", argv[0]);
		printf("    Removes a directory");
		return 1;
	}

	if (GetFileAttributesA(argv[1]) == FILE_ATTRIBUTE_DIRECTORY) {
		BOOL flag = RemoveDirectoryA(argv[1]);

		if (!flag) {
			switch(GetLastError()) {
				case ERROR_DIR_NOT_EMPTY:
					printf("Directory '%s' is not empty\n", argv[1]);
					break;
				default:
					printf("Error: %lu", GetLastError());
					break;
			}
			return 1;
		}
	} else {
		printf("Directory '%s' is not found\n", argv[1]);
		return 1;
	}
	return 0;
}
