#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <iostream>

#include <GLFW/glfw3.h>

bool IsRunningUnderVirtualMachine()
{
	if (glfwInit() != GLFW_TRUE)
		return true;

	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = nullptr;
	window = glfwCreateWindow(1, 1, "", NULL, NULL);
	if (window == nullptr)
		return true;

	glfwTerminate();

	return false;
}

int main()
{
	if (IsRunningUnderVirtualMachine())
	{
		printf("Virtual machine detected!\n");
	}
	else
	{
		printf("No virtual machine detected...\n");
	}

	printf("\nPress any key to continue . . .\n");

	static_cast<void>(getchar());

	return 0;
}