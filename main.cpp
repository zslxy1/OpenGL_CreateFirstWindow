#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);  //声明窗口
void processInput(GLFWwindow* window);

int main()
{
    /*初始化设置*/
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);    //定义窗口
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
	}//如果窗口创建失败，关闭
	glfwMakeContextCurrent(window);//设置当前窗口

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
	}//初始化GLAD，设置传入指针


	glViewport(0, 0, 800, 600);//设置窗口大小

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//注册窗口变化监听函数
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);//按键是否检测，iftrue关闭当前窗口
       


        //渲染指令
        //....

        /*清楚缓冲*/
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);



		glfwSwapBuffers(window);//交换颜色缓冲
		glfwPollEvents();//检查有没有触发事件（：键盘输入，鼠标移动等）
	}//循环执行在窗口没有被关闭的情况下
	glfwTerminate();//释放资源
    return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
}//放于main外面


void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
		glfwSetWindowShouldClose(window, true);
        
    
}




