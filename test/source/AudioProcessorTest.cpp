#include <gtest/gtest.h>
#include "PluginProcessor.h"

namespace audio_plugin_test {
    TEST(AudioPluginAudioProcessor, PassesSilenceThroughUnchanged) {
        AudioPluginAudioProcessor processor{};
        ASSERT_FALSE(true);
    }
}

