//
//  SFReaderWatchInfoGetResponsePacket.h
//  SIfliReaderOCSDK
//
//  读取手表信息响应
//

#import <Foundation/Foundation.h>
#import <SifliReaderOCSDK/SFReaderResponsePacket.h>

NS_ASSUME_NONNULL_BEGIN

@interface SFReaderWatchInfoGetResponsePacket : SFReaderResponsePacket

@property (nonatomic, assign) uint8_t infoCount;              // 信息个数
@property (nonatomic, copy) NSString *SN;
@property (nonatomic, copy) NSString *boradTyppe;
@property (nonatomic, copy) NSString *watch_app_version;
@property (nonatomic, copy) NSString *sha;
@property (nonatomic, copy) NSString *dfuType;

- (instancetype)initWithCommandType:(SFReaderCommandType)commandType
                          infoCount:(uint8_t)infoCount
                                 SN:(NSString *)SN
                         boradTyppe:(NSString *)boradTyppe
                   watch_app_version:(NSString *)watch_app_version
                                sha:(NSString *)sha
                            dfuType:(NSString *)dfuType;

@end

NS_ASSUME_NONNULL_END
