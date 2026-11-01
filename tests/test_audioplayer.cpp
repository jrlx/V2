// Automated tests for AudioPlayer.
// Run with: ctest --test-dir build --output-on-failure

#include "AudioPlayer.h"

#include <SFML/Audio.hpp>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

int failures = 0;

void check(bool condition, const std::string& name) {
    if (condition) {
        std::cout << "[PASS] " << name << '\n';
    } else {
        std::cout << "[FAIL] " << name << '\n';
        ++failures;
    }
}

// Writes a one-second 440 Hz mono sine wave to a WAV file.
bool writeTestWav(const std::string& path) {
    const unsigned int sampleRate = 44100;
    std::vector<sf::Int16> samples(sampleRate);
    for (std::size_t i = 0; i < samples.size(); ++i) {
        const double t = static_cast<double>(i) / sampleRate;
        samples[i] = static_cast<sf::Int16>(10000.0 * std::sin(2.0 * 3.14159265358979 * 440.0 * t));
    }
    sf::SoundBuffer buffer;
    return buffer.loadFromSamples(samples.data(), samples.size(), 1, sampleRate)
        && buffer.saveToFile(path);
}

void testMissingFileThrows() {
    AudioPlayer player;
    bool threw = false;
    try {
        player.loadAudio("this_file_does_not_exist.wav");
    } catch (const std::runtime_error&) {
        threw = true;
    }
    check(threw, "loadAudio throws on a missing file");
}

void testEmptyPlayer() {
    AudioPlayer player;
    check(player.getTotalTime() == 0.0f, "new player has zero total time");
    check(player.getStatus() == sf::Sound::Stopped, "new player is stopped");
}

void testLoadValidFile() {
    const std::string path = "test_tone.wav";
    check(writeTestWav(path), "test WAV file is created");

    AudioPlayer player;
    bool threw = false;
    try {
        player.loadAudio(path);
    } catch (const std::exception&) {
        threw = true;
    }
    check(!threw, "loadAudio accepts a valid WAV file");
    check(std::fabs(player.getTotalTime() - 1.0f) < 0.01f, "total time of a 1 s file is about 1 s");
    check(player.getBuffer().getChannelCount() == 1, "loaded buffer is mono");
    check(player.getBuffer().getSampleRate() == 44100, "loaded buffer keeps its sample rate");

    player.stop();
    check(player.getStatus() == sf::Sound::Stopped, "stop leaves the player stopped");
    check(player.getCurrentTime() == 0.0f, "stopped player is at time 0");

    std::remove(path.c_str());
}

} // namespace

int main() {
    testMissingFileThrows();
    testEmptyPlayer();
    testLoadValidFile();

    if (failures > 0) {
        std::cout << failures << " test(s) failed\n";
        return 1;
    }
    std::cout << "All tests passed\n";
    return 0;
}
