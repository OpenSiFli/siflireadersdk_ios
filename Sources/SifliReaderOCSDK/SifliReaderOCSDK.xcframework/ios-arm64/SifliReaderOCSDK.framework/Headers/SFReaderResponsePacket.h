//
//  SFReaderResponsePacket.h
//  SIfliReaderOCSDK
//

#import <Foundation/Foundation.h>
#import <SifliReaderOCSDK/SFReaderPacketBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface SFReaderResponsePacket : SFReaderPacketBase

@property (nonatomic, assign) SFReaderPacketType packetType;

/// 对应 Swift 的 UInt32?，用 NSNumber 表达可选值
@property (nonatomic, strong, nullable) NSNumber *allDataLength;

@property (nonatomic, copy) NSData *data;

- (instancetype)initWithCommandType:(SFReaderCommandType)commandType
                         packetType:(SFReaderPacketType)packetType
                      allDataLength:(nullable NSNumber *)allDataLength
                               data:(NSData *)data;

/// 对应 Swift 的 mashal()，注意保留原方法名（原文拼写如此）
- (NSData *)mashal;

@end

NS_ASSUME_NONNULL_END
