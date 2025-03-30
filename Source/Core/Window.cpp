#include "Window.h"

#include "Core/Logger.h"

namespace Liaison::Graphics {

	Window::Window(const WindowProperties& settings) : _settings(settings)
	{
		PH_CORE_LOG_INFO("Initializing Window...");
		Initialize();
		PH_CORE_LOG_INFO("Window initialized successfully!");
	}

	Window::~Window()
	{
		PH_CORE_LOG_INFO("Terminating Window...");
		Terminate();
		PH_CORE_LOG_INFO("Window terminated successfully!");
	}

	void Window::Initialize()
	{
		if (!glfwInit()) {
			PH_CORE_LOG_ERROR("Failed to initialize GLFW!");
			return;
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, _settings.Resizable ? GLFW_TRUE : GLFW_FALSE);

		if (_settings.Fullscreen) {
			GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
			_window = glfwCreateWindow(mode->width, mode->height, _settings.ApplicationName.c_str(), primaryMonitor, nullptr);
		}
		else {
			_window = glfwCreateWindow(_settings.Width, _settings.Height, _settings.ApplicationName.c_str(), nullptr, nullptr);
		}

		if (_window == NULL) {
			PH_CORE_LOG_ERROR("Failed to create GLFW window!");
			return;
		}

		glfwSetWindowUserPointer(_window, this);
	}

	void Window::Terminate()
	{

		if (_window == NULL)
		{
			PH_CORE_LOG_ERROR("Window is not initialized, therefore it cannot be terminated!");
			return;
		}

		glfwDestroyWindow(_window);
		glfwTerminate();
	}

}
