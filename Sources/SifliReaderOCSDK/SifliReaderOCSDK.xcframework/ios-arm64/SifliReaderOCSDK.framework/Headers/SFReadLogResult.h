// SFReadLogResult.h
#import <Foundation/Foundation.h>
#import <SifliReaderOCSDK/SFReaderResponsePacket.h>

NS_ASSUME_NONNULL_BEGIN

@interface SFReadLogResult : NSObject

@property (nonatomic, assign) SFReaderCommandType requestCommand;
@property (nonatomic, assign) SFReaderCommandType responseCommand;

/// 单条请求数据响应
@property (nonatomic, strong, nullable) SFReaderResponsePacket *responsePacket;

/// 已接收到的文件列表（只读）
@property (nonatomic, copy, readonly) NSArray<NSString *> *rcvFiles;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithRequestCommand:(SFReaderCommandType)requestCommand;

/// 追加接收到的文件
- (void)appendFiles:(NSArray<NSString *> *)files;

@end

NS_ASSUME_NONNULL_END
