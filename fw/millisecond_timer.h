// Copyright 2018-2019 Josh Pieper, jjp@pobox.com.
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

#pragma once

#include "mbed.h"

namespace fw {

class MillisecondTimer {
 public:
  MillisecondTimer() {
    __HAL_RCC_TIM2_CLK_ENABLE();

    handle_.Instance = TIM2;
    handle_.Init.Period = 0xFFFFFFFF;
    handle_.Init.Prescaler =
        (uint32_t)(SystemCoreClock / 1000000U) - 1;  // 1 us tick
    handle_.Init.ClockDivision = 0;
    handle_.Init.CounterMode = TIM_COUNTERMODE_UP;
    handle_.Init.RepetitionCounter = 0;

    HAL_TIM_Base_Init(&handle_);
    HAL_TIM_Base_Start(&handle_);
  }

  uint32_t read_ms() {
    return TIM2->CNT / 1000;
  }

  uint32_t read_us() {
    return TIM2->CNT;
  }

  void wait_ms(uint32_t delay_ms) {
    wait_us(delay_ms * 1000);
  }

  void wait_us(uint32_t delay_us) {
    uint32_t current = TIM2->CNT;
    uint32_t elapsed = 0;
    while (true) {
      const uint32_t next = TIM2->CNT;
      elapsed += next - current;
      // We check delay_us + 1 since we don't know where in the
      // current microsecond we started.
      if (elapsed >= (delay_us + 1)) { return; }
      current = next;
    }
  }

 private:
  TIM_HandleTypeDef handle_ = {};
};

}
