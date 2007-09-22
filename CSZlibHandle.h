#import "CSHandle.h"

#include <zlib.h>

@interface CSZlibHandle:CSHandle
{
	CSHandle *fh;
	off_t startoffs;
	z_stream zs;
	BOOL inited,eof;
	//uint8_t inbuffer[128*1024];
	uint8_t inbuffer[16*1024];
}

+(CSZlibHandle *)zlibHandleWithHandle:(CSHandle *)handle;
//+(CSZlibHandle *)zlibHandleWithPath:(NSString *)path;

-(id)initWithHandle:(CSHandle *)handle name:(NSString *)descname;
-(id)initAsCopyOf:(CSZlibHandle *)other;
-(void)dealloc;

-(off_t)offsetInFile;
-(BOOL)atEndOfFile;

-(void)seekToFileOffset:(off_t)offs;
-(void)seekToEndOfFile;
-(int)readAtMost:(int)num toBuffer:(void *)buffer;
-(id)copyWithZone:(NSZone *)zone;

-(void)_raiseZlib;

@end
