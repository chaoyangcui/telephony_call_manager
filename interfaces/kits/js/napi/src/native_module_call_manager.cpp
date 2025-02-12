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

#include "napi_call_manager_types.h"
#include "napi_call_manager.h"

namespace OHOS {
namespace Telephony {
static napi_module g_nativeCallManagerModule = {
    .nm_version = kNativeVersion,
    .nm_flags = kNativeFlags,
    .nm_filename = nullptr,
    .nm_register_func = NapiCallManager::RegisterCallManagerFunc,
    .nm_modname = "libtelephony_call.z.so",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterModule(void)
{
    napi_module_register(&g_nativeCallManagerModule);
}
} // namespace Telephony
} // namespace OHOS
