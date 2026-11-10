//
//  SFReaderTxType.h
//  SifliReaderOCSDK
//
//  Created by congqiang on 2026/10/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 对应 Swift 的 SFReaderTxType: UInt8
typedef NS_ENUM(uint8_t, SFReaderTxType) {
    SFReaderTxTypeBleBr         = 0,
    SFReaderTxTypeEdr           = 1,
    SFReaderTxTypeBleBrAndEdir  = 2
};

NS_ASSUME_NONNULL_END
