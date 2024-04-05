#include <SFML/Audio.hpp>

int main()
{
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("assets/audio/eat.wav"))
        return -1;

    return 0;
}