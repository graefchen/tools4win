#include <Windows.h>
#include <fileapi.h>
#include <stdio.h>

int main(int argc, char** argv) {
	if (argc == 1) {
		printf("Usage: %s <filename>\n", argv[0]);
		printf("    Creates a new file");
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		HANDLE hFile = CreateFileA(argv[1], GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);

		if (hFile == INVALID_HANDLE_VALUE) {
			switch (GetLastError()) {
				case ERROR_FILE_EXISTS:
					printf("File '%s' exists\n", argv[1]);
					break;
				default:
					printf("Error: %lu", GetLastError());
					break;
			}
			return 1;
		}

		CloseHandle(hFile);
	}
	return 0;
}
