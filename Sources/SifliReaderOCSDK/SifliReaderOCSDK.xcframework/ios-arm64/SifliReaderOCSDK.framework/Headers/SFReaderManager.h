//
//  SFReaderManager.h
//  SIfliReaderOCSDK
//
//  Created by congqiang on 2026/10/9.
//

#import <Foundation/Foundation.h>
#import <SifliOCore/SifliOCore.h>
#import <SifliReaderOCSDK/SFReadLogResult.h>
#import <SifliReaderOCSDK/SFReaderAudioDumpType.h>
#import <SifliReaderOCSDK/SFReaderTxType.h>

NS_ASSUME_NONNULL_BEGIN

@class SFReaderManager;
@protocol SFReaderManagerDelegate <NSObject>

- (void)readerManager:(SFReaderManager *)manager updateBleState:(SFBleCoreManagerState)state;
- (void)readerManager:(SFReaderManager *)manager
               progress:(NSUInteger)completedBytes
              total:(NSUInteger)totalBytes;

/// 视频预览完成回调
/// - Parameters:
///   - manager:
///   - success:是否成功，失败时error有值。
///   - error: @see SFCoreError
///   - result:@see SFReadLogResult
- (void)readerManager:(SFReaderManager *)manager success:(BOOL)success errror:(nullable SFCoreError *)error result:(nonnull SFReadLogResult *)result;
- (void)readerManager:(SFReaderManager *)manager updateManagerState:(SFBleShellStatus)state;

@end

@interface SFReaderManager : NSObject
@property (nonatomic,weak) id<SFReaderManagerDelegate> delegate;

+ (SFReaderManager *)shared;

+ (NSString *)SDKVersion;

#pragma mark - Memory

/// 内存读取
/// - Parameters:
///   - addr: 地址4字节
///   - targetIdentifier: 蓝牙地址uuid
- (void)memGetRequestWithAddress:(NSString *)addr
                targetIdentifier:(NSString *)targetIdentifier;

/// 内存修改
/// - Parameters:
///   - addr: 地址4字节
///   - value: 值
///   - targetIdentifier: 蓝牙地址uuid
- (void)memSetRequestWithAddress:(NSString *)addr
                       valueData:(NSString *)value
                targetIdentifier:(NSString *)targetIdentifier;

#pragma mark - Log

/// 打开日志读取开关
/// - Parameters:
///   - open: true/false
///   - targetIdentifier: 蓝牙地址uuid
- (void)logOptionRequestWithOpen:(BOOL)open
                targetIdentifier:(NSString *)targetIdentifier;


/// 读取日志
/// - Parameters:
///   - logDir: 日志目录
///   - targetIdentifier: 蓝牙地址uuid
- (void)readLogRequestWithLogDir:(NSString *)logDir
                targetIdentifier:(NSString *)targetIdentifier;

/// 清理日志
/// - Parameter targetIdentifier: 蓝牙地址uuid
- (void)clearLogRequestWithTargetIdentifier:(NSString *)targetIdentifier;

#pragma mark - Asset

/// 打开读取asset日志开关
/// - Parameters:
///   - open: true/false
///   - targetIdentifier: 蓝牙地址uuid
- (void)assetOptionRequestWithOpen:(BOOL)open
                  targetIdentifier:(NSString *)targetIdentifier;

/// 清理asset日志
/// - Parameter targetIdentifier: 蓝牙地址uuid
- (void)clearAssetRequestWithTargetIdentifier:(NSString *)targetIdentifier;


/// 读取asset日志到指定目录
/// - Parameters:
///   - dir: 输出目录
///   - targetIdentifier: 蓝牙地址uuid
- (void)readAssetRequestWithDir:(NSString *)dir
               targetIdentifier:(NSString *)targetIdentifier;

#pragma mark - Audio Dump
- (void)openAudioDumpRequestWithType:(SFReaderAudioDumpType)type
                    targetIdentifier:(NSString *)targetIdentifier;

- (void)clearAudioDumpRequestWithTargetIdentifier:(NSString *)targetIdentifier;

/// set audio delay
/// - Parameters:
///   - delay: delay 具体值，0~1000
///   - targetIdentifier: 目标设备
- (void)setAudioDelayRequestWithDelay:(uint16_t)delay
                     targetIdentifier:(NSString *)targetIdentifier;

/// 发送 Audio Command
/// - Parameters:
///   - command: command 字符串
///   - targetIdentifier: 目标设备
- (void)audioCommandRequestWithCommand:(NSString *)command
                      targetIdentifier:(NSString *)targetIdentifier;

- (void)readAudioDumpRequestWithDir:(NSString *)dir
                   targetIdentifier:(NSString *)targetIdentifier;

#pragma mark - HCI
- (void)hciOptionRequestWithOpen:(BOOL)open
                targetIdentifier:(NSString *)targetIdentifier;

- (void)clearHCIRequestWithTargetIdentifier:(NSString *)targetIdentifier;

- (void)readHCIRequestWithDir:(NSString *)dir
             targetIdentifier:(NSString *)targetIdentifier;

#pragma mark - Metrics
- (void)readMetricsRequestWithDir:(NSString *)dir
                 targetIdentifier:(NSString *)targetIdentifier;

#pragma mark - Watch Info
- (void)getWatchInfoWithTargetIdentifier:(NSString *)targetIdentifier;

/// 设置手表 tx power
/// - Parameters:
///   - txType: 0 blebr  1 edr  2 blebr+edr
///   - level: 0-13
///   - targetIdentifier: 设备 uuid
- (void)setTxPowerRequestWithTxType:(SFReaderTxType)txType
                              level:(uint8_t)level
                   targetIdentifier:(NSString *)targetIdentifier;


/// 发送finsh命令
/// - Parameters:
///   - cmd: finsh命令
///   - targetIdentifier: 设备uuid
- (void)sendFinishCommand:(NSString *)cmd identifier:(NSString *)targetIdentifier;
 
@end

NS_ASSUME_NONNULL_END
