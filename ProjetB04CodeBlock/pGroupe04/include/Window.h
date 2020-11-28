#ifndef WINDOWS_H
#define WINDOWS_H
#include <string>
#include <SFML/Graphics.hpp>
#include "EventManager.h"

class Window
{
private:
    void SetUp(const std::string &l_title, const sf::Vector2u &l_size);
    void Destroy();
    void Create();

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;

    bool m_isDone;
    bool m_isFullscreen;

    //Addition lie a EventManager
    EventManager m_eventManager;
    bool m_isFocused;

public:
    Window();
    Window(const std::string &l_title, const sf::Vector2u &l_size);
    virtual ~Window();

    void BeginDraw(); // Clear the window
    void EndDraw();   // Display the changes

    void Update();

    bool isDone();
    bool isFullscreen();
    sf::Vector2u GetWindowSize();
    sf::RenderWindow *GetRenderWindow();

    void ToggleFullscreen();

    void Draw(sf::Drawable &l_drawable);

    //Addition lie a EventManager
    bool isFocused();
    EventManager *GetEventManager();
    void ToggleFullscreen(EventDetails *l_details);
    void Close(EventDetails *l_details = nullptr);
};

#endif // WINDOWS_H
