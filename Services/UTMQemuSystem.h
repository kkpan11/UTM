//
// Copyright © 2020 osy. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import "UTMProcess.h"
@import QEMUKitInternal;

/// Specify the backend renderer for this VM
typedef NS_ENUM(NSInteger, UTMQEMURendererBackend) {
    kQEMURendererBackendDefault = 0,
    kQEMURendererBackendAngleGL = 1,
    kQEMURendererBackendAngleMetal = 2,
    kQEMURendererBackendMax = 3,
};

/// Specify the sound backend for this VM
typedef NS_ENUM(NSInteger, UTMQEMUSoundBackend) {
    kQEMUSoundBackendDefault = 0,
    kQEMUSoundBackendSPICE = 1,
    kQEMUSoundBackendCoreAudio = 2,
    kQEMUSoundBackendMax = 3,
};

NS_ASSUME_NONNULL_BEGIN

@interface UTMQemuSystem : UTMProcess <QEMULauncher>

@property (nonatomic, nullable, copy) NSArray<NSURL *> *resources;
@property (nonatomic, nullable, weak) NSDictionary<NSURL *, NSData *> *remoteBookmarks;
@property (nonatomic) UTMQEMURendererBackend rendererBackend;
@property (nonatomic, weak) id<QEMULauncherDelegate> launcherDelegate;
@property (nonatomic, nullable) QEMULogging *logging;
@property (nonatomic) BOOL hasDebugLog;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithArguments:(NSArray<NSString *> *)arguments NS_UNAVAILABLE;
- (instancetype)initWithArguments:(NSArray<NSString *> *)arguments architecture:(NSString *)architecture NS_DESIGNATED_INITIALIZER;
- (void)startQemuWithCompletion:(void(^)(NSError * _Nullable))completion;

@end

NS_ASSUME_NONNULL_END
