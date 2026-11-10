//
//  SFReaderMemGetResponsePacket.h
//  SIfliReaderOCSDK
//

#import <Foundation/Foundation.h>
#import <SifliReaderOCSDK/SFReaderResponsePacket.h>

NS_ASSUME_NONNULL_BEGIN

/// MEM GET RSP 37
@interface SFReaderMemGetResponsePacket : SFReaderResponsePacket

@property (nonatomic, copy) NSString *hexMem;

- (instancetype)initWithCommandType:(SFReaderCommandType)commandType
                            memData:(NSData *)memData;

@end

NS_ASSUME_NONNULL_END
