#pragma once

#include "juce_audio_processors_headless/juce_audio_processors_headless.h"
#include "juce_core/juce_core.h"
#include <juce_audio_processors/juce_audio_processors.h>
#include <memory>

//==============================================================================
class AudioPluginAudioProcessor final : public juce::AudioProcessor
{
public:
    //==============================================================================
    AudioPluginAudioProcessor();
    ~AudioPluginAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    using AudioProcessor::processBlock;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    //==============================================================================

    static juce::AudioProcessorValueTreeState::ParameterLayout
    createLayout()
    {
        juce::AudioProcessorValueTreeState::ParameterLayout layout;
        layout.add(std::make_unique<juce::AudioParameterFloat>
            (
                "Low Cut Freq", 
                "Low Cut Freq",
                juce::NormalisableRange<float>(20.0f, 20000.0f, 1.0f, 0.25f),
                20.0f
            )    
        );    

        layout.add(std::make_unique<juce::AudioParameterFloat>
            (
                "High Cut Freq", 
                "High Cut Freq",
                juce::NormalisableRange<float>(20.0f, 20000.0f, 1.0f, 0.25f),
                20000.0f
            )    
        );  


        layout.add(std::make_unique<juce::AudioParameterFloat>
            (
                "Peak Freq", 
                "Peak Freq",
                juce::NormalisableRange<float>(20.0f, 20000.0f, 1.0f, 0.25f),
                20.0f
            )    
        );  

        layout.add(std::make_unique<juce::AudioParameterFloat>
            (
                "Peak Gain", 
                "Peak Gain",
                juce::NormalisableRange<float>(20.0f, 20000.0f, 1.0f, 0.25f),
                20.0f
            )    
        );  
        
    }



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessor)
};
