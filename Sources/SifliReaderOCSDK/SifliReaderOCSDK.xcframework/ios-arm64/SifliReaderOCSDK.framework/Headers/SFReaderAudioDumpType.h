//
//  SFReaderAudioDumpType.h
//  SifliReaderOCSDK
//
//  Created by congqiang on 2026/10/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// 对应 Swift 的 SFReaderAudioDumpType: NSInteger
typedef NS_ENUM(NSInteger, SFReaderAudioDumpType) {
    SFReaderAudioDumpTypeDOWLINK       = 1,
    SFReaderAudioDumpTypeDOWLINK_AGC   = 2,
    SFReaderAudioDumpTypeAUDPRC        = 3,
    SFReaderAudioDumpTypeDC_OUTPUT     = 4,
    SFReaderAudioDumpTypeRAMP_IN_OUTPUT= 5,
    SFReaderAudioDumpTypeAECM_INPUT1   = 6,
    SFReaderAudioDumpTypeAECM_INPUT2   = 7,
    SFReaderAudioDumpTypeAECM_OUTPUT   = 8,
    SFReaderAudioDumpTypeANC_OUTPUT    = 9,
    SFReaderAudioDumpTypeAGC_OUTPUT    = 10,
    SFReaderAudioDumpTypeRAMP_OUT_OUTPUT = 11
};

NS_ASSUME_NONNULL_END
