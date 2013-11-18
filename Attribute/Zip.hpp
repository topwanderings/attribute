#include <Windows.h>

typedef enum {
	COMP_STORED = 0,
	COMP_SHRUNK = 1,
	COMP_REDUCED1 = 2,
	COMP_REDUCED2 = 3,
	COMP_REDUCED3 = 4,
	COMP_REDUCED4 = 5,
	COMP_IMPLODED = 6,
	COMP_TOKEN = 7,
	COMP_DEFLATE = 8,
	COMP_DEFLATE64 = 9
} COMPTYPE;

// Defines a file record
typedef struct {
	// Header for the file
	char     frSignature[4];    //0x04034b50
	u_short   frVersion;
	u_short   frFlags;
	COMPTYPE frCompression;
	u_short  frFileTime;
	u_short  frFileDate;
	u_int     frCrc; // <format = hex>;
	u_int     frCompressedSize;
	u_int     frUncompressedSize;
	u_short   frFileNameLength;
	u_short   frExtraFieldLength;
	/*
	if (frFileNameLength > 0)
		char frFileName[frFileNameLength];
	*/
	char * frFileName;
	/*
	if (frExtraFieldLength > 0)
		uchar frExtraField[frExtraFieldLength];
	*/
	u_char * frExtraField;
	// Compressed data

	/*
	if (frCompressedSize > 0)
		uchar frData[frCompressedSize];
	*/
	u_char * frData;

} ZIPFILERECORD;

// Defines an entry in the directory table
typedef struct {
	char     deSignature[4];     //0x02014b50
	u_short   deVersionMadeBy;
	u_short   deVersionToExtract;
	u_short   deFlags;
	COMPTYPE deCompression;
	u_short  deFileTime;
	u_short  deFileDate;
	u_int     deCrc;     //<format = hex>;
	u_int     deCompressedSize;
	u_int     deUncompressedSize;
	u_short   deFileNameLength;
	u_short   deExtraFieldLength;
	u_short   deFileCommentLength;
	u_short   deDiskNumberStart;
	u_short   deInternalAttributes;
	u_int     deExternalAttributes;
	u_int     deHeaderOffset;
	/*
	if (deFileNameLength > 0)
		char deFileName[deFileNameLength];
	*/
	char * deFileName;

	/*
	if (deExtraFieldLength > 0)
		uchar deExtraField[deExtraFieldLength];
	*/
	u_char * deExtraField;

	/*
	if (deFileCommentLength > 0)
		uchar deFileComment[deFileCommentLength];
	*/
	u_char deFileComment;
} ZIPDIRENTRY;

// Defines the digital signature
typedef struct {
	char     dsSignature[4];    //0x05054b50
	u_short   dsDataLength;

	/*
	if (dsDataLength > 0)
		uchar dsData[dsDataLength];
	*/
	u_char * dsData;
} ZIPDIGITALSIG;

// Defintes the Data descriptor
typedef struct {
	char ddSignature[4]; //0x08074b50
	u_int ddCRC; // <format = hex>;
	u_int ddCompressedSize;
	u_int ddUncompressedSize;
} ZIPDATADESCR;

// Defines the end of central directory locator
typedef struct {
	char     elSignature[4];    //0x06054b50
	u_short   elDiskNumber;
	u_short   elStartDiskNumber;
	u_short   elEntriesOnDisk;
	u_short   elEntriesInDirectory;
	u_int     elDirectorySize;
	u_int     elDirectoryOffset;
	u_short   elCommentLength;
	/*
	if (elCommentLength > 0)
		char elComment[elCommentLength];
	*/
	char * elComment;
} ZIPENDLOCATOR;
