#pragma once

#include <sstream>

namespace Liaison::Graphics {

	struct WindowProperties {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(const std::string& title = "Liaison Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height) {
		}
	};


	class Window {
	public:

		Window(const WindowProperties& settings = WindowProperties());
		~Window();

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator=(Window&&) = delete;

		GLFWwindow* GetWindow() const { return _window; }

	private:
		void Initialize();
		void Terminate();

		WindowSetings _settings;

		GLFWwindow* _window;
	};
}