//
//  SFReaderPacketBase.h
//  SIfliReaderOCSDK
//
//  Created by congqiang on 2026/10/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, SFReaderPacketType) {
    SFReaderPacketTypeSinglePacket   = 0,
    SFReaderPacketTypeStartPacket    = 1, // 一个文件开始
    SFReaderPacketTypeContinuePacket = 2, // 数据包
    SFReaderPacketTypeEndPacket      = 3, // 单一文件发送结束
    SFReaderPacketTypeFinishPacket   = 4  // 会话结束
};

typedef NS_ENUM(NSInteger, SFReaderCommandType) {
    SFReaderCommandTypeNone               = 255,
    
    SFReaderCommandTypeReqClearLog        = 0,   // 清空
    SFReaderCommandTypeReqGetLog          = 1,   // 读取日志开关选项
    SFReaderCommandTypeReqSetLogOption    = 16,  // 设置日志开关选项
    SFReaderCommandTypeReqGetMem          = 36,  // 读取内存地址，附加 DATA string 具体命令
    SFReaderCommandTypeReqSetMem          = 38,
    SFReaderCommandTypeReqSetAssetOption  = 19,  // asset 开关
    SFReaderCommandTypeReqGetAsset        = 17,
    SFReaderCommandTypeReqClearAsset      = 18,
    SFReaderCommandTypeReqSetAudioDumpType= 30,  // 开启 AudioDump
    SFReaderCommandTypeReqClearAudioDump  = 32,
    SFReaderCommandTypeReqSetAudioDelay   = 33,
    SFReaderCommandTypeReqSendAudioCommand= 34,
    SFReaderCommandTypeReqGetAudioDump    = 35,
    SFReaderCommandTypeReqSetHCIOption    = 39,
    SFReaderCommandTypeReqClearHCI        = 40,
    SFReaderCommandTypeReqGetHCI          = 41,
    SFReaderCommandTypeReqGetMetrics      = 20,
    SFReaderCommandTypeReqGetWatchInfo    = 42,  // 获取手表软硬件信息
    SFReaderCommandTypeReqSetTxPower      = 44,  // 设置手表 tx power
    //2026-11-12
    SFReaderCommandTypeReqMakeAsset          = 45,  // 使手表Assert
    SFReaderCommandTypeReqSendFinish         = 46,  // 发送finish字符串命令
    SFReaderCommandTypeReqCurrentLogOption   = 47, //获取当前日志选项状态
    
    SFReaderCommandTypeRspGetSendFinish   = 15,  // 所有命令的结束应答
    SFReaderCommandTypeRspLogGetSendStart = 2,   // 日志响应开始
    SFReaderCommandTypeRspLogGetSendPacket= 3,   // 日志响应数据包
    SFReaderCommandTypeRspLogGetSendEnd   = 4,   // 日志获取结束
    SFReaderCommandTypeRspAudioDumpGet    = 31,  // 音频获取
    SFReaderCommandTypeRspMemGet          = 37,  // MEM GET RSP
    SFReaderCommandTypeRspGetWatchInfo    = 43,
    SFReaderCommandTypeRspCurrentLogOption = 48  // 命令47 获取日志开关状态命令
};

typedef NS_ENUM(uint8_t, SFReaderMessageType) {
    SFReaderMessageTypeCommand = 0, // 单一请求命令，响应为 singlePacket
    SFReaderMessageTypeFile    = 1  // 文件读取，响应为 startPacket、continuePacket、endPacket
};

@interface SFReaderPacketBase : NSObject

@property (nonatomic, assign) SFReaderCommandType commandType;

- (instancetype)initWithCommandType:(SFReaderCommandType)commandType;

@end

NS_ASSUME_NONNULL_END
