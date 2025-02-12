/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include "singleton.h"
#include "call_state_listener_base.h"

namespace OHOS {
namespace Telephony {
class StatusBar : public CallStateListenerBase {
    DECLARE_DELAYED_SINGLETON(StatusBar)
public:
    void UpdateMuteIcon(bool isDisplayMute);
    void UpdateSpeakerphoneIcon(bool isDisplaySpeakerphone);
    void NewCallCreated(sptr<CallBase> &callObjectPtr) override;
    void CallDestroyed(sptr<CallBase> &callObjectPtr) override;
    void CallStateUpdated(sptr<CallBase> &callObjectPtr, TelCallState priorState, TelCallState nextState) override;
    void IncomingCallHungUp(sptr<CallBase> &callObjectPtr, bool isSendSms, std::string content) override;
    void IncomingCallActivated(sptr<CallBase> &callObjectPtr) override;

private:
    bool isDisplayMute_;
    bool isDisplaySpeakerphone_;
};
} // namespace Telephony
} // namespace OHOS
#endif // STATUS_BAR_H